# agentty — Session Statistics Report

**Sources:** `logs/2026-09-10__06:03:34UTC__debug.log`, `logs/2026-09-10__08:21:03UTC__debug.log`

**Generated:** 2026-09-10T11:36:21.356

**Pricing source:** [models.dev](https://models.dev) (agentty cache: `tests/modelsdev-real.json`, USD per 1M tokens)

---

## 1. Overview

| Metric | Value |
|---|---|
| Total turns (dispatches) | 190 |
| Time span | 2026-09-10T08:03:34.766 → 2026-09-10T11:36:21.356 (212m 46s) |
| Models used | glm-5.3, glm-5.3-flash, kimi-k3 |
| Total prompt tokens | 8.33M (8327486) |
| Total completion tokens | 273.2k (273195) |
| Total tokens | 8.60M |
| Estimated cost | $3.7277 |
| Wire chunks | 80572 (23.41 MiB) |
| Request bytes | 32.86 MiB |
| Tool calls | 189 |
| Thread saves | 349 (25706 messages) |
| Models loaded | 2026-09-10__06:03:34UTC__debug.log=19; 2026-09-10__08:21:03UTC__debug.log=19 |
| Error-level events | 163 (200 routine auth) |

## 2. Log volume

### By level

| Level | Count |
|---|---|
| T | 80762 |
| D | 1496 |
| E | 363 |
| I | 18 |
| W | 17 |

### By component

| Component | Count |
|---|---|
| wire | 81723 |
| persist | 349 |
| model | 190 |
| smart | 190 |
| tool | 189 |
| net | 7 |
| auth | 2 |
| general | 2 |
| rag | 2 |
| ui | 2 |

### By event

| Event | Count |
|---|---|
| wire.chunk | 80572 |
| thread.save | 349 |
| openai.auth | 200 |
| dispatch.turn | 190 |
| openai.request | 190 |
| openai.request.body | 190 |
| route.turn | 190 |
| stream.response | 189 |
| tool.exec | 189 |
| stream.end | 188 |
| stream.result | 188 |
| http.local_failed | 4 |
| models.loaded | 4 |
| http.connect_failed | 3 |
| copilot.models.fallback | 2 |
| paste.recv | 2 |
| provider.select | 2 |
| rag.embed | 2 |
| startup | 2 |

## 3. Smart-mode routing

### Role

| Role | Turns | % of total |
|---|---|---|
| implementation | 127 | 66.8 |
| utility | 44 | 23.2 |
| strategic | 19 | 10.0 |

### Complexity

| Complexity | Turns | % of total |
|---|---|---|
| standard | 127 | 66.8 |
| simple | 38 | 20.0 |
| complex | 19 | 10.0 |
| trivial | 6 | 3.2 |

### Orchestration flags

- Orchestrate: 190 / 190 turns
- Subagents: 190 / 190 turns
- Compacting: 0 / 190 turns

## 4. Per-model usage

| Model | Turns | Prompt tok | Completion tok | Total tok | Req bytes | Chunk bytes | Chunks | Retried | Errors |
|---|---|---|---|---|---|---|---|---|---|
| glm-5.3 | 127 | 6.16M | 64.2k | 6.23M | 23.98 MiB | 6.24 MiB | 12585 | 0 | 0 |
| glm-5.3-flash | 44 | 1.68M | 200.9k | 1.88M | 6.94 MiB | 12.99 MiB | 57030 | 0 | 0 |
| kimi-k3 | 19 | 483.4k | 8.1k | 491.5k | 1.93 MiB | 4.18 MiB | 10957 | 0 | 0 |

## 4b. Cost (USD)

*Prices from [models.dev](https://models.dev), loaded from `tests/modelsdev-real.json`; all amounts are United States Dollars (USD). Cost = prompt/1M × input-rate + completion/1M × output-rate.*

| Model | $/1M in | Input cost | $/1M out | Output cost | Turns | Total cost |
|---|---|---|---|---|---|---|
| glm-5.3 | $0.4000 | $2.4650 | $1.4000 | $0.0899 | 127 | $2.5550 |
| kimi-k3 | $2.0000 | $0.9669 | $8.0000 | $0.0648 | 19 | $1.0317 |
| glm-5.3-flash | $0.0600 | $0.1009 | $0.2000 | $0.0402 | 44 | $0.1411 |
| | | | | | | **$3.7277** |

*Note: estimates use input/output token counts from the logs; cache-read/cache-write tokens are not logged and are therefore not reflected in these figures.*

## 5. Tool usage

| Tool | Calls | Total | Avg | Max | ok | err |
|---|---|---|---|---|---|---|
| shell | 135 | 1m 14s | 548 ms | 10.7 s | 134 | 1 |
| edit | 25 | 346 ms | 13 ms | 33 ms | 24 | 1 |
| read | 10 | 28 ms | 2 ms | 28 ms | 10 | 0 |
| grep | 6 | 83 ms | 13 ms | 35 ms | 6 | 0 |
| web_fetch | 5 | 4.0 s | 806 ms | 1.4 s | 4 | 1 |
| write | 3 | 38 ms | 12 ms | 32 ms | 2 | 1 |
| list_dir | 2 | 0 ms | 0 ms | 0 ms | 2 | 0 |
| glob | 1 | 184 ms | 184 ms | 184 ms | 1 | 0 |
| remember | 1 | 0 ms | 0 ms | 0 ms | 1 | 0 |
| web_search | 1 | 1.4 s | 1.4 s | 1.4 s | 1 | 0 |

## 6. Wire / streaming

### Stop reasons

| Stop | Count |
|---|---|
| tool_use | 172 |
| max_tokens | 11 |
| end_turn | 4 |
| unspecified | 1 |

### HTTP status

| Status | Count |
|---|---|
| 200 | 565 |

### Hosts

| Host | Count |
|---|---|
| ollama.com | 188 |

### Providers

| Provider | Count |
|---|---|
| https://ollama.com/v1#main | 2 |

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
| 147 | glm-5.3-flash | trivial | - | 0 | 0 | 0 | $0.0000 | 0 | 0 B | 0 ms |
| 148 | kimi-k3 | complex | tool_use | 0 | 14.0k | 206 | $0.0296 | 13 | 6.0 KiB | 3.2 s |
| 149 | kimi-k3 | complex | tool_use | 0 | 15.4k | 122 | $0.0319 | 3 | 1.3 KiB | 2.2 s |
| 150 | kimi-k3 | complex | tool_use | 0 | 22.8k | 137 | $0.0468 | 38 | 14.5 KiB | 3.2 s |
| 151 | kimi-k3 | complex | end_turn | 0 | 28.7k | 1.8k | $0.0716 | 1030 | 356.6 KiB | 21.3 s |
| 152 | kimi-k3 | complex | unspecified | 0 | 0 | 0 | $0.0000 | 8627 | 3.37 MiB | 3m 20s |
| 153 | glm-5.3 | standard | max_tokens | 0 | 31.5k | 16.4k | $0.0356 | 8440 | 3.26 MiB | 2m 34s |
| 154 | glm-5.3-flash | simple | max_tokens | 0 | 31.6k | 16.4k | $0.005171 | 4951 | 1.13 MiB | 3m 10s |
| 155 | glm-5.3-flash | simple | max_tokens | 0 | 31.6k | 16.4k | $0.005172 | 4878 | 1.11 MiB | 3m 3s |
| 156 | glm-5.3-flash | simple | max_tokens | 0 | 31.6k | 16.4k | $0.005173 | 4839 | 1.10 MiB | 3m 7s |
| 157 | glm-5.3-flash | simple | tool_use | 0 | 31.6k | 476 | $0.001993 | 122 | 29.1 KiB | 6.9 s |
| 158 | glm-5.3-flash | simple | max_tokens | 0 | 31.7k | 16.4k | $0.005181 | 4615 | 1.05 MiB | 2m 46s |
| 159 | glm-5.3-flash | simple | max_tokens | 0 | 31.7k | 16.4k | $0.005182 | 4880 | 1.10 MiB | 3m 0s |
| 160 | glm-5.3-flash | simple | tool_use | 0 | 31.8k | 130 | $0.001932 | 2 | 1.4 KiB | 5.8 s |
| 161 | glm-5.3-flash | simple | max_tokens | 0 | 31.9k | 16.4k | $0.005192 | 5243 | 1.18 MiB | 3m 27s |
| 162 | glm-5.3-flash | simple | max_tokens | 0 | 31.9k | 16.4k | $0.005193 | 4978 | 1.13 MiB | 2m 59s |
| 163 | glm-5.3-flash | simple | tool_use | 0 | 31.9k | 117 | $0.001940 | 14 | 4.1 KiB | 6.4 s |
| 164 | glm-5.3-flash | simple | max_tokens | 0 | 31.5k | 16.4k | $0.005169 | 4799 | 1.09 MiB | 3m 9s |
| 165 | glm-5.3-flash | simple | max_tokens | 0 | 31.6k | 16.4k | $0.005170 | 5174 | 1.17 MiB | 3m 15s |
| 166 | glm-5.3-flash | simple | max_tokens | 0 | 31.6k | 16.4k | $0.005171 | 5024 | 1.14 MiB | 3m 14s |
| 167 | glm-5.3-flash | simple | tool_use | 0 | 31.6k | 10.2k | $0.003941 | 2611 | 613.1 KiB | 1m 56s |
| 168 | glm-5.3-flash | simple | tool_use | 0 | 35.3k | 1.7k | $0.002453 | 59 | 19.3 KiB | 19.4 s |
| 169 | glm-5.3-flash | simple | tool_use | 0 | 38.4k | 1.3k | $0.002558 | 99 | 26.7 KiB | 14.1 s |
| 170 | glm-5.3-flash | simple | - | 0 | 33.6k | 872 | $0.002190 | 301 | 69.9 KiB | 0 ms |
| 171 | glm-5.3-flash | simple | tool_use | 0 | 29.0k | 122 | $0.001767 | 3 | 1.7 KiB | 6.3 s |
| 172 | glm-5.3-flash | simple | tool_use | 0 | 29.4k | 88 | $0.001780 | 3 | 1.3 KiB | 2.1 s |
| 173 | glm-5.3-flash | simple | tool_use | 0 | 29.8k | 91 | $0.001805 | 2 | 1.3 KiB | 2.6 s |
| 174 | glm-5.3-flash | simple | tool_use | 0 | 29.9k | 97 | $0.001816 | 24 | 6.1 KiB | 3.1 s |
| 175 | glm-5.3-flash | simple | tool_use | 0 | 30.1k | 4.9k | $0.002790 | 1146 | 271.1 KiB | 54.9 s |
| 176 | glm-5.3-flash | simple | tool_use | 0 | 32.3k | 973 | $0.002134 | 6 | 5.6 KiB | 14.9 s |
| 177 | glm-5.3-flash | simple | tool_use | 0 | 34.4k | 2.2k | $0.002502 | 10 | 10.8 KiB | 18.5 s |
| 178 | glm-5.3-flash | simple | tool_use | 0 | 37.0k | 1.7k | $0.002556 | 292 | 70.5 KiB | 20.4 s |
| 179 | glm-5.3-flash | simple | - | 0 | 38.3k | 173 | $0.002332 | 59 | 14.4 KiB | 0 ms |
| 180 | glm-5.3-flash | simple | tool_use | 0 | 40.1k | 626 | $0.002528 | 51 | 13.9 KiB | 6.5 s |
| 181 | glm-5.3-flash | simple | tool_use | 0 | 40.6k | 1.3k | $0.002691 | 173 | 42.7 KiB | 13.1 s |
| 182 | glm-5.3-flash | simple | tool_use | 0 | 41.6k | 461 | $0.002588 | 67 | 16.8 KiB | 6.6 s |
| 183 | glm-5.3-flash | simple | - | 0 | 41.6k | 323 | $0.002564 | 124 | 28.9 KiB | 0 ms |
| 184 | glm-5.3-flash | simple | tool_use | 0 | 42.7k | 309 | $0.002626 | 96 | 22.4 KiB | 5.7 s |
| 185 | glm-5.3-flash | simple | - | 0 | 42.7k | 512 | $0.002666 | 160 | 37.2 KiB | 0 ms |
| 186 | glm-5.3-flash | simple | tool_use | 0 | 42.5k | 66 | $0.002563 | 2 | 1.2 KiB | 2.3 s |
| 187 | glm-5.3-flash | simple | tool_use | 0 | 42.6k | 147 | $0.002584 | 2 | 1.5 KiB | 2.4 s |
| 188 | glm-5.3-flash | simple | tool_use | 0 | 43.0k | 166 | $0.002612 | 3 | 1.6 KiB | 3.8 s |
| 189 | glm-5.3-flash | simple | tool_use | 0 | 43.8k | 1.6k | $0.002937 | 329 | 77.3 KiB | 16.5 s |
| 190 | glm-5.3-flash | simple | - | 0 | 0 | 0 | $0.0000 | 29 | 6.6 KiB | 0 ms |

## 8. Error-level events

| Event | Count |
|---|---|
| thread.save | 161 |
| rag.embed | 2 |

**Samples:**

```
2026-09-10T08:17:37.514 rag rag.embed: unavailable: embed failed — endpoint unreachable or model missing; using BM25
2026-09-10T08:17:41.368 persist thread.save: log verification FAILED id=fd6f6872d70a1c61 messages=3 — keeping the legacy document
2026-09-10T08:17:47.060 persist thread.save: log verification FAILED id=fd6f6872d70a1c61 messages=4 — keeping the legacy document
2026-09-10T08:17:49.891 persist thread.save: log verification FAILED id=fd6f6872d70a1c61 messages=5 — keeping the legacy document
2026-09-10T08:30:27.922 persist thread.save: log verification FAILED id=fd6f6872d70a1c61 messages=9 — keeping the legacy document
2026-09-10T08:30:33.963 persist thread.save: log verification FAILED id=fd6f6872d70a1c61 messages=10 — keeping the legacy document
2026-09-10T08:30:40.570 persist thread.save: log verification FAILED id=fd6f6872d70a1c61 messages=11 — keeping the legacy document
2026-09-10T08:30:47.684 persist thread.save: log verification FAILED id=fd6f6872d70a1c61 messages=12 — keeping the legacy document
```

## 9. Persistence

- Thread saves: 349
- Total messages persisted: 25706
- Avg messages per save: 73

---
*Generated by agentty-stats.*
