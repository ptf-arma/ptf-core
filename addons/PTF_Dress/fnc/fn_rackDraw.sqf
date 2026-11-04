/*
 * Draws a rack into a UI texture: three ribbons to a row, senior ribbon first,
 * with a short row on top and centred. Repeat awards wear star devices, gold for
 * each repeat and silver in place of five gold, as Billet's own rack does.
 *
 * The model's rack surface holds three rows at full size. Longer racks shrink to
 * fit. Awards the mod has no art for are left out, so a new award appears once
 * tools/fetch-dress-ribbons.py and the generator have been rerun.
 *
 * Params: [display, rack], rack as "awardId:count" pairs.
 */
params ["_display", ["_rack", "", [""]]];

{ctrlDelete _x} forEach allControls _display;

private _config = configFile >> "CfgPTFDressRibbons";
private _slots = [];
{
    private _pair = _x splitString ":";
    private _class = _config >> ("r_" + (((_pair param [0, ""]) splitString "-") joinString "_"));
    if (isClass _class) then {
        _slots pushBack [getText (_class >> "picture"), parseNumber (_pair param [1, "1"])];
    };
} forEach (_rack splitString ",");

private _bg = _display ctrlCreate ["RscText", -1];
_bg ctrlSetPosition [0, 0, 1, 1];
_bg ctrlSetBackgroundColor getArray (_config >> "background");
_bg ctrlCommit 0;

private _picture = {
    params ["_path", "_x0", "_y0", "_w", "_h"];
    private _c = _display ctrlCreate ["RscPicture", -1];
    _c ctrlSetPosition [_x0, _y0, _w, _h];
    _c ctrlSetText _path;
    _c ctrlCommit 0;
};

private _count = count _slots;
private _rows = ceil (_count / 3);
// The size at which three rows fill the surface from its lower edge.
private _h = if (_rows > 3) then { 0.84 / _rows } else { 0.28 };
private _w = _h * (1 / 3) / 0.28;
private _top = 1 - _rows * _h;
private _first = [_count mod 3, 3] select (_count mod 3 == 0);
private _i = 0;
for "_row" from 0 to (_rows - 1) do {
    private _n = [3, _first] select (_row == 0);
    for "_col" from 0 to (_n - 1) do {
        (_slots select _i) params ["_path", "_held"];
        private _x0 = 0.5 + (_col - _n / 2) * _w;
        private _y0 = _top + _row * _h;
        [_path, _x0 + 0.002, _y0 + 0.008, _w - 0.004, _h - 0.016] call _picture;

        private _silver = floor ((_held - 1) / 5);
        private _gold = (_held - 1) mod 5;
        private _stars = _silver + _gold;
        if (_stars > 0) then {
            private _size = _h * 0.62;
            private _starW = _size * 0.25;
            private _sx = _x0 + _w / 2 - _stars * _starW / 2;
            for "_s" from 0 to (_stars - 1) do {
                private _kind = ["device_gold", "device_silver"] select (_s < _silver);
                [getText (_config >> _kind), _sx + _s * _starW, _y0 + (_h - _size) / 2, _starW, _size] call _picture;
            };
        };
        _i = _i + 1;
    };
};
displayUpdate _display;
