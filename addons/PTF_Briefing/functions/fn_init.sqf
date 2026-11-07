/*
	postInit: start the server side (talks to billet-link) and the client side
	(draws slides on the screens and adds the podium laptop's actions).
*/
// ctrlWebBrowserAction is newer (Arma 2.20) than HEMTT 1.22's command list, which
// refuses to parse any file using it. Compiling it from a string keeps it out of
// the linter's way; the cost is one compile per mission.
PTF_Briefing_browser = compile "params ['_ctrl', '_args']; _ctrl ctrlWebBrowserAction _args";

if (isServer) then {call PTF_Briefing_fnc_serverInit};
if (hasInterface) then {[] spawn PTF_Briefing_fnc_clientLoop};
