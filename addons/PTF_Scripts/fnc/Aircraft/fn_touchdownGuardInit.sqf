/*
 * PTF_fnc_touchdownGuardInit
 * Touchdown guard: give one aircraft the damage handler that stops gentle
 * landings from destroying it (PTF_fnc_touchdownGuardDamage). Run on every machine
 * for every aircraft, from the "Air" init class event in XEH_postInit.sqf:
 * HandleDamage only fires where the aircraft is local, and that changes with
 * whoever is flying it.
 *
 * Arguments:
 * 0: The aircraft <OBJECT>
 *
 * Return Value:
 * None
 */
params ["_vehicle"];

if (!isNil {_vehicle getVariable "PTF_touchdownGuard_eh"}) exitWith {};
_vehicle setVariable ["PTF_touchdownGuard_eh", -1];

// When several HandleDamage handlers return a value, the last one added wins. A
// frame late puts this one after anything another mod adds in the same init, as
// ACE does for its own vehicle damage handler.
[{
	params ["_vehicle"];
	if (isNull _vehicle) exitWith {};
	_vehicle setVariable ["PTF_touchdownGuard_eh", _vehicle addEventHandler ["HandleDamage", {call PTF_fnc_touchdownGuardDamage}]];
	PTF_touchdownGuard_aircraft pushBack _vehicle;
}, [_vehicle]] call CBA_fnc_execNextFrame;
