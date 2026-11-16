/*
 * PTF_fnc_touchdownGuardDamage
 * Touchdown guard: HandleDamage handler on every aircraft (PTF_fnc_touchdownGuardInit).
 *
 * Arma's collision response sometimes finds a landing gear or skid a little inside
 * the deck or ground on one frame and pushes it out with a huge impulse, which
 * counts as collision damage. With the advanced flight model a gentle touchdown can
 * destroy the aircraft outright, on a ship's deck (an object, not terrain) most of
 * all, and skid aircraft like the UH-1Y more than wheeled ones.
 *
 * This ignores collision damage while the aircraft was, a moment before, close to
 * a surface, slow, and descending gently: the touchdown nobody should be hurt by.
 * Everything else still damages it: weapons and explosions, anything rammed by
 * another crewed vehicle, the rotors striking something, and hard or fast landings.
 * The speed sample comes from before the hit (XEH_postInit.sqf), because by the
 * time this runs the collision has already changed the aircraft's velocity.
 *
 * Settings (CBA, Paramarine Task Force > Aircraft): PTF_TouchdownGuardEnabled,
 * PTF_TouchdownGuardMaxSpeed (km/h, across the ground), PTF_TouchdownGuardMaxDescent
 * (m/s). Every damage it ignores is written to the RPT as "PTF touchdown guard".
 *
 * Arguments:
 * HandleDamage event arguments
 *
 * Return Value:
 * The damage to keep, or nil to leave the damage alone <NUMBER or NIL>
 */
params ["_vehicle", "", "_damage", "_source", "_projectile", "_hitIndex", "_instigator", "_hitPoint"];

// How close to the surface below, in metres, a sample must be.
#define GUARD_HEIGHT 5
// How old, in seconds, a sample may be. The sampler takes one every 0.1 s.
#define GUARD_MAX_AGE 0.6

if (!(missionNamespace getVariable ["PTF_TouchdownGuardEnabled", true])) exitWith {nil};
// Collisions have no projectile and nobody behind them.
if (_projectile != "" || {!isNull _instigator}) exitWith {nil};
// Rammed by another vehicle with someone aboard: not a touchdown.
if (!isNull _source && {_source != _vehicle} && {(crew _source) findIf {alive _x} >= 0}) exitWith {nil};
// A rotor striking something is real.
if ("rotor" in toLower _hitPoint) exitWith {nil};

// The last two samples, both recent, both a gentle touchdown.
private _samples = _vehicle getVariable ["PTF_touchdownGuard_samples", []];
if (count _samples < 2) exitWith {nil};
private _maxSpeed = (missionNamespace getVariable ["PTF_TouchdownGuardMaxSpeed", 30]) / 3.6;
private _maxDescent = missionNamespace getVariable ["PTF_TouchdownGuardMaxDescent", 4];
private _rough = _samples findIf {
	_x params ["_at", "_velocity", "_height"];
	(time - _at) > GUARD_MAX_AGE
		|| {_height > GUARD_HEIGHT}
		|| {vectorMagnitude [_velocity select 0, _velocity select 1, 0] > _maxSpeed}
		|| {((_velocity select 2) + _maxDescent) < 0}
};
if (_rough >= 0) exitWith {nil};

private _current = if (_hitIndex < 0) then {damage _vehicle} else {_vehicle getHitIndex _hitIndex};
if (_damage > _current + 0.01 && {(_vehicle getVariable ["PTF_touchdownGuard_logged", -10]) < time - 2}) then {
	_vehicle setVariable ["PTF_touchdownGuard_logged", time];
	(_samples select 0) params ["", "_velocity", "_height"];
	diag_log format [
		"PTF touchdown guard: ignored collision damage %1 -> %2 (%3) on %4, %5 km/h, descending %6 m/s, %7 m up",
		_current toFixed 2, _damage toFixed 2, [_hitPoint, "total"] select (_hitIndex < 0), typeOf _vehicle,
		(vectorMagnitude [_velocity select 0, _velocity select 1, 0] * 3.6) toFixed 1,
		((_velocity select 2) * -1) toFixed 1, _height toFixed 1
	];
};
_current
