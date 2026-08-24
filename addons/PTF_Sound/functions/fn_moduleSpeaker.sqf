/*
	Loudspeaker broadcast module - entry point on the machine where the
	module is local (server for Eden and browse placement, the curator's
	machine for Zeus placement).

	Resolves the speaker binding, optionally shows the ZEN configuration
	dialog (once per module - PTF_Sound_configured), then hands the
	broadcast to the server (PTF_Sound_fnc_serverLoop), which owns the
	activation generation and all scheduling. A Zeus move/edit re-runs this
	function; the server-side generation bump retires the old loop and the
	new one resumes the schedule preserved on the logic, so a move never
	restarts the audio. (If Zeus recreates the logic outright, its state is
	gone - the old broadcast cuts within a second and the module starts
	fresh; that path is accepted rather than papered over.)

	Runtime variables on the logic (all public, read live by the server):
	  PTF_Sound_distance   audible radius, 0/unset = config default
	  PTF_Sound_pause      seconds between repeats, negative/unset = default
	  PTF_Sound_paused     true = hold the broadcast
	  PTF_Sound_next       serverTime before which the loop must not play
	  PTF_Sound_cut        change to cut the current play instantly
	  PTF_Sound_noDialog   set before calling to skip the placement dialog

	Speaker binding: the object the module was dropped onto in Zeus
	(curator attach), else the nearest prop or vehicle within 5 m -
	re-resolved on every activation, so dragging the module onto a
	different prop rebinds it and releases the old prop's ACE cut action.
	The server broadcasts with say3D from an invisible emitter attached to
	the bound object, so destroying OR deleting the speaker, muting, or
	deleting the module cuts the audio mid-play.
*/
params ["_logic", "_units", "_activated"];

if (!_activated) exitWith {};
if (!local _logic) exitWith {};

private _cfg = configFile >> "CfgVehicles" >> typeOf _logic;
if (getText (_cfg >> "PTF_soundClass") isEqualTo "") exitWith {
	diag_log format ["PTF_Sound: %1 has no PTF_soundClass configured", typeOf _logic];
};

// (Re)resolve the physical speaker on every activation.
private _speaker = attachedTo _logic;
if (isNull _speaker) then {
	private _near = (nearestObjects [_logic, ["Static", "Thing", "LandVehicle", "Ship", "Air"], 5]) select {alive _x};
	if (_near isNotEqualTo []) then {_speaker = _near select 0};
};
private _oldSpeaker = _logic getVariable ["PTF_Sound_speaker", objNull];
if (!isNull _oldSpeaker && {_oldSpeaker isNotEqualTo _speaker}) then {
	// Moved to a different prop: the old one no longer controls this module.
	_oldSpeaker setVariable ["PTF_Sound_logic", objNull, true];
};
_logic setVariable ["PTF_Sound_speaker", _speaker, true];

private _startBroadcast = {
	params ["_logic", "_speaker"];
	// The speaker rides along in the call itself, so the server never
	// depends on publicVariable traffic arriving before the remoteExec.
	[_logic, _speaker] remoteExec ["PTF_Sound_fnc_serverLoop", 2];
};

// Configuration dialog once per module; re-activations (Zeus move/edit) go
// straight back to broadcasting.
if (
	!(_logic getVariable ["PTF_Sound_configured", false])
	&& {!(_logic getVariable ["PTF_Sound_noDialog", false])}
	&& {!isNull curatorCamera} && {isClass (configFile >> "CfgPatches" >> "zen_dialog")}
) exitWith {
	_logic setVariable ["PTF_Sound_configured", true, true];
	[_logic, _startBroadcast] call PTF_Sound_fnc_speakerDialog;
};

[_logic, _speaker] call _startBroadcast;
