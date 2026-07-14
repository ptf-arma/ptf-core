params ["_vehicle", "_markers", ["_ticket", ""], ["_caller", clientOwner]];
//_vehicle = class name
//_markers = the name of the marker for the spawn location
//_ticket  = name of the mission variable to decrement by 1 ("" for none)
//_caller  = owner id to send feedback hints to (set automatically)

// Run authoritatively on the server so the spawned vehicle is server-owned
// (JIP-safe) and the ticket counter can't be raced by two concurrent callers.
// Feedback hints are sent back to whoever triggered the action.
if (!isServer) exitWith {
    [_vehicle, _markers, _ticket, clientOwner] remoteExec ["PTF_fnc_SpawnFunction", 2];
};

private _id = missionNamespace getVariable [_markers, 0];
private _name = _markers;
private _cnt = { _markers in _x } count allMapMarkers;

if (_ticket != "" && {(missionNamespace getVariable [_ticket, 0]) <= 0}) exitWith {
    ["There are no more tickets"] remoteExec ["hint", _caller];
};

private _markersA = [_name];
for "_i" from 1 to _cnt - 1 do {
    _markersA pushBack format ["%1_%2", _name, _i];
};

// find if an object is blocking the pad
private _check = nearestObjects [getMarkerPos [_markersA select _id], ["LandVehicle", "Air", "Ship"], 7];
if (_check isNotEqualTo []) exitWith {
    ["Spawning location is blocked"] remoteExec ["hint", _caller];
};

private _vH = createVehicle [_vehicle, getMarkerPos [_markersA select _id]];
_vH setDir (markerDir (_markersA select _id));

if (_vH isKindOf "UAV") then {
    private _uavgroup = createGroup [west, true];
    for "_i" from 1 to (_vH emptyPositions "") do {
        private _unit = _uavgroup createUnit ["B_UAV_AI", [0,0,0], [], 0, "NONE"];
        _unit moveInAny _vH;
    };
};

// decrement the ticket pool (server-authoritative, so no race)
if (_ticket != "") then {
    private _t = (missionNamespace getVariable [_ticket, 0]) - 1;
    missionNamespace setVariable [_ticket, _t, true];
    [format ["You have %1 tickets remaining", _t]] remoteExec ["hint", _caller];
};

// advance the spawn location to the next marker in the ring
if (_id == count _markersA - 1) then {
    missionNamespace setVariable [_markers, 0, true];
} else {
    missionNamespace setVariable [_markers, _id + 1, true];
};

if (_vehicle == "PTF_MV22_Cargo") then {
    [_vH] call PTF_Fnc_slingloading;
};
