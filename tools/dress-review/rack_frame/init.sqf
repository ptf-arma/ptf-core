// Measures the rack constants in fn_rackInit.sqf: where the rack sits in the chest frame built
// from memory points, taken from where attachTo on spine3 puts it in the normal stance. Rerun it
// after the rack model or its offset in CfgPTFDressRibbons changes, and copy the logged values.
// Run with: python tools/review-dress-uniforms.py --script rack_frame --no-build --ranks Maj
#include "review_list.sqf"

diag_log "DRESSREVIEW start";
waitUntil {time > 0};
disableUserInput true; // mouse movement otherwise turns the player while the game has focus

private _start = getPosATL player;
_start set [2, 0];
removeAllWeapons player;
removeUniform player;
player forceAddUniform "PTF_Uniform_Dress_USMC_A_Maj";
player setPosATL _start;
player setDir 0;
player switchMove "AmovPercMstpSnonWnonDnon";
sleep 3;

private _plate = createVehicleLocal ["PTF_Dress_Rack", getPosATL player];
_plate attachTo [player, getArray (configFile >> "CfgPTFDressRibbons" >> "offset"), "spine3", true];
_plate setVectorDirAndUp [[0, 1, 0], [0, 0, 1]];
sleep 0.5;
private _p = player worldToModelVisual ASLToAGL getPosWorldVisual _plate;
private _d = player vectorWorldToModelVisual vectorDirVisual _plate;
private _u = player vectorWorldToModelVisual vectorUpVisual _plate;

// The same frame fn_rackInit.sqf builds.
private _s = player selectionPosition ["spine3", "Memory"];
private _bx = vectorNormalized ((player selectionPosition ["rightshoulder", "Memory"]) vectorDiff (player selectionPosition ["leftshoulder", "Memory"]));
private _bz = (player selectionPosition ["neck", "Memory"]) vectorDiff _s;
_bz = vectorNormalized (_bz vectorDiff (_bx vectorMultiply (_bz vectorDotProduct _bx)));
private _by = _bz vectorCrossProduct _bx;
private _local = {[_this vectorDotProduct _bx, _this vectorDotProduct _by, _this vectorDotProduct _bz]};
diag_log format ["DRESSREVIEW FRAME_OFFSET %1", (_p vectorDiff _s) call _local];
diag_log format ["DRESSREVIEW FRAME_DIR %1", _d call _local];
diag_log format ["DRESSREVIEW FRAME_UP %1", _u call _local];

diag_log "DRESSREVIEW done";
disableUserInput false;
endMission "END1";
