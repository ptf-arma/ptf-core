/*
 * Author: Paramarine Task Force
 * Whether a G/ATOR's generator can be started (or stopped) now. It needs fuel and a working
 * generator (HitEngine) to start, and can't be stopped while the array moves or the antenna
 * turns.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Start (true) or stop (false) <BOOL>
 *
 * Return Value:
 * Can <BOOL>
 *
 * Example:
 * [_radar, true] call PTF_GATOR_fnc_canSetPower
 */
params [["_radar", objNull, [objNull]], ["_on", true, [true]]];

if (!alive _radar) exitWith {false};
private _state = [_radar] call PTF_GATOR_fnc_powerState;
if (_on) exitWith {_state == "off" && {fuel _radar > 0} && {_radar getHitPointDamage "HitEngine" < 0.9}};
if (_state != "on" || {_radar getVariable ["PTF_GATOR_spinning", false]}) exitWith {false};
private _array = _radar animationSourcePhase "ptf_gator_deploy";
private _spin = _radar animationSourcePhase "ptf_gator_spin";
(_array < 0.001 || {_array > 0.999}) && {abs (_spin - round _spin) < 0.001}
