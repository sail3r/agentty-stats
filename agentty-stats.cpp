// agentty-stats — parse one or more agentty debug logs and emit a Markdown
// statistics report.
//
// Usage: agentty-stats <log-file>... <output-file>
//
// The last argument is the output .md file; every preceding argument is an
// input log file. All inputs are aggregated into a single report.
//
// The log is a stream of structured lines of the form:
//   <ISO-ts> +<rel-ms>ms <session-id> <LEVEL> <component> <event>: <key=value ...>
// Lines that do not start with a timestamp are continuations of the previous
// event's payload (e.g. multi-line wire.chunk raw JSON).
//
// This tool aggregates the events into per-turn, per-model, per-tool and
// wire/stream statistics and writes a human-readable Markdown report.

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <climits>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <memory>
#include <cctype>
#include <sys/stat.h>

using std::string;
using std::vector;
using std::map;

// ---------------------------------------------------------------------------
// Small helpers
// ---------------------------------------------------------------------------

// Extract a single-token value for `key=` from a payload string.
static string field(const string& s, const string& key) {
    std::regex re(key + "=(\\S+)");
    std::smatch m;
    if (std::regex_search(s, m, re)) return m[1].str();
    return "";
}

static long long field_num(const string& s, const string& key) {
    string v = field(s, key);
    return v.empty() ? 0 : atoll(v.c_str());
}

// Case-insensitive ASCII string equality (provider labels / model keys).
static bool iequals(const string& a, const string& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); i++)
        if (tolower((unsigned char)a[i]) != tolower((unsigned char)b[i])) return false;
    return true;
}

// Defined with the pricing helpers below; used by the log parser to
// normalize per-request endpoint URLs.
static string norm_api(string a);

static string human_bytes(long long n) {
    char buf[64];
    if (n < 1024)            snprintf(buf, sizeof buf, "%lld B", n);
    else if (n < 1024*1024)  snprintf(buf, sizeof buf, "%.1f KiB", n / 1024.0);
    else if (n < 1024LL*1024*1024) snprintf(buf, sizeof buf, "%.2f MiB", n / (1024.0*1024.0));
    else                    snprintf(buf, sizeof buf, "%.2f GiB", n / (1024.0*1024.0*1024.0));
    return buf;
}

static string human_tokens(long long n) {
    char buf[64];
    if (n < 1000) snprintf(buf, sizeof buf, "%lld", n);
    else if (n < 1000000) snprintf(buf, sizeof buf, "%.1fk", n / 1000.0);
    else snprintf(buf, sizeof buf, "%.2fM", n / 1000000.0);
    return buf;
}

static string human_ms(long long ms) {
    char buf[64];
    if (ms < 1000) snprintf(buf, sizeof buf, "%lld ms", ms);
    else if (ms < 60000) snprintf(buf, sizeof buf, "%.1f s", ms / 1000.0);
    else snprintf(buf, sizeof buf, "%lldm %llds", ms / 60000, (ms % 60000) / 1000);
    return buf;
}

// Parse an ISO-8601 timestamp "YYYY-MM-DDTHH:MM:SS.mmm" into milliseconds
// since the Unix epoch (UTC). Returns 0 on parse failure.
static long long parse_ts_ms(const string& ts) {
    int y, mo, d, h, mi, se, ms = 0;
    if (sscanf(ts.c_str(), "%d-%d-%dT%d:%d:%d.%d", &y, &mo, &d, &h, &mi, &se, &ms) < 6)
        return 0;
    struct tm t;
    memset(&t, 0, sizeof t);
    t.tm_year = y - 1900;
    t.tm_mon = mo - 1;
    t.tm_mday = d;
    t.tm_hour = h;
    t.tm_min = mi;
    t.tm_sec = se;
    t.tm_isdst = -1;
    time_t epoch = timegm(&t);
    if (epoch == (time_t)-1) return 0;
    return (long long)epoch * 1000 + ms;
}

// ---------------------------------------------------------------------------
// Data model
// ---------------------------------------------------------------------------

struct Turn {
    string id;
    string model;        // from dispatch.turn / openai.request
    string role;         // from route.turn (literal value — may be "none")
    string role_inferred;// resolved role (route.turn's model mapped through router state)
    string complexity;   // simple | complex
    int role_source = 0; // 0 = routed, 1 = model→role map, 2 = previous non-none
    double cost = 0;
    bool has_cost = false;
    bool unpriced = false;
    string effort;
    string stop;         // tool_use | end_turn
    string route;
    string provider;
    string api_base;     // normalized request URL base, e.g. "https://ollama.com/v1"
    long long tools = 0;
    long long ctx_window = 0;
    long long max_tokens = 0;
    long long retry = 0;
    long long start_ms = 0;
    long long end_ms = 0;
    long long wall_start_ms = 0;   // absolute epoch ms (for cross-file ordering)
    long long wall_end_ms = 0;
    long long request_bytes = 0;
    long long chunk_bytes = 0;
    long long chunks = 0;
    long long prompt_tokens = 0;
    long long completion_tokens = 0;
    bool has_usage = false;
    bool has_dispatch = false;
    bool has_end = false;
    int orchestrate = 0, subagents = 0, compacting = 0;
    long long http_errors = 0;   // stream.http_error events during this turn
};

struct ToolStat {
    long long calls = 0;
    long long total_ms = 0;
    long long max_ms = 0;
    long long ok = 0;
    long long err = 0;
};

struct ModelStat {
    long long turns = 0;
    long long prompt_tokens = 0;
    long long completion_tokens = 0;
    long long request_bytes = 0;
    long long chunk_bytes = 0;
    long long chunks = 0;
    long long usage_turns = 0;
    long long retried_turns = 0;  // dispatch.turn with retry>0
    long long errors = 0;         // stream.http_error events attributed
};

// ---------------------------------------------------------------------------
// Aggregation state (shared across all input files)
// ---------------------------------------------------------------------------

struct SourceFile {
    string path;
    long long bytes = 0;
    long long models_loaded = -1;   // -1 = no models.loaded event seen in this file
};

struct Stats {
    map<string, ToolStat> tools;
    map<string, ModelStat> models;
    map<string, long long> level_count;      // T D I W E
    map<string, long long> component_count;
    map<string, long long> event_count;
    map<string, long long> stop_count;
    map<string, long long> status_count;
    map<string, long long> host_count;
    map<string, long long> complexity_count;
    map<string, long long> role_count;
    map<string, long long> provider_count;
    map<string, long long> err_events;       // E-level by event
    vector<string> err_samples;
    long long total_chunks = 0, total_chunk_bytes = 0;
    long long total_request_bytes = 0;
    long long total_prompt = 0, total_completion = 0;
    long long thread_saves = 0, thread_messages = 0;
    map<string, long long> model_loaded_by_file;  // file -> count (last wins per file)
    vector<SourceFile> source_files;              // every input file, in argument order
    map<string, long long> http_error_status;     // e.g. "429" -> count
    map<long long, long long> retry_attempts;     // attempt number -> count
    map<string, long long> stream_error_class;    // class -> count
    long long local_failures = 0;                 // http.local_failed events
    long long retried_turns_total = 0;            // dispatch.turn with retry>0
    vector<string> error_turn_samples;            // model + status lines for 4xx/5xx
    long long auth_events = 0;                    // openai.auth (routine, not an error)
    long long wall_min_ms = LLONG_MAX, wall_max_ms = 0;
    string first_ts, last_ts;

    // Pending router decision (route.turn precedes dispatch.turn)
    string pend_role, pend_complexity, pend_model, pend_effort;
    string pend_provider;   // last provider.select (persists across turns)
    int pend_orch = 0, pend_sub = 0, pend_comp = 0;

    // Router state learned from genuinely-routed turns, used to resolve
    // role=none turns (unrouted dispatches still execute under one of the
    // user's configured tiers; route.turn's model= reveals which).
    map<string, string> role_model_map; // model -> role (last routed)
    string last_role;                   // last non-none role (in turn order)
    string last_api_base;               // last openai.request URL base (persists across turns)

    // Turns are keyed by a monotonically increasing index; each dispatch.turn
    // opens a new turn and subsequent wire/stream events attach to it.
    vector<Turn> turn_list;
    Turn* cur_turn = nullptr;

    // Current event being accumulated (may span multiple lines)
    string cur_ts, cur_id, cur_level, cur_comp, cur_event, cur_payload;
    string cur_file;   // path of the file currently being parsed
    long long cur_rel = 0;
    bool have_cur = false;
};

// Process one fully-accumulated event (cur_* fields) into the aggregates.
static void process_event(Stats& s) {
    const string& ev = s.cur_event;
    const string& id = s.cur_id;
    const string& pl = s.cur_payload;

    if (ev == "route.turn") {
        s.pend_role = field(pl, "role");
        s.pend_complexity = field(pl, "complexity");
        s.pend_model = field(pl, "model");
        s.pend_effort = field(pl, "effort");
        s.pend_orch = (int)field_num(pl, "orchestrate");
        s.pend_sub = (int)field_num(pl, "subagents");
        s.pend_comp = (int)field_num(pl, "compacting");
        s.complexity_count[s.pend_complexity]++;
        s.role_count[s.pend_role]++;
        // Learn the user's tier configuration: only a genuinely-routed turn
        // authoritatively maps its model to a role.
        if (s.pend_role != "none" && !s.pend_role.empty() && !s.pend_model.empty())
            s.role_model_map[s.pend_model] = s.pend_role;
    }
    else if (ev == "dispatch.turn") {
        Turn t;
        t.id = id;
        t.has_dispatch = true;
        t.model = field(pl, "model");
        t.route = field(pl, "route");
        t.provider = field(pl, "provider");
        if (t.provider.empty()) t.provider = s.pend_provider;  // falls back to last provider.select
        t.effort = field(pl, "effort");
        t.tools = field_num(pl, "tools");
        t.ctx_window = field_num(pl, "ctx_window");
        t.max_tokens = field_num(pl, "max_tokens");
        t.retry = field_num(pl, "retry");
        if (t.retry > 0) s.retried_turns_total++;
        t.start_ms = s.cur_rel;
        t.wall_start_ms = parse_ts_ms(s.cur_ts);
        t.api_base = s.last_api_base;   // most recent request URL base
        // attach pending router decision
        t.role = s.pend_role;
        t.complexity = s.pend_complexity;
        t.orchestrate = s.pend_orch;
        t.subagents = s.pend_sub;
        t.compacting = s.pend_comp;
        if (t.model.empty()) t.model = s.pend_model;
        // Resolve the effective role. role=none means the router did not
        // re-route this turn, but it still executed under one of the tiers:
        // look the turn's model up in the router map learned from routed
        // turns; for recurring 'none's fall back to the previous known role.
        t.role_inferred = t.role;
        if (t.role.empty() || t.role == "none") {
            auto mi = s.role_model_map.find(t.model);
            if (mi != s.role_model_map.end()) {
                t.role_inferred = mi->second;
                t.role_source = 1;
            } else if (!s.last_role.empty()) {
                t.role_inferred = s.last_role;
                t.role_source = 2;
            }
        }
        if (t.role_inferred != "none" && !t.role_inferred.empty())
            s.last_role = t.role_inferred;
        s.turn_list.push_back(t);
        s.cur_turn = &s.turn_list.back();
    }
    else if (ev == "stream.end") {
        if (s.cur_turn) {
            s.cur_turn->stop = field(pl, "stop");
            s.cur_turn->end_ms = s.cur_rel;
            s.cur_turn->wall_end_ms = parse_ts_ms(s.cur_ts);
            s.cur_turn->has_end = true;
        }
        s.stop_count[field(pl, "stop")]++;
        s.status_count[field(pl, "http")]++;
    }
    else if (ev == "stream.result") {
        s.host_count[field(pl, "host")]++;
        s.status_count[field(pl, "status")]++;
    }
    else if (ev == "stream.response") {
        s.status_count[field(pl, "status")]++;
    }
    else if (ev == "openai.request") {
        if (s.cur_turn) {
            s.cur_turn->request_bytes += field_num(pl, "bytes");
            if (s.cur_turn->model.empty()) s.cur_turn->model = field(pl, "model");
            // Per-request ground truth for the provider: the request URL.
            // Reduce to a normalized base ("https://ollama.com/v1/chat/
            // completions" -> "https://ollama.com/v1") so it can be matched
            // against models.dev "api" fields after '#' stripping.
            if (s.cur_turn->api_base.empty()) {
                string pl2 = pl;
                size_t p = pl2.find("POST ");
                if (p == string::npos) p = pl2.find("GET ");
                if (p != string::npos) {
                    size_t u = pl2.find(' ', p);
                    size_t e = pl2.find(' ', u + 1);
                    string url = pl2.substr(u + 1, e == string::npos ? e : e - u - 1);
                    std::smatch um;
                    static const std::regex URL_RE("^(https?://[^/: ]+)(:(\\d+))?(/[^ ]*)?$");
                    if (std::regex_match(url, um, URL_RE)) {
                        string base = um[1].str();
                        string path = um.size() > 4 ? um[4].str() : "";
                        size_t cc = path.find("/chat/completions");
                        if (cc != string::npos) path = path.substr(0, cc);
                        size_t cm = path.find("/completions");
                        if (cm != string::npos) path = path.substr(0, cm);
                        s.cur_turn->api_base = norm_api(base + path);
                        s.last_api_base = s.cur_turn->api_base;
                    }
                }
            }
        }
        s.total_request_bytes += field_num(pl, "bytes");
    }
    else if (ev == "wire.chunk") {
        long long b = field_num(pl, "bytes");
        s.total_chunks++;
        s.total_chunk_bytes += b;
        if (s.cur_turn) {
            s.cur_turn->chunk_bytes += b;
            s.cur_turn->chunks++;
            // Ollama streams usage on EVERY chunk as a rolling cumulative
            // snapshot (not a delta). Each snapshot grows monotonically, so
            // later overwrites are correct — the final value lands on the
            // last chunk before stream.end. Never early-out on has_usage.
            std::smatch pm;
            if (std::regex_search(pl, pm, std::regex("\"prompt_tokens\":(\\d+)"))) {
                s.cur_turn->prompt_tokens = atoll(pm[1].str().c_str());
                s.cur_turn->has_usage = true;
            }
            if (std::regex_search(pl, pm, std::regex("\"completion_tokens\":(\\d+)"))) {
                s.cur_turn->completion_tokens = atoll(pm[1].str().c_str());
            }
            if (std::regex_search(pl, pm, std::regex("\"model\":\"([^\"]+)\""))) {
                if (s.cur_turn->model.empty()) s.cur_turn->model = pm[1].str();
            }
        }
    }
    else if (ev == "tool.exec") {
        string name = field(pl, "name");
        ToolStat& ts = s.tools[name];
        ts.calls++;
        long long ms = field_num(pl, "ms");
        ts.total_ms += ms;
        if (ms > ts.max_ms) ts.max_ms = ms;
        long long ok = field_num(pl, "ok");
        if (ok) ts.ok++; else ts.err++;
    }
    else if (ev == "thread.save") {
        s.thread_saves++;
        s.thread_messages += field_num(pl, "messages");
    }
    else if (ev == "models.loaded") {
        // keep per-source so multiple files don't overwrite each other
        long long cnt = field_num(pl, "count");
        s.model_loaded_by_file[s.cur_file] = cnt;
        for (auto& sf : s.source_files)
            if (sf.path == s.cur_file) { sf.models_loaded = cnt; break; }
    }
    else if (ev == "stream.retry") {
        s.retry_attempts[field_num(pl, "attempt")]++;
    }
    else if (ev == "stream.error") {
        s.stream_error_class[field(pl, "class")]++;
        string model = s.cur_turn ? s.cur_turn->model : string("?");
        if (s.error_turn_samples.size() < 8)
            s.error_turn_samples.push_back(s.cur_ts + " " + model + " " + field(pl, "msg"));
    }
    else if (ev == "stream.http_error") {
        string status = field(pl, "status");
        s.http_error_status[status]++;
        if (s.cur_turn) s.cur_turn->http_errors++;
        // per-model error attribution (turn model may still be unset)
        string model = s.cur_turn && !s.cur_turn->model.empty() ? s.cur_turn->model : field(pl, "model");
        if (!model.empty()) s.models[model].errors++;
        if (s.error_turn_samples.size() < 8)
            s.error_turn_samples.push_back(s.cur_ts + " " + (model.empty()?"?":model) + " HTTP " + status);
    }
    else if (ev == "stream.error.body") {
        // body of an error response; already counted via stream.error / http_error
    }
    else if (ev == "http.local_failed") {
        s.local_failures++;
        if (s.error_turn_samples.size() < 8)
            s.error_turn_samples.push_back(s.cur_ts + " conn_fail " + field(pl, "host"));
    }
    else if (ev == "provider.select") {
        s.pend_provider = field(pl, "provider");
        s.provider_count[s.pend_provider]++;
    }
    else if (ev == "openai.auth") {
        // routine informational line, NOT a failure — do not count as an error
        s.auth_events++;
    }

    // Only genuinely error-level events (W/E that aren't routine auth) count.
    bool is_error = (s.cur_level == "E") && ev != "openai.auth";
    if (is_error) {
        s.err_events[ev]++;
        if (s.err_samples.size() < 8) {
            s.err_samples.push_back(s.cur_ts + " " + s.cur_comp + " " + ev + ": " + pl);
        }
    }
}

// Lightweight pre-pass over one log file: scan only route.turn lines and
// record genuinely-routed (role != none) model->role mappings into
// s.role_model_map. Lets a file's tier configuration be learned even when
// the routing evidence lives in a different input file.
static void bootstrap_roles(Stats& s, const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) return; // errors are reported by the main pass
    static const std::regex ROUTE_RE(
        R"(^\S+\s+\+\d+ms\s+\S+\s+[TDIWE]\s+\w+\s+route\.turn:\s?(.*)$)");
    char* line = nullptr;
    size_t cap = 0;
    std::smatch m;
    while (getline(&line, &cap, f) > 0) {
        string sline(line);
        if (!sline.empty() && sline.back() == '\n') sline.pop_back();
        if (sline.find("route.turn") == string::npos) continue;
        if (!std::regex_match(sline, m, ROUTE_RE)) continue;
        string pl = m[1].str();
        string role = field(pl, "role");
        string model = field(pl, "model");
        if (role != "none" && !role.empty() && !model.empty())
            s.role_model_map[model] = role;
    }
    free(line);
    fclose(f);
}

// Parse one log file into the shared Stats.
static bool process_file(Stats& s, const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) { fprintf(stderr, "error: cannot open %s\n", path); return false; }
    s.cur_file = path;

    // Register every input file with its byte size so it appears in the report
    // even when it emits no parsable events (e.g. a session continuation that
    // starts mid-stream and never fires models.loaded).
    SourceFile sf;
    sf.path = path;
    {
        struct stat st;
        if (fstat(fileno(f), &st) == 0) sf.bytes = (long long)st.st_size;
    }
    s.source_files.push_back(sf);

    // File boundary: nothing from a previous file may bleed into this one,
    // except role_model_map/last_role — the user's tier configuration is
    // session-independent, so carry it forward (a session may legitimately
    // run entirely under role=none when the router keeps the active model).
    s.have_cur = false;
    s.cur_turn = nullptr;
    s.pend_role.clear(); s.pend_complexity.clear(); s.pend_model.clear();
    s.pend_effort.clear(); s.pend_provider.clear();
    s.pend_orch = s.pend_sub = s.pend_comp = 0;
    s.last_api_base.clear();

    static const std::regex LINE_RE(
        R"(^(\S+)\s+\+(\d+)ms\s+(\S+)\s+([TDIWE])\s+(\w+)\s+([\w.]+):\s?(.*)$)");

    char* line = nullptr;
    size_t cap = 0;
    ssize_t nread;

    while ((nread = getline(&line, &cap, f)) != -1) {
        string ln(line, (size_t)nread);
        // strip trailing newline
        while (!ln.empty() && (ln.back() == '\n' || ln.back() == '\r')) ln.pop_back();

        std::smatch m;
        if (std::regex_match(ln, m, LINE_RE)) {
            // Finalize the previous event before starting a new one.
            if (s.have_cur) process_event(s);

            s.cur_ts = m[1].str();
            s.cur_rel = atoll(m[2].str().c_str());
            s.cur_id = m[3].str();
            s.cur_level = m[4].str();
            s.cur_comp = m[5].str();
            s.cur_event = m[6].str();
            s.cur_payload = m[7].str();
            s.have_cur = true;

            s.level_count[s.cur_level]++;
            s.component_count[s.cur_comp]++;
            s.event_count[s.cur_event]++;
            long long wall = parse_ts_ms(s.cur_ts);
            if (wall > 0) {
                if (wall < s.wall_min_ms) { s.wall_min_ms = wall; s.first_ts = s.cur_ts; }
                if (wall > s.wall_max_ms) { s.wall_max_ms = wall; s.last_ts = s.cur_ts; }
            }
        }
        else {
            // continuation line -> append to current payload
            if (s.have_cur) {
                if (!s.cur_payload.empty()) s.cur_payload += "\n";
                s.cur_payload += ln;
            }
        }
    }

    // Finalize the last event of this file.
    if (s.have_cur) {
        process_event(s);
        s.have_cur = false;
    }

    free(line);
    fclose(f);
    return true;
}

// ---------------------------------------------------------------------------
// Minimal JSON parser + models.dev pricing (modelsdev.json)
// ---------------------------------------------------------------------------
// modelsdev.json is the agentty cache of https://models.dev/api.json:
//   { "<provider-id>": { ... "models": { "<model-key>": { ...
//       "cost": { "input": <USD/1M>, "output": <USD/1M>,
//                  "cache_read": ..., "cache_write": ... } } } } }
// All cost values are United States Dollars per 1M tokens. `cost` is absent
// for free/local models. We only need a read-only walk of the tree, so a
// compact recursive-descent parser (no external JSON dependency) suffices.

struct ModelCost {
    double in = 0, out = 0, cache_read = 0, cache_write = 0;  // USD per 1M tokens
};

struct Pricing {
    // model key (as listed under a provider's "models", e.g.
    // "claude-sonnet-4-6" or "z-ai/glm-5.2") -> (provider, costs). A key may
    // exist under several providers (resellers) with different prices.
    map<string, vector<std::pair<string, ModelCost>>> by_key;
    map<string, ModelCost> by_id;      // "provider-id\x1fmodel-key" + bare-alias entries
    map<string, bool> key_provider;    // "model-key\x1fprovider-id": provider carries this model
    map<string, string> api_to_id;     // normalized api URL -> provider id
    map<string, string> id_name;       // provider id -> display name
    string path;                    // file the pricing was loaded from
    bool loaded = false;
};

// Normalize a provider label / api URL for comparison: strip the account
// disambiguator agentty appends ("#account" to end of string), collapse
// "localhost" to "127.0.0.1", and drop a trailing "/". agentty labels
// custom-host / localhost providers by their api URL, so this is the common
// lookup form for them; flagship providers (Anthropic, Kimi, ...) carry
// short labels matched via id_name/api_to_id instead.
static string norm_api(string a) {
    size_t h = a.find('#');
    if (h != string::npos) a.erase(h);
    while (!a.empty() && isspace((unsigned char)a.back())) a.pop_back();
    while (!a.empty() && isspace((unsigned char)a.front())) a.erase(a.begin());
    while (!a.empty() && a.back() == '/') a.pop_back();
    for (size_t p; (p = a.find("://localhost")) != string::npos;)
        a.replace(p, strlen("://localhost"), "://127.0.0.1");
    // Drop explicit default ports (":443", ":80") so endpoints with and
    // without them compare equal.
    std::smatch pm;
    static const std::regex PORT_RE("^(https?://[^/: ]+):(443|80)(/.*)?$");
    if (std::regex_match(a, pm, PORT_RE))
        a = pm[1].str() + (pm.size() > 3 ? pm[3].str() : "");
    while (!a.empty() && a.back() == '/') a.pop_back();
    return a;
}

// True when the provider label denotes inference on the user's own machine
// (loopback hosts) — cost is defined as zero, not "unknown".
static bool is_local_api(const string& n) {
    return n.find("://127.0.0.1") != string::npos ||
           n.find("://0.0.0.0") != string::npos ||
           n.find("://[::1]") != string::npos;
}

// Map a turn's provider label to a canonical models.dev provider id.
// Order: exact id, display name (case-insensitive), normalized api URL.
static string provider_id_for(const Pricing& pr, const string& label,
                              const string& api_base = "") {
    if (pr.api_to_id.empty()) return "";   // no pricing loaded
    if (!label.empty()) {
        string clean = norm_api(label);
        if (pr.id_name.count(clean)) return clean;          // exact id
        for (const auto& kv : pr.id_name)
            if (iequals(kv.second, clean)) return kv.first; // display name
        auto it = pr.api_to_id.find(clean);
        if (it != pr.api_to_id.end()) return it->second;    // api URL
    }
    if (!api_base.empty()) {
        auto it2 = pr.api_to_id.find(norm_api(api_base));
        if (it2 != pr.api_to_id.end()) return it2->second; // request-URL ground truth
    }
    return "";
}

namespace json {

struct Val {
    enum Kind { NUL, BOOL, NUM, STR, ARR, OBJ } kind = NUL;
    bool b = false;
    double num = 0;
    string str;
    vector<std::unique_ptr<Val>> arr;
    vector<std::pair<string, std::unique_ptr<Val>>> obj;
    const Val* find(const string& key) const {
        if (kind != OBJ) return nullptr;
        for (const auto& kv : obj) if (kv.first == key) return kv.second.get();
        return nullptr;
    }
};

struct Parser {
    const char* p;
    const char* end;
    bool ok = true;

    void skip_ws() {
        while (p < end && (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')) p++;
    }
    bool at_end() { skip_ws(); return p >= end; }

    string parse_string() {
        string out;
        p++;  // opening quote
        while (p < end && *p != '"') {
            char c = *p++;
            if (c == '\\') {
                if (p >= end) { ok = false; break; }
                char e = *p++;
                switch (e) {
                    case '"':  out += '"';  break;
                    case '\\': out += '\\'; break;
                    case '/':  out += '/';  break;
                    case 'n':  out += '\n'; break;
                    case 't':  out += '\t'; break;
                    case 'r':  out += '\r'; break;
                    case 'b': case 'f': break;
                    case 'u':  // skip 4 hex digits; model keys/ids are ASCII
                        if (end - p >= 4) p += 4; else ok = false;
                        break;
                    default: ok = false; break;
                }
            } else {
                out += c;
            }
        }
        if (p >= end) { ok = false; return out; }
        p++;  // closing quote
        return out;
    }

    bool parse_number(double& out) {
        char* e = nullptr;
        double d = strtod(const_cast<char*>(p), &e);
        if (e == p) { ok = false; return false; }
        out = d;
        p = e;
        return true;
    }

    bool parse_value(std::unique_ptr<Val>& v, int depth) {
        if (depth > 64) { ok = false; return false; }
        skip_ws();
        if (p >= end) { ok = false; return false; }
        char c = *p;
        if (c == '{') {
            v->kind = Val::OBJ; p++;
            skip_ws();
            if (p < end && *p == '}') { p++; return true; }
            while (ok) {
                skip_ws();
                if (p >= end || *p != '"') { ok = false; break; }
                string key = parse_string();
                if (!ok) break;
                skip_ws();
                if (p >= end || *p != ':') { ok = false; break; }
                p++;
                std::unique_ptr<Val> child(new Val());
                if (!parse_value(child, depth + 1)) break;
                v->obj.push_back({key, std::move(child)});
                skip_ws();
                if (p < end && *p == ',') { p++; continue; }
                if (p < end && *p == '}') { p++; return true; }
                ok = false;
            }
            return false;
        }
        if (c == '[') {
            v->kind = Val::ARR; p++;
            skip_ws();
            if (p < end && *p == ']') { p++; return true; }
            while (ok) {
                std::unique_ptr<Val> child(new Val());
                if (!parse_value(child, depth + 1)) break;
                v->arr.push_back(std::move(child));
                skip_ws();
                if (p < end && *p == ',') { p++; continue; }
                if (p < end && *p == ']') { p++; return true; }
                ok = false;
            }
            return false;
        }
        if (c == '"') { v->kind = Val::STR; v->str = parse_string(); return ok; }
        if (c == 't') { if (end - p >= 4 && strncmp(p, "true", 4) == 0) { v->kind = Val::BOOL; v->b = true; p += 4; return true; } ok = false; return false; }
        if (c == 'f') { if (end - p >= 5 && strncmp(p, "false", 5) == 0) { v->kind = Val::BOOL; p += 5; return true; } ok = false; return false; }
        if (c == 'n') { if (end - p >= 4 && strncmp(p, "null", 4) == 0) { v->kind = Val::NUL; p += 4; return true; } ok = false; return false; }
        if (parse_number(v->num)) { v->kind = Val::NUM; return true; }
        return false;
    }
};

}  // namespace json

// ---------------------------------------------------------------------------
// Pricing: load modelsdev.json and resolve log model names to USD rates
// ---------------------------------------------------------------------------

static double cost_num(const json::Val* cost, const char* key) {
    if (!cost) return 0;
    const json::Val* v = cost->find(key);
    return (v && v->kind == json::Val::NUM) ? v->num : 0;
}

// Walk providers -> models -> cost{} and flatten into Pricing. Every (key,
// provider) pair is kept; reseller prices differ, and log turns usually carry
// provider= so the right entry can be picked during resolution.
static bool pricing_from_json(const string& buf, Pricing& pr) {
    json::Parser ps{buf.data(), buf.data() + buf.size()};
    std::unique_ptr<json::Val> root(new json::Val());
    if (!ps.parse_value(root, 0)) return false;
    ps.skip_ws();
    if (!ps.at_end()) return false;
    if (root->kind != json::Val::OBJ) return false;
    for (const auto& pv : root->obj) {
        const string& provider = pv.first;
        const json::Val* name_val = pv.second->find("name");
        pr.id_name[provider] = (name_val && name_val->kind == json::Val::STR)
                                   ? name_val->str : provider;
        const json::Val* api_val = pv.second->find("api");
        if (api_val && api_val->kind == json::Val::STR) {
            string a = norm_api(api_val->str);
            // First provider wins on a shared api URL: a provider and its
            // "coding-plan" sibling share an endpoint, and per-model prices
            // are what matter anyway.
            if (!a.empty() && !pr.api_to_id.count(a)) pr.api_to_id[a] = provider;
        }
        const json::Val* models_obj = pv.second->find("models");
        if (!models_obj || models_obj->kind != json::Val::OBJ) continue;
        for (const auto& mv : models_obj->obj) {
            const json::Val* cost = mv.second->find("cost");
            ModelCost mc;
            if (cost && cost->kind == json::Val::OBJ) {
                mc.in = cost_num(cost, "input");
                mc.out = cost_num(cost, "output");
                mc.cache_read = cost_num(cost, "cache_read");
                mc.cache_write = cost_num(cost, "cache_write");
            }
            // ^ cost absent -> provider carries the model for free (local
            // inference, ollama-cloud, ...). It is still recorded in the
            // listing (key_provider) and as a $0 by_id rate, so a turn pinned
            // to that provider prices as $0 instead of inheriting a random
            // reseller's rate.
            string key = mv.first;
            size_t slash = key.rfind('/');
            string alias = (slash == string::npos) ? key : key.substr(slash + 1);
            if (cost && cost->kind == json::Val::OBJ)
                pr.by_key[key].push_back({provider, mc});
            pr.by_id[provider + "\x1f" + alias] = mc;
            if (alias != key)
                pr.by_id[provider + "\x1f" + key] = mc;
            for (const string& k : {key, alias})
                pr.key_provider[k + "\x1f" + provider] = true;
        }
    }
    return !pr.by_key.empty();
}

// Load the pricing file. Returns false if the path was explicitly given
// (flag or env) but unreadable, or the file exists but doesn't parse.
//   missing_default_path : a default-candidate path did not exist -> caller
//                          should try the next candidate, not hard-fail.
static bool load_pricing(const string& path, Pricing& pr, bool& missing_default_path) {
    FILE* f = fopen(path.c_str(), "rb");
    if (!f) {
        missing_default_path = true;
        return false;
    }
    missing_default_path = false;
    string buf;
    {
        char chunk[65536];
        size_t n;
        while ((n = fread(chunk, 1, sizeof chunk, f)) > 0) buf.append(chunk, n);
    }
    bool closed = (fclose(f) == 0);
    if (!closed || buf.empty() || !pricing_from_json(buf, pr)) return false;
    pr.path = path;
    pr.loaded = true;
    return true;
}

struct Rate {          // resolved USD-per-1M-token rates
    double in = 0, out = 0;
    bool exact = true; // false when matched by fuzzy date-prefix
};

// Exact-key resolution for one candidate key against the pricing table.
// models.dev is the sole source of truth and is provider-agnostic: when
// several providers list the same model key (resellers), the cheapest
// metered (non-zero) input rate wins; a sole zero-cost entry prices at $0.
static bool rate_for_key(const Pricing& pr, const string& key, Rate& r) {
    auto it = pr.by_key.find(key);
    if (it == pr.by_key.end()) return false;
    const vector<std::pair<string, ModelCost>>& cands = it->second;
    const std::pair<string, ModelCost>* pick = &cands[0];
    const std::pair<string, ModelCost>* best = nullptr;
    for (const auto& cand : cands)
        if (cand.second.in > 0 || cand.second.out > 0)
            if (!best || cand.second.in < best->second.in) best = &cand;
    if (best) pick = best;
    r.in = pick->second.in;
    r.out = pick->second.out;
    r.exact = true;
    return true;
}

// Resolve a log model name to rates. Order: exact key, then the listed key
// whose trailing date stamp is stripped ("gpt-5.1-2025-11-13" -> "gpt-5.1",
// "glm-5.2-20251113" -> "glm-5.2"), else not priced.
// Resolve the USD-per-1M rate for a turn's model, preferring the pricing of
// the turn's provider when known. Models.dev keys may carry a namespace
// prefix (e.g. "z-ai/glm-5.2") that agentty drops in the logs; conversely
// some entries exist only under the unprefixed key.
static bool resolve_cost(const Pricing& pr, const string& model, Rate& r) {
    if (model.empty() || !pr.loaded) return false;
    if (rate_for_key(pr, model, r)) return true;
    static const std::regex DATE_STAMP_RE("-(\\d{4}-\\d{2}-\\d{2}|\\d{8,14})$");
    std::smatch dm;
    if (std::regex_search(model, dm, DATE_STAMP_RE)) {
        string base = model.substr(0, model.size() - dm[0].length());
        if (rate_for_key(pr, base, r)) { r.exact = false; return true; }
    }
    return false;
}

// Provider-pinned variant: restricts matching to the given models.dev
// provider id, so a turn on https://ollama.com/v1 pays ollama-cloud prices,
// not the cheapest reseller's. model_key_out (when non-null) receives the
// models.dev model key that matched, for reporting.
static bool resolve_cost_for_provider(const Pricing& pr, const string& model,
                                      const string& pid, ModelCost& mc, string* model_key_out) {
    auto scoped = [&](const string& key, ModelCost& out) -> bool {
        if (pid.empty()) return false;
        auto it = pr.by_id.find(pid + "\x1f" + key);
        if (it != pr.by_id.end()) { out = it->second; return true; }
        for (auto& kv : pr.by_id) {
            size_t sep = kv.first.find('\x1f');
            if (sep == string::npos) continue;
            if (kv.first.substr(0, sep) != pid) continue;
            if (iequals(kv.first.substr(sep + 1), key)) { out = kv.second; return true; }
        }
        return false;
    };
    if (scoped(model, mc)) { if (model_key_out) *model_key_out = model; return true; }
    size_t slash = model.rfind('/');
    if (slash != string::npos) {
        if (scoped(model.substr(slash + 1), mc)) { if (model_key_out) *model_key_out = model.substr(slash + 1); return true; }
    } else {
        for (const auto& kv : pr.key_provider) {                   // try namespaced keys
            size_t sep = kv.first.find('\x1f');
            if (sep == string::npos || kv.first.substr(sep + 1) != pid) continue;
            string full = kv.first.substr(0, sep);
            size_t fs = full.rfind('/');
            if (fs != string::npos && iequals(full.substr(fs + 1), model)) {
                if (scoped(full, mc)) { if (model_key_out) *model_key_out = full; return true; }
            }
        }
    }
    static const std::regex DATE_STAMP_RE("-(\\d{4}-\\d{2}-\\d{2}|\\d{8,14})$");
    std::smatch dm;
    if (std::regex_search(model, dm, DATE_STAMP_RE)) {
        string base = model.substr(0, model.size() - dm[0].length());
        if (scoped(base, mc)) { if (model_key_out) *model_key_out = base; return true; }
        if (slash != string::npos) {
            string b = base.substr(base.rfind('/') + 1);
            if (scoped(b, mc)) { if (model_key_out) *model_key_out = b; return true; }
        }
    }
    return false;
}

// Format a percentage share: one decimal (e.g. "58.9"), no % sign — the
// column header already says %.
static string pct_fmt(double v) {
    std::ostringstream os;
    os.imbue(std::locale::classic());
    os << std::fixed << std::setprecision(1) << v;
    return os.str();
}

// Format a USD amount: enough precision for sub-cent values, trimmed for big ones.
static string usd_fmt(double v) {
    char b[64];
    double a = v < 0 ? -v : v;
    if (a > 0 && a < 0.01)      snprintf(b, sizeof b, "$%.6f", v);
    else if (a >= 1000)         snprintf(b, sizeof b, "$%.2f", v);
    else                        snprintf(b, sizeof b, "$%.4f", v);
    return b;
}

// Per-model cost accumulator (USD, rates from models.dev).
struct CostAcc {
    long long turns = 0;
    double rate_in = 0, rate_out = 0;   // USD per 1M tokens
    double input_usd = 0, output_usd = 0, total_usd = 0;
    bool exact_rate = true;
    string disp_provider, disp_model, disp_model_key;
};

// Sort a string->count map into a vector ordered by count descending (then
// key ascending, for stable tie-breaks). Used by every two-column report
// table so the biggest items lead.
static vector<std::pair<string, long long>> sorted_pairs(const map<string, long long>& m) {
    vector<std::pair<string, long long>> v(m.begin(), m.end());
    std::stable_sort(v.begin(), v.end(),
                     [](const std::pair<string, long long>& a, const std::pair<string, long long>& b) {
                         if (a.second != b.second) return a.second > b.second;
                         return a.first < b.first;
                     });
    return v;
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------

int main(int argc, char** argv) {
    // Arg parsing: <log-file>... <output.md> [--cost /path/to/modelsdev.json] [--no-cost]
    vector<const char*> pos;
    bool no_cost = false;
    const char* cost_flag = nullptr;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--no-cost") == 0) { no_cost = true; continue; }
        if (strcmp(argv[i], "--cost") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "error: --cost requires a path argument\n");
                return 2;
            }
            cost_flag = argv[++i];
            continue;
        }
        pos.push_back(argv[i]);
    }
    if (pos.size() < 2) {
        fprintf(stderr, "usage: %s <log-file>... <output.md> [--cost /path/to/modelsdev.json] [--no-cost]\n", argv[0]);
        return 2;
    }
    const char* out_path = pos.back();
    size_t n_inputs = pos.size() - 1;

    // Resolve the models.dev pricing file (default: agentty's cache).
    // NOTE: default path is NOT auto-created; see error message below when missing.
    const char* pricing_path = cost_flag;
    bool pricing_default = false;
    if (!no_cost && !pricing_path) {
        const char* envp = getenv("AGENTTY_MODELS_DEV");
        if (envp && *envp) pricing_path = envp;
    }
    if (!no_cost && !pricing_path) {
        static char cand[4096];
        const char* home = getenv("HOME");
        const char* prof = getenv("USERPROFILE");
        if (home && *home)        { snprintf(cand, sizeof cand, "%s/.agentty/cache/modelsdev.json", home); pricing_path = cand; }
        else if (prof && *prof)   { snprintf(cand, sizeof cand, "%s/.agentty/cache/modelsdev.json", prof); pricing_path = cand; }
        else                      { pricing_path = "~/.agentty/cache/modelsdev.json"; }
        pricing_default = true;
    }

    Stats s;
    vector<string> sources;
    // Bootstrap pass: learn the tier configuration (model -> role) from
    // genuinely-routed turns in ALL inputs before the real parse, so that a
    // session starting with role=none still resolves via the router state
    // even when that routing evidence lives in a later file on the command
    // line. The main parse then refines with per-session chronology.
    for (size_t i = 0; i < n_inputs; i++) bootstrap_roles(s, pos[i]);
    for (size_t i = 0; i < n_inputs; i++) {
        if (!process_file(s, pos[i])) return 1;
        sources.push_back(pos[i]);
    }

    // ---- Aggregate per-model and totals from turns ----
    for (Turn& t : s.turn_list) {
        ModelStat& ms = s.models[t.model];
        ms.turns++;
        ms.prompt_tokens += t.prompt_tokens;
        ms.completion_tokens += t.completion_tokens;
        ms.request_bytes += t.request_bytes;
        ms.chunk_bytes += t.chunk_bytes;
        ms.chunks += t.chunks;
        if (t.has_usage) ms.usage_turns++;
        if (t.retry > 0) ms.retried_turns++;
        ms.errors += t.http_errors;
        s.total_prompt += t.prompt_tokens;
        s.total_completion += t.completion_tokens;
    }

    // ---- Cost: resolve rates and accumulate per-model USD ----
    // Rates come from agentty's models.dev cache; see load_pricing().
    Pricing pricing;
    bool pricing_missing = false;      // default candidate path did not exist
    bool pricing_bad = false;          // explicitly given but unreadable/unparseable
    bool pricing_enabled = !no_cost;
    if (pricing_enabled) {
        bool skip;
        if (!load_pricing(pricing_path, pricing, skip)) {
            if (skip && pricing_default) pricing_missing = true;
            else pricing_bad = true;
            pricing_enabled = false;
        }
    }
    map<string, CostAcc> cost_acc;
    if (pricing_enabled) {
        // Resolve each turn against its provider's own pricing when known
        // (agentty labels custom-host/localhost providers by api URL, e.g.
        // "https://ollama.com/v1#main" -> models.dev id "ollama-cloud"),
        // falling back to the provider-agnostic cheapest rate. Loopback
        // hosts are local inference: fixed at $0, not "unpriced".
        for (Turn& t : s.turn_list) {
            if (t.model.empty()) continue;
            string pid = provider_id_for(pricing, t.provider, t.api_base);
            string prov_disp = t.provider.empty()
                ? (t.api_base.empty() ? "(unspecified)" : t.api_base)
                : norm_api(t.provider);
            if (t.provider.empty() && !pid.empty()) prov_disp = pid;
            string mkey = t.model;
            bool exact = true;
            ModelCost mc;
            bool local = is_local_api(prov_disp) || is_local_api(norm_api(t.api_base));
            if (!local) {
                bool pinned_priced = false, listed_at_provider = false;
                if (!pid.empty()) {
                    pinned_priced = resolve_cost_for_provider(pricing, t.model, pid, mc, &mkey);
                    if (!pinned_priced) {
                        // Provider carries the model but publishes no cost
                        // catalog entry for it (e.g. ollama-cloud models have
                        // cost absent): treat as provider-free at $0, not
                        // "unpriced" and not some reseller's rate.
                        string bare = t.model.substr(t.model.rfind('/') + 1);
                        for (const string& k : {t.model, bare}) {
                            if (pricing.key_provider.count(k + "\x1f" + pid))
                                { listed_at_provider = true; break; }
                        }
                    }
                }
                if (listed_at_provider) {
                    mc.in = mc.out = 0;   // provider-free: cost defined as $0
                } else if (!pinned_priced) {
                    Rate rr;
                    if (!resolve_cost(pricing, t.model, rr)) {
                        t.unpriced = true;
                        continue;
                    }
                    mc.in = rr.in; mc.out = rr.out;
                    exact = rr.exact;
                }
                if (pid.empty()) {
                    // report which provider the rate came from, if unambiguous
                    for (auto& kv : pricing.key_provider) {
                        size_t sep = kv.first.find('\x1f');
                        if (sep == string::npos) continue;
                        if (!iequals(kv.first.substr(0, sep), mkey) && kv.first.substr(0, sep) != mkey) continue;
                        prov_disp = "(cheapest) " + kv.first.substr(sep + 1);
                        break;
                    }
                } else {
                    prov_disp = pid;
                }
            }
            if (local) prov_disp = t.model + " (local)";
            t.cost = (double)t.prompt_tokens / 1e6 * mc.in +
                     (double)t.completion_tokens / 1e6 * mc.out;
            t.has_cost = true;
            CostAcc& a = cost_acc[prov_disp + "\x1f" + t.model + "\x1f" + mkey];
            if (a.turns == 0) {
                a.rate_in = mc.in;
                a.rate_out = mc.out;
                a.exact_rate = exact;
            } else if (a.rate_in != mc.in || a.rate_out != mc.out) {
                a.exact_rate = false;  // mixed rates across turns
            }
            a.turns++;
            a.input_usd += (double)t.prompt_tokens / 1e6 * mc.in;
            a.output_usd += (double)t.completion_tokens / 1e6 * mc.out;
        }
        for (auto& kv : cost_acc) {
            kv.second.total_usd = kv.second.input_usd + kv.second.output_usd;
            size_t sep1 = kv.first.find('\x1f');
            size_t sep2 = kv.first.find('\x1f', sep1 == string::npos ? sep1 : sep1 + 1);
            kv.second.disp_provider = kv.first.substr(0, sep1);
            kv.second.disp_model = kv.first.substr(sep1 + 1, sep2 - sep1 - 1);
            kv.second.disp_model_key = sep2 == string::npos ? kv.second.disp_model
                                     : kv.first.substr(sep2 + 1);
        }
    }

    // ---- Build report ----
    if (pricing_missing || pricing_bad) {
        fprintf(stderr,
            "error: modelsdev.json %s at '%s'.\n"
            "\n"
            "Cost reporting requires the models.dev pricing cache that agentty\n"
            "refreshes every 24 hours, normally at:\n"
            "    $AGENTTY_HOME/cache/modelsdev.json   (default: ~/.agentty/cache/modelsdev.json)\n"
            "\n"
            "Fix it by pointing agentty-stats at the file, then re-run:\n"
            "    agentty-stats <log-files>... <output.md> --cost /path/to/modelsdev.json\n"
            "or export AGENTTY_MODELS_DEV=/path/to/modelsdev.json\n"
            "\n"
            "If AGENTTY_HOME is set to a non-default location, use:\n"
            "    --cost \"$AGENTTY_HOME/cache/modelsdev.json\"\n"
            "\n"
            "To skip cost reporting entirely, re-run with --no-cost.\n",
            pricing_missing ? "was not found" : "exists but could not be parsed",
            pricing_path);
        return 1;
    }
    std::ostringstream o;
    o << "# agentty — Session Statistics Report\n\n";
    if (!no_cost) {
        o << "**Pricing source:** [models.dev](https://models.dev) (agentty cache: `" << pricing_path << "`, USD per 1M tokens)\n\n";
    }
    o << "---\n\n";

    // 1. Overview
    o << "## 1. Overview\n\n";
    o << "| Metric | Value |\n|---|---|\n";
    o << "| Total turns (dispatches) | " << s.turn_list.size() << " |\n";
    o << "| Time span | " << s.first_ts << " → " << s.last_ts << " (" << human_ms(s.wall_max_ms - s.wall_min_ms) << ") |\n";
    o << "| Models used | ";
    {
        bool first = true;
        for (auto& kv : s.models) { if (!first) o << ", "; first = false; o << kv.first; }
        o << " |\n";
    }
    o << "| Total prompt tokens | " << human_tokens(s.total_prompt) << " (" << s.total_prompt << ") |\n";
    o << "| Total completion tokens | " << human_tokens(s.total_completion) << " (" << s.total_completion << ") |\n";
    o << "| Total tokens | " << human_tokens(s.total_prompt + s.total_completion) << " |\n";
    {
        double grand = 0;
        for (auto& kv : cost_acc) grand += kv.second.total_usd;
        o << "| Estimated cost | " << (cost_acc.empty() ? "n/a" : usd_fmt(grand) + (pricing_enabled ? "" : " (pricing unavailable)")) << " |\n";
    }
    o << "| Wire chunks | " << s.total_chunks << " (" << human_bytes(s.total_chunk_bytes) << ") |\n";
    o << "| Request bytes | " << human_bytes(s.total_request_bytes) << " |\n";
    o << "| Tool calls | " << ([] (const map<string,ToolStat>& t){ long long n=0; for(auto&kv:t)n+=kv.second.calls; return n; })(s.tools) << " |\n";
    o << "| Thread saves | " << s.thread_saves << " (" << s.thread_messages << " messages) |\n";
    o << "| Models loaded | ";
    if (s.source_files.empty()) o << "0";
    else {
        bool first = true;
        for (auto& sf : s.source_files) {
            if (!first) o << "; ";
            first = false;
            // basename for readability
            string base = sf.path;
            size_t slash = base.find_last_of('/');
            if (slash != string::npos) base = base.substr(slash + 1);
            o << base << "=";
            if (sf.models_loaded >= 0) o << sf.models_loaded;
            else o << "n/a";   // session continuation: no models.loaded event in this file
        }
    }
    o << " |\n";
    o << "| Source files | " << s.source_files.size() << " (";
    {
        long long tot = 0;
        for (auto& sf : s.source_files) tot += sf.bytes;
        o << human_bytes(tot);
    }
    o << " total)\n";
    for (auto& sf : s.source_files) {
        string base = sf.path;
        size_t slash = base.find_last_of('/');
        if (slash != string::npos) base = base.substr(slash + 1);
        o << "<br>" << base << " " << human_bytes(sf.bytes);
    }
    o << " |\n";
    o << "| Error-level events | " << s.level_count["E"] - s.auth_events << " (" << s.auth_events << " routine auth) |\n\n";

    // 2. Log volume by level / component / event
    o << "## 2. Log volume\n\n";
    o << "### By level\n\n| Level | Count |\n|---|---|\n";
    for (auto& kv : sorted_pairs(s.level_count)) o << "| " << kv.first << " | " << kv.second << " |\n";
    o << "\n### By component\n\n| Component | Count |\n|---|---|\n";
    for (auto& kv : sorted_pairs(s.component_count)) o << "| " << kv.first << " | " << kv.second << " |\n";
    o << "\n### By event\n\n| Event | Count |\n|---|---|\n";
    for (auto& kv : sorted_pairs(s.event_count)) o << "| " << kv.first << " | " << kv.second << " |\n";
    o << "\n";

    // 3. Smart-mode routing
    o << "## 3. Smart-mode routing\n\n";
    const long long total_turns_n = (long long)s.turn_list.size();
    // `route.turn`'s role= is the router's decision for that turn; 'none'
    // means the router did not re-route (the turn kept the active model),
    // not that it ran outside the tiers — every route.turn line carries a
    // model= that reveals which tier executed it. Resolve 'none' via a
    // model→role map learned from genuinely-routed turns (recurring 'none's
    // fall back to the previous resolved role).
    {
        map<string, long long> role_res;
        map<string, long long> role_res_prompt, role_res_compl;
        vector<string> map_notes;
        long long src_model = 0, src_prev = 0, src_unres = 0;
        long long tot_prompt = 0, tot_compl = 0;
        for (Turn& t : s.turn_list) {
            const string r = t.role_inferred.empty() ? "(unknown)" : t.role_inferred;
            role_res[r]++;
            role_res_prompt[r] += t.prompt_tokens;
            role_res_compl[r] += t.completion_tokens;
            tot_prompt += t.prompt_tokens;
            tot_compl += t.completion_tokens;
            if (t.role_source == 1) src_model++;
            else if (t.role_source == 2) src_prev++;
            else if (t.role_inferred.empty() || t.role_inferred == "none") src_unres++;
        }
        for (auto& kv : s.role_model_map)
            map_notes.push_back("`" + kv.first + "` → " + kv.second);
        o << "### Role\n\n"
          << "Turns the router logged as `role=none` are attributed to the tier whose\n"
          << "model actually executed them, via the router map learned from routed turns\n"
          << "(";
        for (size_t i = 0; i < map_notes.size(); i++)
            o << (i ? ", " : "") << map_notes[i];
        o << "); recurring `none`s fall back to the previous resolved role.\n\n";
        o << "| Role | Turns | % of total |\n|---|---|---|\n";
        for (auto& kv : sorted_pairs(role_res))
            o << "| " << kv.first << " | " << kv.second << " | "
              << (total_turns_n ? pct_fmt(100.0 * (double)kv.second / (double)total_turns_n) : "-") << " |\n";
        // Turn counts are a skewed proxy: one turn re-sends the whole
        // conversation context, so token volume is the fair comparison with
        // provider-side (e.g. ollama.com) usage reports.
        vector<string> tok_keys;
        for (auto& kv : role_res_prompt) tok_keys.push_back(kv.first);
        std::sort(tok_keys.begin(), tok_keys.end(), [&](const string& a, const string& b) {
            long long ta = role_res_prompt[a] + role_res_compl[a], tb = role_res_prompt[b] + role_res_compl[b];
            return ta != tb ? ta > tb : a < b;
        });
        o << "\n**Token share by tier:**\n\n"
          << "| Role | Prompt tok | Completion tok | Total tok | % of tokens |\n|---|---|---|---|---|\n";
        for (auto& k : tok_keys) {
            long long tot = role_res_prompt[k] + role_res_compl[k];
            o << "| " << k << " | " << human_tokens(role_res_prompt[k]) << " | "
              << human_tokens(role_res_compl[k]) << " | " << human_tokens(tot) << " | "
              << (tot_prompt + tot_compl ? pct_fmt(100.0 * (double)tot / (double)(tot_prompt + tot_compl)) : "-") << " |\n";
        }
        if (src_model + src_prev > 0 || src_unres > 0)
            o << "\n_" << src_model << " turn(s) resolved via model→role map, "
              << src_prev << " via previous role"
              << (src_unres ? ", " + std::to_string(src_unres) + " left unresolved" : "")
              << "._\n";
    }
    o << "\n### Complexity\n\n| Complexity | Turns | % of total |\n|---|---|---|\n";
    for (auto& kv : sorted_pairs(s.complexity_count))
        o << "| " << kv.first << " | " << kv.second << " | "
          << (total_turns_n ? pct_fmt(100.0 * (double)kv.second / (double)total_turns_n) : "-") << " |\n";
    o << "\n### Orchestration flags\n\n";
    {
        long long orch=0, sub=0, comp=0;
        for (Turn& t : s.turn_list) { orch += t.orchestrate; sub += t.subagents; comp += t.compacting; }
        o << "- Orchestrate: " << orch << " / " << s.turn_list.size() << " turns\n";
        o << "- Subagents: " << sub << " / " << s.turn_list.size() << " turns\n";
        o << "- Compacting: " << comp << " / " << s.turn_list.size() << " turns\n";
    }
    o << "\n";

    // 4. Per-model usage
    o << "## 4. Per-model usage\n\n";
    o << "| Model | Turns | Prompt tok | Completion tok | Total tok | Req bytes | Chunk bytes | Chunks | Retried | Errors |\n";
    o << "|---|---|---|---|---|---|---|---|---|---|\n";
    {
        vector<const std::pair<const string, ModelStat>*> model_rows;
        for (const auto& kv : s.models) model_rows.push_back(&kv);
        std::stable_sort(model_rows.begin(), model_rows.end(),
                         [](const std::pair<const string, ModelStat>* a,
                            const std::pair<const string, ModelStat>* b) {
                             if (a->second.turns != b->second.turns) return a->second.turns > b->second.turns;
                             return a->first < b->first;
                         });
        for (const auto* kv : model_rows) {
            const string& name = kv->first;
            const ModelStat& ms = kv->second;
            o << "| " << name << " | " << ms.turns
              << " | " << human_tokens(ms.prompt_tokens)
              << " | " << human_tokens(ms.completion_tokens)
              << " | " << human_tokens(ms.prompt_tokens + ms.completion_tokens)
              << " | " << human_bytes(ms.request_bytes)
              << " | " << human_bytes(ms.chunk_bytes)
              << " | " << ms.chunks
              << " | " << ms.retried_turns
              << " | " << ms.errors << " |\n";
        }
    }
    o << "\n";

    // 4b. Cost (USD) — rates from models.dev via agentty's cache
    o << "## 4b. Cost (USD)\n\n";
    o << "*Prices from [models.dev](https://models.dev), loaded from `" << pricing_path
      << "`; all amounts are United States Dollars (USD). Cost = prompt/1M × input-rate + completion/1M × output-rate.*\n\n";
    if (no_cost) {
        o << "*Cost reporting disabled (`--no-cost`).*\n\n";
    } else if (cost_acc.empty()) {
        o << "*No priced models: none of the models in the logs could be matched to a models.dev entry.*\n\n";
    } else {
        o << "| Provider | Model | $/1M in | Input cost | $/1M out | Output cost | Turns | Total cost |\n";
        o << "|---|---|---|---|---|---|---|---|\n";
        vector<const std::pair<const string, CostAcc>*> cost_rows;
        for (const auto& kv : cost_acc) cost_rows.push_back(&kv);
        std::stable_sort(cost_rows.begin(), cost_rows.end(),
                         [](const std::pair<const string, CostAcc>* a,
                            const std::pair<const string, CostAcc>* b) {
                             if (a->second.total_usd != b->second.total_usd)
                                 return a->second.total_usd > b->second.total_usd;
                             return a->first < b->first;
                         });
        double grand_total = 0;
        for (const auto* kv : cost_rows) {
            const CostAcc& a = kv->second;
            grand_total += a.total_usd;
            string rate_in = usd_fmt(a.rate_in), rate_out = usd_fmt(a.rate_out);
            if (!a.exact_rate) { rate_in += "\\*"; rate_out += "\\*"; }
            o << "| " << a.disp_provider
              << " | " << a.disp_model
              << " | " << rate_in
              << " | " << usd_fmt(a.input_usd)
              << " | " << rate_out
              << " | " << usd_fmt(a.output_usd)
              << " | " << a.turns
              << " | " << usd_fmt(a.total_usd) << " |\n";
        }
        o << "| **Total** | | | | | | | **" << usd_fmt(grand_total) << "** |\n\n";
        long long unpriced_turns = 0;
        for (auto& kv : s.models) {
            bool any_priced = false;
            for (auto& c : cost_acc)
                if (c.second.disp_model == kv.first) { any_priced = true; break; }
            if (any_priced) continue;
            unpriced_turns += kv.second.turns;
            o << "*No pricing data for model `" << kv.first << "` (" << kv.second.turns
              << " turns, " << human_tokens(kv.second.prompt_tokens + kv.second.completion_tokens) << " tokens) — excluded from cost totals.*\n";
        }
        if (unpriced_turns) o << "\n";
        o << "*Note: estimates use input/output token counts from the logs; cache-read/cache-write tokens are not logged and are therefore not reflected in these figures.*\n\n";
    }

    // 5. Tool usage
    o << "## 5. Tool usage\n\n";
    o << "| Tool | Calls | Total | Avg | Max | ok | err |\n";
    o << "|---|---|---|---|---|---|---|\n";
    {
        vector<const std::pair<const string, ToolStat>*> tool_rows;
        for (const auto& kv : s.tools) tool_rows.push_back(&kv);
        std::stable_sort(tool_rows.begin(), tool_rows.end(),
                         [](const std::pair<const string, ToolStat>* a,
                            const std::pair<const string, ToolStat>* b) {
                             if (a->second.calls != b->second.calls) return a->second.calls > b->second.calls;
                             return a->first < b->first;
                         });
        for (const auto* kv : tool_rows) {
            const ToolStat& ts = kv->second;
            o << "| " << kv->first << " | " << ts.calls
              << " | " << human_ms(ts.total_ms)
              << " | " << human_ms(ts.calls ? ts.total_ms / ts.calls : 0)
              << " | " << human_ms(ts.max_ms)
              << " | " << ts.ok << " | " << ts.err << " |\n";
        }
    }
    o << "\n";

    // 6. Wire / streaming
    o << "## 6. Wire / streaming\n\n";
    o << "### Stop reasons\n\n| Stop | Count |\n|---|---|\n";
    for (auto& kv : sorted_pairs(s.stop_count)) o << "| " << kv.first << " | " << kv.second << " |\n";
    o << "\n### HTTP status\n\n| Status | Count |\n|---|---|\n";
    for (auto& kv : sorted_pairs(s.status_count)) o << "| " << kv.first << " | " << kv.second << " |\n";
    o << "\n### Hosts\n\n| Host | Count |\n|---|---|\n";
    for (auto& kv : sorted_pairs(s.host_count)) o << "| " << kv.first << " | " << kv.second << " |\n";
    o << "\n### Providers\n\n| Provider | Count |\n|---|---|\n";
    for (auto& kv : sorted_pairs(s.provider_count)) o << "| " << kv.first << " | " << kv.second << " |\n";
    o << "\n";

    // 6b. Failures & retries
    bool any_fail = !s.http_error_status.empty() || s.retried_turns_total > 0 ||
                    s.local_failures > 0 || !s.retry_attempts.empty();
    o << "## 6b. Failures & retries\n\n";
    if (!any_fail) {
        o << "No retry or HTTP-failure events recorded.\n\n";
    } else {
        o << "| Signal | Count |\n|---|---|\n";
        o << "| Retried turns (dispatch retry>0) | " << s.retried_turns_total << " |\n";
        long long http_errs = 0;
        for (auto& kv : s.http_error_status) http_errs += kv.second;
        o << "| HTTP error turns | " << http_errs << " |\n";
        o << "| stream.retry attempts | ";
        {
            long long n = 0;
            for (auto& kv : s.retry_attempts) n += kv.second;
            o << n << " |\n";
        }
        o << "| Connection failures (http.local_failed) | " << s.local_failures << " |\n";
        o << "\n";
        if (!s.http_error_status.empty()) {
            o << "### HTTP error status\n\n| Status | Count |\n|---|---|\n";
            for (auto& kv : sorted_pairs(s.http_error_status)) o << "| " << kv.first << " | " << kv.second << " |\n";
            o << "\n";
        }
        if (!s.retry_attempts.empty()) {
            o << "### Retry attempts\n\n| Attempt | Count |\n|---|---|\n";
            for (auto& kv : s.retry_attempts)
                o << "| " << kv.first << " | " << kv.second << " |\n";
            o << "\n";
        }
        if (!s.stream_error_class.empty()) {
            o << "### stream.error classes\n\n| Class | Count |\n|---|---|\n";
            for (auto& kv : sorted_pairs(s.stream_error_class)) o << "| " << kv.first << " | " << kv.second << " |\n";
            o << "\n";
        }
        if (!s.error_turn_samples.empty()) {
            o << "**Samples:**\n\n```\n";
            for (auto& str : s.error_turn_samples) o << str << "\n";
            o << "```\n\n";
        }
    }


    // 7. Turn-by-turn detail
    o << "## 7. Turn-by-turn detail\n\n";
    o << "| # | Model | Complexity | Stop | Retry | Prompt | Completion | Cost | Chunks | Bytes | Duration |\n";
    o << "|---|---|---|---|---|---|---|---|---|---|---|\n";
    {
        vector<const Turn*> ordered;
        for (Turn& t : s.turn_list) ordered.push_back(&t);
        std::sort(ordered.begin(), ordered.end(),
                  [](const Turn* a, const Turn* b){ return a->wall_start_ms < b->wall_start_ms; });
        int i = 1;
        for (const Turn* t : ordered) {
            long long dur = (t->has_end && t->wall_end_ms >= t->wall_start_ms) ? (t->wall_end_ms - t->wall_start_ms) : 0;
            string turn_cost = "-";
            if (pricing_enabled && t->has_cost)
                turn_cost = usd_fmt(t->cost);
            else if (pricing_enabled && t->unpriced)
                turn_cost = "n/a";
            o << "| " << i++
              << " | " << (t->model.empty() ? "-" : t->model)
              << " | " << (t->complexity.empty() ? "-" : t->complexity)
              << " | " << (t->stop.empty() ? "-" : t->stop)
              << " | " << t->retry
              << " | " << human_tokens(t->prompt_tokens)
              << " | " << human_tokens(t->completion_tokens)
              << " | " << turn_cost
              << " | " << t->chunks
              << " | " << human_bytes(t->chunk_bytes)
              << " | " << human_ms(dur) << " |\n";
        }
    }
    o << "\n";

    // 8. Errors
    o << "## 8. Error-level events\n\n";
    if (s.err_events.empty()) {
        o << "No error-level events.\n\n";
    } else {
        o << "| Event | Count |\n|---|---|\n";
        for (auto& kv : sorted_pairs(s.err_events)) o << "| " << kv.first << " | " << kv.second << " |\n";
        o << "\n**Samples:**\n\n```\n";
        for (auto& str : s.err_samples) o << str << "\n";
        o << "```\n\n";
    }

    // 9. Persistence
    o << "## 9. Persistence\n\n";
    o << "- Thread saves: " << s.thread_saves << "\n";
    o << "- Total messages persisted: " << s.thread_messages << "\n";
    o << "- Avg messages per save: " << (s.thread_saves ? s.thread_messages / s.thread_saves : 0) << "\n\n";

    o << "---\n";
    o << "*Generated by agentty-stats.*\n";

    FILE* out = fopen(out_path, "wb");
    if (!out) { fprintf(stderr, "error: cannot write %s\n", out_path); return 1; }
    fwrite(o.str().data(), 1, o.str().size(), out);
    fclose(out);

    fprintf(stderr, "wrote %s (%zu bytes, %zu turns, %zu file%s)\n",
            out_path, o.str().size(), s.turn_list.size(), n_inputs, n_inputs == 1 ? "" : "s");
    return 0;
}
