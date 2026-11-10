/*
 * Server: play a 1MC announcement through the whole ship. Called from the panel's
 * ACE actions and the Zeus module.
 *
 * The sound plays from several ship parts at once (PTF_LHA_Announcements >>
 * speakers) on every machine, like a ship's PA heard from the nearest speaker.
 * One announcement at a time per ship: a request while one is playing is refused.
 *
 * Arguments:
 * 0: The ship <OBJECT>
 * 1: Announcement, a name from PTF_LHA_Announcements >> sounds <STRING>
 */
params [["_ship", objNull, [objNull]], ["_sound", "", [""]]];

if (!isServer || {isNull _ship}) exitWith {};
private _cfg = configFile >> "PTF_LHA_Announcements";
if !(_sound in getArray (_cfg >> "sounds")) exitWith {};

private _caller = remoteExecutedOwner;
if (serverTime < (_ship getVariable ["PTF_LHA_1mcUntil", -1])) exitWith {
	if (_caller > 0) then {["The 1MC is in use. Wait for the announcement to finish."] remoteExec ["systemChat", _caller]};
};

private _duration = getNumber (configFile >> "CfgVehicles" >> ("PTF_Sound_Module_" + _sound) >> "PTF_duration");
_ship setVariable ["PTF_LHA_1mcUntil", serverTime + (_duration max 3) + 1];

private _class = "PTF_Sound_" + _sound;
private _range = getNumber (_cfg >> "range");
private _speakers = getArray (_cfg >> "speakers");
{
	_x params ["_part"];
	if (typeOf _part in _speakers) then {
		// say3D is heard only on the machine that runs it, so every machine runs it.
		[_part, [_class, _range]] remoteExec ["say3D", 0];
	};
} forEach (_ship getVariable ["bis_carrierparts", []]);
