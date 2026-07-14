_tracks = ["LeadTrack01_F_Mark","LeadTrack02_F_Mark","LeadTrack02_F_EXP","LeadTrack03_F_EXP","Menu1","Menu2"];
/////////
// This is War (Marksmen Remix)
// Marksmen DLC: Lead Track 02 (Into the Sun)
// An Unknown Enemy
// No Time For Questions
/// tracks
enableEnvironment true;

_track = _tracks select floor random 5;
playMusic _track;

private _ehID = addMusicEventHandler ["MusicStop", {
	_tracks = ["LeadTrack01_F_Mark","LeadTrack02_F_Mark","LeadTrack02_F_EXP","LeadTrack03_F_EXP","Menu1","Menu2"];
	_track = _tracks select floor random 5;
	playMusic _track;
}];


	["_display"] call BIS_fnc_rscLayer cutRsc ["RscTitleDisplayEmpty", "PLAIN"];
	     _display1 = uiNamespace getVariable ["RscTitleDisplayEmpty", displayNull];
		_display = _display1 ctrlCreate ["RscPicture", -1];
		_display ctrlSetTextColor [1,1,1,1];
		_display ctrlSetPosition [safeZoneX, safeZoneY, safeZoneW, safeZoneH];
		_display ctrlCommit 0;

while {true} do {
		_count = floor random 20;
		if (_count == 0) then {
		_count = _count + 1;
		};
		_displayBackground = format["\z\PTF\addons\PTF_Textures\Backgrounds\background%1.paa",_count];
		_display ctrlSetText _displayBackground;
		sleep 10;
};












