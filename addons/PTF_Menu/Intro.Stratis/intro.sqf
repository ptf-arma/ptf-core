private _tracks = ["LeadTrack01_F_Mark","LeadTrack02_F_Mark","LeadTrack02_F_EXP","LeadTrack03_F_EXP"];
/////////
// This is War (Marksmen Remix)
// Marksmen DLC: Lead Track 02 (Into the Sun)
// An Unknown Enemy
// No Time For Questions
/// tracks
enableEnvironment true;

// selectRandom rather than a hardcoded count, so adding a track here cannot
// leave the new entry unreachable (that is how initIntro.sqf lost "Menu2").
private _track = selectRandom _tracks;

playMusic _track;

	["_display"] call BIS_fnc_rscLayer cutRsc ["RscTitleDisplayEmpty", "PLAIN"];
	     private _display1 = uiNamespace getVariable ["RscTitleDisplayEmpty", displayNull];
		private _display = _display1 ctrlCreate ["RscPicture", -1];
		_display ctrlSetTextColor [1,1,1,1];
		_display ctrlSetPosition [safeZoneX, safeZoneY, safeZoneW, safeZoneH];
		_display ctrlCommit 0;

while {true} do {
		// PTF_Textures\Backgrounds holds background1..background20 with no
		// background17. "floor random 20" yielded 0-19 and the 0 -> 1 fix-up
		// made background1 twice as likely while background20 was unreachable,
		// so pick evenly from the indices that actually ship.
		private _count = selectRandom [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,19,20];
		private _displayBackground = format["\z\PTF\addons\PTF_Textures\Backgrounds\background%1.paa",_count];
		_display ctrlSetText _displayBackground;
		sleep 10;
};
