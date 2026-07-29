params ["_player"];

// PTF_LzNames is a CBA setting; it can be nil before CBA has applied settings
if (isNil "PTF_LzNames") exitWith {
hint "You addon settings are not set up correctly" };

private _names = call compile PTF_LzNames;

if (!(_names isEqualType [])) exitwith {
hint "You addon settings are not set up correctly" };

if (_names isEqualTo [])
exitwith {
hint "You addon settings are not set up correctly" };
_names = _names select {_x isEqualType ""};
if (_names isEqualTo []) exitwith {
hint "You addon settings are not set up correctly"
};

// IDLZ is shared across clients but the filter above can shrink the list, so
// keep the index in range instead of running off the end of _names
private _id = (missionNamespace getVariable ["IDLZ", 0]) mod (count _names);

// Marker names have to be unique - createMarker silently returns "" for a
// duplicate. random 1000000 is a float and two clients can roll the same value,
// so build the name from the owner id plus a counter local to this machine.
private _seq = (missionNamespace getVariable ["PTF_lzMarkerSeq", 0]) + 1;
missionNamespace setVariable ["PTF_lzMarkerSeq", _seq];
private _markername = format ["PTF_lz_%1_%2", clientOwner, _seq];

private _str = format ["|_USER_DEFINED%1|%2|hd_pickup|ICON|[1,1]|0|Solid|ColorGreen|1|LZ %3", _markername, position _player, _names select _id];
hint format ["Created lz %1 at %2", _names select _id, mapGridPosition _player];


_str call BIS_fnc_stringToMarker;

if (_id == count _names - 1 ) then {
	missionNamespace setVariable ["IDLZ", 0 , true];
}
else{
	missionNamespace setVariable ["IDLZ", _ID + 1, true];
};
