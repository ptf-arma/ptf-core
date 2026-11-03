[
    "Sling Load Rigging", "slr_slingloading_releaseCargo", localize LSTRING(ReleaseCargo),{
        // PTF fork: same permission check as the ACE action (crew, or a
        // passenger carrying a cargo sling). destroyRope now really releases
        // from any seat, so an unchecked key would let any passenger drop it.
        private _unit = call CBA_fnc_currentUnit;
        private _heli = vehicle _unit;
        if ([_heli, _unit] call slr_slingload_fnc_canReleaseCargo) then {
            [_heli] call slr_slingload_fnc_releaseCargo;
        };
    }
] call CBA_fnc_addKeybind;
