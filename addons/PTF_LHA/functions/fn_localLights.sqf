/*
 * Make or remove this machine's light sources for one LHA light group. Sent to every
 * machine by PTF_LHA_fnc_setLights. The lights match Peral's LHA_fnc_lha_Lights; they
 * are local objects, so each player's game needs its own.
 *
 * Arguments:
 * 0: The ship <OBJECT>
 * 1: Light group <STRING>
 * 2: 1 for on, 0 for off <NUMBER>
 */
params ["_ship", "_group", "_state"];

if (!hasInterface || {isNull _ship}) exitWith {};

// Remove this group's lights first, so switching on twice can't stack them.
private _var = "PTF_LHA_lights_" + _group;
{deleteVehicle _x} forEach (_ship getVariable [_var, []]);
_ship setVariable [_var, nil];
if (_state != 1) exitWith {};

// A player joining mid-mission can get this before the ship's parts are known.
// remoteExec runs it scheduled, so it can wait for them.
private _t = diag_tickTime;
waitUntil {(_ship getVariable ["bis_carrierparts", []]) isNotEqualTo [] || {diag_tickTime - _t > 30} || {isNull _ship}};
if (isNull _ship) exitWith {};

private _range = getNumber (configFile >> "PTF_LHA_LightGroups" >> _group >> "range");
private _lightsCfg = getArray (configFile >> "CfgVehicles" >> "Peral_LHA" >> _group);
private _lights = [];
{
	private _part = _x select 0;
	{
		_x params ["_class", "_prefix", "_first", "_last"];
		if (typeOf _part == _class) then {
			for "_i" from _first to _last do {
				private _point = format ["%1%2", _prefix, [str _i, "0" + str _i] select (_i < 10)];
				private _light = "#lightpoint" createVehicleLocal [0, 0, 0];
				_light setLightConePars [180, 0, 1];
				_light setLightIntensity 0.2;
				_light setLightColor [2500, 4000, 6000];
				_light setLightAttenuation [0.1, 0, 1, 0.5, 0.1, _range];
				_light attachTo [_part, [0, 0, 0], _point];
				_lights pushBack _light;
			};
		};
	} forEach _lightsCfg;
} forEach (_ship getVariable ["bis_carrierparts", []]);

_ship setVariable [_var, _lights];
