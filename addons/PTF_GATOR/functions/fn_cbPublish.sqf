/*
 * Author: Paramarine Task Force
 * Puts what each G/ATOR knows where players can read it. Server only.
 *
 * Every G/ATOR's own counter-battery tracks go on it (PTF_GATOR_cbOwn, public), for its crew
 * to read at the trailer. Only those cabled to a SATCOM antenna (PTF_GATOR_satcom) are on
 * the network: their counter-battery tracks and the aircraft their radars see make up
 * PTF_GATOR_picture (public), which the Billet tablet's map layers and Tracks list draw from
 * (PTF_GATOR_fnc_cbLayer, PTF_GATOR_fnc_airLayer).
 *
 * A counter-battery track: [id, kind, [x, y], error m, rounds, last seen (CBA_missionTime),
 *   impacts [[x, y], ...], bearing deg, ammo name, [x, y] of its G/ATOR, weapon ("mortar" or
 *   "artillery"), looked at closer (a dwell, PTF_GATOR_fnc_operator)]
 *   kind "point": a firing point, error its likely miss
 *   kind "bearing": fired from beyond CB_TRACE, a bearing from its G/ATOR only
 * An air track: [id, name, relationship ("friendly", "enemy", "neutral", "unknown"), [x, y],
 *   height m, speed km/h, heading deg, kind ("air" a helicopter, "plane", "uav")]
 *   An aircraft its operator interrogated (IFF) shows as what it answered.
 * A splash: [[x, y], when it comes down (CBA_missionTime)], a traced round's predicted impact
 * PTF_GATOR_picture: [revision, [[[x, y], G/ATOR], ...] (each networked one), [counter-battery track, ...],
 *   [air track, ...], [splash, ...]]
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 */
if (!isServer) exitWith {};

private _radars = [];
private _tracks = [];
private _air = [];
private _splashes = [];
{
	private _radar = _x;
	private _at = getPosASL _radar;
	private _home = [_at select 0, _at select 1];
	private _own = (_radar getVariable ["PTF_GATOR_cbTracks", []]) apply {
		[_x get "id", _x get "kind", _x getOrDefault ["point", _home], _x getOrDefault ["error", 0], _x get "rounds",
			_x get "last", _x getOrDefault ["impacts", []], _x getOrDefault ["bearing", 0], _x get "ammo", _home,
			_x getOrDefault ["weapon", "artillery"], _x getOrDefault ["dwelt", false]]
	};
	if (_own isNotEqualTo (_radar getVariable ["PTF_GATOR_cbOwn", []])) then {_radar setVariable ["PTF_GATOR_cbOwn", _own, true]};
	if (alive _radar && {!isNull (_radar getVariable ["PTF_GATOR_satcom", objNull])}) then {
		_radars pushBack [_home, _radar];
		_tracks append _own;
		_splashes append ((_radar getVariable ["PTF_GATOR_splashes", []]) select {(_x select 1) > CBA_missionTime - 3});
		// two G/ATORs seeing one aircraft: listed once
		private _iff = _radar getVariable ["PTF_GATOR_iff", createHashMap];
		{
			private _id = _x select 0;
			if (_air findIf {(_x select 0) isEqualTo _id} < 0) then {
				private _track = +_x;
				if (_id in _iff) then {_track set [2, _iff get _id]};
				_air pushBack _track;
			};
		} forEach (_radar getVariable ["PTF_GATOR_air", []]);
	};
} forEach ((missionNamespace getVariable ["PTF_GATOR_all", []]) select {!isNull _x});

private _old = missionNamespace getVariable ["PTF_GATOR_picture", [0, [], [], [], []]];
if ([_radars, _tracks, _air, _splashes] isEqualTo [_old select 1, _old select 2, _old select 3, _old param [4, []]]) exitWith {};
missionNamespace setVariable ["PTF_GATOR_picture", [(_old select 0) + 1, _radars, _tracks, _air, _splashes], true];
