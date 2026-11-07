// The campaign cover on a frozen subject, from every side, in daylight and on the terrain.
// Run with: python tools/review-dress-uniforms.py --script di_cover --ranks GySgt
#include "review_list.sqf"

diag_log "DRESSREVIEW start";
waitUntil {time > 0};
disableUserInput true;
setDate [2035, 6, 15, 10, 0];
0 setOvercast 0.15;
forceWeatherChange;
showHUD [false, false, false, false, false, false, false, false, false, false];
showCinemaBorder false;
enableEnvironment false;
enableRadio false;
clearRadio;

private _start = getPosATL player;
_start set [2, 0];
player hideObject true;
player setPosATL (_start vectorAdd [0, -60, 0]);
player enableSimulation false;

private _u = (createGroup [west, true]) createUnit ["B_Soldier_F", _start, [], 0, "CAN_COLLIDE"];
_u setPosATL _start;
removeAllWeapons _u;
removeAllItems _u;
removeAllAssignedItems _u;
removeVest _u;
removeBackpack _u;
removeHeadgear _u;
removeGoggles _u;
removeUniform _u;
_u forceAddUniform "PTF_Uniform_Dress_USMC_A_GySgt";
_u addHeadgear "PTF_DI_COVER";
_u setFace "WhiteHead_02";
_u setMimic "neutral";
_u setRandomLip false;
_u disableAI "ALL";
_u allowDamage false;
_u switchMove "AmovPercMstpSnonWnonDnon";
_u setDir 0;
sleep 3;
removeGoggles _u;
_u setPosATL _start;
_u setDir 0;
_u enableSimulation false;
diag_log format ["DRESSREVIEW headgear=%1", headgear _u];

private _cam = "camera" camCreate _start;
_cam cameraEffect ["internal", "back"];
{
    _x params ["_name", "_off", "_tgt", "_fov"];
    _cam camSetPos (_start vectorAdd _off);
    _cam camSetTarget (_start vectorAdd _tgt);
    _cam camSetFov _fov;
    _cam camCommit 0;
    sleep 3;
    screenshot format ["dressreview_%1.png", _name];
    sleep 0.8;
} forEach [
    ["full", [0.6, 2.6, 1.5], [0, 0, 1.15], 0.6],
    ["front", [0, 0.9, 1.72], [0, 0, 1.72], 0.4],
    ["q34", [0.65, 0.65, 1.72], [0, 0, 1.72], 0.4],
    ["side", [0.9, 0, 1.72], [0, 0, 1.72], 0.4],
    ["left", [-0.9, 0, 1.72], [0, 0, 1.72], 0.4],
    ["back", [-0.3, -0.85, 1.75], [0, 0, 1.72], 0.4],
    ["top", [0.25, 0.55, 2.3], [0, 0, 1.75], 0.4],
    ["under", [0.35, 0.65, 1.45], [0, 0, 1.72], 0.4],
    ["emblem", [0, 0.85, 1.83], [0, 0.1, 1.805], 0.09],
    ["brim", [0.45, 0.2, 1.95], [0.1, 0.05, 1.72], 0.25]
];

// The same view in the lighting the felt colour has to survive.
_cam camSetPos (_start vectorAdd [0.65, 0.65, 1.72]);
_cam camSetTarget (_start vectorAdd [0, 0, 1.72]);
_cam camSetFov 0.4;
_cam camCommit 0;
0 setOvercast 1;
forceWeatherChange;
sleep 3;
screenshot "dressreview_overcast.png";
sleep 0.8;
0 setOvercast 0.15;
forceWeatherChange;
setDate [2035, 6, 15, 19, 30];
sleep 3;
screenshot "dressreview_dusk.png";
sleep 0.8;

diag_log "DRESSREVIEW done";
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;
disableUserInput false;
endMission "END1";
