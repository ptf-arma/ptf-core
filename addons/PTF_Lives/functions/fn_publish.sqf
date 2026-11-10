/*
	Server: send everyone the current state, only the parts that changed.

	Status per player: "alive", "down" (unconscious), "dead" (waiting to
	respawn), "out" (no lives left, spectating) or "away" (not connected).
*/
private _users = createHashMap; // SteamID -> [owner, unit]
{
	_x params ["_uid", "_owner", "_unit"];
	_users set [_uid, [_owner, _unit]];
} forEach (call PTF_Lives_fnc_users);

private _table = [];
{
	_y params ["_name", "_lives", "_charges"];
	private _status = "away";
	if (_x in _users) then {
		private _unit = (_users get _x) select 1;
		_status = switch (true) do {
			case (isNull _unit || {!alive _unit}): {["dead", "out"] select (PTF_Lives_on && {_lives <= 0})};
			case ((_unit getVariable ["ACE_isUnconscious", false]) || {lifeState _unit isEqualTo "INCAPACITATED"}): {"down"};
			default {"alive"};
		};
	};
	_table pushBack [toLower _name, _x, _name, _lives, _status, _charges];
} forEach PTF_Lives_book;
_table sort true;
_table = _table apply {_x select [1]};

private _admins = [];
{
	if ([_y select 0, _x] call PTF_Lives_fnc_isAdmin) then {_admins pushBack _x};
} forEach _users;
_admins sort true;

PTF_Lives_sent params [["_on", -1], ["_start", -1], ["_oldTable", -1], ["_oldAdmins", -1]];
if (_on isNotEqualTo PTF_Lives_on) then {publicVariable "PTF_Lives_on"};
if (_start isNotEqualTo PTF_Lives_start) then {publicVariable "PTF_Lives_start"};
if (_oldTable isNotEqualTo _table) then {
	PTF_Lives_table = _table;
	publicVariable "PTF_Lives_table";
};
if (_oldAdmins isNotEqualTo _admins) then {
	PTF_Lives_admins = _admins;
	publicVariable "PTF_Lives_admins";
};
PTF_Lives_sent = [PTF_Lives_on, PTF_Lives_start, _table, _admins];
