/*
	Server, from the laptop's Load and Reload actions: ask billet-link to fetch
	a Google Slides deck for this ship's screens.

	[_ship, _url, _keepSlide, player, clientOwner] remoteExecCall ["PTF_Briefing_fnc_requestLoad", 2];

	_keepSlide: stay on the current slide (Reload) instead of going back to the first.
*/
params [["_ship", objNull, [objNull]], ["_url", "", [""]], ["_keepSlide", false, [false]], ["_caller", objNull, [objNull]], ["_sentOwner", 0, [0]]];
if (!isServer || {isNull _ship}) exitWith {};
private _owner = [_sentOwner] call PTF_Briefing_fnc_callerOwner;
private _tell = {[_this] remoteExecCall ["PTF_Briefing_fnc_notify", _owner]};

if !(missionNamespace getVariable ["PTF_Briefing_ready", false]) exitWith {
	"Briefing screens need billet-link on the server." call _tell;
};
if !([_ship, _caller] call PTF_Briefing_fnc_canControl) exitWith {"Use the briefing laptop to load slides." call _tell};
_url = trim _url;
if (_url == "" || {count _url > 400}) exitWith {"Paste a Google Slides link." call _tell};
// A load that never answered (Google hung, say) stops blocking after two minutes.
if (time - (_ship getVariable ["PTF_Briefing_loading", -1e9]) < 120) exitWith {"Slides are already loading." call _tell};

PTF_Briefing_nextReq = PTF_Briefing_nextReq + 1;
private _req = PTF_Briefing_reqBase + (PTF_Briefing_nextReq toFixed 0);
// Registered before asking: the answer can come back before this script resumes.
PTF_Briefing_pending set [_req, [_ship, _owner, _keepSlide]];
private _answer = ("billet_link" callExtension ["slides", [_req, _url]]) select 0;
if (_answer != "queued") exitWith {
	PTF_Briefing_pending deleteAt _req;
	(switch (_answer) do {
		case "not_slides": {"That link is to a Google Sheets, Docs or Forms file. Use a link to a Google Slides deck."};
		case "bad_url": {"That isn't a Google Slides link. Use the link from Share, or from File > Share > Publish to web."};
		case "queue_full": {"The server is busy loading other slides. Try again in a moment."};
		default {format ["The server couldn't load slides (%1).", _answer]};
	}) call _tell;
};
_ship setVariable ["PTF_Briefing_loading", time];
_ship setVariable ["PTF_Briefing_url", _url, true];
"Loading slides..." call _tell;
