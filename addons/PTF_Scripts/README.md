# PTF_Scripts

Shared SQF for the mod: insignia, healing and gesture actions, the ACE
self-action markers, vehicle spawners and salvage, and the CBA settings that
drive them. Root of most of the scripted behaviour in PTF Core.

## Remote execution — what missions have to whitelist

Two functions run server-authoritatively and forward themselves with
`remoteExec`, and both report back to the caller with `remoteExec ["hint", …]`:

| Entry | Kind | Target | Why |
|-------|------|--------|-----|
| `PTF_fnc_SpawnFunction` | function | server (`2`) | vehicle must be server-owned for JIP, and the ticket pool must not be raced |
| `PTF_fnc_Salvage` | function | server (`2`) | `deleteVehicle` on a server-owned aircraft, plus the same ticket pool |
| `hint` | command | clients (`1`) | server sends the "no tickets" / "pad blocked" / "salvaged" feedback back to whoever used the action |

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

Marker name lists (`PTF_LzNames`, `PTF_ReNames`) are **per-player** — each
player sets their own callsign list and cycles through it independently, so the
rotation index (`IDLZ` / `IDRE`) is client-local and is not broadcast. Two
players can therefore land on the same callsign; the marker *names* are still
unique (owner id plus a local counter), so the markers do not overwrite each
other. If coordinated callsigns are ever wanted, allocation has to move to the
server.

Ticket sliders (`PTF_Uh1yTickets`, `PTF_Ah1zTickets`, `PTF_PlaneTickets`,
`PTF_MQ9Tickets`) are the configured **maximum** only. CBA resets a setting to
its configured value on any settings refresh, so the live count lives in a
matching `<setting>Current` variable in `missionNamespace`. Do not write the
settings themselves from script.
