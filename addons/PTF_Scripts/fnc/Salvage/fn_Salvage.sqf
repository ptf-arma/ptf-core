params ["_target"];

_hash = createHashMapFromArray
[
["PTF_UH1Y_GUNFIGHTERS" ,"PTF_Uh1yTickets"],
["PTF_AH1Z_GUNFIGHTERS" , "PTF_Ah1zTickets"],
["PTF_AH1Z_VIS" , "PTF_Ah1zTickets"],
["PTF_F18D" , "PTF_PlaneTickets"],
["PTF_F18C_CAG" , "PTF_PlaneTickets"],
["FIR_EA6B_VMAQ4" , "PTF_PlaneTickets"],
["PTF_F35Stealth" , "PTF_PlaneTickets"],
["FIR_F35B_Blank1" , "PTF_PlaneTickets"],
["PTF_F35B_VIS" , "PTF_PlaneTickets"],
["PTF_MQ9_SCARFACE" ,"PTF_MQ9Tickets"]
];


_SavLocation = nearestObject [_target, "Land_JumpTarget_F"];
_heli = nearestObject [_SavLocation, "Air"];


if (_SavLocation distance _heli > 10) exitWith {hint "Object is to far away"};
if (_heli getHitPointDamage "hithull" <= 0.8) exitWith {hint "This Helicopter is repairable"};

if (typeof _heli in _hash) then {
_ticket = _hash get typeOf _heli;
_t = missionNamespace getVariable _ticket;
_t = _t + 1;
missionNamespace setVariable [_ticket, _t];
publicVariable _ticket;
hint format ["you have added a ticket to %1 there are now %2 tickets remaining", _ticket, _t];
deleteVehicle _heli;
} else {
deleteVehicle _heli;
};


