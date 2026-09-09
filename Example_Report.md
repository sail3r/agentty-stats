# agentty — Session Statistics Report

**Sources:** `./logs/2026-09-08__15:35:27UTC__debug.log`, `./logs/2026-09-08__15:35:27UTC__debug.log.old`, `./logs/2026-09-08__18:45:27UTC__debug.log`, `./logs/2026-09-08__18:52:08UTC__debug.log`, `./logs/2026-09-09__07:48:52UTC__debug.log`, `./logs/2026-09-09__09:09:09UTC__debug.log`, `./logs/2026-09-09__09:58:02UTC__debug.log`, `./logs/2026-09-09__09:58:02UTC__debug.log.old`, `./logs/2026-09-09__11:47:50UTC__debug.log`, `./logs/2026-09-09__11:47:50UTC__debug.log.old`, `./logs/2026-09-09__16:46:10UTC__debug.log`, `./logs/2026-09-09__19:11:39UTC__debug.log`

**Generated:** 2026-09-09T21:37:41.757

---

## 1. Overview

| Metric | Value |
|---|---|
| Total turns (dispatches) | 577 |
| Time span | 2026-09-08T17:35:27.796 → 2026-09-09T21:37:41.757 (1682m 13s) |
| Models used | deepseek-v4-flash:0731, deepseek-v4-pro:0813, glm-5.3, glm-5.3-flash, kimi-k2.7-code, kimi-k3, minimax-m3 |
| Total prompt tokens | 41.35M (41348701) |
| Total completion tokens | 459.1k (459141) |
| Total tokens | 41.81M |
| Wire chunks | 119776 (41.29 MiB) |
| Request bytes | 154.98 MiB |
| Tool calls | 589 |
| Thread saves | 587 (70183 messages) |
| Models loaded | 2026-09-08__15:35:27UTC__debug.log=19; 2026-09-08__15:35:27UTC__debug.log.old=19; 2026-09-08__18:45:27UTC__debug.log=19; 2026-09-08__18:52:08UTC__debug.log=19; 2026-09-09__07:48:52UTC__debug.log=19; 2026-09-09__09:09:09UTC__debug.log=19; 2026-09-09__09:58:02UTC__debug.log=19; 2026-09-09__09:58:02UTC__debug.log.old=19; 2026-09-09__11:47:50UTC__debug.log.old=19; 2026-09-09__16:46:10UTC__debug.log=19; 2026-09-09__19:11:39UTC__debug.log=19 |
| Error-level events | 8 (631 routine auth) |

## 2. Log volume

### By level

| Level | Count |
|---|---|
| D | 4627 |
| E | 639 |
| I | 25 |
| T | 120353 |
| W | 75 |

### By component

| Component | Count |
|---|---|
| auth | 11 |
| general | 8 |
| model | 577 |
| net | 22 |
| persist | 587 |
| rag | 8 |
| smart | 577 |
| tool | 589 |
| ui | 8 |
| wire | 123332 |

### By event

| Event | Count |
|---|---|
| copilot.models.fallback | 11 |
| dispatch.turn | 577 |
| http.local_failed | 22 |
| models.loaded | 21 |
| openai.auth | 631 |
| openai.request | 577 |
| openai.request.body | 577 |
| provider.select | 10 |
| rag.embed | 8 |
| route.turn | 577 |
| startup | 8 |
| stream.end | 577 |
| stream.error | 4 |
| stream.error.body | 4 |
| stream.http_error | 4 |
| stream.response | 578 |
| stream.result | 577 |
| stream.retry | 4 |
| thread.save | 587 |
| tool.exec | 589 |
| wire.chunk | 119776 |

## 3. Smart-mode routing

### Role

| Role | Turns |
|---|---|
| none | 76 |
| strategic | 501 |

### Complexity

| Complexity | Turns |
|---|---|
| complex | 252 |
| simple | 106 |
| standard | 183 |
| trivial | 36 |

### Orchestration flags

- Orchestrate: 503 / 577 turns
- Subagents: 503 / 577 turns
- Compacting: 2 / 577 turns

## 4. Per-model usage

| Model | Turns | Prompt tok | Completion tok | Total tok | Req bytes | Chunk bytes | Chunks | Retried | Errors |
|---|---|---|---|---|---|---|---|---|---|
| deepseek-v4-flash:0731 | 38 | 1.28M | 31.8k | 1.31M | 4.40 MiB | 1.04 MiB | 3766 | 0 | 0 |
| deepseek-v4-pro:0813 | 32 | 1.85M | 16.3k | 1.87M | 6.46 MiB | 923.7 KiB | 3486 | 0 | 0 |
| glm-5.3 | 127 | 12.20M | 160.7k | 12.36M | 45.52 MiB | 17.31 MiB | 41827 | 0 | 0 |
| glm-5.3-flash | 107 | 7.05M | 106.9k | 7.16M | 28.64 MiB | 7.70 MiB | 32707 | 0 | 0 |
| kimi-k2.7-code | 51 | 1.36M | 41.0k | 1.40M | 5.53 MiB | 6.74 MiB | 17091 | 0 | 0 |
| kimi-k3 | 205 | 16.24M | 95.0k | 16.33M | 59.29 MiB | 7.49 MiB | 20495 | 3 | 8 |
| minimax-m3 | 17 | 1.36M | 7.4k | 1.37M | 5.14 MiB | 91.1 KiB | 246 | 0 | 0 |

## 5. Tool usage

| Tool | Calls | Total | Avg | Max | ok | err |
|---|---|---|---|---|---|---|
| edit | 103 | 1.3 s | 12 ms | 35 ms | 101 | 2 |
| git_branch | 4 | 30 ms | 7 ms | 23 ms | 3 | 1 |
| git_commit | 4 | 202 ms | 50 ms | 70 ms | 4 | 0 |
| git_show | 3 | 32 ms | 10 ms | 25 ms | 3 | 0 |
| git_status | 1 | 4 ms | 4 ms | 4 ms | 1 | 0 |
| glob | 1 | 0 ms | 0 ms | 0 ms | 1 | 0 |
| grep | 44 | 521 ms | 11 ms | 59 ms | 44 | 0 |
| list_dir | 3 | 0 ms | 0 ms | 0 ms | 3 | 0 |
| outline | 1 | 24 ms | 24 ms | 24 ms | 1 | 0 |
| process_poll | 1 | 0 ms | 0 ms | 0 ms | 1 | 0 |
| process_start | 1 | 304 ms | 304 ms | 304 ms | 1 | 0 |
| process_stop | 1 | 0 ms | 0 ms | 0 ms | 1 | 0 |
| read | 100 | 4 ms | 0 ms | 4 ms | 97 | 3 |
| read_filter | 2 | 6 ms | 3 ms | 4 ms | 2 | 0 |
| remove | 3 | 0 ms | 0 ms | 0 ms | 3 | 0 |
| shell | 248 | 10m 35s | 2.6 s | 1m 0s | 248 | 0 |
| web_fetch | 5 | 6.0 s | 1.2 s | 1.9 s | 5 | 0 |
| web_search | 9 | 10.6 s | 1.2 s | 1.8 s | 9 | 0 |
| write | 55 | 773 ms | 14 ms | 34 ms | 53 | 2 |

## 6. Wire / streaming

### Stop reasons

| Stop | Count |
|---|---|
| end_turn | 49 |
| tool_use | 524 |
| unspecified | 4 |

### HTTP status

| Status | Count |
|---|---|
| 200 | 1720 |
| 429 | 12 |

### Hosts

| Host | Count |
|---|---|
| ollama.com | 577 |

### Providers

| Provider | Count |
|---|---|
| https://ollama.com/v1#main | 9 |
| https://ollama.com/v1#seaventures | 1 |

## 6b. Failures & retries

| Signal | Count |
|---|---|
| Retried turns (dispatch retry>0) | 3 |
| HTTP error turns | 4 |
| stream.retry attempts | 4 |
| Connection failures (http.local_failed) | 22 |

### HTTP error status

| Status | Count |
|---|---|
| 429 | 4 |

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

**Samples:**

```
2026-09-08T19:48:06.233 conn_fail localhost:11434
2026-09-08T19:48:06.233 conn_fail localhost:9931
2026-09-08T18:14:19.168 conn_fail localhost:11434
2026-09-08T18:14:19.451 conn_fail localhost:9931
2026-09-08T19:05:34.570 conn_fail localhost:11434
2026-09-08T19:05:34.570 conn_fail localhost:9931
2026-09-09T09:54:12.811 conn_fail localhost:11434
2026-09-09T09:54:12.811 conn_fail localhost:9931
```

## 7. Turn-by-turn detail

| # | Model | Complexity | Stop | Retry | Prompt | Completion | Chunks | Bytes | Duration |
|---|---|---|---|---|---|---|---|---|---|
| 1 | glm-5.3-flash | simple | tool_use | 0 | 41.7k | 4.0k | 1601 | 399.2 KiB | 56.0 s |
| 2 | glm-5.3-flash | simple | tool_use | 0 | 42.7k | 2.4k | 938 | 226.7 KiB | 34.3 s |
| 3 | glm-5.3-flash | simple | - | 0 | 44.3k | 982 | 361 | 87.2 KiB | 0 ms |
| 4 | glm-5.3-flash | simple | tool_use | 0 | 46.2k | 1.4k | 553 | 128.7 KiB | 4 ms |
| 5 | glm-5.3-flash | simple | tool_use | 0 | 47.8k | 1.2k | 456 | 108.4 KiB | 12.8 s |
| 6 | glm-5.3-flash | simple | - | 0 | 48.9k | 862 | 333 | 81.1 KiB | 0 ms |
| 7 | glm-5.3-flash | simple | tool_use | 0 | 50.0k | 2.8k | 1230 | 290.2 KiB | 29.6 s |
| 8 | glm-5.3-flash | simple | tool_use | 0 | 50.3k | 4.3k | 1087 | 272.3 KiB | 32.0 s |
| 9 | glm-5.3-flash | simple | tool_use | 0 | 52.1k | 92 | 3 | 1.3 KiB | 3.7 s |
| 10 | glm-5.3-flash | simple | tool_use | 0 | 52.3k | 147 | 3 | 1.5 KiB | 2.1 s |
| 11 | glm-5.3-flash | simple | tool_use | 0 | 52.2k | 991 | 370 | 90.3 KiB | 7.8 s |
| 12 | glm-5.3-flash | simple | - | 0 | 52.3k | 1.5k | 567 | 137.7 KiB | 0 ms |
| 13 | glm-5.3-flash | simple | tool_use | 0 | 53.2k | 1.1k | 328 | 81.1 KiB | 8.2 s |
| 14 | glm-5.3-flash | simple | tool_use | 0 | 53.3k | 131 | 3 | 1.4 KiB | 3.6 s |
| 15 | glm-5.3-flash | simple | tool_use | 0 | 53.1k | 437 | 138 | 33.1 KiB | 5.7 s |
| 16 | glm-5.3-flash | simple | tool_use | 0 | 53.5k | 150 | 3 | 1.5 KiB | 3.3 s |
| 17 | glm-5.3-flash | simple | - | 0 | 53.8k | 385 | 142 | 35.0 KiB | 0 ms |
| 18 | glm-5.3-flash | simple | tool_use | 0 | 53.9k | 45 | 3 | 1.1 KiB | 1 ms |
| 19 | glm-5.3-flash | simple | tool_use | 0 | 54.5k | 263 | 84 | 21.8 KiB | 4 ms |
| 20 | glm-5.3-flash | simple | tool_use | 0 | 56.8k | 193 | 50 | 14.6 KiB | 3.1 s |
| 21 | glm-5.3-flash | simple | tool_use | 0 | 57.2k | 401 | 112 | 26.9 KiB | 4.2 s |
| 22 | glm-5.3-flash | simple | tool_use | 0 | 57.7k | 784 | 102 | 27.9 KiB | 5.3 s |
| 23 | glm-5.3-flash | simple | tool_use | 0 | 58.7k | 143 | 3 | 1.4 KiB | 2.8 s |
| 24 | glm-5.3-flash | simple | - | 0 | 59.7k | 2.7k | 1075 | 249.9 KiB | 0 ms |
| 25 | glm-5.3-flash | simple | tool_use | 0 | 60.0k | 2.0k | 763 | 201.1 KiB | 4 ms |
| 26 | glm-5.3-flash | simple | tool_use | 0 | 62.2k | 3.8k | 391 | 123.2 KiB | 3 ms |
| 27 | glm-5.3-flash | simple | tool_use | 0 | 63.4k | 351 | 84 | 20.8 KiB | 5.4 s |
| 28 | glm-5.3-flash | simple | tool_use | 0 | 63.8k | 233 | 3 | 1.7 KiB | 4.5 s |
| 29 | glm-5.3-flash | simple | tool_use | 0 | 64.2k | 88 | 3 | 1.2 KiB | 2.9 s |
| 30 | glm-5.3-flash | simple | tool_use | 0 | 64.1k | 180 | 3 | 1.6 KiB | 12.5 s |
| 31 | glm-5.3-flash | simple | tool_use | 0 | 64.4k | 154 | 39 | 9.2 KiB | 33.9 s |
| 32 | glm-5.3-flash | simple | tool_use | 0 | 64.5k | 1.3k | 143 | 36.9 KiB | 13.4 s |
| 33 | glm-5.3-flash | simple | tool_use | 0 | 64.9k | 63 | 4 | 1.2 KiB | 2.8 s |
| 34 | glm-5.3-flash | simple | tool_use | 0 | 65.0k | 420 | 4 | 2.7 KiB | 4.2 s |
| 35 | glm-5.3-flash | simple | end_turn | 0 | 65.4k | 692 | 232 | 52.2 KiB | 15.5 s |
| 36 | kimi-k3 | complex | - | 0 | 71.8k | 242 | 13 | 5.0 KiB | 0 ms |
| 37 | kimi-k3 | complex | tool_use | 0 | 72.6k | 234 | 31 | 11.9 KiB | 5.1 s |
| 38 | kimi-k3 | complex | tool_use | 0 | 73.0k | 217 | 31 | 12.2 KiB | 4.6 s |
| 39 | kimi-k3 | complex | - | 0 | 73.6k | 279 | 65 | 24.1 KiB | 0 ms |
| 40 | kimi-k3 | complex | tool_use | 0 | 77.4k | 287 | 49 | 18.7 KiB | 5.1 s |
| 41 | kimi-k3 | complex | tool_use | 0 | 77.8k | 247 | 30 | 11.6 KiB | 4.4 s |
| 42 | kimi-k3 | complex | tool_use | 0 | 78.2k | 198 | 46 | 17.6 KiB | 4.5 s |
| 43 | kimi-k3 | complex | - | 0 | 78.5k | 68 | 5 | 1012 B | 0 ms |
| 44 | kimi-k3 | complex | tool_use | 0 | 78.6k | 51 | 3 | 993 B | 5 ms |
| 45 | kimi-k3 | complex | end_turn | 0 | 78.7k | 540 | 295 | 106.8 KiB | 8.1 s |
| 46 | kimi-k2.7-code | standard | end_turn | 0 | 71.1k | 545 | 297 | 111.6 KiB | 8.9 s |
| 47 | glm-5.3-flash | simple | tool_use | 0 | 73.6k | 2.0k | 798 | 186.6 KiB | 21.1 s |
| 48 | glm-5.3-flash | trivial | - | 0 | 74.2k | 376 | 81 | 20.2 KiB | 0 ms |
| 49 | glm-5.3-flash | trivial | tool_use | 0 | 77.1k | 970 | 335 | 77.8 KiB | 9.0 s |
| 50 | glm-5.3-flash | trivial | tool_use | 0 | 78.4k | 1.5k | 613 | 141.8 KiB | 16.2 s |
| 51 | glm-5.3-flash | trivial | - | 0 | 80.4k | 2.9k | 1257 | 289.0 KiB | 0 ms |
| 52 | glm-5.3-flash | trivial | tool_use | 0 | 80.6k | 112 | 20 | 6.3 KiB | 8.4 s |
| 53 | glm-5.3-flash | trivial | tool_use | 0 | 82.1k | 2.9k | 1042 | 242.9 KiB | 31.8 s |
| 54 | glm-5.3-flash | trivial | tool_use | 0 | 81.0k | 3.9k | 1223 | 348.7 KiB | 39.5 s |
| 55 | glm-5.3-flash | trivial | - | 0 | 80.6k | 550 | 214 | 48.8 KiB | 0 ms |
| 56 | glm-5.3-flash | trivial | tool_use | 0 | 79.6k | 961 | 375 | 86.1 KiB | 10.4 s |
| 57 | glm-5.3-flash | trivial | tool_use | 0 | 80.3k | 1.9k | 754 | 174.6 KiB | 20.0 s |
| 58 | glm-5.3-flash | trivial | - | 0 | 81.2k | 805 | 325 | 74.8 KiB | 0 ms |
| 59 | glm-5.3-flash | trivial | tool_use | 0 | 80.9k | 628 | 213 | 50.8 KiB | 9 ms |
| 60 | glm-5.3-flash | trivial | tool_use | 0 | 81.1k | 44 | 2 | 1.1 KiB | 1 ms |
| 61 | glm-5.3-flash | trivial | tool_use | 0 | 81.1k | 44 | 2 | 1.1 KiB | 2 ms |
| 62 | glm-5.3-flash | trivial | tool_use | 0 | 81.1k | 43 | 2 | 1.1 KiB | 2 ms |
| 63 | glm-5.3-flash | trivial | tool_use | 0 | 81.2k | 221 | 51 | 13.1 KiB | 3.8 s |
| 64 | glm-5.3-flash | trivial | tool_use | 0 | 80.3k | 80 | 2 | 1.2 KiB | 2.4 s |
| 65 | glm-5.3-flash | trivial | - | 0 | 80.8k | 4.4k | 1684 | 389.4 KiB | 0 ms |
| 66 | glm-5.3-flash | trivial | tool_use | 0 | 81.7k | 8.1k | 2851 | 666.3 KiB | 2 ms |
| 67 | glm-5.3-flash | trivial | tool_use | 0 | 82.8k | 5.5k | 1669 | 393.2 KiB | 43.3 s |
| 68 | glm-5.3-flash | trivial | tool_use | 0 | 83.6k | 558 | 12 | 5.1 KiB | 4.5 s |
| 69 | glm-5.3-flash | trivial | tool_use | 0 | 84.2k | 57 | 2 | 1.2 KiB | 2.3 s |
| 70 | glm-5.3-flash | trivial | tool_use | 0 | 84.7k | 446 | 125 | 30.4 KiB | 5.4 s |
| 71 | glm-5.3-flash | trivial | tool_use | 0 | 85.3k | 268 | 19 | 5.3 KiB | 3.9 s |
| 72 | glm-5.3-flash | trivial | tool_use | 0 | 85.8k | 431 | 18 | 5.7 KiB | 5.3 s |
| 73 | glm-5.3-flash | trivial | tool_use | 0 | 86.6k | 243 | 3 | 1.8 KiB | 3.5 s |
| 74 | glm-5.3-flash | trivial | tool_use | 0 | 87.0k | 638 | 145 | 34.4 KiB | 7.0 s |
| 75 | glm-5.3-flash | trivial | tool_use | 0 | 87.6k | 215 | 3 | 1.7 KiB | 2.8 s |
| 76 | glm-5.3-flash | trivial | tool_use | 0 | 88.7k | 816 | 231 | 54.5 KiB | 7.7 s |
| 77 | glm-5.3-flash | trivial | tool_use | 0 | 89.2k | 332 | 101 | 25.0 KiB | 4.0 s |
| 78 | glm-5.3-flash | trivial | tool_use | 0 | 89.4k | 75 | 2 | 1.3 KiB | 5.7 s |
| 79 | glm-5.3-flash | trivial | tool_use | 0 | 89.7k | 225 | 3 | 1.7 KiB | 3.2 s |
| 80 | glm-5.3-flash | trivial | tool_use | 0 | 90.0k | 203 | 10 | 3.1 KiB | 3.7 s |
| 81 | glm-5.3-flash | trivial | tool_use | 0 | 90.3k | 958 | 154 | 37.5 KiB | 8.0 s |
| 82 | glm-5.3-flash | trivial | tool_use | 0 | 91.5k | 499 | 4 | 2.9 KiB | 4.2 s |
| 83 | glm-5.3-flash | trivial | - | 0 | 0 | 0 | 0 | 0 B | 0 ms |
| 84 | kimi-k3 | standard | tool_use | 0 | 101.9k | 3.1k | 1637 | 605.3 KiB | 1m 38s |
| 85 | kimi-k3 | standard | tool_use | 0 | 104.5k | 173 | 13 | 5.2 KiB | 7.8 s |
| 86 | kimi-k3 | standard | - | 0 | 106.5k | 256 | 39 | 14.0 KiB | 0 ms |
| 87 | kimi-k3 | standard | tool_use | 0 | 107.6k | 324 | 34 | 12.6 KiB | 6.8 s |
| 88 | kimi-k3 | standard | tool_use | 0 | 108.0k | 243 | 47 | 17.0 KiB | 7.2 s |
| 89 | kimi-k3 | standard | - | 0 | 107.2k | 289 | 53 | 20.0 KiB | 0 ms |
| 90 | kimi-k3 | standard | end_turn | 0 | 107.6k | 873 | 500 | 173.2 KiB | 12.8 s |
| 91 | kimi-k3 | standard | tool_use | 0 | 108.5k | 1.1k | 524 | 189.0 KiB | 25.1 s |
| 92 | kimi-k3 | standard | tool_use | 0 | 111.3k | 247 | 32 | 12.0 KiB | 6.1 s |
| 93 | kimi-k3 | standard | tool_use | 0 | 111.8k | 163 | 4 | 1.4 KiB | 4.4 s |
| 94 | kimi-k3 | standard | - | 0 | 112.1k | 302 | 66 | 22.7 KiB | 0 ms |
| 95 | kimi-k3 | standard | tool_use | 0 | 114.6k | 280 | 48 | 17.7 KiB | 12.3 s |
| 96 | kimi-k3 | standard | - | 0 | 115.5k | 267 | 47 | 16.3 KiB | 0 ms |
| 97 | kimi-k3 | standard | tool_use | 0 | 113.6k | 269 | 46 | 16.4 KiB | 13.8 s |
| 98 | kimi-k3 | standard | tool_use | 0 | 114.1k | 171 | 37 | 14.2 KiB | 4.2 s |
| 99 | kimi-k3 | standard | tool_use | 0 | 113.0k | 355 | 17 | 6.6 KiB | 6.0 s |
| 100 | kimi-k3 | standard | - | 0 | 113.1k | 144 | 26 | 8.7 KiB | 0 ms |
| 101 | kimi-k3 | standard | tool_use | 0 | 113.6k | 159 | 14 | 4.7 KiB | 3.8 s |
| 102 | kimi-k3 | standard | tool_use | 0 | 113.7k | 164 | 17 | 7.5 KiB | 3.9 s |
| 103 | kimi-k3 | standard | tool_use | 0 | 113.9k | 100 | 3 | 1.1 KiB | 5.2 s |
| 104 | kimi-k3 | standard | tool_use | 0 | 114.1k | 265 | 42 | 14.3 KiB | 5.7 s |
| 105 | kimi-k3 | standard | - | 0 | 114.4k | 146 | 20 | 8.5 KiB | 0 ms |
| 106 | kimi-k3 | standard | tool_use | 0 | 114.8k | 197 | 3 | 1.6 KiB | 6.3 s |
| 107 | kimi-k3 | standard | tool_use | 0 | 114.7k | 157 | 3 | 1.4 KiB | 6.8 s |
| 108 | kimi-k3 | standard | - | 0 | 115.1k | 150 | 20 | 5.4 KiB | 0 ms |
| 109 | kimi-k3 | standard | tool_use | 0 | 115.7k | 659 | 41 | 16.4 KiB | 10.8 s |
| 110 | kimi-k3 | standard | tool_use | 0 | 116.8k | 293 | 16 | 7.5 KiB | 24.4 s |
| 111 | kimi-k3 | standard | tool_use | 0 | 117.3k | 156 | 22 | 8.4 KiB | 4.1 s |
| 112 | kimi-k3 | standard | tool_use | 0 | 117.6k | 265 | 3 | 1.7 KiB | 6.3 s |
| 113 | kimi-k3 | standard | tool_use | 0 | 118.0k | 468 | 23 | 8.9 KiB | 9.5 s |
| 114 | kimi-k3 | standard | tool_use | 0 | 118.9k | 231 | 3 | 1.6 KiB | 5.6 s |
| 115 | kimi-k3 | standard | tool_use | 0 | 119.3k | 604 | 20 | 9.5 KiB | 11.2 s |
| 116 | kimi-k3 | standard | tool_use | 0 | 120.3k | 420 | 4 | 2.6 KiB | 9.0 s |
| 117 | kimi-k3 | standard | end_turn | 0 | 120.8k | 630 | 353 | 124.8 KiB | 13.9 s |
| 118 | kimi-k3 | standard | tool_use | 0 | 121.6k | 237 | 39 | 13.8 KiB | 5.1 s |
| 119 | kimi-k3 | standard | tool_use | 0 | 122.2k | 196 | 33 | 12.4 KiB | 5.3 s |
| 120 | kimi-k3 | standard | tool_use | 0 | 122.6k | 184 | 3 | 1.5 KiB | 4.5 s |
| 121 | kimi-k3 | standard | tool_use | 0 | 123.1k | 221 | 36 | 14.0 KiB | 7.8 s |
| 122 | kimi-k3 | standard | tool_use | 0 | 123.5k | 273 | 44 | 17.8 KiB | 7.9 s |
| 123 | kimi-k3 | standard | tool_use | 0 | 124.3k | 189 | 42 | 16.4 KiB | 8.9 s |
| 124 | kimi-k3 | standard | tool_use | 0 | 124.6k | 151 | 32 | 12.4 KiB | 7.3 s |
| 125 | kimi-k3 | standard | tool_use | 0 | 124.9k | 97 | 3 | 1.1 KiB | 3.4 s |
| 126 | kimi-k3 | standard | tool_use | 0 | 125.4k | 164 | 3 | 1.4 KiB | 4.5 s |
| 127 | kimi-k3 | standard | tool_use | 0 | 125.8k | 123 | 3 | 1.2 KiB | 3.8 s |
| 128 | kimi-k3 | standard | tool_use | 0 | 126.0k | 111 | 3 | 1.2 KiB | 4.0 s |
| 129 | kimi-k3 | standard | tool_use | 0 | 126.3k | 203 | 27 | 9.7 KiB | 4.7 s |
| 130 | kimi-k3 | standard | tool_use | 0 | 126.8k | 226 | 3 | 1.7 KiB | 8.5 s |
| 131 | kimi-k3 | standard | tool_use | 0 | 127.2k | 156 | 15 | 5.8 KiB | 3.9 s |
| 132 | kimi-k3 | standard | tool_use | 0 | 127.6k | 173 | 51 | 17.5 KiB | 3.8 s |
| 133 | kimi-k3 | standard | tool_use | 0 | 127.8k | 148 | 3 | 1.3 KiB | 3.9 s |
| 134 | kimi-k3 | standard | tool_use | 0 | 128.1k | 227 | 37 | 14.4 KiB | 5.2 s |
| 135 | kimi-k3 | standard | tool_use | 0 | 128.5k | 160 | 17 | 6.5 KiB | 4.5 s |
| 136 | kimi-k3 | standard | tool_use | 0 | 128.9k | 198 | 28 | 10.8 KiB | 4.4 s |
| 137 | kimi-k3 | standard | - | 0 | 129.3k | 172 | 37 | 13.8 KiB | 0 ms |
| 138 | kimi-k3 | standard | tool_use | 0 | 129.5k | 119 | 3 | 1.2 KiB | 5.0 s |
| 139 | kimi-k3 | standard | end_turn | 0 | 129.8k | 380 | 196 | 74.4 KiB | 7.8 s |
| 140 | glm-5.3-flash | standard | tool_use | 0 | 116.4k | 307 | 107 | 24.8 KiB | 11.8 s |
| 141 | glm-5.3-flash | standard | tool_use | 0 | 116.5k | 167 | 26 | 7.3 KiB | 3.6 s |
| 142 | glm-5.3-flash | standard | tool_use | 0 | 116.9k | 696 | 235 | 56.5 KiB | 7.8 s |
| 143 | glm-5.3-flash | standard | tool_use | 0 | 117.3k | 385 | 115 | 27.1 KiB | 6.4 s |
| 144 | glm-5.3-flash | standard | tool_use | 0 | 117.6k | 243 | 21 | 6.1 KiB | 3.8 s |
| 145 | glm-5.3-flash | standard | tool_use | 0 | 118.1k | 457 | 138 | 34.6 KiB | 6.4 s |
| 146 | glm-5.3-flash | standard | end_turn | 0 | 118.4k | 447 | 154 | 33.8 KiB | 6.2 s |
| 147 | glm-5.3-flash | standard | tool_use | 0 | 118.9k | 142 | 27 | 7.6 KiB | 2.9 s |
| 148 | glm-5.3-flash | standard | tool_use | 0 | 119.2k | 306 | 37 | 11.8 KiB | 3.8 s |
| 149 | glm-5.3-flash | standard | tool_use | 0 | 119.7k | 179 | 25 | 6.8 KiB | 4.2 s |
| 150 | glm-5.3-flash | standard | end_turn | 0 | 119.9k | 355 | 113 | 25.7 KiB | 4.3 s |
| 151 | glm-5.3-flash | standard | - | 0 | 120.3k | 2.8k | 303 | 79.5 KiB | 0 ms |
| 152 | glm-5.3-flash | standard | end_turn | 0 | 122.5k | 363 | 127 | 30.7 KiB | 4.5 s |
| 153 | glm-5.3-flash | standard | tool_use | 0 | 14.6k | 195 | 63 | 15.8 KiB | 2.3 s |
| 154 | glm-5.3-flash | standard | tool_use | 0 | 15.5k | 30 | 3 | 1.1 KiB | 1.0 s |
| 155 | glm-5.3-flash | standard | tool_use | 0 | 17.1k | 175 | 50 | 12.7 KiB | 2.7 s |
| 156 | glm-5.3-flash | standard | tool_use | 0 | 19.0k | 2.4k | 222 | 64.8 KiB | 25.2 s |
| 157 | glm-5.3-flash | standard | end_turn | 0 | 20.6k | 225 | 70 | 16.5 KiB | 3.5 s |
| 158 | kimi-k3 | complex | tool_use | 0 | 13.8k | 1.9k | 22 | 13.7 KiB | 22.5 s |
| 159 | kimi-k3 | complex | end_turn | 0 | 15.7k | 236 | 127 | 45.5 KiB | 3.8 s |
| 160 | kimi-k3 | complex | tool_use | 0 | 16.0k | 1.2k | 662 | 251.6 KiB | 13.2 s |
| 161 | kimi-k3 | complex | end_turn | 0 | 16.9k | 484 | 276 | 95.4 KiB | 9.4 s |
| 162 | kimi-k3 | complex | tool_use | 0 | 17.4k | 206 | 75 | 27.4 KiB | 3.8 s |
| 163 | kimi-k3 | complex | end_turn | 0 | 18.5k | 686 | 394 | 135.6 KiB | 9.7 s |
| 164 | kimi-k2.7-code | standard | tool_use | 0 | 17.5k | 509 | 42 | 23.5 KiB | 5.5 s |
| 165 | kimi-k2.7-code | standard | end_turn | 0 | 18.0k | 157 | 73 | 32.3 KiB | 2.2 s |
| 166 | kimi-k2.7-code | standard | tool_use | 0 | 18.1k | 36 | 3 | 1.1 KiB | 1.8 s |
| 167 | kimi-k2.7-code | standard | end_turn | 0 | 19.1k | 865 | 481 | 184.1 KiB | 8.9 s |
| 168 | glm-5.3-flash | simple | tool_use | 0 | 22.1k | 823 | 306 | 70.5 KiB | 13.5 s |
| 169 | glm-5.3-flash | simple | tool_use | 0 | 23.1k | 657 | 241 | 55.7 KiB | 9.5 s |
| 170 | glm-5.3-flash | simple | tool_use | 0 | 24.2k | 52 | 2 | 1.2 KiB | 1.8 s |
| 171 | glm-5.3-flash | simple | end_turn | 0 | 24.8k | 1.3k | 510 | 114.9 KiB | 23.1 s |
| 172 | glm-5.3-flash | simple | tool_use | 0 | 25.1k | 2.8k | 1009 | 230.8 KiB | 37.7 s |
| 173 | glm-5.3-flash | simple | - | 0 | 26.1k | 493 | 131 | 31.0 KiB | 0 ms |
| 174 | glm-5.3-flash | simple | tool_use | 0 | 26.0k | 48 | 15 | 3.8 KiB | 2 ms |
| 175 | glm-5.3-flash | simple | tool_use | 0 | 25.6k | 2.1k | 619 | 143.6 KiB | 31.2 s |
| 176 | glm-5.3-flash | simple | - | 0 | 26.2k | 163 | 2 | 1.5 KiB | 0 ms |
| 177 | glm-5.3-flash | simple | end_turn | 0 | 26.0k | 349 | 138 | 29.9 KiB | 6.2 s |
| 178 | kimi-k2.7-code | standard | tool_use | 0 | 24.1k | 43 | 2 | 1.1 KiB | 2.9 s |
| 179 | kimi-k2.7-code | standard | tool_use | 0 | 24.5k | 487 | 218 | 96.8 KiB | 4.4 s |
| 180 | kimi-k2.7-code | standard | end_turn | 0 | 24.3k | 395 | 203 | 81.1 KiB | 4.0 s |
| 181 | kimi-k3 | complex | tool_use | 0 | 13.8k | 174 | 47 | 19.7 KiB | 3.5 s |
| 182 | kimi-k3 | complex | tool_use | 0 | 13.9k | 1.3k | 32 | 15.9 KiB | 14.3 s |
| 183 | kimi-k3 | complex | tool_use | 0 | 15.3k | 81 | 3 | 1.1 KiB | 2.6 s |
| 184 | kimi-k3 | complex | tool_use | 0 | 15.4k | 1.1k | 55 | 21.4 KiB | 15.0 s |
| 185 | kimi-k3 | complex | tool_use | 0 | 16.5k | 141 | 3 | 1.3 KiB | 2.7 s |
| 186 | kimi-k3 | complex | tool_use | 0 | 16.8k | 93 | 8 | 2.9 KiB | 2.5 s |
| 187 | kimi-k3 | complex | tool_use | 0 | 17.0k | 104 | 4 | 1.1 KiB | 2.5 s |
| 188 | kimi-k3 | complex | tool_use | 0 | 17.2k | 160 | 5 | 1.4 KiB | 3.0 s |
| 189 | kimi-k3 | complex | end_turn | 0 | 17.4k | 476 | 288 | 95.3 KiB | 7.7 s |
| 190 | kimi-k2.7-code | standard | end_turn | 0 | 15.8k | 1.1k | 588 | 232.2 KiB | 8.8 s |
| 191 | kimi-k2.7-code | standard | tool_use | 0 | 16.2k | 10.3k | 5492 | 1.93 MiB | 1m 18s |
| 192 | kimi-k2.7-code | standard | tool_use | 0 | 17.6k | 132 | 3 | 1.3 KiB | 3.2 s |
| 193 | kimi-k2.7-code | standard | end_turn | 0 | 18.1k | 200 | 115 | 40.6 KiB | 5.3 s |
| 194 | kimi-k3 | complex | tool_use | 0 | 20.4k | 1.3k | 86 | 31.3 KiB | 14.8 s |
| 195 | kimi-k3 | complex | end_turn | 0 | 21.7k | 427 | 239 | 85.0 KiB | 6.3 s |
| 196 | kimi-k3 | complex | tool_use | 0 | 22.1k | 1.4k | 623 | 221.8 KiB | 21.7 s |
| 197 | kimi-k3 | complex | end_turn | 0 | 22.7k | 344 | 189 | 67.3 KiB | 5.9 s |
| 198 | kimi-k2.7-code | standard | end_turn | 0 | 21.0k | 951 | 448 | 198.8 KiB | 7.0 s |
| 199 | kimi-k3 | complex | tool_use | 0 | 23.6k | 1.6k | 219 | 77.1 KiB | 20.7 s |
| 200 | kimi-k3 | complex | end_turn | 0 | 25.0k | 262 | 144 | 50.6 KiB | 4.9 s |
| 201 | kimi-k2.7-code | standard | tool_use | 0 | 23.2k | 1.5k | 40 | 20.9 KiB | 13.6 s |
| 202 | kimi-k2.7-code | standard | tool_use | 0 | 70.6k | 567 | 261 | 114.8 KiB | 62m 42s |
| 203 | kimi-k3 | complex | tool_use | 0 | 13.8k | 754 | 42 | 17.4 KiB | 11.4 s |
| 204 | kimi-k3 | complex | tool_use | 0 | 14.6k | 349 | 8 | 3.3 KiB | 7.1 s |
| 205 | kimi-k3 | complex | end_turn | 0 | 15.0k | 227 | 116 | 44.3 KiB | 3.5 s |
| 206 | kimi-k2.7-code | standard | - | 0 | 13.5k | 208 | 83 | 40.7 KiB | 0 ms |
| 207 | glm-5.3-flash | simple | tool_use | 0 | 16.5k | 241 | 70 | 16.3 KiB | 4.1 s |
| 208 | glm-5.3-flash | simple | tool_use | 0 | 16.7k | 472 | 142 | 33.8 KiB | 6.9 s |
| 209 | glm-5.3-flash | simple | tool_use | 0 | 16.8k | 362 | 117 | 28.1 KiB | 6.2 s |
| 210 | glm-5.3-flash | simple | tool_use | 0 | 17.0k | 2.3k | 701 | 163.1 KiB | 29.6 s |
| 211 | glm-5.3-flash | simple | tool_use | 0 | 18.0k | 948 | 349 | 80.6 KiB | 14.5 s |
| 212 | glm-5.3-flash | simple | end_turn | 0 | 18.5k | 291 | 91 | 20.3 KiB | 4.1 s |
| 213 | kimi-k3 | complex | - | 0 | 18.3k | 112 | 3 | 1.2 KiB | 0 ms |
| 214 | kimi-k3 | complex | tool_use | 0 | 19.1k | 818 | 67 | 25.7 KiB | 11.9 s |
| 215 | kimi-k3 | complex | tool_use | 0 | 20.0k | 190 | 3 | 1.4 KiB | 6.3 s |
| 216 | kimi-k3 | complex | tool_use | 0 | 20.2k | 175 | 33 | 12.2 KiB | 3.9 s |
| 217 | kimi-k3 | complex | end_turn | 0 | 20.4k | 348 | 192 | 68.0 KiB | 5.3 s |
| 218 | kimi-k2.7-code | standard | - | 0 | 18.5k | 35 | 3 | 1.0 KiB | 0 ms |
| 219 | kimi-k2.7-code | standard | tool_use | 0 | 19.4k | 289 | 64 | 24.8 KiB | 3.0 s |
| 220 | kimi-k2.7-code | standard | tool_use | 0 | 20.1k | 2.8k | 1162 | 441.8 KiB | 19.8 s |
| 221 | kimi-k2.7-code | standard | - | 0 | 22.5k | 35 | 2 | 1.0 KiB | 0 ms |
| 222 | kimi-k2.7-code | standard | tool_use | 0 | 23.6k | 1.4k | 684 | 273.7 KiB | 11.0 s |
| 223 | kimi-k2.7-code | standard | tool_use | 0 | 25.4k | 100 | 2 | 1.3 KiB | 1.9 s |
| 224 | kimi-k2.7-code | standard | end_turn | 0 | 25.6k | 220 | 98 | 44.6 KiB | 2.7 s |
| 225 | kimi-k2.7-code | standard | - | 0 | 25.8k | 35 | 3 | 1.0 KiB | 0 ms |
| 226 | kimi-k2.7-code | standard | tool_use | 0 | 25.0k | 35 | 2 | 1.0 KiB | 4 ms |
| 227 | kimi-k2.7-code | standard | tool_use | 0 | 25.0k | 35 | 2 | 1.0 KiB | 5 ms |
| 228 | kimi-k2.7-code | standard | tool_use | 0 | 25.1k | 35 | 2 | 1.0 KiB | 4 ms |
| 229 | kimi-k2.7-code | standard | tool_use | 0 | 25.2k | 4.5k | 2009 | 909.1 KiB | 29.8 s |
| 230 | kimi-k2.7-code | standard | tool_use | 0 | 25.6k | 137 | 2 | 1.4 KiB | 2.6 s |
| 231 | kimi-k2.7-code | standard | tool_use | 0 | 25.7k | 187 | 30 | 17.9 KiB | 2.1 s |
| 232 | kimi-k2.7-code | standard | tool_use | 0 | 26.0k | 75 | 3 | 1.2 KiB | 1.6 s |
| 233 | kimi-k2.7-code | standard | tool_use | 0 | 26.1k | 284 | 72 | 31.8 KiB | 2.6 s |
| 234 | kimi-k2.7-code | standard | tool_use | 0 | 26.5k | 75 | 3 | 1.2 KiB | 1.8 s |
| 235 | kimi-k2.7-code | standard | tool_use | 0 | 26.6k | 1.2k | 519 | 225.1 KiB | 10.4 s |
| 236 | kimi-k2.7-code | standard | - | 0 | 26.8k | 2.0k | 1038 | 430.5 KiB | 0 ms |
| 237 | kimi-k2.7-code | standard | tool_use | 0 | 27.9k | 251 | 3 | 1.8 KiB | 2.2 s |
| 238 | kimi-k2.7-code | standard | tool_use | 0 | 27.5k | 71 | 3 | 1.2 KiB | 2.1 s |
| 239 | kimi-k2.7-code | standard | - | 0 | 27.6k | 43 | 4 | 1.3 KiB | 0 ms |
| 240 | kimi-k2.7-code | standard | tool_use | 0 | 27.8k | 211 | 3 | 1.7 KiB | 2.1 s |
| 241 | kimi-k2.7-code | standard | tool_use | 0 | 28.1k | 71 | 3 | 1.2 KiB | 1.5 s |
| 242 | kimi-k2.7-code | standard | tool_use | 0 | 28.2k | 45 | 3 | 1.3 KiB | 1.2 s |
| 243 | kimi-k2.7-code | standard | - | 0 | 29.2k | 3.3k | 1123 | 507.3 KiB | 0 ms |
| 244 | kimi-k2.7-code | standard | tool_use | 0 | 29.9k | 74 | 3 | 1.2 KiB | 3.8 s |
| 245 | kimi-k2.7-code | standard | tool_use | 0 | 30.1k | 191 | 3 | 1.5 KiB | 5.8 s |
| 246 | kimi-k2.7-code | standard | tool_use | 0 | 30.4k | 435 | 3 | 2.4 KiB | 5.1 s |
| 247 | kimi-k2.7-code | standard | tool_use | 0 | 31.1k | 221 | 3 | 1.8 KiB | 2.9 s |
| 248 | kimi-k2.7-code | standard | tool_use | 0 | 31.5k | 190 | 4 | 1.5 KiB | 2.6 s |
| 249 | kimi-k2.7-code | standard | - | 0 | 31.8k | 510 | 3 | 2.7 KiB | 0 ms |
| 250 | kimi-k2.7-code | standard | tool_use | 0 | 32.7k | 89 | 3 | 1.2 KiB | 2.0 s |
| 251 | kimi-k2.7-code | standard | - | 0 | 32.9k | 33 | 2 | 1.0 KiB | 0 ms |
| 252 | kimi-k2.7-code | standard | tool_use | 0 | 33.1k | 3.7k | 1876 | 797.0 KiB | 30.1 s |
| 253 | glm-5.3 | standard | - | 0 | 36.2k | 1.7k | 872 | 293.1 KiB | 0 ms |
| 254 | glm-5.3 | standard | tool_use | 0 | 37.0k | 506 | 6 | 3.2 KiB | 119 ms |
| 255 | glm-5.3 | standard | tool_use | 0 | 36.9k | 81 | 3 | 1.3 KiB | 1.5 s |
| 256 | glm-5.3 | standard | end_turn | 0 | 37.0k | 326 | 174 | 64.6 KiB | 4.0 s |
| 257 | kimi-k3 | complex | - | 0 | 39.9k | 430 | 213 | 78.4 KiB | 0 ms |
| 258 | kimi-k3 | complex | tool_use | 0 | 41.0k | 1.7k | 8 | 7.8 KiB | 24.2 s |
| 259 | kimi-k3 | complex | tool_use | 0 | 41.9k | 65 | 4 | 1.0 KiB | 2.8 s |
| 260 | kimi-k3 | complex | tool_use | 0 | 42.1k | 200 | 4 | 1.4 KiB | 3.8 s |
| 261 | kimi-k3 | complex | tool_use | 0 | 42.5k | 304 | 3 | 1.8 KiB | 5.1 s |
| 262 | kimi-k3 | complex | tool_use | 0 | 43.0k | 359 | 4 | 2.0 KiB | 5.5 s |
| 263 | kimi-k3 | complex | tool_use | 0 | 43.6k | 232 | 3 | 1.6 KiB | 4.2 s |
| 264 | kimi-k3 | complex | tool_use | 0 | 44.0k | 529 | 4 | 2.6 KiB | 8.2 s |
| 265 | kimi-k3 | complex | tool_use | 0 | 45.0k | 234 | 11 | 4.1 KiB | 3.9 s |
| 266 | kimi-k3 | complex | - | 0 | 45.4k | 98 | 3 | 1.0 KiB | 0 ms |
| 267 | kimi-k3 | complex | tool_use | 0 | 45.9k | 98 | 3 | 1.0 KiB | 6 ms |
| 268 | kimi-k3 | complex | tool_use | 0 | 46.6k | 198 | 3 | 1.4 KiB | 3.7 s |
| 269 | kimi-k3 | complex | tool_use | 0 | 47.0k | 1.2k | 24 | 12.2 KiB | 17.5 s |
| 270 | kimi-k3 | complex | - | 0 | 48.0k | 98 | 3 | 1.0 KiB | 0 ms |
| 271 | kimi-k3 | complex | tool_use | 0 | 49.1k | 1.5k | 6 | 5.8 KiB | 4 ms |
| 272 | kimi-k3 | complex | tool_use | 0 | 49.7k | 1.4k | 6 | 5.7 KiB | 21.1 s |
| 273 | kimi-k3 | complex | tool_use | 0 | 52.1k | 218 | 3 | 1.5 KiB | 5.5 s |
| 274 | kimi-k3 | complex | tool_use | 0 | 52.5k | 577 | 30 | 10.5 KiB | 9.7 s |
| 275 | kimi-k3 | complex | tool_use | 0 | 53.4k | 218 | 3 | 1.5 KiB | 4.2 s |
| 276 | kimi-k3 | complex | tool_use | 0 | 53.7k | 317 | 26 | 10.2 KiB | 7.1 s |
| 277 | kimi-k3 | complex | tool_use | 0 | 54.3k | 217 | 3 | 1.5 KiB | 4.6 s |
| 278 | kimi-k3 | complex | tool_use | 0 | 54.6k | 131 | 3 | 1.3 KiB | 3.7 s |
| 279 | kimi-k3 | complex | end_turn | 0 | 54.8k | 331 | 189 | 64.6 KiB | 6.4 s |
| 280 | kimi-k3 | complex | tool_use | 0 | 55.2k | 13.3k | 6947 | 2.63 MiB | 2m 35s |
| 281 | kimi-k3 | complex | tool_use | 0 | 56.7k | 1.2k | 6 | 4.9 KiB | 14.2 s |
| 282 | kimi-k3 | complex | tool_use | 0 | 58.5k | 98 | 4 | 1.0 KiB | 3.6 s |
| 283 | kimi-k3 | complex | tool_use | 0 | 59.6k | 435 | 4 | 2.3 KiB | 6.3 s |
| 284 | kimi-k3 | complex | - | 0 | 60.2k | 296 | 3 | 1.8 KiB | 0 ms |
| 285 | kimi-k3 | complex | tool_use | 0 | 60.5k | 124 | 3 | 1.2 KiB | 2.9 s |
| 286 | kimi-k3 | complex | tool_use | 0 | 60.7k | 278 | 3 | 1.7 KiB | 4.8 s |
| 287 | kimi-k3 | complex | tool_use | 0 | 61.2k | 496 | 4 | 2.4 KiB | 7.0 s |
| 288 | kimi-k3 | complex | - | 0 | 61.2k | 98 | 3 | 1.0 KiB | 0 ms |
| 289 | kimi-k3 | complex | tool_use | 0 | 62.2k | 305 | 20 | 6.8 KiB | 5.5 s |
| 290 | kimi-k3 | complex | tool_use | 0 | 61.8k | 357 | 4 | 2.0 KiB | 5.9 s |
| 291 | kimi-k3 | complex | - | 0 | 62.4k | 98 | 3 | 1.0 KiB | 0 ms |
| 292 | kimi-k3 | complex | tool_use | 0 | 63.1k | 307 | 3 | 1.8 KiB | 4.9 s |
| 293 | kimi-k3 | complex | tool_use | 0 | 63.7k | 372 | 36 | 13.2 KiB | 5.3 s |
| 294 | kimi-k3 | complex | tool_use | 0 | 64.3k | 283 | 45 | 18.3 KiB | 5.0 s |
| 295 | kimi-k3 | complex | tool_use | 0 | 64.3k | 136 | 3 | 1.3 KiB | 3.8 s |
| 296 | kimi-k3 | complex | end_turn | 0 | 64.5k | 283 | 144 | 54.9 KiB | 4.4 s |
| 297 | glm-5.3 | standard | tool_use | 0 | 59.7k | 86 | 31 | 11.9 KiB | 5.4 s |
| 298 | glm-5.3 | standard | tool_use | 0 | 59.9k | 523 | 4 | 2.9 KiB | 6.2 s |
| 299 | glm-5.3 | standard | tool_use | 0 | 60.5k | 89 | 3 | 1.2 KiB | 2.0 s |
| 300 | glm-5.3 | standard | tool_use | 0 | 60.7k | 8.3k | 4716 | 1.56 MiB | 52.5 s |
| 301 | glm-5.3 | standard | tool_use | 0 | 62.0k | 246 | 3 | 1.9 KiB | 2.9 s |
| 302 | glm-5.3 | standard | tool_use | 0 | 62.6k | 79 | 2 | 1.2 KiB | 3.3 s |
| 303 | glm-5.3 | standard | tool_use | 0 | 62.7k | 112 | 3 | 1.3 KiB | 2.3 s |
| 304 | glm-5.3 | standard | tool_use | 0 | 62.9k | 266 | 90 | 35.8 KiB | 3.0 s |
| 305 | glm-5.3 | standard | end_turn | 0 | 63.2k | 37 | 22 | 7.6 KiB | 2.5 s |
| 306 | kimi-k3 | complex | - | 0 | 69.0k | 66 | 3 | 1.0 KiB | 0 ms |
| 307 | kimi-k3 | complex | tool_use | 0 | 71.3k | 1.4k | 392 | 146.1 KiB | 19.9 s |
| 308 | kimi-k3 | complex | tool_use | 0 | 70.5k | 547 | 4 | 2.8 KiB | 7.7 s |
| 309 | kimi-k3 | complex | tool_use | 0 | 71.1k | 136 | 3 | 1.2 KiB | 3.5 s |
| 310 | kimi-k3 | complex | tool_use | 0 | 71.3k | 112 | 3 | 1.2 KiB | 2.9 s |
| 311 | kimi-k3 | complex | tool_use | 0 | 71.5k | 139 | 3 | 1.3 KiB | 3.4 s |
| 312 | kimi-k3 | complex | tool_use | 0 | 71.6k | 116 | 3 | 1.1 KiB | 3.4 s |
| 313 | kimi-k3 | complex | tool_use | 0 | 71.8k | 175 | 3 | 1.5 KiB | 4.0 s |
| 314 | kimi-k3 | complex | end_turn | 0 | 72.1k | 247 | 136 | 47.8 KiB | 4.5 s |
| 315 | glm-5.3 | standard | tool_use | 0 | 66.3k | 2.1k | 807 | 306.3 KiB | 16.1 s |
| 316 | glm-5.3 | standard | - | 0 | 67.8k | 42 | 3 | 1.0 KiB | 0 ms |
| 317 | glm-5.3 | standard | tool_use | 0 | 68.2k | 564 | 4 | 3.1 KiB | 4.1 s |
| 318 | glm-5.3 | standard | tool_use | 0 | 68.8k | 90 | 3 | 1.3 KiB | 2.1 s |
| 319 | glm-5.3 | standard | - | 0 | 68.9k | 59 | 3 | 1.1 KiB | 0 ms |
| 320 | glm-5.3 | standard | tool_use | 0 | 69.0k | 975 | 5 | 3.9 KiB | 25 ms |
| 321 | glm-5.3 | standard | tool_use | 0 | 70.3k | 84 | 3 | 1.2 KiB | 2.6 s |
| 322 | glm-5.3 | standard | tool_use | 0 | 70.5k | 76 | 3 | 1.2 KiB | 2.0 s |
| 323 | glm-5.3 | standard | - | 0 | 114.8k | 663 | 199 | 64.8 KiB | 0 ms |
| 324 | glm-5.3 | standard | tool_use | 0 | 70.8k | 75 | 3 | 1.2 KiB | 4.0 s |
| 325 | glm-5.3 | standard | tool_use | 0 | 70.9k | 130 | 19 | 8.2 KiB | 4.4 s |
| 326 | glm-5.3 | standard | end_turn | 0 | 71.1k | 235 | 104 | 47.3 KiB | 3.4 s |
| 327 | kimi-k3 | complex | - | 0 | 78.6k | 1.0k | 633 | 208.6 KiB | 0 ms |
| 328 | kimi-k3 | complex | tool_use | 0 | 80.6k | 2.1k | 8 | 8.4 KiB | 31.4 s |
| 329 | kimi-k3 | complex | tool_use | 0 | 81.7k | 124 | 15 | 6.3 KiB | 3.9 s |
| 330 | kimi-k3 | complex | tool_use | 0 | 82.8k | 2.4k | 52 | 25.4 KiB | 27.5 s |
| 331 | kimi-k3 | complex | tool_use | 0 | 84.3k | 498 | 4 | 2.6 KiB | 8.6 s |
| 332 | kimi-k3 | complex | - | 0 | 85.3k | 86 | 15 | 5.2 KiB | 0 ms |
| 333 | kimi-k3 | complex | tool_use | 0 | 85.7k | 347 | 4 | 2.0 KiB | 7.5 s |
| 334 | kimi-k3 | complex | tool_use | 0 | 86.0k | 674 | 5 | 3.3 KiB | 9.5 s |
| 335 | kimi-k3 | complex | tool_use | 0 | 86.8k | 121 | 3 | 1.2 KiB | 5.7 s |
| 336 | kimi-k3 | complex | tool_use | 0 | 87.2k | 602 | 65 | 25.8 KiB | 8.7 s |
| 337 | kimi-k3 | complex | tool_use | 0 | 87.4k | 102 | 3 | 1.1 KiB | 3.7 s |
| 338 | kimi-k3 | complex | tool_use | 0 | 87.6k | 668 | 84 | 29.9 KiB | 9.0 s |
| 339 | kimi-k3 | complex | tool_use | 0 | 88.3k | 102 | 3 | 1.1 KiB | 2.9 s |
| 340 | kimi-k3 | complex | tool_use | 0 | 88.4k | 369 | 37 | 13.9 KiB | 6.2 s |
| 341 | kimi-k3 | complex | - | 0 | 88.9k | 647 | 50 | 18.8 KiB | 0 ms |
| 342 | kimi-k3 | complex | tool_use | 0 | 89.6k | 135 | 3 | 1.3 KiB | 3.9 s |
| 343 | kimi-k3 | complex | tool_use | 0 | 89.8k | 219 | 43 | 15.9 KiB | 4.4 s |
| 344 | kimi-k3 | complex | end_turn | 0 | 90.1k | 439 | 250 | 86.4 KiB | 7.6 s |
| 345 | kimi-k3 | complex | tool_use | 0 | 90.7k | 1.3k | 231 | 80.4 KiB | 16.6 s |
| 346 | kimi-k3 | complex | tool_use | 0 | 92.6k | 703 | 11 | 5.7 KiB | 11.2 s |
| 347 | kimi-k3 | complex | - | 0 | 93.7k | 98 | 3 | 1.0 KiB | 0 ms |
| 348 | kimi-k3 | complex | tool_use | 0 | 94.2k | 1.3k | 6 | 5.3 KiB | 19.6 s |
| 349 | kimi-k3 | complex | tool_use | 0 | 96.0k | 668 | 4 | 3.1 KiB | 13.1 s |
| 350 | kimi-k3 | complex | tool_use | 0 | 96.8k | 104 | 3 | 1.1 KiB | 3.6 s |
| 351 | kimi-k3 | complex | tool_use | 0 | 96.9k | 588 | 28 | 11.1 KiB | 10.5 s |
| 352 | kimi-k3 | complex | tool_use | 0 | 97.6k | 105 | 3 | 1.1 KiB | 3.2 s |
| 353 | kimi-k3 | complex | tool_use | 0 | 97.8k | 642 | 50 | 19.7 KiB | 9.0 s |
| 354 | kimi-k3 | complex | tool_use | 0 | 98.5k | 105 | 3 | 1.2 KiB | 3.6 s |
| 355 | kimi-k3 | complex | tool_use | 0 | 98.7k | 630 | 93 | 33.5 KiB | 9.9 s |
| 356 | kimi-k3 | complex | tool_use | 0 | 99.4k | 104 | 3 | 1.1 KiB | 3.1 s |
| 357 | kimi-k3 | complex | tool_use | 0 | 99.5k | 800 | 183 | 65.3 KiB | 14.3 s |
| 358 | kimi-k3 | complex | tool_use | 0 | 100.3k | 104 | 3 | 1.1 KiB | 3.3 s |
| 359 | kimi-k3 | complex | tool_use | 0 | 100.5k | 206 | 3 | 1.4 KiB | 4.4 s |
| 360 | kimi-k3 | complex | tool_use | 0 | 100.9k | 103 | 3 | 1.2 KiB | 2.6 s |
| 361 | kimi-k3 | complex | tool_use | 0 | 101.1k | 1.2k | 272 | 99.7 KiB | 15.5 s |
| 362 | kimi-k3 | complex | tool_use | 0 | 102.7k | 479 | 4 | 2.3 KiB | 7.6 s |
| 363 | kimi-k3 | complex | tool_use | 0 | 103.5k | 106 | 3 | 1.2 KiB | 2.7 s |
| 364 | kimi-k3 | complex | tool_use | 0 | 103.7k | 228 | 30 | 12.1 KiB | 4.4 s |
| 365 | kimi-k3 | complex | tool_use | 0 | 104.0k | 275 | 37 | 15.5 KiB | 5.7 s |
| 366 | kimi-k3 | complex | tool_use | 0 | 104.5k | 147 | 3 | 1.3 KiB | 3.6 s |
| 367 | kimi-k3 | complex | end_turn | 0 | 104.7k | 372 | 204 | 72.9 KiB | 6.1 s |
| 368 | kimi-k3 | complex | - | 0 | 105.2k | 668 | 336 | 123.6 KiB | 0 ms |
| 369 | kimi-k3 | complex | tool_use | 0 | 105.6k | 400 | 4 | 2.1 KiB | 7.4 s |
| 370 | kimi-k3 | complex | tool_use | 0 | 106.1k | 400 | 4 | 2.2 KiB | 7.7 s |
| 371 | kimi-k3 | complex | tool_use | 0 | 106.6k | 126 | 3 | 1.2 KiB | 3.5 s |
| 372 | kimi-k3 | complex | tool_use | 0 | 106.8k | 653 | 42 | 16.1 KiB | 12.3 s |
| 373 | kimi-k3 | complex | tool_use | 0 | 107.9k | 122 | 3 | 1.2 KiB | 5.6 s |
| 374 | kimi-k3 | complex | tool_use | 0 | 108.1k | 529 | 49 | 17.7 KiB | 12.0 s |
| 375 | kimi-k3 | complex | tool_use | 0 | 109.0k | 267 | 3 | 1.7 KiB | 9.6 s |
| 376 | kimi-k3 | complex | - | 0 | 109.5k | 95 | 3 | 1.0 KiB | 0 ms |
| 377 | kimi-k3 | complex | tool_use | 0 | 109.9k | 471 | 13 | 6.2 KiB | 8.6 s |
| 378 | kimi-k3 | complex | tool_use | 0 | 110.2k | 117 | 3 | 1.2 KiB | 3.3 s |
| 379 | kimi-k3 | complex | tool_use | 0 | 110.4k | 449 | 5 | 2.3 KiB | 7.6 s |
| 380 | kimi-k3 | complex | tool_use | 0 | 110.9k | 117 | 3 | 1.2 KiB | 3.2 s |
| 381 | kimi-k3 | complex | tool_use | 0 | 111.1k | 471 | 83 | 26.6 KiB | 8.7 s |
| 382 | kimi-k3 | complex | tool_use | 0 | 111.6k | 153 | 3 | 1.3 KiB | 4.0 s |
| 383 | kimi-k3 | complex | end_turn | 0 | 111.8k | 265 | 162 | 51.4 KiB | 24.0 s |
| 384 | kimi-k3 | complex | unspecified | 0 | 0 | 0 | 1 | 268 B | 1.1 s |
| 385 | kimi-k3 | complex | unspecified | 1 | 0 | 0 | 1 | 268 B | 2.6 s |
| 386 | kimi-k3 | complex | unspecified | 2 | 0 | 0 | 1 | 268 B | 1.1 s |
| 387 | kimi-k3 | complex | unspecified | 3 | 0 | 0 | 1 | 268 B | 1.1 s |
| 388 | minimax-m3 | simple | tool_use | 0 | 74.8k | 1.0k | 5 | 4.9 KiB | 10.0 s |
| 389 | minimax-m3 | simple | - | 0 | 76.4k | 138 | 6 | 2.0 KiB | 0 ms |
| 390 | minimax-m3 | simple | tool_use | 0 | 77.1k | 237 | 2 | 1.5 KiB | 4.0 s |
| 391 | minimax-m3 | simple | tool_use | 0 | 77.2k | 247 | 3 | 1.7 KiB | 2.9 s |
| 392 | minimax-m3 | simple | tool_use | 0 | 77.8k | 618 | 20 | 6.3 KiB | 6.4 s |
| 393 | minimax-m3 | simple | tool_use | 0 | 78.7k | 159 | 2 | 1.2 KiB | 3.7 s |
| 394 | minimax-m3 | simple | tool_use | 0 | 78.9k | 1.3k | 36 | 12.0 KiB | 17.6 s |
| 395 | minimax-m3 | simple | tool_use | 0 | 80.8k | 597 | 19 | 6.4 KiB | 10.2 s |
| 396 | minimax-m3 | simple | - | 0 | 81.5k | 752 | 10 | 4.7 KiB | 0 ms |
| 397 | minimax-m3 | simple | tool_use | 0 | 82.9k | 251 | 3 | 1.8 KiB | 2.9 s |
| 398 | minimax-m3 | simple | tool_use | 0 | 83.2k | 435 | 5 | 2.6 KiB | 5.1 s |
| 399 | minimax-m3 | simple | tool_use | 0 | 83.7k | 192 | 2 | 1.3 KiB | 2.6 s |
| 400 | minimax-m3 | simple | tool_use | 0 | 83.9k | 182 | 4 | 1.5 KiB | 2.9 s |
| 401 | minimax-m3 | simple | tool_use | 0 | 84.2k | 70 | 2 | 954 B | 1.9 s |
| 402 | minimax-m3 | simple | tool_use | 0 | 84.6k | 104 | 4 | 1.5 KiB | 2.2 s |
| 403 | minimax-m3 | simple | end_turn | 0 | 84.7k | 964 | 42 | 12.6 KiB | 17.8 s |
| 404 | glm-5.3 | complex | tool_use | 0 | 82.4k | 61 | 7 | 3.5 KiB | 6.8 s |
| 405 | glm-5.3 | complex | tool_use | 0 | 82.4k | 12 | 2 | 992 B | 3.6 s |
| 406 | glm-5.3 | complex | tool_use | 0 | 83.3k | 7.4k | 819 | 674.8 KiB | 1m 37s |
| 407 | glm-5.3 | complex | tool_use | 0 | 84.0k | 4.3k | 503 | 382.8 KiB | 56.9 s |
| 408 | glm-5.3 | complex | tool_use | 0 | 85.6k | 9.5k | 918 | 801.2 KiB | 2m 1s |
| 409 | glm-5.3 | complex | tool_use | 0 | 86.2k | 114 | 2 | 1.3 KiB | 3.8 s |
| 410 | glm-5.3 | complex | tool_use | 0 | 86.5k | 5.9k | 726 | 499.6 KiB | 1m 14s |
| 411 | glm-5.3 | complex | - | 0 | 87.4k | 6.1k | 17 | 18.2 KiB | 0 ms |
| 412 | glm-5.3 | complex | tool_use | 0 | 93.6k | 1.4k | 14 | 10.3 KiB | 51.9 s |
| 413 | glm-5.3 | complex | tool_use | 0 | 95.5k | 2.2k | 246 | 176.0 KiB | 32.1 s |
| 414 | glm-5.3 | complex | tool_use | 0 | 95.9k | 429 | 50 | 35.4 KiB | 9.3 s |
| 415 | glm-5.3 | complex | tool_use | 0 | 95.4k | 49 | 2 | 1.1 KiB | 2.6 s |
| 416 | glm-5.3 | complex | tool_use | 0 | 95.7k | 2.1k | 161 | 120.2 KiB | 23.4 s |
| 417 | glm-5.3 | complex | tool_use | 0 | 97.3k | 96 | 6 | 4.1 KiB | 3.1 s |
| 418 | glm-5.3 | complex | tool_use | 0 | 97.5k | 123 | 2 | 1.3 KiB | 3.6 s |
| 419 | glm-5.3 | complex | tool_use | 0 | 97.9k | 527 | 44 | 30.8 KiB | 9.0 s |
| 420 | glm-5.3 | complex | tool_use | 0 | 98.4k | 637 | 5 | 3.6 KiB | 5.9 s |
| 421 | glm-5.3 | complex | tool_use | 0 | 99.1k | 617 | 5 | 3.9 KiB | 7.7 s |
| 422 | glm-5.3 | complex | tool_use | 0 | 100.1k | 83 | 6 | 3.2 KiB | 6.4 s |
| 423 | glm-5.3 | complex | tool_use | 0 | 100.7k | 621 | 4 | 3.0 KiB | 7.3 s |
| 424 | glm-5.3 | complex | tool_use | 0 | 101.8k | 83 | 2 | 1.2 KiB | 3.3 s |
| 425 | glm-5.3 | complex | tool_use | 0 | 102.0k | 357 | 3 | 2.2 KiB | 5.4 s |
| 426 | glm-5.3 | complex | tool_use | 0 | 102.8k | 134 | 4 | 3.2 KiB | 3.7 s |
| 427 | glm-5.3 | complex | tool_use | 0 | 102.9k | 860 | 5 | 4.4 KiB | 7.8 s |
| 428 | glm-5.3 | complex | tool_use | 0 | 103.9k | 38 | 2 | 1.1 KiB | 3.6 s |
| 429 | glm-5.3 | complex | tool_use | 0 | 104.1k | 110 | 5 | 2.9 KiB | 3.2 s |
| 430 | glm-5.3 | complex | tool_use | 0 | 104.3k | 60 | 2 | 1.1 KiB | 2.5 s |
| 431 | glm-5.3 | complex | tool_use | 0 | 104.8k | 1.1k | 16 | 12.7 KiB | 9.1 s |
| 432 | glm-5.3 | complex | tool_use | 0 | 105.9k | 840 | 72 | 56.8 KiB | 18.6 s |
| 433 | glm-5.3 | complex | tool_use | 0 | 106.2k | 54 | 2 | 1.1 KiB | 13.1 s |
| 434 | glm-5.3 | complex | tool_use | 0 | 106.6k | 379 | 17 | 12.0 KiB | 6.0 s |
| 435 | glm-5.3 | complex | tool_use | 0 | 107.2k | 1.5k | 70 | 60.8 KiB | 15.3 s |
| 436 | glm-5.3 | complex | tool_use | 0 | 108.0k | 118 | 2 | 1.3 KiB | 5.2 s |
| 437 | glm-5.3 | complex | tool_use | 0 | 108.1k | 210 | 12 | 8.9 KiB | 5.4 s |
| 438 | glm-5.3 | complex | tool_use | 0 | 108.6k | 409 | 25 | 17.0 KiB | 20.7 s |
| 439 | glm-5.3 | complex | tool_use | 0 | 109.1k | 483 | 15 | 10.4 KiB | 5.9 s |
| 440 | glm-5.3 | complex | tool_use | 0 | 109.7k | 257 | 7 | 4.0 KiB | 3.6 s |
| 441 | glm-5.3 | complex | tool_use | 0 | 110.0k | 154 | 2 | 1.4 KiB | 4.1 s |
| 442 | glm-5.3 | complex | - | 0 | 110.2k | 163 | 3 | 2.3 KiB | 0 ms |
| 443 | glm-5.3 | complex | end_turn | 0 | 110.4k | 752 | 80 | 55.8 KiB | 10.0 s |
| 444 | glm-5.3 | complex | tool_use | 0 | 111.2k | 9.8k | 5799 | 2.01 MiB | 1m 37s |
| 445 | glm-5.3 | complex | tool_use | 0 | 112.3k | 12.2k | 6935 | 2.39 MiB | 2m 9s |
| 446 | glm-5.3 | complex | tool_use | 0 | 112.6k | 163 | 3 | 1.5 KiB | 3.8 s |
| 447 | glm-5.3 | complex | tool_use | 0 | 113.1k | 453 | 215 | 68.2 KiB | 7.3 s |
| 448 | glm-5.3 | complex | tool_use | 0 | 113.8k | 4.0k | 2012 | 734.7 KiB | 40.0 s |
| 449 | glm-5.3 | complex | - | 0 | 0 | 0 | 0 | 0 B | 0 ms |
| 450 | glm-5.3 | complex | tool_use | 0 | 115.5k | 129 | 17 | 11.9 KiB | 3.0 s |
| 451 | glm-5.3 | complex | tool_use | 0 | 116.0k | 51 | 3 | 1.1 KiB | 2.3 s |
| 452 | glm-5.3 | complex | tool_use | 0 | 117.0k | 7.8k | 4379 | 1.50 MiB | 57.9 s |
| 453 | glm-5.3 | complex | tool_use | 0 | 117.2k | 6.0k | 3445 | 1.18 MiB | 41.9 s |
| 454 | glm-5.3 | complex | tool_use | 0 | 118.2k | 1.7k | 35 | 20.9 KiB | 9.6 s |
| 455 | glm-5.3 | complex | tool_use | 0 | 121.5k | 464 | 21 | 9.8 KiB | 4.1 s |
| 456 | glm-5.3 | complex | tool_use | 0 | 122.2k | 1.0k | 18 | 9.3 KiB | 11.5 s |
| 457 | glm-5.3 | complex | tool_use | 0 | 124.0k | 93 | 18 | 7.4 KiB | 2.8 s |
| 458 | glm-5.3 | complex | tool_use | 0 | 124.3k | 457 | 17 | 7.3 KiB | 4.8 s |
| 459 | glm-5.3 | complex | tool_use | 0 | 125.2k | 128 | 8 | 2.8 KiB | 3.5 s |
| 460 | glm-5.3 | complex | - | 0 | 125.1k | 4.5k | 2123 | 729.8 KiB | 0 ms |
| 461 | glm-5.3 | complex | tool_use | 0 | 126.6k | 870 | 22 | 10.6 KiB | 14 ms |
| 462 | glm-5.3 | complex | tool_use | 0 | 127.4k | 51 | 3 | 1.1 KiB | 3.6 s |
| 463 | glm-5.3 | complex | - | 0 | 126.8k | 332 | 4 | 2.1 KiB | 0 ms |
| 464 | glm-5.3 | complex | tool_use | 0 | 127.5k | 218 | 12 | 4.7 KiB | 4.1 s |
| 465 | glm-5.3 | complex | - | 0 | 127.9k | 238 | 14 | 4.6 KiB | 0 ms |
| 466 | glm-5.3 | complex | tool_use | 0 | 128.2k | 103 | 2 | 1.3 KiB | 875 ms |
| 467 | glm-5.3 | complex | tool_use | 0 | 128.3k | 86 | 19 | 6.8 KiB | 3.2 s |
| 468 | glm-5.3 | complex | tool_use | 0 | 128.4k | 93 | 28 | 10.2 KiB | 8.4 s |
| 469 | glm-5.3 | complex | tool_use | 0 | 128.7k | 237 | 3 | 1.8 KiB | 3.6 s |
| 470 | glm-5.3 | complex | tool_use | 0 | 129.2k | 651 | 15 | 6.6 KiB | 5.0 s |
| 471 | glm-5.3 | complex | tool_use | 0 | 129.9k | 75 | 3 | 1.2 KiB | 4.0 s |
| 472 | glm-5.3 | complex | tool_use | 0 | 130.4k | 347 | 24 | 8.5 KiB | 4.0 s |
| 473 | glm-5.3 | complex | tool_use | 0 | 131.0k | 414 | 225 | 65.8 KiB | 6.0 s |
| 474 | glm-5.3 | complex | tool_use | 0 | 131.4k | 139 | 3 | 1.5 KiB | 3.0 s |
| 475 | glm-5.3 | complex | tool_use | 0 | 131.7k | 262 | 3 | 1.8 KiB | 3.1 s |
| 476 | glm-5.3 | complex | tool_use | 0 | 132.1k | 526 | 116 | 48.7 KiB | 10.7 s |
| 477 | glm-5.3 | complex | tool_use | 0 | 132.5k | 89 | 3 | 1.2 KiB | 3.0 s |
| 478 | glm-5.3 | complex | tool_use | 0 | 133.1k | 412 | 30 | 11.5 KiB | 4.0 s |
| 479 | glm-5.3 | complex | tool_use | 0 | 133.8k | 331 | 144 | 39.2 KiB | 52.9 s |
| 480 | glm-5.3 | complex | tool_use | 0 | 134.2k | 257 | 50 | 20.0 KiB | 5.1 s |
| 481 | glm-5.3 | complex | tool_use | 0 | 134.7k | 145 | 3 | 1.4 KiB | 5.2 s |
| 482 | glm-5.3 | complex | tool_use | 0 | 135.0k | 309 | 3 | 1.8 KiB | 3.6 s |
| 483 | glm-5.3 | complex | tool_use | 0 | 135.5k | 2.4k | 966 | 353.0 KiB | 25.4 s |
| 484 | glm-5.3 | complex | tool_use | 0 | 136.2k | 121 | 3 | 1.4 KiB | 10.7 s |
| 485 | glm-5.3 | complex | tool_use | 0 | 136.4k | 1.5k | 477 | 164.3 KiB | 11.4 s |
| 486 | glm-5.3 | complex | tool_use | 0 | 137.3k | 116 | 3 | 1.3 KiB | 2.9 s |
| 487 | glm-5.3 | complex | tool_use | 0 | 137.5k | 294 | 32 | 15.0 KiB | 4.1 s |
| 488 | glm-5.3 | complex | tool_use | 0 | 137.8k | 149 | 3 | 1.4 KiB | 2.7 s |
| 489 | glm-5.3 | complex | tool_use | 0 | 138.0k | 130 | 9 | 2.9 KiB | 4.4 s |
| 490 | glm-5.3 | complex | end_turn | 0 | 138.2k | 764 | 448 | 152.6 KiB | 8.0 s |
| 491 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 159.8k | 127 | 6 | 2.5 KiB | 10.4 s |
| 492 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 160.1k | 159 | 12 | 4.3 KiB | 2.6 s |
| 493 | deepseek-v4-pro:0813 | standard | - | 0 | 160.5k | 139 | 13 | 8.8 KiB | 0 ms |
| 494 | minimax-m3 | standard | tool_use | 0 | 74.0k | 95 | 81 | 28.0 KiB | 0 ms |
| 495 | glm-5.3 | complex | tool_use | 0 | 139.6k | 104 | 8 | 4.8 KiB | 10.7 s |
| 496 | glm-5.3 | complex | tool_use | 0 | 139.9k | 394 | 41 | 30.4 KiB | 7.8 s |
| 497 | glm-5.3 | complex | tool_use | 0 | 140.1k | 858 | 60 | 55.1 KiB | 10.8 s |
| 498 | glm-5.3 | complex | end_turn | 0 | 141.0k | 58 | 7 | 4.7 KiB | 3.3 s |
| 499 | glm-5.3-flash | complex | end_turn | 0 | 129.5k | 2.6k | 869 | 192.6 KiB | 33.2 s |
| 500 | glm-5.3 | complex | tool_use | 0 | 17.4k | 6.2k | 736 | 477.6 KiB | 1m 9s |
| 501 | glm-5.3 | complex | tool_use | 0 | 19.3k | 4.4k | 471 | 349.6 KiB | 52.6 s |
| 502 | glm-5.3 | complex | tool_use | 0 | 19.5k | 72 | 2 | 1.2 KiB | 4.0 s |
| 503 | glm-5.3 | complex | tool_use | 0 | 20.7k | 15.4k | 1396 | 1.15 MiB | 2m 55s |
| 504 | glm-5.3 | complex | tool_use | 0 | 21.8k | 287 | 24 | 16.5 KiB | 4.8 s |
| 505 | glm-5.3 | complex | tool_use | 0 | 22.2k | 1.9k | 193 | 141.4 KiB | 22.3 s |
| 506 | glm-5.3 | complex | tool_use | 0 | 22.5k | 150 | 2 | 1.6 KiB | 4.3 s |
| 507 | glm-5.3 | complex | tool_use | 0 | 22.8k | 826 | 66 | 49.9 KiB | 9.6 s |
| 508 | glm-5.3 | complex | tool_use | 0 | 23.2k | 513 | 37 | 33.1 KiB | 8.3 s |
| 509 | glm-5.3 | complex | - | 0 | 23.5k | 342 | 30 | 22.8 KiB | 0 ms |
| 510 | glm-5.3 | complex | end_turn | 0 | 23.7k | 805 | 66 | 53.4 KiB | 10.1 s |
| 511 | deepseek-v4-flash:0731 | simple | - | 0 | 15.5k | 54 | 3 | 2.0 KiB | 0 ms |
| 512 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 15.7k | 141 | 6 | 2.2 KiB | 1.7 s |
| 513 | deepseek-v4-flash:0731 | simple | - | 0 | 15.9k | 111 | 11 | 4.0 KiB | 0 ms |
| 514 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 16.1k | 92 | 2 | 1.1 KiB | 4 ms |
| 515 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 16.3k | 114 | 6 | 2.9 KiB | 1.4 s |
| 516 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 25.1k | 397 | 40 | 14.7 KiB | 2.8 s |
| 517 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 35.6k | 476 | 55 | 16.8 KiB | 23.1 s |
| 518 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 36.0k | 322 | 13 | 5.0 KiB | 2.1 s |
| 519 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 36.4k | 228 | 12 | 4.4 KiB | 4.4 s |
| 520 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 38.9k | 412 | 24 | 10.3 KiB | 6.1 s |
| 521 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 31.5k | 440 | 32 | 11.5 KiB | 3.5 s |
| 522 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 31.6k | 570 | 18 | 6.7 KiB | 3.2 s |
| 523 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 23.7k | 571 | 21 | 8.6 KiB | 4.2 s |
| 524 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 24.3k | 802 | 43 | 16.0 KiB | 4.2 s |
| 525 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 26.7k | 406 | 22 | 9.0 KiB | 2.2 s |
| 526 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 27.2k | 529 | 16 | 6.5 KiB | 2.6 s |
| 527 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 26.4k | 408 | 14 | 5.7 KiB | 2.5 s |
| 528 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 27.0k | 759 | 94 | 27.2 KiB | 3.9 s |
| 529 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 27.6k | 2.5k | 536 | 150.3 KiB | 13.2 s |
| 530 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 28.1k | 490 | 78 | 22.0 KiB | 3.9 s |
| 531 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 28.2k | 676 | 135 | 37.5 KiB | 4.1 s |
| 532 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 31.1k | 11.4k | 1528 | 402.7 KiB | 38.8 s |
| 533 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 37.2k | 109 | 3 | 1.3 KiB | 1.8 s |
| 534 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 37.8k | 142 | 2 | 1.4 KiB | 1.2 s |
| 535 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 38.1k | 107 | 2 | 1.3 KiB | 1.4 s |
| 536 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 38.2k | 119 | 2 | 1.3 KiB | 1.4 s |
| 537 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 38.5k | 118 | 3 | 1.3 KiB | 1.3 s |
| 538 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 38.6k | 290 | 56 | 16.9 KiB | 2.4 s |
| 539 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 40.3k | 4.2k | 114 | 45.0 KiB | 13.3 s |
| 540 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 44.3k | 311 | 51 | 14.7 KiB | 2.5 s |
| 541 | deepseek-v4-flash:0731 | simple | - | 0 | 44.5k | 93 | 10 | 3.5 KiB | 0 ms |
| 542 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 46.9k | 1.9k | 540 | 135.8 KiB | 9.7 s |
| 543 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 47.1k | 704 | 5 | 3.7 KiB | 3.3 s |
| 544 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 47.8k | 419 | 66 | 18.4 KiB | 46.8 s |
| 545 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 48.3k | 318 | 64 | 16.0 KiB | 2.4 s |
| 546 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 48.7k | 246 | 5 | 2.3 KiB | 2.2 s |
| 547 | deepseek-v4-flash:0731 | simple | tool_use | 0 | 49.2k | 126 | 2 | 1.4 KiB | 2.6 s |
| 548 | deepseek-v4-flash:0731 | simple | end_turn | 0 | 47.7k | 628 | 132 | 35.8 KiB | 3.9 s |
| 549 | deepseek-v4-pro:0813 | standard | - | 0 | 48.3k | 331 | 57 | 16.5 KiB | 0 ms |
| 550 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 50.5k | 462 | 95 | 26.2 KiB | 4 ms |
| 551 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 46.1k | 282 | 47 | 15.0 KiB | 5 ms |
| 552 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 48.5k | 315 | 55 | 17.0 KiB | 3.8 s |
| 553 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 47.4k | 181 | 23 | 6.5 KiB | 1.8 s |
| 554 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 45.9k | 431 | 83 | 23.4 KiB | 3.6 s |
| 555 | deepseek-v4-pro:0813 | standard | - | 0 | 47.0k | 155 | 16 | 5.7 KiB | 0 ms |
| 556 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 48.7k | 1.3k | 362 | 90.2 KiB | 4 ms |
| 557 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 48.7k | 165 | 17 | 6.0 KiB | 4 ms |
| 558 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 48.5k | 210 | 32 | 10.4 KiB | 3 ms |
| 559 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 48.9k | 200 | 26 | 8.7 KiB | 4 ms |
| 560 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 46.7k | 180 | 32 | 10.1 KiB | 2.4 s |
| 561 | deepseek-v4-pro:0813 | standard | - | 0 | 47.3k | 141 | 12 | 4.2 KiB | 0 ms |
| 562 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 48.2k | 341 | 74 | 20.7 KiB | 5 ms |
| 563 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 50.5k | 149 | 17 | 5.9 KiB | 5 ms |
| 564 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 48.7k | 217 | 33 | 8.6 KiB | 4.4 s |
| 565 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 50.3k | 4.5k | 1006 | 250.8 KiB | 24.9 s |
| 566 | deepseek-v4-pro:0813 | standard | - | 0 | 50.2k | 182 | 19 | 6.5 KiB | 0 ms |
| 567 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 48.1k | 194 | 23 | 8.6 KiB | 4 ms |
| 568 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 48.6k | 203 | 25 | 8.3 KiB | 1.9 s |
| 569 | deepseek-v4-pro:0813 | standard | - | 0 | 50.3k | 502 | 109 | 28.2 KiB | 0 ms |
| 570 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 50.8k | 212 | 38 | 9.7 KiB | 4 ms |
| 571 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 51.0k | 210 | 28 | 9.7 KiB | 4 ms |
| 572 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 48.7k | 600 | 127 | 34.1 KiB | 5 ms |
| 573 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 49.7k | 628 | 154 | 37.4 KiB | 5.1 s |
| 574 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 49.8k | 378 | 84 | 21.7 KiB | 3.0 s |
| 575 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 52.3k | 717 | 161 | 42.0 KiB | 5.2 s |
| 576 | deepseek-v4-pro:0813 | standard | - | 0 | 54.8k | 2.5k | 614 | 152.8 KiB | 0 ms |
| 577 | deepseek-v4-pro:0813 | standard | tool_use | 0 | 0 | 0 | 86 | 23.1 KiB | 2 ms |

## 8. Error-level events

| Event | Count |
|---|---|
| rag.embed | 8 |

**Samples:**

```
2026-09-08T17:35:41.097 rag rag.embed: unavailable: embed failed — endpoint unreachable or model missing; using BM25
2026-09-08T20:46:43.134 rag rag.embed: unavailable: embed failed — endpoint unreachable or model missing; using BM25
2026-09-08T20:53:26.788 rag rag.embed: unavailable: embed failed — endpoint unreachable or model missing; using BM25
2026-09-09T09:58:27.968 rag rag.embed: unavailable: embed failed — endpoint unreachable or model missing; using BM25
2026-09-09T11:10:39.732 rag rag.embed: unavailable: embed failed — endpoint unreachable or model missing; using BM25
2026-09-09T12:01:27.940 rag rag.embed: unavailable: embed failed — endpoint unreachable or model missing; using BM25
2026-09-09T18:49:20.891 rag rag.embed: unavailable: embed failed — endpoint unreachable or model missing; using BM25
2026-09-09T21:19:48.142 rag rag.embed: unavailable: embed failed — endpoint unreachable or model missing; using BM25
```

## 9. Persistence

- Thread saves: 587
- Total messages persisted: 70183
- Avg messages per save: 119

---
*Generated by agentty-stats.*
