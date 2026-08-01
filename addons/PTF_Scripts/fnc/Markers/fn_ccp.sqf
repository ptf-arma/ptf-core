params ["_player"];

// See fn_Dot.sqf -- a float marker name can collide between clients and the
// marker then silently fails to place.
private _seq = (missionNamespace getVariable ["PTF_ccpMarkerSeq", 0]) + 1;
missionNamespace setVariable ["PTF_ccpMarkerSeq", _seq];
private _markername = format ["PTF_ccp_%1_%2", clientOwner, _seq];

private _str = format ["|_USER_DEFINED%1|%2|RedCrystal|ICON|[1,1]|0|Solid|Default|1|CCP", _markername, position _player];
hint format ["Created CCP %1", mapGridPosition _player ];


_str call BIS_fnc_stringToMarker;
