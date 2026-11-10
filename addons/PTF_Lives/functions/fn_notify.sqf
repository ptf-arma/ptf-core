/*
	Client: a short notice about this player's lives (CBA's notification, top
	right). Remote-executed by the server for admin changes.

	Params: [kind, number, admin's name]
	  "left"     lives left after using one
	  "out"      none left: spectating
	  "add"      an admin gave one ("sub": took one)
	  "switched" Lives switched on (1) or off (0)
	  "refused"  not an admin
*/
if (!hasInterface) exitWith {};
if (isRemoteExecuted && {remoteExecutedOwner != 2}) exitWith {};
params [["_kind", "", [""]], ["_n", 0, [0]], ["_by", "", [""]]];
private _lives = [format ["%1 lives", _n], "1 life"] select (_n isEqualTo 1);
private _text = switch (_kind) do {
	case "left": {[format ["%1 left", _lives], "No lives left"] select (_n <= 0)};
	case "out": {"No lives left. You're spectating until an admin gives you one."};
	case "add": {format ["%1 gave you a life. %2 left.", _by, _lives]};
	case "sub": {format ["%1 took a life. %2 left.", _by, _lives]};
	case "switched": {["Lives are off: respawn is free.", "Lives are on."] select (_n isEqualTo 1)};
	case "refused": {"Only admins can change lives."};
	default {""};
};
if (_text isEqualTo "") exitWith {};
systemChat format ["Lives: %1", _text];
if (!isNil "CBA_fnc_notify") then {[["Lives", 1.2], [_text]] call CBA_fnc_notify};
