/*
 * Author: Paramarine Task Force
 * The cables from a G/ATOR to its SATCOM antenna and its operator computer. Server only.
 *
 * "takeOut": the thing (just made) goes straight into the player's arms. It is attached to them
 *   the moment it's made, at the height it would sit on the ground, so it never stands on its
 *   own anywhere: made where the player stands it was inside the box, flung out by its physics
 *   before a player in multiplayer had it in hand; made on the ground under a raised deck or a
 *   ship's, it stayed below it. ACE's carry then takes it from there (it reckons its carry height
 *   from where the thing is). The player turns away from the trailer first. If the carry never
 *   starts, it is set down at their feet.
 * "rope": a new rope from the box's side to the thing, only a little longer than the way to it,
 *   in the radar variable named.
 * "reel": pays the cable out as the thing is carried away and back in while it's held, so it's
 *   never more than CABLE_SLACK longer than the way to it (a full-length cable piled up at the
 *   trailer, where people tangled in its physics). Carried to its end, the cable pulls out (a
 *   taut rope yanks a thing set down back toward the trailer); "rope" puts it back in once the
 *   thing is in reach. Runs as long as the thing is there.
 *
 * Arguments:
 * 0: "takeOut", "rope" or "reel" <STRING>
 * 1: G/ATOR <OBJECT>
 * 2: The thing on the cable's end <OBJECT>
 * 3: takeOut: the player <OBJECT>, its carry position <ARRAY>; rope, reel: the radar variable
 *    for the rope <STRING>, the cable's full length <NUMBER>, where the rope meets the thing,
 *    model space <ARRAY>
 *
 * Return Value:
 * rope: the rope <OBJECT>; else nothing
 *
 * Example:
 * ["rope", _radar, _antenna, "PTF_GATOR_cable", 40, [0, 0, 0.25]] call PTF_GATOR_fnc_cable
 */
#define CABLE_SLACK 2

params [["_cmd", "", [""]], ["_radar", objNull, [objNull]], ["_thing", objNull, [objNull]]];

// From the box's left side, where the crew works.
private _plug = {_radar modelToWorld (_radar selectionPosition ["interact", "Memory"])};

if (_cmd == "takeOut") exitWith {
	_this params ["", "", "", ["_unit", objNull, [objNull]], ["_carryAt", [0, 1, 1], [[]]]];
	private _away = _radar getDir _unit;
	// at its resting height: ACE adds the height it's found at to the carry position
	private _rest = -((boundingBoxReal _thing) select 0 select 2);
	_thing attachTo [_unit, [_carryAt select 0, _carryAt select 1, _rest]];
	[{
		params ["_unit", "_thing", "_away"];
		_unit setDir _away;
		[_unit, _thing] call ace_dragging_fnc_startCarry;
	}, [_unit, _thing, _away]] remoteExecCall ["CBA_fnc_execNextFrame", _unit];
	// ACE never took it (claimed by someone else, or the player went down): put it down
	[{
		params ["_unit", "_thing"];
		if (isNull _thing || {attachedTo _thing isNotEqualTo _unit} || {_unit getVariable ["ace_dragging_isCarrying", false]}) exitWith {};
		detach _thing;
		_thing setPosASL ((getPosASL _unit) vectorAdd ((vectorDir _unit) vectorMultiply 1) vectorAdd [0, 0, 0.1]);
	}, [_unit, _thing], 8] call CBA_fnc_waitAndExecute;
};

_this params ["", "", "", ["_var", "", [""]], ["_length", 20, [0]], ["_end", [0, 0, 0], [[]]]];

if (_cmd == "rope") exitWith {
	private _type = ["Rope", "TFAR_RopeSmallWire"] select isClass (configFile >> "CfgVehicles" >> "TFAR_RopeSmallWire");
	private _rope = ropeCreate [_radar, _radar selectionPosition ["interact", "Memory"], _thing, _end,
		(((call _plug) distance (_thing modelToWorld _end)) + CABLE_SLACK) min _length,
		["", [0, 0, -1]], ["", [0, 0, -1]], _type];
	_radar setVariable [_var, _rope];
	_rope
};

if (_cmd == "reel") exitWith {
	[{
		params ["_args", "_id"];
		_args params ["_radar", "_thing", "_var", "_length", "_end", "_plug"];
		if (isNull _thing || {isNull _radar}) exitWith {[_id] call CBA_fnc_removePerFrameHandler};
		private _rope = _radar getVariable [_var, objNull];
		if (isNull _rope || {!local _rope}) exitWith {};
		private _held = !isNull attachedTo _thing;   // ACE carries and drags by attaching it
		private _way = (call _plug) distance (_thing modelToWorld _end);
		if (_held && {_way > _length - 1}) exitWith {
			ropeDestroy _rope;
			_radar setVariable [_var, objNull];
		};
		private _want = (_way + CABLE_SLACK) min _length;
		private _has = ropeLength _rope;
		// out as it goes; in only while it's held (shortened under a thing set down, it drags it)
		if (_want > _has + 0.3 || {_held && {_want < _has - 1.5}}) then {ropeUnwind [_rope, 12, _want]};
	}, 0.2, [_radar, _thing, _var, _length, _end, _plug]] call CBA_fnc_addPerFrameHandler;
};
