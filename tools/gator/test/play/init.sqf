// Walk-around mission for the G/ATOR: python tools/gator/test/run.py --play
// (add --full --world=Malden for the whole PTF modset on a real map).
// One radar, packed up, in front of you at its work side. Use the ACE interactions on it
// (Windows key by default): each leg, the generator, then the G/ATOR panel on the box.
// On a real map it stands on clear, flat ground near the map's main airfield; you have a
// Billet tablet and a toolkit, and (with PTF loaded) a PTF MRZR to tow it with.
waitUntil {time > 0};

// The trailer's own spot first: flat (5% at most) and 10 m clear of any object, so it never
// spawns into a wall, a tree or a slope it rolls off (it once blew up on spawn on Malden).
private _spot = player getRelPos [14, 0];
if (worldName != "VR") then {
	private _centre = switch (toLowerANSI worldName) do {
		case "malden": {[8100, 10000, 0]};
		case "stratis": {[1950, 5750, 0]};
		case "altis": {[14600, 16700, 0]};
		case "tanoa": {[6900, 7300, 0]};
		default {[worldSize / 2, worldSize / 2, 0]};
	};
	_spot = [_centre, 0, 800, 10, 0, 0.05, 0] call BIS_fnc_findSafePos;
	setDate [2035, 7, 18, 10, 0];
	0 setOvercast 0.2;
	0 setFog 0;
	forceWeatherChange;
};
_spot = [_spot select 0, _spot select 1, 0];

{player addItem _x} forEach ["blk_tabletItem", "ToolKit"];
player setVariable ["ace_isEngineer", 2, true];

private _radar = createVehicle ["PTF_GATOR", _spot, [], 0, "CAN_COLLIDE"];
// unhurt while it settles onto the ground
_radar allowDamage false;
_radar setDir random 360;
_radar setPosATL _spot;
[{_this allowDamage true}, _radar, 15] call CBA_fnc_waitAndExecute;
[{diag_log format ["[PTF_GATOR] walk-around: G/ATOR settled, damage %1, tilt %2", damage _this, round (acos ((vectorUp _this) select 2))]}, _radar, 20] call CBA_fnc_waitAndExecute;
player setVariable ["PTF_GATOR_radar", _radar];
// You, at its work side (the box's left), facing it.
player setPosATL ((_radar modelToWorld [-5, 0, 0]) vectorMultiply [1, 1, 0]);
player setDir (player getDir _radar);
// A PTF MRZR to tow it with, somewhere empty nearby.
if (isClass (configFile >> "CfgVehicles" >> "PTF_MRZR4")) then {
	private _at = (_radar getRelPos [18, 200]) findEmptyPosition [0, 60, "PTF_MRZR4"];
	if (_at isNotEqualTo []) then {
		private _mrzr = createVehicle ["PTF_MRZR4", _at, [], 0, "NONE"];
		_mrzr setDir getDir _radar;
	};
};
// Zeus (Y), for the PTF G/ATOR modules: enemy batteries, an ARM at the G/ATOR.
private _zeus = (createGroup sideLogic) createUnit ["ModuleCurator_F", [0, 0, 0], [], 0, "NONE"];
_zeus setVariable ["Addons", 3, true];
player assignCurator _zeus;
_zeus addCuratorEditableObjects [[_radar], true];

hint parseText "<t size='1.2'>G/ATOR walk-around</t><br/><br/>ACE interact (Win key) on each leg, the generator (front), then the box's left side (G/ATOR): Raise array, Start antenna rotation, Take out SATCOM antenna (drag it 3 m+ away).<br/><br/>Operator: G/ATOR > Take out operator computer, set it down, then on the computer: Take manual control, Open G/ATOR console.<br/><br/>Zeus (Y) > Modules > PTF G/ATOR: enemy batteries, harass, ARM at the G/ATOR.";
