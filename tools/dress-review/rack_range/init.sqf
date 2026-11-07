// Why does a wearer's rack show in the Arsenal but not outside it? Shoots one wearer's rack
// unarmed and with a rifle, from a scripted camera, inside and after ACE Arsenal, and from Zeus,
// and logs where the rack object sits each time. Needs CBA and ACE loaded through --extra-mod.
// Run with: python tools/review-dress-uniforms.py --script rack_range --no-build --ranks Maj --extra-mod <CBA>;<ACE>
#include "review_list.sqf"

diag_log "DRESSREVIEW start";
waitUntil {time > 0};
disableUserInput true; // mouse movement otherwise turns the player while the game has focus
setDate [2035, 6, 15, 10, 0];
0 setOvercast 0.15;
forceWeatherChange;
showCinemaBorder false;
enableEnvironment false;
enableRadio false;
clearRadio;

private _start = getPosATL player;
_start set [2, 0];
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
private _rifle = primaryWeapon player;

// One ribbon, as on the owner's rack.
private _ids = ("true" configClasses (configFile >> "CfgPTFDressRibbons")) apply {
    (((configName _x) select [2]) splitString "_") joinString "-"
};
missionNamespace setVariable ["blk_rack_" + getPlayerUID player, format ["%1:1", _ids select 0]];

private _state = {
    params ["_label"];
    private _plates = values PTF_Dress_plates;
    private _plate = if (_plates isEqualTo []) then {objNull} else {(_plates select 0) select 0};
    diag_log format ["DRESSREVIEW %1 plates=%2 hidden=%3 offset=%4 view=%5 weapon=%6 anim=%7",
        _label, count _plates, isObjectHidden _plate,
        if (isNull _plate) then {"-"} else {player worldToModelVisual ASLToAGL getPosWorldVisual _plate},
        cameraView, currentWeapon player, animationState player];
};
private _shot = {
    params ["_name"];
    sleep 1.5;
    screenshot format ["dressreview_range_%1.png", _name];
    sleep 0.5;
    [_name] call _state;
};
// A camera 1.5 m in front of the chest, turned with the torso so it faces the rack.
private _cam = objNull;
private _look = {
    params ["_name", ["_dist", 1.5], ["_fov", 0.5]];
    private _chest = player modelToWorld (player selectionPosition "spine3");
    private _front = vectorDir player;
    _cam = "camera" camCreate _chest;
    _cam cameraEffect ["internal", "back"];
    _cam camSetPos (_chest vectorAdd (_front vectorMultiply _dist));
    _cam camSetTarget _chest;
    _cam camSetFov _fov;
    _cam camCommit 0;
    [_name] call _shot;
    player hideObject true;
    [_name + "_bodyhidden"] call _shot;
    player hideObject false;
    // From the wearer's left, where a gap behind the rack would show.
    private _plate = (values PTF_Dress_plates) param [0, [objNull]] select 0;
    if (!isNull _plate) then {
        private _at = ASLToAGL getPosASLVisual _plate;
        private _dir = vectorDirVisual _plate;
        _cam camSetPos (_at vectorAdd ((vectorNormalized ([0, 0, 1] vectorCrossProduct _dir)) vectorMultiply 0.5) vectorAdd (_dir vectorMultiply 0.2));
        _cam camSetTarget _at;
        _cam camSetFov 0.3;
        _cam camCommit 0;
        [_name + "_side"] call _shot;
    };
    _cam cameraEffect ["terminate", "back"];
    camDestroy _cam;
};

sleep 8;
player action ["SwitchWeapon", player, player, 299];
player switchMove "AmovPercMstpSnonWnonDnon";
sleep 2;
["unarmed"] call _look;
player selectWeapon _rifle;
player switchMove "AmovPercMstpSlowWrflDnon";
sleep 2;
["rifle_lowered"] call _look;
player switchMove "AmovPercMstpSrasWrflDnon";
sleep 2;
["rifle_raised"] call _look;

// ACE Arsenal as players open it, then after it closes.
[player, player, true] call ace_arsenal_fnc_openBox;
waitUntil {sleep 0.5; !isNull findDisplay 1127001};
sleep 6;
["ace_arsenal"] call _shot;
(findDisplay 1127001) closeDisplay 2;
sleep 6;
["after_arsenal"] call _look;

// Zeus, looking at the chest from in front.
private _logic = createGroup sideLogic;
private _curator = _logic createUnit ["ModuleCurator_F", _start vectorAdd [0, 20, 0], [], 0, "NONE"];
player assignCurator _curator;
sleep 1;
openCuratorInterface;
waitUntil {sleep 0.5; !isNull curatorCamera};
sleep 2;
{
    private _chest = player modelToWorld (player selectionPosition "spine3");
    private _front = vectorDir player;
    curatorCamera setPosASL AGLToASL (_chest vectorAdd (_front vectorMultiply _x));
    curatorCamera setVectorDirAndUp [_front vectorMultiply -1, [0, 0, 1]];
    sleep 3;
    [format ["zeus_%1m", _x]] call _shot;
} forEach [1.5, 4];
(findDisplay 312) closeDisplay 2;
sleep 2;

diag_log "DRESSREVIEW done";
disableUserInput false;
endMission "END1";
