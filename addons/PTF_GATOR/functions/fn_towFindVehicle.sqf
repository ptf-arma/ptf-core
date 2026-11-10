/*
 * Author: Paramarine Task Force
 * The vehicle a G/ATOR can hitch to now: a car or tracked vehicle, intact and not another
 * G/ATOR, whose hitch is within reach of the trailer's lunette and which sits ahead of the
 * trailer facing away from it. The trailer must be packed up (array down, legs up) and not
 * already hitched, with both wheels on, its SATCOM antenna stowed and not on fire.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Ignore missing wheels (to tell the player why it won't hitch) <BOOL> (default: false)
 *
 * Return Value:
 * Towing vehicle, or objNull <OBJECT>
 *
 * Example:
 * [_radar] call PTF_GATOR_fnc_towFindVehicle
 */
params [["_radar", objNull, [objNull]], ["_ignoreWheels", false, [false]]];

if (!alive _radar || {!isNull (_radar getVariable ["PTF_GATOR_tower", objNull])}) exitWith {objNull};
// Not on a missing wheel or on fire.
if (!_ignoreWheels && {selectMax (["HitLF2Wheel", "HitRF2Wheel"] apply {_radar getHitPointDamage _x}) >= 1}) exitWith {objNull};
if (_radar getVariable ["PTF_GATOR_fireStart", -1] >= 0) exitWith {objNull};
// The SATCOM antenna and the operator computer are stowed first: their cables run from the box.
if (!isNull (_radar getVariable ["PTF_GATOR_antenna", objNull]) || {!isNull (_radar getVariable ["PTF_GATOR_computer", objNull])}) exitWith {objNull};
if (_radar animationSourcePhase "ptf_gator_deploy" > 0.001) exitWith {objNull};
if ({_radar animationSourcePhase ("ptf_gator_leg_" + _x) > 0.001} count ["fl", "fr", "rl", "rr"] > 0) exitWith {objNull};

private _lunette = _radar modelToWorldVisual (_radar selectionPosition ["hitch", "Memory"]);
private _best = objNull;
private _bestDistance = 3;
{
	if (alive _x && {_x != _radar} && {!(_x isKindOf "PTF_GATOR")} && {abs speed _x < 2}
		&& {(vectorDir _x) vectorDotProduct (vectorDir _radar) > 0.5}) then {
		private _distance = (_x modelToWorldVisual ([_x] call PTF_GATOR_fnc_towHitchPoint)) distance _lunette;
		if (_distance < _bestDistance) then {
			_best = _x;
			_bestDistance = _distance;
		};
	};
} forEach (nearestObjects [_lunette, ["Car", "Tank"], 12]);
_best
