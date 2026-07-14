private "_droneItem";
private "_position";

_droneItem = _this select 0;

_position = getPosATL _droneItem;

deleteVehicle _droneItem;

[_position, "PTF_Buiding_RepairDepot", 1, [0,0,0], 0, {0}, true] call BIS_fnc_spawnObjects;
