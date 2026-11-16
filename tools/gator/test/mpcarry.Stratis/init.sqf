// G/ATOR in multiplayer: the computer and the SATCOM antenna, taken out by a man on a client.
//   python tools/mp-test/run_server.py carry "<built mod folder>" --mission tools/gator/test/mpcarry.Stratis
// A dedicated server and two headless clients. A man on the first client takes each out on the
// ground and walks 30 m off with it (does it stay in his hands, and does the cable pay out
// behind him, never piled up at the trailer), sets it down (does it stay where he set it), then
// takes it out again on a cargo HQ's roof and sets it down there (does it stay on the roof).
// Search the RPTs for GATORCARRY.
gm_tag = if (isDedicated) then {"SERVER"} else {format ["HC%1", clientOwner]};

if (isServer) then {
	[] spawn {
		waitUntil {time > 3};
		private _spot = [[1950, 5750, 0], 0, 600, 40, 0, 0.06, 0] call BIS_fnc_findSafePos;
		_spot set [2, 0];
		private _radar = createVehicle ["PTF_GATOR", _spot, [], 0, "CAN_COLLIDE"];
		_radar setPosATL _spot;
		private _hq = createVehicle ["Land_Cargo_HQ_V1_F", _radar modelToWorld [0, -30, 0], [], 0, "CAN_COLLIDE"];
		_hq setDir getDir _radar;
		missionNamespace setVariable ["gm_radar", _radar, true];
		missionNamespace setVariable ["gm_hq", _hq, true];
		diag_log "PTFSMOKE SERVER READY";
		private _t = diag_tickTime;
		waitUntil {sleep 1; count allPlayers >= 1 || {diag_tickTime > _t + 600}};
		diag_log "PTFSMOKE SERVER HC2GO";
		waitUntil {sleep 1; count allPlayers >= 2 || {diag_tickTime > _t + 600}};
		sleep 5;
		missionNamespace setVariable ["gm_carrier", owner (allPlayers select 0), true];
		// the server's view of each, once a second, while the client works
		[_radar] spawn {
			params ["_radar"];
			while {true} do {
				{
					_x params ["_var", "_ropeVar"];
					private _thing = _radar getVariable [_var, objNull];
					if (!isNull _thing) then {
						private _rope = _radar getVariable [_ropeVar, objNull];
						diag_log format ["GATORCARRY SERVER %1 attachedTo=%2 dist=%3 z=%4 rope=%5 ropeLen=%6",
							_var, attachedTo _thing, (_thing distance _radar) toFixed 1, ((getPosASL _thing) select 2) toFixed 2,
							!isNull _rope, [-1, ropeLength _rope] select !isNull _rope];
					};
				} forEach [["PTF_GATOR_computer", "PTF_GATOR_computerRope"], ["PTF_GATOR_antenna", "PTF_GATOR_cable"]];
				sleep 1;
			};
		};
		missionNamespace setVariable ["gm_go", true, true];
		waitUntil {sleep 1; missionNamespace getVariable ["gm_done", false] || {diag_tickTime > _t + 900}};
		diag_log "PTFSMOKE SERVER DONE";
	};
};

if (!isServer) then {
	[] spawn {
		waitUntil {sleep 1; missionNamespace getVariable ["gm_go", false]};
		if (clientOwner != (missionNamespace getVariable ["gm_carrier", -1])) exitWith {};
		private _radar = missionNamespace getVariable ["gm_radar", objNull];
		private _hq = missionNamespace getVariable ["gm_hq", objNull];
		private _man = (createGroup west) createUnit ["B_Soldier_F", _radar modelToWorld [-3, 0, 0], [], 0, "CAN_COLLIDE"];
		_man disableAI "ALL";
		sleep 2;
		{
			_x params ["_fnc", "_var", "_ropeVar", "_name"];
			// on the ground beside the trailer, facing it
			_man setPosATL ((_radar modelToWorld [-3, 0, 0]) vectorMultiply [1, 1, 0]);
			_man setDir (_man getDir _radar);
			sleep 1;
			[_radar, "out", _man] call _fnc;
			sleep 3;
			private _thing = _radar getVariable [_var, objNull];
			diag_log format ["GATORCARRY %1 %2 out: held=%3 carrying=%4 dist=%5", gm_tag, _name, attachedTo _thing isEqualTo _man,
				_man getVariable ["ace_dragging_isCarrying", false], (_thing distance _radar) toFixed 1];
			// walks 30 m off, 1 m a step at a walking pace
			private _dir = _radar getDir _man;
			for "_i" from 1 to 30 do {
				_man setPosATL ((_man getPos [1, _dir]) vectorMultiply [1, 1, 0]);
				_man setDir _dir;
				sleep 0.4;
				if (_i % 10 == 0) then {
					private _rope = _radar getVariable [_ropeVar, objNull];
					diag_log format ["GATORCARRY %1 %2 walked %3: held=%4 dist=%5 ropeLen=%6", gm_tag, _name, _i, attachedTo _thing isEqualTo _man,
						(_thing distance _radar) toFixed 1, [-1, ropeLength _rope] select !isNull _rope];
				};
			};
			[_man, _thing] call ace_dragging_fnc_dropObject_carry;
			private _dropped = getPosASL _thing;
			sleep 4;
			diag_log format ["GATORCARRY %1 %2 set down: moved=%3 since", gm_tag, _name, ((getPosASL _thing) distance _dropped) toFixed 2];
			[_radar, "stow"] call _fnc;
			sleep 2;
			// on the cargo HQ's roof
			private _hqAt = getPosASL _hq;
			private _hits = lineIntersectsSurfaces [_hqAt vectorAdd [0, 0, 30], _hqAt, _man, objNull, true, 1, "GEOM", "NONE"];
			private _roof = [(_hqAt select 2) + 6, (_hits param [0, [[0, 0, 0]]]) select 0 select 2] select (_hits isNotEqualTo []);
			_man setPosASL [_hqAt select 0, _hqAt select 1, _roof + 0.1];
			sleep 2;
			[_radar, "out", _man] call _fnc;
			sleep 3;
			_thing = _radar getVariable [_var, objNull];
			private _held = attachedTo _thing isEqualTo _man;
			[_man, _thing] call ace_dragging_fnc_dropObject_carry;
			sleep 4;
			diag_log format ["GATORCARRY %1 %2 roof: held=%3 aboveRoof=%4 (man %5)", gm_tag, _name, _held,
				(((getPosASL _thing) select 2) - _roof) toFixed 2, (((getPosASL _man) select 2) - _roof) toFixed 2];
			[_radar, "stow"] call _fnc;
			sleep 2;
		} forEach [[PTF_GATOR_fnc_computer, "PTF_GATOR_computer", "PTF_GATOR_computerRope", "computer"],
			[PTF_GATOR_fnc_satcom, "PTF_GATOR_antenna", "PTF_GATOR_cable", "antenna"]];
		missionNamespace setVariable ["gm_done", true, true];
	};
};
