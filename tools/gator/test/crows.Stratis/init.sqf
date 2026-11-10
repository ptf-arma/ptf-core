// Probe on the full modset: the Zeus modules register and the G/ATOR goes on and off CROWS's
// spectrum without script errors.
//   python tools/gator/test/run.py --mission tools/gator/test/crows.Stratis --full
private _check = {
	params ["_name", "_ok", ["_detail", ""]];
	diag_log format ["GATORTEST %1 %2 %3", ["FAIL", "PASS"] select _ok, _name, _detail];
};
diag_log "GATORTEST start";
waitUntil {time > 0};
["CROWS and ZEN loaded", isClass (configFile >> "CfgPatches" >> "crowsEW_spectrum") && {isClass (configFile >> "CfgPatches" >> "zen_custom_modules")}] call _check;
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
sleep 3;
["on CROWS's spectrum while it transmits", _radar getVariable ["PTF_GATOR_beacon", false]] call _check;
[_radar, "silent"] call PTF_GATOR_fnc_operator;
sleep 2;
["off it when silent", !(_radar getVariable ["PTF_GATOR_beacon", true])] call _check;
deleteVehicle _radar;
sleep 1;
diag_log "GATORTEST DONE";
