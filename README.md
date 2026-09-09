# agentty-stats

A static C++ CLI tool that parses one or more [agentty](https://github.com/1ay1/agentty)
debug logs and emits a Markdown statistics report.

See `Example_Report.md` for a full sample of the generated output.

## Syntax

```sh
agentty-stats <log-files>... <output-file>

./agentty-stats a.log report.md
./agentty-stats a.log b.log combined-report.md
./agentty-stats ./* all_logs_report.md
```

The last argument is the output `.md` file; every preceding argument is an
input log file. All inputs are aggregated into a single report (turns are
ordered by wall-clock time across files).

## Setup

Log files need to be accurate, and env AGENTTY_LOG must to be set to 'trace'
or 'debug'.

Here's a simple shell script that creates a new log file in each new session
of Agentty, in its default logs directory:

```sh
#!/bin/sh
export AGENTTY_LOG=trace
export AGENTTY_LOG_FILE="$HOME/.agentty/logs/debug_$(date -u +%Y-%m-%d_%H:%M:%S%Z).log"
agentty
```

## Building

Build with `make` (needs a C++17 compiler). The binary is self-contained and
runs on any POSIX CLI.

Example:

```sh
make
```

## Log format

Each structured line has the shape:

```
<ISO-ts> +<rel-ms>ms <session-id> <LEVEL> <component> <event>: <key=value ...>
```

Lines that do not start with a timestamp are continuations of the previous
event's payload (e.g. multi-line `wire.chunk` raw JSON).

### Components and events

| Component | Events |
| --- | --- |
| `smart` | `route.turn` — router decision (role, complexity, orchestrate, subagents, compacting) |
| `model` | `dispatch.turn` — model dispatch (model, route, provider, tools, ctx_window, max_tokens, retry) |
| `wire` | `openai.request`, `openai.request.body`, `openai.auth`, `stream.response`, `stream.result`, `stream.end`, `stream.retry`, `stream.error`, `stream.error.body`, `stream.http_error`, `wire.chunk`, `provider.select`, `models.loaded` |
| `net` | `http.local_failed` — connection failures to the upstream |
| `tool` | `tool.exec` — tool name, ms, ok/err, args |
| `persist` | `thread.save` — result, id, messages |

### Turn correlation

A **turn** is opened by each `dispatch.turn` event. The immediately preceding
`route.turn` supplies the smart-mode routing metadata. All subsequent
`wire.*` / `stream.*` events attach to the current turn until the next
`dispatch.turn`. `tool.exec` uses independent session ids and is aggregated
globally.

Two caveats the tool accounts for:

- **Clock resets** — the relative `+<rel-ms>ms` field restarts per file, so
  cross-file ordering and spans always use the ISO timestamp (converted to
  epoch milliseconds), not the relative field.
- **Mid-stream starts** — logs may begin in the middle of a stream. Wire
  chunks that appear before the first `dispatch.turn` are counted in the
  global totals (bytes, chunks, level/event volume) but cannot be attributed
  to a turn. This is why per-turn token sums can be slightly smaller than the
  raw chunk total; the per-turn attribution is the correct one.

### Token usage

`wire.chunk` events carry the raw SSE payload. The final chunk of each stream
includes a `usage` object (`prompt_tokens`, `completion_tokens`), which the
tool extracts for per-turn and per-model token accounting.

## Report sections

1. **Overview** — turns, time span, models, total tokens, wire volume, tool calls, persistence, models loaded (per file), errors.
2. **Log volume** — counts by level, component, and event.
3. **Smart-mode routing** — role, complexity, orchestration flags.
4. **Per-model usage** — turns, prompt/completion tokens, request/chunk bytes, chunk counts, retried turns, errors.
5. **Tool usage** — calls, total/avg/max latency, ok/err.
6. **Wire / streaming** — stop reasons, HTTP status, hosts, providers.
6b. **Failures & retries** — retried turns, HTTP-error turns (by status), `stream.retry` attempts, `stream.error` classes, connection failures, samples.
7. **Turn-by-turn detail** — per-turn model, complexity, stop reason, retry count, tokens, chunks, bytes, duration.
8. **Error-level events** — counts and samples (routine `openai.auth` lines are excluded).
9. **Persistence** — thread saves and message counts.
