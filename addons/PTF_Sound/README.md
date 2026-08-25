# PTF_Sound

Loudspeaker / PA audio library with Zeus-placeable broadcast modules. Sounds
are foldered by scope — `sounds/generic/` for campaign-agnostic material
(sirens, tones, church bells, Latin/Caribbean music) and `sounds/valmera/`
for the Valmeran campaign (Bastida regime announcements, La Guardia orders,
El Sindicato pirate radio). Additional campaigns get their own folder and
module category.

**Playlists** rotate through curated sequences instead of looping one line:
*Radio Nacional (programming)* (regime bulletins interleaved with music and
the anthem), *Sindicato: Pirate Radio (rotation)* (ads, the numbers game
and music), *Guardia PA (rotation)*, and *Cantina Radio (music only)* — a
music-only list for bar and street ambience on any map.

## Using it

**Zeus:** Modules → *PTF Loudspeakers (Generic)* / *PTF Loudspeakers
(Valmera)* → place a module where the speaker should be, or use **Place
Loudspeaker...** (under *PTF Loudspeakers* in ZEN's custom modules) to
browse every sound in one list and place it pre-configured — with **Spawn
Speaker Prop** ticked (the default) it also creates a visible loudspeaker
prop and binds the broadcast to it, so one placement gives players
something to find, shoot, or ACE-cut. With Zeus Enhanced loaded (it's in
the modpack) a configuration dialog opens on placement: broadcast range
(radius slider with a terrain circle), pause between repeats, and a
**Muted** checkbox — place muted to position and preview in peace, then go
live when ready. In every range/pause control, **0 range / -1 pause means
"use this sound's default"** (the same convention as the Eden attributes),
so a module keeps tracking config defaults unless you choose a concrete
value. It repeats until the module is **deleted**. ZEN is a soft
dependency: without it the module broadcasts at the sound's defaults.

**Playlist modules** (*Radio Nacional (programming)*, *Guardia PA
(rotation)*) rotate through a curated sequence of sounds instead of looping
one line — a town with rotating regime programming instead of one
announcement on repeat. Defined in the `playlists` section of
`sound_lines.json`.

**Right-click a placed module** (ZEN context menu → *Loudspeaker*) for:
*Preview (only you)* — plays the sound locally at your camera, no one else
hears it; *Broadcast now* — cuts the current line and starts the next
immediately; *Mute* — **stops the audio mid-play** and holds; *Resume
broadcast*; *Adjust range & pause* — reopens the dialog, applied live.

**Audio stops instantly.** Broadcasts are emitted with `say3D` from an
invisible emitter object owned by the **server** (so a curator
disconnecting no longer kills their loudspeakers). `say3D` dies with its
emitter, so muting, deleting the module, or destroying **or deleting** the
bound speaker cuts the sound mid-word — no more waiting for the line to
finish.

**Moving the module does not restart the audio.** The play schedule is
state on the module, not in the loop, and the emitter survives
re-activations, so a Zeus move/edit resumes the existing cadence without
interrupting the current play (and re-binds to whatever prop it now sits
on — releasing the old prop's ACE action). Each module schedules
independently: two speakers with the same sound play on their own
cadences. Range/pause/mute can also be driven by script via the
`PTF_Sound_distance` / `PTF_Sound_pause` / `PTF_Sound_paused` variables —
everything is re-read live. One accepted edge: if a Zeus client's move
outright *recreates* the module object (wiping its variables), the old
broadcast cuts within a second and the module starts over as a fresh
placement — that path cannot preserve state and is not papered over.

The broadcast binds to a physical speaker where one exists: **drop the
module onto a prop or vehicle** to attach it, or place it within 5 m of one
to auto-bind to the nearest. Destroying or deleting the bound object cuts
the broadcast instantly and cleans up the module. A module attached to a
vehicle broadcasts from the vehicle as it moves — a PSYOP van is just a
module dropped on a truck. With ACE loaded, players can also **ACE-interact
with the bound speaker → "Cut loudspeaker power"** (5 s) to kill it
quietly — the stealth alternative to shooting it. With nothing nearby the
module broadcasts unbound, and only deleting it stops it.

**Mission compatibility (CfgRemoteExec):** missions that harden remote
execution with `class CfgRemoteExec { class Functions { mode = 1; }; }`
must whitelist `PTF_Sound_fnc_serverLoop`, `PTF_Sound_fnc_placeSpeaker`,
and `PTF_Sound_fnc_addCutAction` (and the `deleteVehicle` command), or
Zeus-placed speakers will silently never broadcast. Missions without a
CfgRemoteExec class are unaffected (the engine default allows everything).

**Eden:** the same modules under Systems — attributes for *Broadcast range*
(0 = default), *Pause between repeats* (-1 = default), and *Start muted*.
Or classic trigger effects — every sound is registered in `CfgSounds`
(named `PTF PA - ...` in the trigger sound list).

**Script:** `say3D` with the `CfgSounds` class
(`_obj say3D "PTF_Sound_guardia_curfew"`), or `playSound3D` with the file
path for an explicit range.

## Regenerating / adding sounds

The OGGs, `cfgSounds.hpp` and `cfgModules.hpp` are all generated — do not
hand-edit the two `.hpp` files. The source of truth is
[`tools/sound_lines.json`](../../tools/sound_lines.json) (script text, voice,
speech rate, category, range). To change a line or add one:

```
python -m pip install edge-tts imageio-ffmpeg
python tools/generate-sounds.py
```

A new `category` value creates a new sounds subfolder and module category —
add a matching `CfgFactionClasses` entry in `config.cpp` (the generator
prints a reminder listing the categories it used). The `playlists` section
defines rotation modules from existing sound names — no new audio involved.
`tools/check_sound_data.py` gates CI on the generated files matching the
JSON, so a forgotten regeneration fails the build instead of shipping.

Accents come from Microsoft's Latin American Spanish neural voices reading
English text (Cuban, Venezuelan, Dominican, Puerto Rican). Everything is run
through a horn-speaker effect chain (bandpass, light overdrive, slapback
echo — tuned so the lines stay intelligible), so replacement audio from any
source will match: drop a member VA recording as `<name>.mp3` into
`tools\.sound_cache\` and regenerate — a cached/manual raw file always wins
over TTS. The cache is gitignored but deliberately lives in the repo, and
encodes run with `-bitexact`, so regenerating with unchanged inputs
produces byte-identical OGGs instead of dirtying every binary in git.

The music is **original composition**, synthesized by
[`tools/compose-music.py`](../../tools/compose-music.py) — no recording
rights, and the anthem belongs to Valmera alone. Seven pieces: the anthem
and Guardia march, a **son cubano** (clave, conga tumbao, montuno vamp), a
**merengue** (güira, tambora, accordion runs, horn riff), a slow **bolero**
(nylon guitar, muted trumpet), church bells, and the station ident. The
Caribbean pieces are rhythm-forward by design — percussion and syncopation
synthesize convincingly where long lyrical melodies do not, and through the
PA chain they read as real radio music. `generate-sounds.py` runs the
composer automatically when the WAVs are missing from the raw cache. The
music entries in `sound_lines.json` support an optional `text`/`voice` pair,
which appends a spoken tag after the music (that's how the radio ident is
built). To use a real, properly licensed recording instead, drop it over the
matching `<name>.wav` in the cache and regenerate.

## Licensing note (before Workshop release)

The prototype audio comes from the unofficial edge-tts endpoint. Before
shipping, either regenerate the voice lines through the Azure Speech API
(same voices; free tier is ample; license cleanly permits redistribution of
the audio) or replace them with member recordings. The pipeline and effect
chain stay the same either way.

## Verify in-game

1. **Instant stop (the load-bearing assumption).** Delete a module while a
   line is playing — the audio must cut mid-word, everywhere. Mute from the
   context menu must do the same. This is the whole say3D-emitter design;
   if it doesn't hold, everything else needs rethinking.
2. Broadcast is audible to *other* players, not just the placing Zeus
   (`say3D` runs on the server; global effect is the thing to check).
3. The chosen range actually applies: place with a small radius, walk out
   past it, confirm silence; the Eden attribute path too.
4. **Curator disconnect resilience:** place a speaker as Zeus from a
   client, disconnect that client — the broadcast must keep running (the
   loop lives on the server now).
5. CfgSounds entries show up in Eden trigger effects and work via `say3D`.
6. Speaker binding: drop a module onto a prop — confirm it attaches (Zeus
   highlights the object), that destroying the prop AND deleting the prop
   in Zeus both cut the broadcast instantly, and that a module on a moving
   vehicle broadcasts from the vehicle continuously (the emitter is
   attached to it).
7. Move without restart: while a line is playing, drag the module — the
   audio must NOT stop, restart, or double up, and the next repeat should
   come on the original cadence; the placement dialog must not reopen. (If
   it DOES restart with the dialog, the engine recreated the logic on move
   — that is the accepted fresh-start path; report it so the docs can say
   which behavior Zeus actually has.)
8. Context menu: right-click a placed module → *Loudspeaker* — Preview is
   audible only to the acting curator (verify with a second client),
   Mute cuts instantly, Resume plays within a second or two, Broadcast now
   cuts the current line and replays IMMEDIATELY (no dead air), Adjust
   applies without interrupting the loop.
9. ACE: interact with a bound speaker prop → *Cut loudspeaker power* —
   5 s progress bar, then the audio cuts and the module disappears. Then:
   bind a NEW module to the same prop and confirm the action works again;
   and drag a module from prop A to prop B and confirm prop A no longer
   offers the cut. Confirm a JIP client also gets the action.
10. Browse placement: ZEN custom modules → *PTF Loudspeakers* → *Place
    Loudspeaker...* — list shows all sounds and playlists; with Spawn
    Speaker Prop ticked a visible loudspeaker appears and shooting/cutting
    it kills the broadcast; the placed module and prop are Zeus-editable
    (movable/deletable) **on a dedicated server**; no second dialog opens.
11. Playlists: place *Radio Nacional (programming)* — items rotate in
    order with the configured gap, and the rotation position survives a
    module move.
12. Independence: place TWO modules of the same sound in different towns —
    both must broadcast on their own cadence, neither waiting on the other.
13. Eden attributes: all three (range, pause, start muted) apply on a
    dedicated server.

## Later passes

- More material: ambient street audio, additional campaigns.
