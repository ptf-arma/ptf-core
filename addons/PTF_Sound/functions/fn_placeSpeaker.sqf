/*
	Server-side placement, used by the browse flow (and usable by mission
	scripts). Creating the logic on the server avoids every client-created
	object race and lets addCuratorEditableObjects run where the curator
	logic is local, so the placed module is Zeus-editable on dedicated
	servers too.

	[_class, _posASL, _distance, _pause, _muted, _spawnProp, _curator]
		remoteExec ["PTF_Sound_fnc_placeSpeaker", 2];

	_distance <= 0 / _pause < 0 mean "use the sound's defaults".
	_spawnProp true creates a visible loudspeaker prop at the position and
	binds the broadcast to it: one-step placement of a speaker that players
	can see, shoot, or ACE-cut.
*/
params ["_class", "_posASL", ["_distance", 0], ["_pause", -1], ["_muted", false], ["_spawnProp", false], ["_curator", objNull]];

if (!isServer) exitWith {};
if (!isClass (configFile >> "CfgVehicles" >> _class)) exitWith {
	diag_log format ["PTF_Sound: placeSpeaker got unknown class %1", _class];
};

private _editable = [];
if (_spawnProp) then {
	if (isClass (configFile >> "CfgVehicles" >> "Land_Loudspeakers_F")) then {
		private _prop = createVehicle ["Land_Loudspeakers_F", ASLToAGL _posASL, [], 0, "CAN_COLLIDE"];
		_prop setPosASL _posASL;
		_editable pushBack _prop;
	} else {
		diag_log "PTF_Sound: Land_Loudspeakers_F not available, placing module unbound";
	};
};

// deleteWhenEmpty group, so cut/deleted modules do not leak logic groups.
private _logic = (createGroup [sideLogic, true]) createUnit [_class, ASLToAGL _posASL, [], 0, "CAN_COLLIDE"];
_logic setPosASL _posASL;
if (_distance > 0) then {_logic setVariable ["PTF_Sound_distance", _distance, true]};
if (_pause >= 0) then {_logic setVariable ["PTF_Sound_pause", _pause, true]};
_logic setVariable ["PTF_Sound_paused", _muted, true];
_logic setVariable ["PTF_Sound_noDialog", true];
_editable pushBack _logic;
if (!isNull _curator) then {_curator addCuratorEditableObjects [_editable, false]};

// The logic is server-local here, so the module flow runs with no network
// round-trip at all; the nearest-object binding picks up the spawned prop.
[_logic, [], true] call PTF_Sound_fnc_moduleSpeaker;
