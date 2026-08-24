/*
	Loudspeaker broadcast module.

	Runs where the module is local (server for Eden placement, the curator's
	machine for Zeus placement). Repeats the configured sound at the module's
	position until the module is deleted. playSound3D has local effect, so
	each play is remoteExec'd to every machine; the distance parameter caps
	the audible range.

	The play SCHEDULE is state on the logic (PTF_Sound_next, serverTime-based)
	plus a per-sound-class last-play time in missionNamespace - the loop only
	honors it. Zeus moving or editing the module re-runs this function; the
	generation counter retires the old loop and the new one falls in with the
	preserved schedule, so a move never restarts or doubles the audio. Even if
	the move recreated the logic (wiping its variables), the missionNamespace
	last-play time still catches the in-flight broadcast and the new module
	inherits its cadence.

	Runtime variables on the logic (all public, live - read every tick):
	  PTF_Sound_distance   audible radius, 0/unset = config default
	  PTF_Sound_pause      seconds between repeats, unset = config default
	  PTF_Sound_paused     true = hold the broadcast (dialog "Muted", or the
	                       Zeus context menu Mute/Resume actions)
	  PTF_Sound_next       serverTime before which the loop must not play

	On first placement with a curator screen and ZEN present, the placement
	dialog (PTF_Sound_fnc_speakerDialog) configures range/pause/muted before
	anything goes loud. Without ZEN the module broadcasts at defaults - soft
	dependency only.

	The broadcast binds to a physical speaker where one exists: the object the
	module was dropped onto in Zeus (curator attach), else the nearest prop or
	vehicle within 5 m - re-resolved on every activation, so dragging the
	module onto a different prop rebinds it. Destroying the bound object ends
	the broadcast after the current play (playSound3D cannot be cut short) and
	removes the module. Position is re-read each repeat, so a module attached
	to a vehicle broadcasts on the move.
*/
params ["_logic", "_units", "_activated"];

if (!_activated) exitWith {};

private _who = format ["srv=%1 owner=%2 local=%3", isServer, clientOwner, local _logic];
if (!local _logic) exitWith {
	diag_log format ["PTF_Sound: %1 skipped, not local (%2)", typeOf _logic, _who];
};

private _cfg = configFile >> "CfgVehicles" >> typeOf _logic;
private _path = getText (_cfg >> "PTF_sound");

if (_path isEqualTo "") exitWith {
	diag_log format ["PTF_Sound: %1 has no PTF_sound configured", typeOf _logic];
};

// (Re)resolve the physical speaker on every activation.
private _speaker = attachedTo _logic;
if (isNull _speaker) then {
	private _near = (nearestObjects [_logic, ["Static", "Thing", "LandVehicle", "Ship", "Air"], 5]) select {alive _x};
	if (_near isNotEqualTo []) then {_speaker = _near select 0};
};
_logic setVariable ["PTF_Sound_speaker", _speaker, true];

// Every activation bumps the generation; loops exit when theirs is stale.
private _gen = (_logic getVariable ["PTF_Sound_gen", 0]) + 1;
_logic setVariable ["PTF_Sound_gen", _gen, true];
diag_log format ["PTF_Sound: %1 activation gen=%2 (%3)", typeOf _logic, _gen, _who];

private _startBroadcast = {
	params ["_logic", "_gen"];
	// A dialog closing after a re-activation must not stack a second loop
	// for the same generation.
	if (_logic getVariable ["PTF_Sound_loop", -1] == _gen) exitWith {};
	_logic setVariable ["PTF_Sound_loop", _gen];
	[_logic, _gen] spawn {
		params ["_logic", "_gen"];
		private _cfg = configFile >> "CfgVehicles" >> typeOf _logic;
		private _path = getText (_cfg >> "PTF_sound");
		private _volume = getNumber (_cfg >> "PTF_volume");
		private _cfgDistance = getNumber (_cfg >> "PTF_distance");
		private _duration = getNumber (_cfg >> "PTF_duration");
		private _cfgPause = getNumber (_cfg >> "PTF_pause");
		private _lastKey = format ["PTF_Sound_last_%1", typeOf _logic];
		private _speaker = _logic getVariable ["PTF_Sound_speaker", objNull];
		while {
			!isNull _logic
			&& {_gen == _logic getVariable ["PTF_Sound_gen", 0]}
			&& {isNull _speaker || {alive _speaker}}
		} do {
			private _now = serverTime;
			private _next = _logic getVariable ["PTF_Sound_next", 0];
			private _last = missionNamespace getVariable [_lastKey, -1e9];
			private _period = _duration + (_logic getVariable ["PTF_Sound_pause", _cfgPause]);
			if (_next == 0 && {_now < _last + _duration}) then {
				// This sound is already mid-play (typically the module was
				// recreated by a Zeus move) - fall in with its cadence
				// instead of restarting the line on top of it.
				_next = _last + _period;
				_logic setVariable ["PTF_Sound_next", _next, true];
			};
			if (
				!(_logic getVariable ["PTF_Sound_paused", false])
				&& {_now >= _next}
				&& {_now >= _last + _duration}
			) then {
				private _distance = _logic getVariable ["PTF_Sound_distance", 0];
				if (_distance <= 0) then {_distance = _cfgDistance};
				private _pos = if (isNull _speaker) then {getPosASL _logic} else {getPosASL _speaker};
				// Nested array: remoteExec reads the outer array as the
				// command's argument list, and playSound3D is unary - it
				// takes one array.
				[[_path, objNull, false, _pos, _volume, 1, _distance]] remoteExec ["playSound3D", 0];
				missionNamespace setVariable [_lastKey, _now, true];
				_logic setVariable ["PTF_Sound_next", _now + _period, true];
			};
			sleep 1;
		};
		// Superseded by a newer activation: leave the logic alone. Bound
		// speaker destroyed: clean the module up.
		if (!isNull _logic && {_gen == _logic getVariable ["PTF_Sound_gen", 0]}) then {
			deleteVehicle _logic;
		};
	};
};

// Placement dialog only on the true first activation - re-activations from a
// Zeus move/edit go straight back to broadcasting, and a recreated module
// that is mid-broadcast skips the dialog too.
private _midPlay = serverTime < (missionNamespace getVariable [format ["PTF_Sound_last_%1", typeOf _logic], -1e9]) + getNumber (_cfg >> "PTF_duration");
if (
	_gen == 1 && {!_midPlay} && {!isNull curatorCamera}
	&& {isClass (configFile >> "CfgPatches" >> "zen_dialog")}
) exitWith {
	[_logic, _startBroadcast] call PTF_Sound_fnc_speakerDialog;
};

[_logic, _gen] call _startBroadcast;
