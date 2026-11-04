// Feasibility test: can one uniform show a ribbon rack composed at runtime from separate
// images, with no variant classes? Draws two racks in turn into the ribbon selection.
// Run with: python tools/review-dress-uniforms.py --script rack_test --no-build --ranks Sgt
#include "review_list.sqf"

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
player forceAddUniform "PTF_Uniform_Dress_USMC_A_Sgt";
player setFace "WhiteHead_02";
player setPosATL _start;
player setDir 0;
player switchMove "AmovPercMstpSnonWnonDnon";

private _cam = "camera" camCreate _start;
_cam cameraEffect ["internal", "back"];
_cam camSetPos (_start vectorAdd [-0.1, 0.55, 1.42]);
_cam camSetTarget (_start vectorAdd [-0.12, 0, 1.38]);
_cam camSetFov 0.22;
_cam camCommit 0;

diag_log format ["DRESSREVIEW selections %1", getObjectTextures player];
private _texture = "#(rgb,1024,256,1)ui('RscDisplayEmpty','ptf_rack_test')";
player setObjectTexture [3, _texture];
sleep 1;
private _display = findDisplay "ptf_rack_test";
diag_log format ["DRESSREVIEW display %1", _display];

private _draw = {
    params ["_cells"];
    {ctrlDelete _x} forEach allControls _display;
    private _bg = _display ctrlCreate ["RscText", -1];
    _bg ctrlSetPosition [0, 0, 1, 1];
    _bg ctrlSetBackgroundColor [0.15, 0.15, 0.1, 1];
    _bg ctrlCommit 0;
    {
        _x params ["_col", "_row", "_colour"];
        private _c = _display ctrlCreate ["RscText", -1];
        _c ctrlSetPosition [_col / 3, 0.424 + _row * 0.28, 1 / 3 - 0.004, 0.27];
        _c ctrlSetBackgroundColor _colour;
        _c ctrlCommit 0;
    } forEach _cells;
    displayUpdate _display;
};

[[[0, 1, [0.5, 0, 0, 1]], [1, 1, [0, 0.4, 0, 1]], [2, 1, [0, 0, 0.5, 1]]]] call _draw;
sleep 3;
screenshot "dressreview_racktest_a.png";
sleep 1;
[[[1, 0, [0.6, 0.5, 0, 1]], [0, 1, [0, 0.5, 0.5, 1]], [1, 1, [0.5, 0, 0.5, 1]], [2, 1, [0.6, 0.3, 0, 1]]]] call _draw;
sleep 3;
screenshot "dressreview_racktest_b.png";
sleep 1;
diag_log format ["DRESSREVIEW textures after %1", getObjectTextures player];

diag_log "DRESSREVIEW done";
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;
disableUserInput false;
endMission "END1";
