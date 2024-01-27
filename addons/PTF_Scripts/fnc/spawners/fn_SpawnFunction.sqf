params ["_vehicle", "_markers", ["_ticket", ""]];
//_vehicle = class name
//_Markers = the name of the marker for the spawn location
//ticket = the name of the addon variable that you want to - by 1


_id = missionNamespace getVariable [_markers, 0]; 
_name = _markers; 
_cnt = { _markers in _x } count allMapMarkers inArea;

if (_ticket != "" && {missionNamespace getVariable _tickets <= 0}) exitwith {
hint "there are no more tickets"
};

_markersA = [_name]; 
for "_i" from 1 to _cnt - 1 do { 
  _markersA pushBack format ["%1_%2", _name, _i]; 
}; 

_check = nearestObjects [getMarkerPos [_markersA select _id] , ["LandVehicle", "Air", "Ship"], 5];  //find if an object is blocking the pad

if (
  count _check != 0
) exitwith {
  hint "Spawning loacation is blocked";
}; // if there is an object in array _check then somthing is blocking the pad

 _vH = createVehicle [ 
 _vehicle,  
 getMarkerPos [_markersA select _id] 
]; //make the vic

_vh setDir (markerDir (_markersA select _id));
//set vics rotation to rotaiton of marker
if (_ticket != "") then {
_t = missionNamespace getVariable _ticket;
_t = _t - 1;
missionNamespace setVariable [_ticket, _t];
publicVariable _ticket;
hint format ["you have %1 tickets remaining", _t];
}; // check if the tickets peram is empty if not set - 1 of thoses tickets

if (_id == count _markersA - 1 ) then {  
 missionNamespace setVariable [_markers, 0 , true];  
 }  
 
else {  
 missionNamespace setVariable [_markers, _id + 1, true];  
};  //move the spawn location onto the next one in BIS_fnc_showMarkers

if (_vehicle = "PTF_MV22_Cargo") then {
 ["_vehicle"] call PTF_Fnc_slingloading;
};
 
 
