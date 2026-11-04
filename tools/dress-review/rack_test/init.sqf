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
_cam camSetPos (_start vectorAdd [-0.1, 0.55, 1.42]);
_cam camSetTarget (_start vectorAdd [-0.12, 0, 1.38]);
_cam camSetFov 0.22;
_cam camCommit 0;

// Every award in the catalogue, by precedence, as billet-link would publish them.
private _ids = ("true" configClasses (configFile >> "CfgPTFDressRibbons")) apply {
    (((configName _x) select [2]) splitString "_") joinString "-"
};
diag_log format ["DRESSREVIEW awards %1 uid=%2 players=%3", count _ids, getPlayerUID player, allPlayers];
private _key = "blk_rack_" + getPlayerUID player;
private _pair = {params ["_i", "_n"]; format ["%1:%2", _ids select _i, _n]};

{
    _x params ["_name", "_rack"];
    missionNamespace setVariable [_key, _rack];
    // The loop in fn_rackInit runs every 3 seconds, and draws a pass after applying.
    sleep 8;
    screenshot format ["dressreview_racktest_%1.png", _name];
    diag_log format ["DRESSREVIEW %1 texture=%2", _name, (getObjectTextures player) select 3];
    sleep 1;
} forEach [
    ["none", ""],
    ["one", [8, 1] call _pair],
    ["two", ([[8, 1], [10, 1]] apply {_x call _pair}) joinString ","],
    ["four", ([[1, 1], [4, 1], [8, 1], [10, 1]] apply {_x call _pair}) joinString ","],
    ["devices", ([[4, 2], [8, 3], [10, 7]] apply {_x call _pair}) joinString ","],
    ["all", ((_ids apply {[_ids find _x, 1]}) apply {_x call _pair}) joinString ","],
    ["removed", ""]
];

diag_log "DRESSREVIEW done";
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;
disableUserInput false;
endMission "END1";
