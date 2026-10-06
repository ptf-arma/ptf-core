params["_veh"];

_operator = UAVControl _veh select 0;

_groupID = groupId (group _veh);

_operator connectTerminalToUAV objNull;

waitUntil{not isUAVConnected _veh};

{ _veh deleteVehicleCrew _x } forEach crew _veh;

createVehicleCrew _veh;

_veh setGroupIdGlobal [_groupID];

_operator connectTerminalToUAV _veh;

systemChat format ["VMS reset on %1", _groupID];
