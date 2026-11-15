/*
	Server, remote-executed by a player's game when that player dies: the second
	way a death is counted, beside fn_serverInit's EntityKilled. fn_charge counts
	each body once, so whichever arrives second does nothing.

	Who died comes from the network connection, never the arguments, so a player
	can only ever report their own death. The body must be dead, and must not be
	tagged as someone else's.

	Params: [unit]
*/
if (!isServer) exitWith {};
params [["_unit", objNull, [objNull]]];
([] call PTF_Lives_fnc_callerUid) params ["", "_uid"];
if (_uid isEqualTo "" || {isNull _unit} || {alive _unit} || {!(_unit isKindOf "CAManBase")}) exitWith {};
private _tag = _unit getVariable ["PTF_Lives_uid", ""];
if (_tag isNotEqualTo "" && {_tag isNotEqualTo _uid}) exitWith {};
[_unit, _uid, "died"] call PTF_Lives_fnc_charge;
