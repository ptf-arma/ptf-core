// In-game test of PTF_Briefing: load a public Google deck through billet-link the way
// the laptop does, then photograph the LHA briefing screens as slides change.
// Run with: python tools/briefing-test/run.py --billet-dll <billet_link.dll>
#include "test_settings.sqf"

diag_log "BRIEFTEST start";
waitUntil {time > 0};
disableUserInput true;
setDate [2035, 6, 15, 12, 0];
0 setOvercast 0;
forceWeatherChange;
showCinemaBorder false;
enableEnvironment false;
enableRadio false;
diag_log format ["BRIEFTEST ready=%1 caps=%2 version=%3", missionNamespace getVariable ["PTF_Briefing_ready", "nil"],
	"billet_link" callExtension "caps", "billet_link" callExtension "version"];

private _shot = {
	params ["_name"];
	sleep 1;
	screenshot format ["brieftest_%1.png", _name];
	diag_log format ["BRIEFTEST CAPTURE %1", _name];
	sleep 2;
};

// ---------- ship at sea level, briefing lights on ----------
private _lha = createVehicle ["Peral_LHA", [400, 400, 0], [], 0, "CAN_COLLIDE"];
_lha setPosASL [400, 400, 0];
private _t = time;
waitUntil {count (_lha getVariable ["bis_carrierparts", []]) >= 8 || time - _t > 60};
[_lha] call BIS_fnc_Carrier01PosUpdate;
sleep 5;
private _med2 = ((([_lha] call PTF_Briefing_fnc_laptopPos)) select 0);
[_med2, "BriefingRoom", "BriefingRoomRVMatts", 1, 5] call LHA_fnc_lha_Lights;

// ---------- where is the laptop? ----------
private _proxy = "proxy:\a3\props_f_enoch\military\equipment\laptop_03_f.001";
{
	diag_log format ["BRIEFTEST laptop lod %1 -> %2", _x, _med2 selectionPosition [_proxy, _x]];
} forEach [0, 1, 2, "Memory", "Geometry", "ViewGeometry", "FireGeometry"];
diag_log format ["BRIEFTEST podium -> %1 / %2", _med2 selectionPosition ["podium", 0], _med2 selectionPosition "podium"];
([_lha] call PTF_Briefing_fnc_laptopPos) params ["_part", "_laptopLocal"];
private _laptop = _part modelToWorldWorld _laptopLocal;
diag_log format ["BRIEFTEST laptopPos part=%1 local=%2 world=%3 helper=%4", typeOf _part, _laptopLocal, _laptop,
	getPosASL (_lha getVariable ["PTF_Briefing_helper", objNull])];

// ---------- camera, and the screens' positions from what it sees ----------
private _eye = (_med2 modelToWorldWorld (_med2 selectionPosition "chair_01")) vectorAdd [0, 0, 1.2];
private _cam = "camera" camCreate ASLToAGL _eye;
_cam cameraEffect ["internal", "back"];
private _look = {
	params ["_from", "_to", "_fov"];
	_cam camSetPos ASLToAGL _from;
	_cam camSetTarget ASLToAGL _to;
	_cam camSetFov _fov;
	_cam camCommit 0;
};
// This view showed both screens in the earlier runs: far screen at pixel (820, 450),
// side screen at (1190, 320) of 1600 x 900.
[_eye, _eye vectorAdd [8, 17, 0.6], 0.7] call _look;
sleep 1;
private _screens = [[820, 450], [1190, 320]] apply {
	_x params ["_px", "_py"];
	private _dir = screenToWorldDirection [safeZoneX + _px / 1600 * safeZoneW, safeZoneY + _py / 900 * safeZoneH];
	private _hit = (lineIntersectsSurfaces [_eye, _eye vectorAdd (_dir vectorMultiply 60), objNull, objNull, true, 1]) param [0, []];
	if (_hit isEqualTo []) then {[_eye vectorAdd (_dir vectorMultiply 15), _dir vectorMultiply -1]} else {[_hit select 0, _hit select 1]}
};
diag_log format ["BRIEFTEST screens %1", _screens];
// The laptop sits on the podium in front of the far screen, around pixel (828, 466)
// in this view. Scan down from there: the first ray that stops well short of the
// wall behind has hit the laptop or the podium top.
private _wallDist = _eye distance ((_screens select 0) select 0);
private _lhit = [];
for "_py" from 455 to 520 step 1 do {
	private _ldir = screenToWorldDirection [safeZoneX + 828 / 1600 * safeZoneW, safeZoneY + _py / 900 * safeZoneH];
	private _h = (lineIntersectsSurfaces [_eye, _eye vectorAdd (_ldir vectorMultiply 60), objNull, objNull, true, 1]) param [0, []];
	if (_h isNotEqualTo [] && {(_eye distance (_h select 0)) < _wallDist - 0.6}) exitWith {_lhit = _h; diag_log format ["BRIEFTEST laptop ray at pixel y %1", _py]};
};
if (_lhit isNotEqualTo []) then {
	private _measured = _med2 worldToModel (ASLToAGL (_lhit select 0));
	diag_log format ["BRIEFTEST laptop measured world %1 model %2 hitObj %3", _lhit select 0, _measured, typeOf (_lhit select 2)];
	_laptop = _lhit select 0;
	_laptopLocal = _measured;
	(_lha getVariable ["PTF_Briefing_helper", objNull]) attachTo [_med2, _measured];
	_med2 setVariable ["PTF_Briefing_laptop", _measured];
};
["room_empty"] call _shot;

// ---------- load the deck the way the laptop's Load action does ----------
[_lha, brief_url, false] call PTF_Briefing_fnc_requestLoad;
_t = time;
waitUntil {(_lha getVariable ["PTF_Briefing_deck", []]) isNotEqualTo [] || time - _t > 60};
diag_log format ["BRIEFTEST deck %1 after %2 s, slide %3 (player uid %4)", _lha getVariable ["PTF_Briefing_deck", []], time - _t, _lha getVariable ["PTF_Briefing_slide", -9], getPlayerUID player];
// refused (no slides_load permission, say): nothing more to look at
if ((_lha getVariable ["PTF_Briefing_deck", []]) isEqualTo []) exitWith {
	diag_log format ["BRIEFTEST done (no deck), reload link '%1'", _lha getVariable ["PTF_Briefing_url", ""]];
	disableUserInput false;
	endMission "END1";
};
sleep 6;

private _close = {
	params ["_screen", "_name"];
	_screen params ["_pos", "_normal"];
	[_pos vectorAdd (_normal vectorMultiply 5), _pos, 0.55] call _look;
	[_name] call _shot;
};
// Grid check: cover each screen's page with square cells and a circle. On the
// screen the circle's width/height x 2 is the screen's real aspect ratio.
private _gridJs = "(function(){var c=document.createElement('canvas');c.id='grid';c.width=innerWidth;c.height=innerHeight;c.style='position:fixed;left:0;top:0;z-index:9';var g=c.getContext('2d');g.fillStyle='#111';g.fillRect(0,0,c.width,c.height);g.strokeStyle='#888';g.lineWidth=4;for(var x=0;x<=c.width;x+=c.width/16){g.beginPath();g.moveTo(x,0);g.lineTo(x,c.height);g.stroke()}for(var y=0;y<=c.height;y+=c.height/8){g.beginPath();g.moveTo(0,y);g.lineTo(c.width,y);g.stroke()}g.strokeStyle='#ff0';g.lineWidth=12;g.beginPath();g.ellipse(c.width/2,c.height/2,c.height*0.4,c.height*0.4,0,0,7);g.stroke();g.strokeStyle='#f00';g.lineWidth=16;g.strokeRect(8,8,c.width-16,c.height-16);document.body.appendChild(c)})()";
{
	private _d = findDisplay _x;
	diag_log format ["BRIEFTEST display %1 -> %2", _x, _d];
	if (!isNull _d) then {
		[_d displayCtrl 1000, ["ExecJS", _gridJs]] call PTF_Briefing_browser;
		PTF_Briefing_live pushBack [_d, time + 3];
	};
} forEach ["ptfbrief_1_0", "ptfbrief_1_1"];
sleep 1;
[_screens select 0, "far_grid"] call _close;
[_screens select 1, "side_grid"] call _close;
{
	private _d = findDisplay _x;
	if (!isNull _d) then {
		[_d displayCtrl 1000, ["ExecJS", "document.getElementById('grid').remove()"]] call PTF_Briefing_browser;
		PTF_Briefing_live pushBack [_d, time + 3];
	};
} forEach ["ptfbrief_1_0", "ptfbrief_1_1"];

[_eye, _eye vectorAdd [8, 17, 0.6], 0.7] call _look;
["room_slide1"] call _shot;
[_screens select 0, "far_slide1"] call _close;
[_screens select 1, "side_slide1"] call _close;

{
	_x params ["_action", "_name"];
	[_lha, _action] call PTF_Briefing_fnc_setSlide;
	sleep 3;
	diag_log format ["BRIEFTEST %1 -> slide %2 blank %3 cached %4", _action, _lha getVariable "PTF_Briefing_slide",
		_lha getVariable ["PTF_Briefing_blank", false], keys PTF_Briefing_cache];
	[_screens select 1, _name] call _close;
} forEach [["next", "side_next"], ["next", "side_next2"], ["blank", "side_blank"], ["first", "side_first"]];

// ---------- the podium, and the ACE menu on the laptop ----------
[_laptop vectorAdd [1.6, -1.2, 1.0], _laptop, 0.6] call _look;
["laptop"] call _shot;
_cam cameraEffect ["terminate", "back"];
camDestroy _cam;
// Stand behind the podium (screen side), facing the laptop and the room.
private _away = (_screens select 0 select 0) vectorDiff _laptop;
_away set [2, 0];
private _stand = _laptop vectorAdd ((vectorNormalized _away) vectorMultiply 0.8);
_stand set [2, (_laptop select 2) - 1.05];
player setPosASL _stand;
player setDir (player getDir (ASLToAGL _laptop));
sleep 2;
diag_log format ["BRIEFTEST player %1 laptop %2 dist %3", getPosASL player, _laptop, player distance (ASLToAGL _laptop)];
[0] call ace_interact_menu_fnc_keyDown;
sleep 2;
diag_log "BRIEFTEST CAPTURE ace_menu";
sleep 2;
[0] call ace_interact_menu_fnc_keyUp;

diag_log "BRIEFTEST done";
disableUserInput false;
endMission "END1";
