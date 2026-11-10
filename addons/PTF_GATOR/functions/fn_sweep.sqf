/*
 * Author: Paramarine Task Force
 * A sector scan: the array sweeps back and forth between the sector's two edges
 * (PTF_GATOR_sector, [from, to], clockwise from one to the other), at the antenna's own
 * turning speed. Server only; started by PTF_GATOR_fnc_operator "sector". It watches the
 * array ten times a second: once it stops at an edge it turns it to the other. It pauses
 * while the array stares at one track (a dwell), and ends when the G/ATOR leaves sector mode,
 * powers down or lowers its array. Which way it is going now is PTF_GATOR_sweepDir (public:
 * 1 clockwise, -1 back), for the map's sweep (PTF_GATOR_fnc_gatorLayer).
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 *
 * Return Value:
 * None
 */
params [["_radar", objNull, [objNull]]];
if (!isServer || {isNull _radar} || {_radar getVariable ["PTF_GATOR_sweeping", false]}) exitWith {};
_radar setVariable ["PTF_GATOR_sweeping", true];
_radar setVariable ["PTF_GATOR_sweepLast", -1e9];

[{
	params ["_radar", "_handle"];
	if (isNull _radar || {!alive _radar} || {_radar getVariable ["PTF_GATOR_mode", "full"] != "sector"}
		|| {_radar animationSourcePhase "ptf_gator_deploy" < 0.999} || {[_radar] call PTF_GATOR_fnc_powerState != "on"}
		|| {_radar getHitPointDamage "HitRadar" >= 0.9}) exitWith {
		if (!isNull _radar) then {_radar setVariable ["PTF_GATOR_sweeping", false]};
		[_handle] call CBA_fnc_removePerFrameHandler;
	};
	// staring at one track: wait
	if (!isNil {_radar getVariable "PTF_GATOR_dwell"}) exitWith {_radar setVariable ["PTF_GATOR_sweepLast", -1e9]};
	// still turning: wait
	private _phase = _radar animationSourcePhase "ptf_gator_spin";
	if (_phase != (_radar getVariable ["PTF_GATOR_sweepLast", -1e9])) exitWith {_radar setVariable ["PTF_GATOR_sweepLast", _phase]};

	// Stopped: on to the other edge. One turn per unit of phase, anticlockwise from above, so
	// turning clockwise by d degrees takes the phase down by d / 360.
	(_radar getVariable ["PTF_GATOR_sector", [0, 90]]) params ["_from", "_to"];
	private _span = ((_to - _from) + 360) % 360;
	private _facing = [_radar] call PTF_GATOR_fnc_facing;
	private _off = ((_facing - _from) + 360) % 360;
	// a hair short of "from" counts as at it
	if (_off >= 358) then {_off = 0};
	private _dir = _radar getVariable ["PTF_GATOR_sweepDir", 1];
	private _target = _phase;
	if (_off > _span + 2) then {
		// outside the sector (just set, or after a dwell outside it): to the nearer edge, the short way
		private _toFrom = ((_from - _facing) + 540) % 360 - 180;
		private _toTo = ((_to - _facing) + 540) % 360 - 180;
		private _turn = [_toTo, _toFrom] select (abs _toFrom <= abs _toTo);
		_dir = [-1, 1] select (abs _toFrom <= abs _toTo);
		_target = _phase - _turn / 360;
	} else {
		if (_dir > 0 && {_span - _off < 1}) then {_dir = -1};
		if (_dir < 0 && {_off < 1}) then {_dir = 1};
		_target = [_phase + _off / 360, _phase - (_span - _off) / 360] select (_dir > 0);
	};
	if (_dir != (_radar getVariable ["PTF_GATOR_sweepDir", 0])) then {_radar setVariable ["PTF_GATOR_sweepDir", _dir, true]};
	_radar animateSource ["ptf_gator_spin", _target];
}, 0.1, _radar] call CBA_fnc_addPerFrameHandler;
