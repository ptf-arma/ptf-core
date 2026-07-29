params ["_player", "_target"];

private _vehicles = nearestObjects [player, ["Air", "LandVehicle", "Slingload_base_F", "ReammoBox_F"], 25];
private _attachments = ["USAF_PylonRack_1Rnd_AGM114R","USAF_PylonRack_1Rnd_AGM114R","USAF_PylonRack_1Rnd_AGM114R","USAF_PylonRack_1Rnd_AGM114R"];

if (
    _vehicles findIf {[_x] call ace_rearm_fnc_issource} != -1 == true
) then {
    {
        [
            "ace_pylons_setPylonLoadOutEvent",
            [_target, _foreachindex + 1, _x, [], (getPylonMagazines _target) select _foreachindex]
        ] call CBA_fnc_globalEvent;
    } forEach _attachments;
} else {
    ["A rearm vic is not within 25m"] remoteExec ["hint", player]
};
