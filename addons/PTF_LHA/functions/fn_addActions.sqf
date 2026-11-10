/*
 * Player's machine: put the 1MC controls on one LHA, at the panel beside Peral's
 * light switches (PTF_LHA_Announcements >> panel). The panel is part of the ship's
 * model, so the ACE actions hang on an invisible local helper placed there.
 *
 * Arguments:
 * 0: The ship <OBJECT>
 */
params ["_ship"];

if (isNil "ace_interact_menu_fnc_createAction") exitWith {};

private _t = time;
waitUntil {count (_ship getVariable ["bis_carrierparts", []]) >= 8 || {time - _t > 60} || {isNull _ship}};
if (isNull _ship) exitWith {};

private _cfg = configFile >> "PTF_LHA_Announcements";
getArray (_cfg >> "panel") params ["_partClass", "_point"];
private _part = ((_ship getVariable ["bis_carrierparts", []]) select {typeOf (_x select 0) == _partClass}) param [0, [objNull]] select 0;
if (isNull _part) exitWith {};

// Local to this machine, so AI pilots never see this helipad. PTF_Briefing uses
// the same kind of helper for its laptop actions.
private _helper = "Land_HelipadEmpty_F" createVehicleLocal [0, 0, 0];
_helper attachTo [_part, _part selectionPosition _point];
_helper setVariable ["PTF_LHA_ship", _ship];

private _root = [
	"PTF_LHA_1MC", "Ship's 1MC", "\a3\ui_f\data\igui\cfg\simpleTasks\types\talk_ca.paa",
	{}, {true}, {}, [], [0, 0, 0], 3
] call ace_interact_menu_fnc_createAction;
[_helper, 0, [], _root] call ace_interact_menu_fnc_addActionToObject;

{
	private _name = getText (configFile >> "CfgVehicles" >> ("PTF_Sound_Module_" + _x) >> "displayName");
	// "1MC: Flight Quarters" -> "Flight Quarters"
	if (_name select [0, 5] == "1MC: ") then {_name = _name select [5]};
	private _action = [
		"PTF_LHA_1MC_" + _x, _name, "",
		{
			params ["_target", "", "_sound"];
			[_target getVariable "PTF_LHA_ship", _sound] remoteExecCall ["PTF_LHA_fnc_announce", 2];
		},
		{true}, {}, _x, [0, 0, 0], 3
	] call ace_interact_menu_fnc_createAction;
	[_helper, 0, ["PTF_LHA_1MC"], _action] call ace_interact_menu_fnc_addActionToObject;
} forEach getArray (_cfg >> "sounds");

_ship setVariable ["PTF_LHA_1mcHelper", _helper];
_ship addEventHandler ["Deleted", {
	params ["_ship"];
	deleteVehicle (_ship getVariable ["PTF_LHA_1mcHelper", objNull]);
}];
