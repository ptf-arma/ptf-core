// Shoots each uniform, wearing its cap, against a flat magenta wall, for tools/dress-review/make_icons.py
// to key out into Arsenal icons. Run with: python tools/review-dress-uniforms.py --icons
#include "review_list.sqf"

diag_log "DRESSREVIEW start";
waitUntil {time > 0};
disableUserInput true; // mouse movement otherwise turns the player while the game has focus

setDate [2035, 6, 15, 9, 0];
0 setOvercast 0.6;
0 setRain 0;
0 setFog 0;
forceWeatherChange;
showHUD [false, false, false, false, false, false, false, false, false, false];
showCinemaBorder false;
enableEnvironment false;
enableRadio false;
clearRadio;

// An AI subject, as the player drifts round between shots, often side-on.
player hideObject true;
player enableSimulation false;
player disableAI "MOVE"; player disableAI "ANIM"; player disableAI "PATH"; player disableAI "FSM"; player disableAI "TARGET"; player disableAI "AUTOTARGET";
private _start = getPosATL player;
_start set [2, 0];

// The wall stands behind the subject, far enough that the ground never enters the frame.
private _wall = createVehicle ["UserTexture10m_F", _start vectorAdd [0.6, -1.5, 5], [], 0, "CAN_COLLIDE"];
_wall setPosATL (_start vectorAdd [0.6, -1.5, 5]);
_wall setDir 158;
_wall setObjectTexture [0, "#(argb,8,8,3)color(1,0,1,1)"];

private _cam = "camera" camCreate _start;
_cam cameraEffect ["internal", "back"];

{
    _x params ["_rank", "_uniform", "_headgear"];
    private _u = (createGroup [west, true]) createUnit ["B_Soldier_F", _start, [], 0, "CAN_COLLIDE"];
    _u disableAI "ALL";
    _u allowDamage false;
    removeAllWeapons _u;
    removeAllItems _u;
    removeAllAssignedItems _u;
    removeVest _u;
    removeBackpack _u;
    removeGoggles _u;
    removeHeadgear _u;
    removeUniform _u;
    _u forceAddUniform _uniform;
    _u addHeadgear _headgear;
    _u setFace "WhiteHead_02";
    _u setMimic "neutral";
    _u setRandomLip false;
    _u setPosATL _start;
    _u setDir 0;
    _u switchMove "AmovPercMstpSnonWnonDnon";
    sleep 1.5;
    removeGoggles _u;
    _u setPosATL _start;
    _u setDir 0;
    // Three quarters from the wearer's left, so the sleeve insignia shows for every service.
    _cam camSetPos (_start vectorAdd [-1.2, 3.0, 1.25]);
    _cam camSetTarget (_start vectorAdd [0, 0, 1.2]);
    _cam camSetFov 0.42;
    _cam camCommit 0;
    sleep 2.5;
    // Again, as a new unit's own identity can overwrite these, and hands follow the face.
    _u setFace "WhiteHead_02";
    _u setMimic "neutral";
    sleep 2.5;
    _u setPosATL _start;
    _u setDir 0;
    _u enableSimulation false;
    // Long enough for the sheet to finish loading at full size.
    sleep 2;
    screenshot format ["dressreview_icon_%1.png", _rank];
    sleep 0.6;
    deleteVehicle _u;
} forEach dress_subjects;

diag_log "DRESSREVIEW done";
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;
disableUserInput false;
endMission "END1";
