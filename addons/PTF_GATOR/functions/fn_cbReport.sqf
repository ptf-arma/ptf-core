/*
 * Author: Paramarine Task Force
 * Counter-battery, at the radar: a G/ATOR saw a round in the air (PTF_GATOR_fnc_cbFired, from
 * the machine that fired it, the moment it came within CB_DETECT metres). Server only. Where it
 * lands is added later (PTF_GATOR_fnc_cbImpact).
 *
 * Fired from within CB_TRACE metres, it traces the round back to a firing point: the true
 * one off in a random direction by, on average, CB_ERROR of its distance (a 2D normal error).
 * Rounds whose points fall close together (within three times that error, or 150 m) are one
 * track, a firing position: its point is the average of theirs, so its error shrinks with the
 * square root of the rounds counted. Fired from further off, it only has a bearing: rounds on
 * the same bearing (within 4 degrees) are one bearing track.
 *
 * Tracks live on the radar (PTF_GATOR_cbTracks, server only) and reach the tablets only while
 * it is cabled to a SATCOM antenna (PTF_GATOR_fnc_cbPublish).
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Where it was fired from, ASL <ARRAY>
 * 2: Ammo class <STRING>
 * 3: The round's key, for its impact <STRING>
 * 4: What fired it, "mortar" or "artillery" <STRING>
 * 5: Where it will come down, [x, y] (default: [], not known) <ARRAY>
 * 6: In how many seconds <NUMBER>
 *
 * Return Value:
 * None
 */
#include "..\script_gator.hpp"
params [["_radar", objNull, [objNull]], ["_from", [], [[]], 3], ["_ammo", "", [""]], ["_key", "", [""]], ["_weapon", "artillery", [""]], ["_splash", [], [[]]], ["_eta", 0, [0]]];

if (!isServer || {!alive _radar}) exitWith {};

private _at = getPosASL _radar;
private _range = _from distance2D _at;
private _tracks = _radar getVariable ["PTF_GATOR_cbTracks", []];
private _now = CBA_missionTime;
private _gauss = {sqrt (-2 * ln ((random 1) max 1e-9)) * cos (random 360)};
// Staring at a sector traces better; jamming worse (PTF_GATOR_fnc_operatorTick).
private _err = CB_ERROR * (_radar getVariable ["PTF_GATOR_errScale", 1]);
private _name = getText (configFile >> "CfgAmmo" >> _ammo >> "displayName");

if (_range > CB_TRACE) then {
	private _bearing = _at getDir _from;
	private _i = _tracks findIf {_x get "kind" == "bearing" && {abs (((_x get "bearing") - _bearing + 540) % 360 - 180) < 4}};
	if (_i < 0) then {
		private _id = (missionNamespace getVariable ["PTF_GATOR_cbNext", 0]) + 1;
		missionNamespace setVariable ["PTF_GATOR_cbNext", _id];
		_tracks pushBack createHashMapFromArray [["id", _id], ["kind", "bearing"], ["bearing", _bearing], ["rounds", 1],
			["first", _now], ["last", _now], ["radarAt", [_at select 0, _at select 1]], ["ammo", _name], ["weapon", _weapon]];
	} else {
		private _track = _tracks select _i;
		private _n = _track get "rounds";
		// the average bearing, as a vector average so 359 and 1 make 0
		private _b = _track get "bearing";
		_track set ["bearing", ((((sin _b) * _n + sin _bearing) atan2 ((cos _b) * _n + cos _bearing)) + 360) % 360];
		_track set ["rounds", _n + 1];
		_track set ["last", _now];
	};
} else {
	private _sigma = _err * _range / 1.2533;   // per axis, for a mean miss of _err * range
	private _point = [(_from select 0) + _sigma * call _gauss, (_from select 1) + _sigma * call _gauss];
	private _join = (3 * _err * _range) max 150;
	private _best = -1;
	private _bestDistance = _join;
	{
		// (never one jamming made up: a real round starts its own track)
		if (_x get "kind" == "point" && {!(_x getOrDefault ["false", false])}) then {
			private _d = _point distance2D (_x get "point");
			if (_d < _bestDistance) then {_best = _forEachIndex; _bestDistance = _d};
		};
	} forEach _tracks;
	if (_best < 0) then {
		private _id = (missionNamespace getVariable ["PTF_GATOR_cbNext", 0]) + 1;
		missionNamespace setVariable ["PTF_GATOR_cbNext", _id];
		_tracks pushBack createHashMapFromArray [["id", _id], ["kind", "point"], ["sum", _point], ["point", _point],
			["rounds", 1], ["error", _err * _range], ["first", _now], ["last", _now], ["impacts", []],
			["truth", [_from select 0, _from select 1]], ["ammo", _name], ["weapon", _weapon], ["var", (_err * _range) ^ 2]];
		_best = count _tracks - 1;
	} else {
		private _track = _tracks select _best;
		private _n = (_track get "rounds") + 1;
		private _sum = (_track get "sum") vectorAdd _point;
		_track set ["sum", _sum];
		_track set ["point", _sum vectorMultiply (1 / _n)];
		_track set ["rounds", _n];
		// each round's own error counted as it was, so the track's is their average over sqrt n
		private _var = (_track getOrDefault ["var", 0]) + (_err * _range) ^ 2;
		_track set ["var", _var];
		_track set ["error", (sqrt _var) / _n];
		_track set ["last", _now];
		_track set ["ammo", _name];
	};
	// where this round lands goes on this track (PTF_GATOR_fnc_cbImpact)
	if (_key != "") then {
		private _shots = missionNamespace getVariable ["PTF_GATOR_cbShots", createHashMap];
		_shots set [_key, (_shots getOrDefault [_key, []]) + [[_radar, (_tracks select _best) get "id"]]];
		missionNamespace setVariable ["PTF_GATOR_cbShots", _shots];
	};
};
_radar setVariable ["PTF_GATOR_cbTracks", _tracks];
// Where it will come down (a little off: the radar's prediction): drawn on the tablets until
// then, and everyone within SPLASH_WARN metres of it is warned, if this G/ATOR is on the network.
if (_splash isNotEqualTo []) then {
	_splash = _splash vectorAdd [random 30 - 15, random 30 - 15];
	private _lands = _now + _eta;
	private _splashes = (_radar getVariable ["PTF_GATOR_splashes", []]) select {(_x select 1) > _now - 5};
	_splashes pushBack [_splash, _lands];
	_radar setVariable ["PTF_GATOR_splashes", _splashes, true];
	if (!isNull (_radar getVariable ["PTF_GATOR_satcom", objNull]) && {_eta > 2}) then {
		// once every eight seconds a player at most, however many rounds are coming
		private _warned = missionNamespace getVariable ["PTF_GATOR_warnedAt", createHashMap];
		missionNamespace setVariable ["PTF_GATOR_warnedAt", _warned];
		{
			if (_x distance2D _splash < SPLASH_WARN && {_now >= _warned getOrDefault [getPlayerUID _x, 0]}) then {
				_warned set [getPlayerUID _x, _now + 8];
				[_splash, _lands] remoteExecCall ["PTF_GATOR_fnc_splashWarn", _x];
			};
		} forEach allPlayers;
	};
};
// The incoming alarm, where its crew switched it on: from now until shortly after the last
// traced round lands (PTF_GATOR_fnc_cbImpact), ALARM_HOLD seconds at most without news.
if (_radar getVariable ["PTF_GATOR_alarm", false]) then {
	_radar setVariable ["PTF_GATOR_alarmUntil", _now + ALARM_HOLD, true];
};
diag_log format ["[PTF_GATOR] counter-battery: %1 saw a round (%2) fired %3 m off", _radar, _ammo, round _range];
call PTF_GATOR_fnc_cbPublish;
