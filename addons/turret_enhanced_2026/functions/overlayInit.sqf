/*
	GLT_fnc_overlayInit  (Turret Enhanced 2026 Version)
	(called once per client from XEH_postInit.sqf)
	Sets up:
		- a 0.5 s housekeeping loop:
			* lazy vehicle setup: the first time the local player looks through the camera of a vehicle
			  of an enabled type, the original fatlurch_fnc_MPaddaction runs on it (scroll actions + HUD).
			  This replaces the original init event handler, which ran for every plane / helicopter on
			  every machine and started a 200 Hz HUD loop for each.
			* laser caches for the map: candidate vehicles (enabled types, crewed, minus MQ-9s when
			  "Skip MQ-9" is on) and the ones currently lasing
			* hooks the laser map drawing into the main map and UAV terminal map
			* friendly laser spots for the camera view (GLT_fnc_friendlyLasers)
		- a single Draw3D handler for the camera overlay (markers + friendly lasers)
*/

if (!hasInterface) exitWith {};

GLT_lasingCache = [];

[{
	// --- Lazy per-player vehicle setup (actions + HUD), only for vehicles actually used
	private _isr = call GLT_fnc_getISRVehicle;
	if (!isNull _isr && {!(_isr getVariable ["GLT_teInit", false])}) then
	{
		_isr setVariable ["GLT_teInit", true];
		_isr spawn fatlurch_fnc_MPaddaction;
	};

	// --- Laser caches
	private _skipMQ9 = missionNamespace getVariable ["GLT_LaserMapSkipMQ9", true];
	private _candidates = vehicles select {
		_x isKindOf "Air"
		&& {alive _x}
		&& {crew _x isNotEqualTo []}
		&& {[_x] call GLT_fnc_isEnabledFor}
		&& {!_skipMQ9 || {!([_x] call GLT_fnc_isMQ9)}}
	};
	GLT_lasingCache = _candidates select {([_x] call GLT_fnc_laserInfo) isNotEqualTo []};

	// --- Markers for the camera overlay (drawn every frame from this list)
	call GLT_fnc_buildOverlayList;

	// --- Other friendly lasers for the camera overlay (drawn every frame from this list)
	call GLT_fnc_friendlyLasers;

	// --- Attach the laser map drawing to any map control that exists and isn't hooked yet
	{
		private _ctrl = (findDisplay _x) displayCtrl 51;
		if (!isNull _ctrl && {!(_ctrl getVariable ["GLT_laserDraw", false])}) then
		{
			_ctrl setVariable ["GLT_laserDraw", true];
			_ctrl ctrlAddEventHandler ["Draw", {_this call GLT_fnc_drawLaserMap}];
		};
	} forEach [12, 160];	// 12 = main map, 160 = UAV terminal
}, 0.5] call CBA_fnc_addPerFrameHandler;

addMissionEventHandler ["Draw3D", {
	call GLT_fnc_drawMarkerOverlay;
	call GLT_fnc_drawLaserOverlay;
}];
