/*
 * Author: Paramarine Task Force
 * A G/ATOR's warning to this player (from the server): a traced round coming down near them
 * (PTF_GATOR_fnc_cbReport). Arma's own "incoming" call on their radio, and nothing on their
 * screen: the countdown is on the G/ATOR's operator console (PTF_GATOR_fnc_console).
 *
 * Arguments:
 * 0: Where it comes down, [x, y] or ASL <ARRAY>
 * 1: When, CBA_missionTime <NUMBER>
 *
 * Return Value:
 * None
 */
params [["_at", [], [[]]], ["_lands", -1, [0]]];
if (!hasInterface || {!alive player}) exitWith {};

playSound "PTF_GATOR_incoming";
