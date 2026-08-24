# PTF_Sound

Loudspeaker / PA audio library with Zeus-placeable broadcast modules. Sounds
are foldered by scope — `sounds/generic/` for campaign-agnostic material
(sirens, tones) and `sounds/valmera/` for the Valmeran campaign (Bastida
regime announcements, La Guardia orders, El Sindicato pirate radio).
Additional campaigns get their own folder and module category.

## Using it

**Zeus:** Modules → *PTF Loudspeakers (Generic)* / *PTF Loudspeakers
(Valmera)* → place a module where the speaker should be, or use **Place
Loudspeaker...** (under *PTF Loudspeakers* in ZEN's custom modules) to
browse every sound in one list and place it pre-configured. With Zeus
Enhanced loaded (it's in the modpack) a configuration dialog opens on
placement: broadcast range (radius slider with a terrain circle), pause
between repeats, and a **Muted** checkbox — place muted to position and
preview in peace, then go live when ready. It repeats until the module is
**deleted**. ZEN is a soft dependency: without it the module broadcasts at
the sound's defaults.

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
emitter, so muting, deleting the module, or destroying the bound speaker
cuts the sound mid-word — no more waiting for the line to finish.

**Moving the module does not restart the audio.** The play schedule is
state on the module, not in the loop, and the emitter survives
re-activations, so a Zeus move/edit resumes the existing cadence without
interrupting the current play (and re-binds to whatever prop it now sits
on). Range/pause/mute can also be driven by script via the
`PTF_Sound_distance` / `PTF_Sound_pause` / `PTF_Sound_paused` variables —
everything is re-read live.

The broadcast binds to a physical speaker where one exists: **drop the
module onto a prop or vehicle** to attach it, or place it within 5 m of one
to auto-bind to the nearest. Destroying the bound object cuts the broadcast
instantly and cleans up the module. A module attached to a vehicle
broadcasts from the vehicle as it moves — a PSYOP van is just a module
dropped on a truck. With ACE loaded, players can also **ACE-interact with
the bound speaker → "Cut loudspeaker power"** (5 s) to kill it quietly —
the stealth alternative to shooting it. With nothing nearby the module
broadcasts unbound, and only deleting it stops it.

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
through a horn-speaker effect chain (bandpass, overdrive, slapback echo), so
replacement audio from any source will match: drop a member VA recording as
`<name>.mp3` into `%TEMP%\ptf_sound_raw\` and regenerate — a cached/manual
raw file always wins over TTS.

The music (Himno de la República, Marcha de la Guardia, the Radio Nacional
ident) is **original composition**, synthesized by
[`tools/compose-music.py`](../../tools/compose-music.py) — no recording
rights, and the anthem belongs to Valmera alone. `generate-sounds.py` runs
the composer automatically when the WAVs are missing from the raw cache. The
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
   highlights the object), that destroying the prop cuts the broadcast
   instantly, and that a module on a moving vehicle broadcasts from the
   vehicle continuously (the emitter is attached to it).
7. Move without restart: while a line is playing, drag the module — the
   audio must NOT stop, restart, or double up, and the next repeat should
   come on the original cadence. The placement dialog must not reopen.
8. Context menu: right-click a placed module → *Loudspeaker* — Preview is
   audible only to the acting curator (verify with a second client),
   Mute cuts instantly and Resume restarts, Broadcast now cuts and replays,
   Adjust applies without interrupting the loop.
9. ACE: interact with a bound speaker prop → *Cut loudspeaker power* —
   5 s progress bar, then the audio cuts and the module disappears. Confirm
   a JIP client also gets the action.
10. Browse placement: ZEN custom modules → *PTF Loudspeakers* → *Place
    Loudspeaker...* — list shows all sounds and playlists, the placed
    module starts configured, is Zeus-editable (movable/deletable), and
    does not open a second dialog.
11. Playlists: place *Radio Nacional (programming)* — items rotate in
    order with the configured gap, and the rotation position survives a
    module move.
12. Eden attributes: all three (range, pause, start muted) apply on a
    dedicated server.

## Later passes

- A visible loudspeaker *object* variant (inherit a vanilla speaker prop with
  an XEH init) so the speaker itself is placeable/destroyable in one step.
- More material: ambient street audio, additional campaigns.
