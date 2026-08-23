// Hand the PTF role kits to ACE as arsenal default loadouts.
//
// Called from all three arsenal inits, so it runs for every arsenal and crate
// on the map and has to be idempotent and cheap. Until 2026-08 this was an
// #include of defaultloadouts.hpp in each of those functions, which re-pushed
// all 50 kits through ace_arsenal_fnc_addDefaultLoadout per box. That was only
// ever wasteful rather than wrong -- ACE overwrites by name -- but on a map
// with a few dozen crates it is 30 KB of array literal evaluated a few dozen
// times for no effect.
//
// The kit list itself is built once at preInit; see XEH_preInit.sqf.

if (missionNamespace getVariable ["PTF_defaultLoadoutsRegistered", false]) exitWith {};

{
    _x params ["_name", "_loadout"];
    [_name, _loadout] call ace_arsenal_fnc_addDefaultLoadout;
} forEach (missionNamespace getVariable ["PTF_defaultLoadouts", []]);

missionNamespace setVariable ["PTF_defaultLoadoutsRegistered", true];
