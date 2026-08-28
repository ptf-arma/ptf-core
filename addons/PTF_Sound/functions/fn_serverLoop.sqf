/*
	Server-side broadcast loop for one loudspeaker module. Started via
	remoteExec by PTF_Sound_fnc_moduleSpeaker; the server owns the
	activation generation and all scheduling, so a curator disconnecting
	never silences a broadcast, and no client/server variable-ordering race
	can drop an activation (the speaker binding rides in the call args).

	[_logic, _speaker] call PTF_Sound_fnc_serverLoop;   // (on the server)

	Sound is emitted with say3D from an invisible helper attached to the
	bound speaker, or sat at the module when unbound. say3D has local
	effect, so the server tells every machine to run it on that shared
	emitter (a dedicated server playing it itself is heard by nobody).
	say3D dies with its emitter: Mute / Broadcast now (a PTF_Sound_cut
	bump), destroying OR deleting the bound speaker, and module deletion
	all cut the audio mid-play on every client at once. The emitter is
	stored on the logic and reused across activations, so a Zeus move
	never interrupts the play in progress.

	Scheduling is strictly per module: play when serverTime reaches the
	module's own PTF_Sound_next and it is not paused. Playlist modules
	(PTF_playlist[] of sound base names) rotate through their items; a
	plain module is a one-item playlist.
*/
params ["_logic", ["_speaker", objNull]];

if (!isServer) exitWith {};
if (isNull _logic) exitWith {
	diag_log "PTF_Sound: serverLoop received a null logic - broadcast dropped";
};

// Server-authoritative generation: bumped here in one unscheduled step, so
// every activation gets a unique generation and stale loops retire cleanly.
private _gen = (_logic getVariable ["PTF_Sound_gen", 0]) + 1;
_logic setVariable ["PTF_Sound_gen", _gen];

[_logic, _speaker, _gen] spawn {
	params ["_logic", "_speaker", "_gen"];
	private _cfgVehicles = configFile >> "CfgVehicles";
	private _cfg = _cfgVehicles >> typeOf _logic;
	private _cfgDistance = getNumber (_cfg >> "PTF_distance");
	private _cfgPause = getNumber (_cfg >> "PTF_pause");
	private _wasBound = !isNull _speaker;

	// [[soundClass, duration], ...] - playlist items read their data from
	// their own module configs so nothing is duplicated.
	private _items = (getArray (_cfg >> "PTF_playlist")) apply {
		private _itemCfg = _cfgVehicles >> ("PTF_Sound_Module_" + _x);
		[getText (_itemCfg >> "PTF_soundClass"), getNumber (_itemCfg >> "PTF_duration")]
	};
	if (_items isEqualTo []) then {
		_items = [[getText (_cfg >> "PTF_soundClass"), getNumber (_cfg >> "PTF_duration")]];
	};

	// One idempotent seat function owns emitter creation and placement.
	private _seatEmitter = {
		params ["_logic", "_speaker"];
		private _emitter = _logic getVariable ["PTF_Sound_emitter", objNull];
		if (isNull _emitter) then {
			_emitter = createVehicle ["Land_HelipadEmpty_F", getPos _logic, [], 0, "CAN_COLLIDE"];
			_logic setVariable ["PTF_Sound_emitter", _emitter];
		};
		detach _emitter;
		if (isNull _speaker) then {
			_emitter setPos (getPos _logic);
		} else {
			_emitter attachTo [_speaker, [0, 0, 1]];
		};
		_emitter
	};
	// Reused across activations so a Zeus move never interrupts the
	// current play; re-seated on whatever the module is now bound to.
	private _emitter = [_logic, _speaker] call _seatEmitter;
	// Give the emitter's creation time to reach clients before the first
	// say3D references it; a client that has not seen the object yet would
	// resolve objNull and silently play nothing.
	sleep 0.5;

	// ACE "cut the power" on the physical speaker: one generic action per
	// speaker (JIP-queued per speaker) reading the bound module live.
	private _jip = "";
	if (_wasBound) then {
		_speaker setVariable ["PTF_Sound_logic", _logic, true];
		_jip = format ["PTF_Sound_cut_%1", netId _speaker];
		if (isClass (configFile >> "CfgPatches" >> "ace_interact_menu")) then {
			[_speaker] remoteExec ["PTF_Sound_fnc_addCutAction", 0, _jip];
		};
	};

	private _lastCut = _logic getVariable ["PTF_Sound_cut", 0];
	private _lastPos = getPosATL _logic;
	while {
		!isNull _logic
		&& {_gen == _logic getVariable ["PTF_Sound_gen", 0]}
		&& {!_wasBound || {alive _speaker}}   // deleted speaker -> objNull -> alive false
	} do {
		// Cut request (Mute, Broadcast now): kill the emitter - the current
		// play stops dead - and stand up a fresh one for the next play.
		private _cut = _logic getVariable ["PTF_Sound_cut", 0];
		if (_cut != _lastCut) then {
			_lastCut = _cut;
			deleteVehicle _emitter;
			_logic setVariable ["PTF_Sound_emitter", objNull];
			_emitter = [_logic, _speaker] call _seatEmitter;
		};
		if (!_wasBound) then {
			private _pos = getPosATL _logic;
			if (_pos isNotEqualTo _lastPos) then {
				_lastPos = _pos;
				_emitter setPos _pos;
			};
		};

		private _now = serverTime;
		if (
			!(_logic getVariable ["PTF_Sound_paused", false])
			&& {_now >= _logic getVariable ["PTF_Sound_next", 0]}
		) then {
			private _idx = _logic getVariable ["PTF_Sound_index", 0];
			(_items select (_idx mod count _items)) params ["_class", "_duration"];
			private _distance = _logic getVariable ["PTF_Sound_distance", 0];
			if (_distance <= 0) then {_distance = _cfgDistance};
			private _pause = _logic getVariable ["PTF_Sound_pause", -1];
			if (_pause < 0) then {_pause = _cfgPause};
			// say3D has LOCAL effect: a dedicated server executing it is
			// silent for everyone (the server has no sound engine and
			// nothing propagates). Each machine must run it itself, on the
			// server-owned emitter every machine already knows, so the
			// audio still dies when the server deletes that emitter.
			[_emitter, [_class, _distance]] remoteExec ["say3D", 0];
			_logic setVariable ["PTF_Sound_next", _now + _duration + _pause, true];
			_logic setVariable ["PTF_Sound_index", _idx + 1];
		};
		sleep 1;
	};

	// Superseded by a newer activation: hand the emitter over untouched so
	// the in-flight play carries across a Zeus move.
	if (!isNull _logic && {_gen != _logic getVariable ["PTF_Sound_gen", 0]}) exitWith {};

	// Module deleted, or bound speaker destroyed/deleted: cut the audio
	// right now, release the speaker, clean up the module.
	deleteVehicle _emitter;
	if (_wasBound && {!alive _speaker}) then {
		remoteExec ["", _jip];
	};
	if (_wasBound && {!isNull _speaker} && {(_speaker getVariable ["PTF_Sound_logic", objNull]) isEqualTo _logic}) then {
		_speaker setVariable ["PTF_Sound_logic", objNull, true];
	};
	if (!isNull _logic) then {
		// The logic may be local to a curator - delete it where it lives.
		_logic remoteExec ["deleteVehicle", _logic];
	};
};
