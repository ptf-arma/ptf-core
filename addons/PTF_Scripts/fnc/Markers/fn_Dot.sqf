// AceActions.hpp calls this with no arguments, unlike its siblings, so default
// to the local player rather than changing the call signature.
params [["_player", player]];

// Marker names must be unique -- createMarker silently returns "" for a
// duplicate and the marker is never placed. `random 1000000` is a float and
// two clients can roll the same value, so scope the name to the machine that
// made it and a counter, matching fn_lz.sqf and fn_re.sqf.
private _seq = (missionNamespace getVariable ["PTF_dotMarkerSeq", 0]) + 1;
missionNamespace setVariable ["PTF_dotMarkerSeq", _seq];
private _markername = format ["PTF_dot_%1_%2", clientOwner, _seq];

private _str = format ["|_USER_DEFINED%1|%2|hd_dot|ICON|[1,1]|0|Solid|Default|1|", _markername, position _player];

_str call BIS_fnc_stringToMarker;

