/*
	GLT_fnc_keyName  (Turret Enhanced 2026 Version)
	Returns the name of the first key / button bound to a Controls action (config.cpp (CfgUserActions)),
	e.g. "Left Shift+1" or a joystick button, or "unbound".

	Params: _action <STRING> e.g. "GLT_measure"
	Returns: <STRING>
*/

params [["_action", "", [""]]];

private _names = actionKeysNamesArray [_action, 1];
if (_names isEqualTo []) exitWith {"unbound"};
_names select 0
