/*
 * Author: Paramarine Task Force
 * An anti-radiation missile homing on a G/ATOR, as its crew knows it (PTF_GATOR_fnc_armWatch,
 * from the missile's machine). Server only. Missiles inbound are PTF_GATOR_arm on the G/ATOR
 * (public): the missile warning sounds at the trailer (PTF_GATOR_fnc_soundLoop) and the tablet
 * shows them (PTF_GATOR_fnc_gatorLayer). Its crew's choice: go silent, and the missile loses
 * it (and the radar is blind meanwhile), or keep transmitting and take the hit.
 * When the missile is gone, the log says whether it was defeated or hit, by whether the G/ATOR
 * was knocked out or badly damaged (PTF_GATOR_armLast: "defeated" or "hit").
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: The missile's key <STRING>
 * 2: "update" or "end" <STRING>
 * 3: Seconds to impact <NUMBER>
 * 4: Bearing from the G/ATOR <NUMBER>
 * 5: Lost its target <BOOL>
 *
 * Return Value:
 * None
 */
params [["_radar", objNull, [objNull]], ["_key", "", [""]], ["_what", "", [""]], ["_eta", 0, [0]], ["_bearing", 0, [0]], ["_lost", false, [false]]];
if (!isServer || {isNull _radar}) exitWith {};

private _arms = +(_radar getVariable ["PTF_GATOR_arm", []]);
private _i = _arms findIf {(_x select 0) == _key};
if (_what == "update") exitWith {
	if (_i < 0) then {
		// a new one: what the G/ATOR's damage was, for the outcome
		_radar setVariable ["PTF_GATOR_armDamage_" + _key, damage _radar max (_radar getHitPointDamage "HitRadar")];
		diag_log format ["[PTF_GATOR] anti-radiation missile inbound on %1, bearing %2, %3 s", _radar, _bearing, _eta];
		_arms pushBack [_key, _eta, _bearing, _lost];
	} else {
		_arms set [_i, [_key, _eta, _bearing, _lost]];
	};
	_radar setVariable ["PTF_GATOR_arm", _arms, true];
};

if (_i >= 0) then {
	_arms deleteAt _i;
	_radar setVariable ["PTF_GATOR_arm", _arms, true];
};
// Give its blast a moment to land before judging it.
[{
	params ["_radar", "_key"];
	if (isNull _radar) exitWith {};
	private _before = _radar getVariable ["PTF_GATOR_armDamage_" + _key, 0];
	_radar setVariable ["PTF_GATOR_armDamage_" + _key, nil];
	// a hit: knocked out (its antenna wrecked) or badly hurt, not a near miss's scratch
	private _hit = !alive _radar || {(_radar getHitPointDamage "HitRadar") >= 0.9} || {(damage _radar max (_radar getHitPointDamage "HitRadar")) > _before + 0.25};
	// the last outcome, for tests (tools/gator/test/operator.Stratis)
	_radar setVariable ["PTF_GATOR_armLast", ["defeated", "hit"] select _hit];
	diag_log format ["[PTF_GATOR] anti-radiation missile on %1: %2", _radar, ["defeated", "hit"] select _hit];
}, [_radar, _key], 1] call CBA_fnc_waitAndExecute;
