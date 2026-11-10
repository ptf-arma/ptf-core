/*
 * Author: Paramarine Task Force
 * Where one of a G/ATOR's legs is: "up", "down" (resting on the ground, however far it had to
 * reach) or "moving". A lowered leg stops where it meets the ground, so "down" is any phase
 * the server set as the leg's target (PTF_GATOR_legTarget_<leg>) once the leg has got there.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Leg: "fl", "fr", "rl" or "rr" <STRING>
 *
 * Return Value:
 * "up", "down" or "moving" <STRING>
 *
 * Example:
 * [_radar, "fl"] call PTF_GATOR_fnc_legState
 */
params [["_radar", objNull, [objNull]], ["_leg", "", [""]]];

private _target = _radar getVariable ["PTF_GATOR_legTarget_" + _leg, 0];
private _phase = _radar animationSourcePhase ("ptf_gator_leg_" + _leg);
if (abs (_phase - _target) > 0.001) exitWith {"moving"};
["up", "down"] select (_target > 0)
