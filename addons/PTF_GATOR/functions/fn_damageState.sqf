/*
 * Author: Paramarine Task Force
 * A G/ATOR's state in one line, for PTF_GATOR_fnc_damageLog's RPT lines: where, speed, which
 * way up, array and leg phases, what is towing it, this machine and the fuel.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 *
 * Return Value:
 * The line <STRING>
 */
params [["_radar", objNull, [objNull]]];
format ["at %1 speed %2 km/h up %3 array %4 legs %5 towed by %6 owner %7 fuel %8",
	mapGridPosition _radar, round speed _radar, (vectorUp _radar) apply {_x toFixed 2},
	(_radar animationSourcePhase "ptf_gator_deploy") toFixed 2,
	["fl", "fr", "rl", "rr"] apply {(_radar animationSourcePhase ("ptf_gator_leg_" + _x)) toFixed 2},
	typeOf (_radar getVariable ["PTF_GATOR_tower", objNull]), clientOwner, (fuel _radar) toFixed 2]
