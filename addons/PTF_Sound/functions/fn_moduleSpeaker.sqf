/*
	Loudspeaker broadcast module.

	Runs where the module is local (server for Eden placement, the curator's
	machine for Zeus placement). Repeats the configured sound at the module's
	position until the module is deleted. playSound3D has local effect, so
	each play is remoteExec'd to every machine; the distance parameter caps
	the audible range.

	Range resolution order (checked every repeat, so it can be changed live):
	  1. PTF_Sound_distance variable on the module, if > 0 — set by the ZEN
	     placement dialog, the Eden attribute, or script
	  2. the sound's PTF_distance config default

	When Zeus Enhanced is loaded and the placer has the curator camera open, a
	ZEN radius-slider dialog (with terrain circle preview) asks for the range
	on placement. Without ZEN the module still works at the default range —
	soft dependency only.
*/
params ["_logic", "_units", "_activated"];

if (!_activated) exitWith {};

private _cfg = configFile >> "CfgVehicles" >> typeOf _logic;
private _path = getText (_cfg >> "PTF_sound");
private _volume = getNumber (_cfg >> "PTF_volume");
private _distance = getNumber (_cfg >> "PTF_distance");
private _period = getNumber (_cfg >> "PTF_duration") + getNumber (_cfg >> "PTF_pause");

if (_path isEqualTo "") exitWith {
	diag_log format ["PTF_Sound: %1 has no PTF_sound configured", typeOf _logic];
};

private _startBroadcast = {
	params ["_logic", "_path", "_volume", "_distance", "_period"];
	[_logic, _path, _volume, _distance, _period] spawn {
		params ["_logic", "_path", "_volume", "_cfgDistance", "_period"];
		while {!isNull _logic} do {
			private _distance = _logic getVariable ["PTF_Sound_distance", 0];
			if (_distance <= 0) then {_distance = _cfgDistance};
			[_path, objNull, false, getPosASL _logic, _volume, 1, _distance] remoteExec ["playSound3D", 0];
			sleep _period;
		};
	};
};

private _args = [_logic, _path, _volume, _distance, _period];

if (!isNull curatorCamera && {isClass (configFile >> "CfgPatches" >> "zen_dialog")}) exitWith {
	[
		format ["%1 - Range", getText (_cfg >> "displayName")],
		[
			["SLIDER:RADIUS", ["Broadcast Range", "Radius in metres the broadcast is audible out to."], [100, 3000, _distance, 0, _logic, [1, 0.5, 0, 0.6]], true]
		],
		{
			params ["_values", "_args"];
			(_args select 0) setVariable ["PTF_Sound_distance", _values select 0, true];
			_args call (_args select 5);
		},
		{
			params ["", "_args"];
			_args call (_args select 5);
		},
		_args + [_startBroadcast]
	] call zen_dialog_fnc_create;
};

_args call _startBroadcast;
