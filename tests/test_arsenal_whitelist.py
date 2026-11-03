"""Tests for the ACE arsenal whitelist (a pure data function).

fn_arsenalWhitelist.sqf returns [standardArsenal, psoArsenal, limitedArsenal] —
three lists of classnames. These guard against the copy-paste mistakes that are
easy to make in a long hand-maintained list (e.g. the duplicate rhs_weap_m32
entry).
"""
from harness import run_sqf, test

WHITELIST = "addons/PTF_Scripts/fnc/arsenal/fn_arsenalWhitelist.sqf"

# The head-mounted night vision the Limited Arsenal must not offer — mirrors the
# _nightvision sub-array in the whitelist. If you add an NVG there, add it here
# too; the "minus exactly the NVGs" test below will tell you if you forget.
NIGHTVISION = [
    "USP_PVS14",
    "USP_PVS15",
    "USP_PVS31_COMPACT",
    "rhsusf_ANPVS_14",
    "rhsusf_ANPVS_15",
    "PTF_Nightvision_PVS15_WP",
    "PTF_Nightvision_PVS15_GN",
    "USP_PVS31_WP_MID_TAN",
    "USP_PVS31_WP_MID",
    # Clip-on night weapon sight, not goggles — grouped with the NVGs so the
    # Limited Arsenal drops it too.
    "rhsusf_acc_premier_anpvs27",
]


@test("arsenal whitelist returns [standard, pso, limited]")
def _returns_triple():
    result = run_sqf(WHITELIST)
    assert isinstance(result, list) and len(result) == 3, \
        f"expected a 3-element array, got {result!r}"


@test("all three arsenals are non-empty lists of strings")
def _non_empty_strings():
    standard, pso, limited = run_sqf(WHITELIST)
    for label, arsenal in (("standard", standard), ("pso", pso), ("limited", limited)):
        assert arsenal, f"{label} arsenal is empty"
        bad = [x for x in arsenal if not isinstance(x, str)]
        assert not bad, f"{label} arsenal has non-string entries: {bad}"


@test("no duplicate classnames in the standard arsenal")
def _no_duplicates():
    standard, _pso, _limited = run_sqf(WHITELIST)
    dups = sorted({x for x in standard if standard.count(x) > 1})
    assert not dups, f"duplicate whitelist entries: {dups}"


@test("pso arsenal is a superset of the standard arsenal")
def _pso_superset():
    standard, pso, _limited = run_sqf(WHITELIST)
    missing = [x for x in standard if x not in pso]
    assert not missing, f"pso arsenal is missing standard entries: {missing[:5]}"


@test("limited arsenal offers no night vision goggles")
def _limited_has_no_nvgs():
    _standard, _pso, limited = run_sqf(WHITELIST)
    found = sorted({x for x in limited if x in NIGHTVISION})
    assert not found, f"limited arsenal still offers NVGs: {found}"


@test("limited arsenal is the standard arsenal minus exactly the NVGs")
def _limited_is_standard_minus_nvgs():
    standard, _pso, limited = run_sqf(WHITELIST)
    removed = sorted(set(standard) - set(limited))
    expected = sorted(set(NIGHTVISION))
    assert removed == expected, (
        "limited arsenal should differ from standard by the NVGs alone; "
        f"removed={removed} expected={expected} "
        "(update NIGHTVISION here if _nightvision changed)"
    )
    extra = sorted(set(limited) - set(standard))
    assert not extra, f"limited arsenal has entries not in standard: {extra}"
