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
	player setVariable ["PTFTEST", _components];

	if ("hit_legs" in _components ) then {
	_hitEntity setHit ["legs", 1.0]
	};
	if ("hit_arms" in _components) then {
		[_hitEntity] call PTF_fnc_Disarm;
	};
}];
