/*
 * Author: Paramarine Task Force
 * Puts a group on alert after it hears a G/ATOR's generator: out of its safe behaviour, and
 * with some idea of who is at the trailer. Runs where the group is local. A group a mission
 * set to careless stays that way.
 *
 * Arguments:
 * 0: Group <GROUP>
 * 1: Someone at the trailer, or objNull if nobody is <OBJECT>
 * 2: How much the group now knows about them, as for reveal <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [group _ai, player, 1.5] call PTF_GATOR_fnc_alertGroup
 */
params [["_group", grpNull, [grpNull]], ["_unit", objNull, [objNull]], ["_amount", 1, [0]]];

if (isNull _group || {behaviour leader _group == "CARELESS"}) exitWith {};
if (behaviour leader _group == "SAFE") then {_group setBehaviour "AWARE"};
if (!isNull _unit) then {_group reveal [_unit, _amount]};
