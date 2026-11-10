/*
 * Author: Paramarine Task Force
 * Where a vehicle's tow hitch is, in its model space (modelToWorld). RHS vehicles that tow
 * the M119 say so in their config (RHS_TowingSystem >> Carrier >> rhs_attachPointPos); for
 * anything else it is the middle of the vehicle's back end, at the G/ATOR's hitch height.
 *
 * Arguments:
 * 0: Towing vehicle <OBJECT>
 *
 * Return Value:
 * Hitch position, model space <ARRAY>
 *
 * Example:
 * [_truck] call PTF_GATOR_fnc_towHitchPoint
 */
params [["_vehicle", objNull, [objNull]]];

private _rhs = getArray (configOf _vehicle >> "RHS_TowingSystem" >> "Carrier" >> "rhs_attachPointPos");
if (count _rhs == 3) exitWith {_rhs};

(0 boundingBoxReal _vehicle) params ["_min", "_max"];
private _pos = getPosASLVisual _vehicle;
private _ground = (_vehicle worldToModelVisual ASLToAGL [_pos select 0, _pos select 1, getTerrainHeightASL _pos]) select 2;
[0, (_min select 1) - 0.1, _ground + 0.85]
