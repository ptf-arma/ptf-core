/*
 * Author: Paramarine Task Force
 * Whether one of a G/ATOR's leveling legs can be lowered (or raised) now. Not while it is
 * hitched to a vehicle or leveling itself, and a leg only comes up once the array is fully down.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Leg: "fl", "fr", "rl" or "rr" <STRING>
 * 2: Lower (true) or raise (false) <BOOL>
 *
 * Return Value:
 * Can <BOOL>
 *
 * Example:
 * [_radar, "fl", true] call PTF_GATOR_fnc_canSetLeg
 */
params [["_radar", objNull, [objNull]], ["_leg", "", [""]], ["_down", true, [true]]];

if (!alive _radar || {abs speed _radar > 1} || {!isNull (_radar getVariable ["PTF_GATOR_tower", objNull])}) exitWith {false};
if (_radar getVariable ["PTF_GATOR_levelling", false]) exitWith {false};
private _state = [_radar, _leg] call PTF_GATOR_fnc_legState;
if (_down) exitWith {_state == "up"};
_state == "down" && {_radar animationSourcePhase "ptf_gator_deploy" < 0.001}
