# agentty — Session Statistics Report

**Sources:** `/home/jon/.agentty/logs/2026-09-10__06:03:34UTC__debug.log`, `/home/jon/.agentty/logs/2026-09-10__06:03:34UTC__debug.log.old`, `/home/jon/.agentty/logs/2026-09-10__08:21:03UTC__debug.log`, `/home/jon/.agentty/logs/2026-09-10__08:21:03UTC__debug.log.old`, `/home/jon/.agentty/logs/2026-09-10__09:20:28UTC__debug.log`

**Generated:** 2026-09-10T13:19:26.608

**Pricing source:** [models.dev](https://models.dev) (agentty cache: `/home/jon/.agentty/cache/modelsdev.json`, USD per 1M tokens)

---

## 1. Overview

| Metric | Value |
|---|---|
| Total turns (dispatches) | 396 |
| Time span | 2026-09-10T08:03:34.766 → 2026-09-10T13:19:26.608 (315m 51s) |
| Models used | glm-5.3, glm-5.3-flash, kimi-k3 |
| Total prompt tokens | 20.38M (20381149) |
| Total completion tokens | 393.8k (393845) |
| Total tokens | 20.77M |
| Estimated cost | $9.3793 |
| Wire chunks | 109663 (30.68 MiB) |
| Request bytes | 78.67 MiB |
| Tool calls | 391 |
| Thread saves | 737 (78503 messages) |
| Models loaded | 2026-09-10__06:03:34UTC__debug.log.old=19; 2026-09-10__08:21:03UTC__debug.log.old=19; 2026-09-10__09:20:28UTC__debug.log=19 |
| Error-level events | 344 (407 routine auth) |

## 2. Log volume

### By level

| Level | Count |
|---|---|
| T | 110059 |
| D | 3128 |
| E | 751 |
| I | 44 |
| W | 20 |

### By component

| Component | Count |
|---|---|
| wire | 112058 |
| persist | 737 |
| model | 396 |
| smart | 396 |
| tool | 391 |
| ui | 9 |
| net | 7 |
| general | 3 |
| rag | 3 |
| auth | 2 |

### By event

| Event | Count |
|---|---|
| wire.chunk | 109663 |
| thread.save | 737 |
| openai.auth | 407 |
| dispatch.turn | 396 |
| openai.request | 396 |
| openai.request.body | 396 |
| route.turn | 396 |
| stream.end | 396 |
| stream.response | 396 |
| stream.result | 396 |
| tool.exec | 391 |
| paste.recv | 9 |
| models.loaded | 5 |
| http.local_failed | 4 |
| http.connect_failed | 3 |
| provider.select | 3 |
| rag.embed | 3 |
| startup | 3 |
| copilot.models.fallback | 2 |

## 3. Smart-mode routing

### Role

| Role | Turns | % of total |
|---|---|---|
| utility | 180 | 45.5 |
| implementation | 129 | 32.6 |
| strategic | 85 | 21.5 |
| none | 2 | 0.5 |

### Complexity

| Complexity | Turns | % of total |
|---|---|---|
| standard | 129 | 32.6 |
| simple | 123 | 31.1 |
| complex | 86 | 21.7 |
| trivial | 58 | 14.6 |

### Orchestration flags

- Orchestrate: 396 / 396 turns
- Subagents: 396 / 396 turns
- Compacting: 2 / 396 turns

## 4. Per-model usage

| Model | Turns | Prompt tok | Completion tok | Total tok | Req bytes | Chunk bytes | Chunks | Retried | Errors |
|---|---|---|---|---|---|---|---|---|---|
| glm-5.3-flash | 182 | 11.25M | 296.4k | 11.55M | 43.50 MiB | 18.68 MiB | 81808 | 0 | 0 |
| glm-5.3 | 129 | 6.23M | 64.6k | 6.29M | 24.23 MiB | 6.29 MiB | 12715 | 0 | 0 |
| kimi-k3 | 85 | 2.90M | 32.9k | 2.93M | 10.94 MiB | 5.71 MiB | 15138 | 0 | 0 |

## 4b. Cost (USD)

*Prices from [models.dev](https://models.dev), loaded from `/home/jon/.agentty/cache/modelsdev.json`; all amounts are United States Dollars (USD). Cost = prompt/1M × input-rate + completion/1M × output-rate.*

| Model | Provider | $/1M in | $/1M out | Turns | Input cost | Output cost | Total cost |
|---|---|---|---|---|---|---|---|
| kimi-k3 | crof | 2 | 8 | 85 | $5.8001 | $0.2628 | $6.0629 |
| glm-5.3 | https://ollama.com/v1#main | 0.4 | 1.4 | 129 | $2.4916 | $0.0904 | $2.5821 |
| glm-5.3-flash | vancine | 0.06 | 0.2 | 182 | $0.6751 | $0.0593 | $0.7344 |
| **Total** | | | | | $8.9668 | $0.4125 | **$9.3793** |

*Note: estimates use input/output token counts from the logs; cache-read/cache-write tokens are not logged and are therefore not reflected in these figures.*

## 5. Tool usage

| Tool | Calls | Total | Avg | Max | ok | err |
|---|---|---|---|---|---|---|
| shell | 274 | 7m 48s | 1.7 s | 52.1 s | 273 | 1 |
| edit | 67 | 977 ms | 14 ms | 36 ms | 65 | 2 |
| read | 20 | 28 ms | 1 ms | 28 ms | 20 | 0 |
| grep | 11 | 98 ms | 8 ms | 35 ms | 11 | 0 |
| web_fetch | 5 | 4.0 s | 806 ms | 1.4 s | 4 | 1 |
| write | 5 | 78 ms | 15 ms | 34 ms | 4 | 1 |
| remember | 4 | 39 ms | 9 ms | 32 ms | 4 | 0 |
| list_dir | 2 | 0 ms | 0 ms | 0 ms | 2 | 0 |
| extract | 1 | 0 ms | 0 ms | 0 ms | 1 | 0 |
| glob | 1 | 184 ms | 184 ms | 184 ms | 1 | 0 |
| web_search | 1 | 1.4 s | 1.4 s | 1.4 s | 1 | 0 |

## 6. Wire / streaming

### Stop reasons

| Stop | Count |
|---|---|
| tool_use | 365 |
| end_turn | 18 |
| max_tokens | 11 |
| unspecified | 2 |

### HTTP status

| Status | Count |
|---|---|
| 200 | 1188 |

### Hosts

| Host | Count |
|---|---|
| ollama.com | 396 |

### Providers

| Provider | Count |
|---|---|
| https://ollama.com/v1#main | 3 |

## 6b. Failures & retries

| Signal | Count |
|---|---|
| Retried turns (dispatch retry>0) | 0 |
| HTTP error turns | 0 |
| stream.retry attempts | 0 |
| Connection failures (http.local_failed) | 4 |

**Samples:**

```
2026-09-10T08:03:37.929 conn_fail localhost:11434
2026-09-10T08:03:37.929 conn_fail localhost:9931
2026-09-10T08:09:45.591 conn_fail localhost:11434
2026-09-10T08:09:45.591 conn_fail localhost:9931
```

## 7. Turn-by-turn detail

| # | Model | Complexity | Stop | Retry | Prompt | Completion | Cost | Chunks | Bytes | Duration |
|---|---|---|---|---|---|---|---|---|---|---|
| 1 | kimi-k3 | complex | tool_use | 0 | 13.8k | 154 | $0.0289 | 16 | 6.5 KiB | 3.9 s |
| 2 | kimi-k3 | complex | tool_use | 0 | 22.1k | 173 | $0.0455 | 21 | 7.4 KiB | 4.3 s |
| 3 | kimi-k3 | complex | tool_use | 0 | 25.5k | 108 | $0.0518 | 15 | 6.8 KiB | 2.5 s |
| 4 | kimi-k3 | complex | end_turn | 0 | 26.7k | 1.0k | $0.0618 | 573 | 208.6 KiB | 14.6 s |
| 5 | kimi-k3 | complex | tool_use | 0 | 27.8k | 186 | $0.0572 | 55 | 19.6 KiB | 3.8 s |
| 6 | kimi-k3 | complex | tool_use | 0 | 28.4k | 376 | $0.0599 | 4 | 2.1 KiB | 5.6 s |
| 7 | kimi-k3 | complex | tool_use | 0 | 29.3k | 459 | $0.0622 | 19 | 8.5 KiB | 6.6 s |
| 8 | kimi-k3 | complex | tool_use | 0 | 30.2k | 501 | $0.0643 | 4 | 2.5 KiB | 6.8 s |
| 9 | kimi-k3 | complex | tool_use | 0 | 39.7k | 117 | $0.0804 | 3 | 1.3 KiB | 2.5 s |
| 10 | kimi-k3 | complex | - | 0 | 32.7k | 834 | $0.0720 | 5 | 3.4 KiB | 0 ms |
| 11 | kimi-k3 | complex | tool_use | 0 | 30.9k | 817 | $0.0683 | 5 | 3.4 KiB | 9.9 s |
| 12 | kimi-k3 | complex | tool_use | 0 | 31.7k | 72 | $0.0640 | 3 | 1.1 KiB | 2.3 s |
| 13 | kimi-k3 | complex | tool_use | 0 | 31.4k | 93 | $0.0634 | 3 | 1.2 KiB | 3.1 s |
| 14 | kimi-k3 | complex | end_turn | 0 | 32.4k | 921 | $0.0721 | 520 | 183.4 KiB | 13.8 s |
| 15 | glm-5.3 | standard | tool_use | 0 | 33.8k | 657 | $0.0144 | 51 | 46.3 KiB | 9.2 s |
| 16 | glm-5.3 | standard | tool_use | 0 | 33.9k | 84 | $0.0137 | 3 | 1.6 KiB | 2.4 s |
| 17 | glm-5.3 | standard | - | 0 | 25.6k | 28 | $0.0103 | 2 | 1.1 KiB | 0 ms |
| 18 | glm-5.3 | standard | tool_use | 0 | 25.7k | 58 | $0.0104 | 2 | 1.2 KiB | 2.1 s |
| 19 | glm-5.3 | standard | tool_use | 0 | 26.3k | 64 | $0.0106 | 2 | 1.2 KiB | 1.8 s |
| 20 | glm-5.3 | standard | tool_use | 0 | 27.1k | 77 | $0.0109 | 2 | 1.3 KiB | 2.2 s |
| 21 | glm-5.3 | standard | tool_use | 0 | 27.5k | 83 | $0.0111 | 2 | 1.3 KiB | 2.1 s |
| 22 | glm-5.3 | standard | tool_use | 0 | 27.7k | 40 | $0.0111 | 2 | 1.2 KiB | 1.8 s |
| 23 | glm-5.3 | standard | tool_use | 0 | 30.7k | 924 | $0.0136 | 89 | 69.9 KiB | 9.6 s |
| 24 | glm-5.3 | standard | - | 0 | 31.0k | 52 | $0.0125 | 2 | 1.1 KiB | 0 ms |
| 25 | glm-5.3 | standard | tool_use | 0 | 31.5k | 439 | $0.0132 | 55 | 34.9 KiB | 5.8 s |
| 26 | glm-5.3 | standard | - | 0 | 31.7k | 45 | $0.0128 | 3 | 1.1 KiB | 0 ms |
| 27 | glm-5.3 | standard | tool_use | 0 | 31.8k | 69 | $0.0128 | 2 | 1.3 KiB | 2.3 s |
| 28 | glm-5.3 | standard | tool_use | 0 | 32.3k | 1.6k | $0.0152 | 177 | 124.8 KiB | 16.9 s |
| 29 | glm-5.3 | standard | tool_use | 0 | 32.8k | 60 | $0.0132 | 2 | 1.2 KiB | 2.0 s |
| 30 | glm-5.3 | standard | tool_use | 0 | 31.1k | 86 | $0.0126 | 2 | 1.3 KiB | 2.3 s |
| 31 | glm-5.3 | standard | tool_use | 0 | 31.6k | 67 | $0.0127 | 2 | 1.2 KiB | 2.4 s |
| 32 | glm-5.3 | standard | tool_use | 0 | 31.8k | 41 | $0.0128 | 3 | 1.1 KiB | 2.0 s |
| 33 | glm-5.3 | standard | tool_use | 0 | 32.8k | 44 | $0.0132 | 2 | 1.2 KiB | 2.2 s |
| 34 | glm-5.3 | standard | tool_use | 0 | 33.0k | 47 | $0.0133 | 2 | 1.2 KiB | 2.4 s |
| 35 | glm-5.3 | standard | tool_use | 0 | 33.2k | 45 | $0.0133 | 2 | 1.2 KiB | 2.3 s |
| 36 | glm-5.3 | standard | tool_use | 0 | 33.4k | 72 | $0.0135 | 2 | 1.3 KiB | 2.2 s |
| 37 | glm-5.3 | standard | tool_use | 0 | 33.5k | 68 | $0.0135 | 2 | 1.3 KiB | 2.1 s |
| 38 | glm-5.3 | standard | tool_use | 0 | 33.5k | 83 | $0.0135 | 2 | 1.3 KiB | 3.3 s |
| 39 | glm-5.3 | standard | tool_use | 0 | 33.8k | 61 | $0.0136 | 2 | 1.2 KiB | 2.0 s |
| 40 | glm-5.3 | standard | tool_use | 0 | 34.4k | 76 | $0.0139 | 2 | 1.3 KiB | 2.0 s |
| 41 | glm-5.3 | standard | tool_use | 0 | 34.4k | 44 | $0.0138 | 2 | 1.1 KiB | 1.9 s |
| 42 | glm-5.3 | standard | tool_use | 0 | 34.7k | 1.0k | $0.0153 | 94 | 76.0 KiB | 10.2 s |
| 43 | glm-5.3 | standard | tool_use | 0 | 35.1k | 2.1k | $0.0171 | 220 | 176.8 KiB | 21.9 s |
| 44 | glm-5.3 | standard | tool_use | 0 | 35.9k | 72 | $0.0145 | 2 | 1.3 KiB | 3.2 s |
| 45 | glm-5.3 | standard | tool_use | 0 | 36.1k | 43 | $0.0145 | 2 | 1.1 KiB | 2.3 s |
| 46 | glm-5.3 | standard | tool_use | 0 | 36.3k | 465 | $0.0152 | 46 | 35.6 KiB | 6.1 s |
| 47 | glm-5.3 | standard | tool_use | 0 | 37.1k | 3.0k | $0.0190 | 439 | 256.6 KiB | 33.4 s |
| 48 | glm-5.3 | standard | tool_use | 0 | 37.8k | 90 | $0.0152 | 2 | 1.3 KiB | 2.6 s |
| 49 | glm-5.3 | standard | tool_use | 0 | 38.2k | 72 | $0.0154 | 2 | 1.2 KiB | 2.0 s |
| 50 | glm-5.3 | standard | - | 0 | 38.5k | 1.2k | $0.0171 | 153 | 98.4 KiB | 0 ms |
| 51 | glm-5.3 | standard | tool_use | 0 | 39.8k | 52 | $0.0160 | 3 | 1.2 KiB | 2.4 s |
| 52 | glm-5.3 | standard | tool_use | 0 | 40.1k | 42 | $0.0161 | 2 | 1.2 KiB | 1.7 s |
| 53 | glm-5.3 | standard | tool_use | 0 | 40.4k | 3.9k | $0.0216 | 425 | 319.8 KiB | 41.0 s |
| 54 | glm-5.3 | standard | tool_use | 0 | 41.6k | 1.2k | $0.0183 | 149 | 87.5 KiB | 12.2 s |
| 55 | glm-5.3 | standard | tool_use | 0 | 42.0k | 1.7k | $0.0191 | 147 | 130.8 KiB | 17.3 s |
| 56 | glm-5.3 | standard | tool_use | 0 | 42.9k | 2.1k | $0.0201 | 208 | 161.4 KiB | 21.3 s |
| 57 | glm-5.3 | standard | tool_use | 0 | 43.3k | 2.0k | $0.0201 | 197 | 150.3 KiB | 19.8 s |
| 58 | glm-5.3 | standard | tool_use | 0 | 44.0k | 39 | $0.0176 | 2 | 1.1 KiB | 2.0 s |
| 59 | glm-5.3 | standard | tool_use | 0 | 44.0k | 4.6k | $0.0240 | 436 | 358.7 KiB | 48.8 s |
| 60 | glm-5.3 | standard | tool_use | 0 | 44.7k | 66 | $0.0180 | 2 | 1.3 KiB | 18.5 s |
| 61 | glm-5.3 | standard | tool_use | 0 | 44.8k | 63 | $0.0180 | 3 | 1.3 KiB | 2.3 s |
| 62 | glm-5.3 | standard | tool_use | 0 | 44.4k | 54 | $0.0178 | 2 | 1.2 KiB | 2.2 s |
| 63 | glm-5.3 | standard | - | 0 | 44.7k | 62 | $0.0180 | 2 | 1.2 KiB | 0 ms |
| 64 | glm-5.3 | standard | tool_use | 0 | 44.5k | 70 | $0.0179 | 2 | 1.3 KiB | 2.5 s |
| 65 | glm-5.3 | standard | tool_use | 0 | 44.9k | 1.4k | $0.0199 | 162 | 113.8 KiB | 17.4 s |
| 66 | glm-5.3 | standard | tool_use | 0 | 45.0k | 87 | $0.0181 | 2 | 1.3 KiB | 2.5 s |
| 67 | glm-5.3 | standard | tool_use | 0 | 45.2k | 84 | $0.0182 | 2 | 1.3 KiB | 2.4 s |
| 68 | glm-5.3 | standard | tool_use | 0 | 45.3k | 49 | $0.0182 | 2 | 1.2 KiB | 2.9 s |
| 69 | glm-5.3 | standard | tool_use | 0 | 45.5k | 305 | $0.0186 | 24 | 19.2 KiB | 4.0 s |
| 70 | glm-5.3 | standard | tool_use | 0 | 45.9k | 250 | $0.0187 | 19 | 15.0 KiB | 5.7 s |
| 71 | glm-5.3 | standard | tool_use | 0 | 46.0k | 67 | $0.0185 | 2 | 1.3 KiB | 2.6 s |
| 72 | glm-5.3 | standard | tool_use | 0 | 46.1k | 65 | $0.0185 | 2 | 1.2 KiB | 2.9 s |
| 73 | glm-5.3 | standard | tool_use | 0 | 46.2k | 70 | $0.0186 | 2 | 1.3 KiB | 2.5 s |
| 74 | glm-5.3 | standard | tool_use | 0 | 46.4k | 221 | $0.0189 | 26 | 15.7 KiB | 3.8 s |
| 75 | glm-5.3 | standard | tool_use | 0 | 46.9k | 4.4k | $0.0250 | 410 | 356.0 KiB | 46.4 s |
| 76 | glm-5.3 | standard | tool_use | 0 | 47.0k | 64 | $0.0189 | 2 | 1.2 KiB | 2.3 s |
| 77 | glm-5.3 | standard | tool_use | 0 | 47.1k | 43 | $0.0189 | 2 | 1.1 KiB | 2.3 s |
| 78 | glm-5.3 | standard | tool_use | 0 | 47.6k | 408 | $0.0196 | 7 | 4.7 KiB | 4.2 s |
| 79 | glm-5.3 | standard | tool_use | 0 | 48.4k | 360 | $0.0199 | 3 | 2.4 KiB | 3.9 s |
| 80 | glm-5.3 | standard | tool_use | 0 | 49.0k | 572 | $0.0204 | 7 | 5.0 KiB | 5.2 s |
| 81 | glm-5.3 | standard | tool_use | 0 | 50.1k | 428 | $0.0206 | 5 | 3.3 KiB | 5.9 s |
| 82 | glm-5.3 | standard | tool_use | 0 | 51.0k | 215 | $0.0207 | 8 | 4.4 KiB | 3.2 s |
| 83 | glm-5.3 | standard | tool_use | 0 | 51.4k | 173 | $0.0208 | 2 | 1.5 KiB | 3.3 s |
| 84 | glm-5.3 | standard | tool_use | 0 | 51.8k | 176 | $0.0210 | 2 | 1.5 KiB | 3.0 s |
| 85 | glm-5.3 | standard | tool_use | 0 | 52.2k | 134 | $0.0211 | 7 | 3.6 KiB | 3.3 s |
| 86 | glm-5.3 | standard | tool_use | 0 | 52.5k | 85 | $0.0211 | 8 | 4.3 KiB | 2.8 s |
| 87 | glm-5.3 | standard | tool_use | 0 | 52.8k | 166 | $0.0214 | 2 | 1.5 KiB | 3.2 s |
| 88 | glm-5.3 | standard | - | 0 | 53.2k | 431 | $0.0219 | 8 | 5.1 KiB | 0 ms |
| 89 | glm-5.3 | standard | tool_use | 0 | 53.8k | 71 | $0.0216 | 2 | 1.3 KiB | 2.6 s |
| 90 | glm-5.3 | standard | tool_use | 0 | 54.1k | 441 | $0.0222 | 3 | 2.4 KiB | 3.7 s |
| 91 | glm-5.3 | standard | tool_use | 0 | 54.8k | 73 | $0.0220 | 6 | 3.9 KiB | 2.4 s |
| 92 | glm-5.3 | standard | tool_use | 0 | 55.3k | 970 | $0.0235 | 5 | 4.6 KiB | 7.7 s |
| 93 | glm-5.3 | standard | tool_use | 0 | 57.1k | 44 | $0.0229 | 2 | 1.2 KiB | 2.0 s |
| 94 | glm-5.3 | standard | tool_use | 0 | 57.1k | 31 | $0.0229 | 2 | 1.1 KiB | 2.1 s |
| 95 | glm-5.3 | standard | tool_use | 0 | 57.2k | 264 | $0.0232 | 6 | 4.0 KiB | 3.2 s |
| 96 | glm-5.3 | standard | tool_use | 0 | 57.7k | 39 | $0.0231 | 2 | 1.2 KiB | 2.1 s |
| 97 | glm-5.3 | standard | - | 0 | 57.9k | 69 | $0.0232 | 2 | 1.2 KiB | 0 ms |
| 98 | glm-5.3 | standard | tool_use | 0 | 58.0k | 92 | $0.0233 | 2 | 1.3 KiB | 2.4 s |
| 99 | glm-5.3 | standard | tool_use | 0 | 58.1k | 52 | $0.0233 | 2 | 1.2 KiB | 2.3 s |
| 100 | glm-5.3 | standard | tool_use | 0 | 58.4k | 61 | $0.0234 | 2 | 1.2 KiB | 2.2 s |
| 101 | glm-5.3 | standard | tool_use | 0 | 58.3k | 99 | $0.0235 | 2 | 1.4 KiB | 2.5 s |
| 102 | glm-5.3 | standard | tool_use | 0 | 58.5k | 54 | $0.0235 | 2 | 1.2 KiB | 2.4 s |
| 103 | glm-5.3 | standard | tool_use | 0 | 58.6k | 76 | $0.0236 | 2 | 1.2 KiB | 2.4 s |
| 104 | glm-5.3 | standard | tool_use | 0 | 58.7k | 72 | $0.0236 | 3 | 1.2 KiB | 2.4 s |
| 105 | glm-5.3 | standard | tool_use | 0 | 58.8k | 571 | $0.0243 | 50 | 46.2 KiB | 8.0 s |
| 106 | glm-5.3 | standard | tool_use | 0 | 59.0k | 57 | $0.0237 | 2 | 1.2 KiB | 2.4 s |
| 107 | glm-5.3 | standard | tool_use | 0 | 59.1k | 70 | $0.0237 | 2 | 1.3 KiB | 2.8 s |
| 108 | glm-5.3 | standard | tool_use | 0 | 59.4k | 76 | $0.0239 | 2 | 1.3 KiB | 2.9 s |
| 109 | glm-5.3 | standard | tool_use | 0 | 59.6k | 61 | $0.0239 | 2 | 1.2 KiB | 3.2 s |
| 110 | glm-5.3 | standard | tool_use | 0 | 60.4k | 317 | $0.0246 | 24 | 18.9 KiB | 4.4 s |
| 111 | glm-5.3 | standard | tool_use | 0 | 60.6k | 40 | $0.0243 | 2 | 1.2 KiB | 2.0 s |
| 112 | glm-5.3 | standard | tool_use | 0 | 60.7k | 612 | $0.0252 | 59 | 37.9 KiB | 7.9 s |
| 113 | glm-5.3 | standard | tool_use | 0 | 61.5k | 89 | $0.0247 | 2 | 1.3 KiB | 2.4 s |
| 114 | glm-5.3 | standard | tool_use | 0 | 61.7k | 174 | $0.0249 | 3 | 1.6 KiB | 3.6 s |
| 115 | glm-5.3 | standard | tool_use | 0 | 62.1k | 71 | $0.0249 | 2 | 1.3 KiB | 2.3 s |
| 116 | glm-5.3 | standard | tool_use | 0 | 62.2k | 174 | $0.0251 | 3 | 1.7 KiB | 3.0 s |
| 117 | glm-5.3 | standard | tool_use | 0 | 62.7k | 100 | $0.0252 | 6 | 4.9 KiB | 2.4 s |
| 118 | glm-5.3 | standard | tool_use | 0 | 62.6k | 91 | $0.0252 | 2 | 1.4 KiB | 2.6 s |
| 119 | glm-5.3 | standard | tool_use | 0 | 62.8k | 363 | $0.0256 | 29 | 21.3 KiB | 5.4 s |
| 120 | glm-5.3 | standard | tool_use | 0 | 63.0k | 63 | $0.0253 | 2 | 1.3 KiB | 2.4 s |
| 121 | glm-5.3 | standard | tool_use | 0 | 63.3k | 51 | $0.0254 | 2 | 1.2 KiB | 2.8 s |
| 122 | glm-5.3 | standard | tool_use | 0 | 63.4k | 72 | $0.0255 | 2 | 1.3 KiB | 2.6 s |
| 123 | glm-5.3 | standard | tool_use | 0 | 63.5k | 65 | $0.0255 | 2 | 1.3 KiB | 2.2 s |
| 124 | glm-5.3 | standard | tool_use | 0 | 64.1k | 108 | $0.0258 | 2 | 1.4 KiB | 2.6 s |
| 125 | glm-5.3 | standard | tool_use | 0 | 64.2k | 95 | $0.0258 | 2 | 1.4 KiB | 2.6 s |
| 126 | glm-5.3 | standard | tool_use | 0 | 64.4k | 95 | $0.0259 | 2 | 1.4 KiB | 2.5 s |
| 127 | glm-5.3 | standard | tool_use | 0 | 64.6k | 102 | $0.0260 | 7 | 3.2 KiB | 2.6 s |
| 128 | glm-5.3 | standard | tool_use | 0 | 64.8k | 75 | $0.0260 | 2 | 1.3 KiB | 2.6 s |
| 129 | glm-5.3 | standard | tool_use | 0 | 65.0k | 59 | $0.0261 | 2 | 1.2 KiB | 2.2 s |
| 130 | glm-5.3 | standard | tool_use | 0 | 65.2k | 852 | $0.0273 | 79 | 63.8 KiB | 10.0 s |
| 131 | glm-5.3 | standard | tool_use | 0 | 65.4k | 59 | $0.0263 | 2 | 1.2 KiB | 2.6 s |
| 132 | glm-5.3 | standard | tool_use | 0 | 65.6k | 297 | $0.0266 | 27 | 19.0 KiB | 4.6 s |
| 133 | glm-5.3 | standard | tool_use | 0 | 65.7k | 70 | $0.0264 | 2 | 1.3 KiB | 2.2 s |
| 134 | glm-5.3 | standard | tool_use | 0 | 65.8k | 78 | $0.0264 | 2 | 1.3 KiB | 2.4 s |
| 135 | glm-5.3 | standard | tool_use | 0 | 65.9k | 55 | $0.0264 | 2 | 1.2 KiB | 2.6 s |
| 136 | glm-5.3 | standard | tool_use | 0 | 66.1k | 56 | $0.0265 | 2 | 1.2 KiB | 2.0 s |
| 137 | glm-5.3 | standard | tool_use | 0 | 67.1k | 146 | $0.0271 | 17 | 8.5 KiB | 3.5 s |
| 138 | glm-5.3 | standard | tool_use | 0 | 67.4k | 217 | $0.0273 | 3 | 1.9 KiB | 3.6 s |
| 139 | glm-5.3 | standard | tool_use | 0 | 67.7k | 94 | $0.0272 | 2 | 1.4 KiB | 2.9 s |
| 140 | glm-5.3 | standard | end_turn | 0 | 68.0k | 522 | $0.0279 | 70 | 35.7 KiB | 8.5 s |
| 141 | glm-5.3-flash | simple | tool_use | 0 | 68.5k | 3.4k | $0.004785 | 1391 | 320.5 KiB | 58.4 s |
| 142 | glm-5.3-flash | trivial | tool_use | 0 | 68.8k | 1.2k | $0.004361 | 455 | 104.8 KiB | 30.5 s |
| 143 | glm-5.3-flash | trivial | tool_use | 0 | 69.1k | 1.8k | $0.004500 | 8 | 8.6 KiB | 19.5 s |
| 144 | glm-5.3-flash | trivial | tool_use | 0 | 70.9k | 60 | $0.004264 | 2 | 1.2 KiB | 2.5 s |
| 145 | glm-5.3-flash | trivial | tool_use | 0 | 71.0k | 63 | $0.004270 | 2 | 1.3 KiB | 1.9 s |
| 146 | glm-5.3-flash | trivial | tool_use | 0 | 70.7k | 89 | $0.004258 | 2 | 1.3 KiB | 3.0 s |
| 147 | glm-5.3-flash | trivial | tool_use | 0 | 44.9k | 2.3k | $0.003145 | 840 | 191.9 KiB | 152m 19s |
| 148 | glm-5.3-flash | trivial | tool_use | 0 | 71.0k | 115 | $0.004283 | 2 | 1.5 KiB | 2.4 s |
| 149 | glm-5.3-flash | trivial | tool_use | 0 | 71.4k | 286 | $0.004342 | 37 | 9.6 KiB | 4.4 s |
| 150 | glm-5.3-flash | trivial | tool_use | 0 | 71.8k | 65 | $0.004321 | 2 | 1.2 KiB | 2.4 s |
| 151 | glm-5.3-flash | trivial | tool_use | 0 | 71.9k | 55 | $0.004325 | 2 | 1.2 KiB | 2.1 s |
| 152 | glm-5.3-flash | trivial | tool_use | 0 | 72.0k | 97 | $0.004337 | 2 | 1.4 KiB | 1.9 s |
| 153 | glm-5.3-flash | trivial | tool_use | 0 | 72.1k | 149 | $0.004355 | 2 | 1.6 KiB | 2.6 s |
| 154 | glm-5.3-flash | trivial | tool_use | 0 | 72.7k | 422 | $0.004445 | 122 | 28.9 KiB | 6.5 s |
| 155 | glm-5.3-flash | trivial | tool_use | 0 | 73.0k | 65 | $0.004391 | 3 | 1.2 KiB | 2.9 s |
| 156 | glm-5.3-flash | trivial | tool_use | 0 | 73.2k | 2.4k | $0.004863 | 613 | 142.5 KiB | 31.2 s |
| 157 | glm-5.3-flash | trivial | tool_use | 0 | 74.9k | 51 | $0.004503 | 2 | 1.2 KiB | 2.2 s |
| 158 | glm-5.3-flash | trivial | tool_use | 0 | 75.2k | 708 | $0.004654 | 255 | 59.2 KiB | 16.3 s |
| 159 | glm-5.3-flash | trivial | tool_use | 0 | 75.4k | 180 | $0.004561 | 3 | 1.7 KiB | 3.2 s |
| 160 | glm-5.3-flash | trivial | tool_use | 0 | 75.6k | 307 | $0.004599 | 4 | 2.2 KiB | 3.8 s |
| 161 | glm-5.3-flash | trivial | tool_use | 0 | 78.0k | 487 | $0.004777 | 95 | 22.9 KiB | 7.5 s |
| 162 | glm-5.3-flash | trivial | tool_use | 0 | 78.7k | 52 | $0.004730 | 2 | 1.2 KiB | 6.5 s |
| 163 | glm-5.3-flash | trivial | tool_use | 0 | 78.8k | 55 | $0.004737 | 3 | 1.2 KiB | 2.3 s |
| 164 | glm-5.3-flash | trivial | tool_use | 0 | 79.0k | 485 | $0.004840 | 127 | 29.9 KiB | 9.0 s |
| 165 | glm-5.3-flash | trivial | tool_use | 0 | 79.2k | 242 | $0.004800 | 4 | 1.7 KiB | 4.4 s |
| 166 | glm-5.3-flash | trivial | tool_use | 0 | 79.7k | 126 | $0.004805 | 2 | 1.4 KiB | 3.3 s |
| 167 | glm-5.3-flash | trivial | tool_use | 0 | 79.9k | 1.6k | $0.005114 | 228 | 55.7 KiB | 18.0 s |
| 168 | glm-5.3-flash | trivial | tool_use | 0 | 81.8k | 66 | $0.004919 | 2 | 1.3 KiB | 2.1 s |
| 169 | glm-5.3-flash | trivial | tool_use | 0 | 80.6k | 133 | $0.004863 | 3 | 1.5 KiB | 3.3 s |
| 170 | glm-5.3-flash | trivial | tool_use | 0 | 81.1k | 133 | $0.004891 | 15 | 4.4 KiB | 2.9 s |
| 171 | glm-5.3-flash | trivial | tool_use | 0 | 81.3k | 286 | $0.004934 | 3 | 2.1 KiB | 4.8 s |
| 172 | glm-5.3-flash | trivial | tool_use | 0 | 81.6k | 156 | $0.004929 | 3 | 1.7 KiB | 6.1 s |
| 173 | glm-5.3-flash | trivial | tool_use | 0 | 81.8k | 350 | $0.004979 | 46 | 11.8 KiB | 7.1 s |
| 174 | glm-5.3-flash | trivial | tool_use | 0 | 82.2k | 115 | $0.004954 | 2 | 1.5 KiB | 2.5 s |
| 175 | glm-5.3-flash | trivial | tool_use | 0 | 82.4k | 146 | $0.004972 | 3 | 1.5 KiB | 3.3 s |
| 176 | glm-5.3-flash | trivial | end_turn | 0 | 82.4k | 611 | $0.005065 | 212 | 45.8 KiB | 11.4 s |
| 177 | glm-5.3-flash | trivial | tool_use | 0 | 83.0k | 8.6k | $0.006697 | 2586 | 596.0 KiB | 1m 50s |
| 178 | glm-5.3-flash | trivial | tool_use | 0 | 86.5k | 105 | $0.005212 | 2 | 1.4 KiB | 2.8 s |
| 179 | glm-5.3-flash | trivial | tool_use | 0 | 86.7k | 295 | $0.005263 | 4 | 2.0 KiB | 4.1 s |
| 180 | glm-5.3-flash | trivial | tool_use | 0 | 87.7k | 891 | $0.005442 | 373 | 85.3 KiB | 15.3 s |
| 181 | glm-5.3-flash | trivial | tool_use | 0 | 88.1k | 311 | $0.005347 | 3 | 1.9 KiB | 3.8 s |
| 182 | glm-5.3-flash | trivial | tool_use | 0 | 88.8k | 100 | $0.005345 | 2 | 1.4 KiB | 2.6 s |
| 183 | glm-5.3-flash | trivial | tool_use | 0 | 89.1k | 105 | $0.005365 | 2 | 1.4 KiB | 2.4 s |
| 184 | glm-5.3-flash | trivial | tool_use | 0 | 89.3k | 221 | $0.005400 | 3 | 1.8 KiB | 2.9 s |
| 185 | glm-5.3-flash | trivial | tool_use | 0 | 90.2k | 476 | $0.005508 | 90 | 22.0 KiB | 6.0 s |
| 186 | glm-5.3-flash | trivial | - | 0 | 90.0k | 1.1k | $0.005623 | 152 | 36.9 KiB | 0 ms |
| 187 | glm-5.3-flash | trivial | tool_use | 0 | 90.9k | 426 | $0.005539 | 3 | 2.3 KiB | 2 ms |
| 188 | glm-5.3-flash | trivial | tool_use | 0 | 91.5k | 47 | $0.005499 | 2 | 1.2 KiB | 2 ms |
| 189 | glm-5.3-flash | trivial | tool_use | 0 | 91.7k | 529 | $0.005610 | 4 | 2.7 KiB | 4.9 s |
| 190 | glm-5.3-flash | trivial | tool_use | 0 | 92.6k | 131 | $0.005585 | 2 | 1.5 KiB | 2.5 s |
| 191 | glm-5.3-flash | trivial | tool_use | 0 | 92.8k | 79 | $0.005585 | 2 | 1.3 KiB | 2.4 s |
| 192 | glm-5.3-flash | trivial | tool_use | 0 | 92.9k | 40 | $0.005582 | 2 | 1.1 KiB | 2.1 s |
| 193 | glm-5.3-flash | trivial | tool_use | 0 | 93.3k | 61 | $0.005610 | 2 | 1.2 KiB | 2.1 s |
| 194 | glm-5.3-flash | trivial | tool_use | 0 | 93.5k | 417 | $0.005695 | 3 | 2.4 KiB | 4.7 s |
| 195 | glm-5.3-flash | trivial | tool_use | 0 | 95.1k | 525 | $0.005810 | 191 | 44.3 KiB | 9.3 s |
| 196 | glm-5.3-flash | trivial | tool_use | 0 | 95.5k | 99 | $0.005749 | 2 | 1.4 KiB | 2.8 s |
| 197 | glm-5.3-flash | trivial | tool_use | 0 | 95.6k | 256 | $0.005789 | 3 | 2.1 KiB | 4.8 s |
| 198 | glm-5.3-flash | trivial | - | 0 | 96.0k | 161 | $0.005793 | 3 | 1.6 KiB | 0 ms |
| 199 | glm-5.3-flash | trivial | end_turn | 0 | 96.2k | 587 | $0.005889 | 179 | 39.9 KiB | 10.8 s |
| 200 | kimi-k3 | complex | tool_use | 0 | 109.2k | 207 | $0.2201 | 3 | 1.6 KiB | 10.3 s |
| 201 | kimi-k3 | complex | tool_use | 0 | 109.7k | 140 | $0.2205 | 3 | 1.3 KiB | 4.0 s |
| 202 | kimi-k3 | complex | tool_use | 0 | 110.0k | 198 | $0.2216 | 3 | 1.5 KiB | 4.5 s |
| 203 | kimi-k3 | complex | tool_use | 0 | 110.4k | 1.2k | $0.2301 | 6 | 5.9 KiB | 19.0 s |
| 204 | kimi-k3 | complex | tool_use | 0 | 111.0k | 107 | $0.2229 | 3 | 1.2 KiB | 3.6 s |
| 205 | kimi-k3 | complex | - | 0 | 111.2k | 366 | $0.2253 | 211 | 71.8 KiB | 0 ms |
| 206 | glm-5.3-flash | complex | end_turn | 0 | 87.5k | 2.3k | $0.005703 | 685 | 152.0 KiB | 28.0 s |
| 207 | kimi-k3 | complex | tool_use | 0 | 14.0k | 206 | $0.0296 | 13 | 6.0 KiB | 3.2 s |
| 208 | kimi-k3 | complex | tool_use | 0 | 15.4k | 122 | $0.0319 | 3 | 1.3 KiB | 2.2 s |
| 209 | kimi-k3 | complex | tool_use | 0 | 22.8k | 137 | $0.0468 | 38 | 14.5 KiB | 3.2 s |
| 210 | kimi-k3 | complex | end_turn | 0 | 28.7k | 1.8k | $0.0716 | 1030 | 356.6 KiB | 21.3 s |
| 211 | kimi-k3 | complex | unspecified | 0 | 0 | 0 | $0.0000 | 8627 | 3.37 MiB | 3m 20s |
| 212 | glm-5.3 | standard | max_tokens | 0 | 31.5k | 16.4k | $0.0356 | 8440 | 3.26 MiB | 2m 34s |
| 213 | glm-5.3-flash | simple | max_tokens | 0 | 31.6k | 16.4k | $0.005171 | 4951 | 1.13 MiB | 3m 10s |
| 214 | glm-5.3-flash | simple | max_tokens | 0 | 31.6k | 16.4k | $0.005172 | 4878 | 1.11 MiB | 3m 3s |
| 215 | glm-5.3-flash | simple | max_tokens | 0 | 31.6k | 16.4k | $0.005173 | 4839 | 1.10 MiB | 3m 7s |
| 216 | glm-5.3-flash | simple | tool_use | 0 | 31.6k | 476 | $0.001993 | 122 | 29.1 KiB | 6.9 s |
| 217 | glm-5.3-flash | simple | max_tokens | 0 | 31.7k | 16.4k | $0.005181 | 4615 | 1.05 MiB | 2m 46s |
| 218 | glm-5.3-flash | simple | max_tokens | 0 | 31.7k | 16.4k | $0.005182 | 4880 | 1.10 MiB | 3m 0s |
| 219 | glm-5.3-flash | simple | tool_use | 0 | 31.8k | 130 | $0.001932 | 2 | 1.4 KiB | 5.8 s |
| 220 | glm-5.3-flash | simple | max_tokens | 0 | 31.9k | 16.4k | $0.005192 | 5243 | 1.18 MiB | 3m 27s |
| 221 | glm-5.3-flash | simple | max_tokens | 0 | 31.9k | 16.4k | $0.005193 | 4978 | 1.13 MiB | 2m 59s |
| 222 | glm-5.3-flash | simple | tool_use | 0 | 31.9k | 117 | $0.001940 | 14 | 4.1 KiB | 6.4 s |
| 223 | glm-5.3-flash | simple | max_tokens | 0 | 31.5k | 16.4k | $0.005169 | 4799 | 1.09 MiB | 3m 9s |
| 224 | glm-5.3-flash | simple | max_tokens | 0 | 31.6k | 16.4k | $0.005170 | 5174 | 1.17 MiB | 3m 15s |
| 225 | kimi-k3 | complex | tool_use | 0 | 13.8k | 123 | $0.0285 | 7 | 2.3 KiB | 5.4 s |
| 226 | kimi-k3 | complex | tool_use | 0 | 14.5k | 582 | $0.0336 | 251 | 97.4 KiB | 8.9 s |
| 227 | kimi-k3 | complex | tool_use | 0 | 14.9k | 124 | $0.0308 | 8 | 3.0 KiB | 2.7 s |
| 228 | kimi-k3 | complex | tool_use | 0 | 15.2k | 137 | $0.0316 | 3 | 1.3 KiB | 3.3 s |
| 229 | kimi-k3 | complex | tool_use | 0 | 15.4k | 191 | $0.0324 | 21 | 8.8 KiB | 3.3 s |
| 230 | kimi-k3 | complex | - | 0 | 16.2k | 167 | $0.0337 | 30 | 13.0 KiB | 0 ms |
| 231 | kimi-k3 | complex | tool_use | 0 | 16.4k | 82 | $0.0335 | 3 | 1.1 KiB | 1.8 s |
| 232 | kimi-k3 | complex | tool_use | 0 | 16.5k | 159 | $0.0344 | 12 | 5.4 KiB | 3.3 s |
| 233 | kimi-k3 | complex | tool_use | 0 | 17.5k | 136 | $0.0361 | 3 | 1.3 KiB | 2.3 s |
| 234 | kimi-k3 | complex | tool_use | 0 | 17.7k | 208 | $0.0371 | 21 | 8.9 KiB | 3.4 s |
| 235 | kimi-k3 | complex | tool_use | 0 | 18.3k | 275 | $0.0388 | 67 | 26.7 KiB | 3.6 s |
| 236 | kimi-k3 | complex | tool_use | 0 | 18.6k | 232 | $0.0392 | 13 | 5.4 KiB | 3.0 s |
| 237 | glm-5.3-flash | simple | max_tokens | 0 | 31.6k | 16.4k | $0.005171 | 5024 | 1.14 MiB | 3m 14s |
| 238 | kimi-k3 | complex | - | 0 | 19.0k | 984 | $0.0459 | 169 | 60.4 KiB | 0 ms |
| 239 | kimi-k3 | complex | tool_use | 0 | 20.0k | 189 | $0.0416 | 3 | 1.5 KiB | 2.9 s |
| 240 | kimi-k3 | complex | end_turn | 0 | 21.4k | 416 | $0.0462 | 219 | 81.3 KiB | 7.1 s |
| 241 | glm-5.3 | standard | tool_use | 0 | 22.2k | 332 | $0.009352 | 128 | 49.3 KiB | 4.0 s |
| 242 | glm-5.3-flash | simple | tool_use | 0 | 23.6k | 380 | $0.001493 | 3 | 2.2 KiB | 5.4 s |
| 243 | glm-5.3-flash | simple | tool_use | 0 | 24.3k | 209 | $0.001502 | 3 | 1.9 KiB | 5.4 s |
| 244 | glm-5.3-flash | simple | tool_use | 0 | 24.8k | 187 | $0.001523 | 3 | 1.7 KiB | 3.1 s |
| 245 | glm-5.3-flash | simple | tool_use | 0 | 25.0k | 196 | $0.001540 | 3 | 1.7 KiB | 4.0 s |
| 246 | glm-5.3-flash | simple | tool_use | 0 | 25.3k | 247 | $0.001568 | 3 | 1.8 KiB | 3.2 s |
| 247 | glm-5.3-flash | simple | tool_use | 0 | 25.8k | 109 | $0.001568 | 2 | 1.4 KiB | 2.8 s |
| 248 | glm-5.3-flash | simple | tool_use | 0 | 26.0k | 126 | $0.001585 | 2 | 1.5 KiB | 2.1 s |
| 249 | glm-5.3-flash | simple | end_turn | 0 | 25.7k | 304 | $0.001602 | 109 | 24.4 KiB | 8.5 s |
| 250 | glm-5.3-flash | simple | tool_use | 0 | 31.6k | 10.2k | $0.003941 | 2611 | 613.1 KiB | 1m 56s |
| 251 | glm-5.3-flash | simple | tool_use | 0 | 35.3k | 1.7k | $0.002453 | 59 | 19.3 KiB | 19.4 s |
| 252 | glm-5.3-flash | simple | tool_use | 0 | 38.4k | 1.3k | $0.002558 | 99 | 26.7 KiB | 14.1 s |
| 253 | glm-5.3-flash | simple | - | 0 | 33.6k | 872 | $0.002190 | 301 | 69.9 KiB | 0 ms |
| 254 | glm-5.3-flash | simple | tool_use | 0 | 29.0k | 122 | $0.001767 | 3 | 1.7 KiB | 6.3 s |
| 255 | glm-5.3-flash | simple | tool_use | 0 | 29.4k | 88 | $0.001780 | 3 | 1.3 KiB | 2.1 s |
| 256 | glm-5.3-flash | simple | tool_use | 0 | 29.8k | 91 | $0.001805 | 2 | 1.3 KiB | 2.6 s |
| 257 | glm-5.3-flash | simple | tool_use | 0 | 29.9k | 97 | $0.001816 | 24 | 6.1 KiB | 3.1 s |
| 258 | glm-5.3-flash | simple | tool_use | 0 | 30.1k | 4.9k | $0.002790 | 1146 | 271.1 KiB | 54.9 s |
| 259 | glm-5.3-flash | simple | tool_use | 0 | 32.3k | 973 | $0.002134 | 6 | 5.6 KiB | 14.9 s |
| 260 | glm-5.3-flash | simple | tool_use | 0 | 34.4k | 2.2k | $0.002502 | 10 | 10.8 KiB | 18.5 s |
| 261 | glm-5.3-flash | simple | tool_use | 0 | 37.0k | 1.7k | $0.002556 | 292 | 70.5 KiB | 20.4 s |
| 262 | glm-5.3-flash | simple | - | 0 | 38.3k | 173 | $0.002332 | 59 | 14.4 KiB | 0 ms |
| 263 | glm-5.3-flash | simple | tool_use | 0 | 40.1k | 626 | $0.002528 | 51 | 13.9 KiB | 6.5 s |
| 264 | glm-5.3-flash | simple | tool_use | 0 | 40.6k | 1.3k | $0.002691 | 173 | 42.7 KiB | 13.1 s |
| 265 | glm-5.3-flash | simple | tool_use | 0 | 41.6k | 461 | $0.002588 | 67 | 16.8 KiB | 6.6 s |
| 266 | glm-5.3-flash | simple | - | 0 | 41.6k | 323 | $0.002564 | 124 | 28.9 KiB | 0 ms |
| 267 | glm-5.3-flash | simple | tool_use | 0 | 42.7k | 309 | $0.002626 | 96 | 22.4 KiB | 5.7 s |
| 268 | glm-5.3-flash | simple | - | 0 | 42.7k | 512 | $0.002666 | 160 | 37.2 KiB | 0 ms |
| 269 | glm-5.3-flash | simple | tool_use | 0 | 42.5k | 66 | $0.002563 | 2 | 1.2 KiB | 2.3 s |
| 270 | glm-5.3-flash | simple | tool_use | 0 | 42.6k | 147 | $0.002584 | 2 | 1.5 KiB | 2.4 s |
| 271 | glm-5.3-flash | simple | tool_use | 0 | 43.0k | 166 | $0.002612 | 3 | 1.6 KiB | 3.8 s |
| 272 | glm-5.3-flash | simple | tool_use | 0 | 43.8k | 1.6k | $0.002937 | 329 | 77.3 KiB | 16.5 s |
| 273 | glm-5.3-flash | simple | - | 0 | 0 | 0 | $0.0000 | 29 | 6.6 KiB | 0 ms |
| 274 | glm-5.3-flash | simple | tool_use | 0 | 45.3k | 360 | $0.002790 | 3 | 2.6 KiB | 5.1 s |
| 275 | glm-5.3-flash | simple | tool_use | 0 | 45.8k | 1.1k | $0.002971 | 266 | 62.9 KiB | 14.5 s |
| 276 | glm-5.3-flash | simple | tool_use | 0 | 47.0k | 661 | $0.002951 | 61 | 16.2 KiB | 8.5 s |
| 277 | glm-5.3-flash | simple | tool_use | 0 | 47.7k | 2.5k | $0.003358 | 570 | 132.8 KiB | 30.0 s |
| 278 | glm-5.3-flash | simple | tool_use | 0 | 48.9k | 145 | $0.002961 | 3 | 1.5 KiB | 2.8 s |
| 279 | glm-5.3-flash | simple | tool_use | 0 | 49.5k | 120 | $0.002995 | 8 | 2.6 KiB | 2.7 s |
| 280 | glm-5.3-flash | simple | tool_use | 0 | 49.9k | 177 | $0.003027 | 3 | 1.6 KiB | 3.0 s |
| 281 | glm-5.3-flash | simple | tool_use | 0 | 50.7k | 826 | $0.003210 | 146 | 34.9 KiB | 9.0 s |
| 282 | glm-5.3-flash | simple | tool_use | 0 | 51.5k | 148 | $0.003120 | 2 | 1.5 KiB | 2.4 s |
| 283 | glm-5.3-flash | simple | tool_use | 0 | 51.9k | 556 | $0.003223 | 198 | 45.8 KiB | 10.2 s |
| 284 | glm-5.3-flash | simple | tool_use | 0 | 52.3k | 138 | $0.003168 | 2 | 1.5 KiB | 2.8 s |
| 285 | glm-5.3-flash | simple | tool_use | 0 | 52.9k | 303 | $0.003233 | 71 | 17.7 KiB | 7.6 s |
| 286 | glm-5.3-flash | simple | tool_use | 0 | 53.2k | 743 | $0.003340 | 62 | 16.8 KiB | 7.9 s |
| 287 | glm-5.3-flash | simple | tool_use | 0 | 53.8k | 125 | $0.003254 | 2 | 1.4 KiB | 15.3 s |
| 288 | glm-5.3-flash | simple | tool_use | 0 | 54.1k | 1.0k | $0.003453 | 398 | 91.7 KiB | 19.0 s |
| 289 | glm-5.3-flash | simple | tool_use | 0 | 54.6k | 630 | $0.003403 | 165 | 38.7 KiB | 11.5 s |
| 290 | glm-5.3-flash | simple | tool_use | 0 | 55.6k | 972 | $0.003529 | 332 | 76.0 KiB | 15.2 s |
| 291 | glm-5.3-flash | simple | tool_use | 0 | 55.9k | 108 | $0.003375 | 2 | 1.4 KiB | 2.1 s |
| 292 | glm-5.3-flash | simple | tool_use | 0 | 56.8k | 1.2k | $0.003642 | 351 | 80.7 KiB | 15.2 s |
| 293 | glm-5.3-flash | simple | tool_use | 0 | 57.5k | 102 | $0.003470 | 2 | 1.4 KiB | 2.3 s |
| 294 | glm-5.3-flash | simple | tool_use | 0 | 57.9k | 1.3k | $0.003736 | 353 | 83.0 KiB | 17.7 s |
| 295 | glm-5.3-flash | simple | - | 0 | 58.5k | 246 | $0.003559 | 87 | 20.7 KiB | 0 ms |
| 296 | glm-5.3-flash | simple | tool_use | 0 | 58.6k | 668 | $0.003648 | 5 | 3.6 KiB | 9.1 s |
| 297 | glm-5.3-flash | simple | tool_use | 0 | 59.9k | 298 | $0.003652 | 92 | 22.3 KiB | 5.8 s |
| 298 | glm-5.3-flash | simple | tool_use | 0 | 60.2k | 228 | $0.003655 | 3 | 2.1 KiB | 3.9 s |
| 299 | glm-5.3-flash | simple | tool_use | 0 | 60.7k | 215 | $0.003687 | 3 | 2.0 KiB | 3.5 s |
| 300 | glm-5.3-flash | simple | tool_use | 0 | 61.2k | 157 | $0.003705 | 3 | 1.6 KiB | 2.9 s |
| 301 | glm-5.3-flash | simple | tool_use | 0 | 61.4k | 754 | $0.003837 | 234 | 55.0 KiB | 11.6 s |
| 302 | glm-5.3-flash | simple | end_turn | 0 | 61.9k | 739 | $0.003862 | 253 | 56.1 KiB | 11.1 s |
| 303 | glm-5.3-flash | simple | tool_use | 0 | 62.6k | 3.4k | $0.004431 | 1133 | 260.9 KiB | 54.5 s |
| 304 | glm-5.3-flash | simple | tool_use | 0 | 64.0k | 461 | $0.003933 | 142 | 33.6 KiB | 9.3 s |
| 305 | glm-5.3-flash | simple | - | 0 | 64.5k | 1.8k | $0.004231 | 705 | 162.1 KiB | 0 ms |
| 306 | glm-5.3-flash | simple | tool_use | 0 | 66.4k | 785 | $0.004142 | 293 | 68.1 KiB | 2 ms |
| 307 | glm-5.3-flash | simple | tool_use | 0 | 65.8k | 63 | $0.003960 | 3 | 1.2 KiB | 1 ms |
| 308 | glm-5.3-flash | simple | tool_use | 0 | 66.8k | 92 | $0.004028 | 20 | 5.7 KiB | 3.5 s |
| 309 | glm-5.3-flash | simple | - | 0 | 65.9k | 62 | $0.003969 | 2 | 1.2 KiB | 0 ms |
| 310 | glm-5.3-flash | simple | tool_use | 0 | 67.1k | 61 | $0.004038 | 2 | 1.2 KiB | 1 ms |
| 311 | glm-5.3-flash | simple | tool_use | 0 | 66.0k | 65 | $0.003975 | 2 | 1.2 KiB | 2 ms |
| 312 | glm-5.3-flash | simple | tool_use | 0 | 64.5k | 53 | $0.003880 | 2 | 1.2 KiB | 2.6 s |
| 313 | glm-5.3-flash | simple | tool_use | 0 | 66.7k | 55 | $0.004010 | 2 | 1.2 KiB | 2.2 s |
| 314 | glm-5.3-flash | simple | tool_use | 0 | 68.0k | 2.3k | $0.004534 | 910 | 209.3 KiB | 34.4 s |
| 315 | glm-5.3-flash | simple | tool_use | 0 | 68.8k | 7.3k | $0.005592 | 2066 | 481.8 KiB | 1m 24s |
| 316 | glm-5.3-flash | simple | tool_use | 0 | 70.8k | 2.7k | $0.004790 | 486 | 117.8 KiB | 33.3 s |
| 317 | glm-5.3-flash | simple | tool_use | 0 | 72.7k | 1.7k | $0.004697 | 104 | 29.9 KiB | 16.5 s |
| 318 | glm-5.3-flash | simple | tool_use | 0 | 75.4k | 1.1k | $0.004746 | 6 | 5.8 KiB | 10.3 s |
| 319 | glm-5.3-flash | simple | tool_use | 0 | 77.4k | 330 | $0.004709 | 3 | 2.5 KiB | 3.9 s |
| 320 | glm-5.3-flash | simple | tool_use | 0 | 77.2k | 414 | $0.004714 | 121 | 27.8 KiB | 12.0 s |
| 321 | glm-5.3-flash | simple | tool_use | 0 | 77.1k | 49 | $0.004634 | 2 | 1.2 KiB | 2.8 s |
| 322 | glm-5.3-flash | simple | tool_use | 0 | 77.0k | 494 | $0.004719 | 4 | 3.3 KiB | 6.9 s |
| 323 | glm-5.3-flash | simple | tool_use | 0 | 77.5k | 150 | $0.004682 | 2 | 1.5 KiB | 3.5 s |
| 324 | glm-5.3-flash | simple | tool_use | 0 | 77.7k | 1.1k | $0.004876 | 74 | 19.4 KiB | 15.3 s |
| 325 | glm-5.3-flash | simple | tool_use | 0 | 78.2k | 67 | $0.004706 | 2 | 1.2 KiB | 4.0 s |
| 326 | glm-5.3-flash | simple | - | 0 | 78.1k | 48 | $0.004698 | 2 | 1.2 KiB | 0 ms |
| 327 | glm-5.3-flash | simple | tool_use | 0 | 78.4k | 183 | $0.004740 | 3 | 1.7 KiB | 3.2 s |
| 328 | glm-5.3-flash | simple | tool_use | 0 | 78.9k | 542 | $0.004844 | 111 | 26.4 KiB | 7.4 s |
| 329 | glm-5.3-flash | simple | tool_use | 0 | 79.3k | 83 | $0.004775 | 2 | 1.3 KiB | 2.8 s |
| 330 | glm-5.3-flash | simple | tool_use | 0 | 79.5k | 91 | $0.004788 | 2 | 1.3 KiB | 2.5 s |
| 331 | glm-5.3-flash | simple | tool_use | 0 | 79.8k | 502 | $0.004887 | 195 | 45.7 KiB | 9.6 s |
| 332 | glm-5.3-flash | simple | tool_use | 0 | 80.1k | 488 | $0.004905 | 4 | 3.1 KiB | 6.5 s |
| 333 | glm-5.3-flash | simple | end_turn | 0 | 81.2k | 515 | $0.004976 | 165 | 36.4 KiB | 8.6 s |
| 334 | glm-5.3-flash | simple | tool_use | 0 | 82.0k | 721 | $0.005064 | 222 | 52.1 KiB | 14.1 s |
| 335 | glm-5.3-flash | simple | tool_use | 0 | 89.6k | 3.3k | $0.006029 | 1115 | 258.0 KiB | 40.5 s |
| 336 | glm-5.3-flash | simple | tool_use | 0 | 97.7k | 1.6k | $0.006185 | 540 | 125.3 KiB | 24.0 s |
| 337 | glm-5.3-flash | simple | tool_use | 0 | 98.3k | 2.4k | $0.006376 | 743 | 171.6 KiB | 31.9 s |
| 338 | glm-5.3-flash | simple | tool_use | 0 | 99.2k | 265 | $0.006005 | 3 | 1.9 KiB | 3.6 s |
| 339 | glm-5.3-flash | simple | tool_use | 0 | 100.3k | 7.6k | $0.007532 | 2756 | 635.1 KiB | 1m 41s |
| 340 | glm-5.3-flash | simple | unspecified | 0 | 0 | 0 | $0.0000 | 1111 | 254.8 KiB | 1m 14s |
| 341 | glm-5.3-flash | simple | end_turn | 0 | 89.1k | 2.8k | $0.005904 | 907 | 196.4 KiB | 40.7 s |
| 342 | kimi-k3 | complex | - | 0 | 16.6k | 312 | $0.0356 | 120 | 47.2 KiB | 0 ms |
| 343 | kimi-k3 | complex | tool_use | 0 | 17.5k | 87 | $0.0358 | 3 | 1.1 KiB | 2.2 s |
| 344 | kimi-k3 | complex | tool_use | 0 | 19.2k | 2.5k | $0.0581 | 1447 | 510.6 KiB | 37.9 s |
| 345 | kimi-k3 | complex | tool_use | 0 | 20.7k | 156 | $0.0426 | 24 | 8.3 KiB | 3.2 s |
| 346 | kimi-k3 | complex | tool_use | 0 | 21.5k | 1.0k | $0.0513 | 51 | 22.3 KiB | 14.9 s |
| 347 | kimi-k3 | complex | tool_use | 0 | 23.2k | 2.2k | $0.0638 | 9 | 9.4 KiB | 31.0 s |
| 348 | kimi-k3 | complex | tool_use | 0 | 27.2k | 690 | $0.0600 | 126 | 47.6 KiB | 11.6 s |
| 349 | kimi-k3 | complex | - | 0 | 28.1k | 106 | $0.0571 | 15 | 5.7 KiB | 0 ms |
| 350 | kimi-k3 | complex | tool_use | 0 | 28.3k | 99 | $0.0575 | 3 | 1.1 KiB | 2.4 s |
| 351 | kimi-k3 | complex | tool_use | 0 | 29.3k | 681 | $0.0640 | 5 | 3.8 KiB | 9.9 s |
| 352 | kimi-k3 | complex | tool_use | 0 | 29.5k | 642 | $0.0642 | 5 | 3.6 KiB | 9.7 s |
| 353 | kimi-k3 | complex | tool_use | 0 | 30.0k | 72 | $0.0606 | 3 | 1.1 KiB | 2.5 s |
| 354 | kimi-k3 | complex | tool_use | 0 | 30.1k | 104 | $0.0611 | 3 | 1.2 KiB | 2.8 s |
| 355 | kimi-k3 | complex | tool_use | 0 | 30.2k | 231 | $0.0623 | 69 | 25.8 KiB | 5.0 s |
| 356 | kimi-k3 | complex | tool_use | 0 | 29.3k | 121 | $0.0595 | 3 | 1.2 KiB | 3.0 s |
| 357 | kimi-k3 | complex | tool_use | 0 | 29.4k | 78 | $0.0595 | 3 | 1.1 KiB | 2.3 s |
| 358 | kimi-k3 | complex | tool_use | 0 | 29.6k | 106 | $0.0600 | 3 | 1.2 KiB | 2.5 s |
| 359 | kimi-k3 | complex | tool_use | 0 | 29.6k | 208 | $0.0608 | 18 | 7.7 KiB | 3.9 s |
| 360 | kimi-k3 | complex | tool_use | 0 | 30.5k | 216 | $0.0626 | 55 | 20.8 KiB | 3.8 s |
| 361 | kimi-k3 | complex | tool_use | 0 | 30.6k | 88 | $0.0619 | 3 | 1.1 KiB | 2.8 s |
| 362 | kimi-k3 | complex | tool_use | 0 | 31.0k | 288 | $0.0642 | 3 | 1.9 KiB | 4.7 s |
| 363 | kimi-k3 | complex | tool_use | 0 | 31.7k | 92 | $0.0641 | 3 | 1.2 KiB | 2.3 s |
| 364 | kimi-k3 | complex | tool_use | 0 | 31.9k | 127 | $0.0649 | 3 | 1.3 KiB | 2.5 s |
| 365 | kimi-k3 | complex | tool_use | 0 | 32.2k | 75 | $0.0650 | 3 | 1.1 KiB | 2.5 s |
| 366 | kimi-k3 | complex | tool_use | 0 | 32.4k | 129 | $0.0657 | 3 | 1.3 KiB | 2.7 s |
| 367 | kimi-k3 | complex | tool_use | 0 | 32.6k | 93 | $0.0660 | 3 | 1.2 KiB | 2.3 s |
| 368 | kimi-k3 | complex | tool_use | 0 | 32.7k | 97 | $0.0663 | 3 | 1.2 KiB | 3.8 s |
| 369 | kimi-k3 | complex | tool_use | 0 | 33.2k | 109 | $0.0673 | 3 | 1.3 KiB | 2.7 s |
| 370 | kimi-k3 | complex | - | 0 | 33.5k | 173 | $0.0684 | 3 | 1.5 KiB | 0 ms |
| 371 | kimi-k3 | complex | end_turn | 0 | 33.9k | 401 | $0.0710 | 213 | 78.8 KiB | 7.6 s |
| 372 | kimi-k3 | complex | tool_use | 0 | 34.4k | 1.5k | $0.0808 | 331 | 130.0 KiB | 17.2 s |
| 373 | kimi-k3 | complex | tool_use | 0 | 36.0k | 2.2k | $0.0898 | 9 | 9.6 KiB | 22.0 s |
| 374 | kimi-k3 | complex | tool_use | 0 | 40.1k | 1.1k | $0.0891 | 6 | 5.7 KiB | 11.9 s |
| 375 | kimi-k3 | complex | tool_use | 0 | 42.4k | 282 | $0.0870 | 3 | 1.8 KiB | 4.3 s |
| 376 | kimi-k3 | complex | tool_use | 0 | 43.1k | 153 | $0.0875 | 11 | 4.4 KiB | 2.7 s |
| 377 | kimi-k3 | complex | tool_use | 0 | 43.6k | 225 | $0.0891 | 14 | 5.5 KiB | 3.6 s |
| 378 | kimi-k3 | complex | tool_use | 0 | 44.1k | 144 | $0.0893 | 37 | 11.2 KiB | 2.5 s |
| 379 | kimi-k3 | complex | end_turn | 0 | 44.2k | 225 | $0.0903 | 119 | 43.4 KiB | 3.4 s |
| 380 | kimi-k3 | complex | tool_use | 0 | 44.5k | 588 | $0.0938 | 188 | 67.1 KiB | 10.2 s |
| 381 | kimi-k3 | complex | tool_use | 0 | 45.2k | 162 | $0.0916 | 3 | 1.5 KiB | 3.1 s |
| 382 | kimi-k3 | complex | tool_use | 0 | 46.0k | 110 | $0.0928 | 4 | 1.3 KiB | 3.2 s |
| 383 | kimi-k3 | complex | end_turn | 0 | 44.9k | 158 | $0.0910 | 79 | 29.7 KiB | 4.9 s |
| 384 | kimi-k3 | complex | tool_use | 0 | 45.1k | 219 | $0.0920 | 63 | 25.7 KiB | 20.6 s |
| 385 | kimi-k3 | complex | tool_use | 0 | 45.0k | 95 | $0.0908 | 3 | 1.2 KiB | 3.4 s |
| 386 | kimi-k3 | complex | end_turn | 0 | 45.2k | 92 | $0.0912 | 44 | 16.6 KiB | 2.4 s |
| 387 | glm-5.3 | standard | - | 0 | 44.2k | 34 | $0.0177 | 2 | 1.1 KiB | 0 ms |
| 388 | glm-5.3-flash | simple | tool_use | 0 | 44.5k | 401 | $0.002750 | 3 | 2.6 KiB | 5.3 s |
| 389 | glm-5.3-flash | simple | tool_use | 0 | 45.4k | 113 | $0.002745 | 7 | 2.2 KiB | 7.9 s |
| 390 | glm-5.3-flash | simple | tool_use | 0 | 45.5k | 190 | $0.002769 | 3 | 1.7 KiB | 3.0 s |
| 391 | glm-5.3-flash | simple | tool_use | 0 | 45.9k | 50 | $0.002766 | 2 | 1.2 KiB | 2.5 s |
| 392 | glm-5.3-flash | simple | tool_use | 0 | 46.1k | 59 | $0.002778 | 2 | 1.2 KiB | 2.7 s |
| 393 | glm-5.3-flash | simple | tool_use | 0 | 46.5k | 514 | $0.002895 | 4 | 3.0 KiB | 4.8 s |
| 394 | glm-5.3-flash | simple | tool_use | 0 | 47.5k | 74 | $0.002864 | 2 | 1.3 KiB | 2.7 s |
| 395 | glm-5.3-flash | simple | tool_use | 0 | 47.8k | 123 | $0.002890 | 2 | 1.6 KiB | 2.6 s |
| 396 | glm-5.3-flash | simple | end_turn | 0 | 48.1k | 139 | $0.002911 | 39 | 9.1 KiB | 4.8 s |

## 8. Error-level events

| Event | Count |
|---|---|
| thread.save | 341 |
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

- Thread saves: 737
- Total messages persisted: 78503
- Avg messages per save: 106

---
*Generated by agentty-stats.*
