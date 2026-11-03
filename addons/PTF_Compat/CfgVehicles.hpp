class CfgVehicles {
    // --- Restore a vanilla parent -------------------------------------------
    // NDS_M224_mortar redeclares `class Mortar_01_base_F: StaticMortar
    // { class Turrets { class MainTurret; }; }` - a forward declaration with
    // a body, which resets vanilla Mortar_01_base_F/Turrets' parent
    // ('Turrets' -> '') for the Mk6 and every mortar built on it, the M224
    // included. Put it back.
    class StaticWeapon;
    class StaticMortar: StaticWeapon {
        class Turrets;
    };
    class Mortar_01_base_F: StaticMortar {
        class Turrets: Turrets {};
    };

    // --- CBA XEH support ----------------------------------------------------
    // These classes give themselves a plain `class EventHandlers { ... }`
    // with no parent, dropping the CBA_Extended_EventHandlers they would have
    // inherited. CBA then logs "does not support Extended Event Handlers",
    // falls back to polling for them, and class event handlers (ACE's, SLR's,
    // PTF's) do not attach reliably.
    //
    // CBA's documented compat fix: merge the XEH subclass into the existing
    // EventHandlers. The owner's own init/GetIn/... entries are untouched (the
    // engine runs an EventHandlers class's own entries and every subclass's),
    // and each class keeps its real parent. A class that redeclares its own
    // EventHandlers needs its own entry; subclasses that don't, inherit it.

    // Peral ACV / MK23: parents of PTF_ACV* and PTF_MK23*
    class Wheeled_APC_F;
    class Peral_ACV_Base_F: Wheeled_APC_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
        SLX_XEH_DISABLED = 0;
    };
    class Peral_MTVRBase;
    class Peral_MK23: Peral_MTVRBase {
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
        SLX_XEH_DISABLED = 0;
    };
    class Peral_MK23T: Peral_MTVRBase {
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
        SLX_XEH_DISABLED = 0;
    };

    // NDS M224 mortar (the AI variant redeclares its own EventHandlers)
    class NDS_M224_mortar_base: Mortar_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
        SLX_XEH_DISABLED = 0;
    };
    class NDS_M224_mortar;
    class NDS_M224_mortar_AI: NDS_M224_mortar {
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
        SLX_XEH_DISABLED = 0;
    };

    // APOBS
    class Car;
    class MD_APOBS_deployed: Car {
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
        SLX_XEH_DISABLED = 0;
    };

    // Peral LST lights (each redeclares an empty EventHandlers)
    class ThingX;
    class LST_Light_01: ThingX {
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
        SLX_XEH_DISABLED = 0;
    };
    class LST_Light_02: LST_Light_01 {
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
        SLX_XEH_DISABLED = 0;
    };
    class LST_Light_03: LST_Light_01 {
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
        SLX_XEH_DISABLED = 0;
    };
    class LST_Light_04: LST_Light_01 {
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
        SLX_XEH_DISABLED = 0;
    };
    class LST_Light_05: LST_Light_01 {
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
        SLX_XEH_DISABLED = 0;
    };

    // RHICC boat
    class Boat_Armed_01_base_F;
    class RHICC_MAIN: Boat_Armed_01_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };
        SLX_XEH_DISABLED = 0;
    };
};
