"""Tiny SQF unit-test harness for PTF Core.

It runs a PURE SQF function through the sqflint interpreter (a limited SQF VM,
no game engine) and hands you back the return value as ordinary Python objects
so you can assert on it. This only works for functions that don't call engine
commands (world state, units, UI) — data/logic helpers like the arsenal
whitelist. See tests/README.md for how to add a test.
"""
import os

import sqf.interpreter
import sqf.types

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# Registered test cases: list of (name, callable). Populated by the @test decorator.
REGISTRY = []


def test(name):
    """Decorator: register a function as a named test case."""
    def deco(fn):
        REGISTRY.append((name, fn))
        return fn
    return deco


def _to_py(value):
    """Convert an sqflint result (Array/String/Number/Boolean/...) to Python."""
    if isinstance(value, sqf.types.Array):
        return [_to_py(x) for x in value.value]
    return getattr(value, "value", value)


def run_sqf(rel_path):
    """Interpret a .sqf file (path relative to the repo root) and return its
    result value as native Python (lists, strings, numbers, bools)."""
    with open(os.path.join(REPO, rel_path), encoding="utf-8") as fh:
        code = fh.read()
    _interp, outcome = sqf.interpreter.interpret(code)
    return _to_py(outcome)
