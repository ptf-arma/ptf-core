/*
 * Author: Paramarine Task Force
 * Clears a G/ATOR's counter-battery tracks, from its own readout and the network. Runs on the
 * server (called anywhere).
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_radar] call PTF_GATOR_fnc_cbClear
 */
params [["_radar", objNull, [objNull]]];

if (!isServer) exitWith {[_radar] remoteExecCall ["PTF_GATOR_fnc_cbClear", 2]};
if (isNull _radar) exitWith {};
_radar setVariable ["PTF_GATOR_cbTracks", []];
call PTF_GATOR_fnc_cbPublish;
