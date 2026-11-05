// Shows a real rack on a running wearer, with a camera following at fixed offsets, to see
// whether the chest plate clips or floats in motion.
// Run with: python tools/review-dress-uniforms.py --script run_test --ranks Sgt
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

// An AI, because a player with no input drops straight out of a run. fn_rackInit only
// handles players, so this attaches the same model the same way, and the mod's own function
// fills it.
private _group = createGroup [west, true];
dress_subject = _group createUnit ["B_Soldier_F", _start, [], 0, "CAN_COLLIDE"];
dress_subject setPosATL _start;
removeAllWeapons dress_subject;
removeAllItems dress_subject;
removeAllAssignedItems dress_subject;
removeVest dress_subject;
removeBackpack dress_subject;
removeHeadgear dress_subject;
removeUniform dress_subject;
dress_subject forceAddUniform "PTF_Uniform_Dress_USMC_A_GySgt";
dress_subject addHeadgear "PTF_Headgear_Dress_USMC_Cover";
dress_subject setFace "WhiteHead_02";
removeGoggles dress_subject;
dress_subject allowDamage false;
player hideObject true;
player setPosATL (_start vectorAdd [0, -60, 0]);

private _ids = ("true" configClasses (configFile >> "CfgPTFDressRibbons")) apply {
    (((configName _x) select [2]) splitString "_") joinString "-"
};
private _rack = ([0, 1, 2, 4, 8, 10] apply {format ["%1:1", _ids select _x]}) joinString ",";
private _plate = createVehicleLocal ["PTF_Dress_Rack", _start];
_plate attachTo [dress_subject, getArray (configFile >> "CfgPTFDressRibbons" >> "offset"), "spine3", true];
_plate setVectorDirAndUp [[0, 1, 0], [0, 0, 1]];
[_plate, _rack] call PTF_Dress_fnc_rackDraw;

dress_cam = "camera" camCreate _start;
dress_cam cameraEffect ["internal", "back"];
dress_camOff = [-0.5, 2.0, 1.3];
dress_camTgt = [-0.05, 0, 1.25];
dress_camFov = 0.42;
addMissionEventHandler ["EachFrame", {
    dress_cam camSetPos (dress_subject modelToWorld dress_camOff);
    dress_cam camSetTarget (dress_subject modelToWorld dress_camTgt);
    dress_cam camSetFov dress_camFov;
    dress_cam camCommit 0;
}];

// The rack's drawing takes a pass or two of the 3 second loop in fn_rackInit.
sleep 8;
screenshot "dressreview_run_000_stand.png";
sleep 1;

// Close up, standing, from the front and each side, then saluting.
dress_subject disableAI "ANIM";
dress_subject switchMove "AmovPercMstpSnonWnonDnon";
{
    _x params ["_name", "_off", "_tgt", "_fov", "_anim"];
    if (_anim != "") then {dress_subject switchMove _anim; sleep 2.5};
    dress_camOff = _off;
    dress_camTgt = _tgt;
    dress_camFov = _fov;
    sleep 1.5;
    screenshot format ["dressreview_seat_%1.png", _name];
    sleep 0.6;
} forEach [
    ["front", [-0.1, 1.0, 1.4], [-0.1, 0, 1.3], 0.25, ""],
    ["side", [-1.0, 0.2, 1.38], [-0.13, 0.1, 1.34], 0.1, ""],
    ["quarter", [-0.75, 0.75, 1.42], [-0.12, 0.1, 1.33], 0.14, ""],
    ["whole", [0, 2.0, 1.2], [0, 0, 1.2], 0.42, ""],
    ["salute", [-0.3, 1.2, 1.4], [-0.08, 0, 1.3], 0.3, "AmovPercMstpSnonWnonDnon_Salute"]
];
dress_subject switchMove "AmovPercMstpSnonWnonDnon";
dress_subject enableAI "ANIM";
sleep 1;

dress_subject setUnitPos "UP";
dress_subject setBehaviour "AWARE";
dress_subject setCombatMode "BLUE";
dress_subject setSpeedMode "FULL";
private _dest = _start vectorAdd [400, 0, 0];
dress_subject doMove _dest;
dress_subject setDestination [_dest, "LEADER PLANNED", true];
waitUntil {sleep 0.2; speed dress_subject > 8 || time > 60};
diag_log format ["DRESSREVIEW anim %1 speed %2", animationState dress_subject, speed dress_subject];

private _frame = 101;
{
    _x params ["_off", "_tgt", "_fov", "_count"];
    dress_camOff = _off;
    dress_camTgt = _tgt;
    dress_camFov = _fov;
    sleep 0.4;
    for "_i" from 1 to _count do {
        screenshot format ["dressreview_run_%1.png", _frame];
        _frame = _frame + 1;
        sleep 0.15;
    };
    diag_log format ["DRESSREVIEW anim %1 speed %2", animationState dress_subject, speed dress_subject];
} forEach [
    // Front quarter, close enough to read the rack.
    [[-0.5, 2.0, 1.3], [-0.05, 0, 1.25], 0.42, 8],
    // Side on, for the gap between plate and chest.
    [[-1.7, 0.3, 1.35], [-0.1, 0.1, 1.3], 0.3, 8],
    // Closer on the chest, from the front.
    [[-0.25, 1.1, 1.4], [-0.1, 0.1, 1.33], 0.3, 8]
];
missionNamespace setVariable ["dress_done", true];

diag_log "DRESSREVIEW done";
dress_cam cameraEffect ["terminate", "back"];
camDestroy dress_cam;
disableUserInput false;
endMission "END1";
