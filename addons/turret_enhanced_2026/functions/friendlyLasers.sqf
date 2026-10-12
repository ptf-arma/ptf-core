/*
	GLT_fnc_friendlyLasers  [GLT] Goltred update - not part of the original Turret Enhanced by Fat_Lurch.
	Rebuilds GLT_friendlyLasers, the active laser spots of friendly players / units / vehicles, drawn in
	the camera view by GLT_fnc_drawLaserOverlay. Runs twice a second from GLT_fnc_overlayInit, and only while
	the local player is in a camera view (otherwise the list is emptied).

	Sources:
		- GLT_laserRegistry: lasers announced by the machine that created them (GLT_fnc_laserCreated) - the
		  only way to see another player's / a server AI's handheld designator
		- backup for lasers switched on before you joined, or local ones: soldiers on foot
		  (laserTarget <unit>) and crewed vehicles of any type (every turret, pilot camera and crew)
	Friendly = side relation >= 0.6 to the player's side. Only the vehicle whose camera you are using is
	skipped (that camera already shows its own laser); your own soldier / aircraft are shown from other cameras.

	Label: the group name of whoever is lasing (several lasers from one group share the name). With ACE
	loaded, the ACE laser code is added: "Alpha 1-1  [1111]". ACE keeps the code on the laser source: the
	soldier for handheld designators, the vehicle / UAV for vehicle lasers (ace_laser_fnc_getLaserCode).

	Settings (Laser): GLT_LaserOverlayAllow (server-wide), GLT_LaserOverlayShow (player).

	Result: GLT_friendlyLasers = [[_laserTargetObject, _label], ...]
*/

if (!hasInterface) exitWith {};

GLT_friendlyLasers = [];

// Lasers allowed / shown, and not in Declutter mode (GLT_fnc_overlayModes)
if (!((call GLT_fnc_overlayModes) select 3)) exitWith {};
private _camVeh = call GLT_fnc_getISRVehicle;
if (isNull _camVeh) exitWith {};

// Only the vehicle whose camera you are looking through is skipped (that camera already shows its own
// laser). Your own soldier / your own aircraft ARE shown when you look through another camera, e.g. your
// F-35's targeting-pod laser while you fly a Darter, or the designator you left on before taking a UAV.
private _own = [_camVeh];
private _found = [];	// laser objects already listed (one laser can be reported by vehicle and crew)

private _isFriendly = {
	params ["_side"];
	_side != sideUnknown && {(_side getFriend playerSide) >= 0.6}
};

if (isNil "GLT_aceLaser") then {GLT_aceLaser = isClass (configFile >> "CfgPatches" >> "ace_laser")};

private _labelFor = {
	params ["_source"];
	private _group = groupId group effectiveCommander _source;
	if (!GLT_aceLaser) exitWith {_group};
	private _code = if (isNil "ace_laser_fnc_getLaserCode") then
	{
		_source getVariable ["ace_laser_code", 1111]	// ACE default code
	}
	else
	{
		[_source] call ace_laser_fnc_getLaserCode
	};
	format ["%1  [%2]", _group, _code]
};

private _add = {
	params ["_laser", "_source"];
	if (!isNull _laser && {!(_laser in _found)}) then
	{
		_found pushBack _laser;
		GLT_friendlyLasers pushBack [_laser, [_source] call _labelFor];
	};
};

// --- Lasers announced by their owner's machine (drop the ones switched off / owner gone)
GLT_laserRegistry = (missionNamespace getVariable ["GLT_laserRegistry", []]) select {!isNull (_x select 0) && {!isNull (_x select 1)}};
{
	_x params ["_laser", "_owner"];
	if (alive _owner && {!(_owner in _own)} && {!((objectParent _owner) in _own)} && {[side group effectiveCommander _owner] call _isFriendly}) then
	{
		[_laser, _owner] call _add;
	};
} forEach GLT_laserRegistry;

// --- Soldiers on foot (handheld designators)
{
	if (alive _x && {isNull objectParent _x} && {!(_x in _own)} && {[side group _x] call _isFriendly}) then
	{
		[laserTarget _x, _x] call _add;
	};
} forEach allUnits;

// --- Crewed vehicles: every turret path, the vehicle itself, then each crew member
{
	private _veh = _x;
	if (alive _veh && {!(_veh in _own)} && {crew _veh isNotEqualTo []} && {[side group effectiveCommander _veh] call _isFriendly}) then
	{
		// Same per-vehicle path cache as GLT_fnc_laserInfo: pilot camera [-1] + all non-FFV turrets
		private _paths = _veh getVariable "GLT_laserPaths";
		if (isNil "_paths") then
		{
			_paths = [[-1]] + (allTurrets [_veh, false]);
			_veh setVariable ["GLT_laserPaths", _paths];
		};
		{[_veh laserTarget _x, _veh] call _add} forEach _paths;
		[laserTarget _veh, _veh] call _add;
		{[laserTarget _x, _veh] call _add} forEach (crew _veh);
	};
} forEach vehicles;
