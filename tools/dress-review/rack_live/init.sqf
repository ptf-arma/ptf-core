// End-to-end test of Billet racks: this mission's billet-link extension asks a local dev Billet
// for four seeded people, and what comes back is drawn on the wearer. Needs a billet-link mod
// folder whose billet_link.toml points at that dev server, passed with --extra-mod.
// Run with: python tools/review-dress-uniforms.py --script rack_live --extra-mod <folder> --ranks Sgt
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
removeAllWeapons player;
removeAllItems player;
removeAllAssignedItems player;
removeVest player;
removeBackpack player;
removeGoggles player;
removeHeadgear player;
removeUniform player;
player forceAddUniform "PTF_Uniform_Dress_USMC_A_GySgt";
player setFace "WhiteHead_02";
player setPosATL _start;
player setDir 0;
player switchMove "AmovPercMstpSnonWnonDnon";

diag_log format ["DRESSREVIEW extension %1 caps=%2 status=%3 fn=%4", "billet_link" callExtension "version", "billet_link" callExtension "caps", "billet_link" callExtension "status", !isNil "blk_fnc_rack"];
waitUntil {sleep 0.5; !isNil "BLK_tabPending" || time > 30};

private _results = [];
{
    _x params ["_who", "_uid"];
    private _sent = [_uid] call blk_fnc_rack;
    private _var = "blk_rack_" + _uid;
    private _until = time + 12;
    waitUntil {sleep 0.25; !isNil {missionNamespace getVariable _var} || time > _until};
    private _value = missionNamespace getVariable _var;
    diag_log format ["DRESSREVIEW LIVE %1 sent=%2 published=%3 value=%4", _who, _sent, !isNil "_value", if (isNil "_value") then {"-"} else {_value}];
} forEach [
    ["awards", "76561198000000001"],
    ["member_no_awards", "76561198000000002"],
    ["not_linked", "76561198000000003"],
    ["not_on_server", "76561198000000004"]
];

// The awards member's answer goes on the wearer through the normal client loop.
private _cam = "camera" camCreate _start;
_cam cameraEffect ["internal", "back"];
_cam camSetPos (_start vectorAdd [-0.1, 1.1, 1.36]);
_cam camSetTarget (_start vectorAdd [-0.1, 0, 1.3]);
_cam camSetFov 0.22;
_cam camCommit 0;
sleep 2;
screenshot "dressreview_live_before.png";
sleep 1;
missionNamespace setVariable ["blk_rack_" + getPlayerUID player, missionNamespace getVariable "blk_rack_76561198000000001"];
sleep 6;
diag_log format ["DRESSREVIEW LIVE plates=%1", count PTF_Dress_plates];
screenshot "dressreview_live_after.png";
sleep 1;

diag_log "DRESSREVIEW done";
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;
disableUserInput false;
endMission "END1";
