#include "script_component.hpp"
/*
 * Author: Ampersand
 * Attach the lift points connected to the held fitting to the specified hook on the helicopter
 *
 * Arguments:
 * 0: Heli <OBJECT>
 * 1: Unit <OBJECT>
 * 2: Cargo hook index: 0 main, 1 forward, 2 aft, -1 dual point (forward and
 *    aft together) <NUMBER> <OPTIONAL>
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

// The fitting's ropes are tracked on the rigged object (the wreck itself for
// a wreck, not its dummy); drop them from that list before destroying them.
private _riggedObject = _apexFitting getVariable ["slr_slingload_cargo4Fitting", objNull];
private _riggedRopes = _riggedObject getVariable ["slr_slingload_ropes4Cargo", []];
_riggedObject setVariable ["slr_slingload_ropes4Cargo", _riggedRopes - _fittingRopes - [objNull], true];

private _liftPoints = _apexFitting getVariable ["slr_slingload_points4Fitting", []];
// PTF fork: take each lift point's length from its own rope. The fitting's
// rope list isn't in lift-point order once another player has picked the
// fitting up (takeOverRopes recreates the ropes).
private _lengths = _liftPoints apply {
    private _point = _x;
    private _index = _fittingRopes findIf {(_x getVariable ["slr_slingload_point4Rope", []]) isEqualTo _point};
    if (_index < 0) then {10} else {(_fittingRopes select _index) getVariable ["slr_slingload_ropeLength", 10]}
};

// Unlink the fitting before its ropes go: if a RopeBreak deletes it first,
// its Deleted handler would otherwise wipe the cargo's rope list.
_apexFitting setVariable ["slr_slingload_cargo4Fitting", objNull, true];
{
    [_x] call FUNC(destroyRope);
} forEach _fittingRopes;
deleteVehicle _apexFitting;

// PTF fork: dual point (index -1). The lift points nearer the aircraft's nose
// go to the forward hook and the rest to the aft hook, so a long load hangs
// level and lined up with the aircraft instead of spinning under one hook.
if (_cargoHookIndex < 0) exitWith {
    private _hookPositions = [_heli] call FUNC(getHookPositions);
    private _heliDir = vectorDir _heli;
    private _order = [];
    {
        _order pushBack [(_riggedObject modelToWorldVisual _x) vectorDotProduct _heliDir, _forEachIndex];
    } forEach _liftPoints;
    _order sort false;
    private _frontCount = ceil (count _order / 2);
    {
        _x params ["_hookName", "_hookIndex", "_indices"];
        [QGVAR(hookCargo), [
            _heli,
            _cargo,
            _hookName,
            _hookPositions param [_hookIndex, [0, 0, 0]],
            _indices apply {_liftPoints select _x},
            _indices apply {_lengths param [_x, 10]}
        ]] call CBA_fnc_serverEvent;
    } forEach [
        ["slr_slingload_cargoHookForward", 1, (_order select [0, _frontCount]) apply {_x select 1}],
        ["slr_slingload_cargoHookAft", 2, (_order select [_frontCount]) apply {_x select 1}]
    ];
    true
};

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
