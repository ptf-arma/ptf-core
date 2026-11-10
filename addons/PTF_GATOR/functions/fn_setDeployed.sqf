/*
 * Author: Paramarine Task Force
 * Raises or lowers a G/ATOR's array. The struts follow it; it takes 32 seconds.
 * animateSource has global effect, so call this on one machine only.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Raise (true) or lower (false) <BOOL> (default: true)
 * 2: Instantly, skipping the checks (for missions and Zeus). Also puts the legs down
 *    (raising) or up (lowering), but leaves the generator alone. <BOOL> (default: false)
 *
 * Return Value:
 * Started <BOOL>
 *
 * Example:
 * [_radar, true] call PTF_GATOR_fnc_setDeployed
 * [this, true, true] call PTF_GATOR_fnc_setDeployed   // in an editor init field
 */
params [["_radar", objNull, [objNull]], ["_deploy", true, [true]], ["_instant", false, [false]]];

if (isNull _radar) exitWith {false};
if (!_instant && {!([_radar, _deploy] call PTF_GATOR_fnc_canSetDeployed)}) exitWith {false};

if (_instant) then {
	{[_radar, _x, _deploy, true] call PTF_GATOR_fnc_setLeg} forEach ["fl", "fr", "rl", "rr"];
};
_radar animateSource ["ptf_gator_deploy", [0, 1] select _deploy, _instant];
true
