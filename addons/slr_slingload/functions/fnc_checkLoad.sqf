#include "script_component.hpp"
/*
 * Author: PTF
 * What an aircraft carries on its ropes, optionally with one more load added,
 * against its rated sling capacity (slingLoadMaxCargoMass). Ropes don't
 * enforce the rating; this is for warnings and readouts.
 *
 * Mass on the ropes comes from PTF_fnc_slingMassFor when PTF Core is loaded
 * (it accounts for cargo PTF lightens while slung), else from getMass.
 *
 * Arguments:
 * 0: Heli <OBJECT>
 * 1: Extra load to add, e.g. the cargo about to be hooked <OBJECT> (default: objNull)
 *
 * Return Value:
 * [Total mass on the ropes kg <NUMBER>, Rated capacity kg, 0 if none <NUMBER>]
 *
 * Example:
 * [vehicle player] call slr_slingload_fnc_checkLoad
 */

params ["_heli", ["_extraLoad", objNull]];

private _heliType = typeOf _heli;
private _slung = [];
{
    private _target = _x getVariable [QGVAR(target4Rope), objNull];
    if (!isNull _target) then {_slung pushBackUnique _target};
} forEach ropes _heli;
private _vanillaLoad = getSlingLoad _heli;
if (!isNull _vanillaLoad) then {_slung pushBackUnique _vanillaLoad};
if (!isNull _extraLoad) then {_slung pushBackUnique _extraLoad};

private _hasPTF = !isNil "PTF_fnc_slingMassFor";
private _total = 0;
{
    _total = _total + (if (_hasPTF) then {[_x, _heliType] call PTF_fnc_slingMassFor} else {getMass _x});
} forEach _slung;

[_total, getNumber (configOf _heli >> "slingLoadMaxCargoMass")]
