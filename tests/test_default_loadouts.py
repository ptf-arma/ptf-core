"""Tests for the ACE arsenal default loadouts (a pure data file).

defaultloadouts.hpp is a bare array of [name, loadout] pairs. It feeds two
things now, not one: the arsenal's default-loadout list, and the
PTF_RespawnLoadoutName setting that picks the forced respawn kit. A malformed
entry used to cost you one broken preset in the arsenal; it can now break the
respawn setting for the whole server, so the shape is worth asserting.
"""
from harness import run_sqf, test

LOADOUTS = "addons/PTF_Scripts/fnc/arsenal/defaultloadouts.hpp"


@test("default loadouts parse as a non-empty list of pairs")
def _pairs():
    entries = run_sqf(LOADOUTS)
    assert isinstance(entries, list) and entries, f"expected a non-empty array, got {entries!r}"
    bad = [e for e in entries if not isinstance(e, list) or len(e) != 2]
    assert not bad, f"{len(bad)} entries are not [name, loadout] pairs"


@test("loadout names are unique non-empty strings")
def _names():
    names = [e[0] for e in run_sqf(LOADOUTS)]
    bad = [n for n in names if not isinstance(n, str) or not n.strip()]
    assert not bad, f"bad loadout names: {bad}"
    dups = sorted({n for n in names if names.count(n) > 1})
    assert not dups, f"duplicate loadout names: {dups}"


@test("every loadout is a bare unit loadout or an [loadout, extendedInfo] pair")
def _shape():
    # CBA_fnc_setLoadout early-exits on `count _loadout == 10` and otherwise
    # destructures into [loadoutArray, extendedInfo] -- anything else silently
    # applies nothing at all.
    bad = []
    for name, loadout in run_sqf(LOADOUTS):
        if not isinstance(loadout, list):
            bad.append((name, "not an array"))
        elif len(loadout) == 10:
            continue
        elif len(loadout) == 2 and isinstance(loadout[0], list) and len(loadout[0]) == 10:
            continue
        else:
            bad.append((name, f"{len(loadout)} elements"))
    assert not bad, f"loadouts CBA_fnc_setLoadout would ignore: {bad}"


@test("the respawn setting's default kit exists")
def _default_kit_exists():
    # XEH_preInit.sqf selects "Rifleman D" as the default index of the
    # PTF_RespawnLoadoutName list; renaming it silently defaults to "Empty".
    names = [e[0] for e in run_sqf(LOADOUTS)]
    assert "Rifleman D" in names, f'"Rifleman D" is gone; update XEH_preInit.sqf. Have: {names[:5]}...'
