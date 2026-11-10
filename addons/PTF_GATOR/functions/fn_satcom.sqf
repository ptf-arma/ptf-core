/*
 * Author: Paramarine Task Force
 * The G/ATOR's SATCOM antenna, which puts its counter-battery and air picture on the network.
 * Runs on the server (called anywhere).
 *
 * "out": a player takes the antenna out of the trailer. It appears at their feet with the
 *   cable already run to it from the box's side (a real rope, black TFAR intercom wire where
 *   TFAR is loaded), and they're put straight into an ACE drag with it, to set it down where
 *   they want it. The antenna is the TFW RF-3080 where loaded, else a vanilla satellite
 *   antenna (the first of ptf_gator_satcomClasses that exists).
 * "stow": the antenna and its cable go back in the trailer.
 * "update": once a second from the radar loop. The G/ATOR is on the network
 *   (PTF_GATOR_satcom set) while the antenna stands set down, more than SATCOM_CLEAR metres
 *   from the trailer and within its cable's reach (ptf_gator_cableLength), with the cable in.
 *   Set down closer than that, it picks up the radar's own interference: the player who set it
 *   down is told. A cable that pulled out goes back in once the antenna is within reach again.
 *   Hitched, moving or wrecked, the trailer is off the network.
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
 * [_radar, "out", player] call PTF_GATOR_fnc_satcom
 */
#define SATCOM_CLEAR 3

params [["_radar", objNull, [objNull]], ["_cmd", "", [""]], ["_unit", objNull, [objNull]]];

if (!isServer) exitWith {[_radar, _cmd, _unit] remoteExecCall ["PTF_GATOR_fnc_satcom", 2]};
if (isNull _radar) exitWith {};

private _antenna = _radar getVariable ["PTF_GATOR_antenna", objNull];
private _length = getNumber (configOf _radar >> "ptf_gator_cableLength");
private _cable = {
	// From the box's left side, where the crew works, to the antenna's foot.
	private _type = ["Rope", "TFAR_RopeSmallWire"] select isClass (configFile >> "CfgVehicles" >> "TFAR_RopeSmallWire");
	private _rope = ropeCreate [_radar, _radar selectionPosition ["interact", "Memory"], _antenna, [0, 0, 0.25], _length,
		["", [0, 0, -1]], ["", [0, 0, -1]], _type];
	_radar setVariable ["PTF_GATOR_cable", _rope];
};
private _network = {
	params ["_on"];
	private _now = [objNull, _antenna] select _on;
	if ((_radar getVariable ["PTF_GATOR_satcom", objNull]) isEqualTo _now) exitWith {};
	_radar setVariable ["PTF_GATOR_satcom", _now, true];
	call PTF_GATOR_fnc_cbPublish;
};

if (_cmd == "out") exitWith {
	if (!isNull _antenna || {!alive _radar} || {isNull _unit}) exitWith {};
	private _class = (getArray (configOf _radar >> "ptf_gator_satcomClasses")) param [
		(getArray (configOf _radar >> "ptf_gator_satcomClasses")) findIf {isClass (configFile >> "CfgVehicles" >> _x)}, ""];
	if (_class == "") exitWith {};
	_antenna = createVehicle [_class, _unit getRelPos [1.2, 0], [], 0, "CAN_COLLIDE"];
	_antenna setDir getDir _unit;
	// The RF-3080 is wrecked by the knock of being dragged into place; it can't be hurt, on
	// whichever machine ends up with it.
	[_antenna, false] remoteExecCall ["allowDamage", 0, _antenna];
	_radar setVariable ["PTF_GATOR_antenna", _antenna, true];
	_antenna setVariable ["PTF_GATOR_cabledTo", _radar, true];
	_antenna setVariable ["PTF_GATOR_setBy", _unit];
	// ACE can drag the RF-3080 already; a vanilla antenna is made draggable on every machine.
	if (getNumber (configOf _antenna >> "ace_dragging_canDrag") != 1) then {
		[_antenna, true, [0, 1.2, 0], 0, true] remoteExecCall ["ace_dragging_fnc_setDraggable", 0, _antenna];
	};
	call _cable;
	// Into their hands: an ACE drag, from where they stand.
	[{
		params ["_unit", "_antenna"];
		[_unit, _antenna] call ace_dragging_fnc_startDrag;
	}, [_unit, _antenna]] remoteExecCall ["CBA_fnc_execNextFrame", _unit];
};

if (_cmd == "stow") exitWith {
	ropeDestroy (_radar getVariable ["PTF_GATOR_cable", objNull]);
	deleteVehicle _antenna;
	_radar setVariable ["PTF_GATOR_antenna", objNull, true];
	[false] call _network;
};

// "update"
if (isNull _antenna) exitWith {[false] call _network};
if (!alive _antenna) exitWith {[_radar, "stow"] call PTF_GATOR_fnc_satcom};
private _held = !isNull attachedTo _antenna;   // ACE drags and carries by attaching it
if (_held) then {
	_antenna setVariable ["PTF_GATOR_setBy", attachedTo _antenna];
	_antenna setVariable ["PTF_GATOR_warned", false];
};
private _distance = _antenna distance2D _radar;
private _rope = _radar getVariable ["PTF_GATOR_cable", objNull];
if (isNull _rope && {_distance < _length - 1}) then {call _cable; _rope = _radar getVariable ["PTF_GATOR_cable", objNull]};
private _tooClose = !_held && {_distance < SATCOM_CLEAR};
if (_tooClose && {!(_antenna getVariable ["PTF_GATOR_warned", false])}) then {
	_antenna setVariable ["PTF_GATOR_warned", true];
	private _by = _antenna getVariable ["PTF_GATOR_setBy", objNull];
	if (!isNull _by && {isPlayer _by}) then {
		[format ["<t color='#ff5a48'>Radar interference</t><br/>The SATCOM antenna is too close to the G/ATOR to hear the satellite. Set it down more than %1 m away.", SATCOM_CLEAR], 2]
			remoteExecCall ["ace_common_fnc_displayTextStructured", _by];
	};
};
[alive _radar && {!_held} && {!_tooClose} && {_distance <= _length + 1} && {!isNull _rope}
	&& {abs speed _radar < 1} && {isNull (_radar getVariable ["PTF_GATOR_tower", objNull])}] call _network;
