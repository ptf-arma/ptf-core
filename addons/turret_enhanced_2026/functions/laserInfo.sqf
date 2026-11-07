/*
	GLT_fnc_laserInfo  (Turret Enhanced 2026 Version)
	If any camera/turret (or crew member) of the vehicle is lasing, returns where the beam starts and ends.
	Works on every client without network traffic: laser target objects are global.

	Params: _veh <OBJECT>
	Returns: [_originASL, _targetASL] or [] when no laser is on
*/

params [["_veh", objNull, [objNull]]];

if (isNull _veh) exitWith {[]};

// Turret paths to check, cached per vehicle: pilot camera [-1] + all non-FFV turrets
private _paths = _veh getVariable "GLT_laserPaths";
if (isNil "_paths") then
{
	_paths = [[-1]] + (allTurrets [_veh, false]);
	_veh setVariable ["GLT_laserPaths", _paths];
};

private _path = [];
private _laser = objNull;
{
	private _lt = _veh laserTarget _x;
	if (!isNull _lt) exitWith {_path = _x; _laser = _lt};
} forEach _paths;

// Fallbacks: the vehicle's primary gunner, then every crew member. Pilots lasing through the pilot
// camera (jets) are usually only reported on the unit, not on the vehicle's turret path.
if (isNull _laser) then
{
	private _lt = laserTarget _veh;
	if (!isNull _lt) then
	{
		_laser = _lt;
		_path = if (isNull gunner _veh) then {[0]} else {_veh unitTurret (gunner _veh)};
	}
	else
	{
		{
			private _unitLaser = laserTarget _x;
			if (!isNull _unitLaser) exitWith {_laser = _unitLaser; _path = _veh unitTurret _x};
		} forEach (crew _veh);
	};
};

if (isNull _laser) exitWith {[]};

// Beam origin: gunner optics memory point / pilot camera position, cached per turret
private _cacheKey = "GLT_laserOrigin" + str _path;
private _offset = _veh getVariable _cacheKey;
if (isNil "_offset") then
{
	_offset = [0, 0, -1];
	if (_path isEqualTo [-1] || {_path isEqualTo []}) then
	{
		if (hasPilotCamera _veh) then {_offset = getPilotCameraPosition _veh};
	}
	else
	{
		private _memPoint = getText (([_veh, _path] call BIS_fnc_turretConfig) >> "memoryPointGunnerOptics");
		if (_memPoint != "") then
		{
			private _sel = _veh selectionPosition [_memPoint, "Memory"];
			if (_sel isNotEqualTo [0, 0, 0]) then {_offset = _sel};
		};
	};
	_veh setVariable [_cacheKey, _offset];
};

[_veh modelToWorldVisualWorld _offset, getPosASLVisual _laser]
