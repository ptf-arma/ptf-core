/*
 * Shows each wearer's real ribbon rack on their dress uniform, from Billet.
 *
 * Server: spots who is wearing a dress uniform and asks billet-link for their
 * ribbons, using the UID the server itself sees for that player. No client ever
 * asks, so nobody can request or spoof anything and a mission's remote execution
 * whitelist needs no entry. billet-link publishes the answer as blk_rack_<uid>.
 *
 * Clients: draw each published rack and put it on the uniform. Applied locally by
 * every client, and rechecked on a timer, because changing clothes resets it and
 * that can't be observed for other players.
 *
 * With no billet-link, or for anyone Billet can't match to a member, nothing is
 * published and the uniform shows no rack: a rack is only ever the wearer's own.
 */
#define PREFIX "PTF_Uniform_Dress_USMC_A_"
#define RIBBON_SELECTION 3

if (isServer) then {
    [] spawn {
        private _next = createHashMap;
        while {true} do {
            sleep 15;
            if (isNil "blk_fnc_rack") then { continue };
            {
                private _uid = getPlayerUID _x;
                if ((uniform _x find PREFIX) == 0 && {_uid != ""} && {time >= (_next getOrDefault [_uid, 0])}) then {
                    [_uid] call blk_fnc_rack;
                    // Awards change rarely. Sooner if no answer has arrived yet:
                    // Billet refuses a player until its heartbeat has seen them.
                    private _known = !isNil {missionNamespace getVariable ("blk_rack_" + _uid)};
                    _next set [_uid, time + ([60, 300] select _known)];
                };
            } forEach allPlayers;
        };
    };
};

if (hasInterface) then {
    PTF_Dress_racks = createHashMap;
    [] spawn {
        while {true} do {
            sleep 3;
            {
                private _rack = missionNamespace getVariable ("blk_rack_" + getPlayerUID _x);
                if (!isNil "_rack" && {(uniform _x find PREFIX) == 0}) then {
                    // Nobody with no ribbons needs anything done: config hides the rack.
                    // Someone whose last ribbon was removed is drawn as bare cloth.
                    private _current = (getObjectTextures _x) param [RIBBON_SELECTION, ""];
                    if (_rack != "" || {_current != ""}) then {
                        private _texture = [_rack] call PTF_Dress_fnc_rackTexture;
                        if (_current != _texture) then {
                            _x setObjectTexture [RIBBON_SELECTION, _texture];
                            // Set only here: on the config, a material alone brings back
                            // the model's vanilla ribbons on a hidden rack.
                            _x setObjectMaterial [RIBBON_SELECTION, getText (configFile >> "CfgPTFDressRibbons" >> "material")];
                        };
                    };
                };
            } forEach (allPlayers select {_x distance positionCameraToWorld [0, 0, 0] < 150});
            // A display only exists once a texture using it is on something, so
            // racks are drawn the pass after they are first applied.
            {
                _y params ["_name", "_drawn"];
                private _display = findDisplay _name;
                if (!isNull _display && {!_drawn}) then {
                    [_display, _x] call PTF_Dress_fnc_rackDraw;
                    _y set [1, true];
                };
                if (isNull _display) then { _y set [1, false] };
            } forEach PTF_Dress_racks;
        };
    };
};
