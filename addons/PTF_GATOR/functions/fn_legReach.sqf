/*
 * Author: Paramarine Task Force
 * How far a G/ATOR's leg has to run (as a leg phase) for its foot to meet the ground, with the
 * trailer where it is now, or in a given pose. Phase 1 is a foot on flat ground under a
 * trailer standing on its wheels; a leg runs to LEG_MAX_PHASE (model.cfg) at most.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Leg: "fl", "fr", "rl" or "rr" <STRING>
 * 2: Pose to measure in: [model origin ASL, vectorDir, vectorUp], or [] for where it is now <ARRAY> (default: [])
 *
 * Return Value:
 * Phase, not clamped (more than LEG_MAX_PHASE: out of reach) <NUMBER>
 *
 * Example:
 * [_radar, "fl"] call PTF_GATOR_fnc_legReach
 */
#include "..\script_gator.hpp"
params [["_radar", objNull, [objNull]], ["_leg", "", [""]], ["_pose", [], [[]]]];

private _foot = LEG_FOOT get _leg;   // the foot's sole at phase 0, in model space
_pose params [["_origin", _radar modelToWorldWorld [0, 0, 0]], ["_dir", vectorDir _radar], ["_up", vectorUp _radar]];
private _right = _dir vectorCrossProduct _up;
private _at = _origin vectorAdd (_right vectorMultiply (_foot select 0)) vectorAdd (_dir vectorMultiply (_foot select 1))
	vectorAdd (_up vectorMultiply (_foot select 2));
private _ground = [_radar, _at] call PTF_GATOR_fnc_groundUnder;
((_at select 2) - _ground) / (LEG_TRAVEL * ((_up select 2) max 0.5))
