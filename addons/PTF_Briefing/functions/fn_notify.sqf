/*
	Client: a short message about the briefing screens for the player who used
	the laptop.
*/
params [["_message", "", [""]]];
if (!hasInterface || {_message == ""}) exitWith {};
[_message] call CBA_fnc_notify;
