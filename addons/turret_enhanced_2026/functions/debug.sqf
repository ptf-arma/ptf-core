/*
	GLT_fnc_debug  (Turret Enhanced 2026 Version)
	Prints a diagnostic line to chat and the RPT when Addon Options > Turret Enhanced (2026 Version) > Debug is on.
	Used to find out how third-party airframes (custom cameras / lasers) behave.

	Params: _message <STRING>
*/

params [["_message", "", [""]]];

if (!(missionNamespace getVariable ["GLT_Debug", false])) exitWith {};

systemChat ("[TE debug] " + _message);
diag_log text ("[TE debug] " + _message);
