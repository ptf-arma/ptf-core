// Server settings (Addon Options > Paramarine Task Force > G/ATOR).
[
	"PTF_GATOR_cbError", "SLIDER",
	["Counter-battery error (%)", "How far off a firing point traced from one round is, on average, as a share of its distance from the G/ATOR (4: 40 m at 1 km). A track of several rounds is more accurate: this over the square root of its rounds."],
	["Paramarine Task Force", "G/ATOR"],
	[0, 20, 4, 1],
	1, // global: the server's value is everyone's
	{},
	false
] call CBA_fnc_addSetting;
[
	"PTF_GATOR_setupTime", "CHECKBOX",
	["Setting up takes time", "Lowering and raising the legs and the array, starting the generator and reeling in the SATCOM cable are worked by hand for as long as the trailer takes to do them (ACE progress bars). Off: each happens at a click."],
	["Paramarine Task Force", "G/ATOR"],
	true,
	1,
	{},
	false
] call CBA_fnc_addSetting;
[
	"PTF_GATOR_enemyHunt", "CHECKBOX",
	["Enemy counter-fire on a G/ATOR", "A G/ATOR that transmits long enough lets the enemy find it (its crew isn't told). Once they have it, an enemy mortar team is sent every two minutes: it fires on the G/ATOR and is gone before counter-fire. It never takes over the mission's own artillery."],
	["Paramarine Task Force", "G/ATOR"],
	false,
	1,
	{},
	false
] call CBA_fnc_addSetting;
