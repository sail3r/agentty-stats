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
    string role;         // from route.turn
    string complexity;   // simple | complex
    string effort;
    string stop;         // tool_use | end_turn
    string route;
    string provider;
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
    int pend_orch = 0, pend_sub = 0, pend_comp = 0;

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
    }
    else if (ev == "dispatch.turn") {
        Turn t;
        t.id = id;
        t.has_dispatch = true;
        t.model = field(pl, "model");
        t.route = field(pl, "route");
        t.provider = field(pl, "provider");
        t.effort = field(pl, "effort");
        t.tools = field_num(pl, "tools");
        t.ctx_window = field_num(pl, "ctx_window");
        t.max_tokens = field_num(pl, "max_tokens");
        t.retry = field_num(pl, "retry");
        if (t.retry > 0) s.retried_turns_total++;
        t.start_ms = s.cur_rel;
        t.wall_start_ms = parse_ts_ms(s.cur_ts);
        // attach pending router decision
        t.role = s.pend_role;
        t.complexity = s.pend_complexity;
        t.orchestrate = s.pend_orch;
        t.subagents = s.pend_sub;
        t.compacting = s.pend_comp;
        if (t.model.empty()) t.model = s.pend_model;
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
            // usage tokens live in the raw JSON payload
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
        s.model_loaded_by_file[s.cur_file] = field_num(pl, "count");
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
        s.provider_count[field(pl, "provider")]++;
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

// Parse one log file into the shared Stats.
static bool process_file(Stats& s, const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) { fprintf(stderr, "error: cannot open %s\n", path); return false; }
    s.cur_file = path;

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
// Main
// ---------------------------------------------------------------------------

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: %s <log-file>... <output-file>\n", argv[0]);
        return 2;
    }
    const char* out_path = argv[argc - 1];
    int n_inputs = argc - 2;

    Stats s;
    vector<string> sources;
    for (int i = 1; i <= n_inputs; i++) {
        if (!process_file(s, argv[i])) return 1;
        sources.push_back(argv[i]);
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

    // ---- Build report ----
    std::ostringstream o;
    o << "# agentty — Session Statistics Report\n\n";
    o << "**Source";
    if (sources.size() > 1) o << "s";
    o << ":** ";
    for (size_t i = 0; i < sources.size(); i++) {
        if (i) o << ", ";
        o << "`" << sources[i] << "`";
    }
    o << "\n\n";
    o << "**Generated:** " << s.last_ts << "\n\n";
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
    o << "| Wire chunks | " << s.total_chunks << " (" << human_bytes(s.total_chunk_bytes) << ") |\n";
    o << "| Request bytes | " << human_bytes(s.total_request_bytes) << " |\n";
    o << "| Tool calls | " << ([] (const map<string,ToolStat>& t){ long long n=0; for(auto&kv:t)n+=kv.second.calls; return n; })(s.tools) << " |\n";
    o << "| Thread saves | " << s.thread_saves << " (" << s.thread_messages << " messages) |\n";
    o << "| Models loaded | ";
    if (s.model_loaded_by_file.empty()) o << "0";
    else {
        bool first = true;
        for (auto& kv : s.model_loaded_by_file) {
            if (!first) o << "; ";
            first = false;
            // basename for readability
            string base = kv.first;
            size_t slash = base.find_last_of('/');
            if (slash != string::npos) base = base.substr(slash + 1);
            o << base << "=" << kv.second;
        }
    }
    o << " |\n";
    o << "| Error-level events | " << s.level_count["E"] - s.auth_events << " (" << s.auth_events << " routine auth) |\n\n";

    // 2. Log volume by level / component / event
    o << "## 2. Log volume\n\n";
    o << "### By level\n\n| Level | Count |\n|---|---|\n";
    for (auto& kv : s.level_count) o << "| " << kv.first << " | " << kv.second << " |\n";
    o << "\n### By component\n\n| Component | Count |\n|---|---|\n";
    for (auto& kv : s.component_count) o << "| " << kv.first << " | " << kv.second << " |\n";
    o << "\n### By event\n\n| Event | Count |\n|---|---|\n";
    for (auto& kv : s.event_count) o << "| " << kv.first << " | " << kv.second << " |\n";
    o << "\n";

    // 3. Smart-mode routing
    o << "## 3. Smart-mode routing\n\n";
    o << "### Role\n\n| Role | Turns |\n|---|---|\n";
    for (auto& kv : s.role_count) o << "| " << kv.first << " | " << kv.second << " |\n";
    o << "\n### Complexity\n\n| Complexity | Turns |\n|---|---|\n";
    for (auto& kv : s.complexity_count) o << "| " << kv.first << " | " << kv.second << " |\n";
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
    for (auto& kv : s.models) {
        const ModelStat& ms = kv.second;
        o << "| " << kv.first << " | " << ms.turns
          << " | " << human_tokens(ms.prompt_tokens)
          << " | " << human_tokens(ms.completion_tokens)
          << " | " << human_tokens(ms.prompt_tokens + ms.completion_tokens)
          << " | " << human_bytes(ms.request_bytes)
          << " | " << human_bytes(ms.chunk_bytes)
          << " | " << ms.chunks
          << " | " << ms.retried_turns
          << " | " << ms.errors << " |\n";
    }
    o << "\n";

    // 5. Tool usage
    o << "## 5. Tool usage\n\n";
    o << "| Tool | Calls | Total | Avg | Max | ok | err |\n";
    o << "|---|---|---|---|---|---|---|\n";
    for (auto& kv : s.tools) {
        const ToolStat& ts = kv.second;
        o << "| " << kv.first << " | " << ts.calls
          << " | " << human_ms(ts.total_ms)
          << " | " << human_ms(ts.calls ? ts.total_ms / ts.calls : 0)
          << " | " << human_ms(ts.max_ms)
          << " | " << ts.ok << " | " << ts.err << " |\n";
    }
    o << "\n";

    // 6. Wire / streaming
    o << "## 6. Wire / streaming\n\n";
    o << "### Stop reasons\n\n| Stop | Count |\n|---|---|\n";
    for (auto& kv : s.stop_count) o << "| " << kv.first << " | " << kv.second << " |\n";
    o << "\n### HTTP status\n\n| Status | Count |\n|---|---|\n";
    for (auto& kv : s.status_count) o << "| " << kv.first << " | " << kv.second << " |\n";
    o << "\n### Hosts\n\n| Host | Count |\n|---|---|\n";
    for (auto& kv : s.host_count) o << "| " << kv.first << " | " << kv.second << " |\n";
    o << "\n### Providers\n\n| Provider | Count |\n|---|---|\n";
    for (auto& kv : s.provider_count) o << "| " << kv.first << " | " << kv.second << " |\n";
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
            for (auto& kv : s.http_error_status) o << "| " << kv.first << " | " << kv.second << " |\n";
            o << "\n";
        }
        if (!s.retry_attempts.empty()) {
            o << "### Retry attempts\n\n| Attempt | Count |\n|---|---|\n";
            for (auto& kv : s.retry_attempts) o << "| " << kv.first << " | " << kv.second << " |\n";
            o << "\n";
        }
        if (!s.stream_error_class.empty()) {
            o << "### stream.error classes\n\n| Class | Count |\n|---|---|\n";
            for (auto& kv : s.stream_error_class) o << "| " << kv.first << " | " << kv.second << " |\n";
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
    o << "| # | Model | Complexity | Stop | Retry | Prompt | Completion | Chunks | Bytes | Duration |\n";
    o << "|---|---|---|---|---|---|---|---|---|---|\n";
    {
        vector<const Turn*> ordered;
        for (Turn& t : s.turn_list) ordered.push_back(&t);
        std::sort(ordered.begin(), ordered.end(),
                  [](const Turn* a, const Turn* b){ return a->wall_start_ms < b->wall_start_ms; });
        int i = 1;
        for (const Turn* t : ordered) {
            long long dur = (t->has_end && t->wall_end_ms >= t->wall_start_ms) ? (t->wall_end_ms - t->wall_start_ms) : 0;
            o << "| " << i++
              << " | " << (t->model.empty() ? "-" : t->model)
              << " | " << (t->complexity.empty() ? "-" : t->complexity)
              << " | " << (t->stop.empty() ? "-" : t->stop)
              << " | " << t->retry
              << " | " << human_tokens(t->prompt_tokens)
              << " | " << human_tokens(t->completion_tokens)
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
        for (auto& kv : s.err_events) o << "| " << kv.first << " | " << kv.second << " |\n";
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

    fprintf(stderr, "wrote %s (%zu bytes, %zu turns, %d file%s)\n",
            out_path, o.str().size(), s.turn_list.size(), n_inputs, n_inputs == 1 ? "" : "s");
    return 0;
}
