// Demo lineup for PTF_Dress: real in-game screenshots of several ranks in different
// configurations of the uniform. Run with: python tools/review-dress-uniforms.py --demo
#include "review_list.sqf"

diag_log "DRESSREVIEW start";
waitUntil {time > 0};
disableUserInput true; // mouse movement otherwise turns the player while the game has focus

setDate [2035, 6, 15, 10, 0];
0 setOvercast 0.15;
0 setRain 0;
0 setFog 0;
forceWeatherChange;
showHUD [false, false, false, false, false, false, false, false, false, false];
showCinemaBorder false;
enableEnvironment false;
enableRadio false;
clearRadio;

{
    diag_log format ["DRESSREVIEW anim %1 exists=%2", _x, isClass (configFile >> "CfgMovesMaleSdr" >> "States" >> _x)];
} forEach ["AmovPercMstpSnonWnonDnon", "AmovPercMstpSnonWnonDnon_Ease", "AmovPercMstpSnonWnonDnon_EaseIn",
           "AmovPercMstpSnonWnonDnon_Salute", "AmovPercMstpSnonWnonDnon_SaluteIn",
           "Acts_CivilIdle_1", "Acts_CivilTalking_1", "InBaseMoves_HandsBehindBack1"];

private _centre = getPosATL player;
_centre set [2, 0];
player hideObject true;
player setPosATL (_centre vectorAdd [40, 40, 0]);
player enableSimulation false;

// [rank, cap suffix or "none", animation, face]. Subjects face south, into the sun.
private _attention = "AmovPercMstpSnonWnonDnon";
private _lineup = [
    ["LCpl", "", _attention, "WhiteHead_05"],
    ["Sgt", "", dress_ease, "AfricanHead_01"],
    ["GySgt", "", dress_salute, "WhiteHead_11"],
    ["HM2", "", _attention, "WhiteHead_07"],
    ["CWO3", "_Officer", dress_ease, "AsianHead_A3_01"],
    ["2ndLt", "none", _attention, "WhiteHead_14"],
    ["Capt", "_Officer", dress_salute, "AsianHead_A3_02"],
    ["Maj", "_Field", dress_ease, "WhiteHead_02"],
    ["Col", "_Field", _attention, "GreekHead_A3_05"]
];

private _group = createGroup [west, true];
private _spacing = 1.05;
private _x0 = -(count _lineup - 1) * _spacing / 2;
{
    _x params ["_rank", "_cap", "_anim", "_face"];
    private _pos = _centre vectorAdd [_x0 + _forEachIndex * _spacing, 0, 0];
    private _u = _group createUnit ["B_Soldier_F", _pos, [], 0, "CAN_COLLIDE"];
    _u setPosATL _pos;
    removeAllWeapons _u;
    removeAllItems _u;
    removeAllAssignedItems _u;
    removeVest _u;
    removeBackpack _u;
    removeGoggles _u;
    removeHeadgear _u;
    removeUniform _u;
    _u forceAddUniform format ["PTF_Uniform_Dress_USMC_A_%1", _rank];
    if (_cap != "none") then {_u addHeadgear format ["PTF_Headgear_Dress_USMC_Cover%1", _cap]};
    _u setFace _face;
    _u setDir 180;
    {_u disableAI _x} forEach ["MOVE", "TARGET", "AUTOTARGET", "ANIM", "FSM", "PATH", "AUTOCOMBAT", "COVER"];
    _u setBehaviour "CARELESS";
    _u allowDamage false;
    _u switchMove _anim;
    _u setVariable ["dress_anim", _anim];
} forEach _lineup;

// A backdrop of colours behind the line.
{
    private _flag = createVehicle ["Flag_US_F", _centre vectorAdd [_x, 7, 0], [], 0, "CAN_COLLIDE"];
} forEach [-4.5, 4.5];

sleep 4;
private _units = units _group;
{
    // Random identities hand out sunglasses after spawn.
    removeGoggles _x;
    _x setDir 180;
    _x switchMove (_x getVariable "dress_anim");
} forEach _units;
sleep 2;
{
    _x disableAI "ANIM";
    _x switchMove (_x getVariable "dress_anim");
} forEach _units;
sleep 2;
{_x enableSimulation false} forEach _units;

private _cam = "camera" camCreate _centre;
_cam cameraEffect ["internal", "back"];

// [name, camera offset, target offset, fov]. The line faces -y.
{
    _x params ["_name", "_camOff", "_tgtOff", "_fov"];
    _cam camSetPos (_centre vectorAdd _camOff);
    _cam camSetTarget (_centre vectorAdd _tgtOff);
    _cam camSetFov _fov;
    _cam camCommit 0;
    sleep 5;
    screenshot format ["dressreview_demo_%1.png", _name];
    sleep 1.5;
} forEach [
    ["wide",     [0.2, -8.2, 1.25],  [0, 0, 0.98],  0.46],
    ["angle",    [3.5, -7.4, 1.3],   [0.1, 0, 0.98], 0.46],
    ["enlisted", [-2.6, -3.8, 1.35], [-2.9, 0, 1.2], 0.5],
    ["middle",   [0.2, -3.8, 1.35],  [0.1, 0, 1.2],  0.5],
    ["officers", [2.8, -3.8, 1.35],  [3.0, 0, 1.2],  0.5]
];

diag_log "DRESSREVIEW done";
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;
disableUserInput false;
endMission "END1";
