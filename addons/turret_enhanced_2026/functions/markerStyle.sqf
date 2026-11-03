/*
	GLT_fnc_markerStyle  (Turret Enhanced 2026 Version)
	Returns the icon texture and RGBA colour used to draw a marker (camera overlay, marker list).
	Results are cached per type/colour pair because this runs every frame.

	Params: _type <STRING> CfgMarkers class, _color <STRING> CfgMarkerColors class (or "Default")
	Returns: [_iconPath, _rgba]
*/

params [["_type", "", [""]], ["_color", "Default", [""]]];

if (isNil "GLT_styleCache") then {GLT_styleCache = createHashMap};

private _key = _type + "|" + _color;
private _cached = GLT_styleCache get _key;
if (!isNil "_cached") exitWith {_cached};

private _typeCfg = configFile >> "CfgMarkers" >> _type;
private _icon = getText (_typeCfg >> "icon");

private _raw = if (_color == "Default" || {!isClass (configFile >> "CfgMarkerColors" >> _color)}) then
{
	getArray (_typeCfg >> "color")
}
else
{
	getArray (configFile >> "CfgMarkerColors" >> _color >> "color")
};

private _rgba = _raw apply {if (_x isEqualType "") then {call compile _x} else {_x}};
if (count _rgba < 3) then {_rgba = [1, 1, 1, 1]};
if (count _rgba < 4) then {_rgba pushBack 1};

private _result = [_icon, _rgba];
GLT_styleCache set [_key, _result];
_result
