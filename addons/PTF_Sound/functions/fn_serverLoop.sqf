/*
	Server-side broadcast loop for one loudspeaker module. Started by
	PTF_Sound_fnc_moduleSpeaker via remoteExec so the broadcast survives the
	placing curator disconnecting.

	[_logic, _gen] call PTF_Sound_fnc_serverLoop;

	The sound is emitted with say3D from an invisible helper object
	("Land_HelipadEmpty_F") attached to the bound speaker, or sat at the
	module when unbound. say3D dies with its emitter, so deleting the emitter
	cuts the audio MID-PLAY - that is the stop mechanism behind Mute,
	Broadcast now, speaker destruction, module deletion, and the ACE
	cut-the-power interaction. The emitter is stored on the logic and reused
	across activations, so a Zeus move never interrupts a play in progress.

	Playlist modules (PTF_playlist[] holding sound base names) rotate through
	their items; a plain module is treated as a one-item playlist. The
	rotation index persists on the logic across moves and re-activations.
*/
params ["_logic", "_gen"];

if (!isServer) exitWith {};
if (isNull _logic) exitWith {};
if (_logic getVariable ["PTF_Sound_loop", -1] >= _gen) exitWith {};
_logic setVariable ["PTF_Sound_loop", _gen];

[_logic, _gen] spawn {
	params ["_logic", "_gen"];
	private _cfgVehicles = configFile >> "CfgVehicles";
	private _cfg = _cfgVehicles >> typeOf _logic;
	private _cfgDistance = getNumber (_cfg >> "PTF_distance");
	private _cfgPause = getNumber (_cfg >> "PTF_pause");

	// [[soundClass, duration], ...] - per-item data comes from each item's
	// own module config so playlists never duplicate durations.
	private _items = (getArray (_cfg >> "PTF_playlist")) apply {
		private _itemCfg = _cfgVehicles >> ("PTF_Sound_Module_" + _x);
		[getText (_itemCfg >> "PTF_soundClass"), getNumber (_itemCfg >> "PTF_duration")]
	};
	if (_items isEqualTo []) then {
		_items = [[getText (_cfg >> "PTF_soundClass"), getNumber (_cfg >> "PTF_duration")]];
	};

	private _speaker = _logic getVariable ["PTF_Sound_speaker", objNull];

	private _makeEmitter = {
		params ["_logic", "_speaker"];
		private _emitter = createVehicle ["Land_HelipadEmpty_F", getPos _logic, [], 0, "CAN_COLLIDE"];
		if (!isNull _speaker) then {
			_emitter attachTo [_speaker, [0, 0, 1]];
		} else {
			_emitter setPos (getPos _logic);
		};
		_logic setVariable ["PTF_Sound_emitter", _emitter, true];
		_emitter
	};

	// Reuse the emitter across activations so a Zeus move never interrupts
	// the current play; re-seat it on whatever the module is now bound to.
	private _emitter = _logic getVariable ["PTF_Sound_emitter", objNull];
	if (isNull _emitter) then {
		_emitter = [_logic, _speaker] call _makeEmitter;
	} else {
		detach _emitter;
		if (!isNull _speaker) then {_emitter attachTo [_speaker, [0, 0, 1]]};
	};

	// ACE "cut the power" on the physical speaker, for all clients incl. JIP.
	private _jip = format ["PTF_Sound_cut_%1", netId _logic];
	if (!isNull _speaker && {isClass (configFile >> "CfgPatches" >> "ace_interact_menu")}) then {
		[_speaker, _logic] remoteExec ["PTF_Sound_fnc_addCutAction", 0, _jip];
	};

	private _lastCut = _logic getVariable ["PTF_Sound_cut", 0];
	while {
		!isNull _logic
		&& {_gen == _logic getVariable ["PTF_Sound_gen", 0]}
		&& {isNull _speaker || {alive _speaker}}
	} do {
		// Cut request (Mute, Broadcast now): kill the emitter - the current
		// play stops dead - and stand up a fresh one for the next play.
		private _cut = _logic getVariable ["PTF_Sound_cut", 0];
		if (_cut != _lastCut) then {
			_lastCut = _cut;
			deleteVehicle _emitter;
			_emitter = [_logic, _speaker] call _makeEmitter;
		};
		if (isNull _speaker) then {_emitter setPos (getPos _logic)};

		private _now = serverTime;
		private _idx = _logic getVariable ["PTF_Sound_index", 0];
		(_items select (_idx mod count _items)) params ["_class", "_duration"];
		private _lastKey = format ["PTF_Sound_last_%1", _class];
		private _last = missionNamespace getVariable [_lastKey, -1e9];
		private _pause = _logic getVariable ["PTF_Sound_pause", -1];
		if (_pause < 0) then {_pause = _cfgPause};
		private _next = _logic getVariable ["PTF_Sound_next", 0];
		if (_next == 0 && {_now < _last + _duration}) then {
			// This sound is already mid-play (typically the module was
			// recreated by a Zeus move) - fall in with its cadence instead
			// of restarting the line on top of it.
			_next = _last + _duration + _pause;
			_logic setVariable ["PTF_Sound_next", _next, true];
		};
		if (
			!(_logic getVariable ["PTF_Sound_paused", false])
			&& {_now >= _next}
			&& {_now >= _last + _duration}
		) then {
			private _distance = _logic getVariable ["PTF_Sound_distance", 0];
			if (_distance <= 0) then {_distance = _cfgDistance};
			// say3D on the server has global effect and follows the emitter.
			_emitter say3D [_class, _distance];
			missionNamespace setVariable [_lastKey, _now, true];
			_logic setVariable ["PTF_Sound_next", _now + _duration + _pause, true];
			_logic setVariable ["PTF_Sound_index", _idx + 1, true];
		};
		sleep 1;
	};

	// Superseded by a newer activation: hand the emitter over untouched so
	// the in-flight play carries across a Zeus move.
	if (!isNull _logic && {_gen != _logic getVariable ["PTF_Sound_gen", 0]}) exitWith {};

	// Module deleted, or bound speaker destroyed: cut the audio right now,
	// clear the JIP-queued ACE action, clean up the module.
	deleteVehicle _emitter;
	remoteExec ["", _jip];
	if (!isNull _logic) then {
		// The logic may be local to a curator - delete it where it lives.
		_logic remoteExec ["deleteVehicle", _logic];
	};
};
