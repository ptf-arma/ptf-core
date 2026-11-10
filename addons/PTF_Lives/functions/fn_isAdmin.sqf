/*
	Server: may this player change lives?

	The server's logged-in admin (#login), the host of a player-hosted game or
	single player (the server's own machine), or anyone Billet says holds "Manage lives" (asked by
	fn_askAdmin when they open their tablet, answered through blk_main).

	Params: [network owner, SteamID]
*/
params ["_owner", "_uid"];
(_owner isEqualTo clientOwner && {hasInterface})
	|| {(admin _owner) isEqualTo 2}
	|| {(PTF_Lives_billet getOrDefault [_uid, [false]]) select 0}
