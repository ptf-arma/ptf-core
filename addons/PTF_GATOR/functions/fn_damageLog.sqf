/*
 * Author: Paramarine Task Force
 * Writes what hurts a G/ATOR to the RPT of the machine that owns it (usually the server's), so
 * a fire or a wreck nobody can explain can be traced afterwards. Search the RPT for
 * "PTF_GATOR damage". Started on every machine by the PTF_GATOR XEH init; the handlers only
 * fire where the trailer is local, and the owner changes while it is towed.
 *
 * Logged: any hit that raises a hit point by 0.1 or more (any at all on the fuel tank), with
 * who or what did it; hard knocks (PhysX contacts over KNOCK); and its death. Each line has its
 * state: speed, which way up, array and leg phases, hitched or not.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 *
 * Return Value:
 * None
 */
#define KNOCK 300

params [["_radar", objNull, [objNull]]];
if (isNull _radar) exitWith {};

_radar addEventHandler ["HandleDamage", {
	params ["_radar", "", "_new", "_source", "_projectile", "_index", "_instigator", "_hit"];
	private _was = [_radar getHitIndex _index, damage _radar] select (_index < 0);
	private _rise = _new - _was;
	if (_rise >= 0.1 || {_hit == "hitfuel" && {_rise > 0.001}}) then {
		diag_log format ["PTF_GATOR damage %1: %2 %3 -> %4 from %5 (%6) projectile '%7' t=%8, %9",
			_radar, [_hit, "total"] select (_hit == ""), _was toFixed 2, _new toFixed 2, typeOf _source,
			[name _instigator, "-"] select (isNull _instigator), _projectile, round CBA_missionTime, [_radar] call PTF_GATOR_fnc_damageState];
	};
	nil
}];

_radar addEventHandler ["EpeContactStart", {
	params ["_radar", "_other", "", "", "_force"];
	if (_force < KNOCK || {CBA_missionTime < (_radar getVariable ["PTF_GATOR_knockLogged", -1]) + 1}) exitWith {};
	_radar setVariable ["PTF_GATOR_knockLogged", CBA_missionTime];
	diag_log format ["PTF_GATOR damage %1: knocked by %2 force %3 t=%4, %5", _radar, [typeOf _other, "ground"] select (isNull _other),
		round _force, round CBA_missionTime, [_radar] call PTF_GATOR_fnc_damageState];
}];

_radar addEventHandler ["Killed", {
	params ["_radar", "_killer", "_instigator"];
	diag_log format ["PTF_GATOR damage %1: destroyed by %2 (%3) t=%4, %5", _radar, typeOf _killer,
		[name _instigator, "-"] select (isNull _instigator), round CBA_missionTime, [_radar] call PTF_GATOR_fnc_damageState];
}];
