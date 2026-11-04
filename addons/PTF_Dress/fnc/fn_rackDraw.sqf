/*
 * Draws a rack on a square plate's texture, per MCO 1020.34H: three ribbons to a row,
 * each 1 3/8 by 3/8 inches, senior ribbon on the wearer's right at the top, and a short
 * row on top and centred. The plate's centre is the rack's bottom edge, so the rows
 * build upward from there. Repeat awards wear star devices, gold for each repeat and
 * silver in place of five gold, as Billet's own rack does.
 *
 * Five full rows fit. Awards the mod has no art for are left out, so a new award
 * appears once tools/fetch-dress-ribbons.py and the generator have been rerun.
 *
 * Params: [display, rack], rack as "awardId:count" pairs.
 */
params ["_display", ["_rack", "", [""]]];

{ctrlDelete _x} forEach (_display getVariable ["PTF_Dress_pictures", []]);
private _pictures = [];
// The stock display's vignette would otherwise show on the plate as a faint square.
{_x ctrlSetTextColor [0, 0, 0, 0]; _x ctrlSetFade 1; _x ctrlCommit 0} forEach allControls _display;

private _config = configFile >> "CfgPTFDressRibbons";
private _slots = [];
{
    private _pair = _x splitString ":";
    private _class = _config >> ("r_" + (((_pair param [0, ""]) splitString "-") joinString "_"));
    if (isClass _class) then {
        _slots pushBack [getText (_class >> "picture"), parseNumber (_pair param [1, "1"])];
    };
} forEach (_rack splitString ",");

private _picture = {
    params ["_path", "_x0", "_y0", "_w", "_h"];
    private _c = _display ctrlCreate ["RscPicture", -1];
    _c ctrlSetPosition [_x0, _y0, _w, _h];
    _c ctrlSetText _path;
    _c ctrlCommit 0;
    _pictures pushBack _c;
};

private _w = 1 / 3;
private _h = _w * (3 / 8) / (11 / 8);
private _count = count _slots;
private _rows = ceil (_count / 3);
private _first = [_count mod 3, 3] select (_count mod 3 == 0);
private _i = 0;
for "_row" from 0 to (_rows - 1) do {
    private _n = [3, _first] select (_row == 0);
    private _y0 = 0.5 - (_rows - _row) * _h;
    for "_col" from 0 to (_n - 1) do {
        (_slots select _i) params ["_path", "_held"];
        private _x0 = 0.5 + (_col - _n / 2) * _w;
        [_path, _x0, _y0, _w, _h] call _picture;

        private _silver = floor ((_held - 1) / 5);
        private _gold = (_held - 1) mod 5;
        private _stars = _silver + _gold;
        if (_stars > 0) then {
            private _size = _h * 0.7;
            private _sx = _x0 + _w / 2 - _stars * _size / 2;
            for "_s" from 0 to (_stars - 1) do {
                private _kind = ["device_gold", "device_silver"] select (_s < _silver);
                [getText (_config >> _kind), _sx + _s * _size, _y0 + (_h - _size) / 2, _size, _size] call _picture;
            };
        };
        _i = _i + 1;
    };
};
_display setVariable ["PTF_Dress_pictures", _pictures];
displayUpdate _display;
