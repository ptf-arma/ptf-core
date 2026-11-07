/*
	Server: which machine sent this request. remoteExecutedOwner is preferred, but
	on a dedicated server it came back 0 for requests from a headless client
	(tools/briefing-test/mp.py), so clients also send their own clientOwner and
	that is used when the engine gives nothing. In single player it is this machine.
*/
params [["_sent", 0, [0]]];
private _owner = remoteExecutedOwner;
if (_owner == 0) then {_owner = _sent};
if (_owner == 0) then {_owner = clientOwner};
_owner
