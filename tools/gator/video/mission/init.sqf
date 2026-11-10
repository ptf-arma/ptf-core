// G/ATOR hype video, filmed frame by frame. Run with: python tools/gator/video/make_video.py
// The game runs at quarter speed (setAccTime) and every frame is a screenshot taken 1/30 s of game
// time after the last, so the film is smooth whatever the machine does. Each frame logs the
// sounds the G/ATOR starts or stops ("GATORVID SOUND|LOOP|STOP <name> <frame>") so the
// soundtrack can be laid on afterwards. Scenes: a PTF MRZR towing it, a PTF ACV towing it,
// then it sets up: legs, generator, array up (time-lapse), antenna turning.

#define FPS 30

diag_log "GATORVID start";
waitUntil {time > 0};
showCinemaBorder false;
enableEnvironment [false, true];
enableRadio false;
setDate [2035, 7, 18, 17, 50];
0 setOvercast 0.15;
0 setFog 0;
forceWeatherChange;
disableUserInput true;
player allowDamage false;
player hideObjectGlobal true;

PTFV_frame = 0;
PTFV_subject = objNull;   // what the camera films; it doesn't count as in the way
PTFV_ignore = [];
private _camera = "camera" camCreate [0, 0, 0];
_camera cameraEffect ["internal", "back"];
cameraEffectEnableHUD false;
showHUD false;

// --- A route: a long, gentle stretch of road -------------------------------------------------
private _route = {
	params ["_centre", "_length"];
	private _best = [];
	private _bestScore = 1e9;
	{
		private _road = _x;
		private _prev = objNull;
		private _points = [getPosATL _road];
		private _dir = -1;
		private _total = 0;
		private _turning = 0;
		while {_total < _length} do {
			private _next = (roadsConnectedTo _road) select {_x != _prev && {!(getPosATL _x in _points)}};
			if (_next isEqualTo []) exitWith {};
			private _pick = _next select 0;
			if (_dir >= 0) then {
				private _bestTurn = 360;
				{
					private _turn = abs (((_road getDir _x) - _dir + 540) % 360 - 180);
					if (_turn < _bestTurn) then {_bestTurn = _turn; _pick = _x};
				} forEach _next;
				_turning = _turning + _bestTurn;
			};
			_dir = _road getDir _pick;
			_total = _total + (_road distance2D _pick);
			_prev = _road;
			_road = _pick;
			_points pushBack getPosATL _road;
		};
		if (_total >= _length && {_turning < _bestScore}) then {
			_bestScore = _turning;
			_best = _points;
		};
	} forEach ((_centre nearRoads 600) select {isOnRoad _x});
	_best
};

private _sounds = {
	params ["_radar"];
	private _log = _radar getVariable ["PTF_GATOR_soundLog", []];
	private _seen = _radar getVariable ["PTFV_logSeen", 0];
	for "_i" from _seen to (count _log) - 1 do {
		diag_log format ["GATORVID SOUND %1 %2", _log select _i, PTFV_frame];
	};
	_radar setVariable ["PTFV_logSeen", count _log];
	private _now = keys (_radar getVariable ["PTF_GATOR_soundStreams", createHashMap]);
	private _was = _radar getVariable ["PTFV_streams", []];
	{diag_log format ["GATORVID LOOP %1 %2", _x, PTFV_frame]} forEach (_now - _was);
	{diag_log format ["GATORVID STOP %1 %2", _x, PTFV_frame]} forEach (_was - _now);
	_radar setVariable ["PTFV_streams", _now];
};

// Film: _seconds of footage; _shot positions the camera for progress 0..1; _step is game
// seconds per frame in 1/30ths (4 = a four-times time-lapse).
private _film = {
	params ["_seconds", "_shot", "_radar", ["_step", 1]];
	private _frames = round (_seconds * FPS);
	diag_log format ["GATORVID film %1 s from frame %2 (time %3, accTime %4)", _seconds, PTFV_frame, time, accTime];
	for "_i" from 0 to _frames - 1 do {
		[_i / (_frames max 1)] call _shot;
		_camera camCommit 0;
		sleep (0.5 / FPS);
		private _n = str PTFV_frame;
		while {count _n < 5} do {_n = "0" + _n};
		screenshot format ["gatorvid_%1.png", _n];
		[_radar] call _sounds;
		PTFV_frame = PTFV_frame + 1;
		sleep ((_step - 0.5) / FPS);
	};
};
private _look = {
	params ["_from", "_at", ["_fov", 0.7]];
	// Never film through something: while a pole, a tree or a person stands between the
	// camera and the subject, move in a little and up a little.
	for "_k" from 1 to 8 do {
		private _hits = lineIntersectsSurfaces [AGLToASL _from, AGLToASL _at, PTFV_subject, objNull, true, 1, "VIEW", "FIRE"];
		if (_hits isEqualTo [] || {((_hits select 0) select 2) in PTFV_ignore}) exitWith {};
		_from = (_from vectorAdd ((_at vectorDiff _from) vectorMultiply 0.12)) vectorAdd [0, 0, 0.4];
	};
	_camera camSetPos _from;
	_camera camSetTarget _at;
	_camera camSetFov _fov;
};

// --- The road -------------------------------------------------------------------------------
private _points = [];
{
	_points = [_x, 450] call _route;
	if (_points isNotEqualTo []) exitWith {};
} forEach [[8100, 10000, 0], [5200, 8300, 0], [7000, 5600, 0], [3600, 6000, 0], [6400, 6400, 0]];
diag_log format ["GATORVID route %1 points from %2 to %3", count _points, _points select 0, _points select -1];

private _convoy = {
	params ["_class"];
	private _start = _points select 2;
	private _dir = (_points select 2) getDir (_points select 3);
	diag_log format ["GATORVID convoy %1 at %2", _class, _start];
	private _truck = createVehicle [_class, _start, [], 0, "CAN_COLLIDE"];
	_truck setDir _dir;
	_truck setPosATL _start;
	_truck allowDamage false;
	sleep 1;
	private _radar = createVehicle ["PTF_GATOR", _start getPos [12, _dir + 180], [], 0, "CAN_COLLIDE"];
	_radar setDir _dir;
	_radar allowDamage false;
	sleep 1;
	private _hitch = _truck modelToWorldWorld ([_truck] call PTF_GATOR_fnc_towHitchPoint);
	private _lunette = _radar modelToWorldWorld (_radar selectionPosition ["hitch", "Memory"]);
	_radar setPosASL ((getPosASL _radar) vectorAdd (_hitch vectorDiff _lunette));
	sleep 1;
	[_radar, _truck] call PTF_GATOR_fnc_towHitch;
	diag_log format ["GATORVID hitched %1 to %2", _radar, _truck];
	private _driver = (createGroup west) createUnit ["rhsusf_usmc_marpat_wd_rifleman", _start getPos [6, _dir + 90], [], 0, "NONE"];
	_driver moveInDriver _truck;
	_truck limitSpeed 40;
	_driver doMove (_points select -1);
	sleep 3;
	[_truck, _radar, _driver]
};

diag_log "GATORVID slowing time";
setAccTime 0.25;   // 0.1 is too slow: at high frame rates game time stops advancing
diag_log format ["GATORVID accTime %1", accTime];

// --- Scene 1: the MRZR ---------------------------------------------------------------------
(["PTF_MRZR4"] call _convoy) params ["_truck", "_radar", "_driver"];
PTFV_subject = _radar;
PTFV_ignore = [_truck];
sleep 4;
[8, {
	params ["_t"];
	private _mid = (getPosATL _radar) vectorAdd (((getPosATL _truck) vectorDiff (getPosATL _radar)) vectorMultiply 0.45);
	[_radar modelToWorld [7 - 2 * _t, -9 + 12 * _t, 1.8], _mid vectorAdd [0, 0, 1.2], 0.6] call _look;
}, _radar] call _film;
[6, {
	params ["_t"];
	[_truck modelToWorld [-2.5 + 1 * _t, 9 - 2 * _t, 0.9], _radar modelToWorld [0, 1, 1.2], 0.55] call _look;
}, _radar] call _film;
{deleteVehicle _x} forEach [_driver, _truck, _radar];
sleep 2;

// --- Scene 2: the ACV ----------------------------------------------------------------------
(["PTF_ACV"] call _convoy) params ["_truck", "_radar", "_driver"];
PTFV_subject = _radar;
PTFV_ignore = [_truck];
sleep 4;
[7, {
	params ["_t"];
	[_radar modelToWorld [-8 + 3 * _t, 4 + 4 * _t, 1.1], _radar modelToWorld [0, 3, 1.4], 0.6] call _look;
}, _radar] call _film;
[6, {
	params ["_t"];
	[_truck modelToWorld [12 - 4 * _t, 14, 6 - 2 * _t], _radar modelToWorld [0, 2, 1], 0.55] call _look;
}, _radar] call _film;

// Park at the end of the road, unhitch, and the ACV moves off a little.
waitUntil {sleep 0.5; _truck distance2D (_points select -1) < 25 || {speed _truck < 1 && {_truck distance2D (_points select 2) > 200}}};
doStop _driver;
waitUntil {sleep 0.5; abs speed _truck < 0.5};
[_radar, objNull] call PTF_GATOR_fnc_towHitch;
sleep 3;
_driver doMove (_truck getPos [25, getDir _truck]);
sleep 8;

// --- Scene 3: setting up ---------------------------------------------------------------------
private _crew = [];
{
	_x params ["_offset", "_anim"];
	private _unit = (createGroup west) createUnit ["rhsusf_usmc_marpat_wd_rifleman", _radar modelToWorld _offset, [], 0, "CAN_COLLIDE"];
	_unit setPosATL (_radar modelToWorld _offset);
	_unit setDir ((_unit getDir _radar));
	_unit disableAI "MOVE";
	_unit switchMove _anim;
	_crew pushBack _unit;
} forEach [[[3.6, -4.2, 0], "AmovPercMstpSlowWrflDnon"], [[2.8, 5.5, 0], "AmovPercMstpSlowWrflDnon"], [[-1.6, 6.8, 0], "AmovPercMstpSlowWrflDnon"]];
PTFV_ignore = _crew;
sleep 2;

// Legs, one after another.
[_radar] spawn {
	params ["_radar"];
	{[_radar, _x, true] call PTF_GATOR_fnc_setLeg; sleep 1.2} forEach ["fl", "fr", "rl", "rr"];
};
[7.5, {
	params ["_t"];
	[_radar modelToWorld [-5.2 + 0.4 * _t, 2.2 - 1.2 * _t, 0.9], _radar modelToWorld [-1.5, -1.2 + 0.4 * _t, 0.45], 0.62] call _look;
}, _radar] call _film;

// The generator.
[_radar, true] call PTF_GATOR_fnc_setPower;
[6, {
	params ["_t"];
	[_radar modelToWorld [-4.4, 2.6 - 0.8 * _t, 1.7], _radar modelToWorld [-1.2, 1.0, 1.3], 0.55] call _look;
}, _radar] call _film;

// The array, time-lapsed four times.
[_radar, true] call PTF_GATOR_fnc_setDeployed;
[8.5, {
	params ["_t"];
	private _a = 220 - 70 * _t;
	[_radar modelToWorld [12 * sin _a, 12 * cos _a, 3 + 2 * _t], _radar modelToWorld [0, -0.5, 2.6], 0.7] call _look;
}, _radar, 4] call _film;
waitUntil {sleep 0.25; _radar animationSourcePhase "ptf_gator_deploy" > 0.999};

// Turning.
[_radar, true] call PTF_GATOR_fnc_setSpinning;
[9, {
	params ["_t"];
	private _a = 150 + 80 * _t;
	[_radar modelToWorld [11 * sin _a, 11 * cos _a, 2.6], _radar modelToWorld [0, 0, 3], 0.65] call _look;
}, _radar] call _film;
[4, {
	params ["_t"];
	[_radar modelToWorld [-5, -14 - 6 * _t, 1.2 + 4 * _t], _radar modelToWorld [0, 0, 3.4], 0.75] call _look;
}, _radar] call _film;

setAccTime 1;
diag_log format ["GATORVID DONE %1", PTFV_frame];
