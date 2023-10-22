params ["_player", "_target"];

_attachments = [];

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