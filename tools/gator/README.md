# G/ATOR model pipeline

The AN/TPS-80 G/ATOR in `addons/PTF_GATOR` uses a purchased model: "AN-TPS-80 Ground Air
Radar System Deployed" by 3dmi on CGTrader (model #7108279, Royalty Free, no AI). The
licence covers using it in the mod. It does not cover publishing the source files, and
this repo is public, so **no part of the model or its textures is committed**. These
scripts build it into `ptf_gator_data.pbo` from the purchased files. That PBO ships with
the mod like the other external PBOs (`PTF_EXTERNAL_ADDONS`).

## Building the data PBO

```
set PTF_GATOR_SOURCE=C:\Users\<you>\Documents\an-tps-80-ground-air-radar-system-deployed
python tools/gator/build_data.py            # add --install to copy it into PTF_EXTERNAL_ADDONS
```

The source folder holds the archives as downloaded. The script unpacks the `.blend` and
the textures into `extracted/`, then builds into `arma/`:

- `build_model.py` runs inside Blender 5.x on the artist's `.blend`. It writes `gator.p3d`
  and `model.cfg`, plus `gator_model.json`, which records where each moving part should be
  at each phase (the in-game test checks against it).
- `build_textures.py` turns the 8192 px PBR maps into `_co`, `_nohq` and `_smdi` PAAs and
  rvmats.
- HEMTT packs and binarizes the result: `arma/ptf_gator_data.pbo`, about 28 MB.

It takes about 2 minutes. Add `--renders` to get Blender renders of the stow sequence in
`arma/review`. These are quicker to look at than the game.

## How the model is split

The artist's model comes deployed, as six merged meshes. `build_model.py` breaks them into
their loose pieces and sorts each piece into a part with the rules in `classify()`. The
positions those rules use (hinge bolt, brace pivots, jack columns, wheel centre) were
measured from the mesh and are constants at the top of the script.

| Part | Moves | Phase of `ptf_gator_deploy` |
|---|---|---|
| `jack_fl/fr/rl/rr` | rod and foot slide 0.30 m up into the cylinder | own source each: `ptf_gator_leg_<leg>` |
| `radar` | array (and the cables into its foot) folds 63 degrees forward onto the box | 0 - 1 |
| `brace_v_l/r` + `_rod` | vertical hydraulic struts stay pinned to the array and shorten from 1.67 to 0.99 m | 0 - 1 |
| `brace_d_l/r` + `_rod` | diagonal struts stay pinned and shorten until their rod is all the way in, then unpin and fold back onto the box | 0.35 - 1 |
| `wheel_1_2`, `wheel_2_2` | roll (source `wheel`) | - |
| `turntable` (box, array, struts) | turns all the way round, deployed only (source `ptf_gator_spin`, one turn per unit) | - |

Phase 1 is the artist's pose. In game the crew lowers each leg at the leg, starts the
generator, raises the array and starts it turning (ACE interactions; see
`addons/PTF_GATOR/CfgVehicles.hpp`). Packing up runs that backwards.

Notes:

- **Struts:** the struts are hydraulic cylinders and stay pinned to the bracket on the
  array's edge. Each one turns about its pivot and its rod slides to match the array. The
  diagonal ones can only shorten by 1.2 m. They reach that about 36 degrees into the fold:
  folded flat, their two pins would be 33 cm apart. At that point they unpin and fold back
  onto the box, swinging inward to lie straight. The diagonals are skewed sideways (pivot
  inboard, pin on the array's edge), so they also tilt slightly as they shorten to keep
  the pin on the bracket.
- **Strut motion in Arma:** animations are linear, so the struts follow the array in 12
  straight pieces (`STRUT_KEYS`), one animation per piece. A bone's skew animations are
  listed before its pitch ones because Arma applies them in order.
- **Spin and the generator:** turning, the array's foot (level with the hinge) sweeps
  out to 1.85 m from the turntable centre. The artist put the generator's back wall
  1.69 m away, so the two clashed whenever the array faced forward. The generator and its
  guard frame are moved 0.20 m forward along the rails (`GENERATOR_SHIFT`). The build
  checks the whole turn every 15 degrees and prints `SPIN_OVERLAP`, which should be `{}`.
- **Spin control:** `PTF_GATOR_fnc_setSpinning` starts the turn by sending the source's
  phase far ahead. Stopping lets it finish the turn it is on, so the array always stops
  facing aft, where it stows. Stowing waits until it has stopped.
- **Texture seams:** LOD 1 is the artist's mesh with flat neighbouring faces merged,
  limited to within one texture island (`dissolve_limit`, delimited by UV). That is
  lossless and cuts 457k triangles to 175k. The further LODs then edge-collapse with every
  UV break marked as a seam. Collapsing across seams is what tore the texture in the first
  build.
- **Array fold angle:** 63 degrees, not flat. At 64 degrees the array touches the box,
  and at 63 the far end sits 6 degrees up, resting just above the folded struts.
- **Jack rods:** the rod is modelled running up inside the cylinder. The part that would
  come out of the top when retracted is cut off. You can't see the cut.
- **Wheels:** PhysX cars need two axles. The real wheels are `wheel_1_2`/`wheel_2_2` (rear
  pair), and the tongue stand's caster is a narrow invisible front pair (`wheel_1_1`/
  `wheel_2_1`, memory points only).
- **Coordinates:** Blender is x left, y back, z up. The P3D gets (x, z, y). Found in game:
  `selectionPosition` then reads (-x, -z, y) of the P3D's coordinates, and Arma turns
  rotations the opposite way to Blender's right-hand rule (`ARMA_ROTATION_SIGN`).
- **LODs:** four resolution LODs (100k, 40k, 14k and 5.7k triangles). The collision LODs
  (geometry, PhysX, view, fire, shadow) are convex hulls over a grid of cells. Mass is
  5.5 t, with the centre of mass 0.3 m ahead of the axle so the stand carries some weight.

`build_model.py` prints `OVERLAP_NEW`. It lists parts that touch more at some phase than
they do deployed. Expected entries: rods inside their tubes, the vertical rods' tail ends
resting on the box top, the jack rods inside their cylinders, and the folded diagonal
struts touching the array's underside by a few triangles.

## Sounds

`tools/gator/import_sounds.py` cuts the four Pixabay recordings (kept in
`<PTF_GATOR_SOURCE>/sounds`, not committed) into `addons/PTF_GATOR/sounds`. It writes the
generator's start, idle loop and stop from one recording, the antenna hum, the motor's
opening and loop, and the leg clunk. The loops are crossfaded end into start. If a clip's
length changes, update the lengths at the top of `fn_soundLoop.sqf`.

Each client plays the sounds itself from the radar's synced state (`fn_soundLoop.sqf`), so
nothing extra goes over the network. Beyond 2.1 km from the player's camera (past the
incoming alarm's reach) it plays nothing and makes no exhaust, and does the rest (heat, fire,
tail lights) once a second instead of every frame. Each loop plays from its own invisible emitter at a
memory point (`generator`, `motor_source`, `hum_source`, `leg_*`). The hum's emitter sits
2 m in front of the array's face, which looks aft and 26 degrees up, and rides the
turntable. So the hum comes from wherever the antenna faces.

## Lights, markings, shadow

- **Lights:** the artist's "Glass" object is the lamp lenses. They get their own material
  (`lights.rvmat`: the trailer's texture, dimmed) and hidden selection (`lights`), so they
  read as off and can be switched on later.
- **Markings:** "PROPERTY OF THE PARAMARINE TASK FORCE" in stencil capitals on each side of
  the equipment box (7 cm above the panel's middle, clear of the latches along its bottom),
  and a faded PTF patch on each side edge of the array. They are bones of their own
  (`markings_text`, `markings_patch`), hidden on a wreck by a `damage` hide animation. They are quads 5 mm proud
  of the panels (`MARKINGS` in `build_model.py`, panels found by raycasting), textured from
  `markings_ca.paa`, which `build_textures.py` draws from Agency FB Bold and
  `addons/PTF_Menu/data/ptfemblem.paa`.

## Fuel, sling loading, towing

- **Fuel:** the generator burns the trailer's own fuel (`fn_fuelLoop.sqf`): 20 L, 25
  minutes (`ptf_gator_fuelMinutes`). ACE refuels it, with the hook at the generator's left
  side. It won't start dry, and stops itself when the tank runs out. "Check fuel" on the
  generator gives the tank and the minutes left (`fn_fuelReport.sqf`).
- **No storage:** no ACE cargo and no inventory, by the owner's call.
- **Fuel fire:** a wrecked tank (`HitFuel`) with fuel in it catches fire (`fn_fuelLoop.sqf`).
  A full tank pours out and burns in 45 s, charring the generator, body and antenna as it
  goes. Still burning after 25 s (more than about half a tank), the G/ATOR is destroyed.
  With less fuel the fire burns out first and leaves it repairable. Clients draw the
  vanilla destruction fire and smoke at `destructionEffect1` while `PTF_GATOR_fireStart` is
  set; the sound is a `Sound_Fire` source on the trailer's owner.
- **Wreck:** `class Damage` swaps every material for a charred `_destruct` one
  (`build_textures.py`, `burnt()`); the inherited vanilla destruction effects burn at the
  `destructionEffect1` and `destructionEffect2` memory points.
- **Sling loading:** `slingLoadCargoMemoryPoints` are the frame's four lifting eyes
  (`SlingLoadCargo1-4`). Vanilla and the SLR fork both use them.
- **Towing:** `fn_towLoop.sqf` is our own system, not RHS's. RHS limits each towing vehicle's
  load (an HMMWV pulls 1.5 t; this trailer is 5.5 t) and swaps the towed object for a
  stand-in vehicle. Any car or tracked vehicle can tow the G/ATOR. The hitch is RHS's
  `rhs_attachPointPos` where a vehicle has one, otherwise the middle of its back end
  (`fn_towHitchPoint.sqf`). The trailer is kinematic: each frame its axle moves toward the
  hitch at the tongue's length (4.385 m), it pitches to the hitch, rolls with the ground,
  and stops jackknifing at 85 degrees. It runs on the machine that owns the trailer, and the
  server hands the trailer to whoever owns the towing vehicle. The tongue stand's caster
  winds up while hitched. It won't hitch with a wheel off (a "Hitch to vehicle" action then
  says why), and a wheel lost on the move drops it off the hitch.

## Legs and leveling

**Setting up is a crew's job** (`fn_task.sqf`): each leg, raising or lowering the array,
starting the generator and reeling in the SATCOM cable is worked by hand (an ACE progress
bar) for exactly as long as the trailer takes to do it, from the animation: a leg its reach
(or its way up, plus the 3 s settle onto the wheels when leveled) at 4 s per unit of phase,
the array what it has left to travel at 32 s end to end, the generator its 5 s start, the
cable 6 s. Measured within 0.05 s of the animations. Several players can work at once, a
leg each. Let go part way and a leg or the array stops where it is (`fn_halt.sqf`): a
halted leg counts as out, and can be raised, and the trailer still levels once all four are
out; a halted array can be raised or lowered from there. A generator start let go of fails.
The server setting "Setting up takes time" (Addon Options > Paramarine Task Force > G/ATOR)
turns the bars off: each job happens at a click.

Each leg is lowered on its own and runs down until its foot meets the ground
(`fn_legReach.sqf`, `fn_groundUnder.sqf`): phase 1 is flat ground under a trailer on its
wheels, and a leg reaches on to phase 2 (0.6 m in all; the rod stays in its cylinder).
`PTF_GATOR_legTarget_<leg>` holds where each stopped, and `fn_legState.sqf` reads a leg as
up, down or moving from it. Once all four are down the server levels the trailer
(`fn_level.sqf`): over 3 s it turns upright on the same heading and lifts its wheels and
tongue stand just clear while the legs run down to the ground. PhysX would drop a car back
onto its wheels, so a leveled trailer hangs from an anchor (`attachTo`): a hidden soda can.
An attached object animates only as often as its parent is simulated, which for a static
anchor such as a helipad is about twice a second (the array jerked); a hidden PhysX object
is simulated every frame and still stays where it is put. Disabling the trailer's simulation
instead stops its animations altogether. Too
steep for the legs' reach (about 5 degrees across the trailer, more along it), it stays as
it is on its wheels and legs, and players nearby are told. Raising any leg first settles
it back to where it stood on its wheels, then lets it go.

## Radar, damage, lights

- **Radar:** while the array is up and turning on power, the server attaches a hidden
  `PTF_GATOR_Sensor` to the turntable (`fn_radarLoop.sqf`). That is the vanilla AN/MPQ-105
  retuned to 10 km against aircraft, all the way round, crewed by its UAV AI and on the
  data link. The G/ATOR model has no crew seats, and Arma only runs a vehicle's sensors
  with crew. It is deleted when the radar stops.
- **Emissions:** the radar hum plays while it transmits, not while it merely turns. That sensor is a real emitter, so enemy passive radar sees it (tested: a
  vanilla To-201's passive radar picks it up at 7 km) and anti-radiation missiles can home
  on it. Silent (the operator console's Emissions, in manual control) keeps the antenna
  turning but deletes the sensor: it sees nothing and gives nothing away (`PTF_GATOR_emcon`).
- **Heat:** thermal maps (`StageTI`, flat per material: the generator runs hot, the rest
  barely warms) and the vehicle's engine heat, which `fn_soundLoop.sqf` sets on each client:
  it rises over about 90 s of running and falls over about 5 minutes once stopped, and a
  fire is full heat. In a `_ti_ca` map red is always white, green is engine heat, blue
  wheel heat and alpha weapon heat (read off the vanilla Offroad's).
- **Hearing:** every 10 s the server gives each AI group within `ptf_gator_hearingRange`
  (250 m) of a running generator a chance to hear it, less the further off it is
  (`fn_hearGenerator.sqf`). A group that hears it goes from safe to aware and learns of
  whoever is working at the trailer if they are its enemies (`fn_alertGroup.sqf`), the
  same as PTF_Cigs' smell. Player-led groups and AI in vehicles don't.
- **Damage:** hit points `HitBody` (the trailer and box), `HitEngine` (generator), `HitFuel`,
  `HitRadar` (array), and the wheels `HitLF2Wheel` and `HitRF2Wheel`. They live in the hit
  points LOD (`HIT_POINTS` in `build_model.py`), and ACE repairs them. A wrecked generator
  won't start and stalls if running. A wrecked antenna stops turning.
- **Wheels:** a shot-off or removed wheel disappears (a hide animation on the wheel's bone,
  from the hit point's damage). ACE can remove and replace them. The wheels' hit points are
  kept out of the wheel bones in the hit points LOD: hiding the bone pulled the hit point
  to the model's centre, and ACE puts "Replace wheel" there, so it vanished.
- **ACE wheel matching:** ACE pairs each PhysX wheel with a hit point by the first nine
  letters of its `boneName`, else the nearest hit point not named
  HitEngine/HitFuel/HitBody. So the stand-in front wheels carry the bone names
  `wheel_1_2_stand` and `wheel_2_2_stand` (no such bones exist), and the body hit point is
  `HitBody`. Otherwise ACE makes the hull or the radar a "wheel".
- **Wheel roll while towed:** the trailer is placed each frame, so PhysX never turns its
  wheels. `ptf_gator_wheels` does, at the tow speed (`fn_towLoop.sqf`).
- **Tail lights:** the lenses switch to `lights_on.rvmat` and a red light point glows at
  the back while the towing vehicle has its lights on (`fn_soundLoop.sqf`, on each client).
- **Exhaust:** a local particle source under the right-hand edge of the generator housing,
  also in `fn_soundLoop.sqf`. It is thick and dark while the generator starts, thins over
  `EXHAUST_SETTLE` (8 s) to a faint haze, and goes when it stops. It blows out sideways;
  smoke that only rose came up unseen through the deck and appeared above the trailer.
- **Shadows:** two shadow buffer LODs (11000, 11010), the reduced mesh itself, pulled 2 cm
  inside the surface (`SHADOW_BUFFER_INSET`, never more than a third of a piece's own
  thickness, or thin plates turn inside out and stand proud). There is deliberately no shadow
  volume LOD: Arma cast it on top of the shadow buffer, and its convex hulls bridged the
  array's ribs and its top panel's fittings and shaded both in sharp blotches.

## Counter-battery

A transmitting G/ATOR (array up, antenna turning on power, not under EMCON) traces enemy
indirect fire back to where it came from. Numbers are in `script_gator.hpp` (`CB_*`).

- **Seeing rounds** (`fn_cbFired.sqf`): an XEH FiredBIS handler on every vehicle and man.
  Only indirect fire counts: ammo the artillery computer can lock (`artilleryLock`), or a
  shell, rocket or submunition from a vehicle with an artillery computer
  (`artilleryScanner`). The machine that fired a round (where its projectile is local)
  watches it ten times a second, and the moment it comes within 2 km of a G/ATOR listed in
  `PTF_GATOR_cbRadars` (the transmitting ones, kept by the server's radar loop) and in its
  line of sight, in the air, tells the server where it was fired from (`fn_cbReport.sqf`,
  the look itself in `fn_cbWatch.sqf`). Where it lands follows when it does
  (`fn_cbImpact.sqf`).
- **Terrain masking**: hills and ridges hide a round from the array (4.5 m up, `CB_EYE`)
  until it climbs into view; buildings and trees don't. The sight line is
  `terrainIntersectASL`, terrain only and the cheapest occlusion test the engine has, drawn
  only for a round already within 2 km, at most every 0.3 s per round (`CB_LOOK`), and never
  again once that G/ATOR has traced it. Measured (`test/setup.Stratis`): 40 rounds in the air,
  all in range and all looked at in the same tick, 0.31 ms a tick (ten a second, on the
  gun's machine only); 0.13 ms between looks; a rifle shot while a G/ATOR transmits
  0.0025 ms, and while none does one variable check. Air tracks need no masking of ours: the
  vanilla radar the sensor is already needs line of sight.
- **Tracing** (`fn_cbReport.sqf`, server): fired from within 10 km, a round gets a firing
  point off the true one by, on average, the server's "Counter-battery error" setting
  (Addon Options > Paramarine Task Force > G/ATOR, 4% by default) of its distance (a 2D
  normal error, so 40 m at 1 km). Points that fall close together (within three times that, or 150 m) are one track,
  whose point is their average, so its error shrinks with the square root of its rounds
  (16 m after six rounds at 1 km). Fired from further off, a round only gives a bearing;
  rounds on the same bearing within 4 degrees are one bearing track. Each track keeps up to
  12 impact points.
- **The network** (`fn_satcom.sqf`, `fn_cbPublish.sqf`): a G/ATOR's tracks reach the tablets
  only through its SATCOM antenna. "Take out SATCOM antenna" puts it (the TFW RF-3080 where
  loaded, else a vanilla satellite antenna: `ptf_gator_satcomClasses`) at the player's feet,
  the cable already run to it from the box's side (a real rope, TFAR's black intercom wire
  where TFAR is loaded), and the player straight into an ACE drag with it. Wherever they set
  it down within the cable's 40 m (`ptf_gator_cableLength`), the G/ATOR is on the network;
  closer than 3 m it hears the radar's own interference instead, and the player who set it
  down is told. While it's being dragged or carried it's off the network. A cable that
  pulls out goes back in once the antenna is in reach; the trailer won't hitch until the
  antenna is stowed ("Stow SATCOM antenna"). The antenna can't be damaged: the RF-3080 was
  wrecked by the knock of being dragged. Each
  G/ATOR's own tracks are on it (`PTF_GATOR_cbOwn`); the networked ones, with their air
  tracks, make up `PTF_GATOR_picture`. Its operator console shows its own, network or not,
  and clears them.
- **The tablet**: three map layers of their own on the Billet tablet, each switched on and
  off in the map's Layers panel (Billet's `blk_tabletLayers` slot, added for this), drawn in
  the tablet's MIL-STD style: Arma's NATO marker textures, as its groups are, lines and rings
  at least 2 px wide (thinner ones aliased badly), and Billet's own label font and shadow.
  - **G/ATOR** (`fn_gatorLayer.sqf`): each networked G/ATOR's symbol, a friendly radar
    (`data\gator_nato_ca.paa`, drawn by `tools/gator/make_icons.py` in the NATO markers'
    proportions; vanilla has no radar), its 2 km and 10 km rings, and while it transmits an
    outline sensor arc pointing where the array faces. Billet asks once a second, so the arc
    goes over with its turn rate (measured between looks) and Billet's `sector` shape turns
    it every frame.
  - **Counter-battery** (`fn_cbLayer.sqf`): each firing point as the hostile mortar or
    artillery symbol in a ring as wide as its likely miss, its impacts and a label (track,
    rounds, miss, age); each bearing as a dashed line. Tracks quiet for ten minutes fade. Its
    section of the map's Tracks list (a sub-tab beside Groups) lists them by grid, newest
    first; a click centres the map on one, Erase removes one and Clear all the lot
    (`fn_cbErase.sqf`).
- **Incoming alarm**: "Turn incoming alarm on" on the G/ATOR. While it's on, it sounds from
  the moment a round is traced until 4 s after the last traced round is down (30 s at most
  without news): `PTF_GATOR_alarmUntil`, played on every client by `fn_soundLoop.sqf` from
  the box's side. Only for indirect fire. The clip (`sounds\alarm.ogg`) is one 7.183 s cycle
  of the owner's recording, cut by `import_sounds.py` to overlap the next across the quiet
  gap between two pulses with straight-line crossfades (the copies are in step, so
  equal-power fades would swell), and played through a loudspeaker first (`SPEAKER`: a horn's
  band, its cone's break-up, a PA's compression). Mono, so the game places it; loud (volume 8.5) with a 2 km
  reach, so it's faint but directional out there.
- **Air tracks** (`fn_airLayer.sqf`): the third layer. Every other second the server reads
  what each transmitting G/ATOR's radar sees (`getSensorTargets` of its sensor, aircraft
  only) and, while it is on the network, adds them to the picture. On the map each aircraft
  is its MIL-STD symbol (hostile, friendly, or neutral's frame for unknown; rotary wing,
  fixed wing or drone) coloured by the radar's identification (hostile red, unknown yellow,
  friendly blue, neutral green), with a 30-second leader line and a label (type, height,
  speed); in the Tracks list they are under Air, hostile first.
- **Testing**: `tools/gator/test/counterbattery.Altis` (Altis, the full modset and a Billet
  build with the map layer slot): `run.py --mission tools/gator/test/counterbattery.Altis
  --full --extra <billet>/mod/.hemttout/build/addons`. The mission logs `GATORTEST SNAP
  <name>` and `run.py` captures the Arma window itself (`capture.py`, PrintWindow), since
  the game's `screenshot` command leaves out dialogs like the tablet.

## The operator

The G/ATOR has a job for its crew beyond setting it up: choices with costs. The hardware
(legs, generator, array, antenna rotation, the SATCOM antenna, the incoming alarm) is worked
with ACE at the trailer; the radar itself from its operator computer. The commands are
`fn_operator.sqf` (on the server), and `fn_operatorTick.sqf` runs once a second per G/ATOR
from the radar loop. Fire control ("send to fires") waits for the M777 project.

- **The operator computer** (`fn_computer.sqf`): "Take out operator computer" on the trailer
  puts a rugged laptop (the first of `ptf_gator_computerClasses` loaded) into the player's
  hands, an ACE carry, on a 20 m cable (`ptf_gator_computerCable`). Set down within reach,
  it's connected (`PTF_GATOR_console`). Out of reach, towed, or stowed, it isn't, and the
  G/ATOR goes back to automatic. The trailer won't hitch until it's stowed.
- **Automatic and manual**: automatic (the default) turns all the way round and transmits,
  and doesn't defend itself. Manual control, taken at the connected computer, gives the
  operator Emissions, Scan, Look closer and Identify. Back to automatic, it turns all the
  way round and transmits again.
- **The console** (`fn_console.sqf`, `fn_initComputer.sqf`): "Open G/ATOR console" on the
  computer opens Billet's console slot (`blk_tabletConsoles` in config.cpp, added to Billet
  for this, generic for any mod): the tablet's map full screen on a rugged bezel, with the
  G/ATOR, counter-battery and air layers, and this G/ATOR's own picture whether it's on the
  network or not. The panel beside it keeps its controls in view, one compact row each:
  Control (Auto, Manual), Emissions (Transmit, Silent), Scan (Full turn, Sector), the
  sector's edges (Sweep from, Sweep to: 15 degrees a click) and the incoming alarm. Their
  explanations are tooltips. Its lists scroll beneath: Counter-battery (Look closer, Erase,
  Clear all) and Air (Identify). A row with a place centres the map on it. Its status bar
  calls out a missile inbound, traced rounds coming down (how many, seconds to the first)
  and jamming. It closes 3 m from the computer. The laptop's actions sit in its one ACE
  interaction, beside Carry; Take manual control opens the console too. It needs the
  Billet-Link tablet 0.15 or newer: with an older one (or none), Open G/ATOR console says so,
  and the computer still switches manual and automatic by ACE. On the tablet, the G/ATOR section of Tracks only
  reads.

- **Emissions and the enemy's fix**: while it transmits, the enemy direction-finds it. Their
  fix grows over 4 minutes (10 sweeping a sector) through rough (rounds within 500 m), good
  (within 100 m) and locked (25 m); it fades over 5 minutes silent and is lost if the trailer
  moves 50 m. The crew isn't shown it: they can't know what the enemy knows. With the server's
  "Enemy counter-fire on a G/ATOR" setting on (off by default), a good fix brings an enemy
  mortar team every two minutes. It never takes over the mission's own artillery: that was
  re-tasking Zeus's guns off their fire missions.
- **Sector** (`fn_sweep.sqf`): the array sweeps back and forth between two bearings
  (`PTF_GATOR_sector`, clockwise from one to the other, 30 degrees across at least; at first
  90 degrees round where it faces), at the antenna's turning speed. Rounds and aircraft
  outside it go unseen, inside it each round's miss is halved, and the fix grows more slowly.
  The map draws the sector out to where it hears rounds (2 km, less jammed), with its beam
  (20 degrees, Billet's `beam` shape, out to the same reach) panning across all of it.
- **Look closer** (a dwell): the array turns to one firing point for 5 s and nothing else is
  watched meanwhile. Its miss halves, or, if jamming made it up, it is shown false and goes.
  On an unknown aircraft it is **Identify** (IFF): it shows as hostile, friendly or neutral
  by its crew's side from then on.
- **Splash warnings**: a traced round's impact is predicted on the gun's machine (its flight
  run on under gravity and its ammo's air friction, once, when traced) and drawn on the map
  with a countdown. Everyone within 200 m of it hears Arma's "incoming" call on their radio
  if the G/ATOR is on the network: no popup, nothing on their screen. The countdown is on
  the operator console.
- **Anti-radiation missiles** (`fn_armWatch.sqf`, `fn_armReport.sqf`): any guided missile
  whose target is a G/ATOR's sensor is watched where it was fired. The trailer beeps Arma's
  missile warning, the console's status bar and the tablet show its bearing and seconds to impact. Going silent
  removes the sensor it homes on, and it flies on to a remembered spot 250 to 600 m off
  (`setMissileTargetPos`); transmitting on takes the hit.
- **CROWS Electronic Warfare**: CROWS jammers (its `crowsEW_main_jamMap`) jam the G/ATOR as
  CROWS jams radios: fully inside the jammer's effective radius, fading across its falloff.
  Jammed, it hears rounds at 40% of the range, its misses grow up to 2.5 times, its air
  radar shrinks to 4 km, and it now and then shows a ghost firing point. Any jammer within
  15 km leaves a strobe (a bearing line on the tablet) while the G/ATOR is up and powered,
  silent or not; strobes from two places cross on the jammer. Transmitting, the G/ATOR is
  itself a CROWS spectrum signal (`crowsEW_spectrum_addBeacon`, 990 to 1089 MHz), so the
  enemy, or friendly EW practising, can find it with a spectrum device.
- **Zeus** (`fn_initZeus.sqf`, with Zeus Enhanced): under "PTF G/ATOR", Launch ARM at G/ATOR
  (`fn_armLaunch.sqf`), Counter-fire on G/ATOR, Enemy battery: fire mission, Enemy battery:
  harass, and Stop enemy batteries. Enemy batteries (`fn_enemyBattery.sqf`) are a mortar
  team that sets up 1.5 to 3.5 km off, fires, and is gone 15 s after its last round: shoot
  and scoot, so a track shows where it was. CROWS's own Zeus modules place jammers.
- **Testing**: `run.py --mission tools/gator/test/operator.Stratis --extra
  <billet>/mod/.hemttout/build/addons` (CBA, ACE and a Billet build with the console slot; a
  stand-in CROWS jam map).

## Hype video

```
python tools/gator/video/make_video.py
```

This films the G/ATOR on Malden with the full PTF modset: a PTF MRZR and a PTF ACV tow
it, then it sets up. The game runs at a quarter speed and every frame is a screenshot (0.1
speed stops game time at high frame rates). The G/ATOR's sounds are laid on the frames the
mission logged them, with PTF title and end cards. It writes `releases/gator_hype.mp4` in
about 25 minutes. `--reuse-frames` rebuilds the MP4 from the last run's frames.

## Testing

```
python tools/gator/test/run.py
```

This loads CBA, ACE and the PTF_Main and PTF_GATOR PBOs from this repo's build, plus the
data PBO, and plays `test/mission` with the game in the background. The mission:

- checks the trailer settles upright and stays put;
- steps the sequence and compares each part's probe point with `gator_model.json`;
- runs the real sequence through the functions the ACE actions call: legs down one by one,
  generator start, array up, turning, stop, array down, legs up, generator off. It checks
  each sound was started (the radar's local `PTF_GATOR_soundLog`), and that the hum's
  emitter moves round as the antenna turns;
- checks fuel burn, that it won't start dry, and that it stops by itself when the tank runs out;
- hitches a vanilla HEMTT. An AI drives it 100 m and round a corner, and the test checks the
  lunette stays on the hitch and the trailer stays upright. Then it unhitches;
- shoots screenshots into `.hemttout/gator-test/shots`.

It takes about 4 minutes.
