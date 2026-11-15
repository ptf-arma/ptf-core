/*
 * Author: Paramarine Task Force
 * The Radar layer on the Billet tablet's map (class blk_tabletLayers in config.cpp): one
 * switch for all the G/ATOR shows, made of its three parts:
 *  - the G/ATORs: their symbols, sensor arcs, reach, strobes and missiles inbound
 *    (PTF_GATOR_fnc_gatorLayer)
 *  - the air picture: aircraft, small drones and missiles in flight (PTF_GATOR_fnc_airLayer)
 *  - counter-battery: firing points and bearings, where rounds landed and will land
 *    (PTF_GATOR_fnc_cbLayer)
 * Billet asks once a second while the tablet is open; see Billet's fn_tabletLayers for the
 * format. A layer draws 400 shapes at most, so the G/ATORs go first, then the air picture
 * (few, and missiles among them), then counter-battery.
 *
 * ["draw"]: all three parts' shapes.
 * ["tracks"]: one section of the map's Tracks list, "Radar": the G/ATORs, then the air
 *  picture (missiles first, then hostile), then counter-battery (newest first), with Erase on
 *  each counter-battery row and Clear all on the section while there are any.
 * ["action", action, key]: those buttons, passed on to the counter-battery part (its rows'
 *  keys carry a "cb." prefix here, so they can't be mistaken for another part's).
 *
 * Arguments:
 * 0: "draw", "tracks" or "action" <STRING>
 * 1: Action <STRING>
 * 2: Row key <STRING>
 *
 * Return Value:
 * Shapes <ARRAY>, the Tracks section <HASHMAP>, or nil
 */
params [["_cmd", "", [""]], ["_action", "", [""]], ["_key", "", [""]]];

if (_cmd == "action") exitWith {
	["action", _action, _key regexReplace ["^cb\.", ""]] call PTF_GATOR_fnc_cbLayer;
	nil
};

if (_cmd == "draw") exitWith {
	private _shapes = ["draw"] call PTF_GATOR_fnc_gatorLayer;
	_shapes append (["draw"] call PTF_GATOR_fnc_airLayer);
	_shapes append (["draw"] call PTF_GATOR_fnc_cbLayer);
	_shapes
};

if (_cmd != "tracks") exitWith {[]};
private _parts = [["tracks"] call PTF_GATOR_fnc_gatorLayer, ["tracks"] call PTF_GATOR_fnc_airLayer, ["tracks"] call PTF_GATOR_fnc_cbLayer];
if (_parts findIf {!isNil "_x"} < 0) exitWith {nil};
_parts params [["_gators", createHashMap], ["_air", createHashMap], ["_cb", createHashMap]];
private _rows = +(_gators getOrDefault ["rows", []]);
_rows append (_air getOrDefault ["rows", []]);
private _cbRows = (_cb getOrDefault ["rows", []]) apply {
	private _row = +_x;
	_row set ["key", "cb." + (_row getOrDefault ["key", ""])];
	_row
};
_rows append _cbRows;
createHashMapFromArray [["title", "Radar"], ["rows", _rows],
	["actions", [[], [createHashMapFromArray [["id", "clear"], ["label", "Clear all"]]]] select (_cbRows isNotEqualTo [])],
	["empty", _gators getOrDefault ["empty", "No G/ATOR on the network"]]]
