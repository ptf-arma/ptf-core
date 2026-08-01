params ["_player", ["_caller", clientOwner]];
//_player = the unit placing the marker
//_caller = owner id to send feedback hints to (set automatically)

// See fn_lz.sqf - same server-authoritative allocation, different pool.
if (!isServer) exitWith {
   [_player, clientOwner] remoteExec ["PTF_fnc_re", 2];
};

private _alloc = ["PTF_re", "PTF_ReNames"] call PTF_fnc_allocMarkerName;
if (_alloc isEqualTo []) exitWith {
   ["Your addon settings are not set up correctly"] remoteExec ["hint", _caller];
};
_alloc params ["_markername", "_callsign"];

private _str = format ["|_USER_DEFINED%1|%2|loc_rearm|ICON|[1.5,1.5]|0|Solid|ColorGreen|1|Resupply Point %3", _markername, position _player, _callsign];
_str call BIS_fnc_stringToMarker;

[format ["Created resupply point %1 at %2", _callsign, mapGridPosition _player]] remoteExec ["hint", _caller];
