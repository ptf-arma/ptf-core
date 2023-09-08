params ["_player", "_target"];

private _vehicles = nearestObjects [player, ["Air", "LandVehicle", "Slingload_base_F", "ReammoBox_F"], 25];
_attachments = ["FIR_AIM9X_P_1rnd_M","FIR_APKWS_M247_P_7rnd_M","FIR_GBU16_Navy_P_1rnd_M","FIR_ATFLIR_3_P_1rnd_M","FIR_FA18_Fueltank_P_1rnd_M","FIR_ASQ173LST_P_1rnd_M","FIR_GBU16_Navy_P_1rnd_M","FIR_APKWS_M247_P_7rnd_M","FIR_AIM9X_P_1rnd_M"];

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

