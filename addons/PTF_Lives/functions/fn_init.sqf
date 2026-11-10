/*
	CBA postInit (Extended_PostInit_EventHandlers), everywhere. The server keeps the lives; players watch their own.
*/
if (isServer) then {call PTF_Lives_fnc_serverInit};
if (hasInterface) then {call PTF_Lives_fnc_clientInit};
