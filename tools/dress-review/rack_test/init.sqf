// Feasibility test: can one uniform show a ribbon rack composed at runtime from separate
// images, with no variant classes? Draws two racks in turn into the ribbon selection.
// Run with: python tools/review-dress-uniforms.py --script rack_test --no-build --ranks Sgt
#include "review_list.sqf"

diag_log "DRESSREVIEW start";
waitUntil {time > 0};
disableUserInput true; // mouse movement otherwise turns the player while the game has focus
setDate [2035, 6, 15, 8, 0];
0 setOvercast 0.15;
forceWeatherChange;
showHUD [false, false, false, false, false, false, false, false, false, false];
showCinemaBorder false;
enableEnvironment false;
enableRadio false;
clearRadio;

player disableAI "MOVE"; player disableAI "ANIM"; player disableAI "PATH"; player disableAI "FSM";
private _start = getPosATL player;
_start set [2, 0];
removeAllWeapons player;
removeAllItems player;
removeAllAssignedItems player;
removeVest player;
removeBackpack player;
removeGoggles player;
removeHeadgear player;
removeUniform player;
player forceAddUniform "PTF_Uniform_Dress_USMC_A_Sgt";
player setFace "WhiteHead_02";
player setPosATL _start;
player setDir 0;
player switchMove "AmovPercMstpSnonWnonDnon";

private _cam = "camera" camCreate _start;
_cam cameraEffect ["internal", "back"];
private _view = {
    params ["_pos", "_tgt", "_fov"];
    _cam camSetPos (_start vectorAdd _pos);
    _cam camSetTarget (_start vectorAdd _tgt);
    _cam camSetFov _fov;
    _cam camCommit 0;
};
[[-0.1, 1.1, 1.36], [-0.1, 0, 1.3], 0.22] call _view;

// Every award in the catalogue, by precedence, as billet-link would publish them.
private _ids = ("true" configClasses (configFile >> "CfgPTFDressRibbons")) apply {
    (((configName _x) select [2]) splitString "_") joinString "-"
};
diag_log format ["DRESSREVIEW awards %1 uid=%2 players=%3", count _ids, getPlayerUID player, allPlayers];
private _key = "blk_rack_" + getPlayerUID player;
private _pair = {params ["_i", "_n"]; format ["%1:%2", _ids select _i, _n]};

private _shot = {
    params ["_name"];
    screenshot format ["dressreview_racktest_%1.png", _name];
    sleep 1;
};
{
    _x params ["_name", "_rack"];
    missionNamespace setVariable [_key, _rack];
    // The loop in fn_rackInit runs every 3 seconds, and draws a pass after applying.
    sleep 8;
    [_name] call _shot;
    diag_log format ["DRESSREVIEW %1 plates=%2", _name, count PTF_Dress_plates];
} forEach [
    ["none", ""],
    ["one", [8, 1] call _pair],
    ["two", ([[8, 1], [10, 1]] apply {_x call _pair}) joinString ","],
    ["four", ([[1, 1], [4, 1], [8, 1], [10, 1]] apply {_x call _pair}) joinString ","],
    ["devices", ([[4, 2], [8, 3], [10, 7]] apply {_x call _pair}) joinString ","],
    ["six", ([[0, 1], [1, 1], [2, 1], [4, 1], [8, 1], [10, 1]] apply {_x call _pair}) joinString ","]
];

// Where it sits, from the side and front, in poses and light it has to survive.
[[-1.0, 0.25, 1.4], [-0.12, 0.13, 1.36], 0.12] call _view;
sleep 2;
["profile"] call _shot;
[[0, 1.9, 1.25], [0, 0, 1.25], 0.42] call _view;
sleep 2;
["front"] call _shot;
player switchMove dress_salute;
sleep 3;
["salute"] call _shot;
player switchMove "AmovPercMstpSnonWnonDnon";
sleep 2;
[[-0.1, 1.1, 1.36], [-0.1, 0, 1.3], 0.22] call _view;
diag_log format ["DRESSREVIEW light morning %1", getLightingAt player];
{
    _x params ["_name", "_hour", "_overcast"];
    setDate [2035, 6, 15, _hour, 0];
    0 setOvercast _overcast;
    forceWeatherChange;
    sleep 5;
    diag_log format ["DRESSREVIEW light %1 %2", _name, getLightingAt player];
    [_name] call _shot;
} forEach [["noon", 12, 0], ["overcast", 12, 1], ["dusk", 19, 0.2], ["night", 23, 0]];
private _lamp = "#lightpoint" createVehicleLocal (_start vectorAdd [1, 3, 3]);
_lamp setLightColor [1, 0.95, 0.85];
_lamp setLightAmbient [0.08, 0.07, 0.06];
_lamp setLightBrightness 0.35;
_lamp setLightAttenuation [0, 0, 0.3, 0.1];
sleep 5;
diag_log format ["DRESSREVIEW light lamp %1", getLightingAt player];
["lamp"] call _shot;
deleteVehicle _lamp;
0 setOvercast 0.15;
forceWeatherChange;
setDate [2035, 6, 15, 8, 0];
forceWeatherChange;
sleep 2;

// All of it removed again: last ribbon gone, then a change of clothes.
missionNamespace setVariable [_key, ""];
sleep 5;
["removed"] call _shot;
diag_log format ["DRESSREVIEW removed plates=%1", count PTF_Dress_plates];

diag_log "DRESSREVIEW done";
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;
disableUserInput false;
endMission "END1";
