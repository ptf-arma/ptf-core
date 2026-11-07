/*
	Server: send one slide to the machine that asked for it, in pieces small
	enough for the network. Players ask for the slide on screen and the next one,
	only while they are near a ship that shows them.

	[_req, _index, clientOwner] remoteExecCall ["PTF_Briefing_fnc_requestSlide", 2];
*/
params [["_req", "", [""]], ["_index", 0, [0]], ["_sentOwner", 0, [0]]];
if (!isServer || {isNil "PTF_Briefing_decks"}) exitWith {};
private _owner = [_sentOwner] call PTF_Briefing_fnc_callerOwner;
private _slides = PTF_Briefing_decks getOrDefault [_req, []];
if (_index < 0 || {_index >= count _slides}) exitWith {};
// Paced rather than all in one frame: a slide change has every player in the
// room asking at once.
[_req, _index, _owner, _slides select _index] spawn {
	params ["_req", "_index", "_owner", "_data"];
	private _size = 20000;
	private _total = ceil (count _data / _size);
	for "_p" from 0 to _total - 1 do {
		[_req, _index, _p, _total, _data select [_p * _size, _size]] remoteExecCall ["PTF_Briefing_fnc_receiveSlide", _owner];
		sleep 0.03;
	};
};
