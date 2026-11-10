// Counter-battery test, on Altis with the full PTF modset and a Billet build carrying the map
// layer slot:
//   python tools/gator/test/run.py --mission tools/gator/test/counterbattery.Altis --full --extra <billet>/mod/.hemttout/build/addons
// A transmitting G/ATOR cabled to a SATCOM antenna; a mortar 2.5 km off fires one round, then
// more; an MLRS 11 km off fires; a mortar whose rounds never come near fires; then EMCON,
// stowing the antenna, and the cable coming out on its own. Screenshots of the cable and the tablet.
private _check = {
	params ["_name", "_ok", ["_detail", ""]];
	diag_log format ["GATORTEST %1 %2 %3", ["FAIL", "PASS"] select _ok, _name, _detail];
};
diag_log "GATORTEST start";
waitUntil {time > 0};
setDate [2035, 7, 18, 11, 0];
0 setOvercast 0.1;
0 setFog 0;
forceWeatherChange;
disableUserInput true;
showCinemaBorder false;

private _spot = [[14600, 16700, 0], 0, 800, 15, 0, 0.06, 0] call BIS_fnc_findSafePos;
_spot set [2, 0];
player setPosATL (_spot vectorAdd [-8, -8, 0]);
player addItem "blk_tabletItem";
private _radar = createVehicle ["PTF_GATOR", _spot, [], 0, "CAN_COLLIDE"];
_radar setDir 0;
_radar setPosATL _spot;
sleep 8;
{[_radar, _x, true, true] call PTF_GATOR_fnc_setLeg} forEach ["fl", "fr", "rl", "rr"];
[_radar, true, true] call PTF_GATOR_fnc_setPower;
sleep 2;
[_radar, true, true] call PTF_GATOR_fnc_setDeployed;
sleep 2;
[_radar, true] call PTF_GATOR_fnc_setSpinning;
sleep 4;
["listed while transmitting", (missionNamespace getVariable ["PTF_GATOR_cbRadars", []]) findIf {(_x select 0) == _radar} >= 0] call _check;

// The SATCOM antenna and its cable.
// Taken out of the trailer into the player's hands, set down 14 m off.
private _setDown = {
	[_radar, "out", player] call PTF_GATOR_fnc_satcom;
	sleep 2;
	private _a = _radar getVariable ["PTF_GATOR_antenna", objNull];
	[player, _a] call ace_dragging_fnc_dropObject;
	sleep 0.5;
	_a setPosATL ((_radar modelToWorld [-14, -2, 0]) vectorMultiply [1, 1, 0]);
	sleep 3;
	_a
};
private _satcom = call _setDown;
["the SATCOM antenna comes out", !isNull _satcom, typeOf _satcom] call _check;
private _pic = missionNamespace getVariable ["PTF_GATOR_picture", [0, [], [], []]];
["cabled and on the network", (_radar getVariable ["PTF_GATOR_satcom", objNull]) isEqualTo _satcom && {ropes _radar isNotEqualTo []} && {count (_pic select 1) == 1},
	format ["ropes %1, picture radars %2, leveled %3", ropes _radar, _pic select 1, _radar getVariable "PTF_GATOR_leveled"]] call _check;

private _camera = "camera" camCreate [0, 0, 0];
_camera cameraEffect ["internal", "back"];
showHUD false;
_camera camSetPos (_radar modelToWorld [-2.5, 4, 2.4]);
_camera camSetTarget (_radar modelToWorld [-9, -2.5, 0.3]);
_camera camSetFov 0.6;
_camera camCommit 0;
sleep 2;
screenshot "gatortest_cb_cable.png";
sleep 1;

// A gun and its crew, aimed at a point near the G/ATOR, on land the given distance off (the
// first bearing from the one given that has some).
private _battery = {
	params ["_class", "_mag", "_distance", "_bearing", "_aim"];
	private _at = [];
	for "_b" from _bearing to _bearing + 350 step 10 do {
		private _try = [_radar getPos [_distance, _b], 0, 250, 8, 0, 0.3, 0, [], [[0, 0, 0], [0, 0, 0]]] call BIS_fnc_findSafePos;
		if (_try isNotEqualTo [0, 0, 0] && {abs ((_try distance2D _radar) - _distance) < 400}) exitWith {_at = _try};
	};
	if (_at isEqualTo []) then {_at = _radar getPos [_distance, _bearing]};
	private _gun = createVehicle [_class, [_at select 0, _at select 1, 0], [], 0, "NONE"];
	createVehicleCrew _gun;
	(group gunner _gun) setBehaviour "CARELESS";
	_gun allowDamage false;
	sleep 8;   // the crew settles in before it takes orders
	[_gun, _radar getPos _aim, _mag]
};
private _fire = {
	params ["_gun", "_target", "_mag", "_rounds"];
	_gun setVehicleAmmo 1;
	(gunner _gun) doArtilleryFire [_target, _mag, _rounds];
};
private _tracks = {_radar getVariable ["PTF_GATOR_cbTracks", []]};

(["O_Mortar_01_F", "8Rnd_82mm_Mo_shells", 2500, 80, [350, 260]] call _battery) params ["_mortar", "_aimM", "_magM"];
private _range = _mortar distance2D _radar;
["mortar can reach", _aimM inRangeOfArtillery [[_mortar], _magM], format ["%1 m off", round _range]] call _check;
[_mortar, _aimM, _magM, 1] call _fire;
private _t0 = time;
waitUntil {sleep 1; count (call _tracks) > 0 || {time - _t0 > 150}};
sleep 1;
private _first = (call _tracks) param [0, createHashMap];
private _miss = (_first getOrDefault ["point", [0, 0]]) distance2D (getPosASL _mortar);
["one round traced", count (call _tracks) == 1 && {(_first getOrDefault ["kind", ""]) == "point"} && {_miss < 3.5 * 0.04 * _range},
	format ["after %1 s: tracks %2, miss %3 m at %4 m (4 pc is %5 m), error shown %6", round (time - _t0), count (call _tracks), round _miss, round _range, round (0.04 * _range), _first getOrDefault ["error", -1]]] call _check;
[_mortar, _aimM, _magM, 7] call _fire;
_t0 = time;
waitUntil {sleep 1; _first = (call _tracks) param [0, createHashMap]; (_first getOrDefault ["rounds", 0]) >= 6 || {time - _t0 > 150}};
sleep 8;
_first = (call _tracks) param [0, createHashMap];
_miss = (_first getOrDefault ["point", [0, 0]]) distance2D (getPosASL _mortar);
["rounds average down", count (call _tracks) == 1 && {(_first getOrDefault ["rounds", 0]) >= 6} && {(_first getOrDefault ["error", 1e9]) < 0.04 * _range / 2.2} && {_miss < 3 * (_first getOrDefault ["error", 0])},
	format ["tracks %1, rounds %2, error shown %3 m, miss %4 m", count (call _tracks), _first getOrDefault ["rounds", 0], round (_first getOrDefault ["error", -1]), round _miss]] call _check;

// An enemy helicopter circling 5 km off: an air track.
private _heli = createVehicle ["O_Heli_Light_02_dynamicLoadout_F", (_radar getPos [5000, 300]) vectorAdd [0, 0, 300], [], 0, "FLY"];
createVehicleCrew _heli;
_heli allowDamage false;
(group driver _heli) setBehaviour "CARELESS";
(group driver _heli) setCombatMode "BLUE";
_heli flyInHeight 250;
private _wp = (group driver _heli) addWaypoint [_radar getPos [5000, 300], 0];
_wp setWaypointType "LOITER";
_wp setWaypointLoiterRadius 800;
_t0 = time;
waitUntil {sleep 1; ((missionNamespace getVariable ["PTF_GATOR_picture", [0, [], [], []]]) select 3) isNotEqualTo [] || {time - _t0 > 40}};
private _air = (missionNamespace getVariable ["PTF_GATOR_picture", [0, [], [], []]]) select 3;
["air track on the network", count _air >= 1 && {(_air select 0) select 0 == netId _heli},
	format ["%1 after %2 s", _air, round (time - _t0)]] call _check;

// The tablet: the map with both layers, the Layers panel, the Tracks list.
_camera cameraEffect ["terminate", "back"];
camDestroy _camera;
player switchCamera "INTERNAL";
sleep 1;
["auto"] call blk_fnc_tabletToggle;
sleep 5;
["billet.go('map')"] call blk_fnc_tabletExec;
sleep 4;
private _map = (findDisplay 8890) displayCtrl 200;
// Both ends in view: the G/ATOR and the firing point it traced.
private _point = _first getOrDefault ["point", [0, 0]];
private _middle = ((getPosASL _radar) vectorAdd [_point select 0, _point select 1, 0]) vectorMultiply 0.5;
_map ctrlMapAnimAdd [0, 0.16, _middle];
ctrlMapAnimCommit _map;
sleep 2;
[format ["send('native:trackat:%1,%2')", round (_middle select 0), round (_middle select 1)]] call blk_fnc_tabletExec;
sleep 3;
private _draw = uiNamespace getVariable ["BLK_tabLayerDraw", []];
["tablet draws the layer", count _draw > 5, format ["%1 shapes, layers %2", count _draw, uiNamespace getVariable ["BLK_tabLayerList", []]]] call _check;
diag_log "GATORTEST SNAP cb_tablet_map";
sleep 3;
// Close on the firing point: its ring of likely miss, the diamond and the label (zoomed in,
// then centred the way Billet centres, clear of the panels over the map).
_map ctrlMapAnimAdd [0, 0.012, [_point select 0, _point select 1, 0]];
ctrlMapAnimCommit _map;
sleep 2;
[format ["send('native:trackat:%1,%2')", round (_point select 0), round (_point select 1)]] call blk_fnc_tabletExec;
sleep 2.5;
diag_log "GATORTEST SNAP cb_tablet_point";
sleep 3;
_map ctrlMapAnimAdd [0, 0.16, _middle];
ctrlMapAnimCommit _map;
sleep 2;
sleep 2;
["mk.tool='layers';renderTools()"] call blk_fnc_tabletExec;
sleep 2;
diag_log "GATORTEST SNAP cb_tablet_layers";
sleep 3;
sleep 1;
private _shapesOn = count (uiNamespace getVariable ["BLK_tabLayerDraw", []]);
["document.querySelector('[data-alayer=ptf_counterbattery]').click()"] call blk_fnc_tabletExec;
sleep 2.5;
// the air layer stays on, so only the counter-battery shapes go
private _shapesOff = count (uiNamespace getVariable ["BLK_tabLayerDraw", []]);
["layer switches off", _shapesOff < _shapesOn && {(profileNamespace getVariable ["blk_tab_addonLayers", ""]) find "ptf_counterbattery:0" >= 0},
	format ["shapes %1 -> %2, saved %3", _shapesOn, _shapesOff, profileNamespace getVariable ["blk_tab_addonLayers", ""]]] call _check;
diag_log "GATORTEST SNAP cb_tablet_off";
sleep 3;
sleep 1;
["document.querySelector('[data-alayer=ptf_counterbattery]').click()"] call blk_fnc_tabletExec;
sleep 2;
["mk.tool=null;renderTools();document.querySelector('[data-sidetab=tracks]').click()"] call blk_fnc_tabletExec;
sleep 3;
diag_log "GATORTEST SNAP cb_tablet_tracks";
sleep 3;
// A click on a track's row centres the map on it.
_map ctrlMapAnimAdd [0, 0.045, getPosASL _radar];
ctrlMapAnimCommit _map;
sleep 2;
["Array.from(document.querySelectorAll('[data-trackat]')).find((e) => e.textContent.includes('CB01')).click()"] call blk_fnc_tabletExec;
sleep 2.5;
// Billet rings the spot it centred on
private _ping = (uiNamespace getVariable ["BLK_tabPing", [[0, 0], 0, 0]]) select 0;
["a track's row centres the map on it", (_ping distance2D (_first getOrDefault ["point", [0, 0]])) < 5,
	format ["centred %1 m from the firing point", round (_ping distance2D (_first getOrDefault ["point", [0, 0]]))]] call _check;
diag_log "GATORTEST SNAP cb_tablet_trackclick";
sleep 3;
["auto"] call blk_fnc_tabletToggle;
sleep 2;

// From beyond 10 km: rockets from an MLRS 11 km off give a bearing only.
(["B_MBT_01_mlrs_F", "12Rnd_230mm_rockets", 11000, 200, [250, 20]] call _battery) params ["_gun", "_aimG", "_magG"];
["far gun can reach", _aimG inRangeOfArtillery [[_gun], _magG], format ["%1 m off", round (_gun distance2D _radar)]] call _check;
[_gun, _aimG, _magG, 2] call _fire;
_t0 = time;
waitUntil {sleep 1; {(_x get "kind") == "bearing"} count (call _tracks) > 0 || {time - _t0 > 150}};
sleep 2;
private _far = (call _tracks) select {(_x get "kind") == "bearing"};
private _trueBearing = _radar getDir _gun;
private _seenBearing = (_far param [0, createHashMap]) getOrDefault ["bearing", -1];
["beyond 10 km: a bearing, no point", count _far == 1 && {abs ((_seenBearing - _trueBearing + 540) % 360 - 180) < 3},
	format ["%1 bearing tracks, bearing %2 (true %3), after %4 s", count _far, round _seenBearing, round _trueBearing, round (time - _t0)]] call _check;

// Rounds that never come near: nothing.
(["O_Mortar_01_F", "8Rnd_82mm_Mo_shells", 5200, 300, [4800, 300]] call _battery) params ["_away", "_aimA", "_magA"];
private _before = count (call _tracks);
[_away, _aimA, _magA, 2] call _fire;
sleep 45;
["rounds passing far off go unseen", count (call _tracks) == _before, format ["tracks %1 -> %2", _before, count (call _tracks)]] call _check;

// EMCON: silent, it sees nothing.
_radar setVariable ["PTF_GATOR_emcon", true, true];
sleep 2.5;
private _rounds = _first getOrDefault ["rounds", 0];
[_mortar, _aimM, _magM, 2] call _fire;
sleep 45;
["silent, it traces nothing", (_first getOrDefault ["rounds", 0]) == _rounds && {(missionNamespace getVariable ["PTF_GATOR_cbRadars", []]) isEqualTo []},
	format ["rounds %1 -> %2", _rounds, _first getOrDefault ["rounds", 0]]] call _check;
_radar setVariable ["PTF_GATOR_emcon", false, true];

// Stowed: off the network, tracks kept at the trailer.
[_radar, "stow"] call PTF_GATOR_fnc_satcom;
sleep 2;
_pic = missionNamespace getVariable ["PTF_GATOR_picture", [0, [], [], []]];
["stowed: off the network", (_pic select 1) isEqualTo [] && {(_pic select 2) isEqualTo []} && {ropes _radar isEqualTo []} && {count (_radar getVariable ["PTF_GATOR_cbOwn", []]) >= 1},
	format ["picture %1, own %2", _pic, count (_radar getVariable ["PTF_GATOR_cbOwn", []])]] call _check;
// Carried off, the antenna pulls its cable out.
_satcom = call _setDown;
_satcom setPosATL ((_radar modelToWorld [-60, 0, 0]) vectorMultiply [1, 1, 0]);
sleep 3;
["cable comes out when the antenna is carried off", isNull (_radar getVariable ["PTF_GATOR_satcom", objNull])] call _check;
diag_log "GATORTEST DONE";
