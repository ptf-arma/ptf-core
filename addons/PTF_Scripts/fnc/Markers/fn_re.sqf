params ["_player"];

// PTF_ReNames is a CBA setting; it can be nil before CBA has applied settings
if (isNil "PTF_ReNames") exitWith {
hint "You addon settings are not set up correctly" };

private _names = call compile PTF_ReNames;

if (!(_names isEqualType [])) exitwith {
hint "You addon settings are not set up correctly" };

if (_names isEqualTo [])
exitwith {
hint "You addon settings are not set up correctly" };
_names = _names select {_x isEqualType ""};
if (_names isEqualTo []) exitwith {
hint "You addon settings are not set up correctly"
};

// IDRE is shared across clients but the filter above can shrink the list, so
// keep the index in range instead of running off the end of _names
private _id = (missionNamespace getVariable ["IDRE", 0]) mod (count _names);

// Marker names have to be unique - createMarker silently returns "" for a
// duplicate. random 1000000 is a float and two clients can roll the same value,
// so build the name from the owner id plus a counter local to this machine.
private _seq = (missionNamespace getVariable ["PTF_reMarkerSeq", 0]) + 1;
missionNamespace setVariable ["PTF_reMarkerSeq", _seq];
private _markername = format ["PTF_re_%1_%2", clientOwner, _seq];

private _str = format ["|_USER_DEFINED%1|%2|loc_rearm|ICON|[1.5,1.5]|0|Solid|ColorGreen|1|Resupply Point %3", _markername, position _player, _names select _id];
hint format ["Created resupply point %1 at %2", _names select _id, mapGridPosition _player];


_str call BIS_fnc_stringToMarker;

if (_id == count _names - 1 ) then {
	missionNamespace setVariable ["IDRE", 0 , true];
}
else{
	missionNamespace setVariable ["IDRE", _ID + 1, true];
};
