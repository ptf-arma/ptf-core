/*
	PTF_Lives test (tools/lives-test/run.py). Every line the runner reads starts
	"LIVESTEST". The player runs through it twice: run 1 ends unconscious, and the
	runner kills the game there (leaving while unconscious, by crash); run 2 is the
	same player coming back with no lives left.
*/
if (isServer) then {
	createMarker ["respawn_west", [4000, 4010, 0]];
	// the vanilla side pool: Lives keeps it full
	[west, 3] call BIS_fnc_respawnTickets;
	[] spawn {
		waitUntil {sleep 1; !isNil "PTF_Lives_table"};
		diag_log format ["LIVESTEST SERVER READY on %1 start %2", PTF_Lives_on, PTF_Lives_start];
		private _last = [];
		while {true} do {
			sleep 1;
			private _now = [PTF_Lives_on, PTF_Lives_start, PTF_Lives_table, PTF_Lives_admins, [west, 0] call BIS_fnc_respawnTickets];
			if (_now isNotEqualTo _last) then {
				diag_log format ["LIVESTEST SERVER state on %1 start %2 pool %5 table %3 admins %4", _now select 0, _now select 1, _now select 2, _now select 3, _now select 4];
				_last = _now;
			};
		};
	};
};

if (!hasInterface) exitWith {};

[] spawn {
	private _say = {diag_log text format ["LIVESTEST %1", _this]};
	private _mine = {
		private _m = call PTF_Lives_fnc_mine;
		format ["lives %1 status %2 charges %3", _m param [2, "?"], _m param [3, "?"], _m param [4, "?"]]
	};
	// what the page shows, through its own log channel
	private _probe = {
		params ["_tag"];
		[format ["send('log:LIVESPROBE %1 view=' + state.view + ' rail=' + [...document.querySelectorAll('#apprail .label')].map(function (e) { return e.textContent; }).join(',') + ' text=' + document.getElementById('view').innerText.split(String.fromCharCode(10)).join(' | '))", _tag]] call blk_fnc_tabletExec;
	};
	private _js = {[_this] call blk_fnc_tabletExec};
	private _waitAlive = {
		private _t = time + _this;
		waitUntil {sleep 0.5; alive player || {time > _t}};
		alive player
	};
	waitUntil {sleep 0.5; !isNull player && {time > 3}};
	waitUntil {sleep 0.5; (call PTF_Lives_fnc_mine) isNotEqualTo []};
	private _uid = getPlayerUID player;
	private _phase = profileNamespace getVariable ["livestest_phase", 1];

	// Single player (tools/lives-test/ui.py): the tablet and phone only. This
	// machine is the host, so it is an admin, and no Billet answers, so Home is
	// the "no answer" page with the Lives panel beside it. Some made-up players
	// fill the list.
	if (!isMultiplayer) exitWith {
		{
			PTF_Lives_book set [_x select 0, [_x select 1, _x select 2, 0]];
		} forEach [["76561198000000011", "Cpl. A. Reyes", 3], ["76561198000000012", "LCpl. J. Okafor", 1], ["76561198000000013", "Pvt. M. Lindqvist", 0], ["76561198000000014", "Sgt. D. Kowalski", 2]];
		call PTF_Lives_fnc_publish;
		sleep 1;
		(format ["UI start: %1, admins %2", call _mine, PTF_Lives_admins]) call _say;
		player addItem "blk_tabletItem";
		player addItem "blk_phoneItem";
		sleep 1;
		call blk_fnc_tabletToggle;
		sleep 3;
		"window.addEventListener('error', function (e) { send('log:LIVESPROBE page error ' + e.message + ' @' + e.lineno); })" call _js;
		sleep 13; // the server never answers here: wait out the page's own timeout
		["home"] call _probe;
		sleep 1;
		(format ["snap %1", "lives_home"]) call _say;
		sleep 1.5;
		"billet.go('app:ptf_lives')" call _js;
		sleep 2;
		["tab"] call _probe;
		sleep 1;
		(format ["snap %1", "lives_tab"]) call _say;
		sleep 1.5;
		(format ["document.querySelector('[data-appact=""add""][data-key=""%1""]').click()", _uid]) call _js;
		sleep 2;
		(format ["UI after +: %1", call _mine]) call _say;
		(format ["document.querySelector('[data-appact=""sub""][data-key=""%1""]').click()", _uid]) call _js;
		sleep 2;
		(format ["UI after -: %1", call _mine]) call _say;
		"document.querySelector('[data-appact=""add""][data-key=""76561198000000013""]').click()" call _js;
		sleep 2;
		(format ["UI Lindqvist after +: %1", (PTF_Lives_table select {(_x select 0) isEqualTo "76561198000000013"}) apply {_x select 2}]) call _say;
		"document.querySelectorAll('[data-appstep=""start""]')[1].click()" call _js;
		sleep 2;
		(format ["UI after starting +: start %1", PTF_Lives_start]) call _say;
		"document.querySelectorAll('[data-appstep=""start""]')[0].click()" call _js;
		sleep 2;
		(format ["UI after starting -: start %1", PTF_Lives_start]) call _say;
		// the search box filters, and keeps its text through a refresh
		"var q = document.querySelector('[data-appq]'); q.value = 'oka'; q.dispatchEvent(new Event('input', {bubbles: true}))" call _js;
		sleep 2;
		["search"] call _probe;
		sleep 1;
		(format ["snap %1", "lives_search"]) call _say;
		sleep 1.5;
		"var q = document.querySelector('[data-appq]'); q.value = ''; q.dispatchEvent(new Event('input', {bubbles: true}))" call _js;
		"document.querySelector('[data-apptoggle=""on""][data-v=""0""]').click()" call _js;
		sleep 2;
		(format ["UI after Off: on %1", PTF_Lives_on]) call _say;
		["tab_off"] call _probe;
		sleep 1;
		(format ["snap %1", "lives_tab_off"]) call _say;
		sleep 1.5;
		"billet.go('home')" call _js;
		sleep 2;
		["home_off"] call _probe;
		"document.querySelector('[data-view=""app:ptf_lives""]').click()" call _js;
		sleep 1;
		"document.querySelector('[data-apptoggle=""on""][data-v=""1""]').click()" call _js;
		sleep 2;
		(format ["UI after On: on %1", PTF_Lives_on]) call _say;
		call blk_fnc_tabletToggle;
		sleep 2;
		// the Rugged Phone: the same app
		["phone"] call blk_fnc_tabletToggle;
		sleep 16;
		["phone"] call _probe;
		sleep 1;
		(format ["snap %1", "lives_phone"]) call _say;
		sleep 1.5;
		"billet.go('app:ptf_lives')" call _js;
		sleep 2;
		(format ["snap %1", "lives_phone_tab"]) call _say;
		sleep 1.5;
		["phone"] call blk_fnc_tabletToggle;
		sleep 2;
		// a death costs exactly one life (here the server and the player's game
		// both report it), and on the last one the spectator comes up
		["action", "sub", _uid, ""] call PTF_Lives_fnc_tablet;
		sleep 2;
		(format ["UI before dying: %1", call _mine]) call _say;
		player setDamage 1;
		sleep 4;
		(format ["UI died: %1, respawn in %2, spectating %3, ACE spectator %4, ACE screen %5",
			call _mine, round playerRespawnTime, PTF_Lives_spectating,
			missionNamespace getVariable ["ace_spectator_isSet", "-"], !isNull (findDisplay 60000)]) call _say;
		(format ["snap %1", "lives_died"]) call _say;
		sleep 1.5;
		"UI DONE" call _say;
	};

	if (_phase isEqualTo 1) then {
		(format ["C1 joined: %1", call _mine]) call _say;

		// the tablet: Home (the stand-in Billet says "not linked", so this is the
		// error page, which keeps the Lives panel)
		player addItem "blk_tabletItem";
		sleep 1;
		call blk_fnc_tabletToggle;
		sleep 6;
		["home"] call _probe;
		sleep 1;
		(format ["snap %1", "lives_home"]) call _say;
		sleep 1.5;
		// the Lives tab comes once Billet says this player holds "Manage lives"
		private _t = time + 40;
		waitUntil {sleep 1; (_uid in PTF_Lives_admins) || {time > _t}};
		(format ["C1 admin %1 (admins %2)", _uid in PTF_Lives_admins, PTF_Lives_admins]) call _say;
		sleep 2;
		"billet.go('app:ptf_lives')" call _js;
		sleep 2;
		["tab"] call _probe;
		sleep 1;
		(format ["snap %1", "lives_tab"]) call _say;
		sleep 1.5;
		// clicks, as a player makes them
		(format ["document.querySelector('[data-appact=""add""][data-key=""%1""]').click()", _uid]) call _js;
		sleep 3;
		(format ["C1 after +: %1", call _mine]) call _say;
		(format ["document.querySelector('[data-appact=""sub""][data-key=""%1""]').click()", _uid]) call _js;
		sleep 3;
		(format ["C1 after -: %1", call _mine]) call _say;
		"document.querySelectorAll('[data-appstep=""start""]')[1].click()" call _js;
		sleep 3;
		(format ["C1 after starting +: start %1", PTF_Lives_start]) call _say;
		"document.querySelectorAll('[data-appstep=""start""]')[0].click()" call _js;
		sleep 3;
		(format ["C1 after starting -: start %1", PTF_Lives_start]) call _say;
		"document.querySelector('[data-apptoggle=""on""][data-v=""0""]').click()" call _js;
		sleep 3;
		(format ["C1 after Off: on %1", PTF_Lives_on]) call _say;
		["tab_off"] call _probe;
		sleep 1;
		(format ["snap %1", "lives_tab_off"]) call _say;
		sleep 1.5;
		"document.querySelector('[data-apptoggle=""on""][data-v=""1""]').click()" call _js;
		sleep 3;
		(format ["C1 after On: on %1", PTF_Lives_on]) call _say;
		"billet.go('home')" call _js;
		sleep 3;
		["home2"] call _probe;
		sleep 1;
		call blk_fnc_tabletToggle;
		sleep 2;

		// death 1: one life left, back in after the delay
		player setDamage 1;
		sleep 3;
		(format ["C1 died once: %1", call _mine]) call _say;
		(format ["C1 respawned %1: %2", 20 call _waitAlive, call _mine]) call _say;
		sleep 3;

		// death 2: none left, held as a spectator
		player setDamage 1;
		sleep 8;
		(format ["C1 died twice: %1, alive %2, respawn in %3, spectating %4, ACE spectator %5, TFAR spectator %6",
			call _mine, alive player, playerRespawnTime, PTF_Lives_spectating,
			missionNamespace getVariable ["ace_spectator_isSet", "-"], player getVariable ["TFAR_forceSpectator", "-"]]) call _say;
		(format ["snap %1", "lives_out"]) call _say;
		sleep 1.5;
		sleep 10;
		(format ["C1 still out after 10 s: alive %1", alive player]) call _say;

		// an admin gives a life (the Lives tab's +): respawns on its own
		["action", "add", _uid, ""] call PTF_Lives_fnc_tablet;
		(format ["C1 given a life, respawned %1: %2, spectating %3, ACE spectator %4",
			30 call _waitAlive, call _mine, PTF_Lives_spectating, missionNamespace getVariable ["ace_spectator_isSet", "-"]]) call _say;
		sleep 4;

		// unconscious, then the game goes away
		[player, true] call ace_medical_fnc_setUnconscious;
		sleep 4;
		(format ["C1 unconscious: %1 (%2)", player getVariable ["ACE_isUnconscious", false], lifeState player]) call _say;
		profileNamespace setVariable ["livestest_phase", 2];
		saveProfileNamespace;
		"C1 DROP" call _say;
	} else {
		profileNamespace setVariable ["livestest_phase", nil];
		saveProfileNamespace;
		(format ["C2 joined: %1", call _mine]) call _say;
		sleep 8;
		(format ["C2 after joining: %1, alive %2, spectating %3", call _mine, alive player, PTF_Lives_spectating]) call _say;
		(format ["snap %1", "lives_rejoin"]) call _say;
		sleep 1.5;
		// an admin switches Lives off: everyone respawns
		["action", "on", "", "0"] call PTF_Lives_fnc_tablet;
		(format ["C2 Lives off, respawned %1: %2, spectating %3", 30 call _waitAlive, call _mine, PTF_Lives_spectating]) call _say;
		["action", "on", "", "1"] call PTF_Lives_fnc_tablet;
		sleep 3;
		"C2 DONE" call _say;
	};
};
