// Mission-placed boxes on an interface machine: the usual real-world case.
ptfui_log = { diag_log format ["PTFUI %1", _this]; };
[] spawn {
    disableUserInput true;
    waitUntil {time > 1};
    sleep 6;
    format ["start registered=%1 kits=%2", missionNamespace getVariable ["PTF_defaultLoadoutsRegistered", false], count (missionNamespace getVariable ["ace_arsenal_defaultLoadoutsList", []])] call ptfui_log;
    private _describe = {
        params ["_o"];
        private _acts = (_o getVariable ["ace_interact_menu_actions", []]) apply {(_x select 0) select 0};
        private _sub = [];
        {_sub append ((_x select 1) apply {(_x select 0) select 0})} forEach (ace_interact_menu_ActNamespace getOrDefault [typeOf _o, []]);
        format ["%1 xeh=%2 arsenalAction=%3 items=%4 classMainActions=%5 slingInfo=%6 slrRig=%7 cargo=%8 spaceLeft=%9",
            typeOf _o, _o getVariable ["cba_xeh_isInitialized", false], "ace_arsenal_interaction" in _acts,
            count str (_o getVariable ["ace_arsenal_virtualItems", createHashMap]),
            count ((ace_interact_menu_ActNamespace getOrDefault [typeOf _o, []])),
            "PTF_slingInfo" in _sub, "slr_slingload_rig" in _sub,
            count (_o getVariable ["ace_cargo_loaded", []]), _o getVariable ["ace_cargo_space", "nil"]] call ptfui_log;
    };
    private _all = [box_0, box_1, box_2, box_3, box_4];
    {[_x] call _describe} forEach _all;
    {
        player setPos (_x modelToWorld [0, -2, 0]);
        sleep 1;
        [_x, player] call ace_arsenal_fnc_openBox;
        private _t = time;
        waitUntil {sleep 0.2; !isNull (findDisplay 1127001) || {time > _t + 25}};
        sleep 3;
        private _d = findDisplay 1127001;
        format ["openBox %1 display=%2 virtualItems=%3 kits=%4", typeOf _x, !isNull _d, count str (missionNamespace getVariable ["ace_arsenal_virtualItems", []]), count (missionNamespace getVariable ["ace_arsenal_defaultLoadoutsList", []])] call ptfui_log;
        if (!isNull _d) then {_d closeDisplay 2};
        _t = time;
        waitUntil {sleep 0.2; isNull (findDisplay 1127001) || {time > _t + 15}};
        sleep 3;
    } forEach [box_0, box_1];
    "DONE" call ptfui_log;
    disableUserInput false;
};
