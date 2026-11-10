/*
 * Author: Paramarine Task Force
 * Stops a leg or the array where it is, when the player working it lets go part way
 * (PTF_GATOR_fnc_task). Runs on the server (called anywhere). A halted leg counts as down
 * (out, though perhaps not on the ground): it can be raised, and the trailer still levels
 * once all four are out (the leveling runs every leg to the ground). A halted array can be
 * raised or lowered from there. A leg halted while the trailer settles back onto its wheels
 * stays where it is when the settling ends.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: "leg" or "array" <STRING>
 * 2: Leg: "fl", "fr", "rl" or "rr" <STRING> (default: "")
 *
 * Return Value:
 * None
 *
 * Example:
 * [_radar, "leg", "fl"] call PTF_GATOR_fnc_halt
 */
params [["_radar", objNull, [objNull]], ["_what", "", [""]], ["_leg", "", [""]]];

if (!isServer) exitWith {[_radar, _what, _leg] remoteExecCall ["PTF_GATOR_fnc_halt", 2]};
if (isNull _radar) exitWith {};

if (_what == "array") exitWith {
	_radar animateSource ["ptf_gator_deploy", _radar animationSourcePhase "ptf_gator_deploy", true];
};
if (_what == "leg" && {_leg in ["fl", "fr", "rl", "rr"]}) then {
	private _source = "ptf_gator_leg_" + _leg;
	private _phase = _radar animationSourcePhase _source;
	_radar setVariable ["PTF_GATOR_legHalt_" + _leg, true, true];
	_radar setVariable ["PTF_GATOR_legTarget_" + _leg, [_phase, 0] select (_phase < 0.001), true];
	_radar animateSource [_source, _phase, true];
};
