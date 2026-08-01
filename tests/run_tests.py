#!/usr/bin/env python3
"""Discover and run every tests/test_*.py case. Exit non-zero if any fail.

Run locally:   python tests/run_tests.py
CI runs the same command (see .github/workflows/hemtt.yml).
"""
import glob
import importlib.util
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

import harness  # noqa: E402  (must be after sys.path tweak)


def _load_test_modules():
    for path in sorted(glob.glob(os.path.join(HERE, "test_*.py"))):
        name = os.path.splitext(os.path.basename(path))[0]
        spec = importlib.util.spec_from_file_location(name, path)
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)


def main():
    _load_test_modules()
    if not harness.REGISTRY:
        print("No tests found.")
        return 0

    passed = failed = 0
    for name, fn in harness.REGISTRY:
        try:
            fn()
        except AssertionError as exc:
            print(f"  FAIL   {name}: {exc}")
            failed += 1
        except Exception as exc:  # noqa: BLE001 — surface interpreter errors too
            print(f"  ERROR  {name}: {type(exc).__name__}: {exc}")
            failed += 1
        else:
            print(f"  PASS   {name}")
            passed += 1

    print(f"\n{passed} passed, {failed} failed")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
