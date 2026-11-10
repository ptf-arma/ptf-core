/*
	Client: this player's row of PTF_Lives_table, [uid, name, lives, status,
	charges], or [] before the server has listed them.
*/
private _uid = getPlayerUID player;
private _table = missionNamespace getVariable ["PTF_Lives_table", []];
private _i = _table findIf {(_x select 0) isEqualTo _uid};
if (_i < 0) then {[]} else {_table select _i}
