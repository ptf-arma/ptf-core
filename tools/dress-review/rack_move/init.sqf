// Does a rack placed each frame keep up with a moving wearer? Shoots it walking and running, from a
// camera carried along with the wearer, where any lag shows as the rack sliding off the chest.
// Run with: python tools/review-dress-uniforms.py --script rack_move --no-build --ranks Maj --extra-mod <CBA>;<ACE>
#include "review_list.sqf"

diag_log "DRESSREVIEW start";
waitUntil {time > 0};
disableUserInput true; // mouse movement otherwise turns the player while the game has focus
setDate [2035, 6, 15, 10, 0];
0 setOvercast 0.15;
forceWeatherChange;
enableEnvironment false;
enableRadio false;
clearRadio;

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
player forceAddUniform "PTF_Uniform_Dress_USMC_A_Maj";
player setFace "WhiteHead_02";
player setPosATL _start;
player setDir 0;

private _ids = ("true" configClasses (configFile >> "CfgPTFDressRibbons")) apply {
    (((configName _x) select [2]) splitString "_") joinString "-"
};
missionNamespace setVariable ["blk_rack_" + getPlayerUID player, ([0, 1, 2, 4, 8, 10] apply {format ["%1:1", _ids select _x]}) joinString ","];

private _state = {
    params ["_label"];
    private _o = ((values PTF_Dress_plates) param [0, []]) param [0, objNull];
    diag_log format ["DRESSREVIEW %1 plate=%2 hidden=%3 attached=%4 offset=%5 view=%6 anim=%7 textures=%8 camdist=%9",
        _label, _o, isObjectHidden _o, attachedTo _o, player worldToModelVisual ASLToAGL getPosASLVisual _o,
        cameraView, animationState player, count ((getObjectTextures _o) select {_x != ""}),
        (AGLToASL positionCameraToWorld [0, 0, 0]) distance getPosASLVisual _o];
};

sleep 6;
private _cam = "camera" camCreate getPosATL player;
_cam cameraEffect ["internal", "back"];
_cam camSetFov 0.45;
_cam attachTo [player, [-0.1, 1.1, 1.35]];
_cam setVectorDirAndUp [[0, -1, -0.05], [0, 0, 1]];
{
    _x params ["_name", "_move"];
    private _until = time + 4;
    private _n = 0;
    while {time < _until} do {
        player playMoveNow _move;
        sleep 0.6;
        if (time > _until - 2.5 && {_n < 3}) then {
            screenshot format ["dressreview_move_%1_%2.png", _name, _n];
            diag_log format ["DRESSREVIEW move %1 speed=%2", _name, speed player];
            _n = _n + 1;
        };
    };
} forEach [["walk", "AmovPercMwlkSnonWnonDf"], ["run", "AmovPercMrunSnonWnonDf"], ["sprint", "AmovPercMevaSnonWnonDf"]];
player playMoveNow "AmovPercMstpSnonWnonDnon";
sleep 1;
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;

diag_log "DRESSREVIEW done";
disableUserInput false;
endMission "END1";
