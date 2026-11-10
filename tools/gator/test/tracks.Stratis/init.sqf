// Short test of the SATCOM antenna, in-flight tracing, erasing and the tablet's G/ATOR symbol:
//   python tools/gator/test/run.py --mission tools/gator/test/tracks.Stratis --full --extra <billet>/mod/.hemttout/build/addons
// (counterbattery.Altis is the long one: error and averaging, bearings, EMCON, air.)
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
showCinemaBorder false;

private _spot = [[1950, 5750, 0], 0, 600, 15, 0, 0.06, 0] call BIS_fnc_findSafePos;
_spot set [2, 0];
private _radar = createVehicle ["PTF_GATOR", _spot, [], 0, "CAN_COLLIDE"];
_radar setDir 0;
_radar setPosATL _spot;
player setPosATL (_radar modelToWorld [-3, 0, 0]);
player setDir 270;
player addItem "blk_tabletItem";
sleep 6;
{[_radar, _x, true, true] call PTF_GATOR_fnc_setLeg} forEach ["fl", "fr", "rl", "rr"];
[_radar, true, true] call PTF_GATOR_fnc_setPower;
sleep 1;
[_radar, true, true] call PTF_GATOR_fnc_setDeployed;
sleep 1;
[_radar, true] call PTF_GATOR_fnc_setSpinning;

// The antenna: out into the player's hands, on its cable; not on the network while held.
[_radar, "out", player] call PTF_GATOR_fnc_satcom;
sleep 3;
private _antenna = _radar getVariable ["PTF_GATOR_antenna", objNull];
["antenna out, dragged, cabled", !isNull _antenna && {attachedTo _antenna isEqualTo player} && {ropes _radar isNotEqualTo []}
	&& {isNull (_radar getVariable ["PTF_GATOR_satcom", objNull])},
	format ["antenna %1 attached to %2, ropes %3", typeOf _antenna, attachedTo _antenna, ropes _radar]] call _check;
// Set down 2 m off: interference.
[player, _antenna] call ace_dragging_fnc_dropObject;
sleep 0.5;
_antenna setPosATL (_radar modelToWorld [-2, 0, 0]);
sleep 2.5;
["too close: interference, not on the network", isNull (_radar getVariable ["PTF_GATOR_satcom", objNull]) && {_antenna getVariable ["PTF_GATOR_warned", false]},
	format ["%1 m off, warned %2", (_antenna distance2D _radar) toFixed 1, _antenna getVariable "PTF_GATOR_warned"]] call _check;
diag_log "GATORTEST SNAP tr_interference";
sleep 3;
// Moved out to 15 m: on the network.
_antenna setPosATL (_radar modelToWorld [-15, 3, 0]);
sleep 2.5;
["set down clear: on the network", (_radar getVariable ["PTF_GATOR_satcom", objNull]) isEqualTo _antenna && {ropes _radar isNotEqualTo []}] call _check;

// A mortar 2 km off: traced while its rounds are still in the air.
private _at = [];
for "_b" from 60 to 420 step 15 do {
	private _try = [_radar getPos [2000, _b], 0, 200, 8, 0, 0.3, 0, [], [[0, 0, 0], [0, 0, 0]]] call BIS_fnc_findSafePos;
	if (_try isNotEqualTo [0, 0, 0] && {abs ((_try distance2D _radar) - 2000) < 300}) exitWith {_at = _try};
};
private _mortar = createVehicle ["O_Mortar_01_F", [_at select 0, _at select 1, 0], [], 0, "NONE"];
createVehicleCrew _mortar;
_mortar allowDamage false;
sleep 8;
// the incoming alarm on: it should sound while the rounds are up, and stop once they're down
_radar setVariable ["PTF_GATOR_alarm", true, true];
(gunner _mortar) doArtilleryFire [_radar getPos [300, 200], "8Rnd_82mm_Mo_shells", 2];
private _t0 = time;
waitUntil {sleep 0.1; (_radar getVariable ["PTF_GATOR_cbTracks", []]) isNotEqualTo [] || {time - _t0 > 90}};
sleep 1;
["incoming alarm sounds", "alarm" in (_radar getVariable ["PTF_GATOR_soundStreams", createHashMap]),
	format ["alarm until %1, now %2", _radar getVariable ["PTF_GATOR_alarmUntil", -1], CBA_missionTime]] call _check;
private _track = (_radar getVariable ["PTF_GATOR_cbTracks", []]) param [0, createHashMap];
private _inAir = count (missionNamespace getVariable ["PTF_GATOR_cbFlights", []]);
["traced in the air", _track isNotEqualTo createHashMap && {_inAir > 0} && {(_track getOrDefault ["impacts", [0]]) isEqualTo []},
	format ["after %1 s: rounds in the air %2, impacts so far %3, weapon %4", round (time - _t0), _inAir, _track getOrDefault ["impacts", -1], _track getOrDefault ["weapon", ""]]] call _check;
waitUntil {sleep 0.5; (count (_track getOrDefault ["impacts", []]) >= (_track getOrDefault ["rounds", 9])) || {time - _t0 > 120}};
["then where they landed", count (_track getOrDefault ["impacts", []]) >= 1 && {count (_track getOrDefault ["impacts", []]) == (_track getOrDefault ["rounds", 0])},
	format ["rounds %1, impacts %2", _track getOrDefault ["rounds", 0], count (_track getOrDefault ["impacts", []])]] call _check;
sleep 6;
["alarm stops once they're down", !("alarm" in (_radar getVariable ["PTF_GATOR_soundStreams", createHashMap]))] call _check;

// The tablet: the G/ATOR's symbol and turning arc, the tracks with their Erase buttons.
["auto"] call blk_fnc_tabletToggle;
sleep 5;
["billet.go('map')"] call blk_fnc_tabletExec;
sleep 3;
private _map = (findDisplay 8890) displayCtrl 200;
_map ctrlMapAnimAdd [0, 0.06, getPosASL _radar];
ctrlMapAnimCommit _map;
sleep 2;
[format ["send('native:trackat:%1,%2')", round ((getPosASL _radar) select 0), round ((getPosASL _radar) select 1)]] call blk_fnc_tabletExec;
sleep 2.5;
diag_log "GATORTEST SNAP tr_arc_a";
sleep 1.5;
diag_log "GATORTEST SNAP tr_arc_b";
sleep 3;
["document.querySelector('[data-sidetab=tracks]').click()"] call blk_fnc_tabletExec;
sleep 2.5;
diag_log "GATORTEST SNAP tr_tracks";
sleep 3;
["Array.from(document.querySelectorAll('[data-trackact]')).find((e) => e.textContent === 'Erase').click()"] call blk_fnc_tabletExec;
sleep 3;
["erased from the tablet", (_radar getVariable ["PTF_GATOR_cbTracks", []]) isEqualTo [], str count (_radar getVariable ["PTF_GATOR_cbTracks", []])] call _check;
diag_log "GATORTEST SNAP tr_erased";
sleep 3;
["auto"] call blk_fnc_tabletToggle;
diag_log "GATORTEST DONE";
