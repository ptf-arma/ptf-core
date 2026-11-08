/*
	Server: check that billet-link is loaded and can fetch slides, then listen
	for its answers. Without it the screens stay as they are and the laptop
	menu says why.
*/
private _caps = "billet_link" callExtension "caps";
// slides_auth: billet-link also checks Billet's "Load briefing slides"
// permission. An older one loads for anyone, so it isn't used.
PTF_Briefing_ready = "slides_auth" in (_caps splitString ",");
publicVariable "PTF_Briefing_ready";
if (!PTF_Briefing_ready) exitWith {
	diag_log format ["[PTF_Briefing] billet-link with slides and permission support is not loaded on the server (caps: '%1'), so the briefing screens are off", _caps];
};

PTF_Briefing_decks = createHashMap;   // request id -> [base64 JPEG per slide]
PTF_Briefing_deckOrder = [];          // request ids, oldest first
PTF_Briefing_pending = createHashMap; // request id -> [ship, owner of the player who asked, keep slide, url]
PTF_Briefing_ships = [];              // ships that have shown slides this mission
PTF_Briefing_nextReq = 0;
// billet-link stays loaded across mission restarts, so a load still running from
// the last mission can answer late. A per-mission prefix keeps its request ids
// from ever matching this mission's. Ids are digits only, at most 10.
PTF_Briefing_reqBase = (floor (random 90000) + 10000) toFixed 0;

addMissionEventHandler ["ExtensionCallback", {
	params ["_name", "_function", "_data"];
	if (_name == "billet_link" && {(_function find "slides") == 0}) then {
		[_function, _data] call PTF_Briefing_fnc_onExtension;
	};
}];
diag_log "[PTF_Briefing] billet-link can fetch slides";
