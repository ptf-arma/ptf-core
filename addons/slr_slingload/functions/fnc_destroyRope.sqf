#include "script_component.hpp"
/*
 * Author: PTF
 * Destroy a rope on the machine that owns it. Ropes are owned by whoever
 * created them, which in multiplayer is often not the player releasing them.
 *
 * Arguments:
 * 0: Rope <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_rope] call slr_slingload_fnc_destroyRope
 */

params ["_rope"];

if (isNull _rope) exitWith {};

if (local _rope) then {
    ropeDestroy _rope;
} else {
    [QGVAR(destroyRope), [_rope], _rope] call CBA_fnc_targetEvent;
};
