/*
 * Author: Paramarine Task Force
 * Where a G/ATOR's generator is: "off", "starting", "on" or "stopping". Worked out from when
 * it was last switched and the start and stop times in its config, so every machine agrees
 * without anything being sent when it finishes starting.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 *
 * Return Value:
 * State <STRING>
 *
 * Example:
 * [_radar] call PTF_GATOR_fnc_powerState
 */
params [["_radar", objNull, [objNull]]];

private _since = CBA_missionTime - (_radar getVariable ["PTF_GATOR_powerTime", -1e6]);
if (_radar getVariable ["PTF_GATOR_powerOn", false]) exitWith {
	["starting", "on"] select (_since >= getNumber (configOf _radar >> "ptf_gator_powerStartTime"))
};
["off", "stopping"] select (_since < getNumber (configOf _radar >> "ptf_gator_powerStopTime"))
