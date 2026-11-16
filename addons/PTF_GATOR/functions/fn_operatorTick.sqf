/*
 * Author: Paramarine Task Force
 * Once a second on the server, from the radar loop: the operator's world around a G/ATOR.
 *
 * - The enemy's fix on it: grows while it transmits (FIX_RATE_FULL, or FIX_RATE_SECTOR staring
 *   at a sector), fades while it's silent (FIX_FADE), and is lost when it moves 50 m. At "good"
 *   or better, if the server setting PTF_GATOR_enemyHunt is on, the enemy fires on it every two
 *   minutes: a mortar team sent for it (PTF_GATOR_fnc_enemyBattery), never the mission's own
 *   artillery, which stays the mission maker's and Zeus's. Their rounds land within the fix's
 *   miss of it. The crew isn't shown the fix: they find out when rounds come in.
 * - CROWS Electronic Warfare: the nearest enabled CROWS jammer (crowsEW_main_jamMap) jams it as
 *   CROWS jams radios: fully inside the jammer's effective radius, fading out across its falloff.
 *   Jammed, it reaches JAM_REACH as far, its error grows up to JAM_ERROR times, and now and then
 *   it shows a ghost firing point (a dwell finds it out), and it is off the network. It hears
 *   any enabled jammer within JAM_HEAR while it is up and powered (its receiver hears even when
 *   it is silent), but its bearing takes the operator: in manual, a sector swept over the
 *   jammer for DF_TIME seconds gives a strobe, a bearing to it, off by up to the sector's width
 *   over DF_SHARP. Strobes from two places, or two G/ATORs, cross on the jammer.
 *   Transmitting, the G/ATOR is itself a CROWS signal source, found with a spectrum device.
 * - What its error and reach are now (for PTF_GATOR_fnc_cbReport, cbWatch).
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Transmitting <BOOL>
 *
 * Return Value:
 * Jamming, 0 to 1 <NUMBER>
 */
#include "..\script_gator.hpp"
params [["_radar", objNull, [objNull]], ["_active", false, [false]]];

private _now = CBA_missionTime;
private _at = getPosASL _radar;
private _receiving = alive _radar && {_radar animationSourcePhase "ptf_gator_deploy" > 0.999} && {[_radar] call PTF_GATOR_fnc_powerState == "on"};
private _sector = _radar getVariable ["PTF_GATOR_mode", "full"] == "sector";

// --- Jamming (CROWS) ------------------------------------------------------------------------------
private _jam = 0;
private _strobes = (_radar getVariable ["PTF_GATOR_strobes", []]) select {_now - (_x select 2) < JAM_STROBE_LIFE};
// [its netId, its true bearing, how far] for each jammer it hears: the crew isn't told the bearing, they find it
private _heard = [];
private _jamMap = missionNamespace getVariable ["crowsEW_main_jamMap", createHashMap];
{
	_y params [["_jammer", objNull], ["_falloff", 0], ["_effective", 0], ["_on", false]];
	if (_on && {alive _jammer}) then {
		private _d = _jammer distance2D _radar;
		_jam = _jam max (linearConversion [_effective, _effective + (_falloff max 1), _d, 1, 0, true]);
		if (_receiving && {_d < JAM_HEAR}) then {_heard pushBack [netId _jammer, _radar getDir _jammer, _d]};
	};
} forEach _jamMap;

// Direction finding, by hand. In manual, sweeping a sector, the receiver reads each jammer's
// signal (0 to 100): strongest with the jammer on the sector's centre line, falling away to
// nothing at its edges, and stronger the narrower the sector (a whole turn barely hears it),
// a little weaker from farther off, and never quite steady. The operator narrows the sector and
// pans it to the strongest signal. A sector no wider than DF_WIDE, with the jammer well inside
// it (the signal at least half what it would be dead centre) and held still DF_TIME seconds,
// takes a bearing: the sector's centre line, give or take what the signal says it's off by.
// So it's only as good as the operator's centring. A new sector starts the count again.
// PTF_GATOR_df: netId -> [the sector, when it was found well inside it (or -1, its bearing taken)]
private _df = _radar getVariable ["PTF_GATOR_df", createHashMap];
private _holding = [];
// the strongest jammer's: [signal (-1 none read), state (seconds to a bearing, 0 taken, -1 the
// sector too wide, -2 off centre, -3 not in the sector)]
private _best = [-1, -3];
if (_receiving && {_sector} && {_radar getVariable ["PTF_GATOR_manual", false]}) then {
	(_radar getVariable ["PTF_GATOR_sector", [0, 90]]) params ["_from", "_to"];
	private _span = ((_to - _from) + 360) % 360;
	if (_span == 0) then {_span = 360};
	private _half = _span / 2;
	private _mid = (_from + _half) % 360;
	private _focus = linearConversion [360, SECTOR_MIN, _span, 0.2, 1, true];
	{
		_x params ["_id", "_bearing", "_d"];
		private _off = abs ((((_bearing - _mid) + 540) % 360) - 180);
		private _beam = [0, 1 - (_off / _half) ^ 2] select (_off < _half);
		private _full = 100 * _focus * linearConversion [0, JAM_HEAR, _d, 1, 0.6, true];
		private _signal = round (0 max (100 min (_full * _beam + random 6 - 3)));
		private _state = call {
			if (_beam <= 0) exitWith {-3};
			if (_span > DF_WIDE) exitWith {-1};
			if (_beam < 0.5) exitWith {-2};
			_holding pushBack _id;
			private _was = _df getOrDefault [_id, []];
			if (_was isEqualTo [] || {(_was select 0) isNotEqualTo [_from, _to]}) then {
				_was = [[_from, _to], _now];
				_df set [_id, _was];
			};
			if ((_was select 1) < 0) exitWith {0};
			private _wait = DF_TIME - (_now - (_was select 1));
			if (_wait > 0) exitWith {ceil _wait};
			// the centre line, and how far off it the signal says the jammer is
			private _err = 2 max round (_half * sqrt (0 max (1 - _signal / _full)) + 1);
			_strobes = _strobes select {!((_x select 3) == _id && {((_x select 0) distance2D _at) < 200})};
			_strobes pushBack [[_at select 0, _at select 1], _mid, _now, _id, _err];
			_df set [_id, [[_from, _to], -1]];
			0
		};
		if (_signal > (_best select 0)) then {_best = [_signal, _state]};
	} forEach _heard;
};
{if !(_x in _holding) then {_df deleteAt _x}} forEach keys _df;
_radar setVariable ["PTF_GATOR_df", _df];
// for its console: [jammers heard, the strongest signal, its state]
private _dfShow = [count _heard] + _best;
if (_dfShow isNotEqualTo (_radar getVariable ["PTF_GATOR_dfShow", [0, -1, -3]])) then {_radar setVariable ["PTF_GATOR_dfShow", _dfShow, true]};
if (_strobes isNotEqualTo (_radar getVariable ["PTF_GATOR_strobes", []])) then {_radar setVariable ["PTF_GATOR_strobes", _strobes, true]};
_jam = (round (_jam * 20)) / 20;
private _wasJam = _radar getVariable ["PTF_GATOR_jam", 0];
if (_jam != _wasJam) then {
	_radar setVariable ["PTF_GATOR_jam", _jam, true];
	// jammed, it drops off the network (PTF_GATOR_fnc_cbPublish); clear, it's back
	if ((_jam == 0) isNotEqualTo (_wasJam == 0)) then {call PTF_GATOR_fnc_cbPublish};
};

// Ghosts: jamming makes up a firing point now and then, off toward the jammer.
if (_active && {_jam > 0.25} && {random 1 < _jam * 0.012}) then {
	private _toward = (_heard param [0, ["", random 360]]) select 1;
	private _ghost = _radar getPos [2000 + random 7000, _toward + random 80 - 40];
	private _range = _ghost distance2D _radar;
	private _id = (missionNamespace getVariable ["PTF_GATOR_cbNext", 0]) + 1;
	missionNamespace setVariable ["PTF_GATOR_cbNext", _id];
	private _tracks = _radar getVariable ["PTF_GATOR_cbTracks", []];
	_tracks pushBack createHashMapFromArray [["id", _id], ["kind", "point"], ["sum", [_ghost select 0, _ghost select 1]],
		["point", [_ghost select 0, _ghost select 1]], ["rounds", 1], ["error", CB_ERROR * _range * (1 + (JAM_ERROR - 1) * _jam)],
		["first", _now], ["last", _now], ["impacts", []], ["ammo", ""], ["weapon", selectRandom ["mortar", "artillery"]], ["false", true]];
	_radar setVariable ["PTF_GATOR_cbTracks", _tracks];
	call PTF_GATOR_fnc_cbPublish;
};

// What its tracing is worth now (PTF_GATOR_fnc_cbReport) and how far it reaches (cbWatch).
_radar setVariable ["PTF_GATOR_errScale", ([1, SECTOR_GAIN] select _sector) * (1 + (JAM_ERROR - 1) * _jam)];
private _reach = round (CB_DETECT * (1 - (1 - JAM_REACH) * _jam));
if (_reach != (_radar getVariable ["PTF_GATOR_reach", -1])) then {_radar setVariable ["PTF_GATOR_reach", _reach, true]};

// --- The enemy's fix -------------------------------------------------------------------------------
private _fixAt = _radar getVariable ["PTF_GATOR_fixAt", _at];
private _fix = _radar getVariable ["PTF_GATOR_fixRaw", 0];
if (_fixAt distance2D _at > 50) then {_fix = 0; _fixAt = _at};
_radar setVariable ["PTF_GATOR_fixAt", _fixAt];
_fix = if (_active) then {_fix + ([FIX_RATE_FULL, FIX_RATE_SECTOR] select _sector)} else {_fix - FIX_FADE};
_fix = 0 max _fix min 1;
_radar setVariable ["PTF_GATOR_fixRaw", _fix];
// 0 none, 1 rough, 2 good, 3 locked
private _level = [FIX_ROUGH, FIX_GOOD, FIX_LOCKED] findIf {_fix < _x};
if (_level < 0) then {_level = 3};
if (_level != (_radar getVariable ["PTF_GATOR_fix", 0])) then {_radar setVariable ["PTF_GATOR_fix", _level, true]};
if (_level >= 2 && {alive _radar} && {_now >= _radar getVariable ["PTF_GATOR_huntAt", 0]} && {missionNamespace getVariable ["PTF_GATOR_enemyHunt", false]}) then {
	_radar setVariable ["PTF_GATOR_huntAt", _now + 120];
	private _miss = FIX_MISS select (_level - 1);
	private _aim = _radar getPos [random _miss, random 360];
	private _own = [east, west, independent, civilian] select (getNumber (configOf _radar >> "side") max 0 min 3);
	diag_log format ["[PTF_GATOR] enemy counter-fire on %1 (fix %2)", _radar, _level];
	[_aim, 4, 0, _own] call PTF_GATOR_fnc_enemyBattery;
};

// --- A CROWS signal while it transmits --------------------------------------------------------------
if (isClass (configFile >> "CfgPatches" >> "crowsEW_spectrum") && {_active isNotEqualTo (_radar getVariable ["PTF_GATOR_beacon", false])}) then {
	_radar setVariable ["PTF_GATOR_beacon", _active];
	if (_active) then {
		// its own frequency on the spectrum device's second antenna (520-1090 MHz): unique per G/ATOR
		private _freq = 990 + (7 * (((missionNamespace getVariable ["PTF_GATOR_all", []]) find _radar) max 0)) % 100;
		["crowsEW_spectrum_addBeacon", [_radar, _freq, 8000, "zeus"]] call CBA_fnc_serverEvent;
	} else {
		["crowsEW_spectrum_removeBeacon", [_radar, "zeus"]] call CBA_fnc_serverEvent;
	};
};

_jam
