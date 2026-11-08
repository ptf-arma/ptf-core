// Multiplayer test of PTF_Briefing's network path, no game window: a dedicated server
// loads a deck through billet-link, a headless client fetches every slide over the
// network, and the server checks each one arrived intact.
// Run with: python tools/briefing-test/mp.py --billet-dll <billet_link.dll>
#include "test_settings.sqf"

if (isServer) then {
	[] spawn {
		waitUntil {time > 1};
		diag_log format ["BRIEFMP SERVER start ready=%1", missionNamespace getVariable ["PTF_Briefing_ready", "nil"]];
		private _lha = createVehicle ["Peral_LHA", [400, 400, 0], [], 0, "CAN_COLLIDE"];
		_lha setPosASL [400, 400, 0];
		waitUntil {count (_lha getVariable ["bis_carrierparts", []]) >= 8};
		[_lha] call BIS_fnc_Carrier01PosUpdate;
		missionNamespace setVariable ["BRIEFMP_lha", _lha, true];

		// What the laptop's Load action does, minus the player check: no player here.
		PTF_Briefing_nextReq = 1;
		PTF_Briefing_pending set ["1", [_lha, 2, false]];
		_lha setVariable ["PTF_Briefing_loading", time];
		// mp.py's stand-in Billet grants "Load briefing slides" to this SteamID only.
		diag_log format ["BRIEFMP SERVER queued %1", ("billet_link" callExtension ["slides", ["1", brief_url, "76561198000000001"]]) select 0];
		private _t = time;
		waitUntil {(_lha getVariable ["PTF_Briefing_deck", []]) isNotEqualTo [] || time - _t > 60};
		private _mine = (PTF_Briefing_decks getOrDefault ["1", []]) apply {[count _x, hashValue _x]};
		diag_log format ["BRIEFMP SERVER deck %1 slides %2", _lha getVariable ["PTF_Briefing_deck", []], _mine];
		diag_log "BRIEFMP SERVER READY";

		waitUntil {!isNil "BRIEFMP_result"};
		BRIEFMP_result params ["_seconds", "_theirs"];
		_theirs sort true;
		private _ok = (_theirs apply {[_x select 1, _x select 2]}) isEqualTo _mine;
		diag_log format ["BRIEFMP SERVER client got %1 slides in %2 s: %3", count _theirs, _seconds, ["MISMATCH", "MATCH"] select _ok];
		if (!_ok) then {diag_log format ["BRIEFMP SERVER client sent %1", _theirs]};
		diag_log "BRIEFMP SERVER DONE";
	};
};

if (!isServer && !hasInterface) then {
	[] spawn {
		waitUntil {!isNil "BRIEFMP_lha" && {(BRIEFMP_lha getVariable ["PTF_Briefing_deck", []]) isNotEqualTo []}};
		// A headless client has no screens, so set up the cache the client loop would.
		PTF_Briefing_cache = createHashMap;
		PTF_Briefing_partial = createHashMap;
		(BRIEFMP_lha getVariable "PTF_Briefing_deck") params ["_req", "_count"];
		diag_log format ["BRIEFMP HC asking for %1 slides of deck %2, clientOwner %3", _count, _req, clientOwner];
		private _t = diag_tickTime;
		for "_i" from 0 to _count - 1 do {[_req, _i, clientOwner] remoteExecCall ["PTF_Briefing_fnc_requestSlide", 2]};
		waitUntil {count PTF_Briefing_cache == _count || diag_tickTime - _t > 60};
		// Strip the "data:image/jpeg;base64," prefix (23 characters) to compare with the server.
		BRIEFMP_result = [diag_tickTime - _t, (keys PTF_Briefing_cache) apply {
			private _data = (PTF_Briefing_cache get _x) select [23];
			[parseNumber ((_x splitString "_") select 1), count _data, hashValue _data]
		}];
		publicVariableServer "BRIEFMP_result";
	};
};
