/*
 * Author: Paramarine Task Force
 * Lowers or raises one of a G/ATOR's four leveling legs. Runs on the server (called anywhere).
 *
 * A lowered leg runs down until its foot meets the ground, however far that is within its
 * reach. Once all four are down the trailer levels itself on them (PTF_GATOR_fnc_level).
 * Raising a leg first settles a leveled trailer back onto its wheels.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Leg: "fl", "fr", "rl" or "rr" <STRING>
 * 2: Lower (true) or raise (false) <BOOL> (default: true)
 * 3: Instantly, skipping the checks <BOOL> (default: false)
 *
 * Return Value:
 * Started <BOOL>
 *
 * Example:
 * [_radar, "fl", true] call PTF_GATOR_fnc_setLeg
 */
#include "..\script_gator.hpp"
params [["_radar", objNull, [objNull]], ["_leg", "", [""]], ["_down", true, [true]], ["_instant", false, [false]]];

if (isNull _radar || {!(_leg in LEGS)}) exitWith {false};
if (!_instant && {!([_radar, _leg, _down] call PTF_GATOR_fnc_canSetLeg)}) exitWith {false};
if (!isServer) exitWith {
	[_radar, _leg, _down, _instant] remoteExecCall ["PTF_GATOR_fnc_setLeg", 2];
	true
};

private _source = "ptf_gator_leg_" + _leg;
_radar setVariable ["PTF_GATOR_legHalt_" + _leg, false, true];
if (_down) then {
	private _phase = ([_radar, _leg] call PTF_GATOR_fnc_legReach) max 0.05 min LEG_MAX_PHASE;
	_radar setVariable ["PTF_GATOR_legTarget_" + _leg, _phase, true];
	_radar animateSource [_source, _phase, _instant];
	// Level up once all four stand on the ground.
	if (_instant) then {
		if ([_radar] call PTF_GATOR_fnc_legsDown) then {[_radar, true, true] call PTF_GATOR_fnc_level};
	} else {
		[{
			params ["_radar"];
			isNull _radar || {[_radar] call PTF_GATOR_fnc_legsDown}
		}, {
			params ["_radar"];
			if (!isNull _radar && {alive _radar}) then {[_radar, true] call PTF_GATOR_fnc_level};
		}, [_radar], LEG_PERIOD * LEG_MAX_PHASE + 2] call CBA_fnc_waitUntilAndExecute;
	};
} else {
	// (unless the player let go while the trailer settled: PTF_GATOR_fnc_halt)
	[_radar, false, _instant, compile format ["
		if (_this getVariable ['PTF_GATOR_legHalt_%1', false]) exitWith {};
		_this setVariable ['PTF_GATOR_legTarget_%1', 0, true];
		_this animateSource ['%2', 0, %3];
	", _leg, _source, _instant]] call PTF_GATOR_fnc_level;
};
true
