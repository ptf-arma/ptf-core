params ["_player"];
_markername = random 1000000;
_str = format ["|_USER_DEFINED%1|%2|RedCrystal|ICON|[1,1]|0|Solid|Default|1|CCP", _markername, position _player];
hint format ["Created CCP %1", mapGridPosition _player ];


_str call BIS_fnc_stringToMarker; 
