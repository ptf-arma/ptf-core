#include "script_component.hpp"
/*
 * Author: PTF
 * Recreate the SLR ropes hanging from a heli or apex fitting on the machine
 * that now owns it, then destroy the originals. A rope stays simulated by the
 * machine that created it, so it has to be remade when its source changes
 * owner (new pilot, or another player picking up the fitting).
 *
 * Arguments:
 * 0: Heli or apex fitting <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [vehicle player] call slr_slingload_fnc_takeOverRopes
 */

params ["_source"];

// Whoever does own it gets its own Local event and takes over there.
if (isNull _source || {!local _source}) exitWith {};

private _ropeEnd = [[0,0,-11], [0,0,-1]] select (_source isKindOf "slr_slingload_apexFitting");

{
    private _oldRope = _x;
    private _target = _oldRope getVariable [QGVAR(target4Rope), objNull];
    private _sourcePoint = _oldRope getVariable QGVAR(sourcePoint4Rope);
    private _targetPoint = _oldRope getVariable QGVAR(targetPoint4Rope);
    // Already ours, or not an SLR rope (vanilla sling load, ACE fast rope)
    if (local _oldRope || {isNull _target} || {isNil "_sourcePoint"} || {isNil "_targetPoint"}) then {continue};

    private _length = _oldRope getVariable [QGVAR(ropeLength), ropeLength _oldRope];
    private _newRope = ropeCreate [_source, _sourcePoint, _target, _targetPoint, _length, ["", [0,0,-1]], ["RopeEnd", _ropeEnd]];
    if (isNull _newRope) then {continue};

    {
        private _value = _oldRope getVariable _x;
        if (!isNil "_value") then {
            _newRope setVariable [_x, _value, true];
        };
    } forEach [
        QGVAR(point4Rope),
        QGVAR(ropeLength),
        QGVAR(target4Rope),
        QGVAR(sourcePoint4Rope),
        QGVAR(targetPoint4Rope),
        QGVAR(cargo4Rope),
        QGVAR(hook4Rope)
    ];

    // Swap the new rope into the lists that track the old one
    private _cargo = _oldRope getVariable [QGVAR(cargo4Rope), _target];
    private _ropes4Cargo = _cargo getVariable [QGVAR(ropes4Cargo), []];
    _cargo setVariable [QGVAR(ropes4Cargo), (_ropes4Cargo - [_oldRope, objNull]) + [_newRope], true];
    private _cargoHookName = _oldRope getVariable [QGVAR(hook4Rope), ""];
    if (_cargoHookName != "") then {
        private _ropes4Hook = _source getVariable [_cargoHookName, []];
        _source setVariable [_cargoHookName, (_ropes4Hook - [_oldRope, objNull]) + [_newRope], true];
    };

    // New rope first, then the old one, so the cargo is never left hanging
    // from nothing (that would also make the PTF sling-mass script restore
    // the cargo's full weight mid-flight).
    [_oldRope] call FUNC(destroyRope);
} forEach ropes _source;
