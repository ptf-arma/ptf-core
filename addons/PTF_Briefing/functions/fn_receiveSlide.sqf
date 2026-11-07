/*
	Client: one piece of a slide from the server. Once every piece is in, the
	slide is cached as a data URL ready for the screens.
*/
params [["_req", "", [""]], ["_index", 0, [0]], ["_part", 0, [0]], ["_total", 1, [0]], ["_chunk", "", [""]]];if (isNil "PTF_Briefing_cache" || {_total < 1 || _total > 200 || _part < 0 || _part >= _total}) exitWith {};
// Base64 only: anything else could break out of the script string it is shown with.
if ((_chunk regexFind ["[^A-Za-z0-9+/=]"]) isNotEqualTo []) exitWith {};
private _key = format ["%1_%2", _req, _index];
// A late duplicate from a re-request: the slide is already complete.
if (_key in PTF_Briefing_cache) exitWith {};
private _buf = PTF_Briefing_partial getOrDefault [_key, []];
if (count _buf != _total) then {
	_buf = [];
	_buf resize [_total, ""];
	PTF_Briefing_partial set [_key, _buf];
};
_buf set [_part, _chunk];
if (_buf findIf {_x == ""} < 0) then {
	PTF_Briefing_cache set [_key, "data:image/jpeg;base64," + (_buf joinString "")];
	PTF_Briefing_partial deleteAt _key;
};
