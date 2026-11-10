/*
 * Author: Paramarine Task Force
 * Which way a G/ATOR's array faces, as a compass bearing, worked out from the trailer's heading
 * and the turntable's animation (ptf_gator_spin: one turn per unit of phase, anticlockwise seen
 * from above; at rest, phase 0, the array faces ARRAY_REST degrees round from the trailer's
 * heading, straight back). Not from its animated memory points: a dedicated server may not move
 * those, and this answers the same on every machine.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 *
 * Return Value:
 * Bearing, 0 to 360 <NUMBER>
 */
#include "..\script_gator.hpp"
params [["_radar", objNull, [objNull]]];
private _b = (getDir _radar) + ARRAY_REST - 360 * ((_radar animationSourcePhase "ptf_gator_spin") % 1);
((_b % 360) + 360) % 360
