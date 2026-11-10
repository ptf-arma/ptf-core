/*
 * Turn one of the LHA's light groups on or off for everyone. Called by the light
 * switch actions (CfgVehicles.hpp) on the machine of whoever used the switch.
 *
 * Peral's LHA_fnc_lha_Lights made the light sources with createVehicleLocal on that
 * machine only, while switching the night materials for everyone: other players,
 * and anyone who joined later, saw the room go to night materials with no light.
 * Here the materials and switches change once for everyone, and every machine with
 * a screen makes its own light sources, joining players included.
 *
 * Arguments:
 * 0: The LHA part the switch is on <OBJECT>
 * 1: Light group, as named in Peral_LHA's config and PTF_LHA_LightGroups <STRING>
 * 2: 1 for on, 0 for off <NUMBER>
 */
params ["_part", "_group", "_state"];

private _ship = _part getVariable ["LHA_Obj", objNull];
if (isNull _ship) exitWith {};
private _parts = (_ship getVariable ["bis_carrierparts", []]) apply {_x select 0};
private _groupCfg = configFile >> "PTF_LHA_LightGroups" >> _group;
if (_parts isEqualTo [] || {!isClass _groupCfg}) exitWith {};

// Every switch for this group, so the island's two switches agree.
{
	_x params ["_class", "_source"];
	{
		if (typeOf _x == _class) then {_x animateSource [_source, _state, true]};
	} forEach _parts;
} forEach getArray (_groupCfg >> "switches");

// Night materials while lit, as Peral's function does. Only the ship's parts: the
// group's material list can also name the root ship, and Peral's never applied that
// entry (it would cover the briefing screens).
private _materials = getArray (configFile >> "CfgVehicles" >> "Peral_LHA" >> (_group + "RVMatts"));
{
	private _partObj = _x;
	{
		_x params ["_class", "_list"];
		if (typeOf _partObj == _class) then {
			{
				_x params ["_index", "_path"];
				_partObj setObjectMaterialGlobal [_index, ["Peral_LHA\data\rvmat\lha_details_night.rvmat", _path] select (_state != 1)];
			} forEach _list;
		};
	} forEach _materials;
} forEach _parts;

// The light sources, on every machine. One JIP entry per ship and group, replaced by
// each switch, so a joining player gets only the latest state.
[_ship, _group, _state] remoteExec ["PTF_LHA_fnc_localLights", 0, format ["PTF_LHA_lights_%1_%2", netId _ship, _group]];
