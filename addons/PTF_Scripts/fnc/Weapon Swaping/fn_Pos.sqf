/*
 * Author: lost
 * Used to determain the location of a dummy object on a player via the weapon name
 *
 * Arguments:
 * weapon class name
 * 
 * Return Value:
 * pos [x,y,z]
 *
 * Exslrle:
 *  ["rhs_weap_m32"] call PTF_fnc_pos
 */

params ["_weapon"];

switch (_weapon) do {
case "rhs_weap_m32": {[-0.2,-0.22,0]};
default {[-0.2,-0.12,0]};
};

