params ["_player", "_target"];

private _vehicles = nearestObjects [player, ["Air", "LandVehicle", "Slingload_base_F", "ReammoBox_F"], 25];
_attachments = ["rhs_mag_Sidewinder_heli_2","FIR_APKWS_M282_P_7rnd_M","rhs_mag_M151_19_green","rhs_mag_M151_19_green","FIR_APKWS_M282_P_7rnd_M","rhs_mag_Sidewinder_heli_2","rhsusf_ANALE39_CMFlare_Chaff_Magazine_x4"];

if ( 
    _vehicles findIf {[_x] call ace_rearm_fnc_issource} != -1 == true
) then {
    {
        [
            "ace_pylons_setPylonLoadOutEvent", 
            [_target, _foreachindex + 1, _x, [], (getPylonMagazines _target) select _foreachindex + 1] 
        ] call CBA_fnc_globalEvent;
    } forEach _attachments;
} else {
    ["A rearm vic is not within 25m"] remoteExec ["hint", player]
};
