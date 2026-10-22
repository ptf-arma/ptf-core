/*
	GLT_fnc_markerSlotInfo  (Turret Enhanced 2026 Version)
	Resolves the CBA settings for a marker slot (1..3) into everything needed to place the
	marker and to label it in menus.

	Params: _slot <NUMBER> 1 to 4
	Returns: [_type, _color, _typeName, _colorName, _hexColor, _isDark]

	Usage: ([2] call GLT_fnc_markerSlotInfo) params ["_type", "_color", "_typeName", "_colorName", "_hex", "_isDark"];
*/

params [["_slot", 1, [0]]];

private _defaultColors = ["ColorBlue", "ColorRed", "ColorYellow", "ColorGreen"];

private _type  = missionNamespace getVariable [format ["GLT_Marker%1Type", _slot], "hd_dot"];
private _color = missionNamespace getVariable [format ["GLT_Marker%1Color", _slot], _defaultColors param [_slot - 1, "ColorBlue"]];

// Fall back to safe defaults if a configured class does not exist (e.g. removed by a mod)
if (!isClass (configFile >> "CfgMarkers" >> _type)) then {_type = "hd_dot"};
if (!isClass (configFile >> "CfgMarkerColors" >> _color)) then {_color = _defaultColors param [_slot - 1, "ColorBlue"]};

private _typeCfg  = configFile >> "CfgMarkers" >> _type;
private _colorCfg = configFile >> "CfgMarkerColors" >> _color;

private _typeName  = getText (_typeCfg >> "name");
private _colorName = getText (_colorCfg >> "name");
if (_typeName == "") then {_typeName = _type};
if (_colorName == "") then {_colorName = _color};

// Marker colours may contain expressions (e.g. side colours read from the player's profile)
private _rgb = (getArray (_colorCfg >> "color")) apply
{
	if (_x isEqualType "") then {call compile _x} else {_x}
};
if (count _rgb < 3) then {_rgb = [1, 1, 1, 1]};

private _digits = "0123456789ABCDEF" splitString "";
private _hex = "#";
{
	private _v = round (((_x max 0) min 1) * 255);
	_hex = _hex + (_digits select floor (_v / 16)) + (_digits select (_v % 16));
} forEach (_rgb select [0, 3]);

private _luminance = 0.299 * (_rgb select 0) + 0.587 * (_rgb select 1) + 0.114 * (_rgb select 2);

[_type, _color, _typeName, _colorName, _hex, _luminance < 0.25]
