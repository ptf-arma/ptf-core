/*
	Zeus context-menu actions for placed loudspeaker modules, registered under
	zen_context_menu_actions in config.cpp (ZEN-only; the menu itself is
	ZEN's, so no runtime check is needed here beyond the target type).

	[_logic, _mode] call PTF_Sound_fnc_speakerAction;

	Modes:
	  preview   play the sound locally at the curator's camera - no other
	            machine gets a remoteExec, so only this curator hears it
	  pause     hold the broadcast (current play still finishes)
	  resume    lift the hold and allow a play as soon as the schedule does
	  playnow   skip the remaining pause and play at the next tick
	  adjust    reopen the range/pause/muted dialog (applies live)
*/
params ["_logic", "_mode"];

if (!(_logic isKindOf "PTF_Sound_Module_base")) exitWith {};
private _cfg = configFile >> "CfgVehicles" >> typeOf _logic;
private _name = getText (_cfg >> "displayName");

switch (_mode) do {
	case "preview": {
		// At the camera, not the module - the module may be beyond earshot.
		private _pos = getPosASL curatorCamera;
		playSound3D [getText (_cfg >> "PTF_sound"), objNull, false, _pos, getNumber (_cfg >> "PTF_volume"), 1, 500];
		hintSilent format ["Previewing: %1\n(only you can hear this)", _name];
	};
	case "pause": {
		_logic setVariable ["PTF_Sound_paused", true, true];
		hintSilent format ["Muted: %1", _name];
	};
	case "resume": {
		_logic setVariable ["PTF_Sound_paused", false, true];
		_logic setVariable ["PTF_Sound_next", serverTime, true];
		hintSilent format ["Broadcasting: %1", _name];
	};
	case "playnow": {
		_logic setVariable ["PTF_Sound_next", serverTime, true];
		hintSilent format ["Broadcast queued: %1", _name];
	};
	case "adjust": {
		[_logic] call PTF_Sound_fnc_speakerDialog;
	};
};
