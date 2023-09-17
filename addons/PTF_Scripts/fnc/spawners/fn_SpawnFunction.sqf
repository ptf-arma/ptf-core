param ["_player", "_vehicle", "_markers"]
_Target = "Land_helipadEmpty_F",
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
	getPosATL (nearestObject [_player, _target]),
	];
_vh setDir (getDir nearestObject [_vh, _target]);
 
if (_id == count _names - 1 ) then 
{ missionNamespace setVariable ["IDLZ", 0 , true]; } 
else{ missionNamespace setVariable ["IDLZ", _ID + 1, true]; 
}; 


