/*
	Written 2019-02-03 by Erik Kofahl
	Last Edited 2019-02-04 - Adding more CBA options
	2019-11-30 - Adding Azimuth and Elevation indicators
*/

#include "script_name.hpp"	// GLT: GLT_MOD_NAME = mod display name used as the settings category

//diag_log "===FAT_LURCH DEDUG: XEH_preInit.sqf called===";

[
    "Fat_Lurch_ShowNorth", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type. CHECKBOX, EDITBOX, SLIDER, LIST or COLOR
    "Show North", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    GLT_MOD_NAME, // GLT: was "Turret Enhanced". Pretty name of the category where the setting can be found. Can be stringtable entry.
    TRUE, // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {  
        //params ["_value"];
        //setViewDistance _value;
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_Settings_fnc_init;

[
    "Fat_Lurch_ShowAz", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type. CHECKBOX, EDITBOX, SLIDER, LIST or COLOR
    "Show Azimuth", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    GLT_MOD_NAME, // GLT: was "Turret Enhanced". Pretty name of the category where the setting can be found. Can be stringtable entry.
    TRUE, // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {  
        //params ["_value"];
        //setViewDistance _value;
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_Settings_fnc_init;

[
    "Fat_Lurch_ShowEl", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type. CHECKBOX, EDITBOX, SLIDER, LIST or COLOR
    "Show Elevation", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    GLT_MOD_NAME, // GLT: was "Turret Enhanced". Pretty name of the category where the setting can be found. Can be stringtable entry.
    TRUE, // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {  
        //params ["_value"];
        //setViewDistance _value;
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_Settings_fnc_init;

[
    "Fat_Lurch_ShowTarget", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type. CHECKBOX, EDITBOX, SLIDER, LIST or COLOR
    "Show Target Grid", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    GLT_MOD_NAME, // GLT: was "Turret Enhanced". Pretty name of the category where the setting can be found. Can be stringtable entry.
    TRUE, // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {  
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_Settings_fnc_init;

[
    "Fat_Lurch_MapSlew", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type. CHECKBOX, EDITBOX, SLIDER, LIST or COLOR
    "Allow Map Slew", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    GLT_MOD_NAME, // GLT: was "Turret Enhanced". Pretty name of the category where the setting can be found. Can be stringtable entry.
    TRUE, // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {  
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_Settings_fnc_init;

[
    "Fat_Lurch_Markers", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type. CHECKBOX, EDITBOX, SLIDER, LIST or COLOR
    "Allow Markers", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    GLT_MOD_NAME, // GLT: was "Turret Enhanced". Pretty name of the category where the setting can be found. Can be stringtable entry.
    TRUE, // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {  
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_Settings_fnc_init;

[
    "Fat_Lurch_Grid", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type. CHECKBOX, EDITBOX, SLIDER, LIST or COLOR
    "Allow Slew to Grid", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    GLT_MOD_NAME, // GLT: was "Turret Enhanced". Pretty name of the category where the setting can be found. Can be stringtable entry.
    TRUE, // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {  
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_Settings_fnc_init;

[
    "Fat_Lurch_Measure", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "CHECKBOX", // setting type. CHECKBOX, EDITBOX, SLIDER, LIST or COLOR
    "Allow Measuring", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    GLT_MOD_NAME, // GLT: was "Turret Enhanced". Pretty name of the category where the setting can be found. Can be stringtable entry.
    TRUE, // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {  
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_Settings_fnc_init;

[
    "Fat_Lurch_GridNum", // Internal setting name, should always contain a tag! This will be the global variable which takes the value of the setting.
    "LIST", // setting type. CHECKBOX, EDITBOX, SLIDER, LIST or COLOR
    "Target Grid Digits", // Pretty name shown inside the ingame settings menu. Can be stringtable entry.
    GLT_MOD_NAME, // GLT: was "Turret Enhanced". Pretty name of the category where the setting can be found. Can be stringtable entry.
    [[6,8,10],["6 Digit", "8 Digit", "10 Digit"],0 ], // data for this setting: [min, max, default, number of shown trailing decimals]
    nil, // "_isGlobal" flag. Set this to true to always have this setting synchronized between all clients in multiplayer
    {  
    } // function that will be executed once on mission start and every time the setting is changed.
] call CBA_Settings_fnc_init;


// ==================================================================================
// 2026 Version settings
// ==================================================================================

// ===================== Vehicle types =====================
// Checked by the original fatlurch_fnc_isViewISR, so they switch every Turret Enhanced feature
// (actions, HUD, marking, slewing, laser on map) per vehicle type.
{
	_x params ["_var", "_title", "_tooltip", "_default"];
	[_var, "CHECKBOX", [_title, _tooltip], [GLT_MOD_NAME, "Vehicle Types"], _default, nil, {}] call CBA_Settings_fnc_init;
} forEach [
	["GLT_EnableHelicopters", "Helicopters", "Enable " + GLT_MOD_NAME + " on helicopters (incl. helicopter UAVs)", true],
	["GLT_EnablePlanes",      "Planes",      "Enable " + GLT_MOD_NAME + " on planes (incl. fixed-wing UAVs, jets with targeting pods)", true]
];

// ===================== Markers (SHIFT+1 / 2 / 3 / 4) =====================
// Type/colour lists are built from the game config so every standard marker icon and colour is available.

// --- Marker types: standard map icons + NATO symbols (flags and mission-specific markers left out)
private _typeGroups = [
	["hd_",  ""],
	["mil_", ""],
	["b_",   "NATO Friendly: "],
	["o_",   "NATO Hostile: "],
	["n_",   "NATO Neutral: "],
	["c_",   "NATO Civilian: "],
	["u_",   "NATO Unknown: "]
];
private _typeValues = [];
private _typeLabels = [];
{
	_x params ["_prefix", "_labelPrefix"];
	{
		private _class = configName _x;
		if (
			(toLower _class) find _prefix == 0
			&& {getNumber (_x >> "scope") == 2}
			&& {getText (_x >> "icon") != ""}
			&& {!(_class in _typeValues)}
		) then
		{
			_typeValues pushBack _class;
			private _name = getText (_x >> "name");
			if (_name == "") then {_name = _class};
			_typeLabels pushBack (_labelPrefix + _name);
		};
	} forEach ("true" configClasses (configFile >> "CfgMarkers"));
} forEach _typeGroups;
if !("hd_dot" in _typeValues) then {_typeValues insert [0, ["hd_dot"]]; _typeLabels insert [0, ["Dot"]]};

// --- Marker colours: every selectable map marker colour (map markers cannot use arbitrary RGB)
private _colorValues = [];
private _colorLabels = [];
{
	private _class = configName _x;
	if (getNumber (_x >> "scope") == 2 && {_class != "Default"}) then
	{
		_colorValues pushBack _class;
		private _name = getText (_x >> "name");
		if (_name == "") then {_name = _class};
		_colorLabels pushBack _name;
	};
} forEach ("true" configClasses (configFile >> "CfgMarkerColors"));
{
	if !(_x in _colorValues) then {_colorValues pushBack _x; _colorLabels pushBack _x};
} forEach ["ColorBlue", "ColorRed", "ColorYellow", "ColorGreen"];

// Shared lists (kept for other GLT code)
GLT_markerTypeList  = [_typeValues, _typeLabels];
GLT_markerColorList = [_colorValues, _colorLabels];
GLT_markerSlotCount = 4;

// Refresh the coloured "Mark Target" scroll-menu titles whenever a type/colour changes
private _refreshActions = {
	if (!isNil "GLT_fnc_updateMarkerActions") then {call GLT_fnc_updateMarkerActions};
};

{
	_x params ["_slot", "_defaultColor"];
	private _keyName = format ["SHIFT+%1", _slot];
	private _category = [GLT_MOD_NAME, format ["Marker %1", _slot]];

	[
		format ["GLT_Marker%1Type", _slot],
		"LIST",
		["Icon", format ["Marker icon placed by Mark Target (Marker %1), default key %2 (rebind in Options > Controls > %3)", _slot, _keyName, GLT_MOD_NAME]],
		_category,
		[_typeValues, _typeLabels, (_typeValues find "hd_dot") max 0],
		nil,
		_refreshActions
	] call CBA_Settings_fnc_init;

	[
		format ["GLT_Marker%1Color", _slot],
		"LIST",
		["Color", format ["Marker colour placed by Mark Target (Marker %1), default key %2 (rebind in Options > Controls > %3). Map markers only support the game's marker colours", _slot, _keyName, GLT_MOD_NAME]],
		_category,
		[_colorValues, _colorLabels, (_colorValues find _defaultColor) max 0],
		nil,
		_refreshActions
	] call CBA_Settings_fnc_init;

	[
		format ["GLT_Marker%1Prefix", _slot],
		"EDITBOX",
		["Text Prefix", "Marker text prefix. {Counter} is replaced with the marker number. Typed text is appended after ' - '. Default {Counter} gives '0' / '0 - text'"],
		_category,
		"{Counter}",
		nil,
		{}
	] call CBA_Settings_fnc_init;
} forEach [
	[1, "ColorBlue"],
	[2, "ColorRed"],
	[3, "ColorYellow"],
	[4, "ColorGreen"]
];

[
    "GLT_MarkerSize",
    "SLIDER",
    ["Marker Size", "Size of markers placed by " + GLT_MOD_NAME],
    [GLT_MOD_NAME, "Markers"],
    [0.25, 2, 0.5, 2],
    nil,
    {}
] call CBA_Settings_fnc_init;

[
    "GLT_MarkerPromptText",
    "CHECKBOX",
    ["Prompt for Marker Text", "Open a text box when placing a marker. Enter = place (empty = prefix only), Esc = cancel"],
    [GLT_MOD_NAME, "Markers"],
    true,
    nil,
    {}
] call CBA_Settings_fnc_init;


// ===================== Camera overlay / laser =====================

// Server-wide switches (isGlobal = 1): the server's / mission's value always applies and players can't
// change it. In singleplayer or when hosting, set them in the "Server" tab of Addon Options.
[
    "GLT_MarkerOverlayShow",
    "CHECKBOX",
    ["Enable Camera Marker Overlay", "Server-wide. Allows markers to be drawn as icons in the turret / UAV camera view. Off: no markers in the camera view for anyone (the 'Cycle Camera Overlay' key then only switches friendly lasers on / off via Declutter)."],
    [GLT_MOD_NAME, "Camera Overlay"],
    true,
    1,
    {if (!isNil "GLT_fnc_buildOverlayList") then {call GLT_fnc_buildOverlayList}}
] call CBA_Settings_fnc_init;

[
    "GLT_MarkerOverlayAllowMine",
    "CHECKBOX",
    ["Allow 'My Markers'", "Server-wide. Players may show their own Turret Enhanced markers in the camera view."],
    [GLT_MOD_NAME, "Camera Overlay"],
    true,
    1,
    {if (!isNil "GLT_fnc_buildOverlayList") then {call GLT_fnc_buildOverlayList}}
] call CBA_Settings_fnc_init;

[
    "GLT_MarkerOverlayAllowAll",
    "CHECKBOX",
    ["Allow 'All Map Markers'", "Server-wide. Players may show every icon marker on the map (their own, other players' and the mission's) in the camera view."],
    [GLT_MOD_NAME, "Camera Overlay"],
    true,
    1,
    {if (!isNil "GLT_fnc_buildOverlayList") then {call GLT_fnc_buildOverlayList}}
] call CBA_Settings_fnc_init;

// Player's choice, also changed by the 'Cycle Camera Overlay' key / scroll action. A mode the server doesn't allow falls
// back to the other allowed mode, or to no markers.
[
    "GLT_MarkerOverlayMode",
    "LIST",
    ["Overlay Mode", "What the camera view shows. Declutter: nothing. No markers: only friendly lasers. My markers / All map markers: markers + friendly lasers. The 'Cycle Camera Overlay' key (Options > Controls, default SHIFT+7) and the 'Camera Overlay' scroll-menu action cycle through the modes the server allows."],
    [GLT_MOD_NAME, "Camera Overlay"],
    [[3, 0, 1, 2], ["Declutter (nothing)", "No markers (lasers only)", "My markers", "All map markers"], 2],
    nil,
    {if (!isNil "GLT_fnc_buildOverlayList") then {call GLT_fnc_buildOverlayList}}
] call CBA_Settings_fnc_init;

[
    "GLT_MarkerOverlayEdgeArrows",
    "CHECKBOX",
    ["Show Off-screen Markers at Screen Edge", "When a marker drawn in the camera view is outside the camera's field of view, show an arrow at the edge of the screen pointing towards it"],
    [GLT_MOD_NAME, "Camera Overlay"],
    true,
    nil,
    {}
] call CBA_Settings_fnc_init;

[
    "GLT_LaserMapShow",
    "CHECKBOX",
    ["Show Laser on Map", "Draw a red line from your aircraft / UAV to the laser spot on the map while the laser is on"],
    [GLT_MOD_NAME, "Laser"],
    true,
    nil,
    {}
] call CBA_Settings_fnc_init;

[
    "GLT_LaserMapFriendly",
    "CHECKBOX",
    ["Show Friendly Aircraft Lasers", "Also draw lasers of friendly aircraft on the map, not only your own"],
    [GLT_MOD_NAME, "Laser"],
    false,
    nil,
    {}
] call CBA_Settings_fnc_init;

[
    "GLT_LaserMapSkipMQ9",
    "CHECKBOX",
    ["Skip MQ-9 Lasers", "Don't draw the laser on the map for MQ-9 Reapers (the MQ-9 mod already draws its own)"],
    [GLT_MOD_NAME, "Laser"],
    true,
    nil,
    {}
] call CBA_Settings_fnc_init;

[
    "GLT_LaserOverlayAllow",
    "CHECKBOX",
    ["Allow Friendly Lasers in Camera View", "Server-wide. Players may see where other friendly players, soldiers and vehicles are lasing, drawn in their turret / UAV camera view."],
    [GLT_MOD_NAME, "Laser"],
    true,
    1,
    {if (!isNil "GLT_fnc_buildOverlayList") then {call GLT_fnc_buildOverlayList}}
] call CBA_Settings_fnc_init;

[
    "GLT_LaserOverlayShow",
    "CHECKBOX",
    ["Show Friendly Lasers in Camera View", "Draw the laser spots of other friendly players, soldiers and vehicles (designators switched on) in the camera view, labelled with the lasing group's name and, with ACE, the laser code. Only spots your camera can see are shown (in view and not hidden by terrain or buildings). The laser of the camera you are looking through is not marked (it shows its own); your own soldier or aircraft lasing is shown when you use another camera, e.g. a UAV."],
    [GLT_MOD_NAME, "Laser"],
    true,
    nil,
    {if (!isNil "GLT_fnc_buildOverlayList") then {call GLT_fnc_buildOverlayList}}
] call CBA_Settings_fnc_init;

[
    "GLT_LaserOverlayIconSize",
    "SLIDER",
    ["Friendly Laser Icon Size", "Size of the laser spot icon in the camera view (markers use 0.8)."],
    [GLT_MOD_NAME, "Laser"],
    [0.2, 1.5, 0.6, 2]
] call CBA_Settings_fnc_init;

[
    "GLT_LaserOverlayTextColor",
    "COLOR",
    ["Friendly Laser Label Colour", "Colour of the group name / laser code shown under the laser spot icon. The label keeps its black outline."],
    [GLT_MOD_NAME, "Laser"],
    [1, 0.15, 0.15, 1]
] call CBA_Settings_fnc_init;

