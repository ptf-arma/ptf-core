# Ground-Based Sling Load Rigging

Custom load rigging and attaching of helicopter sling loads.

PTF fork
--------

Forked into PTF Core from upstream
[ampersand38/sling-load-rigging](https://github.com/ampersand38/sling-load-rigging)
at `d40087e` (1.1.17, the version PTF already shipped), MIT licence (`LICENSE`).
Prefix and CfgPatches names are unchanged, so it drops in for the old reupload.
Version is 1.1.17.1. Changes, all for multiplayer locality:

- **Hook ropes are created on the aircraft owner's machine.** Upstream created
  them on the rigger's machine and tried to `setOwner` the ropes afterwards, so
  rope, aircraft and cargo could end up simulated on three different machines.
  `attachCargo` now asks the server (`slr_slingload_hookCargo`) to move the
  cargo to the aircraft's owner, and that machine runs `createHookRopes`.
- **Ropes follow the aircraft to a new owner.** When the pilot changes, the
  server moves the slung cargo to the new owner (`slr_slingload_claimCargo`)
  and `takeOverRopes` recreates each rope there before destroying the old one.
- **Picking up someone else's fitting moves it to you**, and its ropes are
  recreated on your machine the same way.
- **Ropes are destroyed on the machine that owns them** (`destroyRope`), so
  crew other than the pilot can release cargo and remove rigging reliably.
- **Adjusting rope length tracks the target length.** Upstream read
  `ropeLength` straight after sending `ropeUnwind` to the rope's owner, so the
  readout, and the length reused when hooking to an aircraft, were stale.
- **New ropes can't snap the load into the aircraft.** Hook ropes and ropes
  recreated on a change of owner go through `createRope`. A rope created
  shorter than the gap between its ends snaps tight at once, so it starts just
  long enough to reach, then winds in to its target length at 1 m/s.
- **Rope takeover is idempotent and re-checked**: a replaced rope is never
  recreated twice, and the machine that created hook ropes checks two seconds
  later that it still owns the aircraft (if not, it asks for a takeover).
- **The release keybind runs the same permission check as the ACE action**,
  and you can't pick up a fitting someone else is holding.
- **Overload warning**: while you hold a fitting, "Attach Cargo" turns red and
  reads e.g. "Attach Cargo (OVERLOAD 17.2 / 16.3 t)" if the load, plus what the
  aircraft already carries, is over its rated `slingLoadMaxCargoMass`. It is a
  warning, not a block. The pilot also gets a hint when an overloaded hook-up
  lands on their aircraft. `checkLoad` computes it, using PTF Core's
  sling-mass rule when present; PTF's "Sling info" readout uses it too.
- **Dual-point hook-up**: on aircraft with forward and aft hooks (CH-53,
  MV-22, CH-47 and the rest of `slr_customHooks`), "Attach Cargo" has a
  "Dual Point (Forward + Aft)" child for loads rigged with two or more lift
  points. The points nearer the aircraft's nose go to the forward hook and
  the rest to the aft hook, so long loads hang lined up with the aircraft and
  don't spin. Releasing one hook leaves the load on the other.
- **Loads that would hit each other are refused** (`hookConflict`). A second
  load can only go on an aircraft if, for each pair of hooks the two loads
  use, the hooks are further apart than the loads' horizontal half-diagonals
  added together. On the CH-53, whose hooks are within 3.1 m of each other,
  that means one vehicle at a time, though two small pallets fit forward and
  aft. Two loads pressed together on ropes can blow up the physics and crash
  the game. `attachCargo` checks before the fitting is touched, and the
  aircraft's owner checks again, because two players can hook up in the same
  second.
- **Occupied vehicles can't be hooked.** The engine won't hand a vehicle with
  anyone inside to the aircraft's owner, so its ropes would be simulated on
  one machine and the vehicle on another. For the same reason, if the cargo
  hasn't arrived after 3 s the hook-up is refused instead of creating the
  ropes anyway. Refusals after the fitting is gone tell the rigger to rig
  again (`hookRefused`).
- **The fitting is deleted only once its ropes are gone**, which may take a
  network round trip when another machine owns them.
- **Public `slr_slingload_fnc_getHookPositions`** `[heli]` returns the
  aircraft's cargo hook positions in model space (`[main, forward, aft]` from
  `slr_customHooks`, else the config sling point). SLR's own attach code uses
  it, so other mods (e.g. a hook camera) find exactly the same points.
- The server only moves apex fittings on a client's `claimObject` request.
- `Plane_Base_F` is forward-declared instead of redefined (upstream's empty
  body reset every plane's parent class).
- The fitting's `RopeBreak` handler only acts on the fitting's owner; the
  per-machine `RopeAttach` handler that flooded the server with `localise`
  events is gone (the hook-up handles ownership itself).

Each SLR rope now records its end object and points (`slr_slingload_target4Rope`,
`..._sourcePoint4Rope`, `..._targetPoint4Rope`, `..._cargo4Rope`,
`..._hook4Rope`) so it can be recreated. Ropes without them (vanilla sling
loading, ACE fast-roping) are never touched.
