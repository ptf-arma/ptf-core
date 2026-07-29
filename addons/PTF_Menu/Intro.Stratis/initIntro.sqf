// Entry point for the main-menu scene wired up in ..\config.cpp
// (CfgWorlds >> <world> >> cutscenes[] -> CfgMissions >> Cutscenes >> mymainmenu).
// The engine runs "initIntro.sqf" by name when a cutscene scene starts; there is
// no execVM anywhere and no init.sqf involved. Every stock BI menu scene ships the
// same two files and nothing else (e.g. a3\map_enoch_scenes_f\scenes\
// Enoch_intro1.Enoch = initIntro.sqf + mission.sqm), so do NOT rename this file.
private _tracks = ["LeadTrack01_F_Mark","LeadTrack02_F_Mark","LeadTrack02_F_EXP","LeadTrack03_F_EXP","Menu1","Menu2"];
/////////
// This is War (Marksmen Remix)
// Marksmen DLC: Lead Track 02 (Into the Sun)
// An Unknown Enemy
// No Time For Questions
/// tracks
enableEnvironment true;

private _track = selectRandom _tracks;
playMusic _track;

// The MusicStop handler outlives the scene, so this script has to clear the one
// the previous visit to the main menu registered. Without it every return adds
// another handler and n handlers start n tracks at once on each track end.
// The id lives in uiNamespace because missionNamespace is wiped between scenes.
private _oldEHID = uiNamespace getVariable ["PTF_MenuMusicEH", -1];
if (_oldEHID >= 0) then {
	removeMusicEventHandler ["MusicStop", _oldEHID];
};

uiNamespace setVariable ["PTF_MenuMusicEH", addMusicEventHandler ["MusicStop", {
	private _tracks = ["LeadTrack01_F_Mark","LeadTrack02_F_Mark","LeadTrack02_F_EXP","LeadTrack03_F_EXP","Menu1","Menu2"];
	private _track = selectRandom _tracks;
	playMusic _track;
}]];


	["_display"] call BIS_fnc_rscLayer cutRsc ["RscTitleDisplayEmpty", "PLAIN"];
	     private _display1 = uiNamespace getVariable ["RscTitleDisplayEmpty", displayNull];
		private _display = _display1 ctrlCreate ["RscPicture", -1];
		_display ctrlSetTextColor [1,1,1,1];
		_display ctrlSetPosition [safeZoneX, safeZoneY, safeZoneW, safeZoneH];
		_display ctrlCommit 0;

// PTF_Textures\Backgrounds ships Background1..Background20 with no Background17.
// The gap cannot be closed by renumbering the files: PTF_Textures\config.cpp names
// each one individually for its NCA_loadingBackground* loading screens, so a rename
// would break those. Derive the pool from the range minus the known gaps instead of
// hand-maintaining a literal list - adding a background means dropping in the next
// Background<n>.paa and bumping _highest, nothing else.
private _highest = 20;
private _gaps = [17];
private _backgrounds = [];
for "_i" from 1 to _highest do {
	if (!(_i in _gaps)) then {_backgrounds pushBack _i};
};

while {true} do {
		private _count = selectRandom _backgrounds;
		// Capital B matches the filenames on disk. A lowercase path still resolves
		// on Windows but not on a case-sensitive filesystem.
		private _displayBackground = format["\z\PTF\addons\PTF_Textures\Backgrounds\Background%1.paa",_count];
		_display ctrlSetText _displayBackground;
		sleep 10;
};
