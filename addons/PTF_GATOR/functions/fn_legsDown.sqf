/*
 * Author: Paramarine Task Force
 * Whether all four of a G/ATOR's legs are down on the ground and still.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 *
 * Return Value:
 * All down <BOOL>
 *
 * Example:
 * [_radar] call PTF_GATOR_fnc_legsDown
 */
params [["_radar", objNull, [objNull]]];

{[_radar, _x] call PTF_GATOR_fnc_legState == "down"} count ["fl", "fr", "rl", "rr"] == 4
