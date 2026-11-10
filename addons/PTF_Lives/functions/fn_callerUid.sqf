/*
	Server: who sent this remote-executed call, as [network owner, SteamID, unit].

	Always from the engine's remoteExecutedOwner, never from the arguments, so
	no one can act as someone else. A local call (single player, or the host of
	a player-hosted game) is this machine's own player. Empty SteamID: unknown.
*/
private _owner = remoteExecutedOwner;
// (on a dedicated server, 0 stays 0, which matches no one)
if (_owner isEqualTo 0 && {!isDedicated}) then {_owner = clientOwner};
private _found = ["", objNull];
{
	_x params ["_uid", "_o", "_unit"];
	if (_o isEqualTo _owner) exitWith {_found = [_uid, _unit]};
} forEach (call PTF_Lives_fnc_users);
[_owner, _found select 0, _found select 1]
