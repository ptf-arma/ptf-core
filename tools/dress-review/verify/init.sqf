// Checks what screenshots of a worn uniform cannot: that every config path resolves, and
// what the uniform and cap look like lying on the ground.
// Run with: python tools/review-dress-uniforms.py --script verify --ranks <all ranks> --cap
#include "review_list.sqf"

diag_log "DRESSREVIEW start";
waitUntil {time > 0};
disableUserInput true; // mouse movement otherwise turns the player while the game has focus
setDate [2035, 6, 15, 9, 0];
0 setOvercast 0.1;
forceWeatherChange;
showHUD [false, false, false, false, false, false, false, false, false, false];
showCinemaBorder false;
enableEnvironment false;
enableRadio false;
clearRadio;

private _bad = 0;
private _check = {
    params ["_label", "_path"];
    if (_path != "" && {!fileExists _path}) then {
        _bad = _bad + 1;
        diag_log format ["DRESSREVIEW MISSING %1 %2", _label, _path];
    };
};
{
    _x params ["_rank", "_uniform"];
    private _item = configFile >> "CfgWeapons" >> _uniform;
    private _unit = getText (_item >> "ItemInfo" >> "uniformClass");
    private _veh = configFile >> "CfgVehicles" >> _unit;
    [_rank + " picture", getText (_item >> "picture")] call _check;
    {[_rank + " texture", _x] call _check} forEach getArray (_veh >> "hiddenSelectionsTextures");
    {[_rank + " material", _x] call _check} forEach getArray (_veh >> "hiddenSelectionsMaterials");
    {[_rank + " suitpack", _x] call _check} forEach getArray (_item >> "hiddenSelectionsTextures");
    diag_log format ["DRESSREVIEW rank %1 name=%2 unit=%3 scope=%4", _rank, getText (_item >> "displayName"), _unit, getNumber (_veh >> "scope")];
} forEach dress_subjects;
{
    private _cap = configFile >> "CfgWeapons" >> _x;
    [_x + " picture", getText (_cap >> "picture")] call _check;
    {[_x + " texture", _x] call _check} forEach getArray (_cap >> "hiddenSelectionsTextures");
} forEach ["PTF_Headgear_Dress_USMC_Cover", "PTF_Headgear_Dress_USMC_Cover_Officer", "PTF_Headgear_Dress_USMC_Cover_Field"];
diag_log format ["DRESSREVIEW paths missing=%1 ranks=%2", _bad, count dress_subjects];

// On the ground, in the open.
private _start = getPosATL player;
_start set [2, 0];
player setPosATL (_start vectorAdd [40, 40, 0]);
private _holder = createVehicle ["GroundWeaponHolder", _start, [], 0, "CAN_COLLIDE"];
_holder addItemCargoGlobal ["PTF_Uniform_Dress_USMC_A_Sgt", 1];
private _capHolder = createVehicle ["GroundWeaponHolder", _start vectorAdd [0.8, 0, 0], [], 0, "CAN_COLLIDE"];
_capHolder addItemCargoGlobal ["PTF_Headgear_Dress_USMC_Cover_Field", 1];
sleep 2;
private _cam = "camera" camCreate _start;
_cam cameraEffect ["internal", "back"];
_cam camSetPos (_start vectorAdd [0.4, 1.3, 0.8]);
_cam camSetTarget (_start vectorAdd [0.4, 0, 0.05]);
_cam camSetFov 0.45;
_cam camCommit 0;
sleep 4;
screenshot "dressreview_ground.png";
sleep 1;

diag_log "DRESSREVIEW done";
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;
disableUserInput false;
endMission "END1";
