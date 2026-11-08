#include "script_component.hpp"
/*
 * Author: PTF
 * A hook-up was refused after the fitting had already gone (by the server or
 * the aircraft's owner). Tell the player who asked for it, and log it.
 *
 * Arguments:
 * 0: Player who attached the cargo, or objNull if unknown <OBJECT>
 * 1: Stringtable name of the reason <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_requester, "STR_SLR_SlingLoad_HookInUse"] call slr_slingload_fnc_hookRefused
 */

params ["_requester", "_stringName"];

diag_log text format ["[SLR] hook-up refused for %1: %2", _requester, _stringName];

if (!isNull _requester) then {
    [QGVAR(hookRefused), [_stringName], _requester] call CBA_fnc_targetEvent;
};
