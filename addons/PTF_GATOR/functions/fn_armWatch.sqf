/*
 * Author: Paramarine Task Force
 * An anti-radiation missile: is it homing on a G/ATOR? Called the frame after any guided missile
 * is fired (PTF_GATOR_fnc_cbFired), or launched by Zeus (PTF_GATOR_fnc_armLaunch), on the machine
 * whose missile it is. If its target is a G/ATOR's radar (the hidden sensor, which only exists
 * while it transmits), it is watched twice a second until it is gone, and the G/ATOR's crew
 * hears of it (PTF_GATOR_fnc_armReport on the server): bearing and time to impact. If its
 * crew goes silent the sensor goes, and the missile has nothing to home on any more.
 *
 * Arguments:
 * 0: Missile <OBJECT>
 *
 * Return Value:
 * None
 */
params [["_missile", objNull, [objNull]]];
if (isNull _missile) exitWith {};
private _target = missileTarget _missile;
if (isNull _target) exitWith {};
private _radar = attachedTo _target;
if (!(_radar isKindOf "PTF_GATOR")) exitWith {};

private _n = (missionNamespace getVariable ["PTF_GATOR_armShot", 0]) + 1;
missionNamespace setVariable ["PTF_GATOR_armShot", _n];
private _key = format ["%1.%2", clientOwner, _n];
[{
	params ["_args", "_handle"];
	_args params ["_missile", "_radar", "_sensor", "_key", "_lost", ["_last", []]];
	if (isNull _missile || {!alive _radar}) exitWith {
		if (_last isNotEqualTo []) then {diag_log format ["[PTF_GATOR] anti-radiation missile ended %1 m from %2, lost lock %3", round (_last distance2D _radar), _radar, _lost]};
		[_radar, _key, "end", 0, 0, _lost] remoteExecCall ["PTF_GATOR_fnc_armReport", 2];
		[_handle] call CBA_fnc_removePerFrameHandler;
	};
	// Its sensor swapped for another while it still transmits (jamming changes its range): the
	// missile stays on the new one.
	private _now = _radar getVariable ["PTF_GATOR_sensor", objNull];
	if (!_lost && {!isNull _now} && {_now isNotEqualTo _sensor}) then {
		_sensor = _now;
		_args set [2, _now];
		_missile setMissileTarget _now;
	};
	// Silent: the sensor it homed on is gone, and it flies on blind.
	// (a deleted sensor is objNull, as is the missile's target then: check for it as such)
	if (!_lost && {isNull _sensor || {missileTarget _missile isNotEqualTo _sensor}}) then {
		_lost = true;
		_args set [4, true];
		// Left to itself it flies on to where it last had the G/ATOR. Without the emitter its
		// memory of it is off, 250 to 600 m. Silence well before it arrives saves the G/ATOR;
		// silence in its last second or two may not, when it can't turn that far.
		private _off = _radar getPos [250 + random 350, random 360];
		_missile setMissileTargetPos AGLToASL _off;
	};
	private _at = getPosASL _missile;
	_args set [5, _at];
	private _speed = (vectorMagnitude velocity _missile) max 50;
	[_radar, _key, "update", round ((_at distance getPosASL _radar) / _speed), round (_radar getDir _at), _lost] remoteExecCall ["PTF_GATOR_fnc_armReport", 2];
}, 0.5, [_missile, _radar, _target, _key, false]] call CBA_fnc_addPerFrameHandler;
