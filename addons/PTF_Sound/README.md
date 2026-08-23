# PTF_Sound

Loudspeaker / PA audio library with Zeus-placeable broadcast modules. Sounds
are foldered by scope — `sounds/generic/` for campaign-agnostic material
(sirens, tones) and `sounds/valmera/` for the Valmeran campaign (Bastida
regime announcements, La Guardia orders, El Sindicato pirate radio).
Additional campaigns get their own folder and module category.

## Using it

**Zeus:** Modules → *PTF Loudspeakers (Generic)* / *PTF Loudspeakers
(Valmera)* → place a module where the speaker should be. With Zeus Enhanced
loaded (it's in the modpack) a radius slider opens on placement, drawing the
range circle on the terrain; confirm or cancel to start the broadcast. It
repeats until the module is **deleted**. The range can also be changed
mid-broadcast by setting the `PTF_Sound_distance` variable on the module —
each repeat re-reads it. ZEN is a soft dependency: without it the module
broadcasts at the sound's default range.

The broadcast binds to a physical speaker where one exists: **drop the
module onto a prop or vehicle** to attach it, or place it within 5 m of one
to auto-bind to the nearest. Destroying the bound object kills the broadcast
(after the current play finishes — a started `playSound3D` can't be cut
short) and cleans up the module. A module attached to a vehicle broadcasts
from the vehicle as it moves — a PSYOP van is just a module dropped on a
truck. With nothing nearby the module broadcasts unbound, and only deleting
it stops it.

**Eden:** the same modules under Systems — the module's *Broadcast range (m)*
attribute overrides the default (0 = default). Or classic trigger effects —
every sound is registered in `CfgSounds` (named `PTF PA - ...` in the trigger
sound list).

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
prints a reminder listing the categories it used).

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

1. Both module categories appear in Zeus under Modules, and placing one
   opens the ZEN range slider (with the terrain circle) then starts the
   broadcast; deleting the module stops the loop after the current play.
2. Broadcast is audible to *other* players, not just the placing Zeus
   (playSound3D is remoteExec'd to all machines — this is the thing to
   check).
3. The chosen range actually applies: place with a small radius, walk out
   past it, confirm silence; the Eden attribute path too.
4. A Zeus-placed module keeps looping if the curator stays connected; the
   loop runs on the machine that placed it, so a Zeus disconnect mid-loop
   orphans the broadcast (known limitation — reassess if it bites).
5. CfgSounds entries show up in Eden trigger effects and work via `say3D`.
6. Speaker binding: drop a module onto a prop — confirm it attaches (Zeus
   highlights the object), that destroying the prop stops the broadcast
   after the current line, and that a module on a moving vehicle broadcasts
   from the vehicle's position each repeat.

## Later passes

- A visible loudspeaker *object* variant (inherit a vanilla speaker prop with
  an XEH init) so the speaker itself is placeable/destroyable in one step.
- ACE interaction on placed speakers (start/stop/choose broadcast) for
  non-Zeus use.
- More material: ambient street audio, additional campaigns.
