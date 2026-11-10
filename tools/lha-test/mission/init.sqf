// In-game test of PTF_LHA. Run with: python tools/lha-test/run.py
// Logs one "LHATEST PASS|FAIL <check> <detail>" line per check.

private _check = {
	params ["_name", "_ok", ["_detail", ""]];
	diag_log format ["LHATEST %1 %2 %3", ["FAIL", "PASS"] select _ok, _name, _detail];
};
private _shot = {
	params ["_name"];
	sleep 1.5;
	screenshot format ["lhatest_%1.png", _name];
	sleep 1.5;
};

diag_log "LHATEST start";
waitUntil {time > 0};
disableUserInput true;
setDate [2035, 6, 15, 23, 30];
0 setOvercast 0;
forceWeatherChange;
showCinemaBorder false;
enableEnvironment false;
enableRadio false;

// ---------- config ----------
private _cfg = configFile >> "CfgVehicles" >> "Peral_LHA";
["addon loaded", isClass (configFile >> "CfgPatches" >> "PTF_LHA")] call _check;
{
	_x params ["_list", "_count"];
	private _classes = getArray (_cfg >> _list);
	private _bad = _classes select {getNumber (configFile >> "CfgVehicles" >> _x >> "scope") != 2};
	[format ["%1 list", _list], count _classes == _count && {_bad isEqualTo []}, format ["%1 classes, missing or hidden: %2", count _classes, _bad]] call _check;
} forEach [["Aircraft", 23], ["Amphibious", 7]];
["Peral's config kept", getText (_cfg >> "model") != "" && {count getArray (_cfg >> "Boats") == 4}
	&& {"Carrier01Init" in getText (_cfg >> "EventHandlers" >> "init")} && {isClass (_cfg >> "Attributes" >> "LHA_Number")},
	getText (_cfg >> "EventHandlers" >> "init")] call _check;
private _act = configFile >> "CfgVehicles" >> "LHA_house_2" >> "UserActions" >> "mh_lights_on";
["light action merged", getText (_act >> "displayName") == "Turn On Main Hallway Lights"
	&& {getText (_act >> "position") == "mh_lights_action"} && {"animationPhase" in getText (_act >> "condition")}
	&& {isClass (configFile >> "CfgVehicles" >> "LHA_house_2" >> "UserActions" >> "door_01_open")},
	getText (_act >> "statement")] call _check;
private _grey = configFile >> "CfgVehicles" >> "PTF_Spawner" >> "ACE_Actions" >> "ACE_MainActions" >> "PTF_Boat" >> "boat" >> "PTF_RHICC_GRAY";
private _greyStatement = getText (_grey >> "statement");
["RHICC grey boat spawner", "RHICC_GREY" in _greyStatement && {isClass (configFile >> "CfgVehicles" >> "RHICC_GREY")}, _greyStatement] call _check;

// ---------- the ship ----------
private _lha = createVehicle ["Peral_LHA", [400, 400, 0], [], 0, "CAN_COLLIDE"];
// Level, as Eden places it: a script-spawned ship takes the seabed's slope.
_lha setVectorDirAndUp [[0, 1, 0], [0, 0, 1]];
_lha setPosASL [400, 400, 0];
private _t = time;
waitUntil {count (_lha getVariable ["bis_carrierparts", []]) >= 8 || time - _t > 60};
[_lha] call BIS_fnc_Carrier01PosUpdate;
sleep 6;
private _parts = (_lha getVariable ["bis_carrierparts", []]) apply {_x select 0};
private _part = {params ["_class"]; (_parts select {typeOf _x == _class}) param [0, objNull]};
private _h1 = ["LHA_house_1"] call _part;
private _h2 = ["LHA_house_2"] call _part;
private _med3 = ["LHA_Med_3"] call _part;
["ship parts", count _parts >= 8 && {!isNull _h2}, str (_parts apply {typeOf _x})] call _check;

private _tex = getObjectTextures _lha;
["hull number 8", "num_8" in toLower (_tex select 2), _tex select 2] call _check;
["PTF unit flag", "ptfflag" in toLower (_tex select 4), _tex select 4] call _check;

// ---------- turrets ----------
private _turrets = [];
{_turrets append (_x getVariable ["LHA_Ship_Components", []])} forEach _parts;
_turrets = _turrets select {_x isKindOf "StaticWeapon" || {_x isKindOf "LandVehicle"}};
private _crewed = _turrets select {(crew _x) findIf {alive _x} >= 0};
["turrets uncrewed", count _turrets == 9 && {_crewed isEqualTo []},
	format ["%1 turrets %2, crewed %3", count _turrets, _turrets apply {typeOf _x}, _crewed apply {typeOf _x}]] call _check;

// ---------- deck services ----------
private _deckObjs = _lha getVariable ["PTF_LHA_deckObjects", []];
private _pads = _deckObjs select {typeOf _x == "Land_HelipadEmpty_F"};
private _hoses = _deckObjs select {typeOf _x == "Land_RefuelingHose_01_F"};
private _boxes = _deckObjs select {typeOf _x == "Box_NATO_AmmoVeh_F"};
["AI helipads", count _pads == 6 && {(_pads findIf {isNull attachedTo _x}) < 0}, format ["%1 pads", count _pads]] call _check;
["fuel points", count _hoses == 3 && {(_hoses findIf {(_x getVariable ["ace_refuel_capacity", 0]) != -10}) < 0},
	format ["%1 hoses, capacity %2", count _hoses, _hoses apply {_x getVariable ["ace_refuel_capacity", "nil"]}]] call _check;
["ammo points", count _boxes == 3 && {(_boxes findIf {(_x getVariable ["ace_rearm_currentSupply", 0]) < 1e5}) < 0},
	format ["%1 boxes, supply %2", count _boxes, _boxes apply {_x getVariable ["ace_rearm_currentSupply", "nil"]}]] call _check;
// Each prop's bottom should be at flight deck height. Ray tests can't check this:
// near the deck edge the deck is walkable surface only, which rays don't see. In
// the parts' own frames the deck is at z 13.0 (measured at Peral's spawn points).
private _heights = (_hoses + _boxes) apply {
	private _on = attachedTo _x;
	private _bottom = _on worldToModel (_x modelToWorld [0, 0, ((boundingBoxReal _x) select 0) select 2]);
	[typeOf _x, typeOf _on, (_bottom select 2) - 13.0]
};
["props on the deck", (_heights findIf {abs (_x select 2) > 0.15}) < 0, str _heights] call _check;

private _dcam = "camera" camCreate [0, 0, 50];
_dcam cameraEffect ["internal", "back"];
{
	private _at = getPosASL _x;
	private _side = [-1, 1] select (((_lha worldToModel ASLToAGL _at) select 0) > 0);
	private _out = _at vectorAdd ((_lha vectorModelToWorld [_side, 0, 0]) vectorMultiply 10);
	_dcam camSetPos ASLToAGL (_out vectorAdd [0, -4, 5]);
	_dcam camSetTarget ASLToAGL _at;
	_dcam camSetFov 0.7;
	_dcam camCommit 0;
	[format ["fuel_point_%1", _forEachIndex + 1]] call _shot;
} forEach _hoses;
_dcam cameraEffect ["terminate", "back"];
camDestroy _dcam;

// Repair facility: the hangar yes, the flight deck no.
private _light = _med3 modelToWorldWorld (_med3 selectionPosition "l1_light_15");
private _floor = (lineIntersectsSurfaces [_light vectorAdd [0, 0, -0.5], _light vectorAdd [0, 0, -15], objNull, objNull, true, 1]) param [0, []];
player setPosASL ((_floor param [0, _light]) vectorAdd [0, 0, 0.1]);
sleep 2;
private _inHangar = [player] call ace_repair_fnc_isInRepairFacility;
player setPosASL (_lha modelToWorldWorld ((_lha selectionPosition "ac_spawnpoint_3") vectorAdd [0, 0, 0.2]));
sleep 3;
private _onDeck = [player] call ace_repair_fnc_isInRepairFacility;
["hangar is a repair facility", _inHangar && {!_onDeck}, format ["hangar %1, flight deck %2, %3 markers", _inHangar, _onDeck, count (_lha getVariable ["PTF_LHA_repairMarkers", []])]] call _check;

// ---------- 1MC ----------
private _helper = _lha getVariable ["PTF_LHA_1mcHelper", objNull];
// ACE keeps object actions as a flat list of [action, parent path].
private _acts = _helper getVariable ["ace_interact_menu_actions", []];
private _rootActs = _acts select {(_x select 1) isEqualTo [] && {((_x select 0) select 0) == "PTF_LHA_1MC"}};
private _children = _acts select {(_x select 1) isEqualTo ["PTF_LHA_1MC"]};
["1MC panel", !isNull _helper && {count _rootActs == 1} && {count _children == 10},
	format ["helper %1, root %2, announcements %3", typeOf _helper, count _rootActs, _children apply {(_x select 0) select 1}]] call _check;
[_lha, "1mc_general_quarters"] call PTF_LHA_fnc_announce;
private _until = _lha getVariable ["PTF_LHA_1mcUntil", -1];
[_lha, "1mc_taps"] call PTF_LHA_fnc_announce;
["1MC one at a time", _until > serverTime + 5 && {(_lha getVariable ["PTF_LHA_1mcUntil", -1]) == _until},
	format ["busy for %1 s", _until - serverTime]] call _check;
[_lha, "not_a_sound"] call PTF_LHA_fnc_announce;

// Stand at the panel and open the ACE menu on it.
private _hp = getPosASL _helper;
private _stand = [];
for "_a" from 0 to 345 step 15 do {
	private _p = _hp vectorAdd [1.1 * sin _a, 1.1 * cos _a, 0];
	private _floorHit = (lineIntersectsSurfaces [_p, _p vectorAdd [0, 0, -2.5], objNull, objNull, true, 1]) param [0, []];
	if (_floorHit isNotEqualTo [] && {(lineIntersectsSurfaces [_hp, _p, objNull, objNull, true, 1]) isEqualTo []}) exitWith {_stand = _floorHit select 0};
};
if (_stand isNotEqualTo []) then {
	player setPosASL _stand;
	player setDir (player getDir _helper);
	sleep 2;
	[0] call ace_interact_menu_fnc_keyDown;
	sleep 1.5;
	// screenshot leaves out the UI, so the runner captures the game window instead.
	diag_log "LHATEST CAPTURE 1mc_menu";
	sleep 3;
	[0] call ace_interact_menu_fnc_keyUp;
};
["stand at 1MC panel", _stand isNotEqualTo [], format ["%1 m from panel", if (_stand isEqualTo []) then {-1} else {_stand distance _hp}]] call _check;

// ---------- lights ----------
// Switch state is read with animationPhase, as Peral's action conditions do:
// animationSourcePhase reads 0 on these parts even when the switch has moved.
// Camera in the hangar, between two ceiling lights, looking aft.
private _l1 = _med3 modelToWorldWorld (_med3 selectionPosition "l1_light_15");
private _l2 = _med3 modelToWorldWorld (_med3 selectionPosition "l1_light_20");
private _eye = _l1 vectorAdd [0, 0, -3];
private _cam = "camera" camCreate ASLToAGL _eye;
_cam cameraEffect ["internal", "back"];
_cam camSetTarget ASLToAGL (_l2 vectorAdd [0, 0, -3.5]);
_cam camSetFov 0.9;
_cam camCommit 0;
["hangar_off"] call _shot;

private _lights = {params ["_group"]; _lha getVariable ["PTF_LHA_lights_" + _group, []]};
[_h2, "HangerLVL1", 1] call PTF_LHA_fnc_setLights;
sleep 2;
private _mats = getObjectMaterials _med3;
["hangar lights on", count (["HangerLVL1"] call _lights) == 56 && {(_h2 animationPhase "lvl1_light_swich") == 1}
	&& {"lha_details_night" in toLower (_mats select 0)},
	format ["%1 lights, switch %2, material %3", count (["HangerLVL1"] call _lights), _h2 animationPhase "lvl1_light_swich", _mats select 0]] call _check;
["hangar_on"] call _shot;

// Island: two switches, one group. Switching on twice must not stack lights.
[_h1, "House", 1] call PTF_LHA_fnc_setLights;
sleep 2;
private _first = ["House"] call _lights;
[_h2, "House", 1] call PTF_LHA_fnc_setLights;
sleep 2;
private _second = ["House"] call _lights;
["island switches agree", (_h1 animationPhase "lvl1_lights_swich") == 1 && {(_h2 animationPhase "h_light_swich") == 1},
	format ["%1 / %2", _h1 animationPhase "lvl1_lights_swich", _h2 animationPhase "h_light_swich"]] call _check;
["no stacked lights", count _first == 54 && {count _second == 54} && {(_first select {!isNull _x}) isEqualTo []},
	format ["first %1 (left %2), second %3", count _first, count (_first select {!isNull _x}), count _second]] call _check;

[_h1, "House", 0] call PTF_LHA_fnc_setLights;
[_h2, "HangerLVL1", 0] call PTF_LHA_fnc_setLights;
sleep 2;
_mats = getObjectMaterials _med3;
["lights off", (["House"] call _lights) isEqualTo [] && {(["HangerLVL1"] call _lights) isEqualTo []}
	&& {(_second select {!isNull _x}) isEqualTo []} && {(_h2 animationPhase "h_light_swich") == 0}
	&& {!("lha_details_night" in toLower (_mats select 0))}, _mats select 0] call _check;

// Briefing room lights must leave the briefing screens' material alone.
private _screenMat = (getObjectMaterials _lha) select 0;
[_h2, "BriefingRoom", 1] call PTF_LHA_fnc_setLights;
sleep 2;
["screens untouched", ((getObjectMaterials _lha) select 0) == _screenMat && {count (["BriefingRoom"] call _lights) == 17},
	format ["%1 -> %2", _screenMat, (getObjectMaterials _lha) select 0]] call _check;
[_h2, "BriefingRoom", 0] call PTF_LHA_fnc_setLights;

_cam cameraEffect ["terminate", "back"];
camDestroy _cam;

// ---------- logistics console ----------
private _logi = configFile >> "PTF_LHA_Logistics";
private _pieces = _lha getVariable ["PTF_LHA_logisticsConsole", []];
private _screen = _pieces param [1, objNull];
_acts = _screen getVariable ["ace_interact_menu_actions", []];
private _menus = _acts select {(_x select 1) isEqualTo ["PTF_LHA_Logistics"]};
private _entries = _acts select {count (_x select 1) == 2};
private _listed = 0;
{_listed = _listed + count getArray (_x >> "classes")} forEach ("true" configClasses (_logi >> "Menus"));
["logistics console", count _pieces == 2 && {count _menus == 3} && {count _entries == _listed},
	format ["%1, menus %2, entries %3 of %4", _pieces apply {typeOf _x}, _menus apply {(_x select 0) select 1}, count _entries, _listed]] call _check;

// Stand in front of the console (it faces inboard, the ship's +x) and open the menu.
player setPosASL ((getPosASL _screen) vectorAdd ((_lha vectorModelToWorld [1.4, 0, 0])) vectorAdd [0, 0, -1.3]);
sleep 0.5;
player setPosASL [(getPosASL player) select 0, (getPosASL player) select 1, ((lineIntersectsSurfaces [getPosASL player vectorAdd [0, 0, 1], getPosASL player vectorAdd [0, 0, -2], player, objNull, true, 1]) param [0, [getPosASL player]]) select 0 select 2];
player setDir (player getDir _screen);
sleep 2;
[0] call ace_interact_menu_fnc_keyDown;
sleep 1.5;
diag_log "LHATEST CAPTURE logistics_menu";
sleep 3;
[0] call ace_interact_menu_fnc_keyUp;

// Everything listed spawns where it should and comes to rest on the floor.
private _spawned = [];
private _settle = [];
{
	private _menu = _x;
	private _area = _logi >> "Areas" >> getText (_menu >> "area");
	private _onPart = [getText (_area >> "part")] call _part;
	private _spots = getArray (_area >> "spots");
	// One of each class until the area is full, then one more, which must be refused.
	private _classes = getArray (_menu >> "classes");
	private _n = count _spots min count _classes;
	private _got = 0;
	for "_i" from 0 to _n - 1 do {
		private _o = [_lha, _classes select _i] call PTF_LHA_fnc_logisticsSpawn;
		if (!isNull _o) then {_got = _got + 1; _spawned pushBack _o; _settle pushBack [_o, _onPart, (_spots select _i) select 2]};
	};
	private _extra = [_lha, _classes select 0] call PTF_LHA_fnc_logisticsSpawn;
	[format ["%1 fills its %2 spots, then refuses", configName _menu, count _spots], _got == _n && {isNull _extra},
		format ["spawned %1 of %2, extra %3", _got, _n, typeOf _extra]] call _check;
	if (!isNull _extra) then {_spawned pushBack _extra};
} forEach ("true" configClasses (_logi >> "Menus"));
sleep 10;
private _bad = _settle select {
	_x params ["_o", "_onPart", "_floor"];
	private _bottom = _onPart worldToModel (_o modelToWorld [0, 0, ((boundingBoxReal _o) select 0) select 2]);
	!alive _o || {abs ((_bottom select 2) - _floor) > 0.25} || {((vectorUp _o) select 2) < 0.98}
};
["logistics spawns settle", count _settle == 12 && {_bad isEqualTo []},
	format ["%1 spawned, not on the floor or tilted: %2", count _settle, _bad apply {typeOf (_x select 0)}]] call _check;

private _notListed = [_lha, "B_MRAP_01_F"] call PTF_LHA_fnc_logisticsSpawn;
["only listed classes", isNull _notListed] call _check;
{deleteVehicle _x} forEach _spawned;
sleep 1;
{_x setVariable ["LHA_DisableSpawners", true]} forEach _parts;
private _disabled = [_lha, "PTF_Cargo_Small_Ammo"] call PTF_LHA_fnc_logisticsSpawn;
{_x setVariable ["LHA_DisableSpawners", nil]} forEach _parts;
private _enabled = [_lha, "PTF_Cargo_Small_Ammo"] call PTF_LHA_fnc_logisticsSpawn;
["Disable Spawners respected", isNull _disabled && {!isNull _enabled}] call _check;
deleteVehicle _enabled;

// ---------- spawner ----------
private _point = _lha selectionPosition "ac_spawnpoint_1";
["spawn point found", _point isNotEqualTo [0, 0, 0], str _point] call _check;
private _spot = _lha modelToWorld _point;
private _heli = createVehicle ["PTF_UH1Y", [0, 0, 100], [], 0, "CAN_COLLIDE"];
_heli attachTo [_lha, [0, 0, abs ((getModelInfo _heli) select 3 select 2) + 0.2], "ac_spawnpoint_1"];
sleep 0.5;
detach _heli;
createVehicleCrew _heli;
sleep 3;

player setVariable ["Peral_LHA_Obj", _lha];
createDialog "LHA_Vehicle_Spawner_Aircraft";
waitUntil {!isNull findDisplay 14600};
private _combo = (findDisplay 14600) displayCtrl 14605;
waitUntil {lbSize _combo > 0};
private _idx = -1;
for "_i" from 0 to (lbSize _combo - 1) do {if (_combo lbData _i == "PTF_MV22_Ramp") exitWith {_idx = _i}};
["spawner lists PTF aircraft", lbSize _combo == 23 && {_idx >= 0}, format ["%1 entries", lbSize _combo]] call _check;

// Someone aboard: the helicopter must stay.
[[_combo, _idx, ""], "ac", "Aircraft", 10] call LHA_fnc_lha_spawner_selectVehicle;
sleep 3;
private _mv22 = {(_spot nearObjects ["PTF_MV22_Ramp", 15]) select {alive _x}};
["crewed aircraft kept", alive _heli && {(call _mv22) isEqualTo []},
	format ["heli alive %1, crew %2, MV-22s %3", alive _heli, count crew _heli, count call _mv22]] call _check;

// Empty: Peral's script replaces it as before.
{_heli deleteVehicleCrew _x} forEach crew _heli;
sleep 1;
[[_combo, _idx, ""], "ac", "Aircraft", 10] call LHA_fnc_lha_spawner_selectVehicle;
sleep 5;
["empty aircraft replaced", isNull _heli && {count call _mv22 == 1}, format ["heli gone %1, MV-22s %2", isNull _heli, count call _mv22]] call _check;
closeDialog 0;

diag_log "LHATEST DONE";
disableUserInput false;
endMission "END1";
