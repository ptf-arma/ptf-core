params ["_player", ["_caller", clientOwner]];
//_player = the unit placing the marker
//_caller = owner id to send feedback hints to (set automatically)

// Server-authoritative, mirroring fn_SpawnFunction and fn_Salvage. Callsigns
// come from one canonical pool, so two players marking in the same tick cannot
// be handed the same one, and the marker is created server-side and is
// therefore global and JIP-safe.
if (!isServer) exitWith {
   [_player, clientOwner] remoteExec ["PTF_fnc_lz", 2];
};

private _alloc = ["PTF_lz", "PTF_LzNames"] call PTF_fnc_allocMarkerName;
if (_alloc isEqualTo []) exitWith {
   ["Your addon settings are not set up correctly"] remoteExec ["hint", _caller];
};
_alloc params ["_markername", "_callsign"];

private _str = format ["|_USER_DEFINED%1|%2|hd_pickup|ICON|[1,1]|0|Solid|ColorGreen|1|LZ %3", _markername, position _player, _callsign];
_str call BIS_fnc_stringToMarker;

[format ["Created LZ %1 at %2", _callsign, mapGridPosition _player]] remoteExec ["hint", _caller];
