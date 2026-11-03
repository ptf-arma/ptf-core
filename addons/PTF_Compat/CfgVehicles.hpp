// CBA XEH support for the Peral vehicles PTF_ACV* and PTF_MK23* inherit from.
//
// Peral gives these classes a plain `class Eventhandlers { init = ...; }`
// with no parent, which drops the CBA_Extended_EventHandlers they would have
// inherited. CBA then logs "does not support Extended Event Handlers" and
// falls back to polling for them, and class event handlers (ACE's, SLR's,
// PTF's sling-mass `Local` handler) do not attach reliably.
//
// This is CBA's documented compat fix: merge the XEH subclass into Peral's
// existing Eventhandlers. Peral's own init/GetIn/... entries are untouched
// (the engine runs an EventHandlers class's own entries and every subclass's),
// and each class keeps its real parent. Peral_ACV and Peral_USMC_Gear are in
// requiredAddons, so this loads after them.
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
