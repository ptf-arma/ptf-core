/*
	Server, from billet-link's callback: a deck finished loading (`slides|<req>`,
	data is the slide count) or failed (`slides_err|<req>`, data is the reason).
	Reads every slide out of the extension, keeps them, and points the ship at
	the new deck so every player's screens follow.
*/
params ["_function", "_data"];
(_function splitString "|") params ["_kind", ["_req", ""]];
if !(_kind in ["slides", "slides_err"]) exitWith {};
private _pending = PTF_Briefing_pending getOrDefault [_req, []];
if (_pending isEqualTo []) exitWith {};
PTF_Briefing_pending deleteAt _req;
_pending params ["_ship", "_owner", "_keepSlide", ["_url", ""]];
private _tell = {[_this] remoteExecCall ["PTF_Briefing_fnc_notify", _owner]};
if (isNull _ship) exitWith {};

if (_kind == "slides_err") exitWith {
	_ship setVariable ["PTF_Briefing_loading", -1e9];
	diag_log format ["[PTF_Briefing] deck %1 not loaded: %2", _req, _data];
	(switch (_data) do {
		case "not_public": {"That deck isn't public. In Google Slides, Share it as 'Anyone with the link can view'."};
		case "not_found": {"Google couldn't find that deck. Check the link."};
		case "not_published": {"That deck isn't published any more. Publish it again, or use its Share link."};
		case "published_partial": {"That published deck is too long to read from its web page. Use its Share link ('Anyone with the link') instead."};
		case "too_large";
		case "too_many_slides": {"That deck is too big (150 slides or 50 MB at most)."};
		case "unreachable": {"The server couldn't reach Google. Try again."};
		case "not_allowed": {"Loading slides needs the Billet permission 'Load briefing slides'."};
		case "not_linked";
		case "not_member": {"Loading slides needs a Billet account linked to your Steam account, with the 'Load briefing slides' permission."};
		case "not_on_server": {"Billet hasn't seen you on this server yet. Try again in a minute."};
		case "no_player": {"Billet couldn't tell who you are, so the slides weren't loaded."};
		case "billet_unreachable": {"The server couldn't reach Billet to check your permission. Try again."};
		case "billet_config": {"The server's Billet link is misconfigured, so nobody can load slides. Tell an admin."};
		default {format ["The slides couldn't be loaded (%1).", _data]};
	}) call _tell;
};

// Reading a big deck is a few thousand extension calls: do it scheduled, so it
// spreads over frames instead of stalling one.
[_ship, _req, parseNumber _data, _keepSlide, _owner, _url] spawn {
	params ["_ship", "_req", "_count", "_keepSlide", "_owner", "_url"];
	private _tell = {[_this] remoteExecCall ["PTF_Briefing_fnc_notify", _owner]};
	private _slides = [];
	for "_i" from 0 to _count - 1 do {
		private _parts = [];
		// 400 pieces of 6000 characters: far beyond any real 1280 px JPEG.
		for "_p" from 0 to 399 do {
			private _piece = ("billet_link" callExtension ["slide", [_req, _i, _p]]) select 0;
			if (_piece == "" || {(_piece select [0, 1]) == "!"}) exitWith {};
			_parts pushBack _piece;
		};
		_slides pushBack (_parts joinString "");
	};
	_ship setVariable ["PTF_Briefing_loading", -1e9];
	if (_count < 1 || {_slides findIf {_x == ""} >= 0}) exitWith {"The slides couldn't be read back from billet-link." call _tell};

	PTF_Briefing_decks set [_req, _slides];
	PTF_Briefing_deckOrder pushBack _req;
	PTF_Briefing_ships pushBackUnique _ship;
	// Keep the decks ships are showing, and drop the rest beyond the newest few.
	private _inUse = (PTF_Briefing_ships select {!isNull _x}) apply {(_x getVariable ["PTF_Briefing_deck", []]) param [0, ""]};
	_inUse pushBack _req;
	PTF_Briefing_deckOrder = PTF_Briefing_deckOrder select {
		if (_x in _inUse || {PTF_Briefing_deckOrder find _x >= count PTF_Briefing_deckOrder - 6}) then {true} else {
			PTF_Briefing_decks deleteAt _x;
			false
		};
	};

	private _slide = if (_keepSlide) then {(_ship getVariable ["PTF_Briefing_slide", 0]) min (_count - 1)} else {0};
	_ship setVariable ["PTF_Briefing_slide", _slide, true];
	_ship setVariable ["PTF_Briefing_blank", false, true];
	_ship setVariable ["PTF_Briefing_deck", [_req, _count], true];
	// The link Reload uses, kept only once Billet allowed the load: a refused
	// player must not leave theirs for the next officer's Reload.
	if (_url != "") then {_ship setVariable ["PTF_Briefing_url", _url, true]};
	private _chars = 0;
	{_chars = _chars + count _x} forEach _slides;
	diag_log format ["[PTF_Briefing] deck %1 loaded on %2: %3 slides, %4 KB", _req, _ship, _count, round (_chars / 1024)];
	(format ["Slides loaded: %1. Use the laptop to change slides.", _count]) call _tell;
};
