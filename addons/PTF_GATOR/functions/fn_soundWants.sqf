/*
 * Author: Paramarine Task Force
 * Which of a G/ATOR's steady sound loops should be playing, from the state every machine
 * shares (variables the server or the operator set for everyone), so every player hears the
 * same. PTF_GATOR_fnc_soundLoop plays exactly these:
 *  "gen"           the generator, running (or past its start clip)
 *  "hum"           the radar hum, while it transmits
 *  "alarm", "arm"  the incoming alarm, and the missile warning
 * The array's and the legs' motors aren't here: they play while the part moves on the
 * listener's own machine (PTF_GATOR_fnc_soundLoop). Comparing a part with where another
 * machine sent it doesn't work: an animation can come to rest a hair off that on another
 * machine, and a motor heard "until it gets there" then never stopped for other players.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 *
 * Return Value:
 * Loop names <ARRAY>
 */
#define OVERLAP 0.5
params [["_radar", objNull, [objNull]]];

private _wants = [];
private _power = [_radar] call PTF_GATOR_fnc_powerState;
private _powerTime = _radar getVariable ["PTF_GATOR_powerTime", -1e6];
if (_power == "on" || {_power == "starting" && {CBA_missionTime - _powerTime > getNumber (configOf _radar >> "ptf_gator_powerStartTime") - OVERLAP}}) then {
	_wants pushBack "gen";
};
if (!isNull (_radar getVariable ["PTF_GATOR_sensor", objNull])) then {_wants pushBack "hum"};
if (CBA_missionTime < _radar getVariable ["PTF_GATOR_alarmUntil", -1]) then {_wants pushBack "alarm"};
if ((_radar getVariable ["PTF_GATOR_arm", []]) isNotEqualTo []) then {_wants pushBack "arm"};
_wants
