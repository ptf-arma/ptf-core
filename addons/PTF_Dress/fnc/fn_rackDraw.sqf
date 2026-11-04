/*
 * Fills a rack model's slots, per MCO 1020.34H: three ribbons to a row, senior ribbon on the
 * wearer's right at the top, and a short row on top and centred. Repeat awards wear star
 * devices, gold for each repeat and silver in place of five gold, as Billet's own rack does.
 *
 * Holds 15 ribbons, junior ribbons dropping off first. Awards the mod has no art for are left
 * out, so a new award appears once tools/fetch-dress-ribbons.py and the generator have rerun.
 *
 * Slots run in rows from the bottom, five to a row: three full columns, then a short row's two.
 *
 * Params: [rack model, rack], rack as "awardId:count" pairs.
 */
#define SLOTS 25
params ["_plate", ["_rack", "", [""]]];

private _config = configFile >> "CfgPTFDressRibbons";
private _slots = [];
{
    private _pair = _x splitString ":";
    private _class = _config >> ("r_" + (((_pair param [0, ""]) splitString "-") joinString "_"));
    if (isClass _class) then {
        _slots pushBack [getText (_class >> "picture"), parseNumber (_pair param [1, "1"])];
    };
} forEach (_rack splitString ",");
_slots = _slots select [0, 15];

for "_i" from 0 to (SLOTS * 2 - 1) do { _plate setObjectTexture [_i, ""] };

private _count = count _slots;
private _rows = ceil (_count / 3);
private _first = [_count mod 3, 3] select (_count mod 3 == 0);
private _devices = getText (_config >> "device_path");
private _i = 0;
for "_row" from 0 to (_rows - 1) do {
    private _n = [3, _first] select (_row == 0);
    private _fromBottom = _rows - 1 - _row;
    private _columns = [[1], [3, 4], [0, 1, 2]] select (_n - 1);
    for "_col" from 0 to (_n - 1) do {
        (_slots select _i) params ["_path", "_held"];
        private _slot = _fromBottom * 5 + (_columns select _col);
        _plate setObjectTexture [_slot, _path];
        private _silver = floor ((_held - 1) / 5) min 2;
        private _gold = (_held - 1) mod 5;
        if (_silver + _gold > 0) then {
            _plate setObjectTexture [SLOTS + _slot, format ["%1%2%3_ca.paa", _devices, _silver, _gold]];
        };
        _i = _i + 1;
    };
};
