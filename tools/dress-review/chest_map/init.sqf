// Maps the chest's surface: sweeps a flat coloured sheet back through it, looking straight at
// it with a long lens. The depth where each pixel stops showing colour is the surface there.
// tools/dress-review/chest_map/analyse.py turns the shots into a height map.
// Run with: python tools/review-dress-uniforms.py --script chest_map --ranks Sgt --timeout 200
#include "review_list.sqf"

diag_log "DRESSREVIEW start";
waitUntil {time > 0};
disableUserInput true; // mouse movement otherwise turns the player while the game has focus
setDate [2035, 6, 15, 9, 0];
0 setOvercast 0.15;
forceWeatherChange;
showHUD [false, false, false, false, false, false, false, false, false, false];
showCinemaBorder false;
enableEnvironment false;
enableRadio false;
clearRadio;

private _start = getPosATL player;
_start set [2, 0];
private _u = (createGroup [west, true]) createUnit ["B_Soldier_F", _start, [], 0, "CAN_COLLIDE"];
_u setPosATL _start;
removeAllWeapons _u;
removeAllItems _u;
removeAllAssignedItems _u;
removeVest _u;
removeBackpack _u;
removeHeadgear _u;
removeUniform _u;
_u forceAddUniform "PTF_Uniform_Dress_USMC_A_GySgt";
removeGoggles _u;
_u allowDamage false;
_u disableAI "ANIM";
_u disableAI "MOVE";
_u switchMove "AmovPercMstpSnonWnonDnon";
player hideObject true;
player setPosATL (_start vectorAdd [0, -60, 0]);
sleep 2;
_u setPosATL _start;
_u setDir 0;
_u enableSimulation false;
sleep 1;

// The bone's real axes in this pose, so the map and the attachment agree.
private _sheet = createVehicleLocal ["UserTexture1m_F", _start];
_sheet setObjectTexture [0, "#(argb,8,8,3)color(1,0,1,1)"];
private _landing = {
    params ["_offset"];
    _sheet attachTo [_u, _offset, "spine3", true];
    sleep 0.3;
    _u worldToModel ASLToAGL getPosASL _sheet
};
private _o = [[0, 0, 0]] call _landing;
private _ax = ([[0.1, 0, 0]] call _landing) vectorDiff _o vectorMultiply 10;
private _ay = ([[0, 0.1, 0]] call _landing) vectorDiff _o vectorMultiply 10;
private _az = ([[0, 0, 0.1]] call _landing) vectorDiff _o vectorMultiply 10;
diag_log format ["DRESSREVIEW axes o=%1 x=%2 y=%3 z=%4", _o, _ax, _ay, _az];
private _inBone = {params ["_v"]; [_v vectorDotProduct _ax, _v vectorDotProduct _ay, _v vectorDotProduct _az]};

private _size = 0.24;
private _centre = [-0.11, 0, 1.40];
private _place = {
    params ["_y"];
    private _at = _centre vectorAdd [0, _y, 0];
    _sheet attachTo [_u, [_at vectorDiff _o] call _inBone, "spine3", true];
    _sheet setVectorDirAndUp [[[0, -1, 0]] call _inBone, [[0, 0, 1]] call _inBone];
    _sheet setObjectScale _size;
};

private _cam = "camera" camCreate _start;
_cam cameraEffect ["internal", "back"];
_cam camSetPos (_u modelToWorld (_centre vectorAdd [0, 3, 0]));
_cam camSetTarget (_u modelToWorld _centre);
_cam camSetFov 0.06;
_cam camCommit 0;
sleep 2;

// Depths in tenths of a millimetre, so file names stay whole numbers.
private _y = 1800;
while {_y >= 400} do {
    [_y / 10000] call _place;
    sleep 0.3;
    screenshot format ["dressreview_map_%1.png", _y];
    sleep 0.25;
    _y = _y - 30;
};
diag_log format ["DRESSREVIEW sheet size=%1 centre=%2", _size, _centre];

diag_log "DRESSREVIEW done";
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;
disableUserInput false;
endMission "END1";
