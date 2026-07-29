# PTF_OPFOR

Custom OPFOR factions for the Valmeran campaign. Standalone PBO — nothing in
the existing PTF addons was modified to add it.

RHS is the only content dependency (GREF, AFRF and USAF). No third-party
faction mods are used, so nothing new has to be added to the repack.

## Factions

| Layer | Faction | Class | Status |
|-------|---------|-------|--------|
| 1 | Batallón de Infantería No. 7 "Pera" (los Pereños) | `PTF_OPFOR_Perenos` | Implemented |
| 2 | La Guardia (Destacamento Especial Bastida) | `PTF_OPFOR_Guardia` | Implemented |
| 3 | Kestrel Group | `PTF_OPFOR_Kestrel` | Implemented |

**All three layers sit on EAST (OPFOR).** Kestrel included — its "defeated by
economics" condition is campaign scripting, not a side assignment. Do not move
any of these to Independent.

## Layer 1 — los Pereños

The design brief calls for conscripts and long-service NCOs, island-born,
ageing rifles, no night vision worth the name, poorly paid and paid late.
Defeated by fracture rather than attrition.

### Why this equipment

RHS GREF ships a **Horizon Islands Defence Force** set — a tropical island
garrison in ERDL and OG-107 fatigues, M1 steel helmets, ALICE webbing, and
L1A1 (FAL) rifles. That is very close to a Latin American conscript army
already, and the FAL in particular is *the* South American service rifle. The
units inherit from `rhsgref_hidf_base` and are rebadged onto EAST.

- **Rifles** — L1A1/FAL, wood-furniture variant for the rank and file. A
  minority carry AKMs from an older aid shipment and do *not* share magazines
  with the FAL men.
- **Support** — FN MAG (pairs with the FAL in 7.62 NATO), M79 "blooper",
  RPG-7, 2B14 82mm mortar, DShKM and SPG-9 emplacements.
- **Marksman** — L1A1 with the old SUIT sight. Daylight only.
- **Vehicles** — deliberately incoherent. Soviet soft-skins (UAZ, Ural,
  GAZ-66, BRDM-2) next to ex-US tracks (M113A3, M1025), because the battalion
  bought from whoever would sell.

### How the brief is encoded in config, not left to mission scripting

- **No NVGs on any unit in the faction.** Night is the players' advantage,
  and it should stay that way without a mission maker remembering to strip
  kit.
- **`sensitivity` tiers by role.** Sentries sit at 0.8 and conscripts at 1.0 —
  they man a checkpoint properly and then stop paying attention. NCOs run
  2.6–3.0, because the long-service cadre is the competent part of the
  battalion. This is the single most important knob in the faction; if the
  garrison feels too sharp or too blind in playtesting, tune it here.
- **Kit reads rank at a glance.** Conscripts in OG-107 with a field cap,
  riflemen in mixed OG-107/ERDL under randomised M1 shells, NCOs in full ERDL
  with a PASGT. Players should be able to see who matters before they shoot.
- **Thin ammunition loads.** They fight hard for about four minutes; they do
  not carry the magazines for a long engagement.
- **Local names.** `PTF_ValmeranMen` in `cfgNames.hpp` supplies a Spanish name
  pool so the dead have names that belong to the towns the players walk
  through next week.

### Not encoded here (deliberately)

"They surrender in groups when a leader falls" is mission-side behaviour —
config cannot express it. What the config does is make it *easy*: every group
has exactly one obvious leader, and the leader is the best-equipped man in it.
Wiring surrender to leader death belongs in the campaign framework.

## Layer 2 — La Guardia

Bastida's praetorians: hand-picked, paid in hard currency, loyal to the man
rather than to any flag. ~140 strong, garrisoning Presa Alta and Tagua Air
Base. Defeated by killing them.

Built as the deliberate mechanical **inverse** of los Pereños, so that a
contact with La Guardia feels categorically different rather than just
statistically harder:

| | los Pereños | La Guardia |
|---|---|---|
| Night vision | None, on anyone | Every unit; PVS-15 on the veteran tier |
| `sensitivity` | 0.8 (sentry) – 3.0 (NCO) | 3.2 – 4.0, no inattentive tier |
| Rifle | L1A1/FAL, iron sights | AK-103, EOTech or ACOG MDO + PEQ-15 |
| Magazines | 3–6, steel | 8, polymer |
| Protection | ALICE webbing, M1 steel | MBAV plate carrier, Ops-Core |
| MG | FN MAG, three belts | PKP Pecheneg, five belts |
| AT | RPG-7, PG-7V | RPG-7 PGO, PG-7VR tandem + thermobaric |
| Armour | M113, BRDM-2 | BTR-70, BMP-2 |

Notes on specific choices:

- **AK-103** puts them on a different ammunition family from the FAL-armed
  garrison, so a player who picks up a dead man's magazines learns something.
  It is also the real service rifle of the region's cash-rich armies.
- **Optics are baked onto custom weapon classes** in `cfgGuardiaWeapons.hpp`.
  A unit's `weapons[]` array cannot carry attachments, so naming the RHS
  rifle directly would have handed them iron sights. The Zenitco B-33 rail is
  1913/ASDG, which is why Western optics mount on a Russian rifle.
- **No checkpoint group exists for this faction, on purpose.** La Guardia do
  not stand bored roadblocks. Their appearance anywhere other than Presa Alta
  or Tagua is supposed to tell the players something.
- **Escalation is a ladder, not a buff.** `Equipo de Asalto` → `Sección de
  Asalto` → `Sección Reforzada` (veterans throughout), plus the BMP-2 section
  held back for when the campaign is meant to get hard. Escalate by fielding
  higher tiers, not by editing skill values.

## Layer 3 — Kestrel Group

~50 foreign contractors on Marenco's payroll, ex-special-forces from four or
five countries. They hold the airport and the research compound, and they own
the island's air defence. Defeated by economics.

The third silhouette. The other two layers differ in *quality*; Kestrel
differs in *shape*:

| | los Pereños | La Guardia | Kestrel |
|---|---|---|---|
| `accuracy` / `sensitivity` | 1.0 / 1.2 | 2.6 / 3.2 | 3.6 / 4.2 |
| Typical group size | 9 | 8–10 | **4** |
| Largest group | 9 | 10 | **6** |
| `cost` per man | 25k–400k | 250k–600k | **800k–1.6M** |
| Camouflage | Mixed — they're poor | Uniform — they're funded | Mixed — four old armies |

- **They do not mass.** The largest Kestrel group is six, and it is the
  airfield site-defence group. A Kestrel contact is four men who are each
  better than anything the players have met, with nobody behind them. That is
  the config expression of "individually excellent, collectively uninterested
  in dying for a mining concession."
- **`cost` is set very high** — up to 1.6M. Beyond AI targeting priority it is
  a note to the mission maker: every one of these is a line item, and the win
  condition is making the contract unprofitable.
- **Four national camouflage patterns** — DPM, French lizard, US woodland,
  3-colour desert — all on RHS's shared `gue_m93` body model, so one base
  class covers all four. Nobody issued these men anything; they each kept the
  kit they left their old army in. A Kestrel fireteam should not look like a
  unit, it should look like a contract.
- **Suppressed Mk18s** throughout, with Glock 17 sidearms.

### The air defence

This is the layer that changes how players *plan* rather than how they shoot.

| Asset | Class | Notes |
|---|---|---|
| FIM-92 Stinger | `PTF_Kestrel_aa_stinger` | Kestrel's own procurement |
| Igla (9K38) | `PTF_Kestrel_aa_igla` | The island's, now run by professionals |
| ZU-23-2 | `PTF_Kestrel_zu23` | Static AA autocannon |
| Igla AA pod | `PTF_Kestrel_igla_pod` | Static SAM |
| Air search radar | `PTF_Kestrel_radar` | See caveat below |
| M107 (Mk211) | `PTF_Kestrel_antimateriel` | Makes airframes unflyable on the ground |

Two MANPADS flavours is deliberate. Fielding both tells the players Kestrel
did not simply arrive with kit — they took something over.

There are three AA groups: two MANPADS teams and `Batería AA
(ZU-23-2 / Igla)`, which pairs a gun and a launcher with the men who service
them. That last group is what an airfield approach should cost.

**Radar caveat.** RHS ships the SERHAT radar as pure scenery — `NonStrategic`,
`destrType = "DestructNo"`, no sensors. It is a prop, not a working or
destructible radar. `PTF_Kestrel_radar` overrides `destrType` and gives it
armour so it can be serviced as an objective, but the model has no destruction
LOD, so expect it to stop working rather than visibly collapse — **and verify
it takes damage at all.** If the p3d has no fire geometry the override will
not be enough, and the fallback is a mission-side trigger on a satchel placed
at the site. The radar does not actually feed the AA either way; it is an
objective and a set piece, not a sensor.

## Flags

Four flags live in `data/`, generated as flat geometry and converted with
Arma 3 Tools' `ImageToPAA` (the generator is
`scratchpad/Make-Flags.ps1`, kept out of the repo — regenerate from there if a
design needs changing):

| Flag | Texture | Design |
|---|---|---|
| Valmera (national) | `flag_valmera_co.paa` | Green/white/blue tricolour, gold sun — what flew over Bocachico before any of this |
| BI-7 "Pera" | `flag_perenos_co.paa` | Olive field, blood-red base band, gold `VII` — a regimental colour, plain and cheap |
| La Guardia | `flag_guardia_co.paa` | Black field, crimson hoist bar, silver device — no national colours at all, because they are loyal to a man |
| Kestrel Group | `flag_kestrel_co.paa` | Charcoal and amber chevrons with a wordmark — a logo, not a flag |

Each is wired two ways:

- **As the faction flag** — `flag = ...` on each `CfgFactionClasses` entry.
- **As placeable flagpoles** — `PTF_Flag_Valmera_F`, `PTF_Flag_Perenos_F`,
  `PTF_Flag_Guardia_F`, `PTF_Flag_Kestrel_F` under Signs → Flags in Eden.
  Useful for telling players who holds what before a shot is fired.

Flag cloth on a `FlagCarrier` is a proxy rather than a hidden selection, so the
texture is applied with `setFlagTexture` in an init handler — the same way
vanilla `FlagChecked_F` does it.

For vehicle liveries see **LIVERIES.md**.

## Verify in-game

The addon builds clean and every classname was checked against the extracted
RHS configs, but the following want eyes on them in the Eden editor:

1. **Side.** These units inherit from an RHS BLUFOR base (`SoldierWB`) with
   `side = 0` overridden. Confirm they place as OPFOR and that BLUFOR shoots
   at them. This is the most likely thing to be wrong.
2. **Uniform textures.** Check the OG-107 / ERDL / mixed variants actually
   swap — the `hiddenSelectionsTextures` paths point into RHS's Tanoa data.
3. **Headgear randomisation.** Riflemen should spawn with a mix of bare and
   painted M1 shells and the odd field cap, not all identical.
4. **Voices.** `identityTypes` uses `LanguageGRE_F` — Greek radio protocol,
   the usual stand-in for a non-English-speaking faction, since Arma has no
   Spanish voice set. Swap if it grates.
5. **Groups.** Confirm all thirteen Pereño and eleven Guardia groups appear
   under their factions in Zeus.
6. **La Guardia optics actually mount.** The EOTech / ACOG MDO and AN/PEQ-15
   are attached through `LinkedItems` onto a CBA ASDG rail. Spawn a Guardia
   and confirm the rifle has glass on it, not irons — this is the one part of
   layer 2 that depends on runtime rail compatibility rather than a
   classname, so it is the thing most likely to silently not work.
7. **La Guardia insignia.** They inherit RHS's Spectre-SKWO uniform, which
   carries ChDKZ chevrons in its texture set. Fine for now; replacing them
   needs a custom `.paa`.
8. **Kestrel radar takes damage.** See the radar caveat above — this is the
   most likely thing in layer 3 to not work as intended.
9. **MANPADS engage.** Fly something over a `MANPADS Team` and confirm they
   actually launch. AI MANPADS behaviour is sensitive to engagement rules and
   `Batería AA` in particular should be checked with both the ZU-23-2 and the
   Igla pod manned.

10. **Flags render.** Place each of the four flagpoles and confirm the design
    fills the cloth. (First playtest caught these offset ~40% — the base class
    was `FlagChecked_F`, the checkered racing flag, whose cloth UV differs.
    Now on `FlagCarrier`, the proper mast.)
11. **Guardia UAZ / Ural repaint.** Park a `PTF_Guardia_uaz_ags` next to a
    `PTF_Pereno_uaz_open` and confirm they are tellable apart at distance —
    Guardia should be visibly darker. Check the Ural cab *and* tarp both took
    the repaint.
12. **Guardia BMP-2 stencil.** Confirm "LA GUARDIA" reads correctly on **both**
    hull flanks, right way up, and that the camouflage is otherwise identical
    to a stock RHS BMP-2.
13. **Kestrel Humvee markings.** Place `PTF_Kestrel_m1025_m2` and confirm it
    carries Kestrel chevrons and `KESTREL GROUP` rather than RHS's stock 101st
    Airborne 2/502 decals — and that the rest of the vehicle is still normally
    textured, not white. White anywhere means a selection index is off.

14. **Kestrel sniper glass.** The XM2010 should carry its M2010 day scope and
    a Harris bipod, the M107 a Leupold Mk4. (First playtest caught the sniper
    on bare irons — same weapons[]-cannot-carry-attachments trap as the
    Guardia AK-103s, fixed the same way in `kestrel/cfgKestrelWeapons.hpp`.)
15. **Kestrel vest variety.** A Kestrel fireteam should show a different
    carrier on every man — plateframe/SPC variants per role, not four copies
    of the base MBAV.
16. **HVTs.** Each faction has one (`... (HVT)` in the name) plus an escort
    group. Pereño HVT is deliberately soft; Guardia HVT keeps veteran kit;
    Kestrel HVT is a civilian silhouette among operators.
17. **New vehicles spawn with correct crews.** Boats (HIDF hulls rebadged),
    helicopters (Mi-8/UH-1H for the garrison, Mi-17Sh/Mi-35 for La Guardia,
    MH-6/AH-6 little birds for Kestrel), trucks (ZiL/KrAZ/GAZ vs KamAZ),
    and the AA layer: gun-only for the garrison (ZU-23 static and truck-
    mounted), the campaign's only SPAAG for La Guardia (ZSU-23-4), and
    Kestrel's Stinger pod + crewed P-37 search radar.
18. **The P-37 radar mans and dies.** Unlike the SERHAT prop it is a real
    crewed vehicle — confirm a gunner sits in it and that it can be killed.

## Later passes

- Unit insignia (shoulder patches) — the flags are done, arm insignia is not.
- Markings for the GREF vehicles (BMP-2 first) — see LIVERIES.md; those hulls
  have no decal slot so the marking composites onto the body texture.
- Replacing the ChDKZ chevrons on La Guardia's Spectre uniform.
- A purpose-built destructible radar model, if the `destrType` override on
  the SERHAT prop turns out not to be enough.
