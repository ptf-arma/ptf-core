// ---------------------------------------------------------------------------
// La Guardia -- Bastida Special Detachment
//
// Design intent (campaign layer 2): Bastida's praetorians. Hand-picked, paid
// in hard currency, loyal to the man rather than to any flag or state.
// ~140 strong. Defeated by killing them -- there is no fracture to exploit
// and no spreadsheet to break.
//
// Built as the deliberate mechanical inverse of los Perenos:
//   * EVERY unit has working night vision. The garrison hands the players the
//     night; La Guardia takes it back. This is the single most important
//     difference between the two factions and should be felt immediately.
//   * `sensitivity` runs 3.2-4.0 across the board against the garrison's
//     0.8-3.0. They notice things. There is no inattentive tier here at all,
//     because La Guardia does not stand a bored checkpoint.
//   * Optics on every rifle (see cfgGuardiaWeapons.hpp), polymer magazines,
//     plate carriers, Ops-Core helmets. Where the garrison looks like a depot
//     emptied at random, La Guardia looks bought.
//   * Deep magazine loads. They can sustain a fight the garrison cannot.
//
// On escalation: the brief asks that every meeting be measurably worse than
// the last, which is pacing and belongs to the mission maker. What config
// provides is the *ladder* -- a standard trooper and a veteran tier that
// differ in optic, night vision and skill, plus support weapons to layer in.
// Escalate by fielding higher tiers and heavier groups, not by buffing.
// ---------------------------------------------------------------------------

class PTF_Guardia_base: rhsgref_ins_uniform_specter
{
   // rhsgref_ins_uniform_specter names an editor-preview image RHS never
   // shipped ("Cannot load texture ... rhsgref_ins_uniform_specter.paa").
   // Blank it; children inherit the blank. Same fix as PTF_Kestrel_base.
   editorPreview = "";
   scope = 0;
   scopeCurator = 0;
   author = "Paramarine Task Force";
   side = 0;                              // EAST
   faction = "PTF_OPFOR_Guardia";
   vehicleClass = "Men";
   editorSubcategory = "EdSubcat_Personnel";
   genericNames = "PTF_ValmeranMen";
   // Hand-picked from the whole country, not just the island: a broader
   // mix than the garrison, same voice protocol.
   identityTypes[] = {"LanguageENGFRE_F", "Head_Tanoan", "Head_Euro", "Head_African"};
   modelSides[] = {0, 1, 2, 3};

   // Professional baseline. Compare PTF_Pereno_base at 1.0 / 1.2.
   accuracy = 2.6;
   sensitivity = 3.2;
   camouflage = 1.2;
   cost = 250000;

   class EventHandlers;

   Items[] = {"FirstAidKit"};
   RespawnItems[] = {"FirstAidKit"};

   // ANPVS-14 as the floor. Nobody in this faction fights blind at night.
   linkedItems[] = {"rhsusf_opscore_01", "rhsusf_mbav_rifleman", "rhsusf_ANPVS_14", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "rhsusf_acc_eotech_xps3", "rhsusf_acc_anpeq15"};
   respawnLinkedItems[] = {"rhsusf_opscore_01", "rhsusf_mbav_rifleman", "rhsusf_ANPVS_14", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "rhsusf_acc_eotech_xps3", "rhsusf_acc_anpeq15"};

   weapons[] = {"PTF_weap_guardia_ak103", "Throw", "Put"};
   respawnWeapons[] = {"PTF_weap_guardia_ak103", "Throw", "Put"};
   // Smoke is the gap unit feedback found. The RGD-5 frags were always here;
   // nothing in the faction could screen a move. Two RDG-2 white on top of the
   // two frags, faction-wide, which is what makes La Guardia visibly heavier
   // than the garrison rather than only better-shooting.
   // Uniform (40): aid kit 8 + two AK 22.94 + one RGD-5 6.82 = 37.76.
   // Carrier (140): six AK 68.82 + one RGD-5 6.82 + two RDG-2 20 = 95.64.
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_rgd5",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white",
         "rhs_mag_rdg2_white"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_rgd5",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white",
         "rhs_mag_rdg2_white"
      };
};

// --- Line troops -----------------------------------------------------------

class PTF_Guardia_rifleman: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Guardia Rifleman";
};

// The escalation tier. Dual-tube night vision, a ranged optic and noticeably
// better skill. Field these when a meeting is supposed to be worse than the
// last one.
//
// The carrier is rhsusf_mbav_grenadier. RHS's plain rhsusf_mbav is the bare
// plate carrier with no pouches on it -- it holds 20, against 140 for the
// mbav_rifleman PTF_Guardia_base wears, and the veteran tier was silently
// spawning with three magazines instead of eight because of it. The
// grenadier rig holds 150 and is the most heavily pouched carrier in the
// MBAV family short of the MG and medic rigs, so the veteran now reads as
// better equipped than the line trooper rather than worse -- which is the
// whole point of the tier.
class PTF_Guardia_rifleman_vet: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Guardia Veteran";
   accuracy = 3.0;
   sensitivity = 3.8;
   cost = 340000;
   weapons[] = {"PTF_weap_guardia_ak103_mdo", "Throw", "Put"};
   respawnWeapons[] = {"PTF_weap_guardia_ak103_mdo", "Throw", "Put"};
   linkedItems[] = {"rhsusf_opscore_01_tan", "rhsusf_mbav_grenadier", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "rhsusf_acc_ACOG_MDO", "rhsusf_acc_anpeq15"};
   respawnLinkedItems[] = {"rhsusf_opscore_01_tan", "rhsusf_mbav_grenadier", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "rhsusf_acc_ACOG_MDO", "rhsusf_acc_anpeq15"};
};

class PTF_Guardia_grenadier: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Grenadier (GP-25)";
   cost = 300000;
   linkedItems[] = {"rhsusf_opscore_01", "rhsusf_mbav_grenadier", "rhsusf_ANPVS_14", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01", "rhsusf_mbav_grenadier", "rhsusf_ANPVS_14", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"PTF_weap_guardia_ak103_gp25", "Throw", "Put"};
   respawnWeapons[] = {"PTF_weap_guardia_ak103_gp25", "Throw", "Put"};
   // One frag and two RDG-2 white. He keeps one RGD-5 rather than the line's
   // two because ten GP-25 rounds are already his high explosive -- the VOG-25
   // and GDM-40 below are launcher magazines, not hand grenades, and none of
   // them were touched.
   // Uniform (40): aid kit 8 + two AK 22.94 + two VOG 8.25 = 39.19.
   // Carrier (150): four AK 45.88 + six VOG 24.75 + two GDM 8.25
   //   + one RGD-5 6.82 + two RDG-2 20 = 105.70.
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_VOG25", "rhs_VOG25", "rhs_VOG25", "rhs_VOG25",
         "rhs_VOG25", "rhs_VOG25", "rhs_VOG25", "rhs_VOG25",
         "rhs_GDM40", "rhs_GDM40",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white",
         "rhs_mag_rdg2_white"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_VOG25", "rhs_VOG25", "rhs_VOG25", "rhs_VOG25",
         "rhs_VOG25", "rhs_VOG25", "rhs_VOG25", "rhs_VOG25",
         "rhs_GDM40", "rhs_GDM40",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white",
         "rhs_mag_rdg2_white"
      };
};

// The machinegunner's belt pack. The AT gunner's rocket pack below works the
// same way, and together they are the faction's only backpacks.
//
// It exists because magazines[] can only reach the uniform and the vest, and
// a 100-round 7.62x54R belt is 64.35 mass: the MBAV MG carrier's 160 holds
// exactly two, and the uniform's 40 holds none. Everything past the second
// belt has to be put in a container the engine will not fill by itself.
//
// Preloaded through TransportMagazines rather than through a CBA init handler.
// Belts are ordinary magazines and need no runtime help; this is how RHS's own
// ammo-bearer packs do it, including rhsgref_hidf_alicepack_mg, which the
// Pereno machinegunner already wears with four FN MAG belts in it. Even the
// two Kestrel AA specialists, who once seated their missile rounds through CBA
// init handlers, now use this same mechanism -- declaring the CBA base class
// cost ~375 RPT warning lines per session (see the top of cfgKestrelMen.hpp).
//
// Eagle A-III holds 240. Three belts is 193.05 of it; a fourth would be 257.4
// and would not fit.
class PTF_B_guardia_pkp: rhsusf_assault_eagleaiii_coy
{
   author = "Paramarine Task Force";
   // Hidden: this is a loadout component, not something to place. The empty
   // Eagle A-III is already in the arsenal if a mission maker wants one.
   scope = 1;
   scopeCurator = 0;
   displayName = "Eagle A-III (PKP)";
   class TransportMagazines
   {
      class _xx_rhs_100Rnd_762x54mmR_green
      {
         magazine = "rhs_100Rnd_762x54mmR_green";
         count = 3;
      };
   };
};

// PKP Pecheneg with a 1P78. A better gun than the garrison's FN MAG, and a
// much heavier one to feed: a 100-round 7.62x54R belt is 64.35 mass against
// 32.34 for the MAG's 7.62 NATO belt.
//
// Two belts in magazines[] is the hard ceiling -- see PTF_B_guardia_pkp above,
// which carries the other three. Five belts total, which is what this class
// was written to carry and what the faction's tiering needs: the Pereno
// machinegunner has seven (three worn, four in his ALICE pack), and La Guardia
// must not be the side that runs dry first.
class PTF_Guardia_machinegunner: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Machine Gunner (PKP)";
   cost = 380000;
   icon = "iconManMG";
   backpack = "PTF_B_guardia_pkp";
   linkedItems[] = {"rhsusf_opscore_01", "rhsusf_mbav_mg", "rhsusf_ANPVS_14", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01", "rhsusf_mbav_mg", "rhsusf_ANPVS_14", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_pkp_1p78", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_pkp_1p78", "Throw", "Put"};
   // The frag and both RDG-2 white ride in the uniform, not the carrier. Two
   // belts leave 31.30 of the MG rig, but the uniform is nearly empty because
   // no belt will ever fit in it, so the grenades cost him nothing at all.
   // Uniform (40): aid kit 8 + one RGD-5 6.82 + two RDG-2 20 = 34.82.
   // Carrier (160): two belts 128.70, unchanged.
   magazines[] =
      {
         "rhs_100Rnd_762x54mmR_green",
         "rhs_100Rnd_762x54mmR_green",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white",
         "rhs_mag_rdg2_white"
      };
   respawnMagazines[] =
      {
         "rhs_100Rnd_762x54mmR_green",
         "rhs_100Rnd_762x54mmR_green",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white",
         "rhs_mag_rdg2_white"
      };
};

// The AT gunner's rocket pack. Same mechanism as PTF_B_guardia_pkp above,
// and it exists for the same reason: a PG-7VR or TBG-7V is 64.35 mass, the
// MBAV rifleman carrier's 140 takes exactly two, and unit feedback after
// missions was that the AT gunner died with nothing left to shoot.
//
// Eagle A-III holds 240. Three rockets is 193.05 of it; a fourth would be
// 257.4 and would not fit. The mix is two tandems and one thermobaric,
// weighted toward the armour-killing round because the worn pair on his
// chest already carries one of each.
class PTF_B_guardia_rpg: rhsusf_assault_eagleaiii_coy
{
   author = "Paramarine Task Force";
   // Hidden for the same reason as the belt pack: a loadout component, not
   // something to place.
   scope = 1;
   scopeCurator = 0;
   displayName = "Eagle A-III (RPG)";
   class TransportMagazines
   {
      class _xx_rhs_rpg7_PG7VR_mag
      {
         magazine = "rhs_rpg7_PG7VR_mag";
         count = 2;
      };
      class _xx_rhs_rpg7_TBG7V_mag
      {
         magazine = "rhs_rpg7_TBG7V_mag";
         count = 1;
      };
   };
};

// Tandem warheads. The garrison's RPG is a threat to a truck; this one is a
// threat to whatever the players actually arrived in.
//
// A PG-7VR tandem and a TBG-7V thermobaric are 64.35 mass each -- twice the
// garrison's PG-7V and far too big for the uniform's 40, so both have to go
// in the MBAV rifleman carrier's 140 and they leave 11 of it. The rockets
// are therefore listed FIRST: the engine fills containers in array order,
// and a rifle magazine seated in the carrier ahead of them would push a
// rocket out. A third rocket never fits anywhere on his torso -- rounds one
// and two ride in the carrier, and the other three ride in PTF_B_guardia_rpg
// on his back, exactly as the machinegunner's third through fifth belts do.
class PTF_Guardia_at: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "AT Gunner (RPG-7 PGO)";
   cost = 360000;
   icon = "iconManAT";
   backpack = "PTF_B_guardia_rpg";
   weapons[] = {"PTF_weap_guardia_ak103", "rhs_weap_rpg7_pgo", "Throw", "Put"};
   respawnWeapons[] = {"PTF_weap_guardia_ak103", "rhs_weap_rpg7_pgo", "Throw", "Put"};
   // He carried no hand grenade at all until now. One RGD-5 and one RDG-2
   // white fit, but only just, and only in this order.
   // Uniform (40): aid kit 8 + two AK 22.94 + one RGD-5 6.82 = 37.76, so the
   //   frag costs the carrier nothing.
   // Carrier (140): two rockets 128.70 + one RDG-2 10 = 138.70. That is 1.30
   //   of slack in the whole rig. A second smoke, or anything else added
   //   here, is dropped silently at spawn -- and the rockets stay first in
   //   the array so it is never a rocket that gets dropped.
   magazines[] =
      {
         "rhs_rpg7_PG7VR_mag",
         "rhs_rpg7_TBG7V_mag",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white"
      };
   respawnMagazines[] =
      {
         "rhs_rpg7_PG7VR_mag",
         "rhs_rpg7_TBG7V_mag",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white"
      };
};

class PTF_Guardia_marksman: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Marksman (SVDS)";
   cost = 400000;
   accuracy = 3.4;
   sensitivity = 4.0;
   icon = "iconManRecon";
   // mbav_rifleman (140), not the pouchless rhsusf_mbav (20) -- see the
   // veteran class above. Eight SVD magazines and a sidearm do not fit 20.
   // Same rig as the line trooper: the magazine pouches suit a DMR and it
   // keeps him from being the worst-equipped man in the platoon.
   linkedItems[] = {"rhsusf_opscore_01_tan", "rhsusf_mbav_rifleman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01_tan", "rhsusf_mbav_rifleman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_svds_pso1", "rhs_weap_pya", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_svds_pso1", "rhs_weap_pya", "Throw", "Put"};
   // He carried no grenades either. One RGD-5 and two RDG-2 white: smoke is
   // how a marksman breaks contact, and SVD magazines are light enough that
   // his carrier was barely a fifth full.
   // Uniform (40): aid kit 8 + six SVD 30.72 = 38.72.
   // Carrier (140): two SVD 10.24 + two pistol 14.98 + one RGD-5 6.82
   //   + two RDG-2 20 = 52.04.
   magazines[] =
      {
         "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1",
         "rhs_mag_9x19_17",
         "rhs_mag_9x19_17",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white",
         "rhs_mag_rdg2_white"
      };
   respawnMagazines[] =
      {
         "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1",
         "rhs_mag_9x19_17",
         "rhs_mag_9x19_17",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white",
         "rhs_mag_rdg2_white"
      };
};

// Six magazines rather than the standard eight: the Medikit is 80 mass on
// its own, which is 40% of what his uniform and medic carrier hold between
// them, and Items[] are packed before magazines[].
class PTF_Guardia_medic: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Medic";
   cost = 320000;
   attendant = 1;
   icon = "iconManMedic";
   linkedItems[] = {"rhsusf_opscore_01", "rhsusf_mbav_medic", "rhsusf_ANPVS_14", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01", "rhsusf_mbav_medic", "rhsusf_ANPVS_14", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   Items[] = {"FirstAidKit", "Medikit"};
   RespawnItems[] = {"FirstAidKit", "Medikit"};
   // One RDG-2 white rather than the line's two. The Medikit is 80 of the
   // medic carrier on its own, and one smoke leaves 17.30 of headroom against
   // the 7.30 a second would leave -- too thin a margin to want on the man
   // whose kit list is most likely to grow.
   // Uniform (40): aid kit 8 + two AK 22.94 + one RGD-5 6.82 = 37.76.
   // Carrier (160): Medikit 80 + four AK 45.88 + one RGD-5 6.82
   //   + one RDG-2 10 = 142.70.
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_rgd5",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_rgd5",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white"
      };
};

// La Guardia does the work the garrison will not. That includes demolitions,
// and it included the village near Cacao.
//
// Toolkit (80), mine detector (20) and first aid kit (8) come to 108 of the
// 180 his uniform and carrier hold, and the engine packs Items[] before
// magazines[]. Four magazines is what is left of the standard eight.
class PTF_Guardia_engineer: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Engineer";
   cost = 330000;
   engineer = 1;
   canDeactivateMines = 1;
   icon = "iconManEngineer";
   Items[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   RespawnItems[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   // One RDG-2 white, and one is the ceiling. A second would take the carrier
   // to 141.23 against 140 and be dropped at spawn without saying so.
   // Uniform (40): aid kit 8 + mine detector 20 + one AK 11.47 = 39.47.
   // Carrier (140): toolkit 80 + three AK 34.41 + one RGD-5 6.82
   //   + one RDG-2 10 = 131.23.
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white"
      };
};

class PTF_Guardia_crewman: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Crewman";
   cost = 260000;
   // A frag and one RDG-2 white. The smoke is the point for a crewman: it
   // covers a bail-out, which is the only fight he is likely to be in. There
   // is room for more, but a dismounted crew should still feel like a crew.
   // Uniform (40): aid kit 8 + two AK 22.94 + one RGD-5 6.82 = 37.76.
   // Carrier (140): two AK 22.94 + one RDG-2 10 = 32.94.
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white"
      };
};

// --- Cadre -----------------------------------------------------------------

class PTF_Guardia_teamleader: PTF_Guardia_rifleman_vet
{
   displayName = "Team Leader";
   cost = 420000;
   icon = "iconManLeader";
   weapons[] = {"PTF_weap_guardia_ak103_mdo", "rhs_weap_pya", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"PTF_weap_guardia_ak103_mdo", "rhs_weap_pya", "Throw", "Put", "Binocular"};
   // Marking is a leader's job, so the cadre carries both kinds of smoke: two
   // RDG-2 white to screen a move like everyone else, and the NSP-D, which is
   // orange signal smoke, to mark with. Nobody below team leader carries the
   // NSP-D, so an orange cloud on the field means somebody in charge is still
   // alive and still talking. Second RGD-5 added to match the line troops.
   // Uniform (40): aid kit 8 + two AK 22.94 + one pistol 7.49 = 38.43.
   // Carrier (150): four AK 45.88 + two RGD-5 13.64 + two RDG-2 20
   //   + one NSP-D 10 = 89.52.
   // The HVT inherits this list into a 100 carrier, not a 150 one. Read the
   // note on PTF_Guardia_hvt below before adding anything here.
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_9x19_17",
         "rhs_mag_rgd5",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white",
         "rhs_mag_rdg2_white",
         "rhs_mag_nspd"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_9x19_17",
         "rhs_mag_rgd5",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white",
         "rhs_mag_rdg2_white",
         "rhs_mag_nspd"
      };
};

class PTF_Guardia_squadleader: PTF_Guardia_teamleader
{
   displayName = "Squad Leader";
   cost = 520000;
   accuracy = 3.2;
   sensitivity = 4.0;
};

class PTF_Guardia_officer: PTF_Guardia_teamleader
{
   displayName = "Commander";
   cost = 600000;
   icon = "iconManOfficer";
   accuracy = 3.0;
   sensitivity = 3.9;
};

// --- HVT -------------------------------------------------------------------
//
// Bastida's senior man on the ground. La Guardia are defeated by killing them,
// so unlike the Pereno HVT this one is not a soft target -- he keeps the
// veteran optic and night vision. What marks him out is the beret instead of
// a helmet, and the sidearm.
//
// Capacity warning: he swaps the grenadier carrier for an ERDL tac vest,
// which holds 100 against 150, and he inherits the Commander's magazine list
// unchanged. That list puts 89.52 in the carrier, so the HVT has 10.48 of
// slack where the rest of the cadre has 60.48. Anything added to
// PTF_Guardia_teamleader has to be checked against this vest, not that one.
class PTF_Guardia_hvt: PTF_Guardia_officer
{
   displayName = "Senior Officer (HVT)";
   cost = 1100000;
   accuracy = 3.2;
   sensitivity = 4.0;
   headgearList[] = {"rhsgref_patrolcap_specter", 1};
   linkedItems[] = {"rhsgref_patrolcap_specter", "rhsgref_TacVest_ERDL", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_patrolcap_specter", "rhsgref_TacVest_ERDL", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};

class PTF_Guardia_pilot: PTF_Guardia_crewman
{
   displayName = "Pilot";
   cost = 350000;
};
