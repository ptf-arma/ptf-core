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

private _name = _markers;
// The rotation index gets its own key: _markers is also the marker-name prefix,
// so storing the index under that name shares one variable with two meanings.
private _idVar = "PTF_spawnIdx_" + _markers;

// _ticket names a CBA setting, which is the configured maximum and is reset to
// its configured value on any CBA settings refresh. Track the live pool in a
// separate variable, seeded from the setting the first time it is touched.
private _liveTicket = "";
if (_ticket != "") then {
    _liveTicket = _ticket + "Current";
    if (isNil _liveTicket) then {
        missionNamespace setVariable [_liveTicket, missionNamespace getVariable [_ticket, 0], true];
    };
};

if (_liveTicket != "" && {(missionNamespace getVariable [_liveTicket, 0]) <= 0}) exitWith {
    ["There are no more tickets"] remoteExec ["hint", _caller];
};

// Build the ring from the exact marker names this function uses ("Name",
// "Name_1", "Name_2", ...). The old test was `_markers in _x`, which is a
// substring match, so a base name of "Vic" also counted "Vicinity".
// Matched case-insensitively, as the old substring test was.
private _allMarkers = allMapMarkers;
private _lowerMarkers = _allMarkers apply {toLower _x};
private _markersA = [];
private _n = 0;
private _wanted = _name;
private _idx = _lowerMarkers find (toLower _wanted);
while {_idx > -1} do {
    _markersA pushBack (_allMarkers select _idx);
    _n = _n + 1;
    _wanted = format ["%1_%2", _name, _n];
    _idx = _lowerMarkers find (toLower _wanted);
};

if (_markersA isEqualTo []) exitWith {
    [format ["No spawn marker named %1 was found", _name]] remoteExec ["hint", _caller];
};

// getMarkerPos on a marker that doesn't exist returns [0,0,0], and a stored
// index can outlive a mission that has fewer markers, so keep it in range.
private _id = (missionNamespace getVariable [_idVar, 0]) mod (count _markersA);

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
if (_liveTicket != "") then {
    private _t = (missionNamespace getVariable [_liveTicket, 0]) - 1;
    missionNamespace setVariable [_liveTicket, _t, true];
    [format ["You have %1 tickets remaining", _t]] remoteExec ["hint", _caller];
};

// advance the spawn location to the next marker in the ring
if (_id == count _markersA - 1) then {
    missionNamespace setVariable [_idVar, 0, true];
} else {
    missionNamespace setVariable [_idVar, _id + 1, true];
};

if (_vehicle == "PTF_MV22_Cargo") then {
    [_vH] call PTF_Fnc_slingloading;
};
