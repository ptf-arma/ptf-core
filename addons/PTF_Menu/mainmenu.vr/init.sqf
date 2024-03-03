 _backgrounds = ["background1.paa", "background2.paa", "background3.paa", "background4.paa", "background5.paa", "background6.paa", "background7.paa", "background8.paa", "background9.paa", "background10.paa", "background11.paa", "background12.paa", "background13.paa", "background14.paa", "background15.paa", "background16.paa", "background17.paa", "background18.paa", "background19.paa", "background20.paa"];

while {true} do
{
 _display = findDisplay 46 createDisplay "RscDisplayEmpty";
_display = _display ctrlCreate ["RscPicture", -1];
_display ctrlSetTextColor [1,1,1,1];
_display ctrlSetPosition [safeZoneX, safeZoneY, safeZoneW, safeZoneH];
_display ctrlCommit 0;
_display ctrlSetText "";

enableEnvironment false;
showCinemaBorder false;

for "_i" From 1 to 500 do {
_count = floor random 20;
if (_count = 0) then {
_count = _count + 1;
};
_displayBackground = format["PTF_Textures\Backgrounds\background%1.paa",_count];
_display ctrlSetText _displayBackground;
sleep 20
};
};





