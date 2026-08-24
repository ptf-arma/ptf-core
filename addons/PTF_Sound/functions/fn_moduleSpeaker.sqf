/*
	Loudspeaker broadcast module - client-side entry point.

	Runs where the module is local (server for Eden placement, the curator's
	machine for Zeus placement or the browse dialog). Resolves the speaker
	binding, bumps the activation generation, optionally shows the ZEN
	configuration dialog, then hands the broadcast to the SERVER
	(PTF_Sound_fnc_serverLoop) - the loop must not die with a disconnecting
	curator.

	The play schedule is state on the logic (PTF_Sound_next, serverTime-based)
	plus a per-sound last-play time in missionNamespace; the server loop only
	honors it. Zeus moving or editing the module re-runs this function; the
	generation bump retires the old loop and the new one resumes the preserved
	schedule, so a move never restarts or doubles the audio. Even if the move
	recreated the logic (wiping its variables), the missionNamespace last-play
	time catches the in-flight broadcast and the new module inherits its
	cadence.

	Runtime variables on the logic (all public, live - read every tick):
	  PTF_Sound_distance   audible radius, 0/unset = config default
	  PTF_Sound_pause      seconds between repeats, negative/unset = default
	  PTF_Sound_paused     true = hold the broadcast
	  PTF_Sound_next       serverTime before which the loop must not play
	  PTF_Sound_cut        change to cut the current play instantly
	  PTF_Sound_noDialog   set before calling to skip the placement dialog

	The broadcast binds to a physical speaker where one exists: the object the
	module was dropped onto in Zeus (curator attach), else the nearest prop or
	vehicle within 5 m - re-resolved on every activation, so dragging the
	module onto a different prop rebinds it. The server broadcasts with say3D
	from an invisible emitter attached to the bound object (or at the module),
	so destroying the speaker, muting, or deleting the module cuts the audio
	MID-PLAY - the emitter dies and the sound dies with it.
*/
params ["_logic", "_units", "_activated"];

if (!_activated) exitWith {};

private _who = format ["srv=%1 owner=%2 local=%3", isServer, clientOwner, local _logic];
if (!local _logic) exitWith {
	diag_log format ["PTF_Sound: %1 skipped, not local (%2)", typeOf _logic, _who];
};

private _cfg = configFile >> "CfgVehicles" >> typeOf _logic;
private _class = getText (_cfg >> "PTF_soundClass");

if (_class isEqualTo "") exitWith {
	diag_log format ["PTF_Sound: %1 has no PTF_soundClass configured", typeOf _logic];
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
	[_logic, _gen] remoteExec ["PTF_Sound_fnc_serverLoop", 2];
};

// Placement dialog only on the true first activation - re-activations from a
// Zeus move/edit go straight back to broadcasting, a recreated module that is
// mid-broadcast skips the dialog via the same-sound check, and the browse
// dialog pre-configures and sets PTF_Sound_noDialog.
private _midPlay = serverTime < (missionNamespace getVariable [format ["PTF_Sound_last_%1", _class], -1e9]) + getNumber (_cfg >> "PTF_duration");
if (
	_gen == 1 && {!_midPlay} && {!(_logic getVariable ["PTF_Sound_noDialog", false])}
	&& {!isNull curatorCamera} && {isClass (configFile >> "CfgPatches" >> "zen_dialog")}
) exitWith {
	[_logic, _startBroadcast] call PTF_Sound_fnc_speakerDialog;
};

[_logic, _gen] call _startBroadcast;
