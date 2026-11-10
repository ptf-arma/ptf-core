/*
	Server: take a body with no lives behind it out of play. It is hidden and
	killed, which costs nothing (it is marked as already charged), and the
	player's own client then holds them dead as a spectator. The body is deleted
	when they next respawn (fn_serverInit's EntityRespawned).

	Params: [unit, SteamID]
*/
params ["_unit", "_uid"];
_unit setVariable ["PTF_Lives_charged", _uid];
_unit setVariable ["PTF_Lives_ghost", true];
hideObjectGlobal _unit;
_unit setDamage 1;
