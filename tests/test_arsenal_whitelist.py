"""Tests for the ACE arsenal whitelist (a pure data function).

fn_arsenalWhitelist.sqf returns [standardArsenal, psoArsenal] — two lists of
classnames. These guard against the copy-paste mistakes that are easy to make
in a long hand-maintained list (e.g. the duplicate rhs_weap_m32 entry).
"""
from harness import run_sqf, test

WHITELIST = "addons/PTF_Scripts/fnc/arsenal/fn_arsenalWhitelist.sqf"


@test("arsenal whitelist returns [standard, pso]")
def _returns_pair():
    result = run_sqf(WHITELIST)
    assert isinstance(result, list) and len(result) == 2, \
        f"expected a 2-element array, got {result!r}"


@test("both arsenals are non-empty lists of strings")
def _non_empty_strings():
    standard, pso = run_sqf(WHITELIST)
    for label, arsenal in (("standard", standard), ("pso", pso)):
        assert arsenal, f"{label} arsenal is empty"
        bad = [x for x in arsenal if not isinstance(x, str)]
        assert not bad, f"{label} arsenal has non-string entries: {bad}"


@test("no duplicate classnames in the standard arsenal")
def _no_duplicates():
    standard, _pso = run_sqf(WHITELIST)
    dups = sorted({x for x in standard if standard.count(x) > 1})
    assert not dups, f"duplicate whitelist entries: {dups}"


@test("pso arsenal is a superset of the standard arsenal")
def _pso_superset():
    standard, pso = run_sqf(WHITELIST)
    missing = [x for x in standard if x not in pso]
    assert not missing, f"pso arsenal is missing standard entries: {missing[:5]}"
