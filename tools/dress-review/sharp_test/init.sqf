// Identical frozen subjects and cameras, so texture changes can be compared shot for shot.
// Normal field of view at real viewing distances, then a zoom like the review's close-ups.
// Run with: python tools/review-dress-uniforms.py --script sharp_test --ranks Sgt
#include "review_list.sqf"

diag_log "DRESSREVIEW start";
waitUntil {time > 0};
disableUserInput true; // mouse movement otherwise turns the player while the game has focus
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

private _dress = {
    params ["_rank", "_x0", "_cap"];
    private _pos = _start vectorAdd [_x0, 0, 0];
    private _u = (createGroup [west, true]) createUnit ["B_Soldier_F", _pos, [], 0, "CAN_COLLIDE"];
    _u setPosATL _pos;
    removeAllWeapons _u;
    removeAllItems _u;
    removeAllAssignedItems _u;
    removeVest _u;
    removeBackpack _u;
    removeHeadgear _u;
    removeUniform _u;
    _u forceAddUniform format ["PTF_Uniform_Dress_USMC_A_%1", _rank];
    _u addHeadgear format ["PTF_Headgear_Dress_USMC_Cover%1", _cap];
    _u setFace "WhiteHead_02";
    {_u disableAI _x} forEach ["MOVE", "ANIM", "PATH", "FSM", "TARGET", "AUTOTARGET"];
    _u allowDamage false;
    _u switchMove "AmovPercMstpSnonWnonDnon";
    _u setDir 0;
    _u
};
private _gy = ["GySgt", -0.7, ""] call _dress;
private _col = ["Col", 0.7, "_Field"] call _dress;
sleep 3;
{removeGoggles _x; _x setPosATL (_start vectorAdd [[-0.7, 0.7] select (_x == _col), 0, 0]); _x setDir 0; _x enableSimulation false} forEach [_gy, _col];
diag_log format ["DRESSREVIEW res %1 sampling=%2", getResolution, getVideoOptions];

private _cam = "camera" camCreate _start;
_cam cameraEffect ["internal", "back"];
{
    _x params ["_name", "_off", "_tgt", "_fov"];
    _cam camSetPos (_start vectorAdd _off);
    _cam camSetTarget (_start vectorAdd _tgt);
    _cam camSetFov _fov;
    _cam camCommit 0;
    sleep 4;
    screenshot format ["dressreview_s_%1.png", _name];
    sleep 0.8;
} forEach [
    // Standing in front of them at normal zoom.
    ["d2", [0, 2, 1.5], [0, 0, 1.3], 0.75],
    ["d4", [0, 4, 1.6], [0, 0, 1.3], 0.75],
    ["d8", [0, 8, 1.7], [0, 0, 1.3], 0.75],
    ["d15", [0, 15, 1.7], [0, 0, 1.3], 0.75],
    // Holding zoom.
    ["z4", [0, 4, 1.6], [0, 0, 1.3], 0.25],
    ["z8", [0, 8, 1.7], [0, 0, 1.3], 0.25]
];

diag_log "DRESSREVIEW done";
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;
disableUserInput false;
endMission "END1";
