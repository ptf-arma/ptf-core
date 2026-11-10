/*
 * Player's machine: put the logistics console on one LHA, against the hangar wall
 * (PTF_LHA_Logistics >> console). One submenu per class in PTF_LHA_Logistics >>
 * Menus, one entry per spawnable class; classes from mods that aren't loaded are
 * left out. Choosing one asks the server to spawn it (fn_logisticsSpawn).
 *
 * The menu shows only while the ship's spawners are on and, if the mission has a
 * spawner whitelist module, only to players on it, as Peral's own spawners do.
 *
 * Arguments:
 * 0: The ship <OBJECT>
 */
params ["_ship"];

if (isNil "ace_interact_menu_fnc_createAction") exitWith {};

private _t = time;
waitUntil {count (_ship getVariable ["bis_carrierparts", []]) >= 8 || {time - _t > 60} || {isNull _ship}};
if (isNull _ship) exitWith {};

private _cfg = configFile >> "PTF_LHA_Logistics";
getArray (_cfg >> "console") params ["_partClass", "_offset"];
private _part = ((_ship getVariable ["bis_carrierparts", []]) select {typeOf (_x select 0) == _partClass}) param [0, [objNull]] select 0;
if (isNull _part) exitWith {};

// A desk with a screen against the hangar wall, so players have something to walk up
// to. Local, like the 1MC helper: every machine builds its own copy in the same
// place, and the ACE menu hangs on the desk.
private _pieces = [];
{
	private _piece = _x createVehicleLocal [0, 0, 0];
	_piece allowDamage false;
	// No ACE carry, drag or cargo on a local copy of a fixture.
	_piece setVariable ["ace_dragging_canDrag", false];
	_piece setVariable ["ace_dragging_canCarry", false];
	_piece setVariable ["ace_cargo_canLoad", false];
	if (_pieces isEqualTo []) then {
		_piece attachTo [_part, _offset vectorAdd [0, 0, (((boundingBoxReal _piece) select 0) select 2) * -1]];
		_piece setDir getNumber (_cfg >> "consoleDir");
	} else {
		// On top of the piece below.
		private _below = _pieces select -1;
		_piece attachTo [_below, [0, 0, (((boundingBoxReal _below) select 1) select 2) - (((boundingBoxReal _piece) select 0) select 2)]];
	};
	_pieces pushBack _piece;
} forEach getArray (_cfg >> "consoleModels");
if (_pieces isEqualTo []) exitWith {};
// The menu goes on the top piece, at eye height.
private _console = _pieces select -1;
_console setVariable ["PTF_LHA_ship", _ship];
_console setVariable ["PTF_LHA_part", _part];

private _allowed = {
	params ["_target"];
	private _part = _target getVariable ["PTF_LHA_part", objNull];
	!(_part getVariable ["LHA_DisableSpawners", false])
		&& {isNil {_part getVariable "LHA_SpawnerWhiteList"} || {player in (_part getVariable ["LHA_SpawnerWhiteList", []])}}
};

private _root = [
	"PTF_LHA_Logistics", getText (_cfg >> "displayName"), getText (_cfg >> "icon"),
	{}, _allowed, {}, [], [0, 0, 0], 3
] call ace_interact_menu_fnc_createAction;
[_console, 0, [], _root] call ace_interact_menu_fnc_addActionToObject;

{
	private _menu = _x;
	private _classes = getArray (_menu >> "classes") select {getNumber (configFile >> "CfgVehicles" >> _x >> "scope") >= 1};
	if (_classes isNotEqualTo []) then {
		private _menuId = "PTF_LHA_Logistics_" + configName _menu;
		private _sub = [_menuId, getText (_menu >> "displayName"), getText (_menu >> "icon"), {}, {true}] call ace_interact_menu_fnc_createAction;
		[_console, 0, ["PTF_LHA_Logistics"], _sub] call ace_interact_menu_fnc_addActionToObject;
		{
			private _label = getText (_cfg >> "Labels" >> _x);
			if (_label == "") then {_label = getText (configFile >> "CfgVehicles" >> _x >> "displayName")};
			private _action = [
				_menuId + "_" + _x, _label, "",
				{
					params ["_target", "", "_class"];
					[_target getVariable "PTF_LHA_ship", _class] remoteExecCall ["PTF_LHA_fnc_logisticsSpawn", 2];
				},
				{true}, {}, _x
			] call ace_interact_menu_fnc_createAction;
			[_console, 0, ["PTF_LHA_Logistics", _menuId], _action] call ace_interact_menu_fnc_addActionToObject;
		} forEach _classes;
	};
} forEach ("true" configClasses (_cfg >> "Menus"));

_ship setVariable ["PTF_LHA_logisticsConsole", _pieces];
_ship addEventHandler ["Deleted", {
	params ["_ship"];
	{deleteVehicle _x} forEach (_ship getVariable ["PTF_LHA_logisticsConsole", []]);
}];
