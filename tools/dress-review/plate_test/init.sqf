// Calibrates a rack plate attached to the chest bone, and shows it on the pocket with real
// ribbons at the order's proportions. Logs the offset and orientation for fn_rackInit.
// Run with: python tools/review-dress-uniforms.py --script plate_test --ranks Sgt
#include "review_list.sqf"
// Rack's bottom centre and the chest's facing in the unit's coordinates, and the plate's
// width in metres. The logged RESULT line gives the values for fn_rackInit.
dress_target = [-0.112, 0.142, 1.366];
dress_facing = [-0.12, 1, 0];
dress_scale = 0.092;

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
player forceAddUniform "PTF_Uniform_Dress_USMC_A_GySgt";
player setFace "WhiteHead_02";
player setPosATL _start;
player setDir 0;
player switchMove "AmovPercMstpSnonWnonDnon";
sleep 2;
player setPosATL _start;
player setDir 0;

private _plate = createVehicleLocal ["UserTexture1m_F", _start];

// Where the plate lands for each offset, in the unit's own coordinates, gives the bone's axes.
private _landing = {
    params ["_offset"];
    _plate attachTo [player, _offset, "spine3", true];
    sleep 0.3;
    player worldToModel ASLToAGL getPosASL _plate
};
private _o = [[0, 0, 0]] call _landing;
private _ax = ([[0.1, 0, 0]] call _landing) vectorDiff _o vectorMultiply 10;
private _ay = ([[0, 0.1, 0]] call _landing) vectorDiff _o vectorMultiply 10;
private _az = ([[0, 0, 0.1]] call _landing) vectorDiff _o vectorMultiply 10;
diag_log format ["DRESSREVIEW axes o=%1 x=%2 y=%3 z=%4", _o, _ax, _ay, _az];

// Rack's bottom centre, and the chest's facing there, in the unit's coordinates.
private _target = dress_target;
private _facing = vectorNormalized dress_facing;
private _up = [0, 0, 1];
_up = vectorNormalized (_up vectorDiff (_facing vectorMultiply (_up vectorDotProduct _facing)));

// Into the bone's frame. Its axes are orthonormal, so the transpose is the inverse.
private _inBone = {
    params ["_v"];
    [_v vectorDotProduct _ax, _v vectorDotProduct _ay, _v vectorDotProduct _az]
};
private _offset = [_target vectorDiff _o] call _inBone;
// The plate is seen from its -y side, so its own forward points into the chest.
private _dir = [_facing vectorMultiply -1] call _inBone;
private _relUp = [_up] call _inBone;
diag_log format ["DRESSREVIEW RESULT offset=%1 dir=%2 up=%3", _offset, _dir, _relUp];

_plate attachTo [player, _offset, "spine3", true];
_plate setVectorDirAndUp [_dir, _relUp];
_plate setObjectScale dress_scale;
sleep 0.5;
diag_log format ["DRESSREVIEW landed %1 wanted %2", player worldToModel ASLToAGL getPosASL _plate, _target];

_plate setObjectTexture [0, "#(rgb,1024,1024,1)ui('RscDisplayEmpty','ptf_plate_test')"];
// The display only exists once the plate has been on screen.
private _cam = "camera" camCreate _start;
_cam cameraEffect ["internal", "back"];
_cam camSetPos (_start vectorAdd [-0.12, 0.8, 1.36]);
_cam camSetTarget (_start vectorAdd [-0.12, 0, 1.3]);
_cam camSetFov 0.16;
_cam camCommit 0;
waitUntil {sleep 0.2; !isNull findDisplay "ptf_plate_test"};
private _display = findDisplay "ptf_plate_test";
diag_log format ["DRESSREVIEW display %1", _display];
private _tiles = ("true" configClasses (configFile >> "CfgPTFDressRibbons")) apply {getText (_x >> "picture")};
// Three to a row at 1 3/8 by 3/8 inches, filling the texture's width. The plate's centre,
// which is the attachment point, is the rack's bottom edge.
private _w = 1 / 3;
private _h = _w * (3 / 8) / (11 / 8);
{
    _x params ["_col", "_row"];
    private _c = _display ctrlCreate ["RscPicture", -1];
    _c ctrlSetPosition [_col * _w, 0.5 - (_row + 1) * _h, _w, _h];
    _c ctrlSetText (_tiles select _forEachIndex);
    _c ctrlCommit 0;
} forEach [[0, 1], [1, 1], [2, 1], [0, 0], [1, 0], [2, 0]];
displayUpdate _display;
sleep 2;

{
    _x params ["_name", "_anim", "_pos", "_tgt", "_fov"];
    if (_anim != "") then { player switchMove _anim; sleep 2.5; };
    _cam camSetPos (_start vectorAdd _pos);
    _cam camSetTarget (_start vectorAdd _tgt);
    _cam camSetFov _fov;
    _cam camCommit 0;
    sleep 2;
    screenshot format ["dressreview_plate_%1.png", _name];
    sleep 0.6;
} forEach [
    ["near",   "",                                 [-0.12, 0.8, 1.36],  [-0.12, 0, 1.3], 0.16],
    ["top",    "",                                 [-0.2, 0.2, 2.2],    [-0.18, 0.1, 1.36], 0.1],
    ["profile", "",                                [-1.1, 0.1, 1.38],   [-0.15, 0.12, 1.36], 0.1],
    ["front",  "",                                 [0, 1.9, 1.25],      [0, 0, 1.25],    0.42],
    ["side",   "",                                 [-0.9, 0.3, 1.36],   [-0.12, 0.14, 1.33], 0.14],
    ["salute", "AmovPercMstpSnonWnonDnon_Salute",  [0, 1.9, 1.25],      [0, 0, 1.25],    0.42],
    ["ease",   "AmovPercMstpSnonWnonDnon_EaseIn",  [0, 1.9, 1.25],      [0, 0, 1.25],    0.42]
];

diag_log "DRESSREVIEW done";
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;
disableUserInput false;
endMission "END1";
