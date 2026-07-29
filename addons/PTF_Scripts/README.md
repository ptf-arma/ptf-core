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
