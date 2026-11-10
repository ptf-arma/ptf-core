/*
	Server, remote-executed from an admin's Lives tab (fn_tablet).

	Params: [action, key, value], all strings:
	  ["add", <SteamID>, ""]   one more life for that player (a player out of
	                           lives then respawns on their own)
	  ["sub", <SteamID>, ""]   one less
	  ["start", "", <n>]       lives for players joining from now on (1-50)
	  ["on", "", "1" or "0"]   switch Lives on or off. Off, dying is free and
	                           anyone spectating for lack of lives respawns.
	Who is asking comes from the network connection; anyone not an admin
	(fn_isAdmin) is refused.
*/
if (!isServer) exitWith {};
params [["_action", "", [""]], ["_key", "", [""]], ["_value", "", [""]]];
([] call PTF_Lives_fnc_callerUid) params ["_owner", "_uid", "_unit"];
if (_uid isEqualTo "") exitWith {};
if !([_owner, _uid] call PTF_Lives_fnc_isAdmin) exitWith {
	diag_log format ["[PTF_Lives] refused %1 from %2 (%3): not an admin", _action, name _unit, _uid];
	["refused"] remoteExecCall ["PTF_Lives_fnc_notify", _owner];
};
private _admin = name _unit;

switch (_action) do {
	case "add";
	case "sub": {
		private _entry = PTF_Lives_book getOrDefault [_key, []];
		if (_entry isEqualTo []) exitWith {};
		private _was = _entry select 1;
		private _now = (_was + ([-1, 1] select (_action isEqualTo "add"))) max 0 min 99;
		if (_now isEqualTo _was) exitWith {};
		_entry set [1, _now];
		diag_log format ["[PTF_Lives] %1 set %2 to %3 lives", _admin, _entry select 0, _now];
		// tell that player, if they're here
		{
			_x params ["_u", "_o"];
			if (_u isEqualTo _key) exitWith {[_action, _now, _admin] remoteExecCall ["PTF_Lives_fnc_notify", _o]};
		} forEach (call PTF_Lives_fnc_users);
	};
	case "start": {
		private _n = round parseNumber _value;
		if (_n < 1 || {_n > 50}) exitWith {};
		PTF_Lives_start = _n;
		diag_log format ["[PTF_Lives] %1 set starting lives to %2", _admin, _n];
	};
	case "on": {
		private _on = _value isEqualTo "1";
		if (_on isEqualTo PTF_Lives_on) exitWith {};
		PTF_Lives_on = _on;
		diag_log format ["[PTF_Lives] %1 switched Lives %2", _admin, ["off", "on"] select _on];
		["switched", [0, 1] select _on, _admin] remoteExecCall ["PTF_Lives_fnc_notify", 0];
	};
};
call PTF_Lives_fnc_publish;
