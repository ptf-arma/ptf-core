/*
 * Author: Paramarine Task Force
 * Whether a G/ATOR's antenna can start (or stop) turning now. It only starts with the array
 * fully raised and the generator running.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Start (true) or stop (false) <BOOL>
 *
 * Return Value:
 * Can <BOOL>
 *
 * Example:
 * [_radar, true] call PTF_GATOR_fnc_canSetSpinning
 */
params [["_radar", objNull, [objNull]], ["_spin", true, [true]]];

if (!alive _radar) exitWith {false};
private _spinning = _radar getVariable ["PTF_GATOR_spinning", false];
// staring at a sector (PTF_GATOR_fnc_operator) counts as on: stopping brings the array back to rest
if (!_spin) exitWith {_spinning || {_radar getVariable ["PTF_GATOR_mode", "full"] == "sector"}};
!_spinning && {_radar animationSourcePhase "ptf_gator_deploy" > 0.999}
	&& {[_radar] call PTF_GATOR_fnc_powerState == "on"} && {_radar getHitPointDamage "HitRadar" < 0.9}
