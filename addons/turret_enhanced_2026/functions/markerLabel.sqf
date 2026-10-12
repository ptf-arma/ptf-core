/*
	GLT_fnc_markerLabel  (Turret Enhanced 2026 Version)
	Builds the map marker text for a slot from its prefix setting (GLT_Marker<n>Prefix).
	The tag {Counter} (any case) in the prefix is replaced with the marker number.

		prefix "My {Counter} Mark", number 0, no text    -> "My 0 Mark"
		prefix "My {Counter} Mark", number 0, text "BTR" -> "My 0 Mark - BTR"
		prefix "{Counter}" (default)                      -> "0" / "0 - BTR"   (original behaviour)
		prefix ""                                         -> "" / "BTR"

	Params: _slot <NUMBER>, _num <NUMBER> marker number, _text <STRING> typed text (optional),
	        _prefix <STRING> prefix to use instead of the setting (optional)
	Returns: <STRING>
*/

params [["_slot", 1, [0]], ["_num", 0, [0]], ["_text", "", [""]], ["_prefix", nil, [""]]];

// _prefix (optional) overrides the setting
if (isNil "_prefix") then
{
	_prefix = missionNamespace getVariable [format ["GLT_Marker%1Prefix", _slot], "{Counter}"];
};

// Case-insensitive replace of every {Counter} tag
private _tag = "{counter}";
private _rest = _prefix;
private _expanded = "";
while {true} do
{
	private _i = (toLower _rest) find _tag;
	if (_i < 0) exitWith {_expanded = _expanded + _rest};
	_expanded = _expanded + (_rest select [0, _i]) + str _num;
	_rest = _rest select [_i + count _tag, count _rest];
};

_expanded = [_expanded] call CBA_fnc_trim;
_text = [_text] call CBA_fnc_trim;

switch (true) do
{
	case (_text == ""):     {_expanded};
	case (_expanded == ""): {_text};
	default                 {format ["%1 - %2", _expanded, _text]};
}
