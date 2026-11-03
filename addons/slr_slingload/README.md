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
- The fitting's `RopeBreak` handler only acts on the fitting's owner; the
  per-machine `RopeAttach` handler that flooded the server with `localise`
  events is gone (the hook-up handles ownership itself).

Each SLR rope now records its end object and points (`slr_slingload_target4Rope`,
`..._sourcePoint4Rope`, `..._targetPoint4Rope`, `..._cargo4Rope`,
`..._hook4Rope`) so it can be recreated. Ropes without them (vanilla sling
loading, ACE fast-roping) are never touched.
