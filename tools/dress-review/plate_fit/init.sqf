// Finds how the rack plate should sit on the curved chest. Tries a grid of angles and depths,
// looking straight at the plate each time. tools/dress-review/plate_fit/analyse.py then counts
// how much of the rack survives: the angle that lets it go deepest while staying whole is the
// one that follows the chest. Run with:
//   python tools/review-dress-uniforms.py --script plate_fit --ranks Sgt --timeout 300
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
private _group = createGroup [west, true];
private _u = _group createUnit ["B_Soldier_F", _start, [], 0, "CAN_COLLIDE"];
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

private _ids = ("true" configClasses (configFile >> "CfgPTFDressRibbons")) apply {
    (((configName _x) select [2]) splitString "_") joinString "-"
};
private _rack = ([0, 1, 2, 4, 8, 10] apply {format ["%1:1", _ids select _x]}) joinString ",";
private _plate = createVehicleLocal ["UserTexture1m_F", _start];
_plate setObjectTexture [0, [_rack] call PTF_Dress_fnc_rackTexture];

// The bone's axes in the unit's coordinates, from plate_test.
private _o = [-0.0113525, -0.0268555, 1.34451];
private _ax = [0.998535, -0.0439453, 0.00942707];
private _ay = [0.045166, 0.996094, -0.0824404];
private _az = [-0.00610352, 0.0830078, 0.99678];
private _inBone = {params ["_v"]; [_v vectorDotProduct _ax, _v vectorDotProduct _ay, _v vectorDotProduct _az]};
private _target = [-0.112, 0.142, 1.366];

private _cam = "camera" camCreate _start;
_cam cameraEffect ["internal", "back"];
private _pos = {params ["_v"]; AGLToASL (_u modelToWorld _v)};
// The rack is only drawn once its plate has been on screen: show it before counting.
_plate attachTo [_u, [_target vectorDiff _o] call _inBone, "spine3", true];
_cam camSetPos (_u modelToWorld (_target vectorAdd [0, 0.9, 0]));
_cam camSetTarget (_u modelToWorld _target);
_cam camSetFov 0.09;
_cam camCommit 0;
sleep 9;

{
    private _yaw = _x;
    {
        private _tilt = _x;
        private _facing = vectorNormalized [_yaw, 1, _tilt];
        private _up = vectorNormalized ([0, 0, 1] vectorDiff (_facing vectorMultiply _facing#2));
        _cam camSetPos (_u modelToWorld (_target vectorAdd (_facing vectorMultiply 0.9)));
        _cam camSetTarget (_u modelToWorld _target);
        _cam camSetFov 0.09;
        _cam camCommit 0;
        {
            private _depth = _x;
            private _at = _target vectorDiff (_facing vectorMultiply (_depth / 1000));
            _plate attachTo [_u, [_at vectorDiff _o] call _inBone, "spine3", true];
            _plate setVectorDirAndUp [[_facing vectorMultiply -1] call _inBone, [_up] call _inBone];
            _plate setObjectScale 0.092;
            sleep 0.45;
            screenshot format ["dressreview_fit_%1_%2_%3.png", round (_yaw * 100), round (_tilt * 100), _depth + 100];
            sleep 0.2;
        } forEach [0, 30, 34, 38, 41, 44, 47, 50, 53];
        diag_log format ["DRESSREVIEW done yaw %1 tilt %2", _yaw, _tilt];
    } forEach [-0.1, 0, 0.1, 0.2];
} forEach [-0.12, -0.25, -0.4];

diag_log "DRESSREVIEW done";
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;
disableUserInput false;
endMission "END1";
