/*
 * Author: Paramarine Task Force
 * Enemy AI within earshot of a G/ATOR's running generator may hear it. Each group of AI on
 * foot gets one chance per call, less the further off it is (none past ptf_gator_hearingRange):
 * hearing it, the group comes out of its safe behaviour and learns something of whoever is
 * working at the trailer (PTF_GATOR_fnc_alertGroup), as it would hearing a vehicle idle.
 * Groups led by a player, and AI in vehicles, don't. Server only, from the radar loop.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 *
 * Return Value:
 * Groups that heard it <ARRAY>
 *
 * Example:
 * [_radar] call PTF_GATOR_fnc_hearGenerator
 */
params [["_radar", objNull, [objNull]]];

private _range = getNumber (configOf _radar >> "ptf_gator_hearingRange");
if (_range <= 0) exitWith {[]};

// Who is at the trailer: the people the noise gives away.
private _crew = (_radar nearEntities ["CAManBase", 30]) select {alive _x && {isNull objectParent _x} && {!captive _x}};
private _owner = [east, west, independent, civilian] select (getNumber (configOf _radar >> "side") max 0 min 3);
private _heard = [];
{
	private _group = group _x;
	if (!(_group in _heard) && {!isPlayer leader _group} && {isNull objectParent _x} && {alive _x}) then {
		private _side = side _group;
		private _enemies = _crew select {_side getFriend side group _x < 0.6};
		// Nobody at it: whoever it belongs to (the config side) is the enemy it betrays.
		private _hostile = _enemies isNotEqualTo [] || {_crew isEqualTo [] && {_side getFriend _owner < 0.6}};
		private _distance = _x distance _radar;
		if (_hostile && {random 1 < 1 - 0.85 * (_distance / _range)}) then {
			_heard pushBack _group;
			private _target = [objNull, _enemies select 0] select (_enemies isNotEqualTo []);
			[_group, _target, 1 + 1.5 * (1 - _distance / _range)] remoteExecCall ["PTF_GATOR_fnc_alertGroup", leader _group];
		};
	};
} forEach ((_radar nearEntities ["CAManBase", _range]) select {!isPlayer _x});
_heard
