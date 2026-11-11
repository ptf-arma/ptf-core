/*
	Server, remote-executed by a player in a fresh body: they just joined, or
	just respawned. Puts them in the book, and if Lives is on and they have no
	lives left (they rejoined after running out, or a respawn slipped past the
	block in fn_clientInit), retires the body so they go back to spectating.
*/
if (!isServer) exitWith {};
([] call PTF_Lives_fnc_callerUid) params ["", "_uid", "_unit"];
if (_uid isEqualTo "" || {isNull _unit}) exitWith {};
if (alive _unit) then {_unit setVariable ["PTF_Lives_uid", _uid]};

private _entry = PTF_Lives_book getOrDefault [_uid, []];
if (_entry isEqualTo []) then {
	_entry = [name _unit, PTF_Lives_start, 0];
	PTF_Lives_book set [_uid, _entry];
} else {
	_entry set [0, name _unit];
};
if (PTF_Lives_on && {(_entry select 1) <= 0} && {alive _unit}) then {
	diag_log format ["[PTF_Lives] %1 has no lives left: back to spectating", _entry select 0];
	[_unit, _uid] call PTF_Lives_fnc_retire;
};
call PTF_Lives_fnc_publish;
