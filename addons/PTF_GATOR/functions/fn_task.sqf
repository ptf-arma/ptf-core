/*
 * Author: Paramarine Task Force
 * A setup job at the G/ATOR, done by hand: the ACE actions call this. The player works it for
 * exactly as long as the trailer takes to do it (an ACE progress bar timed from the animation:
 * its distance to go times its animPeriod), so setting up is a crew's job, several people at
 * once (each leg is its own job). Let go part way and it stops where it is: a leg or the array
 * halts (PTF_GATOR_fnc_halt) and can be finished, or reversed, later; a generator start fails
 * and the generator stops again. With the server setting "Setting up takes time" off
 * (PTF_GATOR_setupTime) each job happens on the spot, the animation running on its own.
 *
 *   "legDown", "legUp"  a leg (3rd argument): its reach (or what it has to come up, plus the
 *                       LEVEL_TIME settle back onto the wheels when the trailer is leveled)
 *                       at LEG_PERIOD seconds per unit of phase
 *   "raise", "lower"    the array: what it has to travel at ARRAY_PERIOD seconds end to end
 *   "power"             starting the generator: ptf_gator_powerStartTime
 *   "stow"              reeling the SATCOM antenna's cable in: STOW_TIME
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Job <STRING>
 * 2: Leg: "fl", "fr", "rl" or "rr" <STRING> (default: "")
 *
 * Return Value:
 * None
 *
 * Example:
 * [_radar, "legDown", "fl"] call PTF_GATOR_fnc_task
 */
#include "..\script_gator.hpp"
#define ARRAY_PERIOD 32
#define STOW_TIME 6

params [["_radar", objNull, [objNull]], ["_job", "", [""]], ["_leg", "", [""]]];

private _timed = missionNamespace getVariable ["PTF_GATOR_setupTime", true];
private _time = 0;
private _title = "";
private _onFail = {};
switch (_job) do {
	case "legDown": {
		if !([_radar, _leg, true] call PTF_GATOR_fnc_setLeg) exitWith {_job = ""};
		_time = (([_radar, _leg] call PTF_GATOR_fnc_legReach) max 0.05 min LEG_MAX_PHASE) * LEG_PERIOD;
		_title = "Lowering the leg";
		_onFail = {params ["_args"]; _args params ["_radar", "_leg"]; [_radar, "leg", _leg] call PTF_GATOR_fnc_halt};
	};
	case "legUp": {
		// Up from where it comes to rest on the trailer's wheels (it settles there first if leveled).
		private _leveled = _radar getVariable ["PTF_GATOR_leveled", false];
		private _from = if (_leveled) then {
			((_radar getVariable ["PTF_GATOR_restPhases", []]) param [LEGS find _leg, 1])
		} else {
			_radar animationSourcePhase ("ptf_gator_leg_" + _leg)
		};
		if !([_radar, _leg, false] call PTF_GATOR_fnc_setLeg) exitWith {_job = ""};
		_time = _from * LEG_PERIOD + ([0, LEVEL_TIME] select _leveled);
		_title = "Raising the leg";
		_onFail = {params ["_args"]; _args params ["_radar", "_leg"]; [_radar, "leg", _leg] call PTF_GATOR_fnc_halt};
	};
	case "raise";
	case "lower": {
		private _up = _job == "raise";
		private _phase = _radar animationSourcePhase "ptf_gator_deploy";
		if !([_radar, _up] call PTF_GATOR_fnc_setDeployed) exitWith {_job = ""};
		_time = abs (([0, 1] select _up) - _phase) * ARRAY_PERIOD;
		_title = ["Lowering the array", "Raising the array"] select _up;
		_onFail = {params ["_args"]; [_args select 0, "array"] call PTF_GATOR_fnc_halt};
	};
	case "power": {
		if !([_radar, true] call PTF_GATOR_fnc_setPower) exitWith {_job = ""};
		_time = getNumber (configOf _radar >> "ptf_gator_powerStartTime");
		_title = "Starting the generator";
		// let go before it caught: it dies again (and is heard stopping)
		_onFail = {
			params ["_args"];
			(_args select 0) setVariable ["PTF_GATOR_powerOn", false, true];
			(_args select 0) setVariable ["PTF_GATOR_powerTime", CBA_missionTime, true];
		};
	};
	case "stow": {
		if (!_timed) exitWith {[_radar, "stow"] call PTF_GATOR_fnc_satcom};
		_time = STOW_TIME;
		_title = "Reeling in the SATCOM cable";
	};
	default {_job = ""};
};
if (_job == "" || {!_timed} || {_time < 0.5}) exitWith {};

[_time, [_radar, _leg, _job], {
	params ["_args"];
	_args params ["_radar", "", "_job"];
	if (_job == "stow") then {[_radar, "stow"] call PTF_GATOR_fnc_satcom};
}, _onFail, _title, {
	params ["_args"];
	_args params ["_radar"];
	alive _radar && {ACE_player distance _radar < 9}
}] call ace_common_fnc_progressBar;
