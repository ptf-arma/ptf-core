/*
PTF_fnc_formatDaytime
Returns the current in-game daytime as a zero-padded "HHMMSS" string.

Params:
    0: _sep <STRING> - separator inserted between hours, minutes and seconds (default "")

Returns <STRING> - e.g. "134502" (default) or "13 45 02" (separator " ")

a: reyhard (RHS Original), A.Nilsen (PTF Modifications)
*/

params [["_sep",""]];

private _min  = daytime mod 1;
private _hour = daytime - _min;

private _sec = (60 * _min) mod 1;

_hour = (if (_hour <= 9) then {"0"} else {""}) + str _hour;

_min = (60 * _min) - ((60 * _min) mod 1);
_min = (if (_min <= 9) then {"0"} else {""}) + str _min;

_sec = (60 * _sec) - ((60 * _sec) mod 1);
_sec = (if (_sec <= 9) then {"0"} else {""}) + str _sec;

format ["%1%4%2%4%3", _hour, _min, _sec, _sep]
