/*
 * Author: Paramarine Task Force
 * Counter-battery, at the gun: every weapon fired (an XEH FiredBIS handler on all vehicles and
 * men) passes through here. Only indirect fire matters: mortar, artillery and rocket rounds,
 * either ammo the artillery computer can lock (artilleryLock) or a shell, rocket or
 * submunition fired by a vehicle with an artillery computer (artilleryScanner). Each one is
 * watched in flight on the machine that fired it (its projectile is local there,
 * PTF_GATOR_fnc_cbWatch). The moment it is within CB_DETECT metres of a transmitting G/ATOR and
 * in its line of sight, in the air, that G/ATOR traces it (PTF_GATOR_fnc_cbReport on the
 * server); where it lands follows when it does (PTF_GATOR_fnc_cbImpact).
 *
 * It costs one variable check per shot while no G/ATOR is transmitting, and two hashmap
 * lookups per shot otherwise (is it indirect fire; is it a guided missile, for
 * PTF_GATOR_fnc_armWatch).
 *
 * Arguments: the FiredBIS event's
 *
 * Return Value:
 * None
 */
#include "..\script_gator.hpp"
params ["_unit", "", "", "", "_ammo", "", "_projectile", "_gunner"];

if ((missionNamespace getVariable ["PTF_GATOR_cbRadars", []]) isEqualTo []) exitWith {};
if (isNull _projectile) exitWith {};
private _shooter = [_gunner, _unit] select (isNull _gunner);
if (!local _shooter) exitWith {};

private _cache = missionNamespace getVariable "PTF_GATOR_cbIndirect";
if (isNil "_cache") then {
	_cache = createHashMap;
	missionNamespace setVariable ["PTF_GATOR_cbIndirect", _cache];
};
// A guided missile: an anti-radiation missile may be homing on a G/ATOR (PTF_GATOR_fnc_armWatch,
// which knows next frame, once it has its target).
if (_cache getOrDefaultCall ["m:" + _ammo, {toLowerANSI getText (configFile >> "CfgAmmo" >> _ammo >> "simulation") == "shotmissile"}, true]) then {
	[PTF_GATOR_fnc_armWatch, [_projectile]] call CBA_fnc_execNextFrame;
};
private _indirect = _cache getOrDefaultCall [typeOf _unit + ":" + _ammo, {
	private _config = configFile >> "CfgAmmo" >> _ammo;
	toLowerANSI getText (_config >> "simulation") in ["shotshell", "shotsubmunitions", "shotrocket", "shotmissile"]
		&& {getNumber (_config >> "artilleryLock") == 1 || {getNumber (configOf _unit >> "artilleryScanner") == 1}}
}, true];
if (!_indirect) exitWith {};

// [projectile, fired from (ASL), fired at, ammo, G/ATORs that saw it, last seen (ASL), its key, mortar or artillery]
private _flights = missionNamespace getVariable ["PTF_GATOR_cbFlights", []];
private _n = (missionNamespace getVariable ["PTF_GATOR_cbShot", 0]) + 1;
missionNamespace setVariable ["PTF_GATOR_cbShot", _n];
_flights pushBack [_projectile, getPosASL _unit, CBA_missionTime, _ammo, [], getPosASL _projectile, format ["%1.%2", clientOwner, _n],
	["artillery", "mortar"] select (_unit isKindOf "StaticMortar")];
missionNamespace setVariable ["PTF_GATOR_cbFlights", _flights];
if (missionNamespace getVariable ["PTF_GATOR_cbWatching", false]) exitWith {};
missionNamespace setVariable ["PTF_GATOR_cbWatching", true];

// Ten times a second (PTF_GATOR_fnc_cbWatch), until none of this machine's rounds are up.
[{
	params ["", "_handle"];
	if ((call PTF_GATOR_fnc_cbWatch) == 0) then {
		missionNamespace setVariable ["PTF_GATOR_cbWatching", false];
		[_handle] call CBA_fnc_removePerFrameHandler;
	};
}, 0.1, []] call CBA_fnc_addPerFrameHandler;
