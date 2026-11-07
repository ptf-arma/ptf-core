/*
	GLT_fnc_isMQ9  (Turret Enhanced 2026 Version)
	True for MQ-9 Reaper airframes (e.g. USAF mod "USAF_MQ9"), which draw their own laser on the map.

	Params: _veh <OBJECT>
	Returns: <BOOL>
*/

params [["_veh", objNull, [objNull]]];

private _type = toLower typeOf _veh;
(_type find "mq9" >= 0) || {_type find "mq_9" >= 0} || {_veh isKindOf "USAF_MQ9"}
