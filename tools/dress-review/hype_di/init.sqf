// The campaign cover for a shareable screenshot: a drill instructor out in front of a formation,
// then nose to nose with the end of the front rank. Real in-game shots, with nothing painted on.
// Run with: python tools/review-dress-uniforms.py --script hype_di --ranks GySgt --timeout 300
#include "review_list.sqf"

diag_log "DRESSREVIEW start";
waitUntil {time > 0};
disableUserInput true; // mouse movement otherwise turns the player while the game has focus
showHUD [false, false, false, false, false, false, false, false, false, false];
showCinemaBorder false;
enableEnvironment false;
enableRadio false;
clearRadio;

private _c = getPosATL player;
_c set [2, 0];
player hideObject true;
player setPosATL (_c vectorAdd [60, 60, 0]);
player enableSimulation false;

private _group = createGroup [west, true];
private _attention = "AmovPercMstpSnonWnonDnon";
private _faces = ["WhiteHead_05", "AfricanHead_01", "WhiteHead_11", "AsianHead_A3_02", "WhiteHead_14", "GreekHead_A3_05", "AfricanHead_02", "WhiteHead_07", "AsianHead_A3_01"];
private _units = [];
private _add = {
    params ["_rank", "_headgear", "_x0", "_y0", "_face"];
    private _pos = _c vectorAdd [_x0, _y0, 0];
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
    _u addHeadgear _headgear;
    _u setFace _face;
    _u setMimic "neutral";
    _u setRandomLip false;
    _u setDir 270;
    _u disableAI "ALL";
    _u setBehaviour "CARELESS";
    _u allowDamage false;
    _u switchMove _attention;
    _units pushBack _u;
    _u
};
// Ranks run along y, facing -x, toward the evening sun.
{
    _x params ["_x0", "_row"];
    private _n = count _row;
    {
        [_x, "PTF_Headgear_Dress_USMC_Cover", _x0, ((_forEachIndex - (_n - 1) / 2) * 1.15), _faces select (count _units mod count _faces)] call _add;
    } forEach _row;
} forEach [
    [0, ["Pvt", "Pvt", "PFC", "Pvt", "PFC", "Pvt", "Pvt"]],
    [1.6, ["Pvt", "PFC", "Pvt", "Pvt", "Pvt", "PFC", "Pvt"]],
    [3.2, ["PFC", "Pvt", "Pvt", "PFC", "Pvt", "Pvt", "PFC"]]
];
private _di = ["GySgt", "PTF_DI_COVER", -2.4, 0, "WhiteHead_02"] call _add;

{
    createVehicle ["Flag_US_F", _c vectorAdd _x, [], 0, "CAN_COLLIDE"];
} forEach [[5.5, -5.5, 0], [5.5, 5.5, 0]];

// A huge ring of magenta walls hides the real sky, so make_hype.py can key it out cleanly.
player setPosATL _c;
player setDir 0;
for "_b" from 0 to 315 step 45 do {
    private _wall = createVehicleLocal ["UserTexture10m_F", _c vectorAdd [0, 0, 300]];
    _wall setObjectTexture [0, "#(argb,8,8,3)color(1,0,1,1)"];
    _wall attachTo [player, [900 * sin _b, 900 * cos _b, 300]];
    _wall setDir _b;
    _wall setObjectScale 90;
};

sleep 3;
{
    removeGoggles _x;
    _x setDir 270;
    _x switchMove _attention;
} forEach _units;
sleep 3;
// Random identities can add glasses a while after spawning.
{removeGoggles _x; _x enableSimulation false} forEach _units;
diag_log format ["DRESSREVIEW headgear=%1", headgear _di];

setDate [2035, 6, 15, 19, 0];
0 setOvercast 0.25;
0 setRain 0;
0 setFog 0;
forceWeatherChange;
sleep 4;

private _cam = "camera" camCreate _c;
_cam cameraEffect ["internal", "back"];
private _shoot = {
    {
        _x params ["_name", "_off", "_tgt", "_fov"];
        _cam camSetPos (_c vectorAdd _off);
        _cam camSetTarget (_c vectorAdd _tgt);
        _cam camSetFov _fov;
        _cam camCommit 0;
        {removeGoggles _x} forEach _units;
        sleep 4;
        screenshot format ["dressreview_hype_di_%1.png", _name];
        sleep 1;
    } forEach _this;
};

// Out in front of the formation.
[
    ["front", [-7.4, -2.2, 1.35], [-2.6, 0.2, 1.45], 0.34],
    ["frontr", [-7.4, 2.2, 1.35], [-2.6, -0.2, 1.45], 0.34],
    ["portrait", [-4.9, -1.5, 1.45], [-2.4, 0, 1.6], 0.2],
    ["portraitr", [-4.9, 1.5, 1.45], [-2.4, 0, 1.6], 0.2]
] call _shoot;

// Nose to nose with the first man of the front rank, the rest of it running away from the camera.
_di enableSimulation true;
_di setPosATL (_c vectorAdd [-0.72, -3.45, 0]);
_di setDir 90;
_di switchMove _attention;
sleep 2;
_di setPosATL (_c vectorAdd [-0.72, -3.45, 0]);
_di setDir 90;
_di enableSimulation false;
[
    ["nose", [-0.36, -7.2, 1.4], [-0.36, -3.45, 1.6], 0.28],
    ["nose34", [-1.9, -6.9, 1.4], [-0.45, -3.45, 1.6], 0.28],
    ["nose34r", [1.1, -6.9, 1.4], [-0.3, -3.45, 1.6], 0.28]
] call _shoot;

diag_log "DRESSREVIEW done";
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;
disableUserInput false;
endMission "END1";
