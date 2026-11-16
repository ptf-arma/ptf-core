// ACE refuel by hand, as a player does it, again and again on one trailer: take the nozzle,
// look at the trailer within 2 m, left-click (ace_refuel_fnc_onMouseButtonDown), the tank fills,
// Disconnect (the nozzle back in hand).
//   python tools/gator/test/run.py --no-build --data <ptf_gator_data.pbo> --mission tools/gator/test/refuel.Stratis
// 1. A fuel truck's nozzle twice, generator off, then the nozzle put back on the truck.
// 2. Legs down, generator running, array up and turning (its hidden radar attached): a jerrycan,
//    then a second jerrycan after the first is unplugged and set down.
// 3. An empty jerrycan left plugged in: does it block the next one (ACE allows one nozzle per
//    vehicle), and does the next one go in once it is unplugged.
private _check = {
	params ["_name", "_ok", ["_detail", ""]];
	diag_log format ["GATORTEST %1 %2 %3", ["FAIL", "PASS"] select _ok, _name, _detail];
};
diag_log "GATORTEST start";
waitUntil {time > 0};
waitUntil {!isNil "ace_common_settingsInitFinished" && {ace_common_settingsInitFinished}};
setDate [2035, 7, 18, 11, 0];
0 setOvercast 0.1;
0 setFog 0;
forceWeatherChange;
showCinemaBorder false;
player switchCamera "INTERNAL";

private _spot = [[1950, 5750, 0], 0, 600, 20, 0, 0.06, 0] call BIS_fnc_findSafePos;
_spot set [2, 0];
private _radar = createVehicle ["PTF_GATOR", _spot, [], 0, "CAN_COLLIDE"];
_radar setDir 0;
_radar setPosATL _spot;
sleep 4;
["ace refuel on", missionNamespace getVariable ["ace_refuel_enabled", false]] call _check;

private _held = {player getVariable ["ace_refuel_nozzle", objNull]};
// Take a nozzle from a truck or pick up a jerrycan: what's in hand after.
private _take = {
	params ["_from"];
	player setPosATL ((_from getRelPos [1.5, (_from getRelDir player)]) vectorMultiply [1, 1, 0]);
	player setDir (player getDir _from);
	sleep 0.5;
	[player, _from] call ace_refuel_fnc_takeNozzle;
	private _t = time;
	waitUntil {sleep 0.5; !isNull call _held || {time - _t > 15}};
	sleep 0.5;
	call _held
};
// Stand 1.3 m out from the generator side, facing it, and left-click. True once plugged in.
private _plug = {
	params ["_name", "_nozzle"];
	private _hook = _radar modelToWorld [-1.3, 1.0, 1.25];
	private _stand = _radar getRelPos [(_radar distance2D _hook) + 1.3, _radar getRelDir _hook];
	player setPosATL [_stand select 0, _stand select 1, 0];
	player setDir (player getDir _hook);
	sleep 1.5;
	getCursorObjectParams params ["_obj", "", "_d"];
	diag_log format ["GATORTEST %1: cursor on %2 at %3 m, holding %4, trailer's nozzle %5", _name, typeOf _obj, _d toFixed 2,
		typeOf _nozzle, _radar getVariable ["ace_refuel_nozzle", objNull]];
	[displayNull, 0] call ace_refuel_fnc_onMouseButtonDown;
	private _t = time;
	waitUntil {sleep 0.5; (_nozzle getVariable ["ace_refuel_isConnected", false]) || {time - _t > 12}};
	_nozzle getVariable ["ace_refuel_isConnected", false]
};
// Wait for a full tank (or the pump to stop): the fuel readings on the way.
private _fill = {
	params ["_nozzle"];
	private _t = time;
	private _log = [(fuel _radar) toFixed 2];
	sleep 2;
	waitUntil {sleep 2; _log pushBack ((fuel _radar) toFixed 2);
		fuel _radar > 0.99 || {!(_nozzle getVariable ["ace_refuel_isRefueling", false])} || {time - _t > 50}};
	_log
};
// The player's Disconnect: the nozzle (or can) back in his hands.
private _unplug = {
	params ["_nozzle"];
	[player, _nozzle] call ace_refuel_fnc_disconnect;
	private _t = time;
	waitUntil {sleep 0.5; (call _held) isEqualTo _nozzle || {time - _t > 12}};
	sleep 0.5;
	(call _held) isEqualTo _nozzle && {isNull (_radar getVariable ["ace_refuel_nozzle", objNull])}
};

// 1. Fuel truck, twice.
_radar setFuel 0.1;
private _truck = createVehicle ["B_Truck_01_fuel_F", _radar modelToWorld [-9, 6, 0], [], 0, "NONE"];
_truck setDir 0;
sleep 2;
private _nozzle = [_truck] call _take;
["truck: nozzle in hand", !isNull _nozzle] call _check;
["truck 1st: plugged in", ["truck 1st", _nozzle] call _plug] call _check;
diag_log "GATORTEST SNAP rf_truck_filling";
private _log = [_nozzle] call _fill;
["truck 1st: tank filled", fuel _radar > 0.99, str _log] call _check;
["truck 1st: unplugged, nozzle back in hand", [_nozzle] call _unplug] call _check;
_radar setFuel 0.4;
["truck 2nd: plugged in again", ["truck 2nd", _nozzle] call _plug] call _check;
_log = [_nozzle] call _fill;
["truck 2nd: tank filled", fuel _radar > 0.99, str _log] call _check;
["truck 2nd: unplugged", [_nozzle] call _unplug] call _check;
player setPosATL ((_truck getRelPos [3, (_truck getRelDir player)]) vectorMultiply [1, 1, 0]);
player setDir (player getDir _truck);
sleep 1;
[player, _truck] call ace_refuel_fnc_returnNozzle;
private _t = time;
waitUntil {sleep 0.5; isNull call _held || {time - _t > 12}};
["truck: nozzle put back", isNull call _held && {isNull _nozzle}] call _check;
deleteVehicle _truck;
sleep 2;

// 2. Set up and running: one jerrycan, then a second.
{[_radar, _x, true, true] call PTF_GATOR_fnc_setLeg} forEach ["fl", "fr", "rl", "rr"];
[_radar, true, true] call PTF_GATOR_fnc_setPower;
sleep 1;
[_radar, true, true] call PTF_GATOR_fnc_setDeployed;
sleep 1;
[_radar, true] call PTF_GATOR_fnc_setSpinning;
sleep 6;
private _cans = [];
for "_i" from 0 to 3 do {
	_cans pushBack createVehicle ["Land_CanisterFuel_F", _radar modelToWorld [-5, 3 + 2 * _i, 0], [], 0, "CAN_COLLIDE"];
};
sleep 2;
["jerrycans are fuel sources", _cans findIf {!(_x getVariable ["ace_refuel_jerryCan", false])} < 0] call _check;
private _down = {
	params ["_can"];
	[player, _can] call ace_refuel_fnc_dropNozzle;
	sleep 1;
	isNull call _held
};
{
	_x params ["_name", "_can", "_from"];
	_radar setFuel _from;
	private _got = [_can] call _take;
	[format ["%1: can in hand", _name], _got isEqualTo _can] call _check;
	[format ["%1: plugged in", _name], [_name, _can] call _plug] call _check;
	diag_log format ["GATORTEST SNAP rf_%1", _name select [0, 5]];
	private _log = [_can] call _fill;
	[format ["%1: tank filled", _name], fuel _radar > 0.99, str _log] call _check;
	[format ["%1: unplugged and set down", _name], ([_can] call _unplug) && {[_can] call _down}] call _check;
} forEach [["can 1st", _cans select 0, 0.3], ["can 2nd", _cans select 1, 0.3]];
["generator still running", [_radar] call PTF_GATOR_fnc_powerState == "on", [_radar] call PTF_GATOR_fnc_powerState] call _check;

// 3. An empty can left plugged in.
_radar setFuel 0.2;
[_cans select 2, 1] call ace_refuel_fnc_setFuel;
private _got = [_cans select 2] call _take;
["empty can: plugged in", ["empty can", _got] call _plug] call _check;
sleep 6;
["empty can: ran dry, still plugged in", ([_cans select 2] call ace_refuel_fnc_getFuel) == 0 && {(_radar getVariable ["ace_refuel_nozzle", objNull]) isEqualTo (_cans select 2)},
	format ["can %1 L, trailer's nozzle %2", [_cans select 2] call ace_refuel_fnc_getFuel, _radar getVariable ["ace_refuel_nozzle", objNull]]] call _check;
_got = [_cans select 3] call _take;
private _blocked = !(["next can, empty one still in", _got] call _plug);
["the empty can blocks the next one (ACE: one nozzle at a time)", _blocked] call _check;
// unplug the empty one: hands must be free for Disconnect, so the full can goes down first
[_got] call _down;
private _out = [_cans select 2] call _unplug;
[_cans select 2] call _down;
["empty can unplugged", _out] call _check;
_got = [_cans select 3] call _take;
["next can: plugged in once the empty one is out", ["next can", _got] call _plug] call _check;
_log = [_got] call _fill;
["next can: tank filled", fuel _radar > 0.99, str _log] call _check;
diag_log "GATORTEST DONE";
