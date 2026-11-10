/*
 * Author: Paramarine Task Force
 * Player's machine (postInit): the ACE actions on a G/ATOR's operator computer (any of
 * ptf_gator_computerClasses that a G/ATOR put out, PTF_GATOR_fnc_computer), in its main
 * interaction beside ACE's own Carry, so the laptop has the one interaction point:
 *  - Open G/ATOR console: the operator's console (PTF_GATOR_fnc_console) on the Billet tablet's
 *    console slot. Without Billet there is no console.
 *  - Take manual control / Return to automatic: the same switch as the console's, so the
 *    G/ATOR can be put back to automatic without Billet too.
 */
if (!hasInterface) exitWith {};

private _radarOf = "(_target getVariable ['PTF_GATOR_radar', objNull])";
private _actions = [
	["PTF_GATOR_Console", "Open G/ATOR console", {["ptf_gator", _target] call blk_fnc_tabletConsole},
		compile format ["!isNull %1 && {!isNil 'blk_fnc_tabletConsole'}", _radarOf]],
	["PTF_GATOR_Manual", "Take manual control", {[_target getVariable ["PTF_GATOR_radar", objNull], "manual", "", _player] call PTF_GATOR_fnc_operator},
		compile format ["private _r = %1; !isNull _r && {!(_r getVariable ['PTF_GATOR_manual', false])} && {(_r getVariable ['PTF_GATOR_console', objNull]) isEqualTo _target}", _radarOf]],
	["PTF_GATOR_Auto", "Return to automatic control", {[_target getVariable ["PTF_GATOR_radar", objNull], "auto", "", _player] call PTF_GATOR_fnc_operator},
		compile format ["%1 getVariable ['PTF_GATOR_manual', false]", _radarOf]]
];
{
	private _class = _x;
	if (isClass (configFile >> "CfgVehicles" >> _class)) then {
		{
			_x params ["_name", "_title", "_statement", "_condition"];
			[_class, 0, ["ACE_MainActions"], [_name, _title, "", _statement, _condition] call ace_interact_menu_fnc_createAction, true]
				call ace_interact_menu_fnc_addActionToClass;
		} forEach _actions;
	};
} forEach getArray (configFile >> "CfgVehicles" >> "PTF_GATOR" >> "ptf_gator_computerClasses");
