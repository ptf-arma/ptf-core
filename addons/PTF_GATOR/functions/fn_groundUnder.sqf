/*
 * Author: Paramarine Task Force
 * The height (ASL) of whatever is under a point near a G/ATOR: a road, a floor or a rock if
 * there is one, else the terrain. The G/ATOR itself and whatever it is attached to (or has
 * attached to it) don't count.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Point, ASL <ARRAY>
 *
 * Return Value:
 * Ground height, ASL <NUMBER>
 *
 * Example:
 * [_radar, getPosASL player] call PTF_GATOR_fnc_groundUnder
 */
params [["_radar", objNull, [objNull]], ["_at", [0, 0, 0], [[]]]];

_at params ["_px", "_py", "_pz"];
private _ground = getTerrainHeightASL [_px, _py];
private _skip = [_radar, attachedTo _radar] + attachedObjects _radar;
{
	_x params ["_hit", "", "_object"];
	if !(_object in _skip) exitWith {_ground = _ground max (_hit select 2)};
} forEach lineIntersectsSurfaces [[_px, _py, _pz + 1.5], [_px, _py, _ground - 0.2], objNull, objNull, true, 6, "GEOM", "NONE"];
_ground
