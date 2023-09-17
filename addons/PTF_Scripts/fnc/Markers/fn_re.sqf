params ["_player"];
_markername = random 1000000;
_id = missionNamespace getVariable ["IDRE", 0];
_names = ["Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "X-ray", "Yankee", "Zulu"]; 
_str = format ["|_USER_DEFINED%1|%2|loc_rearm|ICON|[1.5,1.5]|0|Solid|ColorGreen|1|Resupply Point %3", _markername, position _player, _names select _id];
hint format ["Created resupply point %1 at %2", _names select _id, mapGridPosition _player];


_str call BIS_fnc_stringToMarker;

if (_id == count _names - 1 ) then {
	missionNamespace setVariable ["IDRE", 0 , true];
}
else{
	missionNamespace setVariable ["IDRE", _ID + 1, true];
};