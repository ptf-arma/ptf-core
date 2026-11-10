/*
 * Author: Paramarine Task Force
 * Tells the player how much fuel a G/ATOR's generator has: the tank as a percentage, and
 * about how many minutes of running that is.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_radar] call PTF_GATOR_fnc_fuelReport
 */
params [["_radar", objNull, [objNull]]];

private _fuel = fuel _radar;
private _minutes = floor (_fuel * getNumber (configOf _radar >> "ptf_gator_fuelMinutes"));
private _text = if (_fuel <= 0) then {
	"Generator fuel: empty"
} else {
	format ["Generator fuel: %1%2<br/>About %3 of running", round (_fuel * 100), "%", ["less than a minute", format ["%1 min", _minutes]] select (_minutes > 0)]
};
[_text, 1.5] call ace_common_fnc_displayTextStructured;
