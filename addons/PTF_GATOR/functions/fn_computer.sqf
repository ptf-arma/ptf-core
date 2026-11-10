/*
 * Author: Paramarine Task Force
 * The G/ATOR's operator computer: a rugged laptop on a cable from the trailer, where its crew
 * takes manual control and works the radar from its console (PTF_GATOR_fnc_console, on the
 * Billet tablet's console slot). Runs on the server (called anywhere).
 *
 * "out": a player takes the computer out of the trailer. It appears in their hands (an ACE
 *   carry) with its cable run from the box's side, to set down where they want it within the
 *   cable's reach (ptf_gator_computerCable). The laptop is the first of
 *   ptf_gator_computerClasses that exists.
 * "stow": the computer and its cable go back in the trailer; the G/ATOR goes back to
 *   automatic control.
 * "update": once a second from the radar loop. The computer is connected (PTF_GATOR_console)
 *   while it's within its cable's reach with the cable in. Unplugged (pulled out of reach, or
 *   the trailer towed off), the G/ATOR goes back to automatic control; a cable that pulled out
 *   goes back in once the computer is within reach again.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: "out", "stow" or "update" <STRING>
 * 2: The player taking it out <OBJECT> (default: objNull)
 *
 * Return Value:
 * None
 *
 * Example:
 * [_radar, "out", player] call PTF_GATOR_fnc_computer
 */
params [["_radar", objNull, [objNull]], ["_cmd", "", [""]], ["_unit", objNull, [objNull]]];

if (!isServer) exitWith {[_radar, _cmd, _unit] remoteExecCall ["PTF_GATOR_fnc_computer", 2]};
if (isNull _radar) exitWith {};

private _computer = _radar getVariable ["PTF_GATOR_computer", objNull];
private _length = getNumber (configOf _radar >> "ptf_gator_computerCable");
private _cable = {
	private _type = ["Rope", "TFAR_RopeSmallWire"] select isClass (configFile >> "CfgVehicles" >> "TFAR_RopeSmallWire");
	private _rope = ropeCreate [_radar, _radar selectionPosition ["interact", "Memory"], _computer, [0, 0, 0.05], _length,
		["", [0, 0, -1]], ["", [0, 0, -1]], _type];
	_radar setVariable ["PTF_GATOR_computerRope", _rope];
};
private _connect = {
	params ["_on"];
	private _now = [objNull, _computer] select _on;
	if ((_radar getVariable ["PTF_GATOR_console", objNull]) isEqualTo _now) exitWith {};
	_radar setVariable ["PTF_GATOR_console", _now, true];
	// no computer, no manual control
	if (!_on && {_radar getVariable ["PTF_GATOR_manual", false]}) then {[_radar, "auto"] call PTF_GATOR_fnc_operator};
};

if (_cmd == "out") exitWith {
	if (!isNull _computer || {!alive _radar} || {isNull _unit}) exitWith {};
	private _classes = getArray (configOf _radar >> "ptf_gator_computerClasses");
	private _class = _classes param [_classes findIf {isClass (configFile >> "CfgVehicles" >> _x)}, ""];
	if (_class == "") exitWith {};
	_computer = createVehicle [_class, _unit getRelPos [0.8, 0], [], 0, "CAN_COLLIDE"];
	_computer setDir getDir _unit;
	[_computer, false] remoteExecCall ["allowDamage", 0, _computer];
	_computer setVariable ["PTF_GATOR_radar", _radar, true];
	_radar setVariable ["PTF_GATOR_computer", _computer, true];
	[_computer, true, [0, 0.6, 1], 0, true] remoteExecCall ["ace_dragging_fnc_setCarryable", 0, _computer];
	call _cable;
	// Into their hands: an ACE carry, from where they stand.
	[{
		params ["_unit", "_computer"];
		[_unit, _computer] call ace_dragging_fnc_startCarry;
	}, [_unit, _computer]] remoteExecCall ["CBA_fnc_execNextFrame", _unit];
};

if (_cmd == "stow") exitWith {
	ropeDestroy (_radar getVariable ["PTF_GATOR_computerRope", objNull]);
	deleteVehicle _computer;
	_radar setVariable ["PTF_GATOR_computer", objNull, true];
	[false] call _connect;
};

// "update"
if (isNull _computer) exitWith {[false] call _connect};
private _distance = _computer distance _radar;
private _rope = _radar getVariable ["PTF_GATOR_computerRope", objNull];
if (isNull _rope && {_distance < _length - 1}) then {call _cable; _rope = _radar getVariable ["PTF_GATOR_computerRope", objNull]};
[alive _radar && {!isNull _rope} && {_distance <= _length + 1} && {isNull (_radar getVariable ["PTF_GATOR_tower", objNull])}] call _connect;
