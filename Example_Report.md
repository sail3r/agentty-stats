# agentty — Session Statistics Report

## 1. Overview

| Metric | Value |
|---|---|
| Total turns (dispatches) | 532 |
| Time span | 2026-09-10T08:03:34.766 → 2026-09-10T17:20:11.029 (556m 36s) |
| Models used | glm-5.3, glm-5.3-flash, kimi-k3, minimax-m3 |
| Total prompt tokens | 30.59M (30586982) |
| Total completion tokens | 186.9k (186890) |
| Total tokens | 30.77M |
| Estimated cost | $0.0000 |
| Wire chunks | 29924 (11.06 MiB) |
| Request bytes | 112.47 MiB |
| Tool calls | 546 |
| Thread saves | 942 (162630 messages) |
| Models loaded | 2026-09-10__06:03:34UTC__debug.log=n/a; 2026-09-10__06:03:34UTC__debug.log.old=19; 2026-09-10__08:21:03UTC__debug.log=n/a; 2026-09-10__08:21:03UTC__debug.log.old=19; 2026-09-10__09:20:28UTC__debug.log=19; 2026-09-10__13:33:28UTC__debug.log=n/a; 2026-09-10__13:33:28UTC__debug.log.old=19 |
| Source files | 7 (127.29 MiB total)
<br>2026-09-10__06:03:34UTC__debug.log 21.84 MiB<br>2026-09-10__06:03:34UTC__debug.log.old 32.08 MiB<br>2026-09-10__08:21:03UTC__debug.log 3.17 MiB<br>2026-09-10__08:21:03UTC__debug.log.old 32.00 MiB<br>2026-09-10__09:20:28UTC__debug.log 2.37 MiB<br>2026-09-10__13:33:28UTC__debug.log 3.60 MiB<br>2026-09-10__13:33:28UTC__debug.log.old 32.22 MiB |
| Error-level events | 415 (564 routine auth) |

## 2. Log volume

### By level

| Level | Count |
|---|---|
| T | 30456 |
| D | 4198 |
| E | 979 |
| I | 78 |
| W | 66 |

### By component

| Component | Count |
|---|---|
| wire | 33176 |
| persist | 942 |
| tool | 546 |
| model | 532 |
| smart | 532 |
| net | 18 |
| ui | 18 |
| auth | 7 |
| general | 3 |
| rag | 3 |

### By event

| Event | Count |
|---|---|
| wire.chunk | 29924 |
| thread.save | 942 |
| openai.auth | 564 |
| tool.exec | 546 |
| stream.end | 533 |
| stream.response | 533 |
| stream.result | 533 |
| dispatch.turn | 532 |
| openai.request | 532 |
| openai.request.body | 532 |
| route.turn | 532 |
| http.local_failed | 14 |
| models.loaded | 11 |
| paste.recv | 9 |
| copilot.models.fallback | 7 |
| stream.error | 5 |
| stream.error.body | 5 |
| stream.http_error | 5 |
| provider.select | 4 |
| stream.retry | 4 |
| http.connect_failed | 3 |
| rag.embed | 3 |
| startup | 3 |
| http.stream_hangup | 1 |

## 3. Smart-mode routing

### Role

| Role | Turns | % of total |
|---|---|---|
| strategic | 331 | 62.2 |
| implementation | 127 | 23.9 |
| utility | 74 | 13.9 |

**Token share by tier:**

| Role | Prompt tok | Completion tok | Total tok | % of tokens |
|---|---|---|---|---|
| strategic | 19.23M | 96.3k | 19.33M | 62.8 |
| implementation | 6.15M | 48.2k | 6.20M | 20.2 |
| utility | 5.20M | 42.4k | 5.24M | 17.0 |

_283 turn(s) resolved via model→role map, 1 via previous role._

### Complexity

| Complexity | Turns | % of total |
|---|---|---|
| standard | 410 | 77.1 |
| trivial | 58 | 10.9 |
| complex | 50 | 9.4 |
| simple | 14 | 2.6 |

### Orchestration flags

- Orchestrate: 249 / 532 turns
- Subagents: 249 / 532 turns
- Compacting: 3 / 532 turns

## 4. Per-model usage

| Model | Turns | Prompt tok | Completion tok | Total tok | Req bytes | Chunk bytes | Chunks | Retried | Errors |
|---|---|---|---|---|---|---|---|---|---|
| kimi-k3 | 316 | 18.41M | 86.7k | 18.50M | 64.65 MiB | 3.97 MiB | 10865 | 11 | 10 |
| glm-5.3 | 141 | 6.87M | 55.1k | 6.93M | 26.72 MiB | 4.58 MiB | 8361 | 0 | 0 |
| glm-5.3-flash | 74 | 5.20M | 42.4k | 5.24M | 20.74 MiB | 2.35 MiB | 10235 | 0 | 0 |
| minimax-m3 | 1 | 102.6k | 2.7k | 105.4k | 371.8 KiB | 23.7 KiB | 66 | 0 | 0 |

## 4b. Cost (USD)

*Prices from [models.dev](https://models.dev), loaded from `~/.agentty/cache/modelsdev.json`; all amounts are United States Dollars (USD). Cost = prompt/1M × input-rate + completion/1M × output-rate.*

| Provider | Model | $/1M in | Input cost | $/1M out | Output cost | Turns | Total cost |
|---|---|---|---|---|---|---|---|
| ollama-cloud | glm-5.3 | $0.0000 | $0.0000 | $0.0000 | $0.0000 | 141 | $0.0000 |
| ollama-cloud | glm-5.3-flash | $0.0000 | $0.0000 | $0.0000 | $0.0000 | 74 | $0.0000 |
| ollama-cloud | kimi-k3 | $0.0000 | $0.0000 | $0.0000 | $0.0000 | 316 | $0.0000 |
| ollama-cloud | minimax-m3 | $0.0000 | $0.0000 | $0.0000 | $0.0000 | 1 | $0.0000 |
| **Total** | | | | | | | **$0.0000** |

*Note: estimates use input/output token counts from the logs; cache-read/cache-write tokens are not logged and are therefore not reflected in these figures.*

## 5. Tool usage

| Tool | Calls | Total | Avg | Max | ok | err |
|---|---|---|---|---|---|---|
| shell | 330 | 10m 11s | 1.9 s | 52.1 s | 329 | 1 |
| read | 76 | 37 ms | 0 ms | 37 ms | 76 | 0 |
| edit | 73 | 1.1 s | 14 ms | 37 ms | 66 | 7 |
| grep | 31 | 119 ms | 3 ms | 33 ms | 30 | 1 |
| write | 5 | 78 ms | 15 ms | 34 ms | 4 | 1 |
| git_status | 4 | 35 ms | 8 ms | 25 ms | 4 | 0 |
| list_dir | 4 | 0 ms | 0 ms | 0 ms | 4 | 0 |
| remember | 4 | 39 ms | 9 ms | 32 ms | 4 | 0 |
| remove | 4 | 0 ms | 0 ms | 0 ms | 2 | 2 |
| web_fetch | 4 | 3.0 s | 758 ms | 1.4 s | 3 | 1 |
| aggregate | 2 | 174 ms | 87 ms | 87 ms | 2 | 0 |
| git_commit | 2 | 194 ms | 97 ms | 111 ms | 2 | 0 |
| glob | 2 | 184 ms | 92 ms | 184 ms | 2 | 0 |
| outline | 2 | 82 ms | 41 ms | 41 ms | 2 | 0 |
| git_diff | 1 | 5 ms | 5 ms | 5 ms | 1 | 0 |
| repo_map | 1 | 8 ms | 8 ms | 8 ms | 1 | 0 |
| web_search | 1 | 1.4 s | 1.4 s | 1.4 s | 1 | 0 |

## 6. Wire / streaming

### Stop reasons

| Stop | Count |
|---|---|
| tool_use | 509 |
| end_turn | 18 |
| unspecified | 6 |

### HTTP status

| Status | Count |
|---|---|
| 200 | 1584 |
| 429 | 12 |
| 500 | 3 |

### Hosts

| Host | Count |
|---|---|
| ollama.com | 533 |

### Providers

| Provider | Count |
|---|---|
| https://ollama.com/v1#main | 2 |
| https://ollama.com/v1#seaventures | 2 |

## 6b. Failures & retries

| Signal | Count |
|---|---|
| Retried turns (dispatch retry>0) | 11 |
| HTTP error turns | 5 |
| stream.retry attempts | 4 |
| Connection failures (http.local_failed) | 14 |

### HTTP error status

| Status | Count |
|---|---|
| 429 | 4 |
| 500 | 1 |

### Retry attempts

| Attempt | Count |
|---|---|
| 1 | 1 |
| 2 | 1 |
| 3 | 1 |
| 4 | 1 |

### stream.error classes

| Class | Count |
|---|---|
| 1 | 4 |
| 4 | 1 |

**Samples:**

```
2026-09-10T08:03:37.929 conn_fail localhost:11434
2026-09-10T08:03:37.929 conn_fail localhost:9931
2026-09-10T08:09:45.591 conn_fail localhost:11434
2026-09-10T08:09:45.591 conn_fail localhost:9931
2026-09-10T15:12:03.508 kimi-k3 HTTP 429
2026-09-10T15:12:03.508 kimi-k3 HTTP
2026-09-10T15:12:07.022 kimi-k3 HTTP 429
2026-09-10T15:12:07.022 kimi-k3 HTTP
```

## 7. Turn-by-turn detail

| # | Model | Complexity | Stop | Retry | Prompt | Completion | Cost | Chunks | Bytes | Duration |
|---|---|---|---|---|---|---|---|---|---|---|
| 1 | kimi-k3 | complex | tool_use | 0 | 13.8k | 154 | $0.0000 | 16 | 6.5 KiB | 3.9 s |
| 2 | kimi-k3 | complex | tool_use | 0 | 22.1k | 173 | $0.0000 | 21 | 7.4 KiB | 4.3 s |
| 3 | kimi-k3 | complex | tool_use | 0 | 25.5k | 108 | $0.0000 | 15 | 6.8 KiB | 2.5 s |
| 4 | kimi-k3 | complex | end_turn | 0 | 26.7k | 1.0k | $0.0000 | 573 | 208.6 KiB | 14.6 s |
| 5 | kimi-k3 | complex | tool_use | 0 | 27.8k | 186 | $0.0000 | 55 | 19.6 KiB | 3.8 s |
| 6 | kimi-k3 | complex | tool_use | 0 | 28.4k | 376 | $0.0000 | 4 | 2.1 KiB | 5.6 s |
| 7 | kimi-k3 | complex | tool_use | 0 | 29.3k | 459 | $0.0000 | 19 | 8.5 KiB | 6.6 s |
| 8 | kimi-k3 | complex | tool_use | 0 | 30.2k | 501 | $0.0000 | 4 | 2.5 KiB | 6.8 s |
| 9 | kimi-k3 | complex | tool_use | 0 | 39.7k | 117 | $0.0000 | 3 | 1.3 KiB | 2.5 s |
| 10 | kimi-k3 | complex | - | 0 | 32.7k | 834 | $0.0000 | 5 | 3.4 KiB | 0 ms |
| 11 | kimi-k3 | complex | tool_use | 0 | 30.9k | 817 | $0.0000 | 5 | 3.4 KiB | 9.9 s |
| 12 | kimi-k3 | complex | tool_use | 0 | 31.7k | 72 | $0.0000 | 3 | 1.1 KiB | 2.3 s |
| 13 | kimi-k3 | complex | tool_use | 0 | 31.4k | 93 | $0.0000 | 3 | 1.2 KiB | 3.1 s |
| 14 | kimi-k3 | complex | end_turn | 0 | 32.4k | 921 | $0.0000 | 520 | 183.4 KiB | 13.8 s |
| 15 | glm-5.3 | standard | tool_use | 0 | 33.8k | 657 | $0.0000 | 51 | 46.3 KiB | 9.2 s |
| 16 | glm-5.3 | standard | tool_use | 0 | 33.9k | 84 | $0.0000 | 3 | 1.6 KiB | 2.4 s |
| 17 | glm-5.3 | standard | - | 0 | 25.6k | 28 | $0.0000 | 2 | 1.1 KiB | 0 ms |
| 18 | glm-5.3 | standard | tool_use | 0 | 25.7k | 58 | $0.0000 | 2 | 1.2 KiB | 2.1 s |
| 19 | glm-5.3 | standard | tool_use | 0 | 26.3k | 64 | $0.0000 | 2 | 1.2 KiB | 1.8 s |
| 20 | glm-5.3 | standard | tool_use | 0 | 27.1k | 77 | $0.0000 | 2 | 1.3 KiB | 2.2 s |
| 21 | glm-5.3 | standard | tool_use | 0 | 27.5k | 83 | $0.0000 | 2 | 1.3 KiB | 2.1 s |
| 22 | glm-5.3 | standard | tool_use | 0 | 27.7k | 40 | $0.0000 | 2 | 1.2 KiB | 1.8 s |
| 23 | glm-5.3 | standard | tool_use | 0 | 30.7k | 924 | $0.0000 | 89 | 69.9 KiB | 9.6 s |
| 24 | glm-5.3 | standard | - | 0 | 31.0k | 52 | $0.0000 | 2 | 1.1 KiB | 0 ms |
| 25 | glm-5.3 | standard | tool_use | 0 | 31.5k | 439 | $0.0000 | 55 | 34.9 KiB | 5.8 s |
| 26 | glm-5.3 | standard | - | 0 | 31.7k | 45 | $0.0000 | 3 | 1.1 KiB | 0 ms |
| 27 | glm-5.3 | standard | tool_use | 0 | 31.8k | 69 | $0.0000 | 2 | 1.3 KiB | 2.3 s |
| 28 | glm-5.3 | standard | tool_use | 0 | 32.3k | 1.6k | $0.0000 | 177 | 124.8 KiB | 16.9 s |
| 29 | glm-5.3 | standard | tool_use | 0 | 32.8k | 60 | $0.0000 | 2 | 1.2 KiB | 2.0 s |
| 30 | glm-5.3 | standard | tool_use | 0 | 31.1k | 86 | $0.0000 | 2 | 1.3 KiB | 2.3 s |
| 31 | glm-5.3 | standard | tool_use | 0 | 31.6k | 67 | $0.0000 | 2 | 1.2 KiB | 2.4 s |
| 32 | glm-5.3 | standard | tool_use | 0 | 31.8k | 41 | $0.0000 | 3 | 1.1 KiB | 2.0 s |
| 33 | glm-5.3 | standard | tool_use | 0 | 32.8k | 44 | $0.0000 | 2 | 1.2 KiB | 2.2 s |
| 34 | glm-5.3 | standard | tool_use | 0 | 33.0k | 47 | $0.0000 | 2 | 1.2 KiB | 2.4 s |
| 35 | glm-5.3 | standard | tool_use | 0 | 33.2k | 45 | $0.0000 | 2 | 1.2 KiB | 2.3 s |
| 36 | glm-5.3 | standard | tool_use | 0 | 33.4k | 72 | $0.0000 | 2 | 1.3 KiB | 2.2 s |
| 37 | glm-5.3 | standard | tool_use | 0 | 33.5k | 68 | $0.0000 | 2 | 1.3 KiB | 2.1 s |
| 38 | glm-5.3 | standard | tool_use | 0 | 33.5k | 83 | $0.0000 | 2 | 1.3 KiB | 3.3 s |
| 39 | glm-5.3 | standard | tool_use | 0 | 33.8k | 61 | $0.0000 | 2 | 1.2 KiB | 2.0 s |
| 40 | glm-5.3 | standard | tool_use | 0 | 34.4k | 76 | $0.0000 | 2 | 1.3 KiB | 2.0 s |
| 41 | glm-5.3 | standard | tool_use | 0 | 34.4k | 44 | $0.0000 | 2 | 1.1 KiB | 1.9 s |
| 42 | glm-5.3 | standard | tool_use | 0 | 34.7k | 1.0k | $0.0000 | 94 | 76.0 KiB | 10.2 s |
| 43 | glm-5.3 | standard | tool_use | 0 | 35.1k | 2.1k | $0.0000 | 220 | 176.8 KiB | 21.9 s |
| 44 | glm-5.3 | standard | tool_use | 0 | 35.9k | 72 | $0.0000 | 2 | 1.3 KiB | 3.2 s |
| 45 | glm-5.3 | standard | tool_use | 0 | 36.1k | 43 | $0.0000 | 2 | 1.1 KiB | 2.3 s |
| 46 | glm-5.3 | standard | tool_use | 0 | 36.3k | 465 | $0.0000 | 46 | 35.6 KiB | 6.1 s |
| 47 | glm-5.3 | standard | tool_use | 0 | 37.1k | 3.0k | $0.0000 | 439 | 256.6 KiB | 33.4 s |
| 48 | glm-5.3 | standard | tool_use | 0 | 37.8k | 90 | $0.0000 | 2 | 1.3 KiB | 2.6 s |
| 49 | glm-5.3 | standard | tool_use | 0 | 38.2k | 72 | $0.0000 | 2 | 1.2 KiB | 2.0 s |
| 50 | glm-5.3 | standard | - | 0 | 38.5k | 1.2k | $0.0000 | 153 | 98.4 KiB | 0 ms |
| 51 | glm-5.3 | standard | tool_use | 0 | 39.8k | 52 | $0.0000 | 3 | 1.2 KiB | 2.4 s |
| 52 | glm-5.3 | standard | tool_use | 0 | 40.1k | 42 | $0.0000 | 2 | 1.2 KiB | 1.7 s |
| 53 | glm-5.3 | standard | tool_use | 0 | 40.4k | 3.9k | $0.0000 | 425 | 319.8 KiB | 41.0 s |
| 54 | glm-5.3 | standard | tool_use | 0 | 41.6k | 1.2k | $0.0000 | 149 | 87.5 KiB | 12.2 s |
| 55 | glm-5.3 | standard | tool_use | 0 | 42.0k | 1.7k | $0.0000 | 147 | 130.8 KiB | 17.3 s |
| 56 | glm-5.3 | standard | tool_use | 0 | 42.9k | 2.1k | $0.0000 | 208 | 161.4 KiB | 21.3 s |
| 57 | glm-5.3 | standard | tool_use | 0 | 43.3k | 2.0k | $0.0000 | 197 | 150.3 KiB | 19.8 s |
| 58 | glm-5.3 | standard | tool_use | 0 | 44.0k | 39 | $0.0000 | 2 | 1.1 KiB | 2.0 s |
| 59 | glm-5.3 | standard | tool_use | 0 | 44.0k | 4.6k | $0.0000 | 436 | 358.7 KiB | 48.8 s |
| 60 | glm-5.3 | standard | tool_use | 0 | 44.7k | 66 | $0.0000 | 2 | 1.3 KiB | 18.5 s |
| 61 | glm-5.3 | standard | tool_use | 0 | 44.8k | 63 | $0.0000 | 3 | 1.3 KiB | 2.3 s |
| 62 | glm-5.3 | standard | tool_use | 0 | 44.4k | 54 | $0.0000 | 2 | 1.2 KiB | 2.2 s |
| 63 | glm-5.3 | standard | - | 0 | 44.7k | 62 | $0.0000 | 2 | 1.2 KiB | 0 ms |
| 64 | glm-5.3 | standard | tool_use | 0 | 44.5k | 70 | $0.0000 | 2 | 1.3 KiB | 2.5 s |
| 65 | glm-5.3 | standard | tool_use | 0 | 44.9k | 1.4k | $0.0000 | 162 | 113.8 KiB | 17.4 s |
| 66 | glm-5.3 | standard | tool_use | 0 | 45.0k | 87 | $0.0000 | 2 | 1.3 KiB | 2.5 s |
| 67 | glm-5.3 | standard | tool_use | 0 | 45.2k | 84 | $0.0000 | 2 | 1.3 KiB | 2.4 s |
| 68 | glm-5.3 | standard | tool_use | 0 | 45.3k | 49 | $0.0000 | 2 | 1.2 KiB | 2.9 s |
| 69 | glm-5.3 | standard | tool_use | 0 | 45.5k | 305 | $0.0000 | 24 | 19.2 KiB | 4.0 s |
| 70 | glm-5.3 | standard | tool_use | 0 | 45.9k | 250 | $0.0000 | 19 | 15.0 KiB | 5.7 s |
| 71 | glm-5.3 | standard | tool_use | 0 | 46.0k | 67 | $0.0000 | 2 | 1.3 KiB | 2.6 s |
| 72 | glm-5.3 | standard | tool_use | 0 | 46.1k | 65 | $0.0000 | 2 | 1.2 KiB | 2.9 s |
| 73 | glm-5.3 | standard | tool_use | 0 | 46.2k | 70 | $0.0000 | 2 | 1.3 KiB | 2.5 s |
| 74 | glm-5.3 | standard | tool_use | 0 | 46.4k | 221 | $0.0000 | 26 | 15.7 KiB | 3.8 s |
| 75 | glm-5.3 | standard | tool_use | 0 | 46.9k | 4.4k | $0.0000 | 410 | 356.0 KiB | 46.4 s |
| 76 | glm-5.3 | standard | tool_use | 0 | 47.0k | 64 | $0.0000 | 2 | 1.2 KiB | 2.3 s |
| 77 | glm-5.3 | standard | tool_use | 0 | 47.1k | 43 | $0.0000 | 2 | 1.1 KiB | 2.3 s |
| 78 | glm-5.3 | standard | tool_use | 0 | 47.6k | 408 | $0.0000 | 7 | 4.7 KiB | 4.2 s |
| 79 | glm-5.3 | standard | tool_use | 0 | 48.4k | 360 | $0.0000 | 3 | 2.4 KiB | 3.9 s |
| 80 | glm-5.3 | standard | tool_use | 0 | 49.0k | 572 | $0.0000 | 7 | 5.0 KiB | 5.2 s |
| 81 | glm-5.3 | standard | tool_use | 0 | 50.1k | 428 | $0.0000 | 5 | 3.3 KiB | 5.9 s |
| 82 | glm-5.3 | standard | tool_use | 0 | 51.0k | 215 | $0.0000 | 8 | 4.4 KiB | 3.2 s |
| 83 | glm-5.3 | standard | tool_use | 0 | 51.4k | 173 | $0.0000 | 2 | 1.5 KiB | 3.3 s |
| 84 | glm-5.3 | standard | tool_use | 0 | 51.8k | 176 | $0.0000 | 2 | 1.5 KiB | 3.0 s |
| 85 | glm-5.3 | standard | tool_use | 0 | 52.2k | 134 | $0.0000 | 7 | 3.6 KiB | 3.3 s |
| 86 | glm-5.3 | standard | tool_use | 0 | 52.5k | 85 | $0.0000 | 8 | 4.3 KiB | 2.8 s |
| 87 | glm-5.3 | standard | tool_use | 0 | 52.8k | 166 | $0.0000 | 2 | 1.5 KiB | 3.2 s |
| 88 | glm-5.3 | standard | - | 0 | 53.2k | 431 | $0.0000 | 8 | 5.1 KiB | 0 ms |
| 89 | glm-5.3 | standard | tool_use | 0 | 53.8k | 71 | $0.0000 | 2 | 1.3 KiB | 2.6 s |
| 90 | glm-5.3 | standard | tool_use | 0 | 54.1k | 441 | $0.0000 | 3 | 2.4 KiB | 3.7 s |
| 91 | glm-5.3 | standard | tool_use | 0 | 54.8k | 73 | $0.0000 | 6 | 3.9 KiB | 2.4 s |
| 92 | glm-5.3 | standard | tool_use | 0 | 55.3k | 970 | $0.0000 | 5 | 4.6 KiB | 7.7 s |
| 93 | glm-5.3 | standard | tool_use | 0 | 57.1k | 44 | $0.0000 | 2 | 1.2 KiB | 2.0 s |
| 94 | glm-5.3 | standard | tool_use | 0 | 57.1k | 31 | $0.0000 | 2 | 1.1 KiB | 2.1 s |
| 95 | glm-5.3 | standard | tool_use | 0 | 57.2k | 264 | $0.0000 | 6 | 4.0 KiB | 3.2 s |
| 96 | glm-5.3 | standard | tool_use | 0 | 57.7k | 39 | $0.0000 | 2 | 1.2 KiB | 2.1 s |
| 97 | glm-5.3 | standard | - | 0 | 57.9k | 69 | $0.0000 | 2 | 1.2 KiB | 0 ms |
| 98 | glm-5.3 | standard | tool_use | 0 | 58.0k | 92 | $0.0000 | 2 | 1.3 KiB | 2.4 s |
| 99 | glm-5.3 | standard | tool_use | 0 | 58.1k | 52 | $0.0000 | 2 | 1.2 KiB | 2.3 s |
| 100 | glm-5.3 | standard | tool_use | 0 | 58.4k | 61 | $0.0000 | 2 | 1.2 KiB | 2.2 s |
| 101 | glm-5.3 | standard | tool_use | 0 | 58.3k | 99 | $0.0000 | 2 | 1.4 KiB | 2.5 s |
| 102 | glm-5.3 | standard | tool_use | 0 | 58.5k | 54 | $0.0000 | 2 | 1.2 KiB | 2.4 s |
| 103 | glm-5.3 | standard | tool_use | 0 | 58.6k | 76 | $0.0000 | 2 | 1.2 KiB | 2.4 s |
| 104 | glm-5.3 | standard | tool_use | 0 | 58.7k | 72 | $0.0000 | 3 | 1.2 KiB | 2.4 s |
| 105 | glm-5.3 | standard | tool_use | 0 | 58.8k | 571 | $0.0000 | 50 | 46.2 KiB | 8.0 s |
| 106 | glm-5.3 | standard | tool_use | 0 | 59.0k | 57 | $0.0000 | 2 | 1.2 KiB | 2.4 s |
| 107 | glm-5.3 | standard | tool_use | 0 | 59.1k | 70 | $0.0000 | 2 | 1.3 KiB | 2.8 s |
| 108 | glm-5.3 | standard | tool_use | 0 | 59.4k | 76 | $0.0000 | 2 | 1.3 KiB | 2.9 s |
| 109 | glm-5.3 | standard | tool_use | 0 | 59.6k | 61 | $0.0000 | 2 | 1.2 KiB | 3.2 s |
| 110 | glm-5.3 | standard | tool_use | 0 | 60.4k | 317 | $0.0000 | 24 | 18.9 KiB | 4.4 s |
| 111 | glm-5.3 | standard | tool_use | 0 | 60.6k | 40 | $0.0000 | 2 | 1.2 KiB | 2.0 s |
| 112 | glm-5.3 | standard | tool_use | 0 | 60.7k | 612 | $0.0000 | 59 | 37.9 KiB | 7.9 s |
| 113 | glm-5.3 | standard | tool_use | 0 | 61.5k | 89 | $0.0000 | 2 | 1.3 KiB | 2.4 s |
| 114 | glm-5.3 | standard | tool_use | 0 | 61.7k | 174 | $0.0000 | 3 | 1.6 KiB | 3.6 s |
| 115 | glm-5.3 | standard | tool_use | 0 | 62.1k | 71 | $0.0000 | 2 | 1.3 KiB | 2.3 s |
| 116 | glm-5.3 | standard | tool_use | 0 | 62.2k | 174 | $0.0000 | 3 | 1.7 KiB | 3.0 s |
| 117 | glm-5.3 | standard | tool_use | 0 | 62.7k | 100 | $0.0000 | 6 | 4.9 KiB | 2.4 s |
| 118 | glm-5.3 | standard | tool_use | 0 | 62.6k | 91 | $0.0000 | 2 | 1.4 KiB | 2.6 s |
| 119 | glm-5.3 | standard | tool_use | 0 | 62.8k | 363 | $0.0000 | 29 | 21.3 KiB | 5.4 s |
| 120 | glm-5.3 | standard | tool_use | 0 | 63.0k | 63 | $0.0000 | 2 | 1.3 KiB | 2.4 s |
| 121 | glm-5.3 | standard | tool_use | 0 | 63.3k | 51 | $0.0000 | 2 | 1.2 KiB | 2.8 s |
| 122 | glm-5.3 | standard | tool_use | 0 | 63.4k | 72 | $0.0000 | 2 | 1.3 KiB | 2.6 s |
| 123 | glm-5.3 | standard | tool_use | 0 | 63.5k | 65 | $0.0000 | 2 | 1.3 KiB | 2.2 s |
| 124 | glm-5.3 | standard | tool_use | 0 | 64.1k | 108 | $0.0000 | 2 | 1.4 KiB | 2.6 s |
| 125 | glm-5.3 | standard | tool_use | 0 | 64.2k | 95 | $0.0000 | 2 | 1.4 KiB | 2.6 s |
| 126 | glm-5.3 | standard | tool_use | 0 | 64.4k | 95 | $0.0000 | 2 | 1.4 KiB | 2.5 s |
| 127 | glm-5.3 | standard | tool_use | 0 | 64.6k | 102 | $0.0000 | 7 | 3.2 KiB | 2.6 s |
| 128 | glm-5.3 | standard | tool_use | 0 | 64.8k | 75 | $0.0000 | 2 | 1.3 KiB | 2.6 s |
| 129 | glm-5.3 | standard | tool_use | 0 | 65.0k | 59 | $0.0000 | 2 | 1.2 KiB | 2.2 s |
| 130 | glm-5.3 | standard | tool_use | 0 | 65.2k | 852 | $0.0000 | 79 | 63.8 KiB | 10.0 s |
| 131 | glm-5.3 | standard | tool_use | 0 | 65.4k | 59 | $0.0000 | 2 | 1.2 KiB | 2.6 s |
| 132 | glm-5.3 | standard | tool_use | 0 | 65.6k | 297 | $0.0000 | 27 | 19.0 KiB | 4.6 s |
| 133 | glm-5.3 | standard | tool_use | 0 | 65.7k | 70 | $0.0000 | 2 | 1.3 KiB | 2.2 s |
| 134 | glm-5.3 | standard | tool_use | 0 | 65.8k | 78 | $0.0000 | 2 | 1.3 KiB | 2.4 s |
| 135 | glm-5.3 | standard | tool_use | 0 | 65.9k | 55 | $0.0000 | 2 | 1.2 KiB | 2.6 s |
| 136 | glm-5.3 | standard | tool_use | 0 | 66.1k | 56 | $0.0000 | 2 | 1.2 KiB | 2.0 s |
| 137 | glm-5.3 | standard | tool_use | 0 | 67.1k | 146 | $0.0000 | 17 | 8.5 KiB | 3.5 s |
| 138 | glm-5.3 | standard | tool_use | 0 | 67.4k | 217 | $0.0000 | 3 | 1.9 KiB | 3.6 s |
| 139 | glm-5.3 | standard | tool_use | 0 | 67.7k | 94 | $0.0000 | 2 | 1.4 KiB | 2.9 s |
| 140 | glm-5.3 | standard | end_turn | 0 | 68.0k | 522 | $0.0000 | 70 | 35.7 KiB | 8.5 s |
| 141 | glm-5.3-flash | simple | tool_use | 0 | 68.5k | 3.4k | $0.0000 | 1391 | 320.5 KiB | 58.4 s |
| 142 | glm-5.3-flash | trivial | tool_use | 0 | 68.8k | 1.2k | $0.0000 | 455 | 104.8 KiB | 30.5 s |
| 143 | glm-5.3-flash | trivial | tool_use | 0 | 69.1k | 1.8k | $0.0000 | 8 | 8.6 KiB | 19.5 s |
| 144 | glm-5.3-flash | trivial | tool_use | 0 | 70.9k | 60 | $0.0000 | 2 | 1.2 KiB | 2.5 s |
| 145 | glm-5.3-flash | trivial | tool_use | 0 | 71.0k | 63 | $0.0000 | 2 | 1.3 KiB | 1.9 s |
| 146 | glm-5.3-flash | trivial | tool_use | 0 | 70.7k | 89 | $0.0000 | 2 | 1.3 KiB | 3.0 s |
| 147 | glm-5.3-flash | trivial | - | 0 | 0 | 0 | $0.0000 | 0 | 0 B | 0 ms |
| 148 | glm-5.3-flash | trivial | tool_use | 0 | 71.0k | 115 | $0.0000 | 2 | 1.5 KiB | 2.4 s |
| 149 | glm-5.3-flash | trivial | tool_use | 0 | 71.4k | 286 | $0.0000 | 37 | 9.6 KiB | 4.4 s |
| 150 | glm-5.3-flash | trivial | tool_use | 0 | 71.8k | 65 | $0.0000 | 2 | 1.2 KiB | 2.4 s |
| 151 | glm-5.3-flash | trivial | tool_use | 0 | 71.9k | 55 | $0.0000 | 2 | 1.2 KiB | 2.1 s |
| 152 | glm-5.3-flash | trivial | tool_use | 0 | 72.0k | 97 | $0.0000 | 2 | 1.4 KiB | 1.9 s |
| 153 | glm-5.3-flash | trivial | tool_use | 0 | 72.1k | 149 | $0.0000 | 2 | 1.6 KiB | 2.6 s |
| 154 | glm-5.3-flash | trivial | tool_use | 0 | 72.7k | 422 | $0.0000 | 122 | 28.9 KiB | 6.5 s |
| 155 | glm-5.3-flash | trivial | tool_use | 0 | 73.0k | 65 | $0.0000 | 3 | 1.2 KiB | 2.9 s |
| 156 | glm-5.3-flash | trivial | tool_use | 0 | 73.2k | 2.4k | $0.0000 | 613 | 142.5 KiB | 31.2 s |
| 157 | glm-5.3-flash | trivial | tool_use | 0 | 74.9k | 51 | $0.0000 | 2 | 1.2 KiB | 2.2 s |
| 158 | glm-5.3-flash | trivial | tool_use | 0 | 75.2k | 708 | $0.0000 | 255 | 59.2 KiB | 16.3 s |
| 159 | glm-5.3-flash | trivial | tool_use | 0 | 75.4k | 180 | $0.0000 | 3 | 1.7 KiB | 3.2 s |
| 160 | glm-5.3-flash | trivial | tool_use | 0 | 75.6k | 307 | $0.0000 | 4 | 2.2 KiB | 3.8 s |
| 161 | glm-5.3-flash | trivial | tool_use | 0 | 78.0k | 487 | $0.0000 | 95 | 22.9 KiB | 7.5 s |
| 162 | glm-5.3-flash | trivial | tool_use | 0 | 78.7k | 52 | $0.0000 | 2 | 1.2 KiB | 6.5 s |
| 163 | glm-5.3-flash | trivial | tool_use | 0 | 78.8k | 55 | $0.0000 | 3 | 1.2 KiB | 2.3 s |
| 164 | glm-5.3-flash | trivial | tool_use | 0 | 79.0k | 485 | $0.0000 | 127 | 29.9 KiB | 9.0 s |
| 165 | glm-5.3-flash | trivial | tool_use | 0 | 79.2k | 242 | $0.0000 | 4 | 1.7 KiB | 4.4 s |
| 166 | glm-5.3-flash | trivial | tool_use | 0 | 79.7k | 126 | $0.0000 | 2 | 1.4 KiB | 3.3 s |
| 167 | glm-5.3-flash | trivial | tool_use | 0 | 79.9k | 1.6k | $0.0000 | 228 | 55.7 KiB | 18.0 s |
| 168 | glm-5.3-flash | trivial | tool_use | 0 | 81.8k | 66 | $0.0000 | 2 | 1.3 KiB | 2.1 s |
| 169 | glm-5.3-flash | trivial | tool_use | 0 | 80.6k | 133 | $0.0000 | 3 | 1.5 KiB | 3.3 s |
| 170 | glm-5.3-flash | trivial | tool_use | 0 | 81.1k | 133 | $0.0000 | 15 | 4.4 KiB | 2.9 s |
| 171 | glm-5.3-flash | trivial | tool_use | 0 | 81.3k | 286 | $0.0000 | 3 | 2.1 KiB | 4.8 s |
| 172 | glm-5.3-flash | trivial | tool_use | 0 | 81.6k | 156 | $0.0000 | 3 | 1.7 KiB | 6.1 s |
| 173 | glm-5.3-flash | trivial | tool_use | 0 | 81.8k | 350 | $0.0000 | 46 | 11.8 KiB | 7.1 s |
| 174 | glm-5.3-flash | trivial | tool_use | 0 | 82.2k | 115 | $0.0000 | 2 | 1.5 KiB | 2.5 s |
| 175 | glm-5.3-flash | trivial | tool_use | 0 | 82.4k | 146 | $0.0000 | 3 | 1.5 KiB | 3.3 s |
| 176 | glm-5.3-flash | trivial | end_turn | 0 | 82.4k | 611 | $0.0000 | 212 | 45.8 KiB | 11.4 s |
| 177 | glm-5.3-flash | trivial | tool_use | 0 | 83.0k | 8.6k | $0.0000 | 2586 | 596.0 KiB | 1m 50s |
| 178 | glm-5.3-flash | trivial | tool_use | 0 | 86.5k | 105 | $0.0000 | 2 | 1.4 KiB | 2.8 s |
| 179 | glm-5.3-flash | trivial | tool_use | 0 | 86.7k | 295 | $0.0000 | 4 | 2.0 KiB | 4.1 s |
| 180 | glm-5.3-flash | trivial | tool_use | 0 | 87.7k | 891 | $0.0000 | 373 | 85.3 KiB | 15.3 s |
| 181 | glm-5.3-flash | trivial | tool_use | 0 | 88.1k | 311 | $0.0000 | 3 | 1.9 KiB | 3.8 s |
| 182 | glm-5.3-flash | trivial | tool_use | 0 | 88.8k | 100 | $0.0000 | 2 | 1.4 KiB | 2.6 s |
| 183 | glm-5.3-flash | trivial | tool_use | 0 | 89.1k | 105 | $0.0000 | 2 | 1.4 KiB | 2.4 s |
| 184 | glm-5.3-flash | trivial | tool_use | 0 | 89.3k | 221 | $0.0000 | 3 | 1.8 KiB | 2.9 s |
| 185 | glm-5.3-flash | trivial | tool_use | 0 | 90.2k | 476 | $0.0000 | 90 | 22.0 KiB | 6.0 s |
| 186 | glm-5.3-flash | trivial | - | 0 | 90.0k | 1.1k | $0.0000 | 152 | 36.9 KiB | 0 ms |
| 187 | glm-5.3-flash | trivial | tool_use | 0 | 90.9k | 426 | $0.0000 | 3 | 2.3 KiB | 2 ms |
| 188 | glm-5.3-flash | trivial | tool_use | 0 | 91.5k | 47 | $0.0000 | 2 | 1.2 KiB | 2 ms |
| 189 | glm-5.3-flash | trivial | tool_use | 0 | 91.7k | 529 | $0.0000 | 4 | 2.7 KiB | 4.9 s |
| 190 | glm-5.3-flash | trivial | tool_use | 0 | 92.6k | 131 | $0.0000 | 2 | 1.5 KiB | 2.5 s |
| 191 | glm-5.3-flash | trivial | tool_use | 0 | 92.8k | 79 | $0.0000 | 2 | 1.3 KiB | 2.4 s |
| 192 | glm-5.3-flash | trivial | tool_use | 0 | 92.9k | 40 | $0.0000 | 2 | 1.1 KiB | 2.1 s |
| 193 | glm-5.3-flash | trivial | tool_use | 0 | 93.3k | 61 | $0.0000 | 2 | 1.2 KiB | 2.1 s |
| 194 | glm-5.3-flash | trivial | tool_use | 0 | 93.5k | 417 | $0.0000 | 3 | 2.4 KiB | 4.7 s |
| 195 | glm-5.3-flash | trivial | tool_use | 0 | 95.1k | 525 | $0.0000 | 191 | 44.3 KiB | 9.3 s |
| 196 | glm-5.3-flash | trivial | tool_use | 0 | 95.5k | 99 | $0.0000 | 2 | 1.4 KiB | 2.8 s |
| 197 | glm-5.3-flash | trivial | tool_use | 0 | 95.6k | 256 | $0.0000 | 3 | 2.1 KiB | 4.8 s |
| 198 | glm-5.3-flash | trivial | - | 0 | 96.0k | 161 | $0.0000 | 3 | 1.6 KiB | 0 ms |
| 199 | glm-5.3-flash | trivial | end_turn | 0 | 96.2k | 587 | $0.0000 | 179 | 39.9 KiB | 10.8 s |
| 200 | kimi-k3 | complex | tool_use | 0 | 109.2k | 207 | $0.0000 | 3 | 1.6 KiB | 10.3 s |
| 201 | kimi-k3 | complex | tool_use | 0 | 109.7k | 140 | $0.0000 | 3 | 1.3 KiB | 4.0 s |
| 202 | kimi-k3 | complex | tool_use | 0 | 110.0k | 198 | $0.0000 | 3 | 1.5 KiB | 4.5 s |
| 203 | kimi-k3 | complex | tool_use | 0 | 110.4k | 1.2k | $0.0000 | 6 | 5.9 KiB | 19.0 s |
| 204 | kimi-k3 | complex | tool_use | 0 | 111.0k | 107 | $0.0000 | 3 | 1.2 KiB | 3.6 s |
| 205 | kimi-k3 | complex | - | 0 | 111.2k | 366 | $0.0000 | 211 | 71.8 KiB | 0 ms |
| 206 | glm-5.3-flash | complex | end_turn | 0 | 87.5k | 2.3k | $0.0000 | 685 | 152.0 KiB | 28.0 s |
| 207 | kimi-k3 | complex | tool_use | 0 | 13.8k | 123 | $0.0000 | 7 | 2.3 KiB | 5.4 s |
| 208 | kimi-k3 | complex | tool_use | 0 | 14.5k | 582 | $0.0000 | 251 | 97.4 KiB | 8.9 s |
| 209 | kimi-k3 | complex | tool_use | 0 | 14.9k | 124 | $0.0000 | 8 | 3.0 KiB | 2.7 s |
| 210 | kimi-k3 | complex | tool_use | 0 | 15.2k | 137 | $0.0000 | 3 | 1.3 KiB | 3.3 s |
| 211 | kimi-k3 | complex | tool_use | 0 | 15.4k | 191 | $0.0000 | 21 | 8.8 KiB | 3.3 s |
| 212 | kimi-k3 | complex | - | 0 | 16.2k | 167 | $0.0000 | 30 | 13.0 KiB | 0 ms |
| 213 | kimi-k3 | complex | tool_use | 0 | 16.4k | 82 | $0.0000 | 3 | 1.1 KiB | 1.8 s |
| 214 | kimi-k3 | complex | tool_use | 0 | 16.5k | 159 | $0.0000 | 12 | 5.4 KiB | 3.3 s |
| 215 | kimi-k3 | complex | tool_use | 0 | 17.5k | 136 | $0.0000 | 3 | 1.3 KiB | 2.3 s |
| 216 | kimi-k3 | complex | tool_use | 0 | 17.7k | 208 | $0.0000 | 21 | 8.9 KiB | 3.4 s |
| 217 | kimi-k3 | complex | tool_use | 0 | 18.3k | 275 | $0.0000 | 67 | 26.7 KiB | 3.6 s |
| 218 | kimi-k3 | complex | tool_use | 0 | 18.6k | 232 | $0.0000 | 13 | 5.4 KiB | 3.0 s |
| 219 | kimi-k3 | complex | - | 0 | 19.0k | 984 | $0.0000 | 169 | 60.4 KiB | 0 ms |
| 220 | kimi-k3 | complex | tool_use | 0 | 20.0k | 189 | $0.0000 | 3 | 1.5 KiB | 2.9 s |
| 221 | kimi-k3 | complex | end_turn | 0 | 21.4k | 416 | $0.0000 | 219 | 81.3 KiB | 7.1 s |
| 222 | glm-5.3 | standard | tool_use | 0 | 22.2k | 332 | $0.0000 | 128 | 49.3 KiB | 4.0 s |
| 223 | glm-5.3-flash | simple | tool_use | 0 | 23.6k | 380 | $0.0000 | 3 | 2.2 KiB | 5.4 s |
| 224 | glm-5.3-flash | simple | tool_use | 0 | 24.3k | 209 | $0.0000 | 3 | 1.9 KiB | 5.4 s |
| 225 | glm-5.3-flash | simple | tool_use | 0 | 24.8k | 187 | $0.0000 | 3 | 1.7 KiB | 3.1 s |
| 226 | glm-5.3-flash | simple | tool_use | 0 | 25.0k | 196 | $0.0000 | 3 | 1.7 KiB | 4.0 s |
| 227 | glm-5.3-flash | simple | tool_use | 0 | 25.3k | 247 | $0.0000 | 3 | 1.8 KiB | 3.2 s |
| 228 | glm-5.3-flash | simple | tool_use | 0 | 25.8k | 109 | $0.0000 | 2 | 1.4 KiB | 2.8 s |
| 229 | glm-5.3-flash | simple | tool_use | 0 | 26.0k | 126 | $0.0000 | 2 | 1.5 KiB | 2.1 s |
| 230 | glm-5.3-flash | simple | end_turn | 0 | 25.7k | 304 | $0.0000 | 109 | 24.4 KiB | 8.5 s |
| 231 | kimi-k3 | standard | tool_use | 0 | 95.7k | 124 | $0.0000 | 3 | 1.2 KiB | 3.5 s |
| 232 | kimi-k3 | standard | tool_use | 0 | 95.8k | 99 | $0.0000 | 3 | 1.1 KiB | 2.9 s |
| 233 | kimi-k3 | standard | tool_use | 0 | 103.5k | 137 | $0.0000 | 17 | 5.2 KiB | 3.5 s |
| 234 | kimi-k3 | standard | tool_use | 0 | 103.7k | 177 | $0.0000 | 3 | 1.4 KiB | 4.2 s |
| 235 | kimi-k3 | standard | tool_use | 0 | 104.0k | 148 | $0.0000 | 3 | 1.3 KiB | 3.4 s |
| 236 | kimi-k3 | standard | tool_use | 0 | 104.2k | 152 | $0.0000 | 3 | 1.3 KiB | 3.7 s |
| 237 | kimi-k3 | standard | tool_use | 0 | 105.2k | 235 | $0.0000 | 78 | 27.9 KiB | 4.7 s |
| 238 | kimi-k3 | standard | - | 0 | 105.6k | 104 | $0.0000 | 3 | 1.1 KiB | 0 ms |
| 239 | kimi-k3 | standard | tool_use | 0 | 106.3k | 110 | $0.0000 | 3 | 1.1 KiB | 1 ms |
| 240 | kimi-k3 | standard | tool_use | 0 | 106.4k | 97 | $0.0000 | 3 | 1.2 KiB | 3.9 s |
| 241 | kimi-k3 | standard | tool_use | 0 | 99.5k | 80 | $0.0000 | 3 | 1.1 KiB | 3.5 s |
| 242 | kimi-k3 | standard | tool_use | 0 | 99.9k | 269 | $0.0000 | 26 | 10.0 KiB | 5.1 s |
| 243 | kimi-k3 | standard | tool_use | 0 | 100.3k | 126 | $0.0000 | 3 | 1.3 KiB | 2.8 s |
| 244 | kimi-k3 | standard | tool_use | 0 | 100.5k | 109 | $0.0000 | 3 | 1.2 KiB | 3.0 s |
| 245 | kimi-k3 | standard | tool_use | 0 | 100.5k | 146 | $0.0000 | 41 | 14.0 KiB | 4.3 s |
| 246 | kimi-k3 | standard | tool_use | 0 | 100.8k | 81 | $0.0000 | 3 | 1.1 KiB | 2.4 s |
| 247 | kimi-k3 | standard | tool_use | 0 | 101.1k | 95 | $0.0000 | 3 | 1.2 KiB | 2.6 s |
| 248 | kimi-k3 | standard | tool_use | 0 | 101.3k | 97 | $0.0000 | 3 | 1.2 KiB | 3.7 s |
| 249 | kimi-k3 | standard | tool_use | 0 | 101.5k | 159 | $0.0000 | 3 | 1.3 KiB | 4.0 s |
| 250 | kimi-k3 | standard | tool_use | 0 | 101.7k | 86 | $0.0000 | 3 | 1.1 KiB | 4.4 s |
| 251 | kimi-k3 | standard | tool_use | 0 | 103.2k | 104 | $0.0000 | 3 | 1.1 KiB | 3.6 s |
| 252 | kimi-k3 | standard | - | 0 | 103.6k | 102 | $0.0000 | 3 | 1.1 KiB | 0 ms |
| 253 | kimi-k3 | standard | tool_use | 0 | 104.7k | 964 | $0.0000 | 131 | 48.3 KiB | 12.2 s |
| 254 | kimi-k3 | standard | tool_use | 0 | 104.6k | 112 | $0.0000 | 3 | 1.2 KiB | 2.8 s |
| 255 | kimi-k3 | standard | tool_use | 0 | 105.0k | 130 | $0.0000 | 3 | 1.2 KiB | 2.9 s |
| 256 | kimi-k3 | standard | tool_use | 0 | 105.3k | 133 | $0.0000 | 3 | 1.2 KiB | 3.2 s |
| 257 | kimi-k3 | standard | tool_use | 0 | 105.5k | 105 | $0.0000 | 3 | 1.1 KiB | 2.9 s |
| 258 | kimi-k3 | standard | tool_use | 0 | 105.7k | 102 | $0.0000 | 3 | 1.1 KiB | 2.9 s |
| 259 | kimi-k3 | standard | tool_use | 0 | 105.2k | 102 | $0.0000 | 3 | 1.2 KiB | 2.7 s |
| 260 | kimi-k3 | standard | tool_use | 0 | 105.4k | 662 | $0.0000 | 78 | 29.6 KiB | 8.7 s |
| 261 | kimi-k3 | standard | tool_use | 0 | 106.6k | 114 | $0.0000 | 3 | 1.3 KiB | 2.9 s |
| 262 | kimi-k3 | standard | tool_use | 0 | 107.1k | 142 | $0.0000 | 27 | 8.4 KiB | 4.3 s |
| 263 | kimi-k3 | standard | tool_use | 0 | 107.4k | 106 | $0.0000 | 3 | 1.2 KiB | 3.0 s |
| 264 | kimi-k3 | standard | tool_use | 0 | 107.6k | 157 | $0.0000 | 3 | 1.3 KiB | 3.7 s |
| 265 | kimi-k3 | standard | tool_use | 0 | 107.8k | 104 | $0.0000 | 3 | 1.2 KiB | 2.6 s |
| 266 | kimi-k3 | standard | tool_use | 0 | 108.1k | 95 | $0.0000 | 3 | 1.1 KiB | 2.4 s |
| 267 | kimi-k3 | standard | tool_use | 0 | 108.3k | 149 | $0.0000 | 3 | 1.3 KiB | 2.9 s |
| 268 | kimi-k3 | standard | tool_use | 0 | 108.5k | 110 | $0.0000 | 3 | 1.2 KiB | 2.7 s |
| 269 | kimi-k3 | standard | tool_use | 0 | 108.8k | 117 | $0.0000 | 3 | 1.2 KiB | 2.7 s |
| 270 | kimi-k3 | standard | tool_use | 0 | 109.0k | 180 | $0.0000 | 3 | 1.4 KiB | 3.4 s |
| 271 | kimi-k3 | standard | tool_use | 0 | 109.2k | 115 | $0.0000 | 3 | 1.2 KiB | 3.3 s |
| 272 | kimi-k3 | standard | tool_use | 0 | 109.4k | 159 | $0.0000 | 3 | 1.3 KiB | 3.1 s |
| 273 | kimi-k3 | standard | tool_use | 0 | 109.7k | 389 | $0.0000 | 122 | 42.6 KiB | 5.7 s |
| 274 | kimi-k3 | standard | tool_use | 0 | 110.1k | 144 | $0.0000 | 3 | 1.3 KiB | 3.0 s |
| 275 | kimi-k3 | standard | tool_use | 0 | 110.4k | 143 | $0.0000 | 3 | 1.3 KiB | 3.0 s |
| 276 | kimi-k3 | standard | tool_use | 0 | 110.7k | 143 | $0.0000 | 3 | 1.3 KiB | 3.3 s |
| 277 | kimi-k3 | standard | tool_use | 0 | 110.9k | 170 | $0.0000 | 3 | 1.3 KiB | 3.3 s |
| 278 | kimi-k3 | standard | tool_use | 0 | 118.0k | 235 | $0.0000 | 63 | 21.7 KiB | 3.5 s |
| 279 | kimi-k3 | standard | tool_use | 0 | 118.7k | 150 | $0.0000 | 22 | 8.3 KiB | 4.4 s |
| 280 | kimi-k3 | standard | tool_use | 0 | 119.2k | 107 | $0.0000 | 3 | 1.3 KiB | 3.5 s |
| 281 | kimi-k3 | standard | - | 0 | 119.5k | 461 | $0.0000 | 259 | 90.8 KiB | 0 ms |
| 282 | minimax-m3 | standard | end_turn | 0 | 102.6k | 2.7k | $0.0000 | 66 | 23.7 KiB | 23.5 s |
| 283 | kimi-k3 | standard | - | 0 | 16.3k | 487 | $0.0000 | 105 | 38.8 KiB | 0 ms |
| 284 | kimi-k3 | standard | tool_use | 0 | 17.2k | 202 | $0.0000 | 37 | 16.4 KiB | 1 ms |
| 285 | kimi-k3 | standard | tool_use | 0 | 17.5k | 118 | $0.0000 | 13 | 4.6 KiB | 2.1 s |
| 286 | kimi-k3 | standard | tool_use | 0 | 17.7k | 106 | $0.0000 | 14 | 5.8 KiB | 2.3 s |
| 287 | kimi-k3 | standard | tool_use | 0 | 19.3k | 252 | $0.0000 | 22 | 9.8 KiB | 3.3 s |
| 288 | kimi-k3 | standard | tool_use | 0 | 20.4k | 274 | $0.0000 | 30 | 14.0 KiB | 3.5 s |
| 289 | kimi-k3 | standard | - | 0 | 21.4k | 173 | $0.0000 | 16 | 7.5 KiB | 0 ms |
| 290 | kimi-k3 | standard | tool_use | 0 | 20.9k | 214 | $0.0000 | 39 | 15.0 KiB | 3.1 s |
| 291 | kimi-k3 | standard | tool_use | 0 | 21.2k | 84 | $0.0000 | 3 | 1.1 KiB | 1.8 s |
| 292 | kimi-k3 | standard | tool_use | 0 | 21.4k | 137 | $0.0000 | 14 | 6.0 KiB | 2.3 s |
| 293 | kimi-k3 | standard | tool_use | 0 | 21.0k | 195 | $0.0000 | 16 | 6.8 KiB | 3.9 s |
| 294 | kimi-k3 | standard | tool_use | 0 | 21.3k | 215 | $0.0000 | 33 | 11.8 KiB | 3.1 s |
| 295 | kimi-k3 | standard | tool_use | 0 | 21.7k | 232 | $0.0000 | 18 | 8.1 KiB | 5.0 s |
| 296 | kimi-k3 | standard | tool_use | 0 | 29.7k | 213 | $0.0000 | 16 | 5.2 KiB | 5.2 s |
| 297 | kimi-k3 | standard | tool_use | 0 | 30.0k | 174 | $0.0000 | 3 | 1.3 KiB | 6.7 s |
| 298 | kimi-k3 | standard | tool_use | 0 | 30.1k | 121 | $0.0000 | 3 | 1.2 KiB | 4.2 s |
| 299 | kimi-k3 | standard | tool_use | 0 | 30.4k | 139 | $0.0000 | 3 | 1.3 KiB | 2.8 s |
| 300 | kimi-k3 | standard | tool_use | 0 | 30.6k | 136 | $0.0000 | 13 | 4.8 KiB | 3.0 s |
| 301 | kimi-k3 | standard | tool_use | 0 | 30.9k | 211 | $0.0000 | 22 | 8.2 KiB | 3.4 s |
| 302 | kimi-k3 | standard | tool_use | 0 | 31.1k | 268 | $0.0000 | 50 | 18.5 KiB | 4.1 s |
| 303 | kimi-k3 | standard | tool_use | 0 | 31.6k | 607 | $0.0000 | 219 | 80.9 KiB | 9.2 s |
| 304 | kimi-k3 | standard | - | 0 | 25.7k | 263 | $0.0000 | 81 | 31.2 KiB | 0 ms |
| 305 | kimi-k3 | standard | tool_use | 0 | 25.2k | 100 | $0.0000 | 15 | 5.3 KiB | 2.3 s |
| 306 | kimi-k3 | standard | tool_use | 0 | 26.0k | 198 | $0.0000 | 69 | 21.3 KiB | 4.5 s |
| 307 | kimi-k3 | standard | - | 0 | 26.9k | 354 | $0.0000 | 48 | 18.3 KiB | 0 ms |
| 308 | kimi-k3 | standard | tool_use | 0 | 27.0k | 359 | $0.0000 | 26 | 9.2 KiB | 5.2 s |
| 309 | kimi-k3 | standard | tool_use | 0 | 27.4k | 146 | $0.0000 | 31 | 12.4 KiB | 3.0 s |
| 310 | kimi-k3 | standard | tool_use | 0 | 27.9k | 122 | $0.0000 | 20 | 8.6 KiB | 2.6 s |
| 311 | kimi-k3 | standard | tool_use | 0 | 28.3k | 384 | $0.0000 | 21 | 9.3 KiB | 5.5 s |
| 312 | kimi-k3 | standard | tool_use | 0 | 28.9k | 74 | $0.0000 | 3 | 1.1 KiB | 1.8 s |
| 313 | kimi-k3 | standard | tool_use | 0 | 29.2k | 127 | $0.0000 | 3 | 1.3 KiB | 2.5 s |
| 314 | kimi-k3 | standard | tool_use | 0 | 29.4k | 273 | $0.0000 | 17 | 7.1 KiB | 4.3 s |
| 315 | kimi-k3 | standard | tool_use | 0 | 29.9k | 163 | $0.0000 | 30 | 10.6 KiB | 3.5 s |
| 316 | kimi-k3 | standard | tool_use | 0 | 30.9k | 822 | $0.0000 | 93 | 33.3 KiB | 11.9 s |
| 317 | kimi-k3 | standard | tool_use | 0 | 31.5k | 185 | $0.0000 | 9 | 3.4 KiB | 3.4 s |
| 318 | kimi-k3 | standard | tool_use | 0 | 32.2k | 223 | $0.0000 | 41 | 14.4 KiB | 3.7 s |
| 319 | kimi-k3 | standard | tool_use | 0 | 32.4k | 183 | $0.0000 | 3 | 1.4 KiB | 2.9 s |
| 320 | kimi-k3 | standard | tool_use | 0 | 32.7k | 237 | $0.0000 | 92 | 30.9 KiB | 3.8 s |
| 321 | kimi-k3 | standard | tool_use | 0 | 33.0k | 115 | $0.0000 | 15 | 4.4 KiB | 2.7 s |
| 322 | kimi-k3 | standard | tool_use | 0 | 33.2k | 162 | $0.0000 | 3 | 1.3 KiB | 2.9 s |
| 323 | kimi-k3 | standard | tool_use | 0 | 33.8k | 219 | $0.0000 | 53 | 20.8 KiB | 3.7 s |
| 324 | kimi-k3 | standard | tool_use | 0 | 34.5k | 59 | $0.0000 | 7 | 2.4 KiB | 2.1 s |
| 325 | kimi-k3 | standard | tool_use | 0 | 34.6k | 330 | $0.0000 | 4 | 2.3 KiB | 4.2 s |
| 326 | kimi-k3 | standard | end_turn | 0 | 35.0k | 624 | $0.0000 | 353 | 123.0 KiB | 7.1 s |
| 327 | kimi-k3 | standard | tool_use | 0 | 35.7k | 317 | $0.0000 | 133 | 46.8 KiB | 6.3 s |
| 328 | kimi-k3 | standard | - | 0 | 36.1k | 211 | $0.0000 | 3 | 1.4 KiB | 0 ms |
| 329 | kimi-k3 | standard | tool_use | 0 | 37.0k | 196 | $0.0000 | 32 | 12.1 KiB | 4.0 s |
| 330 | kimi-k3 | standard | tool_use | 0 | 37.3k | 84 | $0.0000 | 3 | 1.1 KiB | 2.5 s |
| 331 | kimi-k3 | standard | tool_use | 0 | 37.4k | 112 | $0.0000 | 3 | 1.2 KiB | 3.2 s |
| 332 | kimi-k3 | standard | tool_use | 0 | 37.6k | 101 | $0.0000 | 3 | 1.2 KiB | 3.0 s |
| 333 | kimi-k3 | standard | tool_use | 0 | 37.8k | 115 | $0.0000 | 3 | 1.1 KiB | 2.8 s |
| 334 | kimi-k3 | standard | tool_use | 0 | 38.1k | 226 | $0.0000 | 54 | 20.7 KiB | 4.8 s |
| 335 | kimi-k3 | standard | unspecified | 0 | 0 | 0 | $0.0000 | 1 | 268 B | 749 ms |
| 336 | kimi-k3 | standard | unspecified | 1 | 0 | 0 | $0.0000 | 1 | 268 B | 665 ms |
| 337 | kimi-k3 | standard | unspecified | 2 | 0 | 0 | $0.0000 | 1 | 268 B | 576 ms |
| 338 | kimi-k3 | standard | unspecified | 3 | 0 | 0 | $0.0000 | 1 | 268 B | 674 ms |
| 339 | kimi-k3 | standard | tool_use | 4 | 38.4k | 151 | $0.0000 | 3 | 1.3 KiB | 4.3 s |
| 340 | kimi-k3 | standard | tool_use | 4 | 38.8k | 216 | $0.0000 | 57 | 21.7 KiB | 3.5 s |
| 341 | kimi-k3 | standard | tool_use | 4 | 38.7k | 232 | $0.0000 | 62 | 22.0 KiB | 4.0 s |
| 342 | kimi-k3 | standard | tool_use | 4 | 39.0k | 326 | $0.0000 | 95 | 31.6 KiB | 5.9 s |
| 343 | kimi-k3 | standard | tool_use | 4 | 39.5k | 226 | $0.0000 | 22 | 8.6 KiB | 3.9 s |
| 344 | kimi-k3 | standard | tool_use | 4 | 39.8k | 319 | $0.0000 | 71 | 26.4 KiB | 5.2 s |
| 345 | kimi-k3 | standard | tool_use | 4 | 40.5k | 116 | $0.0000 | 3 | 1.1 KiB | 2.5 s |
| 346 | kimi-k3 | standard | end_turn | 4 | 41.4k | 637 | $0.0000 | 345 | 124.2 KiB | 9.7 s |
| 347 | kimi-k3 | standard | tool_use | 0 | 42.2k | 246 | $0.0000 | 35 | 12.8 KiB | 6.4 s |
| 348 | kimi-k3 | standard | tool_use | 0 | 42.6k | 330 | $0.0000 | 44 | 13.5 KiB | 5.7 s |
| 349 | kimi-k3 | standard | tool_use | 0 | 43.0k | 393 | $0.0000 | 36 | 13.1 KiB | 6.9 s |
| 350 | kimi-k3 | standard | tool_use | 0 | 43.5k | 253 | $0.0000 | 3 | 1.5 KiB | 4.4 s |
| 351 | kimi-k3 | standard | tool_use | 0 | 43.8k | 345 | $0.0000 | 3 | 1.8 KiB | 8.5 s |
| 352 | kimi-k3 | standard | tool_use | 0 | 44.4k | 248 | $0.0000 | 3 | 1.6 KiB | 4.9 s |
| 353 | kimi-k3 | standard | tool_use | 0 | 44.8k | 181 | $0.0000 | 3 | 1.5 KiB | 4.4 s |
| 354 | kimi-k3 | standard | tool_use | 0 | 45.5k | 348 | $0.0000 | 53 | 18.2 KiB | 6.7 s |
| 355 | kimi-k3 | standard | tool_use | 0 | 45.7k | 204 | $0.0000 | 50 | 17.3 KiB | 4.5 s |
| 356 | kimi-k3 | standard | tool_use | 0 | 46.2k | 281 | $0.0000 | 42 | 14.6 KiB | 4.7 s |
| 357 | kimi-k3 | standard | tool_use | 0 | 46.8k | 531 | $0.0000 | 141 | 50.9 KiB | 8.2 s |
| 358 | kimi-k3 | standard | tool_use | 0 | 47.5k | 587 | $0.0000 | 181 | 65.4 KiB | 8.3 s |
| 359 | kimi-k3 | standard | tool_use | 0 | 48.3k | 467 | $0.0000 | 110 | 39.3 KiB | 7.2 s |
| 360 | kimi-k3 | standard | end_turn | 0 | 48.9k | 601 | $0.0000 | 358 | 119.0 KiB | 9.4 s |
| 361 | glm-5.3-flash | simple | - | 0 | 15.4k | 419 | $0.0000 | 93 | 22.5 KiB | 0 ms |
| 362 | glm-5.3-flash | simple | tool_use | 0 | 17.4k | 608 | $0.0000 | 186 | 43.6 KiB | 17 ms |
| 363 | glm-5.3-flash | simple | tool_use | 0 | 19.1k | 1.2k | $0.0000 | 426 | 100.0 KiB | 23.4 s |
| 364 | glm-5.3-flash | simple | tool_use | 0 | 20.5k | 1.0k | $0.0000 | 317 | 74.7 KiB | 18.6 s |
| 365 | glm-5.3-flash | simple | unspecified | 0 | 0 | 0 | $0.0000 | 99 | 22.5 KiB | 6.7 s |
| 366 | kimi-k3 | standard | - | 0 | 13.8k | 159 | $0.0000 | 10 | 4.1 KiB | 0 ms |
| 367 | kimi-k3 | standard | tool_use | 0 | 14.2k | 186 | $0.0000 | 45 | 19.1 KiB | 4 ms |
| 368 | kimi-k3 | standard | tool_use | 0 | 15.9k | 812 | $0.0000 | 379 | 143.1 KiB | 3 ms |
| 369 | kimi-k3 | standard | tool_use | 0 | 17.6k | 101 | $0.0000 | 3 | 1.1 KiB | 3 ms |
| 370 | kimi-k3 | standard | tool_use | 0 | 17.8k | 179 | $0.0000 | 46 | 18.0 KiB | 5 ms |
| 371 | kimi-k3 | standard | tool_use | 0 | 18.6k | 652 | $0.0000 | 223 | 84.1 KiB | 11 ms |
| 372 | kimi-k3 | standard | tool_use | 0 | 19.7k | 460 | $0.0000 | 149 | 56.9 KiB | 6.9 s |
| 373 | kimi-k3 | standard | tool_use | 0 | 17.6k | 190 | $0.0000 | 3 | 1.4 KiB | 4.5 s |
| 374 | kimi-k3 | standard | tool_use | 0 | 18.5k | 286 | $0.0000 | 34 | 13.0 KiB | 4.5 s |
| 375 | kimi-k3 | standard | tool_use | 0 | 18.7k | 193 | $0.0000 | 3 | 1.4 KiB | 3.2 s |
| 376 | kimi-k3 | standard | tool_use | 0 | 19.7k | 234 | $0.0000 | 3 | 1.5 KiB | 3.9 s |
| 377 | kimi-k3 | standard | tool_use | 0 | 28.1k | 1.7k | $0.0000 | 836 | 315.5 KiB | 22.7 s |
| 378 | kimi-k3 | standard | - | 0 | 28.9k | 115 | $0.0000 | 3 | 1.2 KiB | 0 ms |
| 379 | kimi-k3 | standard | tool_use | 0 | 29.5k | 111 | $0.0000 | 3 | 1.1 KiB | 4 ms |
| 380 | kimi-k3 | standard | tool_use | 0 | 31.0k | 109 | $0.0000 | 3 | 1.1 KiB | 3 ms |
| 381 | kimi-k3 | standard | tool_use | 0 | 31.7k | 800 | $0.0000 | 401 | 150.6 KiB | 4 ms |
| 382 | kimi-k3 | standard | tool_use | 0 | 32.5k | 101 | $0.0000 | 3 | 1.1 KiB | 4 ms |
| 383 | kimi-k3 | standard | tool_use | 0 | 25.6k | 231 | $0.0000 | 3 | 1.7 KiB | 4.1 s |
| 384 | kimi-k3 | standard | tool_use | 0 | 25.8k | 329 | $0.0000 | 4 | 2.1 KiB | 5.7 s |
| 385 | kimi-k3 | standard | tool_use | 0 | 26.4k | 791 | $0.0000 | 11 | 5.9 KiB | 11.4 s |
| 386 | kimi-k3 | standard | tool_use | 0 | 27.7k | 1.1k | $0.0000 | 18 | 9.0 KiB | 15.1 s |
| 387 | kimi-k3 | standard | tool_use | 0 | 29.2k | 135 | $0.0000 | 3 | 1.2 KiB | 3.2 s |
| 388 | kimi-k3 | standard | tool_use | 0 | 28.8k | 102 | $0.0000 | 3 | 1.1 KiB | 2.5 s |
| 389 | kimi-k3 | standard | tool_use | 0 | 29.3k | 158 | $0.0000 | 3 | 1.3 KiB | 3.4 s |
| 390 | kimi-k3 | standard | tool_use | 0 | 37.2k | 219 | $0.0000 | 3 | 1.5 KiB | 4.6 s |
| 391 | kimi-k3 | standard | tool_use | 0 | 38.8k | 241 | $0.0000 | 3 | 1.6 KiB | 4.2 s |
| 392 | kimi-k3 | standard | tool_use | 0 | 40.6k | 570 | $0.0000 | 4 | 2.9 KiB | 7.9 s |
| 393 | kimi-k3 | standard | - | 0 | 41.4k | 132 | $0.0000 | 15 | 5.6 KiB | 0 ms |
| 394 | kimi-k3 | standard | tool_use | 0 | 41.8k | 509 | $0.0000 | 4 | 2.6 KiB | 7.9 s |
| 395 | kimi-k3 | standard | tool_use | 0 | 42.8k | 132 | $0.0000 | 3 | 1.2 KiB | 2.9 s |
| 396 | kimi-k3 | standard | - | 0 | 35.8k | 102 | $0.0000 | 3 | 1.1 KiB | 0 ms |
| 397 | kimi-k3 | standard | tool_use | 0 | 36.0k | 102 | $0.0000 | 3 | 1.1 KiB | 5 ms |
| 398 | kimi-k3 | standard | tool_use | 0 | 35.9k | 163 | $0.0000 | 31 | 12.4 KiB | 4 ms |
| 399 | kimi-k3 | standard | tool_use | 0 | 36.2k | 140 | $0.0000 | 3 | 1.2 KiB | 3.4 s |
| 400 | kimi-k3 | standard | tool_use | 0 | 36.6k | 992 | $0.0000 | 6 | 4.9 KiB | 13.1 s |
| 401 | kimi-k3 | standard | tool_use | 0 | 38.4k | 153 | $0.0000 | 3 | 1.3 KiB | 3.5 s |
| 402 | kimi-k3 | standard | - | 0 | 38.9k | 283 | $0.0000 | 3 | 1.9 KiB | 0 ms |
| 403 | kimi-k3 | standard | tool_use | 0 | 38.8k | 70 | $0.0000 | 3 | 1.1 KiB | 3 ms |
| 404 | kimi-k3 | standard | tool_use | 0 | 38.9k | 79 | $0.0000 | 3 | 1.1 KiB | 2.2 s |
| 405 | kimi-k3 | standard | - | 0 | 39.1k | 99 | $0.0000 | 3 | 1.1 KiB | 0 ms |
| 406 | kimi-k3 | standard | tool_use | 0 | 39.9k | 100 | $0.0000 | 3 | 1.1 KiB | 4 ms |
| 407 | kimi-k3 | standard | tool_use | 0 | 40.2k | 330 | $0.0000 | 4 | 2.1 KiB | 4.3 s |
| 408 | kimi-k3 | standard | tool_use | 0 | 40.3k | 236 | $0.0000 | 13 | 4.1 KiB | 4.2 s |
| 409 | kimi-k3 | standard | tool_use | 0 | 40.6k | 169 | $0.0000 | 3 | 1.3 KiB | 3.0 s |
| 410 | kimi-k3 | standard | tool_use | 0 | 41.1k | 144 | $0.0000 | 16 | 6.4 KiB | 2.9 s |
| 411 | kimi-k3 | standard | - | 0 | 41.5k | 192 | $0.0000 | 3 | 1.5 KiB | 0 ms |
| 412 | kimi-k3 | standard | end_turn | 0 | 41.9k | 647 | $0.0000 | 347 | 128.2 KiB | 11.6 s |
| 413 | kimi-k3 | standard | tool_use | 0 | 42.9k | 178 | $0.0000 | 34 | 15.0 KiB | 4.9 s |
| 414 | kimi-k3 | standard | tool_use | 0 | 45.6k | 109 | $0.0000 | 3 | 1.1 KiB | 8.0 s |
| 415 | kimi-k3 | standard | tool_use | 0 | 48.3k | 144 | $0.0000 | 3 | 1.3 KiB | 3.5 s |
| 416 | kimi-k3 | standard | tool_use | 0 | 49.7k | 255 | $0.0000 | 4 | 1.7 KiB | 4.8 s |
| 417 | kimi-k3 | standard | tool_use | 0 | 50.2k | 192 | $0.0000 | 3 | 1.4 KiB | 4.1 s |
| 418 | kimi-k3 | standard | tool_use | 0 | 61.3k | 289 | $0.0000 | 3 | 1.8 KiB | 4.9 s |
| 419 | kimi-k3 | standard | - | 0 | 62.6k | 106 | $0.0000 | 3 | 1.1 KiB | 0 ms |
| 420 | kimi-k3 | standard | tool_use | 0 | 61.2k | 109 | $0.0000 | 3 | 1.1 KiB | 3.7 s |
| 421 | kimi-k3 | standard | - | 0 | 59.8k | 107 | $0.0000 | 3 | 1.1 KiB | 0 ms |
| 422 | kimi-k3 | standard | tool_use | 0 | 58.9k | 701 | $0.0000 | 5 | 3.5 KiB | 8.9 s |
| 423 | kimi-k3 | standard | tool_use | 0 | 59.0k | 711 | $0.0000 | 5 | 3.6 KiB | 11.2 s |
| 424 | kimi-k3 | standard | - | 0 | 59.8k | 122 | $0.0000 | 11 | 4.9 KiB | 0 ms |
| 425 | kimi-k3 | standard | tool_use | 0 | 50.2k | 102 | $0.0000 | 3 | 1.1 KiB | 8.0 s |
| 426 | kimi-k3 | standard | tool_use | 0 | 50.1k | 121 | $0.0000 | 3 | 1.2 KiB | 4.0 s |
| 427 | kimi-k3 | standard | tool_use | 0 | 52.3k | 105 | $0.0000 | 3 | 1.1 KiB | 2.7 s |
| 428 | kimi-k3 | standard | tool_use | 0 | 54.1k | 118 | $0.0000 | 3 | 1.2 KiB | 3.0 s |
| 429 | kimi-k3 | standard | tool_use | 0 | 52.7k | 102 | $0.0000 | 3 | 1.1 KiB | 3.0 s |
| 430 | kimi-k3 | standard | tool_use | 0 | 53.2k | 107 | $0.0000 | 3 | 1.1 KiB | 3.7 s |
| 431 | kimi-k3 | standard | - | 0 | 54.4k | 110 | $0.0000 | 4 | 1.1 KiB | 0 ms |
| 432 | kimi-k3 | standard | tool_use | 0 | 53.4k | 1.7k | $0.0000 | 14 | 9.9 KiB | 27.2 s |
| 433 | kimi-k3 | standard | tool_use | 0 | 55.9k | 389 | $0.0000 | 4 | 2.3 KiB | 8.8 s |
| 434 | kimi-k3 | standard | tool_use | 0 | 56.6k | 1.3k | $0.0000 | 7 | 6.0 KiB | 20.6 s |
| 435 | kimi-k3 | standard | - | 0 | 57.2k | 104 | $0.0000 | 3 | 1.1 KiB | 0 ms |
| 436 | kimi-k3 | standard | tool_use | 0 | 57.6k | 103 | $0.0000 | 3 | 1.1 KiB | 3.4 s |
| 437 | kimi-k3 | standard | - | 0 | 58.5k | 107 | $0.0000 | 3 | 1.1 KiB | 0 ms |
| 438 | kimi-k3 | standard | tool_use | 0 | 57.9k | 111 | $0.0000 | 3 | 1.1 KiB | 4 ms |
| 439 | kimi-k3 | standard | tool_use | 0 | 59.0k | 108 | $0.0000 | 3 | 1.1 KiB | 3.5 s |
| 440 | kimi-k3 | standard | tool_use | 0 | 58.8k | 103 | $0.0000 | 3 | 1.1 KiB | 5.3 s |
| 441 | kimi-k3 | standard | - | 0 | 58.0k | 108 | $0.0000 | 3 | 1.1 KiB | 0 ms |
| 442 | kimi-k3 | standard | tool_use | 0 | 58.6k | 717 | $0.0000 | 11 | 5.5 KiB | 13.1 s |
| 443 | kimi-k3 | standard | - | 0 | 59.0k | 1.0k | $0.0000 | 6 | 5.0 KiB | 0 ms |
| 444 | kimi-k3 | standard | tool_use | 0 | 60.1k | 584 | $0.0000 | 286 | 101.8 KiB | 12.1 s |
| 445 | kimi-k3 | standard | tool_use | 0 | 61.0k | 104 | $0.0000 | 3 | 1.1 KiB | 2.7 s |
| 446 | kimi-k3 | standard | tool_use | 0 | 61.7k | 191 | $0.0000 | 3 | 1.4 KiB | 4.2 s |
| 447 | kimi-k3 | standard | - | 0 | 61.4k | 111 | $0.0000 | 3 | 1.1 KiB | 0 ms |
| 448 | kimi-k3 | standard | tool_use | 0 | 62.9k | 108 | $0.0000 | 3 | 1.1 KiB | 3.2 s |
| 449 | kimi-k3 | standard | tool_use | 0 | 63.4k | 2.5k | $0.0000 | 44 | 22.1 KiB | 38.0 s |
| 450 | kimi-k3 | standard | tool_use | 0 | 68.0k | 456 | $0.0000 | 19 | 7.5 KiB | 12.6 s |
| 451 | kimi-k3 | standard | tool_use | 0 | 68.7k | 1.3k | $0.0000 | 7 | 6.6 KiB | 24.4 s |
| 452 | kimi-k3 | standard | tool_use | 0 | 71.0k | 112 | $0.0000 | 3 | 1.1 KiB | 4.6 s |
| 453 | kimi-k3 | standard | tool_use | 0 | 71.4k | 237 | $0.0000 | 3 | 1.7 KiB | 5.8 s |
| 454 | kimi-k3 | standard | tool_use | 0 | 71.7k | 73 | $0.0000 | 3 | 1.1 KiB | 3.4 s |
| 455 | kimi-k3 | standard | - | 0 | 72.2k | 122 | $0.0000 | 16 | 5.0 KiB | 0 ms |
| 456 | kimi-k3 | standard | tool_use | 0 | 71.6k | 102 | $0.0000 | 3 | 1.1 KiB | 4 ms |
| 457 | kimi-k3 | standard | tool_use | 0 | 71.8k | 103 | $0.0000 | 3 | 1.1 KiB | 2 ms |
| 458 | kimi-k3 | standard | tool_use | 0 | 70.7k | 126 | $0.0000 | 18 | 5.3 KiB | 4.0 s |
| 459 | kimi-k3 | standard | tool_use | 0 | 71.2k | 278 | $0.0000 | 3 | 1.8 KiB | 5.5 s |
| 460 | kimi-k3 | standard | tool_use | 0 | 70.9k | 73 | $0.0000 | 3 | 1.1 KiB | 2.7 s |
| 461 | kimi-k3 | standard | tool_use | 0 | 71.1k | 172 | $0.0000 | 3 | 1.3 KiB | 3.9 s |
| 462 | kimi-k3 | standard | tool_use | 0 | 71.6k | 176 | $0.0000 | 3 | 1.3 KiB | 3.8 s |
| 463 | kimi-k3 | standard | tool_use | 0 | 72.2k | 155 | $0.0000 | 3 | 1.3 KiB | 3.7 s |
| 464 | kimi-k3 | standard | tool_use | 0 | 80.2k | 102 | $0.0000 | 3 | 1.1 KiB | 3.4 s |
| 465 | kimi-k3 | standard | tool_use | 0 | 80.6k | 131 | $0.0000 | 3 | 1.3 KiB | 3.4 s |
| 466 | kimi-k3 | standard | tool_use | 0 | 81.0k | 91 | $0.0000 | 3 | 1.1 KiB | 4.1 s |
| 467 | kimi-k3 | standard | - | 0 | 81.2k | 144 | $0.0000 | 25 | 8.8 KiB | 0 ms |
| 468 | kimi-k3 | standard | tool_use | 0 | 81.9k | 106 | $0.0000 | 3 | 1.1 KiB | 3.6 s |
| 469 | kimi-k3 | standard | tool_use | 0 | 81.8k | 497 | $0.0000 | 4 | 2.8 KiB | 9.0 s |
| 470 | kimi-k3 | standard | tool_use | 0 | 82.4k | 104 | $0.0000 | 3 | 1.1 KiB | 3.0 s |
| 471 | kimi-k3 | standard | tool_use | 0 | 83.4k | 1.2k | $0.0000 | 16 | 8.7 KiB | 19.8 s |
| 472 | kimi-k3 | standard | - | 0 | 77.3k | 102 | $0.0000 | 3 | 1.1 KiB | 0 ms |
| 473 | kimi-k3 | standard | tool_use | 0 | 77.7k | 201 | $0.0000 | 10 | 3.6 KiB | 5.2 s |
| 474 | kimi-k3 | standard | tool_use | 0 | 78.5k | 103 | $0.0000 | 3 | 1.1 KiB | 3.1 s |
| 475 | kimi-k3 | standard | tool_use | 0 | 78.6k | 261 | $0.0000 | 3 | 1.9 KiB | 6.4 s |
| 476 | kimi-k3 | standard | tool_use | 0 | 79.2k | 190 | $0.0000 | 3 | 1.4 KiB | 4.5 s |
| 477 | kimi-k3 | standard | tool_use | 0 | 79.9k | 332 | $0.0000 | 4 | 2.0 KiB | 7.4 s |
| 478 | kimi-k3 | standard | tool_use | 0 | 80.4k | 148 | $0.0000 | 3 | 1.3 KiB | 4.6 s |
| 479 | kimi-k3 | standard | tool_use | 0 | 80.7k | 145 | $0.0000 | 28 | 9.6 KiB | 4.0 s |
| 480 | kimi-k3 | standard | tool_use | 0 | 81.0k | 755 | $0.0000 | 5 | 3.8 KiB | 12.4 s |
| 481 | kimi-k3 | standard | tool_use | 0 | 82.3k | 1.5k | $0.0000 | 7 | 7.1 KiB | 25.5 s |
| 482 | kimi-k3 | standard | tool_use | 0 | 84.6k | 576 | $0.0000 | 4 | 3.0 KiB | 12.4 s |
| 483 | kimi-k3 | standard | tool_use | 0 | 85.9k | 1.1k | $0.0000 | 6 | 4.9 KiB | 23.0 s |
| 484 | kimi-k3 | standard | unspecified | 0 | 0 | 0 | $0.0000 | 1 | 134 B | 3.4 s |
| 485 | kimi-k3 | standard | tool_use | 0 | 87.9k | 187 | $0.0000 | 3 | 1.3 KiB | 4.5 s |
| 486 | kimi-k3 | standard | - | 0 | 88.8k | 186 | $0.0000 | 3 | 1.3 KiB | 0 ms |
| 487 | kimi-k3 | standard | tool_use | 0 | 89.3k | 166 | $0.0000 | 3 | 1.4 KiB | 3.7 s |
| 488 | kimi-k3 | standard | tool_use | 0 | 89.4k | 313 | $0.0000 | 3 | 2.0 KiB | 5.9 s |
| 489 | kimi-k3 | standard | tool_use | 0 | 89.7k | 187 | $0.0000 | 3 | 1.4 KiB | 4.3 s |
| 490 | kimi-k3 | standard | - | 0 | 90.2k | 105 | $0.0000 | 3 | 1.1 KiB | 0 ms |
| 491 | kimi-k3 | standard | tool_use | 0 | 90.9k | 166 | $0.0000 | 3 | 1.4 KiB | 4.7 s |
| 492 | kimi-k3 | standard | tool_use | 0 | 90.9k | 791 | $0.0000 | 5 | 4.5 KiB | 12.4 s |
| 493 | kimi-k3 | standard | tool_use | 0 | 91.5k | 188 | $0.0000 | 3 | 1.4 KiB | 4.0 s |
| 494 | kimi-k3 | standard | tool_use | 0 | 92.1k | 185 | $0.0000 | 4 | 1.4 KiB | 4.2 s |
| 495 | kimi-k3 | standard | tool_use | 0 | 93.2k | 135 | $0.0000 | 4 | 1.3 KiB | 3.4 s |
| 496 | kimi-k3 | standard | tool_use | 0 | 93.4k | 495 | $0.0000 | 4 | 3.1 KiB | 8.8 s |
| 497 | kimi-k3 | standard | tool_use | 0 | 93.6k | 159 | $0.0000 | 3 | 1.3 KiB | 5.4 s |
| 498 | kimi-k3 | standard | - | 0 | 93.8k | 107 | $0.0000 | 3 | 1.1 KiB | 0 ms |
| 499 | kimi-k3 | standard | tool_use | 0 | 94.4k | 105 | $0.0000 | 3 | 1.1 KiB | 2 ms |
| 500 | kimi-k3 | standard | tool_use | 0 | 94.3k | 347 | $0.0000 | 4 | 2.3 KiB | 7.4 s |
| 501 | kimi-k3 | standard | tool_use | 0 | 95.0k | 159 | $0.0000 | 3 | 1.3 KiB | 4.4 s |
| 502 | kimi-k3 | standard | tool_use | 0 | 95.3k | 131 | $0.0000 | 3 | 1.3 KiB | 3.3 s |
| 503 | kimi-k3 | standard | tool_use | 0 | 95.7k | 830 | $0.0000 | 30 | 12.8 KiB | 12.3 s |
| 504 | kimi-k3 | standard | tool_use | 0 | 97.1k | 371 | $0.0000 | 4 | 2.5 KiB | 6.4 s |
| 505 | kimi-k3 | standard | tool_use | 0 | 97.8k | 186 | $0.0000 | 3 | 1.4 KiB | 4.3 s |
| 506 | kimi-k3 | standard | tool_use | 0 | 98.4k | 602 | $0.0000 | 4 | 3.1 KiB | 8.8 s |
| 507 | kimi-k3 | standard | - | 0 | 99.6k | 105 | $0.0000 | 3 | 1.1 KiB | 0 ms |
| 508 | kimi-k3 | standard | tool_use | 0 | 99.8k | 71 | $0.0000 | 3 | 1.1 KiB | 3 ms |
| 509 | kimi-k3 | standard | tool_use | 0 | 0 | 0 | $0.0000 | 0 | 0 B | 2 ms |
| 510 | kimi-k3 | standard | tool_use | 0 | 102.0k | 148 | $0.0000 | 3 | 1.3 KiB | 6.1 s |
| 511 | kimi-k3 | standard | tool_use | 0 | 102.4k | 212 | $0.0000 | 3 | 1.4 KiB | 5.7 s |
| 512 | kimi-k3 | standard | tool_use | 0 | 103.3k | 90 | $0.0000 | 10 | 3.9 KiB | 3.1 s |
| 513 | kimi-k3 | standard | - | 0 | 103.5k | 34 | $0.0000 | 3 | 1.0 KiB | 0 ms |
| 514 | kimi-k3 | standard | tool_use | 0 | 103.6k | 68 | $0.0000 | 3 | 1.1 KiB | 3 ms |
| 515 | kimi-k3 | standard | tool_use | 0 | 103.7k | 92 | $0.0000 | 3 | 1.2 KiB | 3.0 s |
| 516 | kimi-k3 | standard | tool_use | 0 | 103.9k | 128 | $0.0000 | 3 | 1.2 KiB | 4.2 s |
| 517 | kimi-k3 | standard | - | 0 | 104.1k | 596 | $0.0000 | 346 | 118.1 KiB | 0 ms |
| 518 | glm-5.3-flash | standard | end_turn | 0 | 83.8k | 3.1k | $0.0000 | 1027 | 221.8 KiB | 1m 1s |
| 519 | glm-5.3 | complex | - | 0 | 46.1k | 2.2k | $0.0000 | 1217 | 445.3 KiB | 0 ms |
| 520 | glm-5.3 | complex | tool_use | 0 | 46.4k | 369 | $0.0000 | 187 | 75.0 KiB | 4.6 s |
| 521 | glm-5.3 | complex | - | 0 | 0 | 0 | $0.0000 | 1017 | 407.6 KiB | 0 ms |
| 522 | glm-5.3 | complex | - | 0 | 73.9k | 1.2k | $0.0000 | 631 | 240.7 KiB | 0 ms |
| 523 | glm-5.3 | complex | tool_use | 0 | 74.3k | 114 | $0.0000 | 4 | 1.7 KiB | 8.8 s |
| 524 | glm-5.3 | complex | tool_use | 0 | 74.6k | 176 | $0.0000 | 20 | 7.8 KiB | 2.9 s |
| 525 | glm-5.3 | complex | tool_use | 0 | 49.5k | 190 | $0.0000 | 64 | 26.3 KiB | 2.8 s |
| 526 | glm-5.3 | complex | tool_use | 0 | 49.7k | 36 | $0.0000 | 3 | 1.1 KiB | 1.6 s |
| 527 | glm-5.3 | complex | tool_use | 0 | 49.5k | 101 | $0.0000 | 2 | 1.4 KiB | 2.1 s |
| 528 | glm-5.3 | complex | tool_use | 0 | 50.4k | 917 | $0.0000 | 328 | 132.3 KiB | 7.5 s |
| 529 | glm-5.3 | complex | tool_use | 0 | 50.8k | 217 | $0.0000 | 42 | 17.6 KiB | 6.4 s |
| 530 | glm-5.3 | complex | tool_use | 0 | 51.3k | 840 | $0.0000 | 326 | 123.6 KiB | 8.5 s |
| 531 | glm-5.3 | complex | tool_use | 0 | 51.7k | 62 | $0.0000 | 26 | 10.8 KiB | 2.4 s |
| 532 | glm-5.3 | complex | end_turn | 0 | 51.8k | 423 | $0.0000 | 221 | 83.7 KiB | 4.4 s |

## 8. Error-level events

| Event | Count |
|---|---|
| thread.save | 412 |
| rag.embed | 3 |

**Samples:**

```
2026-09-10T09:04:36.286 persist thread.save: log verification FAILED id=fd6f6872d70a1c61 messages=155 — keeping the legacy document
2026-09-10T09:04:38.786 persist thread.save: log verification FAILED id=fd6f6872d70a1c61 messages=156 — keeping the legacy document
2026-09-10T09:04:43.248 persist thread.save: log verification FAILED id=fd6f6872d70a1c61 messages=157 — keeping the legacy document
2026-09-10T09:04:45.708 persist thread.save: log verification FAILED id=fd6f6872d70a1c61 messages=158 — keeping the legacy document
2026-09-10T09:04:47.886 persist thread.save: log verification FAILED id=fd6f6872d70a1c61 messages=159 — keeping the legacy document
2026-09-10T09:04:49.871 persist thread.save: log verification FAILED id=fd6f6872d70a1c61 messages=160 — keeping the legacy document
2026-09-10T09:04:52.567 persist thread.save: log verification FAILED id=fd6f6872d70a1c61 messages=161 — keeping the legacy document
2026-09-10T09:04:59.113 persist thread.save: log verification FAILED id=fd6f6872d70a1c61 messages=162 — keeping the legacy document
```

## 9. Persistence

- Thread saves: 942
- Total messages persisted: 162630
- Avg messages per save: 172

---
*Generated by agentty-stats.*
