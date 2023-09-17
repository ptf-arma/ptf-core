///param ["_player", "_vehicle", "_markers"] 
 
_player = player; 
_vehicle = "PTF_AH1Z_GUNFIGHTERS"; 
_markers = "attack"; 
 
_id = missionNamespace getVariable [_markers, 0]; 
 
_name = _markers; 
_markersA = [_name]; 
for "_i" from 1 to 10 do { 
  _markersA pushBack format ["%1_%2", _name, _i]; 
}; 
 
_vH = createVehicle [ 
 _vehicle,  
 getMarkerPos [_markersA select _id] 
]; 
 
_vh setDir [getmarkerDir [_markersA select _id]]; 
  
if (_id == count _markersA - 1 ) then {  
 missionNamespace setVariable [_markers, 0 , true];  
 }  
 
else {  
 missionNamespace setVariable [_markers, _id + 1, true];  
};  
 
 
