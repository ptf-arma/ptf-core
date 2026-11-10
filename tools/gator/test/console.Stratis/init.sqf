// Quick look at the G/ATOR operator console on Billet (screenshots only, under a minute):
//   python tools/gator/test/run.py --mission tools/gator/test/console.Stratis --extra <billet>/mod/.hemttout/build/addons
private _check = {
	params ["_name", "_ok", ["_detail", ""]];
	diag_log format ["GATORTEST %1 %2 %3", ["FAIL", "PASS"] select _ok, _name, _detail];
};
diag_log "GATORTEST start";
waitUntil {time > 0};
private _spot = [[1950, 5750, 0], 0, 600, 15, 0, 0.06, 0] call BIS_fnc_findSafePos;
_spot set [2, 0];
private _radar = createVehicle ["PTF_GATOR", _spot, [], 0, "CAN_COLLIDE"];
_radar setPosATL _spot;
player setPosATL (_radar modelToWorld [-3, 0, 0]);
sleep 3;
{[_radar, _x, true, true] call PTF_GATOR_fnc_setLeg} forEach ["fl", "fr", "rl", "rr"];
[_radar, true, true] call PTF_GATOR_fnc_setPower;
sleep 1;
[_radar, true, true] call PTF_GATOR_fnc_setDeployed;
sleep 1;
[_radar, true] call PTF_GATOR_fnc_setSpinning;
[_radar, "out", player] call PTF_GATOR_fnc_computer;
sleep 2;
private _computer = _radar getVariable ["PTF_GATOR_computer", objNull];
[player, _computer] call ace_dragging_fnc_dropObject_carry;
sleep 2;
[_radar, "manual"] call PTF_GATOR_fnc_operator;
// The laptop's actions are in its one main interaction (beside ACE's Carry), not a second point.
private _find = {
	params ["_tree", "_name"];
	private _hit = false;
	{
		if (((_x select 0) select 0) == _name || {[_x select 1, _name] call _find}) exitWith {_hit = true};
	} forEach _tree;
	_hit
};
private _store = missionNamespace getVariable ["ace_interact_menu_ActNamespace", createHashMap];
private _acts = if (_store isEqualType createHashMap) then {_store getOrDefault [typeOf _computer, []]} else {_store getVariable [typeOf _computer, []]};
private _main = (_acts select {((_x select 0) select 0) == "ACE_MainActions"}) param [0, [[], []]];
["the laptop has one interaction point", [_main select 1, "PTF_GATOR_Console"] call _find
	&& {_acts findIf {((_x select 0) select 0) == "PTF_GATOR_Console"} < 0},
	str (_acts apply {(_x select 0) select 0})] call _check;
// a firing point 3 km off, and a missile inbound, for something to show
private _at = _radar getPos [3000, 120];
private _tracks = _radar getVariable ["PTF_GATOR_cbTracks", []];
_tracks pushBack createHashMapFromArray [["id", 1], ["kind", "point"], ["sum", [_at select 0, _at select 1]], ["point", [_at select 0, _at select 1]],
	["rounds", 4], ["error", 60], ["first", CBA_missionTime], ["last", CBA_missionTime], ["impacts", []], ["ammo", "82 mm HE"], ["weapon", "mortar"]];
missionNamespace setVariable ["PTF_GATOR_cbNext", 1];
call PTF_GATOR_fnc_cbPublish;
_radar setVariable ["PTF_GATOR_splashes", [[[_at select 0, _at select 1], CBA_missionTime + 40]], true];
sleep 2;
player setPosATL (_computer modelToWorld [0, -1.2, 0]);
["ptf_gator", _computer] call blk_fnc_tabletConsole;
sleep 5;
["the console opens", !isNull findDisplay 8890] call _check;
// The console's map fitted to a place and a width (metres): its arc is 2 km at any zoom.
private _fit = {
	params ["_centre", "_across"];
	private _map = (findDisplay 8890) displayCtrl 200;
	if (isNull _map) exitWith {};
	private _s = ctrlMapScale _map;
	for "_i" from 1 to 3 do {
		[_map, _centre, _s, 0] call (uiNamespace getVariable "BLK_tabCentre");
		sleep 0.4;
		(ctrlPosition _map) params ["_x0", "_y0", "_w", "_h"];
		private _now = ((_map ctrlMapScreenToWorld [_x0 + _w, _y0 + _h / 2]) select 0) - ((_map ctrlMapScreenToWorld [_x0, _y0 + _h / 2]) select 0);
		_s = (_s * _across / (_now max 1)) min 1;
	};
	[_map, _centre, _s, 0] call (uiNamespace getVariable "BLK_tabCentre");
	sleep 1.5;
};
[getPosASL _radar, 6000] call _fit;
diag_log "GATORTEST SNAP console";
sleep 4;
[getPosASL _radar, 3000] call _fit;
diag_log "GATORTEST SNAP console_zoomed";
sleep 4;
// A friendly drone the tablet already tracks (its group is one of the tablet's own) isn't drawn
// a second time by the air layer.
private _uav = createVehicle ["B_UAV_02_dynamicLoadout_F", _radar getPos [1500, 90], [], 0, "FLY"];
createVehicleCrew _uav;
_uav flyInHeight 200;
private _t0 = time;
waitUntil {sleep 1; time - _t0 > 25 || {(_radar getVariable ["PTF_GATOR_air", []]) findIf {(_x select 0) == netId _uav} >= 0}};
sleep 2;
private _listed = (_radar getVariable ["PTF_GATOR_air", []]) findIf {(_x select 0) == netId _uav} >= 0;
private _billet = (group effectiveCommander _uav) in (uiNamespace getVariable ["BLK_tabGroups", []]) || {_uav in (uiNamespace getVariable ["BLK_tabVehs", []])};
private _drawn = (["draw"] call PTF_GATOR_fnc_airLayer) findIf {(_x select 0) == "icon"} >= 0;
["a drone the tablet already tracks isn't drawn twice", _listed && {_billet} && {!_drawn},
	format ["on the radar %1, tracked by the tablet %2, drawn by the air layer %3", _listed, _billet, _drawn]] call _check;
diag_log "GATORTEST DONE";
