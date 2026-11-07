/*
 * Shows each wearer's real ribbon rack on their dress uniform, from Billet.
 *
 * Server: spots who is wearing a dress uniform and asks billet-link for their
 * ribbons, using the UID the server itself sees for that player. No client ever
 * asks, so nobody can request or spoof anything and a mission's remote execution
 * whitelist needs no entry. billet-link publishes the answer as blk_rack_<uid>.
 *
 * Clients: place a rack model on each wearer's chest every frame and fill its ribbon slots.
 * The model is shaped to the chest, from tools/dress-review/chest_map, and lit like any other
 * object. Racks are local to each client, and kept in step on a timer because other players
 * changing clothes can't be observed.
 *
 * Racks aren't hung on a bone with attachTo. Its bone following misses how far the chest bends
 * forward in the inventory pose, which Zeus puts its user in, and leaves the rack inside the
 * body. So each frame the rack is placed in a frame built from where the chest's memory points
 * are, which the drawn body does follow: across the shoulders, and up from spine3 to the neck.
 *
 * With no billet-link, or for anyone Billet can't match to a member, nothing is
 * published and the uniform shows no rack: a rack is only ever the wearer's own.
 */
#define PREFIX "PTF_Uniform_Dress_USMC_A_"
#define RANGE 150
// The rack in that chest frame, measured in the normal stance where attachTo on spine3 puts it
// right (tools/dress-review/rack_frame logs these): offset from spine3, direction and up.
#define FRAME_OFFSET [-0.1075, 0.1036, 0.0501]
#define FRAME_DIR [-0.0279, 0.9996, -0.0101]
#define FRAME_UP [-0.0105, 0.0098, 0.9999]
// How much further out the rack stands, in metres, where the coat's chest swells past it:
// with a weapon in hand, which twists the torso, and in the inventory pose, which hunches it.
// tools/dress-review/rack_pose and rack_frame found these clear every stance.
#define ARMED_CLEARANCE 0.008
#define INVENTORY_CLEARANCE 0.02

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
    // Wearer to [rack model, rack string, wearer].
    PTF_Dress_plates = createHashMap;

    addMissionEventHandler ["EachFrame", {
        {
            _x params ["_plate", "", "_unit"];
            if (!isNull _plate && {!isNull _unit} && {!isObjectHidden _plate}) then {
                private _s = _unit selectionPosition ["spine3", "Memory"];
                private _bx = vectorNormalized ((_unit selectionPosition ["rightshoulder", "Memory"])
                    vectorDiff (_unit selectionPosition ["leftshoulder", "Memory"]));
                private _bz = (_unit selectionPosition ["neck", "Memory"]) vectorDiff _s;
                _bz = vectorNormalized (_bz vectorDiff (_bx vectorMultiply (_bz vectorDotProduct _bx)));
                private _by = _bz vectorCrossProduct _bx;
                private _model = {
                    (_bx vectorMultiply (_this select 0)) vectorAdd (_by vectorMultiply (_this select 1))
                        vectorAdd (_bz vectorMultiply (_this select 2))
                };
                private _out = call {
                    if ((animationState _unit) select [0, 4] == "ainv") exitWith { INVENTORY_CLEARANCE };
                    if (currentWeapon _unit != "") exitWith { ARMED_CLEARANCE };
                    0
                };
                _plate setPosWorld (_unit modelToWorldVisualWorld (_s vectorAdd ((FRAME_OFFSET vectorAdd [0, _out, 0]) call _model)));
                _plate setVectorDirAndUp [_unit vectorModelToWorldVisual (FRAME_DIR call _model),
                    _unit vectorModelToWorldVisual (FRAME_UP call _model)];
            };
        } forEach values PTF_Dress_plates;
    }];

    [] spawn {
        while {true} do {
            sleep 3;
            private _seen = [];
            {
                private _unit = _x;
                private _rack = missionNamespace getVariable ("blk_rack_" + getPlayerUID _unit);
                if (!isNil "_rack" && {_rack != ""} && {alive _unit} && {(uniform _unit find PREFIX) == 0}
                    && {_unit distance positionCameraToWorld [0, 0, 0] < RANGE}) then {
                    private _key = hashValue _unit;
                    _seen pushBack _key;
                    private _entry = PTF_Dress_plates getOrDefault [_key, []];
                    if (_entry isEqualTo []) then {
                        // The frame handler above places it.
                        private _plate = createVehicleLocal ["PTF_Dress_Rack", getPosATL _unit];
                        _entry = [_plate, -1, _unit];
                        PTF_Dress_plates set [_key, _entry];
                    };
                    _entry params ["_plate", "_current"];
                    if !(_current isEqualTo _rack) then {
                        [_plate, _rack] call PTF_Dress_fnc_rackDraw;
                        _entry set [1, _rack];
                    };
                    // Crew models are hidden in many vehicles, and a rack wouldn't be.
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
        };
    };
};
