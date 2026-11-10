/*
 * Author: Paramarine Task Force
 * Counter-battery: one look at the rounds this machine has in the air (PTF_GATOR_cbFlights),
 * ten times a second from PTF_GATOR_fnc_cbFired's handler. A transmitting G/ATOR traces a
 * round the moment it is both within CB_DETECT metres and in its line of sight: hills and
 * ridges hide a round from the array (CB_EYE metres up) until it climbs into view. Buildings
 * and trees don't: a radar sees past them.
 *
 * Kept cheap for big fire missions: the sight line (terrainIntersectASL, terrain only) is only
 * drawn for a round already within range of a G/ATOR, at most every CB_LOOK seconds per round,
 * and never again for a G/ATOR that has traced it.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * Rounds still in the air <NUMBER>
 */
#include "..\script_gator.hpp"

private _radars = missionNamespace getVariable ["PTF_GATOR_cbRadars", []];
// Where a round will come down, and in how many seconds: its flight run on from here, under
// gravity and its ammo's air friction, half a second a step, until it meets the ground.
// Done once per round, the moment it is traced.
private _predict = {
	params ["_projectile", "_p", "_ammo"];
	private _v = velocity _projectile;
	private _k = getNumber (configFile >> "CfgAmmo" >> _ammo >> "airFriction");
	private _t = 0;
	for "_i" from 1 to 300 do {
		_v = _v vectorAdd (([0, 0, -9.81] vectorAdd (_v vectorMultiply (_k * vectorMagnitude _v))) vectorMultiply 0.5);
		_p = _p vectorAdd (_v vectorMultiply 0.5);
		_t = _t + 0.5;
		if ((_v select 2) < 0 && {(_p select 2) < getTerrainHeightASL _p}) exitWith {};
	};
	[[_p select 0, _p select 1], _t]
};
private _now = CBA_missionTime;
private _left = [];
{
	_x params ["_projectile", "_from", "_firedAt", "_ammo", "_seen", "_last", "_key", "_weapon", ["_lookAt", 0]];
	if (isNull _projectile || {_now - _firedAt > 240}) then {
		// Landed (or burst, or lost): where it ended, for the tracks it made.
		if (_seen isNotEqualTo []) then {[_key, _last] remoteExecCall ["PTF_GATOR_fnc_cbImpact", 2]};
	} else {
		private _at = getPosASL _projectile;
		_x set [5, _at];
		if (_now >= _lookAt) then {
			private _looked = false;
			private _splash = [];
			{
				// [G/ATOR, where, reach (shorter while jammed), its sector [from, to] or [], staring at one track]
				_x params ["_radar", "_radarAt", ["_reach", CB_DETECT], ["_sector", []], ["_staring", false]];
				if (!(_radar in _seen) && {!_staring} && {_at distance _radarAt < _reach}
					&& {_sector isEqualTo [] || {(((_radarAt getDir _at) - (_sector select 0) + 360) % 360) <= (((_sector select 1) - (_sector select 0) + 360) % 360)}}) then {
					_looked = true;
					if !(terrainIntersectASL [_radarAt vectorAdd [0, 0, CB_EYE], _at]) then {
						// seen, in the air: traced now, with where it will come down and when
						if (_splash isEqualTo []) then {_splash = [_projectile, _at, _ammo] call _predict};
						_seen pushBack _radar;
						[_radar, _from, _ammo, _key, _weapon, _splash select 0, _splash select 1] remoteExecCall ["PTF_GATOR_fnc_cbReport", 2];
					};
				};
			} forEach _radars;
			if (_looked) then {_x set [8, _now + CB_LOOK]};
		};
		_left pushBack _x;
	};
} forEach (missionNamespace getVariable ["PTF_GATOR_cbFlights", []]);
missionNamespace setVariable ["PTF_GATOR_cbFlights", _left];
count _left
