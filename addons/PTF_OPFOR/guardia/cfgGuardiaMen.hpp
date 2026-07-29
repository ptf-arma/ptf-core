// ---------------------------------------------------------------------------
// La Guardia -- Destacamento Especial Bastida
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
         "rhs_mag_rgd5"
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
         "rhs_mag_rgd5"
      };
};

// --- Line troops -----------------------------------------------------------

class PTF_Guardia_rifleman: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Guardia";
};

// The escalation tier. Dual-tube night vision, a ranged optic and noticeably
// better skill. Field these when a meeting is supposed to be worse than the
// last one.
//
// The carrier is rhsusf_mbav_light, not rhsusf_mbav. RHS's plain
// rhsusf_mbav is the bare plate carrier with no pouches on it -- it holds
// 20, against 140 for the mbav_rifleman the standard trooper wears. The
// veteran tier was silently spawning with three magazines instead of eight
// because of it. mbav_light holds 100, which with the uniform's 40 carries
// the full eight-magazine load and still reads as a leaner rig than the
// line trooper's.
class PTF_Guardia_rifleman_vet: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Guardia Veterano";
   accuracy = 3.0;
   sensitivity = 3.8;
   cost = 340000;
   weapons[] = {"PTF_weap_guardia_ak103_mdo", "Throw", "Put"};
   respawnWeapons[] = {"PTF_weap_guardia_ak103_mdo", "Throw", "Put"};
   linkedItems[] = {"rhsusf_opscore_01_tan", "rhsusf_mbav_light", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "rhsusf_acc_ACOG_MDO", "rhsusf_acc_anpeq15"};
   respawnLinkedItems[] = {"rhsusf_opscore_01_tan", "rhsusf_mbav_light", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "rhsusf_acc_ACOG_MDO", "rhsusf_acc_anpeq15"};
};

class PTF_Guardia_grenadier: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Granadero (GP-25)";
   cost = 300000;
   linkedItems[] = {"rhsusf_opscore_01", "rhsusf_mbav_grenadier", "rhsusf_ANPVS_14", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01", "rhsusf_mbav_grenadier", "rhsusf_ANPVS_14", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"PTF_weap_guardia_ak103_gp25", "Throw", "Put"};
   respawnWeapons[] = {"PTF_weap_guardia_ak103_gp25", "Throw", "Put"};
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
         "rhs_mag_rgd5"
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
         "rhs_mag_rgd5"
      };
};

// PKP Pecheneg with a 1P78. A better gun than the garrison's FN MAG, and a
// much heavier one to feed: a 100-round 7.62x54R belt is 64.35 mass against
// 32.34 for the MAG's 7.62 NATO belt. Two is all the MBAV MG carrier's 160
// will hold, and nothing that big fits the uniform's 40 -- the five belts
// this class used to declare meant three were dropped at spawn.
class PTF_Guardia_machinegunner: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Ametrallador (PKP)";
   cost = 380000;
   linkedItems[] = {"rhsusf_opscore_01", "rhsusf_mbav_mg", "rhsusf_ANPVS_14", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01", "rhsusf_mbav_mg", "rhsusf_ANPVS_14", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_pkp_1p78", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_pkp_1p78", "Throw", "Put"};
   magazines[] =
      {
         "rhs_100Rnd_762x54mmR_green",
         "rhs_100Rnd_762x54mmR_green",
         "rhs_mag_rgd5"
      };
   respawnMagazines[] =
      {
         "rhs_100Rnd_762x54mmR_green",
         "rhs_100Rnd_762x54mmR_green",
         "rhs_mag_rgd5"
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
// rocket out. Three rockets never fitted at all; one of each warhead does.
class PTF_Guardia_at: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Contracarro (RPG-7 PGO)";
   cost = 360000;
   weapons[] = {"PTF_weap_guardia_ak103", "rhs_weap_rpg7_pgo", "Throw", "Put"};
   respawnWeapons[] = {"PTF_weap_guardia_ak103", "rhs_weap_rpg7_pgo", "Throw", "Put"};
   magazines[] =
      {
         "rhs_rpg7_PG7VR_mag",
         "rhs_rpg7_TBG7V_mag",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer"
      };
   respawnMagazines[] =
      {
         "rhs_rpg7_PG7VR_mag",
         "rhs_rpg7_TBG7V_mag",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer"
      };
};

class PTF_Guardia_marksman: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Tirador (SVDS)";
   cost = 400000;
   accuracy = 3.4;
   sensitivity = 4.0;
   // mbav_light (100), not the pouchless rhsusf_mbav (20) -- see the
   // veteran class above. Eight SVD magazines and a sidearm do not fit 20.
   linkedItems[] = {"rhsusf_opscore_01_tan", "rhsusf_mbav_light", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01_tan", "rhsusf_mbav_light", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_svds_pso1", "rhs_weap_pya", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_svds_pso1", "rhs_weap_pya", "Throw", "Put"};
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
         "rhs_mag_9x19_17"
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
         "rhs_mag_9x19_17"
      };
};

// Six magazines rather than the standard eight: the Medikit is 80 mass on
// its own, which is 40% of what his uniform and medic carrier hold between
// them, and Items[] are packed before magazines[].
class PTF_Guardia_medic: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Sanitario";
   cost = 320000;
   attendant = 1;
   icon = "iconManMedic";
   linkedItems[] = {"rhsusf_opscore_01", "rhsusf_mbav_medic", "rhsusf_ANPVS_14", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01", "rhsusf_mbav_medic", "rhsusf_ANPVS_14", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   Items[] = {"FirstAidKit", "Medikit"};
   RespawnItems[] = {"FirstAidKit", "Medikit"};
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_rgd5",
         "rhs_mag_rgd5"
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
         "rhs_mag_rgd5"
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
   displayName = "Zapador";
   cost = 330000;
   engineer = 1;
   canDeactivateMines = 1;
   icon = "iconManEngineer";
   Items[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   RespawnItems[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_rgd5"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_rgd5"
      };
};

class PTF_Guardia_crewman: PTF_Guardia_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Tripulante";
   cost = 260000;
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_rgd5"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_rgd5"
      };
};

// --- Cadre -----------------------------------------------------------------

class PTF_Guardia_teamleader: PTF_Guardia_rifleman_vet
{
   displayName = "Jefe de Equipo";
   cost = 420000;
   icon = "iconManLeader";
   weapons[] = {"PTF_weap_guardia_ak103_mdo", "rhs_weap_pya", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"PTF_weap_guardia_ak103_mdo", "rhs_weap_pya", "Throw", "Put", "Binocular"};
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
         "rhs_mag_nspd"
      };
};

class PTF_Guardia_squadleader: PTF_Guardia_teamleader
{
   displayName = "Jefe de Seccion";
   cost = 520000;
   accuracy = 3.2;
   sensitivity = 4.0;
};

class PTF_Guardia_officer: PTF_Guardia_teamleader
{
   displayName = "Comandante";
   cost = 600000;
   accuracy = 3.0;
   sensitivity = 3.9;
};

// --- HVT -------------------------------------------------------------------
//
// Bastida's senior man on the ground. La Guardia are defeated by killing them,
// so unlike the Pereno HVT this one is not a soft target -- he keeps the
// veteran optic and night vision. What marks him out is the beret instead of
// a helmet, and the sidearm.
class PTF_Guardia_hvt: PTF_Guardia_officer
{
   displayName = "Oficial Superior (HVT)";
   cost = 1100000;
   accuracy = 3.2;
   sensitivity = 4.0;
   icon = "iconManLeader";
   headgearList[] = {"rhsgref_patrolcap_specter", 1};
   linkedItems[] = {"rhsgref_patrolcap_specter", "rhsgref_TacVest_ERDL", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_patrolcap_specter", "rhsgref_TacVest_ERDL", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};

class PTF_Guardia_pilot: PTF_Guardia_crewman
{
   displayName = "Piloto";
   cost = 350000;
};
