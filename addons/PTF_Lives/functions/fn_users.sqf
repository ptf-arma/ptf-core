/*
	Server: the connected players, as [[SteamID, network owner, unit, name], ...].
	Headless clients are left out. In single player, where allUsers is empty,
	the player.
*/
private _list = [];
{
	_x params ["", ["_owner", -1], ["_uid", ""], "", ["_name", ""], "", "", ["_isHC", false], "", "", ["_unit", objNull]];
	if (!_isHC && {_uid isNotEqualTo ""}) then {_list pushBack [_uid, _owner, _unit, _name]};
} forEach (allUsers apply {getUserInfo _x});
if (!isMultiplayer && {hasInterface} && {!isNull player}) then {
	_list pushBack [getPlayerUID player, clientOwner, player, name player];
};
_list
