/*
	ZEN configuration dialog for a loudspeaker module - used at placement and
	from the Zeus context menu's Adjust action. Requires ZEN (callers check).

	[_logic, _onClose] call PTF_Sound_fnc_speakerDialog;

	_onClose (optional) runs as [_logic, boundSpeaker] call _onClose after
	confirm OR cancel - the placement flow passes the broadcast starter so
	nothing goes loud while the dialog is open; Adjust passes nothing because
	the loop is already running and reads the variables live.

	The sliders show and store the RAW values including the use-default
	sentinels (0 = default range, -1 = default pause), the same convention
	as the Eden attributes and the browse dialog, so a module keeps tracking
	its sound's config defaults unless a concrete value is chosen.
*/
params ["_logic", ["_onClose", {}]];

private _cfg = configFile >> "CfgVehicles" >> typeOf _logic;
private _distance = _logic getVariable ["PTF_Sound_distance", 0];
private _pause = _logic getVariable ["PTF_Sound_pause", -1];
private _paused = _logic getVariable ["PTF_Sound_paused", false];

[
	format ["Loudspeaker - %1", getText (_cfg >> "displayName")],
	[
		["SLIDER:RADIUS", ["Broadcast Range", format ["Metres. 0 = this sound's default range (%1 m).", getNumber (_cfg >> "PTF_distance")]], [0, 3000, _distance, 0, _logic, [1, 0.5, 0, 0.6]], true],
		["SLIDER", ["Pause Between Repeats", format ["Seconds. -1 = this sound's default pause (%1 s).", getNumber (_cfg >> "PTF_pause")]], [-1, 300, _pause, 0], true],
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
		[_logic, _logic getVariable ["PTF_Sound_speaker", objNull]] call _onClose;
	},
	{
		params ["", "_args"];
		_args params ["_logic", "_onClose"];
		if (isNull _logic) exitWith {};
		[_logic, _logic getVariable ["PTF_Sound_speaker", objNull]] call _onClose;
	},
	[_logic, _onClose]
] call zen_dialog_fnc_create;
