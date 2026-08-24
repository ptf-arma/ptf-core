/*
	ZEN configuration dialog for a loudspeaker module - used at placement and
	from the Zeus context menu's Adjust action. Requires ZEN (callers check).

	[_logic, _onClose] call PTF_Sound_fnc_speakerDialog;

	_onClose (optional) runs as [_logic, currentGen] call _onClose after
	confirm OR cancel - the placement flow passes the broadcast starter so
	nothing goes loud while the dialog is open; Adjust passes nothing because
	the loop is already running and reads the variables live.
*/
params ["_logic", ["_onClose", {}]];

private _cfg = configFile >> "CfgVehicles" >> typeOf _logic;
private _distance = _logic getVariable ["PTF_Sound_distance", 0];
if (_distance <= 0) then {_distance = getNumber (_cfg >> "PTF_distance")};
private _pause = _logic getVariable ["PTF_Sound_pause", -1];
if (_pause < 0) then {_pause = getNumber (_cfg >> "PTF_pause")};
private _paused = _logic getVariable ["PTF_Sound_paused", false];

[
	format ["Loudspeaker - %1", getText (_cfg >> "displayName")],
	[
		["SLIDER:RADIUS", ["Broadcast Range", "Radius in metres the broadcast is audible out to."], [100, 3000, _distance, 0, _logic, [1, 0.5, 0, 0.6]], true],
		["SLIDER", ["Pause Between Repeats", "Seconds of silence between plays."], [0, 300, _pause, 0], true],
		["CHECKBOX", ["Muted", "Hold the broadcast. Preview and position the speaker, then Resume from the right-click Loudspeaker menu when ready."], _paused, true]
	],
	{
		params ["_values", "_args"];
		_args params ["_logic", "_onClose"];
		_values params ["_distance", "_pause", "_paused"];
		if (isNull _logic) exitWith {};
		_logic setVariable ["PTF_Sound_distance", _distance, true];
		_logic setVariable ["PTF_Sound_pause", _pause, true];
		_logic setVariable ["PTF_Sound_paused", _paused, true];
		[_logic, _logic getVariable ["PTF_Sound_gen", 0]] call _onClose;
	},
	{
		params ["", "_args"];
		_args params ["_logic", "_onClose"];
		if (isNull _logic) exitWith {};
		[_logic, _logic getVariable ["PTF_Sound_gen", 0]] call _onClose;
	},
	[_logic, _onClose]
] call zen_dialog_fnc_create;
