/*
 * Author: Paramarine Task Force
 * Counter-battery: where a traced round landed (or burst), added to the track(s) it was traced
 * to while in the air (PTF_GATOR_fnc_cbReport). Server only, from the machine that fired it.
 * Each track keeps its last 12 impacts. A G/ATOR's incoming alarm stops ALARM_TAIL seconds after
 * the last round it traced is down.
 *
 * Arguments:
 * 0: The round's key <STRING>
 * 1: Where it ended, ASL <ARRAY>
 *
 * Return Value:
 * None
 */
#include "..\script_gator.hpp"
params [["_key", "", [""]], ["_end", [], [[]], 3]];

if (!isServer) exitWith {};
private _shots = missionNamespace getVariable ["PTF_GATOR_cbShots", createHashMap];
private _for = _shots getOrDefault [_key, []];
_shots deleteAt _key;
{
	_x params ["_radar", "_id"];
	private _track = ((_radar getVariable ["PTF_GATOR_cbTracks", []]) select {(_x get "id") isEqualTo _id}) param [0, createHashMap];
	private _impacts = _track getOrDefault ["impacts", objNull];
	if (_impacts isEqualType []) then {
		_impacts pushBack [_end select 0, _end select 1];
		if (count _impacts > 12) then {_impacts deleteAt 0};
	};
} forEach _for;
// The incoming alarm stops shortly after the last round its G/ATOR traced is down.
{
	private _radar = _x select 0;
	private _pending = {(_x findIf {(_x select 0) isEqualTo _radar}) >= 0} count values _shots;
	private _until = _radar getVariable ["PTF_GATOR_alarmUntil", -1];
	if (_pending == 0 && {_until > CBA_missionTime + ALARM_TAIL}) then {
		_radar setVariable ["PTF_GATOR_alarmUntil", CBA_missionTime + ALARM_TAIL, true];
	};
} forEach _for;
if (_for isNotEqualTo []) then {call PTF_GATOR_fnc_cbPublish};
