 _backgrounds = ["background1.paa", "background2.paa", "background3.paa", "background4.paa", "background5.paa", "background6.paa", "background7.paa", "background8.paa", "background9.paa", "background10.paa", "background11.paa", "background12.paa", "background13.paa", "background14.paa", "background15.paa", "background16.paa", "background17.paa", "background18.paa", "background19.paa", "background20.paa"];
_tracks = ["LeadTrack01_F_Mark","LeadTrack02_F_Mark","LeadTrack02_F_EXP","LeadTrack03_F_EXP"];
/////////
// This is War (Marksmen Remix)
// Marksmen DLC: Lead Track 02 (Into the Sun)
// An Unknown Enemy	
// No Time For Questions
/// tracks
enableEnvironment true;

_track = _tracks select floor random 4;

playMusic _track;

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
		_displayBackground = format["PTF_Textures\Backgrounds\background%1.paa",_count];
		_display ctrlSetText _displayBackground;
		sleep 10;
};












