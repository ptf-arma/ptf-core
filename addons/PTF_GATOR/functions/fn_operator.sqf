/*
 * Author: Paramarine Task Force
 * The radar operator's controls, from the operator computer's console (PTF_GATOR_fnc_console)
 * or its ACE actions. Runs on the server (called anywhere). Only a player within OP_RANGE
 * metres of the G/ATOR works it, or Zeus.
 *
 *   "manual", "auto"      who has it. Automatic (the default): it turns all the way round and
 *                         transmits by itself, and doesn't defend itself. Manual takes its
 *                         operator computer, cabled in (PTF_GATOR_fnc_computer); the commands
 *                         below up to "iff" work only in manual. Back to automatic, it turns
 *                         all the way round and transmits again.
 *   "silent", "transmit"  emissions control: silent, it sees nothing and can't be found by its
 *                         emissions (an anti-radiation missile loses it), and the enemy's fix
 *                         on it fades
 *   "full"                the array turns all the way round: sees everything
 *   "sector"              the array sweeps back and forth across a sector (PTF_GATOR_fnc_sweep),
 *                         at first 90 degrees round where it faces: rounds and aircraft
 *                         outside it go unseen, inside it each round's error is SECTOR_GAIN of
 *                         usual, and the enemy's fix grows more slowly
 *   "sectorFrom", "sectorTo" (key: a bearing)  the sector's edges, clockwise from one to the
 *                         other; at least SECTOR_MIN degrees apart
 *   "dwell" (key: track)  the array turns to stare at one counter-battery track for DWELL_TIME
 *                         seconds: its error comes down by DWELL_GAIN, or, if jamming made
 *                         it up, it is shown to be false and goes. Nothing else is watched
 *                         meanwhile.
 *   "iff" (key: aircraft) the same stare at an aircraft: the radar interrogates it, and it shows
 *                         as friendly or hostile from then on
 *   "alarmOn", "alarmOff" the incoming alarm at the trailer
 *   "erase" (key: track)  a counter-battery track is erased; "clear": all of this G/ATOR's
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Command <STRING>
 * 2: Key: a track number, an aircraft's netId or a bearing, as text <STRING> (default: "")
 * 3: Who <OBJECT> (default: objNull: Zeus or a script)
 *
 * Return Value:
 * None
 *
 * Example:
 * [_radar, "sectorTo", "135", player] call PTF_GATOR_fnc_operator
 */
#include "..\script_gator.hpp"
params [["_radar", objNull, [objNull]], ["_cmd", "", [""]], ["_key", "", [""]], ["_who", objNull, [objNull]]];

if (!isServer) exitWith {[_radar, _cmd, _key, _who] remoteExecCall ["PTF_GATOR_fnc_operator", 2]};
if (!alive _radar) exitWith {};
if (!isNull _who && {!(_who in (allCurators apply {getAssignedCuratorUnit _x}))} && {_who distance _radar > OP_RANGE}) exitWith {};

private _tell = {
	params ["_text"];
	if (!isNull _who && {isPlayer _who}) then {[_text, 1.5] remoteExecCall ["ace_common_fnc_displayTextStructured", _who]};
};
// Which way the array faces (PTF_GATOR_fnc_facing), and the turntable phase that faces a bearing
// (one turn per unit of phase, anticlockwise from above: the nearer way round from where it is).
private _facing = {[_radar] call PTF_GATOR_fnc_facing};
private _point = {
	params ["_bearing"];
	private _turn = ((_bearing - call _facing) + 540) % 360 - 180;
	_radar setVariable ["PTF_GATOR_spinning", false, true];
	_radar animateSource ["ptf_gator_spin", (_radar animationSourcePhase "ptf_gator_spin") - _turn / 360];
};
private _deployed = _radar animationSourcePhase "ptf_gator_deploy" > 0.999 && {[_radar] call PTF_GATOR_fnc_powerState == "on"};
private _inSector = {
	params ["_bearing"];
	(_radar getVariable ["PTF_GATOR_sector", [0, 360]]) params ["_from", "_to"];
	(((_bearing - _from) + 360) % 360) <= (((_to - _from) + 360) % 360)
};

// The radar's own controls are the operator's, in manual only.
if (_cmd in ["silent", "transmit", "full", "sector", "sectorFrom", "sectorTo", "dwell", "iff"] && {!(_radar getVariable ["PTF_GATOR_manual", false])}) exitWith {
	["Automatic control: take manual control at the operator computer first."] call _tell;
};

switch (_cmd) do {
	case "manual": {
		if (isNull (_radar getVariable ["PTF_GATOR_console", objNull])) exitWith {
			["Manual control needs the operator computer, cabled in."] call _tell;
		};
		_radar setVariable ["PTF_GATOR_manual", true, true];
	};
	case "auto": {
		_radar setVariable ["PTF_GATOR_manual", false, true];
		_radar setVariable ["PTF_GATOR_emcon", false, true];
		// sweeping a sector or staring at a track: back to all the way round
		if (_radar getVariable ["PTF_GATOR_mode", "full"] == "sector" || {!isNil {_radar getVariable "PTF_GATOR_dwell"}}) then {
			_radar setVariable ["PTF_GATOR_mode", "full", true];
			_radar setVariable ["PTF_GATOR_dwell", nil, true];
			if (_deployed) then {[_radar, true] call PTF_GATOR_fnc_setSpinning};
		};
	};
	case "alarmOn": {_radar setVariable ["PTF_GATOR_alarm", true, true]};
	case "alarmOff": {
		_radar setVariable ["PTF_GATOR_alarm", false, true];
		_radar setVariable ["PTF_GATOR_alarmUntil", -1, true];
	};
	case "erase": {[parseNumber _key] call PTF_GATOR_fnc_cbErase};
	case "clear": {[_radar] call PTF_GATOR_fnc_cbClear};
	case "silent": {_radar setVariable ["PTF_GATOR_emcon", true, true]};
	case "transmit": {_radar setVariable ["PTF_GATOR_emcon", false, true]};
	case "full": {
		if (!_deployed) exitWith {};
		_radar setVariable ["PTF_GATOR_mode", "full", true];
		_radar setVariable ["PTF_GATOR_dwell", nil, true];
		[_radar, true] call PTF_GATOR_fnc_setSpinning;
	};
	case "sector": {
		if (!_deployed) exitWith {};
		// a sector it had before, else 90 degrees round where it faces now
		if (isNil {_radar getVariable "PTF_GATOR_sector"}) then {
			private _mid = round ((call _facing) / 5) * 5;
			_radar setVariable ["PTF_GATOR_sector", [(_mid - 45 + 360) % 360, (_mid + 45) % 360], true];
		};
		// stop the turning where it is; the sweep takes it from there
		_radar setVariable ["PTF_GATOR_spinning", false, true];
		_radar animateSource ["ptf_gator_spin", _radar animationSourcePhase "ptf_gator_spin"];
		_radar setVariable ["PTF_GATOR_mode", "sector", true];
		[_radar] call PTF_GATOR_fnc_sweep;
	};
	case "sectorFrom";
	case "sectorTo": {
		private _bearing = ((round parseNumber _key) % 360 + 360) % 360;
		(_radar getVariable ["PTF_GATOR_sector", [0, 90]]) params ["_from", "_to"];
		if (_cmd == "sectorFrom") then {_from = _bearing} else {_to = _bearing};
		if ((((_to - _from) + 360) % 360) < SECTOR_MIN) exitWith {
			[format ["A sector is %1 degrees across at least.", SECTOR_MIN]] call _tell;
		};
		_radar setVariable ["PTF_GATOR_sector", [_from, _to], true];
	};
	case "dwell";
	case "iff": {
		if (!_deployed || {_radar getVariable ["PTF_GATOR_emcon", false]}) exitWith {["The G/ATOR must be up and transmitting to look closer."] call _tell};
		if (!isNil {_radar getVariable "PTF_GATOR_dwell"}) exitWith {["The array is already staring at a track."] call _tell};
		private _at = [];
		if (_cmd == "dwell") then {
			private _track = ((_radar getVariable ["PTF_GATOR_cbTracks", []]) select {str (_x get "id") == _key && {(_x get "kind") == "point"}}) param [0, createHashMap];
			_at = _track getOrDefault ["point", []];
		} else {
			private _plane = objectFromNetId _key;
			if (alive _plane) then {_at = getPosASL _plane};
		};
		if (_at isEqualTo []) exitWith {};
		private _bearing = _radar getDir _at;
		// in sector mode, only within its sector
		if (_radar getVariable ["PTF_GATOR_mode", "full"] == "sector" && {!([_bearing] call _inSector)}) exitWith {
			["That's outside the sector. Widen the sector, or go to full turn."] call _tell;
		};
		_radar setVariable ["PTF_GATOR_dwell", [_cmd, _key, CBA_missionTime + DWELL_TIME, _bearing], true];
		[_bearing] call _point;
		[{
			params ["_radar", "_cmd", "_key"];
			private _dwell = _radar getVariable ["PTF_GATOR_dwell", []];
			if !(_dwell isEqualTo [] || {(_dwell select 1) != _key}) then {
				_radar setVariable ["PTF_GATOR_dwell", nil, true];
				if (_cmd == "dwell") then {
					private _tracks = _radar getVariable ["PTF_GATOR_cbTracks", []];
					private _i = _tracks findIf {str (_x get "id") == _key};
					if (_i >= 0) then {
						private _track = _tracks select _i;
						if (_track getOrDefault ["false", false]) then {
							// jamming's ghost: no return
							_tracks deleteAt _i;
						} else {
							_track set ["error", (_track get "error") * DWELL_GAIN];
							_track set ["var", (_track getOrDefault ["var", 0]) * DWELL_GAIN ^ 2];
							_track set ["dwelt", true];
						};
					};
				} else {
					private _plane = objectFromNetId _key;
					if (!isNull _plane) then {
						private _iff = _radar getVariable ["PTF_GATOR_iff", createHashMap];
						// friend or foe to the G/ATOR's own side, by its crew; an empty aircraft is neutral
						private _own = [east, west, independent, civilian] select (getNumber (configOf _radar >> "side") max 0 min 3);
						private _crew = crew _plane;
						_iff set [_key, ["neutral", ["enemy", "friendly"] select ((side group (_crew select 0)) getFriend _own >= 0.6)] select (_crew isNotEqualTo [])];
						_radar setVariable ["PTF_GATOR_iff", _iff, true];
					};
				};
				// back to watching as before (a sweep carries on by itself)
				if (_radar getVariable ["PTF_GATOR_mode", "full"] != "sector") then {[_radar, true] call PTF_GATOR_fnc_setSpinning};
				call PTF_GATOR_fnc_cbPublish;
			};
		}, [_radar, _cmd, _key], DWELL_TIME] call CBA_fnc_waitAndExecute;
	};
};
call PTF_GATOR_fnc_cbPublish;
