# SQF unit tests

These run **pure** SQF logic/data functions outside the game, using the
[`sqflint`](https://github.com/LordGolias/sqf) interpreter, so mistakes in them
get caught in CI instead of in-game. They can't test anything that touches the
engine (units, world, UI, most `PTF_fnc_*` action scripts) — only self-contained
functions like the arsenal whitelist.

## Run them

```sh
pip install sqflint      # once
python tests/run_tests.py
```

CI runs the exact same command on every PR (see `.github/workflows/hemtt.yml`).

## Add a test

1. Create `tests/test_<thing>.py`.
2. Interpret the SQF function with `run_sqf()` — it returns the function's value
   as ordinary Python (lists/strings/numbers), then assert on it in Python:

```python
from harness import run_sqf, test

@test("my helper returns a non-empty list")
def _check():
    result = run_sqf("addons/PTF_Scripts/fnc/foo/fn_myHelper.sqf")
    assert result, "expected a non-empty result"
```

`run_tests.py` auto-discovers every `test_*.py` and every `@test(...)` in it.

## Limits of the interpreter

The VM implements common commands (`count`, `select`, `in`, `forEach`,
`pushBackUnique`, arithmetic/comparison) but **not** everything (`typeName`,
`arrayIntersect`, `select` with a code filter, the `!` operator, and any engine
command are unsupported). Keep the function under test pure, and do the
richer checks in Python on the returned value rather than in SQF.
