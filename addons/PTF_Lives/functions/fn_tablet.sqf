/*
	Client: what the Billet tablet (and Rugged Phone) shows for Lives, through
	its add-on slot (class blk_tabletApps in config.cpp). Billet's tablet mod
	calls this about twice a second while the tablet is open and draws the
	answer in its own style; nothing here touches the page.

	Params: [what, action, key, value]
	  ["widget"]  the home screen panel: everyone's lives. Nothing while Lives
	              is off.
	  ["tab"]     the admin's Lives tab. Nothing for anyone else, so they have
	              no tab; it also asks the server to check Billet's "Manage
	              lives" permission for this player, at most once a minute.
	  ["action", action, key, value]  a click on the tab, sent to the server,
	              which checks again that this player is an admin (fn_admin).
*/
params [["_what", "", [""]], ["_action", "", [""]], ["_key", "", [""]], ["_value", "", [""]]];
private _on = missionNamespace getVariable ["PTF_Lives_on", false];
private _table = missionNamespace getVariable ["PTF_Lives_table", []];
private _me = getPlayerUID player;
private _status = {
	switch (_this) do {
		case "down": {"Down"};
		case "dead": {"Respawning"};
		case "out": {"Spectating"};
		case "away": {"Left the game"};
		default {""};
	}
};
private _tone = {
	if (!_on) exitWith {""};
	["ok", "acc", "bad"] select ([2, 1, 0] find (_this max 0 min 2))
};

if (_what isEqualTo "widget") exitWith {
	if (!_on) exitWith {nil};
	private _i = _table findIf {(_x select 0) isEqualTo _me};
	private _mine = if (_i < 0) then {-1} else {(_table select _i) select 2};
	createHashMapFromArray [
		["title", "Lives"],
		["value", [str _mine, "-"] select (_mine < 0)],
		["unit", "left"],
		["tone", [_mine call _tone, ""] select (_mine < 0)],
		["note", switch (true) do {
			case (_mine isEqualTo 0): {"Spectating until an admin gives you a life"};
			case (_mine isEqualTo 1): {"Last life"};
			default {""};
		}],
		["empty", "No players yet"],
		["rows", _table apply {
			_x params ["_uid", "_name", "_lives", "_st"];
			createHashMapFromArray [
				["label", _name],
				["value", str _lives],
				["tone", _lives call _tone],
				["note", _st call _status],
				["me", _uid isEqualTo _me]
			]
		}]
	]
};

if (_what isEqualTo "tab") exitWith {
	if !(_me in (missionNamespace getVariable ["PTF_Lives_admins", []])) exitWith {
		if (diag_tickTime - (missionNamespace getVariable ["PTF_Lives_askedAt", -1e6]) > 60) then {
			PTF_Lives_askedAt = diag_tickTime;
			[] remoteExecCall ["PTF_Lives_fnc_askAdmin", 2];
		};
		nil
	};
	createHashMapFromArray [
		["title", "Lives"],
		["blocks", [
			createHashMapFromArray [
				["type", "toggle"],
				["id", "on"],
				["label", "Use lives"],
				["note", ["Off: everyone respawns freely", "Players respawn until their lives run out"] select _on],
				["on", _on]
			],
			createHashMapFromArray [
				["type", "stepper"],
				["id", "start"],
				["label", "Starting lives"],
				["note", "For players joining for the first time"],
				["value", missionNamespace getVariable ["PTF_Lives_start", 3]],
				["min", 1],
				["max", 50]
			],
			createHashMapFromArray [
				["type", "list"],
				["title", "Players"],
				["search", true],
				["empty", "No players yet"],
				["rows", _table apply {
					_x params ["_uid", "_name", "_lives", "_st"];
					createHashMapFromArray [
						["key", _uid],
						["label", _name],
						["note", _st call _status],
						["value", str _lives],
						["tone", _lives call _tone],
						["actions", [
							createHashMapFromArray [["id", "sub"], ["label", "-"], ["title", "Take a life"]],
							createHashMapFromArray [["id", "add"], ["label", "+"], ["title", "Give a life"]]
						]]
					]
				}]
			]
		]]
	]
};

if (_what isEqualTo "action") exitWith {
	if !(_action in ["add", "sub", "start", "on"]) exitWith {};
	[_action, _key, _value] remoteExecCall ["PTF_Lives_fnc_admin", 2];
};
nil
