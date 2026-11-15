// G/ATOR in multiplayer: does every machine agree on which sounds should be playing?
//   python tools/mp-test/run_server.py gator "<built mod folder>" --mission tools/gator/test/mp.Stratis
// A dedicated server and two headless clients. hc1 works the trailer as an operator's machine
// does (legs, generator, array, letting go part way, turning, packing up); after each step every
// machine logs what PTF_GATOR_fnc_soundWants says on it, which is what its sound loop plays.
// Headless clients have no sound loop of their own, but they see the state a player's machine
// sees. Search the RPTs for GATORMP.
// headless clients show the towed copy too (players' machines do), so they can measure it
if (!isServer) then {PTF_GATOR_towCopyTest = true};
gm_tag = if (isDedicated) then {"SERVER"} else {format ["HC_%1_%2", name player, clientOwner]};
gm_report = {
	params ["_step"];
	private _radar = missionNamespace getVariable ["gm_radar", objNull];
	if (isNull _radar) exitWith {diag_log format ["GATORMP %1 step=%2 no radar", gm_tag, _step]};
	// the motors play while a part moves on this machine: is anything still moving here?
	private _sources = ["ptf_gator_deploy", "ptf_gator_leg_fl", "ptf_gator_leg_fr", "ptf_gator_leg_rl", "ptf_gator_leg_rr"];
	private _a = _sources apply {_radar animationSourcePhase _x};
	sleep 0.5;
	private _moving = _sources select {_radar animationSourcePhase _x != _a select (_sources find _x)};
	diag_log format ["GATORMP %1 step=%2 wants=%3 moving=%4 power=%5 array=%6 legs=%7 targets=%8 sensor=%9",
		gm_tag, _step, [_radar] call PTF_GATOR_fnc_soundWants, _moving, [_radar] call PTF_GATOR_fnc_powerState,
		(_radar animationSourcePhase "ptf_gator_deploy") toFixed 4,
		["fl", "fr", "rl", "rr"] apply {(_radar animationSourcePhase ("ptf_gator_leg_" + _x)) toFixed 4},
		["fl", "fr", "rl", "rr"] apply {_radar getVariable ["PTF_GATOR_legTarget_" + _x, -1]},
		!isNull (_radar getVariable ["PTF_GATOR_sensor", objNull])];
};
// Every machine reports each step a few seconds after the operator's machine announces it.
[] spawn {
	waitUntil {time > 1};
	private _seen = -1;
	while {true} do {
		sleep 0.5;
		private _step = missionNamespace getVariable ["gm_step", -1];
		if (_step != _seen) then {
			_seen = _step;
			sleep 3;
			[_step] call gm_report;
		};
	};
};

// Towing seen from another machine: once the server's AI drives off with the G/ATOR hitched,
// every machine records where it sees the trailer and the truck each frame for 20 s and logs
// how far the trailer's lunette strays from the truck's hitch, and how jerky the trailer moves
// next to the truck (frame-to-frame acceleration). The server's machine drives the tow.
[] spawn {
	waitUntil {sleep 0.5; missionNamespace getVariable ["gm_tow", false]};
	private _radar = missionNamespace getVariable ["gm_radar", objNull];
	private _truck = missionNamespace getVariable ["gm_truck", objNull];
	gm_samples = [];
	gm_speeds = [];
	gm_sampleEnd = diag_tickTime + 20;
	// sampled in a per-frame handler added after the trailer's own, so each frame it reads what
	// the trailer's handler just placed (a mission EachFrame handler ran before it)
	[{
		params ["", "_handle"];
		if (diag_tickTime > gm_sampleEnd) exitWith {[_handle] call CBA_fnc_removePerFrameHandler};
		private _radar = missionNamespace getVariable ["gm_radar", objNull];
		private _truck = missionNamespace getVariable ["gm_truck", objNull];
		gm_speeds pushBack speed _truck;
		// what this machine shows: the copy where there is one
		private _copy = _radar getVariable ["PTF_GATOR_towCopy", objNull];
		if (!isNull _copy) then {gm_copySeen = true; _radar = _copy};
		gm_samples pushBack [diag_tickTime, getPosWorldVisual _radar, getPosWorldVisual _truck,
			(_radar modelToWorldVisualWorld (_radar selectionPosition ["hitch", "Memory"])) distance
			(_truck modelToWorldVisualWorld ([_truck] call PTF_GATOR_fnc_towHitchPoint)),
			// where it was just put (not its visual state), to tell a stale reading from a stale placement
			getPosWorld _radar,
			(_radar modelToWorldWorld (_radar selectionPosition ["hitch", "Memory"])) distance
			(_truck modelToWorldVisualWorld ([_truck] call PTF_GATOR_fnc_towHitchPoint))];
	}, 0, []] call CBA_fnc_addPerFrameHandler;
	waitUntil {sleep 1; diag_tickTime > gm_sampleEnd + 1};
	private _jerk = {
		params ["_i"];
		private _sum = 0;
		private _n = 0;
		for "_k" from 1 to count gm_samples - 2 do {
			private _dt = ((gm_samples select (_k + 1)) select 0) - ((gm_samples select (_k - 1)) select 0);
			if (_dt > 0.001) then {
				private _a = (((gm_samples select (_k + 1)) select _i) vectorAdd ((gm_samples select (_k - 1)) select _i)) vectorDiff (((gm_samples select _k) select _i) vectorMultiply 2);
				_sum = _sum + (vectorMagnitude _a) / ((_dt / 2) ^ 2);
				_n = _n + 1;
			};
		};
		_sum / (_n max 1)
	};
	private _gaps = gm_samples apply {_x select 3};
	diag_log format ["GATORMP %1 copy=%2", gm_tag, missionNamespace getVariable ["gm_copySeen", false]];
	diag_log format ["GATORMP %1 towing frames=%2 gapMean=%3 gapMax=%4 trailerJerk=%5 truckJerk=%6 local=%7 meanSpeed=%8",
		gm_tag, count gm_samples, ((_gaps call BIS_fnc_arithmeticMean) toFixed 3), (selectMax _gaps) toFixed 3,
		([1] call _jerk) toFixed 1, ([2] call _jerk) toFixed 1, local _radar, round (gm_speeds call BIS_fnc_arithmeticMean)];
	private _gapsSet = gm_samples apply {_x select 5};
	diag_log format ["GATORMP %1 placed gapMean=%2 gapMax=%3 trailerJerk=%4",
		gm_tag, ((_gapsSet call BIS_fnc_arithmeticMean) toFixed 3), (selectMax _gapsSet) toFixed 3, ([4] call _jerk) toFixed 1];
};

if (isServer) then {
	[] spawn {
		waitUntil {time > 3};
		private _spot = [[1950, 5750, 0], 0, 600, 15, 0, 0.06, 0] call BIS_fnc_findSafePos;
		_spot set [2, 0];
		private _radar = createVehicle ["PTF_GATOR", _spot, [], 0, "CAN_COLLIDE"];
		_radar setPosATL _spot;
		missionNamespace setVariable ["gm_radar", _radar, true];
		// Which indirect-fire weapons in the modset would it trace? The rule
		// (PTF_GATOR_fnc_cbFired): a shell, rocket, submunition or missile, and either the ammo
		// can be locked by the artillery computer or the vehicle has one.
		{
			private _cfg = _x;
			private _scanner = getNumber (_cfg >> "artilleryScanner") == 1;
			private _mags = [];
			{
				private _t = _x;
				{_mags pushBackUnique _x} forEach getArray (_t >> "magazines");
				{{_mags pushBackUnique _x} forEach getArray (configFile >> "CfgWeapons" >> _x >> "magazines")} forEach getArray (_t >> "weapons");
			} forEach ([_cfg] + ("true" configClasses (_cfg >> "Turrets")));
			private _ammo = [];
			{_ammo pushBackUnique getText (configFile >> "CfgMagazines" >> _x >> "ammo")} forEach _mags;
			private _traced = _ammo select {
				private _a = configFile >> "CfgAmmo" >> _x;
				toLowerANSI getText (_a >> "simulation") in ["shotshell", "shotsubmunitions", "shotrocket", "shotmissile"]
					&& {_scanner || {getNumber (_a >> "artilleryLock") == 1}}
			};
			diag_log format ["GATORMP DETECT %1 (%2) computer=%3 traced %4 of %5: %6 | not: %7", configName _cfg, getText (_cfg >> "displayName"),
				_scanner, count _traced, count _ammo, _traced, _ammo - _traced];
		} forEach ("getNumber (_x >> 'scope') == 2 && {getNumber (_x >> 'artilleryScanner') == 1 || {configName _x isKindOf 'StaticMortar'} || {'mortar' in toLowerANSI configName _x}}" configClasses (configFile >> "CfgVehicles"));
		diag_log "PTFSMOKE SERVER READY";
		private _t = diag_tickTime;
		waitUntil {sleep 1; count allPlayers > 0 || {diag_tickTime > _t + 400}};
		diag_log "PTFSMOKE SERVER HC2GO";
		waitUntil {sleep 1; count allPlayers >= 2 || {diag_tickTime > _t + 600}};
		sleep 5;
		// the first headless client to join works the trailer
		private _hcs = allPlayers select {_x isKindOf "HeadlessClient_F"};
		diag_log format ["GATORMP SERVER players=%1 hcs=%2", allPlayers apply {[name _x, typeOf _x, owner _x]}, count _hcs];
		missionNamespace setVariable ["gm_operator", owner (_hcs param [0, objNull]), true];
		missionNamespace setVariable ["gm_go", true, true];
		waitUntil {sleep 1; missionNamespace getVariable ["gm_done", false] || {diag_tickTime > _t + 1200}};
		sleep 8;
		// Towing: a HEMTT backs up to the lunette, hitches, and the server's AI drives it off.
		private _radar = missionNamespace getVariable ["gm_radar", objNull];
		private _lunette = {_radar modelToWorldVisualWorld (_radar selectionPosition ["hitch", "Memory"])};
		private _truck = createVehicle ["B_Truck_01_transport_F", _radar modelToWorld [0, 12, 0], [], 0, "CAN_COLLIDE"];
		_truck setDir getDir _radar;
		sleep 2;
		private _truckHitch = {_truck modelToWorldVisualWorld ([_truck] call PTF_GATOR_fnc_towHitchPoint)};
		_truck setPosASL ((getPosASL _truck) vectorAdd ((call _lunette) vectorDiff (call _truckHitch)) vectorAdd [0, 0.5, 0]);
		sleep 3;
		missionNamespace setVariable ["gm_truck", _truck, true];
		[_radar, _truck] call PTF_GATOR_fnc_towHitch;
		sleep 2;
		private _driver = (createGroup west) createUnit ["B_Soldier_F", _radar modelToWorld [6, 0, 0], [], 0, "NONE"];
		_driver moveInDriver _truck;
		_driver doMove (_radar getPos [400, getDir _radar]);
		diag_log format ["GATORMP SERVER towing: hitched %1, owner radar %2 truck %3", (_radar getVariable ["PTF_GATOR_tower", objNull]) == _truck, owner _radar, owner _truck];
		sleep 6;
		missionNamespace setVariable ["gm_tow", true, true];
		sleep 26;
		diag_log "PTFSMOKE SERVER DONE";
	};
};

// The operator's machine (a headless client the server picks), doing what the ACE jobs do (they
// run on the player's machine).
if (!isServer && {!hasInterface}) then {
	[] spawn {
		waitUntil {sleep 1; missionNamespace getVariable ["gm_go", false]};
		diag_log format ["GATORMP %1 operator is %2", gm_tag, missionNamespace getVariable ["gm_operator", -1]];
		if (clientOwner != (missionNamespace getVariable ["gm_operator", -1])) exitWith {};
		private _radar = missionNamespace getVariable ["gm_radar", objNull];
		private _step = {
			params ["_n", "_what", "_wait"];
			diag_log format ["GATORMP %1 doing step=%2 %3", gm_tag, _n, _what];
			sleep _wait;
			missionNamespace setVariable ["gm_step", _n, true];
			sleep 5;
		};
		{[_radar, _x, true] call PTF_GATOR_fnc_setLeg; sleep 1} forEach ["fl", "fr", "rl", "rr"];
		[1, "legs down", 14] call _step;
		[_radar, true] call PTF_GATOR_fnc_setPower;
		[2, "generator on", 8] call _step;
		[_radar, true] call PTF_GATOR_fnc_setDeployed;
		sleep 4;
		[_radar, "array"] call PTF_GATOR_fnc_halt;
		[3, "array let go part way", 3] call _step;
		[_radar, true] call PTF_GATOR_fnc_setDeployed;
		[4, "array up", 34] call _step;
		[_radar, true] call PTF_GATOR_fnc_setSpinning;
		[5, "turning", 8] call _step;
		[_radar, false] call PTF_GATOR_fnc_setSpinning;
		[6, "stopped turning", 8] call _step;
		[_radar, false] call PTF_GATOR_fnc_setDeployed;
		[7, "array down", 34] call _step;
		[_radar, false] call PTF_GATOR_fnc_setPower;
		[8, "generator off", 8] call _step;
		// the first leg up unlevels the trailer (the rest settle to their rest lengths), then the rest
		[_radar, "fl", false] call PTF_GATOR_fnc_setLeg;
		[9, "first leg up, the rest settled", 10] call _step;
		{[_radar, _x, false] call PTF_GATOR_fnc_setLeg; sleep 1} forEach ["fr", "rl", "rr"];
		[10, "legs up", 14] call _step;
		missionNamespace setVariable ["gm_done", true, true];
	};
};
