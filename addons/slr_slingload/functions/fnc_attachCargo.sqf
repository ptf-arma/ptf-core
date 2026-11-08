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
private _riggedObject = _apexFitting getVariable ["slr_slingload_cargo4Fitting", objNull];

// PTF fork: checks made before anything is torn down, so a refused hook-up
// leaves the load rigged and the fitting in hand.
// A vehicle with anyone inside can't be handed to the aircraft's owner, so its
// ropes would end up simulated on one machine and the vehicle on another.
if ((crew _riggedObject) findIf {alive _x} > -1) exitWith {
    hint localize LSTRING(CargoOccupied);
    false
};
// Two loads hanging close together are pulled into each other.
private _hookPositions = [_heli] call FUNC(getHookPositions);
private _newHooks = if (_cargoHookIndex < 0) then {
    [_hookPositions param [1, []], _hookPositions param [2, []]]
} else {
    [_hookPositions param [_cargoHookIndex, []]]
} select {_x isNotEqualTo []};
if ([_heli, _cargo, _newHooks] call FUNC(hookConflict)) exitWith {
    hint localize LSTRING(HookInUse);
    false
};

private _fittingRopes = ropes _apexFitting;

// The fitting's ropes are tracked on the rigged object (the wreck itself for
// a wreck, not its dummy); drop them from that list before destroying them.
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

// What to hook where: [hook variable name, hook position, lift points, lengths]
private _requests = if (_cargoHookIndex < 0) then {
    // PTF fork: dual point (index -1). The lift points nearer the aircraft's
    // nose go to the forward hook and the rest to the aft hook, so a long load
    // hangs level and lined up with the aircraft instead of spinning under one
    // hook.
    private _heliDir = vectorDir _heli;
    private _order = [];
    {
        _order pushBack [(_riggedObject modelToWorldVisual _x) vectorDotProduct _heliDir, _forEachIndex];
    } forEach _liftPoints;
    _order sort false;
    private _frontCount = ceil (count _order / 2);
    [
        ["slr_slingload_cargoHookForward", 1, (_order select [0, _frontCount]) apply {_x select 1}],
        ["slr_slingload_cargoHookAft", 2, (_order select [_frontCount]) apply {_x select 1}]
    ] apply {
        _x params ["_hookName", "_hookIndex", "_indices"];
        [_hookName, _hookPositions param [_hookIndex, [0, 0, 0]], _indices apply {_liftPoints select _x}, _indices apply {_lengths param [_x, 10]}]
    }
} else {
    [[
        ["slr_slingload_cargoHookMain", "slr_slingload_cargoHookForward", "slr_slingload_cargoHookAft"] select _cargoHookIndex,
        _hookPositions param [_cargoHookIndex, [0, 0, 0]],
        _liftPoints,
        _lengths
    ]]
};

// Unlink the fitting before its ropes go: if a RopeBreak deletes it first,
// its Deleted handler would otherwise wipe the cargo's rope list. The flag
// stops the holder's per-frame handler (pickUpFitting) deleting the fitting
// before its ropes are gone.
_apexFitting setVariable [QGVAR(hookingUp), true];
_apexFitting setVariable ["slr_slingload_cargo4Fitting", objNull, true];
{
    [_x] call FUNC(destroyRope);
} forEach _fittingRopes;

// PTF fork: delete the fitting only once its ropes are gone. They may be
// simulated by another machine, and deleting an object under live ropes can
// crash the game. Then hand over to the server, which moves the cargo to the
// aircraft's owner and has that machine create the hook ropes.
private _fnc_hookUp = {
    params ["_apexFitting", "_heli", "_cargo", "_requests", "_unit"];
    if (!isNull _apexFitting) then {
        deleteVehicle _apexFitting;
    };
    {
        _x params ["_hookName", "_hookPosition", "_points", "_hookLengths"];
        [QGVAR(hookCargo), [_heli, _cargo, _hookName, _hookPosition, _points, _hookLengths, _unit]] call CBA_fnc_serverEvent;
    } forEach _requests;
};
[{
    params ["_apexFitting"];
    isNull _apexFitting || {(ropes _apexFitting - [objNull]) isEqualTo []}
}, _fnc_hookUp, [_apexFitting, _heli, _cargo, _requests, _unit], 2, _fnc_hookUp] call CBA_fnc_waitUntilAndExecute;

true
