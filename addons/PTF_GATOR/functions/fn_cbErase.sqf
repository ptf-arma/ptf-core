/*
 * Author: Paramarine Task Force
 * Erases counter-battery tracks from every G/ATOR: one track by its number, or all of them.
 * Runs on the server (called anywhere): the tablet's Tracks list calls it from its Erase and
 * Clear all buttons (PTF_GATOR_fnc_cbLayer).
 *
 * Arguments:
 * 0: Track number, or -1 for all <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [3] call PTF_GATOR_fnc_cbErase
 */
params [["_id", -1, [0]]];

if (!isServer) exitWith {[_id] remoteExecCall ["PTF_GATOR_fnc_cbErase", 2]};
{
	private _tracks = _x getVariable ["PTF_GATOR_cbTracks", []];
	_x setVariable ["PTF_GATOR_cbTracks", [_tracks select {(_x get "id") != _id}, []] select (_id < 0)];
} forEach ((missionNamespace getVariable ["PTF_GATOR_all", []]) select {!isNull _x});
call PTF_GATOR_fnc_cbPublish;
