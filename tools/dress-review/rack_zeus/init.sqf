// An unarmed wearer seen from Zeus, as the owner sees themself: the rack shows in the Arsenal but
// was reported missing here. Shoots from Zeus after first and third person, logs the rack's state.
// Run with: python tools/review-dress-uniforms.py --script rack_zeus --no-build --ranks Maj --extra-mod <CBA>;<ACE>
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

private _logic = createGroup sideLogic;
private _curator = _logic createUnit ["ModuleCurator_F", _start vectorAdd [0, 20, 0], [], 0, "NONE"];
player assignCurator _curator;
sleep 8;

{
    private _view = _x;
    player switchCamera _view;
    sleep 2;
    [format ["%1_before", _view]] call _state;
    openCuratorInterface;
    waitUntil {sleep 0.5; !isNull curatorCamera && {!isNull findDisplay 312}};
    sleep 2;
    {
        private _chest = player modelToWorldVisual (player selectionPosition "spine3");
        curatorCamera setPosASL AGLToASL (_chest vectorAdd [0, _x, 0.05]);
        curatorCamera setVectorDirAndUp [[0, -1, -0.03], [0, 0, 1]];
        sleep 3;
        private _name = format ["%1_zeus_%2m", _view, _x];
        screenshot format ["dressreview_zeus_%1.png", _name];
        sleep 0.5;
        [_name] call _state;
    } forEach [0.8, 2, 4];
    // From where the rack faces: the pose turns the left chest away from a camera in front.
    private _o = ((values PTF_Dress_plates) param [0, []]) param [0, objNull];
    if (!isNull _o) then {
        private _dir = vectorDirVisual _o;
        curatorCamera setPosASL ((getPosASLVisual _o) vectorAdd (_dir vectorMultiply 0.8));
        curatorCamera setVectorDirAndUp [_dir vectorMultiply -1, [0, 0, 1]];
        sleep 3;
        screenshot format ["dressreview_zeus_%1_facing.png", _view];
        sleep 0.5;
        [_view + "_facing"] call _state;
    };
    (findDisplay 312) closeDisplay 2;
    sleep 3;
} forEach ["INTERNAL", "EXTERNAL"];

diag_log "DRESSREVIEW done";
disableUserInput false;
endMission "END1";
