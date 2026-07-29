// Allocates a callsign for an LZ or resupply marker from one canonical pool.
// Server only - callers reach it through PTF_fnc_lz / PTF_fnc_re, which forward
// to the server first.
//
// _prefix  - internal marker-name stem, e.g. "PTF_lz"
// _setting - name of the CBA setting holding the callsign list, e.g. "PTF_LzNames"
//
// Returns [markerName, callsign], or [] if the setting is missing or unusable.
//
// Allocation works by scanning allMapMarkers for the marker each callsign would
// own, rather than by advancing a counter. That makes recycling automatic: when
// a marker is deleted its callsign is free again on the next placement. There is
// no MarkerDeleted handler to register and no allocation table that can drift
// out of step with what is actually on the map - the map IS the state.
params ["_prefix", "_setting"];

if (!isServer) exitWith {[]};

private _raw = missionNamespace getVariable _setting;
if (isNil "_raw") exitWith {[]};

private _names = call compile _raw;
if (!(_names isEqualType [])) exitWith {[]};

_names = _names select {_x isEqualType ""};
if (_names isEqualTo []) exitWith {[]};

private _live = allMapMarkers;
private _index = -1;
{
   if (!(format ["%1_%2", _prefix, _forEachIndex] in _live)) exitWith {_index = _forEachIndex};
} forEach _names;

if (_index > -1) exitWith {
   [format ["%1_%2", _prefix, _index], _names select _index]
};

// Every callsign in the list is already on the map. Fall back to a numbered one
// so the marker still places and its callsign is still unique - running out of
// names should cost you a tidy callsign, not the marker.
private _overflowVar = _prefix + "_overflow";
private _n = (missionNamespace getVariable [_overflowVar, 0]) + 1;
missionNamespace setVariable [_overflowVar, _n];

[format ["%1_x%2", _prefix, _n], format ["%1", _n]]
