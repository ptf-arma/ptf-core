// Reports everything the crate/arsenal fix touches, from whichever machine this runs on.
ptf_tag = if (isDedicated) then {"SERVER"} else {if (hasInterface) then {"CLIENT"} else {format ["HC_%1", name player]}};
ptf_boxes = ["box_0","box_1","box_2","box_3","box_4","box_5","box_6","box_7","box_8","late_0","late_1","late_2","late_3","late_4","late_5","late_6"];
ptf_report = {
    params ["_label"];
    {
        private _o = missionNamespace getVariable [_x, objNull];
        if (!isNull _o) then {
            private _loaded = _o getVariable ["ace_cargo_loaded", []];
            private _counts = [];
            {
                private _i = _x;
                _counts pushBack format ["%1=%2", _i, {_x isEqualTo _i} count _loaded];
            } forEach (_loaded arrayIntersect _loaded);
            private _acts = (_o getVariable ["ace_interact_menu_actions", []]) apply {(_x select 0) select 0};
            private _sub = [];
            {_sub append ((_x select 1) apply {(_x select 0) select 0})} forEach ((missionNamespace getVariable ["ace_interact_menu_ActNamespace", createHashMap]) getOrDefault [typeOf _o, []]);
            diag_log format ["PTFSMOKE %1 %2 %3 %4 cargo=%5 spaceLeft=%6 xeh=%7 vItemsLen=%8 arsenalAction=%9 slingInfo=%10 slrRig=%11 jip=%12",
                ptf_tag, _label, _x, typeOf _o, _counts, _o getVariable ["ace_cargo_space", "nil"],
                _o getVariable ["cba_xeh_isInitialized", false],
                count str (_o getVariable ["ace_arsenal_virtualItems", createHashMap]),
                "ace_arsenal_interaction" in _acts, "PTF_slingInfo" in _sub, "slr_slingload_rig" in _sub,
                _o getVariable ["ace_arsenal_initBoxJIP", "none"]];
        };
    } forEach ptf_boxes;
    diag_log format ["PTFSMOKE %1 %2 loadoutsRegistered=%3 defaultLoadouts=%4 players=%5",
        ptf_tag, _label, missionNamespace getVariable ["PTF_defaultLoadoutsRegistered", false],
        count (missionNamespace getVariable ["ace_arsenal_defaultLoadoutsList", []]), count allPlayers];
};

// ---- whole-config comparison, server only ----
ptf_deep = {
    params ["_cfg", "_path", "_out"];
    {
        private _n = configName _x;
        if (isClass _x) then {
            _out pushBack format ["%1/%2:%3", _path, _n, configName inheritsFrom _x];
            [_x, _path + "/" + _n, _out] call ptf_deep;
        } else {
            _out pushBack format ["%1/%2=%3", _path, _n, if (isArray _x) then {str getArray _x} else {if (isNumber _x) then {getNumber _x} else {getText _x}}];
        };
    } forEach configProperties [_cfg, "true", true];
};
if (isDedicated) then {
    isNil {
        private _ours = (configProperties [configFile >> "CfgPatches", "isClass _x", true]) apply {configName _x};
        _ours = _ours select {
            private _p = toLowerANSI _x;
            (_p find "ptf_") == 0 || {_p in ["bettir_ptf","drc_custom_billboards","riku_class_a","slr_main","slr_slingload","turret_enhanced_2026"]}
        };
        diag_log format ["CFGDUMP patches %1", _ours];
        private _t = diag_tickTime;
        private _n = 0;
        private _deepN = 0;
        {
            private _sec = _x;
            {
                private _c = _x;
                _n = _n + 1;
                private _src = configSourceAddonList _c;
                diag_log format ["CFGDUMP|S|%1|%2|%3|%4|%5|%6|%7|%8", _sec, configName _c, configName inheritsFrom _c,
                    getNumber (_c >> "scope"), getNumber (_c >> "scopeCurator"), getNumber (_c >> "scopeArsenal"),
                    getText (_c >> "model"), getText (_c >> "displayName")];
                if (_src findIf {_x in _ours} > -1) then {
                    _deepN = _deepN + 1;
                    private _o = [];
                    [_c, "", _o] call ptf_deep;
                    _o sort true;
                    diag_log format ["CFGDUMP|D|%1|%2|%3|%4", _sec, configName _c, count _o, hashValue (_o joinString "~")];
                };
            } forEach ("true" configClasses (configFile >> _sec));
        } forEach ["CfgVehicles","CfgWeapons","CfgMagazines","CfgAmmo","CfgGlasses"];
        diag_log format ["CFGDUMP done classes=%1 deep=%2 secs=%3", _n, _deepN, diag_tickTime - _t];
    };
};

[] spawn {
    waitUntil {time > 3};
    if (isDedicated) then {
        sleep 10;
        ["prejoin"] call ptf_report;
        diag_log "PTFSMOKE SERVER READY";
        private _t = diag_tickTime;
        waitUntil {sleep 1; (count allPlayers > 0) || {diag_tickTime > _t + 400}};
        diag_log format ["PTFSMOKE SERVER firstJoin players=%1", allPlayers apply {name _x}];
        sleep 30;
        ["onejoin"] call ptf_report;
        // Placed mid-mission, the way Zeus does it: init runs on every connected machine.
        late_0 = createVehicle ["PTF_Cargo_Large_VicBox", [1800,5640,0], [], 0, "CAN_COLLIDE"]; publicVariable "late_0";
        late_1 = createVehicle ["PTF_Cargo_Vic", [1812,5640,0], [], 0, "CAN_COLLIDE"]; publicVariable "late_1";
        late_2 = createVehicle ["PTF_Cargo_Tracks", [1824,5640,0], [], 0, "CAN_COLLIDE"]; publicVariable "late_2";
        late_3 = createVehicle ["PTF_Standard_Arsenal", [1836,5640,0], [], 0, "CAN_COLLIDE"]; publicVariable "late_3";
        late_4 = createVehicle ["PTF_Standard_Arsenal_No_Ammo", [1848,5640,0], [], 0, "CAN_COLLIDE"]; publicVariable "late_4";
        late_5 = createVehicle ["PTF_Pso_Arsenal", [1860,5640,0], [], 0, "CAN_COLLIDE"]; publicVariable "late_5";
        late_6 = createVehicle ["PTF_Limited_Arsenal", [1872,5640,0], [], 0, "CAN_COLLIDE"]; publicVariable "late_6";
        sleep 30;
        ["placed"] call ptf_report;
        // Empty a crate, then have someone join: it must stay empty.
        box_1 setVariable ["ace_cargo_loaded", [], true];
        box_1 setVariable ["ace_cargo_space", 40, true];
        private _before = count allPlayers;
        ptf_stage2 = true; publicVariable "ptf_stage2";
        diag_log "PTFSMOKE SERVER HC2GO";
        _t = diag_tickTime;
        waitUntil {sleep 1; (count allPlayers > _before) || {diag_tickTime > _t + 240}};
        sleep 30;
        ["twojoin"] call ptf_report;
        ptf_server_done = true; publicVariable "ptf_server_done";
        sleep 5;
        diag_log "PTFSMOKE SERVER DONE";
    } else {
        waitUntil {sleep 1; !isNil "ptf_server_done"};
        ["final"] call ptf_report;
        diag_log format ["PTFSMOKE %1 DONE", ptf_tag];
    };
};
