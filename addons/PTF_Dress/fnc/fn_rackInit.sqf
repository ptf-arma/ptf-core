/*
 * Shows each wearer's real ribbon rack on their dress uniform, from Billet.
 *
 * Server: spots who is wearing a dress uniform and asks billet-link for their
 * ribbons, using the UID the server itself sees for that player. No client ever
 * asks, so nobody can request or spoof anything and a mission's remote execution
 * whitelist needs no entry. billet-link publishes the answer as blk_rack_<uid>.
 *
 * Clients: attach a rack model to each wearer's chest and fill its ribbon slots. The
 * model is shaped to the chest, from tools/dress-review/chest_map, and lit like any other
 * object. Racks are local to each client, and kept in step on a timer because other
 * players changing clothes can't be observed.
 *
 * With no billet-link, or for anyone Billet can't match to a member, nothing is
 * published and the uniform shows no rack: a rack is only ever the wearer's own.
 */
#define PREFIX "PTF_Uniform_Dress_USMC_A_"
#define RANGE 150

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
    // Wearer to [rack model, rack string].
    PTF_Dress_plates = createHashMap;
    [] spawn {
        private _offset = getArray (configFile >> "CfgPTFDressRibbons" >> "offset");
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
                        private _plate = createVehicleLocal ["PTF_Dress_Rack", getPosATL _unit];
                        _plate attachTo [_unit, _offset, "spine3", true];
                        _plate setVectorDirAndUp [[0, 1, 0], [0, 0, 1]];
                        _entry = [_plate, -1];
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
