// Automated review mission for PTF_Dress: dresses the player in each uniform and
// screenshots it from fixed camera positions. Run by tools/review-dress-uniforms.py,
// which writes review_list.sqf. Fixed face, weather and time, so runs compare directly.
#include "review_list.sqf"

diag_log "DRESSREVIEW start";
waitUntil {time > 0};
disableUserInput true; // mouse movement otherwise turns the player while the game has focus

0 setRain 0;
0 setFog 0;
showHUD [false, false, false, false, false, false, false, false, false, false];
showCinemaBorder false;
enableEnvironment false;
enableRadio false;
clearRadio;

// [name, camera offset, target offset, fov], offsets relative to the subject's feet.
// The subject faces +y, so +x is the wearer's RIGHT side. Views ending in l or r name
// the side of the image the camera sits on, not the wearer's side.
private _allViews = [
    ["front",     [0, 3.4, 1.05],        [0, 0, 0.92],       0.75],
    ["quarter",   [2.2, 2.6, 1.15],      [0, 0, 0.92],       0.75],
    ["left",      [3.4, 0, 1.05],        [0, 0, 0.92],       0.75],
    ["right",     [-3.4, 0, 1.05],       [0, 0, 0.92],       0.75],
    ["back",      [0, -3.4, 1.05],       [0, 0, 0.92],       0.75],
    ["chest",     [0, 1.0, 1.32],        [0, 0, 1.28],       0.5],
    ["belt",      [0, 0.8, 1.0],         [0, 0, 1.0],        0.4],
    ["collar",    [0, 0.65, 1.52],       [0, 0, 1.48],       0.35],
    ["shoulder",  [0.55, 0.55, 1.75],    [0.2, 0, 1.47],     0.35],
    ["shoulderr", [-0.55, 0.55, 1.75],   [-0.2, 0, 1.47],    0.35],
    ["shouldertopl", [0.3, 0.05, 2.35],  [0.2, 0, 1.47],     0.22],
    ["shouldertopr", [-0.3, 0.05, 2.35], [-0.2, 0, 1.47],    0.22],
    ["armupperl", [1.0, 0, 1.4],         [0.25, 0, 1.3],     0.28],
    ["armupperr", [-1.0, 0, 1.4],        [-0.25, 0, 1.3],    0.28],
    ["collarl",   [-0.42, 0.62, 1.56],   [-0.12, 0, 1.5],    0.13],
    ["collarr",   [0.42, 0.62, 1.56],    [0.12, 0, 1.5],     0.13],
    ["coat",      [0, 1.7, 1.0],         [0, 0, 1.0],        0.42],
    ["eaglel",    [0.3, 0.05, 2.35],     [0.3, 0, 1.47],     0.09],
    ["eagler",    [-0.3, 0.05, 2.35],    [-0.3, 0, 1.47],    0.09],
    ["rate",      [-1.0, 0.1, 1.34],     [-0.25, 0, 1.3],    0.3],
    ["far8",      [1.5, 8, 1.5],         [0, 0, 1.0],        0.5],
    ["far15",     [3, 15, 1.6],          [0, 0, 1.0],        0.5],
    ["far30",     [6, 30, 1.7],          [0, 0, 1.0],        0.5],
    ["far60",     [10, 60, 1.7],         [0, 0, 1.0],        0.5],
    ["sleevel",   [1.05, 0, 1.18],       [0.25, 0, 1.15],    0.45],
    ["sleever",   [-1.05, 0, 1.18],      [-0.25, 0, 1.15],   0.45],
    ["cuffl",     [0.95, 0, 0.82],       [0.25, 0, 0.82],    0.32],
    ["cap",       [0.25, 0.85, 1.85],    [0, 0, 1.7],        0.35],
    ["capside",   [1.0, 0.1, 1.75],      [0, 0, 1.72],       0.25],
    ["captop",    [0.1, 0.45, 2.45],     [0, 0, 1.8],        0.25],
    ["capback",   [-0.4, -0.9, 1.9],     [0, 0, 1.75],       0.25],
    ["shoes",     [0.2, 0.9, 0.35],      [0, 0, 0.06],       0.5],
    ["legs",      [0, 1.5, 0.55],        [0, 0, 0.5],        0.5],
    ["legl",      [1.5, 0.2, 0.55],      [0, 0, 0.5],        0.5],
    ["rack",      [-0.1, 0.55, 1.42],    [-0.12, 0, 1.38],   0.22]
];

player disableAI "MOVE"; player disableAI "ANIM"; player disableAI "PATH"; player disableAI "FSM"; player disableAI "TARGET"; player disableAI "AUTOTARGET";
// On the ground: the camera offsets are measured from the feet, and the unit may
// still be settling this early in the mission.
private _start = getPosATL player;
_start set [2, 0];
private _cam = "camera" camCreate _start;
_cam cameraEffect ["internal", "back"];

// [name, hour, overcast, building to stand inside].
{
    _x params ["_light", "_hour", "_overcast", ["_building", ""], ["_flood", false]];
    setDate [2035, 6, 15, _hour, 0];
    0 setOvercast _overcast;
    forceWeatherChange;
    private _shelter = objNull;
    if (_building != "") then {
        _shelter = createVehicle [_building, _start, [], 0, "CAN_COLLIDE"];
        _shelter setPosATL _start;
    };
    private _lamp = objNull;
    if (_flood) then {
        _lamp = "#lightpoint" createVehicleLocal (_start vectorAdd [1, 3, 3]);
        _lamp setLightColor [1, 0.95, 0.85];
        _lamp setLightAmbient [0.08, 0.07, 0.06];
        _lamp setLightBrightness 0.35;
        _lamp setLightAttenuation [0, 0, 0.3, 0.1];
    };
    sleep 3;
{
    _x params ["_label", "_uniform", ["_headgear", ""]];
    removeAllWeapons player;
    removeAllItems player;
    removeAllAssignedItems player; // the base soldier spawns wearing NVGs
    removeVest player;
    removeBackpack player;
    removeGoggles player;
    removeHeadgear player;
    removeUniform player;
    player forceAddUniform _uniform;
    if (_headgear != "") then {player addHeadgear _headgear};
    player setFace "WhiteHead_02";
    player setPosATL _start;
    player setDir 0;
    player switchMove dress_anim;
    diag_log format ["DRESSREVIEW subject %1 uniform=%2 worn=%3", _label, _uniform, uniform player];
    sleep 2;

    private _base = _start;
    {
        _x params ["_name", "_camOff", "_tgtOff", "_fov"];
        if (dress_views isEqualTo [] || {_name in dress_views}) then {
            // Re-pinned each shot, or the subject drifts out of frame.
            player setPosATL _start;
            player setDir 0;
            _cam camSetPos (_base vectorAdd _camOff);
            _cam camSetTarget (_base vectorAdd _tgtOff);
            _cam camSetFov _fov;
            _cam camCommit 0;
            // Long enough for texture streaming and eye adaptation to settle.
            sleep dress_settle;
            player setPosATL _start;
            player setDir 0;
            sleep 0.2;
            screenshot format ["dressreview_%1_%2_%3.png", _light, _label, _name];
            sleep 0.6;
        };
    } forEach _allViews;
} forEach dress_subjects;
    deleteVehicle _shelter;
    deleteVehicle _lamp;
} forEach dress_lights;

diag_log "DRESSREVIEW done";
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;
disableUserInput false;
endMission "END1";
