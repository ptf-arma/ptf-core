/*
 * Author: Paramarine Task Force
 * Whether a G/ATOR's array can start going up (or down) now: it is fully the other way, the
 * generator is running, the antenna isn't turning (and has come to rest facing aft), and to
 * go up, all four legs are down.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Raise (true) or lower (false) <BOOL>
 *
 * Return Value:
 * Can start <BOOL>
 *
 * Example:
 * [_radar, true] call PTF_GATOR_fnc_canSetDeployed
 */
params [["_radar", objNull, [objNull]], ["_deploy", true, [true]]];

if (!alive _radar || {abs speed _radar > 1} || {_radar getVariable ["PTF_GATOR_levelling", false]}) exitWith {false};
if ([_radar] call PTF_GATOR_fnc_powerState != "on") exitWith {false};
if (_radar getVariable ["PTF_GATOR_spinning", false]) exitWith {false};
private _spin = _radar animationSourcePhase "ptf_gator_spin";
if (abs (_spin - round _spin) > 0.001) exitWith {false};

private _phase = _radar animationSourcePhase "ptf_gator_deploy";
// From wherever it is: a crew can let go part way (PTF_GATOR_fnc_halt), and carry on or go back.
if (!_deploy) exitWith {_phase > 0.001};
// Up only on all four legs.
_phase < 0.999 && {[_radar] call PTF_GATOR_fnc_legsDown}
