#include "script_component.hpp"
/*
 * Author: Ampersand
 * Attach the lift points connected to the held fitting to the specified hook on the helicopter
 *
 * Arguments:
 * 0: Heli <OBJECT>
 * 1: Unit <OBJECT>
 * 1: Cargo Hook Position <ARRAY> <OPTIONAL>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli, _unit] call slr_slingload_fnc_attachCargo
 * [cursorObject, player, (cursorObject selectionPosition "slingload0") vectorAdd [0,-3,0]] call slr_slingload_fnc_attachCargo
 */

params ["_heli", "_unit", ["_cargoHookIndex", 0]];

private _apexFitting = _unit getVariable ["slr_slingload_heldFitting", objNull];
if (isNull _apexFitting) exitWith {false};
private _cargo = _apexFitting getVariable ["slr_slingload_cargo4Fitting", objNull];
if (isNull _cargo) exitWith {false};
private _cargoWreck = _cargo getVariable [QGVAR(wreckDummy), objNull];
if !(isNull _cargoWreck) then {
    _cargo = _cargoWreck;
};
private _fittingRopes = ropes _apexFitting;
private _lengths = _fittingRopes apply {_x getVariable ["slr_slingload_ropeLength", 10]};

// The fitting's ropes are tracked on the rigged object (the wreck itself for
// a wreck, not its dummy); drop them from that list before destroying them.
private _riggedObject = _apexFitting getVariable ["slr_slingload_cargo4Fitting", objNull];
private _riggedRopes = _riggedObject getVariable ["slr_slingload_ropes4Cargo", []];
_riggedObject setVariable ["slr_slingload_ropes4Cargo", _riggedRopes - _fittingRopes - [objNull], true];

private _liftPoints = _apexFitting getVariable ["slr_slingload_points4Fitting", []];

// Unlink the fitting before its ropes go: if a RopeBreak deletes it first,
// its Deleted handler would otherwise wipe the cargo's rope list.
_apexFitting setVariable ["slr_slingload_cargo4Fitting", objNull, true];
{
    [_x] call FUNC(destroyRope);
} forEach _fittingRopes;
deleteVehicle _apexFitting;

private _cargoHookName = [
    "slr_slingload_cargoHookMain",
    "slr_slingload_cargoHookForward",
    "slr_slingload_cargoHookAft"
] select _cargoHookIndex;

private _cargoHookPosition = ([_heli] call FUNC(getHookPositions)) param [_cargoHookIndex, [0, 0, 0]];

// PTF fork: hand over to the server, which moves the cargo to the
// aircraft's owner and has that machine create the hook ropes.
[QGVAR(hookCargo), [_heli, _cargo, _cargoHookName, _cargoHookPosition, _liftPoints, _lengths]] call CBA_fnc_serverEvent;

true
