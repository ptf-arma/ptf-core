// A staged formation for a shareable screenshot: three ranks, officers out front and flags,
// shot low in evening light. Real in-game shots, with nothing painted on.
// Run with: python tools/review-dress-uniforms.py --script hype --ranks Sgt --timeout 200
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
private _faces = ["WhiteHead_02", "WhiteHead_05", "AfricanHead_01", "WhiteHead_11", "AsianHead_A3_02", "WhiteHead_14", "GreekHead_A3_05", "AfricanHead_02", "WhiteHead_07", "AsianHead_A3_01"];
private _coverFor = {
    params ["_rank"];
    if (_rank in ["Maj", "LtCol", "Col"]) exitWith {"_Field"};
    if (_rank in ["WO1", "CWO2", "CWO3", "CWO4", "CWO5", "2ndLt", "1stLt", "Capt"]) exitWith {"_Officer"};
    ""
};
private _units = [];
private _add = {
    params ["_rank", "_x0", "_y0", "_anim"];
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
    _u addHeadgear format ["PTF_Headgear_Dress_USMC_Cover%1", [_rank] call _coverFor];
    _u setFace (_faces select (count _units mod count _faces));
    _u setDir 270;
    {_u disableAI _x} forEach ["MOVE", "TARGET", "AUTOTARGET", "ANIM", "FSM", "PATH", "AUTOCOMBAT", "COVER"];
    _u setBehaviour "CARELESS";
    _u allowDamage false;
    _u switchMove _anim;
    _u setVariable ["dress_anim", _anim];
    _units pushBack _u;
};
// Ranks run along y, facing -x, toward the evening sun.
{
    _x params ["_x0", "_row"];
    private _n = count _row;
    {
        [_x, _x0, ((_forEachIndex - (_n - 1) / 2) * 1.15), _attention] call _add;
    } forEach _row;
} forEach [
    [0, ["Sgt", "HM3", "GySgt", "SSgt", "HM1", "Sgt", "SSgt"]],
    [1.6, ["LCpl", "Cpl", "PFC", "HM2", "Cpl", "LCpl", "PFC"]],
    [3.2, ["Pvt", "PFC", "LCpl", "HN", "LCpl", "Cpl", "Pvt"]]
];
["Col", -3.2, 0, dress_salute] call _add;
["Maj", -2.0, -2.0, _attention] call _add;
["Capt", -2.0, 2.0, _attention] call _add;
["CWO3", -2.0, -3.4, _attention] call _add;
["1stLt", -2.0, 3.4, _attention] call _add;

{
    private _flag = createVehicle ["Flag_US_F", _c vectorAdd _x, [], 0, "CAN_COLLIDE"];
} forEach [[5.5, -5.5, 0], [5.5, 5.5, 0], [5.5, 0, 0]];

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
    _x switchMove (_x getVariable "dress_anim");
} forEach _units;
sleep 3;
// Random identities can add glasses a while after spawning.
{removeGoggles _x; _x enableSimulation false} forEach _units;

private _cam = "camera" camCreate _c;
_cam cameraEffect ["internal", "back"];
{
    _x params ["_label", "_hour", "_minute"];
    setDate [2035, 6, 15, _hour, _minute];
    0 setOvercast 0.25;
    0 setRain 0;
    0 setFog 0;
    forceWeatherChange;
    sleep 4;
    {
        _x params ["_name", "_off", "_tgt", "_fov"];
        _cam camSetPos (_c vectorAdd _off);
        _cam camSetTarget (_c vectorAdd _tgt);
        _cam camSetFov _fov;
        _cam camCommit 0;
        {removeGoggles _x} forEach _units;
        sleep 4;
        screenshot format ["dressreview_hype_%1_%2.png", _label, _name];
        sleep 1;
    } forEach [
        ["low", [-7.6, -2.4, 0.5], [-2.6, 0.35, 1.95], 0.36],
        ["lower", [-6.4, -1.5, 0.35], [-2.8, 0.15, 1.75], 0.45],
        ["left", [-7.4, 2.8, 0.55], [-2.6, -0.2, 1.9], 0.36],
        ["rank", [-1.6, -7.2, 1.0], [-0.4, 0.6, 1.5], 0.3]
    ];
} forEach [["c", 19, 0]];

diag_log "DRESSREVIEW done";
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;
disableUserInput false;
endMission "END1";
