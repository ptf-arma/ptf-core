/*
 * Author: lost
 * adds hitpart event handler to a projectile and checks where it hit
 *
 * Arguments:
 * object
 *
 * Return Value:
 * N/a
 *
 * Exslrle:
 *  [_bullet] call PTF_fnc_BeanBag
 */

params ["_bullet"];

_bullet addEventHandler ["HitPart", {
	params ["_projectile", "_hitEntity", "_projectileOwner", "_pos", "_velocity", "_normal", "_components", "_radius" ,"_surfaceType", "_instigator"];

	// HitPart also fires for terrain, buildings and props - only people can be beanbagged
	if !(_hitEntity isKindOf "CAManBase") exitWith {};

	// This EH runs where the projectile is local (the shooter), so both effects have to
	// be pushed to the machine that owns the victim or they only happen in the shooter's
	// simulation and desync away on the next update.
	if ("hit_legs" in _components ) then {
		// ACE Medical owns the HitLegs hitpoint - its HandleDamage EH throws away incoming
		// leg damage and ace_medical_engine_fnc_damageBodyPart rewrites the hitpoint from
		// ACE's own wound state, so setHit ["legs", 1] does nothing here. "punch" is ACE's
		// blunt trauma damage type (contusion/crush), which is what makes a unit limp.
		// ACE tracks the legs separately and HitPart does not reliably say which one was
		// hit, so pick one - the resulting limp is the same either way.
		[_hitEntity, 1, "leftleg", "punch"] remoteExec ["ace_medical_fnc_addDamageToUnit", _hitEntity];
	};
	if ("hit_arms" in _components) then {
		[_hitEntity] remoteExec ["PTF_fnc_Disarm", _hitEntity];
	};
}];
