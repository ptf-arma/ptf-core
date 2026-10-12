/*
	GLT_fnc_friendlyUnits  [GLT] Goltred update - not part of the original Turret Enhanced by Fat_Lurch.
	Rebuilds GLT_friendlyUnits, the friendly datalinked vehicles drawn with their NATO symbol in the camera
	view by GLT_fnc_drawUnitOverlay. Runs twice a second from GLT_fnc_overlayInit, only
	while the player is in a camera view and unit icons are on (GLT_fnc_overlayModes, not in Declutter).

	NATO type per vehicle class (cached), symbol = CfgMarkers "<side prefix><type>" (b_ / o_ / n_ / c_),
	falling back to "<prefix>unknown":
		UAV / UGV -> uav            plane -> plane            helicopter -> air        boat -> naval
		artillery (artilleryScanner) -> art, static mortar -> mortar (other static weapons not shown)
		medical (attendant) -> med   repair -> maint           fuel / ammo -> support
		tank: armor, or mech_inf if it carries 4+ passengers (tracked APC / IFV)
		wheeled APC -> mech_inf     other cars -> motor_inf
	Colour: the side's map colour (BIS_fnc_sideColor).
	Shown: vehicles that share their position on YOUR side's data link, following the engine: a vehicle with
	vehicleReportOwnPosition on shares its position "via datalink with the Side center" (its own side only), so
	the check is: vehicleReportOwnPosition AND the vehicle's side == your side. Which vehicles report is set up
	by the mission (Eden "Data Link" attributes, defaults from the vehicle config).
	Skipped: the vehicle whose camera you're using, empty / destroyed vehicles, anything beyond the max distance.
	Infantry never reports on the data link, so it is never marked.

	Settings (Friendly Units): GLT_UnitOverlayAllow (server-wide), GLT_UnitOverlayShow, GLT_UnitOverlayRange,
	GLT_UnitOverlayIconSize, GLT_UnitOverlayLabels (players).

	Result: GLT_friendlyUnits = [[_object, _icon, _rgba, _label], ...]
*/

if (!hasInterface) exitWith {};

GLT_friendlyUnits = [];

if (!((call GLT_fnc_overlayModes) select 4)) exitWith {};
private _camVeh = call GLT_fnc_getISRVehicle;
if (isNull _camVeh) exitWith {};

private _range = missionNamespace getVariable ["GLT_UnitOverlayRange", 4000];
private _labels = missionNamespace getVariable ["GLT_UnitOverlayLabels", true];
private _camPos = positionCameraToWorld [0, 0, 0];

if (isNil "GLT_natoTypeCache") then {GLT_natoTypeCache = createHashMap};
if (isNil "GLT_natoIconCache") then {GLT_natoIconCache = createHashMap};
if (isNil "GLT_sideColorCache") then {GLT_sideColorCache = createHashMap};

// NATO type of a vehicle class ("" = not shown)
private _natoType = {
	params ["_veh"];
	private _type = typeOf _veh;
	private _cached = GLT_natoTypeCache get _type;
	if (!isNil "_cached") exitWith {_cached};
	private _cfg = configOf _veh;
	private _arty = getNumber (_cfg >> "artilleryScanner") == 1;
	private _result = switch (true) do
	{
		case (unitIsUAV _veh): {"uav"};
		case (_veh isKindOf "Plane"): {"plane"};
		case (_veh isKindOf "Helicopter"): {"air"};
		case (_veh isKindOf "Ship"): {"naval"};
		case (_veh isKindOf "StaticWeapon"): {["", "mortar"] select _arty};
		case (_arty): {"art"};
		case (getNumber (_cfg >> "attendant") > 0): {"med"};
		case (getNumber (_cfg >> "transportRepair") > 0): {"maint"};
		case (getNumber (_cfg >> "transportFuel") > 0 || {getNumber (_cfg >> "transportAmmo") > 0}): {"support"};
		case (_veh isKindOf "Tank"): {["armor", "mech_inf"] select (getNumber (_cfg >> "transportSoldier") >= 4)};
		case (_veh isKindOf "Wheeled_APC_F"): {"mech_inf"};
		case (_veh isKindOf "Car"): {"motor_inf"};
		default {""};
	};
	GLT_natoTypeCache set [_type, _result];
	_result
};

// Icon texture for a side + NATO type, with "<prefix>unknown" fallback
private _iconFor = {
	params ["_side", "_type"];
	private _prefix = switch (_side) do
	{
		case west: {"b_"};
		case east: {"o_"};
		case independent: {"n_"};
		default {"c_"};
	};
	private _key = _prefix + _type;
	private _cached = GLT_natoIconCache get _key;
	if (!isNil "_cached") exitWith {_cached};
	private _marker = _key;
	if (!isClass (configFile >> "CfgMarkers" >> _marker)) then {_marker = _prefix + "unknown"};
	if (!isClass (configFile >> "CfgMarkers" >> _marker)) then {_marker = "b_unknown"};
	private _icon = getText (configFile >> "CfgMarkers" >> _marker >> "icon");
	GLT_natoIconCache set [_key, _icon];
	_icon
};

private _colorFor = {
	params ["_side"];
	private _key = str _side;
	private _cached = GLT_sideColorCache get _key;
	if (!isNil "_cached") exitWith {_cached};
	private _rgba = +(_side call BIS_fnc_sideColor);
	if (count _rgba < 4) then {_rgba pushBack 1};
	_rgba set [3, 1];
	GLT_sideColorCache set [_key, _rgba];
	_rgba
};

private _mySide = side group player;	// the data link network you are on

// --- Crewed, datalinked vehicles
{
	private _veh = _x;
	if (_veh != _camVeh && {alive _veh} && {((crew _veh) findIf {alive _x}) >= 0} && {(_veh distance _camPos) <= _range}
		&& {vehicleReportOwnPosition _veh}) then
	{
		private _side = side group effectiveCommander _veh;
		if (_side isEqualTo _mySide) then
		{
			private _type = [_veh] call _natoType;
			if (_type != "") then
			{
				GLT_friendlyUnits pushBack [_veh, [_side, _type] call _iconFor, [_side] call _colorFor,
					["", groupId group effectiveCommander _veh] select _labels];
			};
		};
	};
} forEach vehicles;
