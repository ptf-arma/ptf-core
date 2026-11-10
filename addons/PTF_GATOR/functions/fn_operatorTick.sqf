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
 *   it shows a ghost firing point (a dwell finds it out). Any enabled jammer within JAM_HEAR
 *   leaves a strobe, a bearing to it, while the G/ATOR is up and powered (its receiver hears
 *   even when it is silent); strobes from two places, or two G/ATORs, cross on the jammer.
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
private _jamMap = missionNamespace getVariable ["crowsEW_main_jamMap", createHashMap];
{
	_y params [["_jammer", objNull], ["_falloff", 0], ["_effective", 0], ["_on", false]];
	if (_on && {alive _jammer}) then {
		private _d = _jammer distance2D _radar;
		_jam = _jam max (linearConversion [_effective, _effective + (_falloff max 1), _d, 1, 0, true]);
		if (_receiving && {_d < JAM_HEAR}) then {
			// a strobe from here, unless one from near here is already up for this jammer
			private _id = netId _jammer;
			if (_strobes findIf {(_x select 3) == _id && {((_x select 0) distance2D _at) < 200}} < 0) then {
				_strobes pushBack [[_at select 0, _at select 1], ((_radar getDir _jammer) + random 4 - 2 + 360) % 360, _now, _id];
			};
		};
	};
} forEach _jamMap;
if (_strobes isNotEqualTo (_radar getVariable ["PTF_GATOR_strobes", []])) then {_radar setVariable ["PTF_GATOR_strobes", _strobes, true]};
_jam = (round (_jam * 20)) / 20;
if (_jam != (_radar getVariable ["PTF_GATOR_jam", 0])) then {_radar setVariable ["PTF_GATOR_jam", _jam, true]};

// Ghosts: jamming makes up a firing point now and then, off toward the jammer.
if (_active && {_jam > 0.25} && {random 1 < _jam * 0.012}) then {
	private _toward = (_strobes param [count _strobes - 1, [0, 0, random 360]]) select 1;
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
