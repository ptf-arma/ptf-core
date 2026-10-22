# PTF_Scripts

Shared SQF for the mod: insignia, healing and gesture actions, the ACE
self-action markers, vehicle spawners and salvage, and the CBA settings that
drive them. Root of most of the scripted behaviour in PTF Core.

## Remote execution — what missions have to whitelist

Four functions run server-authoritatively and forward themselves with
`remoteExec`, and all of them report back to the caller with
`remoteExec ["hint", …]`:

| Entry | Kind | Target | Why |
|-------|------|--------|-----|
| `PTF_fnc_SpawnFunction` | function | server (`2`) | vehicle must be server-owned for JIP, and the ticket pool must not be raced |
| `PTF_fnc_Salvage` | function | server (`2`) | `deleteVehicle` on a server-owned aircraft, plus the same ticket pool |
| `PTF_fnc_lz` | function | server (`2`) | callsigns come from one canonical pool; two players marking at once must not get the same one |
| `PTF_fnc_re` | function | server (`2`) | same pool, resupply callsigns |
| `ace_medical_fnc_addDamageToUnit` | function | clients (`1`) | beanbag leg damage has to run where the victim is local |
| `hint` | command | clients (`1`) | server sends the "no tickets" / "pad blocked" / "salvaged" / "created LZ" feedback back to whoever used the action |

By default Arma permits these, so nothing has to be done for a mission that
does not restrict remote execution. **If a mission's `description.ext` defines
`CfgRemoteExec`, it must list all three or the actions fail silently** — the
player clicks, nothing spawns, and there is no error.

```cpp
class CfgRemoteExec {
    class Functions {
        mode = 1;
        class PTF_fnc_SpawnFunction { allowedTargets = 2; };
        class PTF_fnc_Salvage       { allowedTargets = 2; };
    };
    class Commands {
        mode = 1;
        class hint { allowedTargets = 1; };
    };
};
```

### Why this is not shipped in the mod's config.cpp

It would not work. `CfgRemoteExec` is resolved `missionConfigFile` >
`campaignConfigFile` > `configFile`, and an addon's `config.cpp` only ever
reaches `configFile`. A `description.ext` definition replaces the whole class
rather than merging into it, so the moment a mission defines its own whitelist
anything the mod declared is ignored. (A mission that wants to keep it can
`import CfgRemoteExec as …;` and inherit, but that is a mission-side decision.)

In the other direction it is not merely useless but risky: every addon's
`CfgRemoteExec` merges into the single `configFile` tree and `mode` is taken
from the last config parsed, so a `mode` declared here could change remote
execution behaviour for the ~40 other PBOs in the repack.

## CBA settings

Marker name lists (`PTF_LzNames`, `PTF_ReNames`) are **server-forced**
(`isGlobal = true`). The server reads them to allocate callsigns from one
canonical pool, so every machine has to agree on the list — per-player lists and
unique unit-wide callsigns are mutually exclusive, and the unit chose unique
callsigns.

`PTF_fnc_lz` and `PTF_fnc_re` forward to the server, which calls
`PTF_fnc_allocMarkerName` and creates the marker itself (`createMarker` is
global and JIP-safe). No two players can be handed the same callsign, however
close together they mark.

Allocation scans `allMapMarkers` for the marker each callsign would own rather
than advancing a counter, so **recycling is automatic** — delete an LZ marker
and its callsign is free again on the next placement. There is no
`MarkerDeleted` handler to register and no allocation table that can drift out
of step with the map; the map is the state. Internal marker names are
`PTF_lz_<index>` / `PTF_re_<index>`, so anything that deletes markers by name
should expect that shape.

If every callsign in the list is on the map, allocation falls back to a numbered
one (`PTF_lz_x1`, labelled "LZ 1"). Running out of names costs you a tidy
callsign, not the marker.

Ticket sliders (`PTF_Uh1yTickets`, `PTF_Ah1zTickets`, `PTF_PlaneTickets`,
`PTF_MQ9Tickets`) are the configured **maximum** only. CBA resets a setting to
its configured value on any settings refresh, so the live count lives in a
matching `<setting>Current` variable in `missionNamespace`. Do not write the
settings themselves from script.

## Respawn loadout

Arma does not restore a unit on respawn, it builds a **new** one from the config
of whatever class the mission's playable slot uses. Gear applied in Eden, at
mission start, or out of an arsenal is not part of that class, so the player
comes back in whatever the class itself declares — and PTF Core defines no
BLUFOR man classes (`PTF_OPFOR` bakes kit into config; nothing equivalent exists
for players), so that is a vanilla or stock RHS kit.

Two server-forced CBA settings under **Paramarine Task Force → Respawn** override
that:

| Setting | Type | Default | Effect |
|---------|------|---------|--------|
| `PTF_RespawnLoadoutEnabled` | CHECKBOX | **off** | Master switch. Off means respawn behaves exactly as it always has. |
| `PTF_RespawnLoadoutName` | LIST | `Rifleman D` | Which kit from `defaultloadouts.hpp` respawning players get. |

Both are `isGlobal` — one server-wide rule, and a client must not be able to
opt itself into a better kit than everyone else.

### How it is wired

`XEH_postInit.sqf` adds an `EntityRespawned` mission EH on machines with an
interface, filters it to the local player, and calls `PTF_fnc_respawnLoadout`
via `CBA_fnc_execNextFrame`. Two deliberate choices there:

- **`EntityRespawned`, not an init EH.** It fires only on an actual respawn,
  never on initial spawn or JIP, so a mission maker's Eden loadout is never
  touched. Only the vanilla-kit-on-death case is.
- **A frame late.** ACE's own respawn gear handling (`ace_respawn_savePreDeathGear`)
  and any mission-side `onPlayerRespawn.sqf` run on the respawn frame, and the
  last write to the unit's loadout wins. Going next frame makes PTF Core that
  last write instead of a coin toss.

The kit is applied with `[_unit, _loadout, true] call CBA_fnc_setLoadout` — the
`true` refills partially-loaded magazines, so a forced respawn kit never starts
dry.

### Missions that own their own respawn gear

A mission that already handles respawn loadouts — an `onPlayerRespawn.sqf`,
`respawnTemplates[] = {"MenuInventory"}` with a `CfgRespawnInventory`, or a
training map that wants the Eden slot's kit — opts out in `init.sqf`:

```sqf
PTF_RespawnLoadoutDisabled = true;
```

This matters because the setting is server-wide: without an opt-out, turning it
on would silently overwrite the respawn handling of **every** mission on the
server, side ops and training included.

### Interaction with ACE

ACE ships `ace_respawn_savePreDeathGear`, which restores the gear a player died
in (depleted magazines and all). It solves an overlapping problem from the other
direction. Pick one — with both on, PTF Core's fixed kit lands a frame later and
wins, which makes the ACE setting look broken.

## Default loadouts

`fnc/arsenal/defaultloadouts.hpp` is the 50 PTF role kits. It is **pure data** —
a bare array of `[name, loadout]` pairs with no engine calls — so `tests/` can
interpret it with sqflint (see `tests/test_default_loadouts.py`). Each `loadout`
is either a bare 10-element `getUnitLoadout` array or ACE's
`[loadout, extendedInfo]` pair; `ace_arsenal_fnc_addDefaultLoadout` and
`CBA_fnc_setLoadout` both accept either.

It is built **once per machine** in `XEH_preInit.sqf` into `PTF_defaultLoadouts`
(ordered array) and `PTF_defaultLoadoutsMap` (name → loadout HashMap). An
`#include` rather than a function call, because the `PTF_RespawnLoadoutName`
LIST setting needs the kit names while CBA settings are still being registered,
and that is earlier than any assumption about CfgFunctions compilation order is
worth making.

`PTF_fnc_registerDefaultLoadouts` hands the kits to ACE, guarded so it only runs
for the first arsenal on the map. Until 2026-08 the data file was `#include`d
into all three arsenal init functions instead, which re-pushed all 50 kits
through `ace_arsenal_fnc_addDefaultLoadout` for every arsenal and crate placed —
harmless (ACE overwrites by name) but 30 KB of array literal evaluated dozens of
times to no effect.

Kit names are user-visible twice over: in the arsenal's loadout list and in the
`PTF_RespawnLoadoutName` setting. Renaming one silently resets any server that
had it selected, and `Rifleman D` in particular is the setting's default index.
