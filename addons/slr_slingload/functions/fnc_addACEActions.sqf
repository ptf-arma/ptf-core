#include "script_component.hpp"
/*
 * Author: Ampersand
 * Add to given helicopter ACE actions for attaching and detaching cargo. Run on vehicle init.
 *
 * Arguments:
 * 0: Heli <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call slr_slingload_fnc_addACEActions
 */

params ["_heli"];

private _action = [];
private _displayName = localize LSTRING(AttachCargo);
private _icon = "\a3\ui_f\data\igui\cfg\vehicletoggles\slingloadropeiconon2_ca.paa";
private _statement = slr_slingload_fnc_attachCargo;
private _condition = slr_slingload_fnc_canAttachCargo;
private _position = [];
private _distance = 3.5;
private _flags = [false, false, false, false, false];

// PTF fork: flag an overload on the action itself, before it is used. Runs on
// a copy of the action each time the menu is drawn, so nothing to reset.
private _modifier = {
    params ["_target", "_player", "", "_actionData"];
    private _apexFitting = _player getVariable ["slr_slingload_heldFitting", objNull];
    private _cargo = _apexFitting getVariable ["slr_slingload_cargo4Fitting", objNull];
    if (isNull _cargo) exitWith {};
    private _wreckDummy = _cargo getVariable [QGVAR(wreckDummy), objNull];
    if (!isNull _wreckDummy) then {_cargo = _wreckDummy};

    ([_target, _cargo] call FUNC(checkLoad)) params ["_total", "_rated"];
    if (_rated > 0 && {_total > _rated}) then {
        _actionData set [1, format [
            "%1 (%2 %3 / %4 t)",
            _actionData select 1,
            localize LSTRING(Overload),
            (_total / 1000) toFixed 1,
            (_rated / 1000) toFixed 1
        ]];
        _actionData set [2, [_actionData select 2, "#E06C5F"]];
    };
};

// [main, forward, aft] from slr_customHooks, else just the config sling point
private _hookPositions = [_heli] call FUNC(getHookPositions);
{
    if (_x isEqualTo []) then { continue; };

    _action = [format ["slr_slingload_attachCargo%1", _forEachIndex], _displayName, _icon, _statement, _condition, {}, _forEachIndex, _x, _distance, _flags, _modifier] call ace_interact_menu_fnc_createAction;
    [_heli, 0, [], _action] call ace_interact_menu_fnc_addActionToObject;
} forEach _hookPositions;

_hookPositions isNotEqualTo []
