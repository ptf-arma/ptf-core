/*
	GLT_fnc_laserCreated  [GLT] Goltred update - not part of the original Turret Enhanced by Fat_Lurch.
	Init event handler of the engine's laser spot object (CfgVehicles >> LaserTarget, see config.cpp).

	Why: "laserTarget <unit>" only finds a soldier's laser on the machine that owns that soldier, so the
	laser of another player's (or a server AI's) handheld designator can't be found from your machine.
	The machine that created the laser spot can find the owner, so it announces it once to everyone:
	CBA global event "GLT_laserOn" [laserObject, owner] -> each player's GLT_laserRegistry
	(XEH_postInit.sqf), used by GLT_fnc_friendlyLasers. Same approach ACE uses for its laser codes.

	Cost: runs once per laser switched on, only on the machine that created it (the server for server AI);
	one small network message per laser switched on.
*/

params ["_laser"];

[{
	params ["_laser"];
	if (isNull _laser || {!local _laser}) exitWith {};

	// Owner: soldier on foot first (handheld designator), then a vehicle / UAV (turrets, pilot camera, crew)
	private _owner = objNull;
	{
		if (isNull objectParent _x && {(laserTarget _x) isEqualTo _laser}) exitWith {_owner = _x};
	} forEach (allUnits select {local _x});

	if (isNull _owner) then
	{
		{
			private _veh = _x;
			private _paths = _veh getVariable "GLT_laserPaths";
			if (isNil "_paths") then
			{
				_paths = [[-1]] + (allTurrets [_veh, false]);
				_veh setVariable ["GLT_laserPaths", _paths];
			};
			if ((laserTarget _veh) isEqualTo _laser
				|| {(_paths findIf {(_veh laserTarget _x) isEqualTo _laser}) >= 0}
				|| {((crew _veh) findIf {(laserTarget _x) isEqualTo _laser}) >= 0}) exitWith {_owner = _veh};
		} forEach (vehicles select {local _x && {crew _x isNotEqualTo []}});
	};

	if (!isNull _owner) then
	{
		["GLT_laserOn", [_laser, _owner]] call CBA_fnc_globalEvent;
	};
}, [_laser]] call CBA_fnc_execNextFrame;	// the laser is linked to its owner after the object is created
