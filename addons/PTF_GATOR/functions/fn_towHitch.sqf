/*
 * Author: Paramarine Task Force
 * Hitches a G/ATOR to a vehicle, or unhitches it. While hitched, PTF_GATOR_fnc_towLoop moves
 * the trailer behind the vehicle on whichever machine owns them both; the server keeps the
 * trailer owned by whoever owns the vehicle. The tongue stand winds up while hitched.
 * Runs on the server: call it from anywhere, it forwards itself.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Towing vehicle, or objNull to unhitch <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_radar, _truck] call PTF_GATOR_fnc_towHitch
 * [_radar, objNull] call PTF_GATOR_fnc_towHitch
 */
params [["_radar", objNull, [objNull]], ["_tower", objNull, [objNull]]];

if (!isServer) exitWith {[_radar, _tower] remoteExecCall ["PTF_GATOR_fnc_towHitch", 2]};
if (isNull _radar) exitWith {};

if (isNull _tower) then {
	_radar setVariable ["PTF_GATOR_tower", objNull, true];
	_radar animateSource ["ptf_gator_stand", 0];
} else {
	_radar setVariable ["PTF_GATOR_towHitch", [_tower] call PTF_GATOR_fnc_towHitchPoint, true];
	_radar setVariable ["PTF_GATOR_tower", _tower, true];
	_radar animateSource ["ptf_gator_stand", 1];
	if (owner _radar != owner _tower) then {_radar setOwner owner _tower};
};
