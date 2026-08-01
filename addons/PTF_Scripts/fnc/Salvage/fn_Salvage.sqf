params ["_target", ["_caller", clientOwner]];
//_target = the salvage computer the action was used on
//_caller = owner id to send feedback hints to (set automatically)

// Run authoritatively on the server: deleteVehicle on a server-owned aircraft
// is unreliable from a client and can leave a ghost, and the ticket counter
// can't be raced by two concurrent salvagers.
// Feedback hints are sent back to whoever triggered the action.
if (!isServer) exitWith {
    [_target, clientOwner] remoteExec ["PTF_fnc_Salvage", 2];
};

private _hash = createHashMapFromArray
[
["PTF_UH1Y_GUNFIGHTERS" ,"PTF_Uh1yTickets"],
["PTF_AH1Z_GUNFIGHTERS" , "PTF_Ah1zTickets"],
["PTF_AH1Z_VIS" , "PTF_Ah1zTickets"],
["PTF_F35B_VIS" , "PTF_PlaneTickets"],
["PTF_MQ9_SCARFACE" ,"PTF_MQ9Tickets"]
];


private _SavLocation = nearestObject [_target, "Land_JumpTarget_F"];
// nearestObject must not be handed a null object, so check before using it
if (isNull _SavLocation) exitWith {["No aircraft found to salvage nearby"] remoteExec ["hint", _caller]};

private _heli = nearestObject [_SavLocation, "Air"];
if (isNull _heli) exitWith {["No aircraft found to salvage nearby"] remoteExec ["hint", _caller]};

if (_SavLocation distance _heli > 10) exitWith {["Object is to far away"] remoteExec ["hint", _caller]};

// getHitPointDamage returns -1 for a hitpoint the vehicle doesn't have, and the
// F-35 and MQ-9 in the table have no "hithull", so -1 <= 0.8 made salvage
// always report "repairable" for them. Fall back to overall damage instead.
private _hull = _heli getHitPointDamage "hithull";
if (_hull < 0) then {_hull = damage _heli};
if (_hull <= 0.8) exitWith {["This Helicopter is repairable"] remoteExec ["hint", _caller]};

if (typeof _heli in _hash) then {
private _ticket = _hash get typeOf _heli;
// _ticket names a CBA setting, which is the configured maximum and is reset to
// its configured value on any CBA settings refresh. Track the live pool in a
// separate variable, seeded from the setting the first time it is touched.
private _liveTicket = _ticket + "Current";
if (isNil _liveTicket) then {
	missionNamespace setVariable [_liveTicket, missionNamespace getVariable [_ticket, 0], true];
};
private _t = (missionNamespace getVariable [_liveTicket, 0]) + 1;
missionNamespace setVariable [_liveTicket, _t, true];
[format ["you have added a ticket to %1 there are now %2 tickets remaining", _ticket, _t]] remoteExec ["hint", _caller];
};

deleteVehicle _heli;
