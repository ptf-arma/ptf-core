/*
	Server, from the laptop's Load and Reload actions: ask billet-link to fetch
	a Google Slides deck for this ship's screens.

	[_ship, _url, _keepSlide, player, clientOwner] remoteExecCall ["PTF_Briefing_fnc_requestLoad", 2];

	_keepSlide: stay on the current slide (Reload) instead of going back to the first.

	Loading needs the Billet permission "Load briefing slides" (slides_load):
	billet-link asks Billet about the SteamID found here from the network
	connection, never from the arguments, before it fetches anything.
*/
params [["_ship", objNull, [objNull]], ["_url", "", [""]], ["_keepSlide", false, [false]], ["_caller", objNull, [objNull]], ["_sentOwner", 0, [0]]];
if (!isServer || {isNull _ship}) exitWith {};
private _owner = [_sentOwner] call PTF_Briefing_fnc_callerOwner;
private _tell = {[_this] remoteExecCall ["PTF_Briefing_fnc_notify", _owner]};

// Who is asking: the player on the machine that sent this. A client can put
// anyone in the arguments, so the SteamID (and the unit that must be at the
// laptop) come from the engine's own record of that connection. A call made
// on this machine (single player, a player-hosted server's host) is its player.
private _uid = "";
private _sender = remoteExecutedOwner;
{
	private _info = getUserInfo _x;
	if (_sender > 0 && {(_info param [1, -1]) isEqualTo _sender}) exitWith {
		_uid = _info param [2, ""];
		_caller = _info param [10, objNull];
	};
} forEach allUsers;
if (_uid == "" && {hasInterface && {!isMultiplayer || {_sender == clientOwner}}}) then {
	_uid = getPlayerUID player;
	_caller = player;
};

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
PTF_Briefing_pending set [_req, [_ship, _owner, _keepSlide, _url]];
private _answer = ("billet_link" callExtension ["slides", [_req, _url, _uid]]) select 0;
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
"Loading slides..." call _tell;
