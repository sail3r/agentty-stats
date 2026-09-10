# agentty — Session Statistics Report

**Sources:** `logs/2026-09-10__06:03:34UTC__debug.log`, `logs/2026-09-10__08:21:03UTC__debug.log`, `logs/2026-09-10__09:20:28UTC__debug.log`

**Generated:** 2026-09-10T14:49:51.406

---

## 1. Overview

| Metric | Value |
|---|---|
| Total turns (dispatches) | 135 |
| Time span | 2026-09-10T09:04:36.154 → 2026-09-10T14:49:51.406 (345m 15s) |
| Models used | glm-5.3, glm-5.3-flash, kimi-k3, minimax-m3 |
| Total prompt tokens | 11.08M (11076512) |
| Total completion tokens | 47.4k (47367) |
| Total tokens | 11.12M |
| Estimated cost | n/a |
| Wire chunks | 8491 (2.27 MiB) |
| Request bytes | 39.96 MiB |
| Tool calls | 129 |
| Thread saves | 261 (56546 messages) |
| Models loaded | 2026-09-10__06:03:34UTC__debug.log=n/a; 2026-09-10__08:21:03UTC__debug.log=n/a; 2026-09-10__09:20:28UTC__debug.log=19 |
| Source files | 3 (43.27 MiB total)
<br>2026-09-10__06:03:34UTC__debug.log 21.84 MiB<br>2026-09-10__08:21:03UTC__debug.log 19.05 MiB<br>2026-09-10__09:20:28UTC__debug.log 2.37 MiB |
| Error-level events | 123 (136 routine auth) |

## 2. Log volume

### By level

| Level | Count |
|---|---|
| T | 8626 |
| D | 1073 |
| E | 259 |
| I | 14 |
| W | 3 |

### By component

| Component | Count |
|---|---|
| wire | 9310 |
| persist | 261 |
| model | 135 |
| smart | 135 |
| tool | 129 |
| ui | 3 |
| general | 1 |
| rag | 1 |

### By event

| Event | Count |
|---|---|
| wire.chunk | 8491 |
| thread.save | 261 |
| stream.end | 137 |
| stream.response | 137 |
| stream.result | 137 |
| openai.auth | 136 |
| dispatch.turn | 135 |
| openai.request | 135 |
| openai.request.body | 135 |
| route.turn | 135 |
| tool.exec | 129 |
| paste.recv | 3 |
| models.loaded | 1 |
| provider.select | 1 |
| rag.embed | 1 |
| startup | 1 |

## 3. Smart-mode routing

### Role

| Role | Turns | % of total |
|---|---|---|
| utility | 60 | 44.4 |
| none | 53 | 39.3 |
| strategic | 21 | 15.6 |
| implementation | 1 | 0.7 |

### Complexity

| Complexity | Turns | % of total |
|---|---|---|
| standard | 53 | 39.3 |
| trivial | 52 | 38.5 |
| complex | 22 | 16.3 |
| simple | 8 | 5.9 |

### Orchestration flags

- Orchestrate: 83 / 135 turns
- Subagents: 83 / 135 turns
- Compacting: 2 / 135 turns

## 4. Per-model usage

| Model | Turns | Prompt tok | Completion tok | Total tok | Req bytes | Chunk bytes | Chunks | Retried | Errors |
|---|---|---|---|---|---|---|---|---|---|
| kimi-k3 | 72 | 6.33M | 14.8k | 6.34M | 21.42 MiB | 756.5 KiB | 2043 | 0 | 0 |
| glm-5.3-flash | 61 | 4.62M | 29.5k | 4.65M | 18.10 MiB | 1.45 MiB | 6227 | 0 | 0 |
| glm-5.3 | 1 | 22.2k | 332 | 22.5k | 84.6 KiB | 49.3 KiB | 128 | 0 | 0 |
| minimax-m3 | 1 | 102.6k | 2.7k | 105.4k | 371.8 KiB | 23.7 KiB | 66 | 0 | 0 |

## 4b. Cost (USD)

*Prices from [models.dev](https://models.dev), loaded from `