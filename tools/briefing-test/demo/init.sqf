// Playable demo of PTF_Briefing: puts you in the LHA briefing room next to the podium.
// Run with: python tools/briefing-test/demo.py --billet-dll <billet_link.dll>
#include "test_settings.sqf"

waitUntil {time > 0};
setDate [2035, 6, 15, 12, 0];
0 setOvercast 0;
forceWeatherChange;

titleText ["Setting up the LHA...", "BLACK FADED", 999];
private _lha = createVehicle ["Peral_LHA", [400, 400, 0], [], 0, "CAN_COLLIDE"];
_lha setPosASL [400, 400, 0];
private _t = time;
waitUntil {count (_lha getVariable ["bis_carrierparts", []]) >= 8 || time - _t > 60};
[_lha] call BIS_fnc_Carrier01PosUpdate;
sleep 3;
([_lha] call PTF_Briefing_fnc_laptopPos) params ["_part", "_local"];
[_part, "BriefingRoom", "BriefingRoomRVMatts", 1, 5] call LHA_fnc_lha_Lights;

// A few metres in front of the podium, facing it and the screens behind it.
private _laptop = _part modelToWorldWorld _local;
private _stand = _laptop vectorAdd [-3.5, 0, 0];
_stand set [2, (_laptop select 2) - 1.2];
player setPosASL _stand;
player setDir 90;
player allowDamage false;

copyToClipboard brief_url;
titleText ["", "BLACK IN", 2];
hint parseText format [
	"<t size='1.2'>PTF Briefing demo</t><br/><br/>Walk to the laptop on the podium and use ACE interact (Windows key by default): <t color='#ffcc66'>Briefing screens</t>.<br/><br/>A public test deck's link is on your clipboard: choose <t color='#ffcc66'>Load slides...</t> and paste it (Ctrl+V), or use your own deck: its Share link ('Anyone with the link') or its File, Share, Publish to web link.<br/><br/>Esc, Abort closes the game when you're done."
];
