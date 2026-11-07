/*
	Client: keep every briefing ship's screens showing what the server says.

	Each screen is a web browser control drawn into the screen's texture. Arma
	only creates that display once the screen is actually rendered, so this loop
	keeps checking, loads viewer.html into any new one, and hands it the current
	slide. Slides are fetched from the server on demand (the one on screen and
	the next) and only while the player is near the ship.
*/
PTF_Briefing_cache = createHashMap;     // "<req>_<index>" -> data URL
PTF_Briefing_partial = createHashMap;   // "<req>_<index>" -> pieces still arriving
PTF_Briefing_requested = createHashMap; // "<req>_<index>" -> time to ask again
PTF_Briefing_live = [];                 // [display, keep updating until]
PTF_Briefing_shipCount = 0;

// A browser draws on its own schedule; the texture only picks that up on
// displayUpdate. Pump each display for a few seconds after anything changes.
addMissionEventHandler ["EachFrame", {
	if (PTF_Briefing_live isEqualTo []) exitWith {};
	PTF_Briefing_live = PTF_Briefing_live select {!isNull (_x select 0) && {time < (_x select 1)}};
	{displayUpdate (_x select 0)} forEach PTF_Briefing_live;
}];

waitUntil {!isNull player};
private _classes = ("true" configClasses (configFile >> "PTF_Briefing_Ships")) apply {configName _x};
private _ships = [];
private _nextScan = 0;

while {true} do {
	// `entities` doesn't list carrier-style roots like Peral_LHA, so look around
	// the camera every couple of seconds. Only nearby ships need screens or actions.
	if (time >= _nextScan) then {
		_nextScan = time + 2;
		_ships = nearestObjects [positionCameraToWorld [0, 0, 0], _classes, 600, true];
		// Forget slides of decks no nearby ship is showing (a reload makes a new deck).
		private _live = _ships apply {(_x getVariable ["PTF_Briefing_deck", []]) param [0, ""]};
		{
			private _deck = (_x splitString "_") select 0;
			if !(_deck in _live) then {
				PTF_Briefing_cache deleteAt _x;
				PTF_Briefing_partial deleteAt _x;
			};
		} forEach ((keys PTF_Briefing_cache) + (keys PTF_Briefing_partial));
	};
	{
		private _ship = _x;
		private _cfg = configFile >> "PTF_Briefing_Ships" >> typeOf _ship;
		// The ship's parts can take a moment to exist; retry the laptop now and then.
		if (isNull (_ship getVariable ["PTF_Briefing_helper", objNull]) && {time > (_ship getVariable ["PTF_Briefing_actionsRetry", -1])}) then {
			_ship setVariable ["PTF_Briefing_actionsRetry", time + 5];
			[_ship] call PTF_Briefing_fnc_addActions;
		};
		if (isNil {_ship getVariable "PTF_Briefing_id"}) then {
			PTF_Briefing_shipCount = PTF_Briefing_shipCount + 1;
			_ship setVariable ["PTF_Briefing_id", PTF_Briefing_shipCount];
		};
		private _screens = getArray (_cfg >> "screens");
		private _deck = _ship getVariable ["PTF_Briefing_deck", []];
		private _on = _deck isNotEqualTo [] && {!(_ship getVariable ["PTF_Briefing_blank", false])};

		if (!_on) then {
			// Put back whatever the mission had on the screens.
			if (_ship getVariable ["PTF_Briefing_textured", false]) then {
				private _original = _ship getVariable ["PTF_Briefing_original", []];
				{_ship setObjectTexture [_x select 0, _original param [_forEachIndex, ""]]} forEach _screens;
				_ship setVariable ["PTF_Briefing_textured", false];
			};
		} else {
			_deck params ["_req", "_count"];
			private _index = _ship getVariable ["PTF_Briefing_slide", 0];
			// From the camera, not the player: covers Zeus and spectators too.
			private _near = (positionCameraToWorld [0, 0, 0]) distance _ship < 400;

			// Fetch the slide on screen at once, and the next one ahead of time once the
			// current one is in. The prefetch waits a random moment, so a room full of
			// players doesn't ask the server all in the same frame. Lost requests are
			// asked again after 15 s.
			if (_near) then {
				private _current = format ["%1_%2", _req, _index];
				{
					_x params ["_slide", "_prefetch"];
					private _key = format ["%1_%2", _req, _slide];
					if (_slide < _count && {!(_key in PTF_Briefing_cache)} && {time > (PTF_Briefing_requested getOrDefault [_key, -1])}
						&& {!_prefetch || {_current in PTF_Briefing_cache && {random 1 < 0.15}}}) then {
						PTF_Briefing_requested set [_key, time + 15];
						[_req, _slide, clientOwner] remoteExecCall ["PTF_Briefing_fnc_requestSlide", 2];
					};
				} forEach [[_index, false], [_index + 1, true]];
			};

			if !(_ship getVariable ["PTF_Briefing_textured", false]) then {
				if (isNil {_ship getVariable "PTF_Briefing_original"}) then {
					private _textures = getObjectTextures _ship;
					_ship setVariable ["PTF_Briefing_original", _screens apply {_textures param [_x select 0, ""]}];
				};
				{
					_x params ["_sel", "_w", "_h"];
					_ship setObjectTexture [_sel, format ["#(rgb,%1,%2,1)ui('PTF_Briefing_RscScreen','ptfbrief_%3_%4')", _w, _h, _ship getVariable "PTF_Briefing_id", _forEachIndex]];
				} forEach _screens;
				_ship setVariable ["PTF_Briefing_textured", true];
			};

			private _key = format ["%1_%2", _req, _index];
			{
				private _display = findDisplay format ["ptfbrief_%1_%2", _ship getVariable "PTF_Briefing_id", _forEachIndex];
				if (!isNull _display) then {
					private _ctrl = _display displayCtrl 1000;
					if !(_ctrl getVariable ["PTF_Briefing_init", false]) then {
						_ctrl setVariable ["PTF_Briefing_init", true];
						_ctrl setVariable ["PTF_Briefing_aspect", _x param [3, 2]];
						_ctrl ctrlAddEventHandler ["PageLoaded", {
							params ["_ctrl"];
							[_ctrl, ["ExecJS", format ["setAspect(%1)", _ctrl getVariable ["PTF_Briefing_aspect", 2]]]] call PTF_Briefing_browser;
							_ctrl setVariable ["PTF_Briefing_loaded", true];
							_ctrl setVariable ["PTF_Briefing_shown", ""];
							PTF_Briefing_live pushBack [ctrlParent _ctrl, time + 2];
						}];
						[_ctrl, ["LoadFile", "\z\PTF\addons\PTF_Briefing\viewer.html"]] call PTF_Briefing_browser;
						PTF_Briefing_live pushBack [_display, time + 3];
					};
					if (_ctrl getVariable ["PTF_Briefing_loaded", false] && {(_ctrl getVariable ["PTF_Briefing_shown", ""]) != _key}) then {
						private _data = PTF_Briefing_cache getOrDefault [_key, ""];
						if (_data != "") then {
							[_ctrl, ["ExecJS", "show('" + _data + "')"]] call PTF_Briefing_browser;
							_ctrl setVariable ["PTF_Briefing_shown", _key];
							PTF_Briefing_live pushBack [_display, time + 2];
						};
					};
				};
			} forEach _screens;
		};
	} forEach (_ships select {!isNull _x});
	sleep 0.25;
};
