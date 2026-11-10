/*
 * Author: Paramarine Task Force
 * Starts or stops a G/ATOR's generator. It powers the radar once started
 * (ptf_gator_powerStartTime seconds); every client plays the start, running and stop sounds
 * from this state. Global effect.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Start (true) or stop (false) <BOOL> (default: true)
 * 2: Instantly, skipping the checks and the start-up (for missions and Zeus) <BOOL> (default: false)
 *
 * Return Value:
 * Changed <BOOL>
 *
 * Example:
 * [_radar, true] call PTF_GATOR_fnc_setPower
 */
params [["_radar", objNull, [objNull]], ["_on", true, [true]], ["_instant", false, [false]]];

if (isNull _radar) exitWith {false};
if (!_instant && {!([_radar, _on] call PTF_GATOR_fnc_canSetPower)}) exitWith {false};

_radar setVariable ["PTF_GATOR_powerOn", _on, true];
_radar setVariable ["PTF_GATOR_powerTime", [CBA_missionTime, -1e6] select _instant, true];
true
