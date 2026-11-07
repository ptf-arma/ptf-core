// Per-class init handlers, attached through CBA XEH.
// Do NOT put these back in a bare `class EventHandlers { ... }` inside the
// vehicle class: that replaces the parent's EventHandlers, dropping CBA's
// CBA_Extended_EventHandlers (so no XEH/class event handler ever runs on the
// aircraft, including Sling Load Rigging's) and RHS's own handlers.
class Extended_Init_EventHandlers {
    class PTF_CH53_Ramp {
        class PTF_slingloading {
            init = "[_this select 0] call PTF_fnc_slingloading";
        };
    };
    class PTF_CH53_Cargo {
        class PTF_slingloading {
            init = "[_this select 0] call PTF_fnc_slingloading";
        };
    };
    class PTF_MV22_Ramp {
        class PTF_slingloading {
            init = "[_this select 0] call PTF_fnc_slingloading";
        };
    };
    class PTF_MV22_Cargo {
        class PTF_slingloading {
            init = "[_this select 0] call PTF_fnc_slingloading";
        };
    };
    class PTF_MV22_Minigun {
        class PTF_slingloading {
            init = "[_this select 0] call PTF_fnc_slingloading";
        };
    };
    // Server only: equipFRIES createVehicle's a global FRIES object, so
    // calling it on every machine would stack one FRIES per client.
    class PTF_UH1Y {
        class PTF_equipFRIES {
            serverInit = "[_this select 0] call ace_fastroping_fnc_equipFRIES";
        };
    };
    class PTF_UH1Y_Unarmed {
        class PTF_equipFRIES {
            serverInit = "[_this select 0] call ace_fastroping_fnc_equipFRIES";
        };
    };
};
