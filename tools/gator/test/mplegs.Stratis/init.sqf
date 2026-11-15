// G/ATOR in multiplayer: do every machine's legs agree after a player has towed it?
//   python tools/mp-test/run_server.py legs "<built mod folder>" --mission tools/gator/test/mplegs.Stratis
// A dedicated server and two headless clients. An AI on the first client tows the trailer (so
// that machine owns it, as a player driving it would), unhitches, then the other client lowers
// and raises the legs. After each step every machine logs the legs as it sees them. Search the
// RPTs for GATORLEGS. Also: a missile fired on a client is listed on the server for the radars.
gm_tag = if (isDedicated) then {"SERVER"} else {format ["HC%1", clientOwner]};
gm_report = {
	params ["_step"];
	private _radar = missionNamespace getVariable ["gm_radar", objNull];
	diag_log format ["GATORLEGS %1 step=%2 local=%3 legs=%4 targets=%5 states=%6 leveled=%7 levelling=%8",
		gm_tag, _step, local _radar,
		["fl", "fr", "rl", "rr"] apply {(_radar animationSourcePhase ("ptf_gator_leg_" + _x)) toFixed 3},
		["fl", "fr", "rl", "rr"] apply {_radar getVariable ["PTF_GATOR_legTarget_" + _x, -1]},
		["fl", "fr", "rl", "rr"] apply {[_radar, _x] call PTF_GATOR_fnc_legState},
		_radar getVariable ["PTF_GATOR_leveled", false], _radar getVariable ["PTF_GATOR_levelling", false]];
};
[] spawn {
	waitUntil {time > 1};
	private _seen = "";
	while {true} do {
		sleep 0.5;
		private _step = missionNamespace getVariable ["gm_step", ""];
		if (_step != _seen) then {
			_seen = _step;
			sleep 2;
			[_step] call gm_report;
		};
	};
};

if (isServer) then {
	[] spawn {
		waitUntil {time > 3};
		private _spot = [[1950, 5750, 0], 0, 600, 15, 0, 0.06, 0] call BIS_fnc_findSafePos;
		_spot set [2, 0];
		private _radar = createVehicle ["PTF_GATOR", _spot, [], 0, "CAN_COLLIDE"];
		_radar setPosATL _spot;
		missionNamespace setVariable ["gm_radar", _radar, true];
		diag_log "PTFSMOKE SERVER READY";
		private _t = diag_tickTime;
		waitUntil {sleep 1; count allPlayers >= 1 || {diag_tickTime > _t + 600}};
		diag_log "PTFSMOKE SERVER HC2GO";
		waitUntil {sleep 1; count allPlayers >= 2 || {diag_tickTime > _t + 600}};
		sleep 5;
		private _clients = allPlayers apply {owner _x};
		diag_log format ["GATORLEGS SERVER players=%1", allPlayers apply {[name _x, typeOf _x, owner _x]}];
		private _driverMachine = _clients select 0;
		missionNamespace setVariable ["gm_operator", _clients param [1, _driverMachine], true];

		// Tow: a HEMTT backs up to the lunette and hitches; its driver's group goes to a client.
		private _lunette = {_radar modelToWorldVisualWorld (_radar selectionPosition ["hitch", "Memory"])};
		private _truck = createVehicle ["B_Truck_01_transport_F", _radar modelToWorld [0, 12, 0], [], 0, "CAN_COLLIDE"];
		_truck setDir getDir _radar;
		sleep 2;
		private _truckHitch = {_truck modelToWorldVisualWorld ([_truck] call PTF_GATOR_fnc_towHitchPoint)};
		_truck setPosASL ((getPosASL _truck) vectorAdd ((call _lunette) vectorDiff (call _truckHitch)) vectorAdd [0, 0.5, 0]);
		sleep 3;
		[_radar, _truck] call PTF_GATOR_fnc_towHitch;
		private _group = createGroup west;
		private _driver = _group createUnit ["B_Soldier_F", _radar modelToWorld [6, 0, 0], [], 0, "NONE"];
		_driver moveInDriver _truck;
		sleep 1;
		_group setGroupOwner _driverMachine;
		sleep 2;
		[_driver, _radar getPos [150, getDir _radar]] remoteExecCall ["doMove", _driverMachine];
		sleep 25;
		diag_log format ["GATORLEGS SERVER towing: owner radar %1 truck %2, moved %3 m", owner _radar, owner _truck, round (_radar distance2D _spot)];
		[_driver] remoteExecCall ["doStop", _driverMachine];
		waitUntil {sleep 0.5; abs speed _truck < 0.5};
		sleep 2;
		[_radar, objNull] call PTF_GATOR_fnc_towHitch;
		sleep 5;
		diag_log format ["GATORLEGS SERVER unhitched: owner radar %1 (server 2), truck %2", owner _radar, owner _truck];
		missionNamespace setVariable ["gm_step", "unhitched", true];
		sleep 6;
		missionNamespace setVariable ["gm_legs", true, true];
		waitUntil {sleep 1; missionNamespace getVariable ["gm_legsDone", false] || {diag_tickTime > _t + 1200}};
		diag_log format ["GATORLEGS SERVER after legs: owner radar %1", owner _radar];

		// A missile fired on a client: listed here while a G/ATOR is transmitting (for real: the
		// radar loop keeps its list).
		{[_radar, _x, true, true] call PTF_GATOR_fnc_setLeg} forEach ["fl", "fr", "rl", "rr"];
		[_radar, true, true] call PTF_GATOR_fnc_setPower;
		sleep 1;
		[_radar, true, true] call PTF_GATOR_fnc_setDeployed;
		sleep 1;
		[_radar, true] call PTF_GATOR_fnc_setSpinning;
		sleep 4;
		diag_log format ["GATORLEGS SERVER transmitting: %1", missionNamespace getVariable ["PTF_GATOR_cbRadars", []]];
		missionNamespace setVariable ["gm_fire", true, true];
		private _seen = 0;
		private _end = time + 15;
		waitUntil {
			sleep 0.2;
			_seen = _seen max ({!isNull (_x select 0)} count (missionNamespace getVariable ["PTF_GATOR_missiles", []]));
			time > _end
		};
		diag_log format ["GATORLEGS SERVER missiles seen in flight: %1 (listed %2)", _seen, count (missionNamespace getVariable ["PTF_GATOR_missiles", []])];
		diag_log "PTFSMOKE SERVER DONE";
	};
};

if (!isServer) then {
	[] spawn {
		waitUntil {sleep 1; missionNamespace getVariable ["gm_legs", false]};
		if (clientOwner != (missionNamespace getVariable ["gm_operator", -1])) exitWith {};
		private _radar = missionNamespace getVariable ["gm_radar", objNull];
		diag_log format ["GATORLEGS %1 operator: lowering", gm_tag];
		{diag_log format ["GATORLEGS %1 lower %2: %3", gm_tag, _x, [_radar, _x, true] call PTF_GATOR_fnc_setLeg]; sleep 1} forEach ["fl", "fr", "rl", "rr"];
		sleep 18;
		missionNamespace setVariable ["gm_step", "legs down", true];
		sleep 5;
		diag_log format ["GATORLEGS %1 operator: raising", gm_tag];
		{diag_log format ["GATORLEGS %1 raise %2: %3", gm_tag, _x, [_radar, _x, false] call PTF_GATOR_fnc_setLeg]; sleep 1} forEach ["fl", "fr", "rl", "rr"];
		sleep 18;
		missionNamespace setVariable ["gm_step", "legs up", true];
		sleep 5;
		missionNamespace setVariable ["gm_legsDone", true, true];
	};
	// the first client fires an anti-tank missile from a launcher of its own
	[] spawn {
		waitUntil {sleep 1; missionNamespace getVariable ["gm_fire", false]};
		if (clientOwner == (missionNamespace getVariable ["gm_operator", -1]) && {count allPlayers > 1}) exitWith {};
		private _radar = missionNamespace getVariable ["gm_radar", objNull];
		private _at = createVehicle ["B_static_AA_F", _radar getPos [60, 90], [], 0, "NONE"];
		createVehicleCrew _at;
		_at addEventHandler ["Fired", {diag_log format ["GATORLEGS %1 fired %2, projectile %3", gm_tag, _this select 4, _this select 6]}];
		sleep 3;
		private _gunner = gunner _at;
		_gunner doWatch ((_at getPos [2000, 90]) vectorAdd [0, 0, 1500]);
		sleep 3;
		private _weapon = (_at weaponsTurret [0]) param [0, ""];
		diag_log format ["GATORLEGS %1 firing %2 local %3", gm_tag, _weapon, local _at];
		[_at, _weapon] call BIS_fnc_fire;
	};
};
