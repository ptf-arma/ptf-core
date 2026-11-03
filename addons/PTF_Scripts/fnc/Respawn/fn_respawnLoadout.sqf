// Give a respawning player the server's chosen PTF role kit.
//
// Why this exists: respawn does not restore a unit, it builds a new one from
// the config of the playable slot's class. Gear applied in Eden, at mission
// start or out of an arsenal is not part of that class, so the player comes
// back in whatever that class declares -- and since PTF Core defines no BLUFOR
// man classes (unlike PTF_OPFOR, which bakes kit into config), that is a
// vanilla or stock RHS kit.
//
// Called a frame after EntityRespawned; see XEH_postInit.sqf.

params ["_unit"];

if (isNull _unit) exitWith {};
if (!alive _unit) exitWith {};        // died again inside the frame we waited
if (!local _unit) exitWith {};        // setUnitLoadout has to run where the unit is local

// Server-forced, off by default: nothing changes on any server until someone
// deliberately turns it on.
if !(missionNamespace getVariable ["PTF_RespawnLoadoutEnabled", false]) exitWith {};

// Mission opt-out. A mission that owns its own respawn gear -- an
// onPlayerRespawn.sqf, respawnTemplates[] = {"MenuInventory"}, or a training
// map that wants the Eden slot's kit -- sets this in init.sqf and PTF Core
// stays out of the way. Without it, turning the setting on would silently
// overwrite the respawn handling of every mission on the server.
if (missionNamespace getVariable ["PTF_RespawnLoadoutDisabled", false]) exitWith {};

private _name = missionNamespace getVariable ["PTF_RespawnLoadoutName", ""];
private _loadouts = missionNamespace getVariable ["PTF_defaultLoadoutsMap", createHashMap];
private _loadout = _loadouts getOrDefault [_name, []];

// Only reachable if a kit was renamed or removed from defaultloadouts.hpp while
// a server still had it selected. Leave the player alone and say so, rather
// than stripping them.
if (_loadout isEqualTo []) exitWith {
    diag_log text format [
        "[PTF] Respawn loadout '%1' is not a known PTF kit - %2 keeps the config kit of %3.",
        _name, name _unit, typeOf _unit
    ];
};

// fullMagazines: the kits are authored full, so this only tops up anything
// saved partially loaded. A forced respawn kit should never start dry.
[_unit, _loadout, true] call CBA_fnc_setLoadout;
