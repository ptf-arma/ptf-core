#include "script_component.hpp"
/*
 * Author: PTF
 * Check whether a load hung from these hook positions would touch a different
 * load already hanging from the aircraft. Two loads pressed together while
 * held by ropes can blow up the physics and crash the game, and nothing else
 * stops a second load going onto the same hook, or onto a hook only a metre
 * or two away (the CH-53's main, forward and aft hooks are within 3.1 m).
 *
 * Two loads may share an aircraft only if, for every pair of hooks they use,
 * the hooks are further apart than the two loads' horizontal half-diagonals
 * added together, so the loads could not touch while hanging straight down.
 * The same load may use several hooks (Dual Point).
 *
 * Arguments:
 * 0: Heli <OBJECT>
 * 1: Cargo, the object the hook ropes will be attached to <OBJECT>
 * 2: Hook positions for the new load, heli model space <ARRAY>
 *
 * Return Value:
 * True if the new load would be too close to another load <BOOLEAN>
 *
 * Example:
 * [_heli, _cargo, [[0, 5.45, -4.13]]] call slr_slingload_fnc_hookConflict
 */

params ["_heli", "_cargo", "_newHooks"];

// Horizontal half-diagonal of a load, including anything attached to it (a
// wreck hangs from its dummy, so the dummy alone would be too small).
private _fnc_radius = {
    params ["_object"];
    private _radius = 0;
    {
        (boundingBoxReal _x) params ["_min", "_max"];
        _radius = _radius max (vectorMagnitude [((_max # 0) - (_min # 0)) / 2, ((_max # 1) - (_min # 1)) / 2, 0]);
    } forEach ([_object] + attachedObjects _object);
    _radius
};

private _newRadius = [_cargo] call _fnc_radius;

(ropes _heli) findIf {
    private _other = _x getVariable [QGVAR(target4Rope), objNull];
    private _hook = _x getVariable QGVAR(sourcePoint4Rope);
    // Only SLR hook ropes to a different load. A string source point would be
    // a memory point, which hook ropes never use.
    if (isNull _other || {_other isEqualTo _cargo} || {isNil "_hook"} || {!(_hook isEqualType [])}) then {
        false
    } else {
        private _gap = _newRadius + ([_other] call _fnc_radius);
        _newHooks findIf {(_x vectorDistance _hook) < _gap} > -1
    }
} > -1
