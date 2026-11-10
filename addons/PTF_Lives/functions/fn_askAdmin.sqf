/*
	Server, remote-executed when a player opens their tablet: ask Billet whether
	they hold "Manage lives", at most once a minute each. Nothing to do without
	blk_main's fn_role (billet-link not on the server, or too old for it): then
	only the server's logged-in admin manages lives.
*/
if (!isServer || {isNil "blk_fnc_role"}) exitWith {};
([] call PTF_Lives_fnc_callerUid) params ["", "_uid"];
if (_uid isEqualTo "") exitWith {};
if (diag_tickTime - (PTF_Lives_asked getOrDefault [_uid, -1e6]) < 60) exitWith {};
PTF_Lives_asked set [_uid, diag_tickTime];
[_uid, "lives_role"] call blk_fnc_role;
