/*
	Server: the book of lives and everything that changes it.

	PTF_Lives_book: SteamID -> [name, lives, charges]. "charges" counts the lives
	this player has used, so a client can tell when the server has seen a death.
	A player keeps their entry when they leave, so rejoining keeps their count;
	it starts at the starting value the first time they join.

	Published to everyone (fn_publish):
	  PTF_Lives_on      Lives switched on
	  PTF_Lives_start   lives a player gets the first time they join
	  PTF_Lives_table   [[uid, name, lives, status, charges], ...], by name
	  PTF_Lives_admins  SteamIDs of the players who may change them
*/
PTF_Lives_book = createHashMap;
PTF_Lives_billet = createHashMap; // SteamID -> [has "Manage lives" on Billet, when asked]
PTF_Lives_asked = createHashMap;  // SteamID -> when the player last asked for a Billet check
PTF_Lives_pools = createHashMap;  // vanilla respawn ticket pool variable -> its full value
PTF_Lives_sent = [];
PTF_Lives_on = false;
PTF_Lives_start = 3;

// Start from the server's settings once CBA has them.
["CBA_settingsInitialized", {
	PTF_Lives_on = missionNamespace getVariable ["PTF_Lives_onSetting", false];
	PTF_Lives_start = round (missionNamespace getVariable ["PTF_Lives_startSetting", 3]);
	// anyone listed before the settings arrived got the default: give them the real one
	{
		if ((_y select 2) isEqualTo 0) then {_y set [1, PTF_Lives_start]};
	} forEach PTF_Lives_book;
	// players already in the mission when it started (PlayerConnected only sees later ones)
	{
		_x params ["_uid", "", "", "_name"];
		if !(_uid in PTF_Lives_book) then {PTF_Lives_book set [_uid, [_name, PTF_Lives_start, 0]]};
	} forEach (call PTF_Lives_fnc_users);
	call PTF_Lives_fnc_publish;
	diag_log format ["[PTF_Lives] ready: %1, %2 lives each", ["off", "on"] select PTF_Lives_on, PTF_Lives_start];
}] call CBA_fnc_addEventHandler;

// New players get the starting value; returning ones keep what they had.
addMissionEventHandler ["PlayerConnected", {
	params ["", "_uid", "_name", "", "", "_idstr"];
	private _info = getUserInfo _idstr;
	if (_uid isEqualTo "" || {_name isEqualTo "__SERVER__"} || {_info param [7, false]}) exitWith {};
	private _entry = PTF_Lives_book getOrDefault [_uid, []];
	if (_entry isEqualTo []) then {
		PTF_Lives_book set [_uid, [_name, PTF_Lives_start, 0]];
	} else {
		_entry set [0, _name];
	};
	call PTF_Lives_fnc_publish;
}];

// Dying uses a life. That includes the pause menu's Respawn, which kills the unit.
// Whose body it was comes from the tag fn_publish and fn_hello put on each
// player's living body: on a dedicated server the engine can no longer name the
// player of a body that just died (tested 2026-11-10: deaths went uncounted).
// The player's own game also reports its death (fn_died); either way it is
// counted once (fn_charge).
addMissionEventHandler ["EntityKilled", {
	params ["_unit"];
	if !(_unit isKindOf "CAManBase") exitWith {};
	// not an AI a Zeus is remote-controlling
	if !(isNull (_unit getVariable ["bis_fnc_moduleRemoteControl_owner", objNull])) exitWith {};
	private _uid = _unit getVariable ["PTF_Lives_uid", ""];
	if (_uid isEqualTo "") then {_uid = getPlayerUID _unit};
	if (_uid isEqualTo "") exitWith {};
	[_unit, _uid, "died"] call PTF_Lives_fnc_charge;
}];

// Leaving while unconscious uses a life; leaving while conscious doesn't.
addMissionEventHandler ["HandleDisconnect", {
	params ["_unit", "", "_uid"];
	if (alive _unit && {(_unit getVariable ["ACE_isUnconscious", false]) || {lifeState _unit isEqualTo "INCAPACITATED"}}) then {
		[_unit, _uid, "left while unconscious"] call PTF_Lives_fnc_charge;
	};
	// the body is no longer theirs: if it stays on as AI, its death costs them nothing
	_unit setVariable ["PTF_Lives_uid", nil];
	call PTF_Lives_fnc_publish;
	// never true: that would keep the unit as AI, which is the mission's call
	nil
}];

// A body retired for having no lives (fn_retire) goes once the player respawns.
addMissionEventHandler ["EntityRespawned", {
	params ["", "_old"];
	if (_old getVariable ["PTF_Lives_ghost", false]) then {deleteVehicle _old};
}];

// Billet's answer to "may this player manage lives?" (blk_main's fn_role).
[missionNamespace, "blk_role", {
	params ["_uid", "_kind", "_allowed"];
	if (_kind isNotEqualTo "lives_role") exitWith {};
	PTF_Lives_billet set [_uid, [_allowed, diag_tickTime]];
	call PTF_Lives_fnc_publish;
}] call BIS_fnc_addScriptedEventHandler;

// Once a second: keep the vanilla side ticket pool from running out while Lives
// is on (Lives replaces it), and publish what changed (who is down, who is
// admin) every other second.
[] spawn {
	private _tick = 0;
	while {true} do {
		sleep 1;
		_tick = _tick + 1;
		if (PTF_Lives_on) then {
			// BIS_fnc_respawnTickets keeps each side's pool in a public variable;
			// -1 or nothing means the mission has none. Each pool is topped back
			// up to the most it has held.
			{
				_x params ["_space", "_suffix"];
				private _var = "BIS_fnc_respawnTickets_value" + _suffix;
				private _now = missionNamespace getVariable [_var, -1];
				if (_now isEqualType 0 && {_now >= 0}) then {
					private _full = (PTF_Lives_pools getOrDefault [_var, 0]) max _now;
					PTF_Lives_pools set [_var, _full];
					// through the function, so its running total stays right too
					if (_now < _full) then {[_space, _full - _now] call BIS_fnc_respawnTickets};
				};
			} forEach [[missionNamespace, ""], [west, "WEST"], [east, "EAST"], [resistance, "GUER"], [civilian, "CIV"]];
		};
		if (_tick % 2 == 0) then {call PTF_Lives_fnc_publish};
	};
};
