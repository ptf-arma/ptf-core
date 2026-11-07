#include "script_component.hpp"
/*
 * Author: Ampersand, PTF
 * Create the ropes from a cargo hook to the cargo. Runs on the machine that
 * owns the aircraft, so it simulates the ropes (see eventHandlers.hpp).
 *
 * Arguments:
 * 0: Heli <OBJECT>
 * 1: Cargo <OBJECT>
 * 2: Cargo hook variable name <STRING>
 * 3: Cargo hook position, heli model space <ARRAY>
 * 4: Lift points, cargo model space <ARRAY>
 * 5: Rope lengths, one per lift point <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_heli, _cargo, "slr_slingload_cargoHookMain", _hookPos, _liftPoints, _lengths] call slr_slingload_fnc_createHookRopes
 */

params ["_heli", "_cargo", "_cargoHookName", "_cargoHookPosition", "_liftPoints", "_lengths"];

if (isNull _heli || {isNull _cargo}) exitWith {};

// The aircraft changed owner while the cargo was on its way: start over so
// the cargo follows it to the new owner.
if (!local _heli) exitWith {
    [QGVAR(hookCargo), _this] call CBA_fnc_serverEvent;
};

private _ropes4Hook = _heli getVariable [_cargoHookName, []];
private _ropes4Cargo = _cargo getVariable [QGVAR(ropes4Cargo), []];
{
    private _length = _lengths param [_forEachIndex, 10];
    private _rope = [_heli, _cargoHookPosition, _cargo, _x, _length, [0,0,-11]] call FUNC(createRope);
    if (isNull _rope) then {continue};

    _rope setVariable [QGVAR(point4Rope), _x, true];
    _rope setVariable [QGVAR(ropeLength), _length, true];
    // Everything needed to recreate the rope if the aircraft changes owner
    _rope setVariable [QGVAR(target4Rope), _cargo, true];
    _rope setVariable [QGVAR(sourcePoint4Rope), _cargoHookPosition, true];
    _rope setVariable [QGVAR(targetPoint4Rope), _x, true];
    _rope setVariable [QGVAR(cargo4Rope), _cargo, true];
    _rope setVariable [QGVAR(hook4Rope), _cargoHookName, true];

    _ropes4Hook pushBack _rope;
    _ropes4Cargo pushBack _rope;
} forEach _liftPoints;

_heli setVariable [_cargoHookName, _ropes4Hook - [objNull], true];
_cargo setVariable [QGVAR(ropes4Cargo), _ropes4Cargo - [objNull], true];

// This runs on the aircraft's owner, so when it's player-flown that is the
// pilot: tell them if what is now hanging off the aircraft is over its rating.
if (hasInterface && {driver _heli isEqualTo player}) then {
    ([_heli] call FUNC(checkLoad)) params ["_total", "_rated"];
    if (_rated > 0 && {_total > _rated}) then {
        hint format [localize LSTRING(OverloadHint), (_total / 1000) toFixed 1, (_rated / 1000) toFixed 1];
    };
};

// If the aircraft changed owner while these ropes were still reaching the
// network, the new owner's Local event may have seen no SLR ropes and done
// nothing. Check again once they have propagated.
[{
    params ["_heli"];
    if (!isNull _heli && {!local _heli} && {(ropes _heli) findIf {local _x} > -1}) then {
        [QGVAR(claimCargo), [_heli]] call CBA_fnc_serverEvent;
    };
}, [_heli], 2] call CBA_fnc_waitAndExecute;
