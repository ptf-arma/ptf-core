/*
 * Shows each wearer's real ribbon rack on their dress uniform, from Billet.
 *
 * Server: spots who is wearing a dress uniform and asks billet-link for their
 * ribbons, using the UID the server itself sees for that player. No client ever
 * asks, so nobody can request or spoof anything and a mission's remote execution
 * whitelist needs no entry. billet-link publishes the answer as blk_rack_<uid>.
 *
 * Clients: put a small plate on each wearer's chest and draw their rack on it. The
 * model's own ribbon surface is too small and sits off-centre from the pocket, so it
 * stays hidden. Plates are local to each client, and kept in step on a timer because
 * other players changing clothes can't be observed.
 *
 * UI textures ignore scene lighting and even materials, so a rack would glow in the
 * dark. It is dimmed instead by the light reaching the wearer, measured with
 * getLightingAt. People sharing a rack share a drawing, and so its dimming.
 *
 * With no billet-link, or for anyone Billet can't match to a member, nothing is
 * published and the uniform shows no rack: a rack is only ever the wearer's own.
 */
#define PREFIX "PTF_Uniform_Dress_USMC_A_"
// Bottom centre of the rack, 1/8 inch above the wearer's left pocket and centred on it,
// in the frame of the chest bone. tools/dress-review/plate_test logs the bone's axes,
// which turn a position in the unit's own coordinates into these.
#define PLATE_BONE "spine3"
#define PLATE_OFFSET [-0.1032, 0.1484, 0.0319]
#define PLATE_DIR [0.1625, -0.9836, -0.0831]
#define PLATE_UP [0.0094, -0.0824, 0.9968]
// Metres across the plate, which the rack fills. Under the real 4 1/8 inches, because
// the model's pocket is narrower than a real one and the rack has to keep its proportion.
#define PLATE_SCALE 0.092
#define RANGE 150
// Light levels, read in game: sun 68000+, overcast 28000, dusk 445, a lamp 199, night 0.2.
// Full brightness from here up, fading to dark at 1, on a log scale.
#define FULL_LIGHT_LOG 2.3

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
    // Rack string to [display name, drawn], and wearer to [plate, texture].
    PTF_Dress_racks = createHashMap;
    PTF_Dress_plates = createHashMap;
    [] spawn {
        while {true} do {
            sleep 3;
            private _seen = [];
            private _levels = createHashMap;
            {
                private _unit = _x;
                private _rack = missionNamespace getVariable ("blk_rack_" + getPlayerUID _unit);
                if (!isNil "_rack" && {_rack != ""} && {alive _unit} && {(uniform _unit find PREFIX) == 0}
                    && {_unit distance positionCameraToWorld [0, 0, 0] < RANGE}) then {
                    private _key = hashValue _unit;
                    _seen pushBack _key;
                    private _texture = [_rack] call PTF_Dress_fnc_rackTexture;
                    private _entry = PTF_Dress_plates getOrDefault [_key, []];
                    if (_entry isEqualTo []) then {
                        private _plate = createVehicleLocal ["UserTexture1m_F", getPosATL _unit];
                        _plate attachTo [_unit, PLATE_OFFSET, PLATE_BONE, true];
                        _plate setVectorDirAndUp [PLATE_DIR, PLATE_UP];
                        _plate setObjectScale PLATE_SCALE;
                        _entry = [_plate, ""];
                        PTF_Dress_plates set [_key, _entry];
                    };
                    _entry params ["_plate", "_current"];
                    if (_current != _texture) then {
                        _plate setObjectTexture [0, _texture];
                        _entry set [1, _texture];
                    };
                    getLightingAt _unit params ["", "_ambient", "", "_dynamic"];
                    _levels set [_rack, 0 max ((log ((_ambient + _dynamic) max 1)) / FULL_LIGHT_LOG) min 1];
                    // Crew models are hidden in many vehicles, and a plate wouldn't be.
                    _plate hideObject (vehicle _unit != _unit);
                };
            } forEach allPlayers;

            // Wearers who changed clothes, left, died, lost their ribbons or went out of range.
            {
                if !(_x in _seen) then {
                    deleteVehicle (_y select 0);
                    PTF_Dress_plates deleteAt _x;
                };
            } forEach (+PTF_Dress_plates);

            // A display only exists once a plate using it has been on screen, so racks
            // are drawn on a later pass, and again if the game has dropped the display.
            {
                _y params ["_name", "_drawn", ["_shown", -1]];
                private _display = findDisplay _name;
                if (isNull _display) then {
                    _y set [1, false];
                } else {
                    if (!_drawn) then {
                        [_display, _x] call PTF_Dress_fnc_rackDraw;
                        _y set [1, true];
                        _shown = -1;
                    };
                    private _level = _levels getOrDefault [_x, _shown];
                    if (abs (_level - _shown) > 0.03) then {
                        {_x ctrlSetTextColor [_level, _level, _level, 1]} forEach (_display getVariable ["PTF_Dress_pictures", []]);
                        displayUpdate _display;
                        _y set [2, _level];
                    };
                };
            } forEach PTF_Dress_racks;
        };
    };
};
