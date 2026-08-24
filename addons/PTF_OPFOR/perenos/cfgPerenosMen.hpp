// ---------------------------------------------------------------------------
// Infantry Battalion No. 7 "Pera" -- los Perenos
//
// Design intent (campaign layer 1): the original Valmeran army garrison.
// Conscripts stiffened by long-service NCOs, all island-born. Ageing rifles,
// no night vision worth the name, poorly paid and paid late.
//
// This is expressed in config rather than left to mission scripting:
//   * NO unit in this faction carries NVGs. Night is the players' advantage.
//   * Conscripts and sentries get LOW `sensitivity` -- they man a checkpoint
//     properly and then stop paying attention. NCOs and officers get high
//     `sensitivity`, because the long-service cadre is the competent part.
//   * Kit quality tiers visibly by rank: conscripts in OG-107 with a field
//     cap, riflemen in mixed OG-107/ERDL with M1 steel, NCOs in full ERDL
//     with a PASGT. A player should be able to read who matters by looking.
//   * Ammunition loads are deliberately thin -- thin against La Guardia's
//     eight polymer magazines, not starvation. Unit feedback after the first
//     missions was that three or four magazines read as a bug rather than as
//     poverty, so line troops now carry five or six; the tier gap is held by
//     La Guardia carrying eight, not by the garrison running dry at first
//     contact.
// ---------------------------------------------------------------------------

class PTF_Pereno_base: rhsgref_hidf_base
{
   scope = 0;
   scopeCurator = 0;
   author = "Paramarine Task Force";
   side = 0;                              // EAST
   faction = "PTF_OPFOR_Perenos";
   vehicleClass = "Men";
   editorSubcategory = "EdSubcat_Personnel";
   genericNames = "PTF_ValmeranMen";
   // Island-born, island-recruited: Tanoan-weighted faces, the island
   // voice protocol (the closest Arma has to a Caribbean garrison).
   identityTypes[] = {"LanguageENGFRE_F", "Head_Tanoan", "Head_Tanoan", "Head_African", "Head_Euro"};
   modelSides[] = {0, 1, 2, 3};

   // Conscript baseline: slow to identify a target, slow to notice one.
   accuracy = 1.0;
   sensitivity = 1.2;
   camouflage = 1.5;
   cost = 40000;

   // Declared so child classes can extend the inherited handlers rather than
   // replace them -- the headgear randomiser below hangs off this.
   class EventHandlers;

   uniformClass = "PTF_U_pereno_og107";
   hiddenSelections[] = {"Camo"};
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_tanoa\m93_og107_co.paa"};

   Items[] = {"FirstAidKit"};
   RespawnItems[] = {"FirstAidKit"};

   // No NVG entry here, and none added by any child class. Deliberate.
   linkedItems[] = {"rhsgref_hat_M1951", "rhsgref_alice_webbing", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_hat_M1951", "rhsgref_alice_webbing", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};

   weapons[] = {"rhs_weap_l1a1_wood", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_l1a1_wood", "Throw", "Put"};
   // Six magazines and a grenade: 8 + 99 + 8.8 = 115.8 of the 160 the
   // uniform (40) and ALICE webbing (120) hold, first aid kit packed first.
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67"
      };
};

// --- Rank and file ---------------------------------------------------------

// The bottom of the barrel: a teenager on a checkpoint with a rifle, two
// spare magazines and a cap. Lowest sensitivity in the faction.
//
// He keeps the base class's ALICE webbing. The brief is ageing equipment, not
// absent equipment, and stripping the webbing left him with the OG-107
// uniform's 40 as his whole carrying capacity -- a first aid kit is 8 and a
// 20-round FAL magazine is 16.5, so exactly one magazine fitted and the rest
// were dropped at spawn. With the webbing's 120 he carries his three: 8 + 49.5
// against 160. What marks him out is the cap, the sensitivity and the thin
// load, not the absence of a belt order.
class PTF_Pereno_sentry: PTF_Pereno_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Sentry";
   sensitivity = 0.8;
   cost = 25000;
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal"
      };
};

class PTF_Pereno_conscript: PTF_Pereno_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Conscript";
   sensitivity = 1.0;
   cost = 35000;
   // Five, still a magazine and a grenade short of the rifleman's load:
   // 8 + 82.5 against the same 160.
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal"
      };
};

// Helmet is randomised per spawn: bare and painted M1 shells in a mix, so a
// squad looks like it was issued out of a depot rather than a catalogue.
class PTF_Pereno_rifleman: PTF_Pereno_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Rifleman";
   uniformClass = "PTF_U_pereno_og107_erdl";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_tanoa\m93_og107_erdl_co.paa"};
   class EventHandlers: EventHandlers
   {
      init = "if (local (_this select 0)) then {[(_this select 0), [], nil] call BIS_fnc_unitHeadgear;}";
   };
   headgearList[] =
      {
         "rhsgref_helmet_M1_bare", 3,
         "rhsgref_helmet_M1_bare_alt01", 2,
         "rhsgref_helmet_M1_painted", 2,
         "rhsgref_helmet_M1_painted_alt01", 1,
         "rhsgref_hat_M1951", 2
      };
   linkedItems[] = {"rhsgref_helmet_M1_bare", "rhsgref_alice_webbing", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_helmet_M1_bare", "rhsgref_alice_webbing", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};

// Depot stock is not uniform. A minority of the battalion carries AKMs from
// an older aid shipment, and they do not share magazines with the FAL men.
class PTF_Pereno_rifleman_akm: PTF_Pereno_rifleman
{
   displayName = "Rifleman (AKM)";
   weapons[] = {"rhs_weap_akm", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_akm", "Throw", "Put"};
   // Six steel mags to mirror the FAL men's six. An AK magazine is lighter
   // than a FAL one, so this sits well inside the same 160.
   magazines[] =
      {
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_mag_m67"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_mag_m67"
      };
};

// --- Specialists -----------------------------------------------------------

class PTF_Pereno_grenadier: PTF_Pereno_rifleman
{
   displayName = "Grenadier (M79)";
   cost = 90000;
   backpack = "rhsgref_hidf_alicepack_gr";
   weapons[] = {"rhs_weap_m79", "rhsusf_weap_m1911a1", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_m79", "rhsusf_weap_m1911a1", "Throw", "Put"};
   magazines[] =
      {
         "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE",
         "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE",
         "rhs_mag_M433_HEDP", "rhs_mag_M433_HEDP",
         "rhsusf_mag_7x45acp_MHP", "rhsusf_mag_7x45acp_MHP"
      };
   respawnMagazines[] =
      {
         "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE",
         "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE",
         "rhs_mag_M433_HEDP", "rhs_mag_M433_HEDP",
         "rhsusf_mag_7x45acp_MHP", "rhsusf_mag_7x45acp_MHP"
      };
};

// The FN MAG is the battalion's real weapon. It is also the thing most worth
// killing first, and it only has three belts.
class PTF_Pereno_machinegunner: PTF_Pereno_rifleman
{
   displayName = "Machine Gunner (FN MAG)";
   cost = 130000;
   icon = "iconManMG";
   backpack = "rhsgref_hidf_alicepack_mg";
   weapons[] = {"rhs_weap_fnmag", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_fnmag", "Throw", "Put"};
   magazines[] = {"rhsusf_100Rnd_762x51", "rhsusf_100Rnd_762x51", "rhsusf_100Rnd_762x51", "rhs_mag_m67"};
   respawnMagazines[] = {"rhsusf_100Rnd_762x51", "rhsusf_100Rnd_762x51", "rhsusf_100Rnd_762x51", "rhs_mag_m67"};
};

class PTF_Pereno_machinegunner_assist: PTF_Pereno_rifleman
{
   displayName = "Assistant Machine Gunner";
   cost = 100000;
   backpack = "rhsgref_hidf_alicepack_mg";
};

// The AT man's spare rockets. magazines[] can only reach the uniform and the
// webbing, and their 160 is spoken for (see the class below), so rockets past
// the second live in a container the engine will not fill by itself. Same
// mechanism as rhsgref_hidf_alicepack_mg, which already carries the
// machinegunner's spare belts, and PTF_B_guardia_pkp across the fence.
// Two PG-7V is 63 of the ALICE pack's 320.
class PTF_B_pereno_rpg: rhsgref_hidf_alicepack
{
   author = "Paramarine Task Force";
   // Hidden: a loadout component, not something to place. The empty ALICE
   // pack is already in the arsenal if a mission maker wants one.
   scope = 1;
   scopeCurator = 0;
   displayName = "ALICE Pack (RPG)";
   class TransportMagazines
   {
      class _xx_rhs_rpg7_PG7V_mag
      {
         magazine = "rhs_rpg7_PG7V_mag";
         count = 2;
      };
   };
};

// Four rockets: one in the tube, one on the webbing, two in the pack. Mission
// feedback was that the AT man fired once and was finished, which made him a
// prop rather than a threat. The warhead stays PG-7V -- the garrison's RPG is
// a vehicle answer, not a fragmentation one, and the tandem rounds stay
// La Guardia's.
//
// Rockets are listed first: the engine packs Items[] and then magazines[] in
// array order, and a rifle magazine seated ahead of a 31.5-mass rocket would
// push it out. First aid kit (8) + two rockets (63) + five FAL magazines
// (82.5) = 153.5 of the 160 the uniform (40) and ALICE webbing (120) hold.
class PTF_Pereno_at: PTF_Pereno_rifleman
{
   displayName = "AT Rifleman (RPG-7)";
   cost = 120000;
   icon = "iconManAT";
   backpack = "PTF_B_pereno_rpg";
   weapons[] = {"rhs_weap_l1a1_wood", "rhs_weap_rpg7", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_l1a1_wood", "rhs_weap_rpg7", "Throw", "Put"};
   magazines[] =
      {
         "rhs_rpg7_PG7V_mag",
         "rhs_rpg7_PG7V_mag",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal"
      };
   respawnMagazines[] =
      {
         "rhs_rpg7_PG7V_mag",
         "rhs_rpg7_PG7V_mag",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal"
      };
};

// L1A1 with the old SUIT sight -- the closest thing the garrison has to a
// precision weapon, and a daylight-only one.
class PTF_Pereno_marksman: PTF_Pereno_rifleman
{
   displayName = "Marksman";
   cost = 140000;
   icon = "iconManRecon";
   accuracy = 1.6;
   sensitivity = 2.0;
   weapons[] = {"rhs_weap_l1a1_suit", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_l1a1_suit", "Throw", "Put"};
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal"
      };
};

class PTF_Pereno_medic: PTF_Pereno_rifleman
{
   displayName = "Medic";
   cost = 160000;
   attendant = 1;
   icon = "iconManMedic";
   backpack = "rhsgref_hidf_alicepack_medic";
};

// The engine packs per container, not against a combined total, so the sum of
// the uniform and vest capacities is the wrong number to reason with. Items[]
// go in first: the first aid kit (8) and mine detector (20) fill 28 of the
// uniform's 40, and the toolkit (80) plus two FAL magazines (33) fill 113 of
// the webbing's 120. A third magazine is 16.5 and fits neither container --
// 44.5 in the uniform, 129.5 in the webbing -- so it would be dropped at
// spawn without a word. Two is the ceiling. (The ALICE pack does not help:
// the engine only fills the uniform and vest when it distributes
// magazines[].)
class PTF_Pereno_engineer: PTF_Pereno_rifleman
{
   displayName = "Engineer";
   cost = 150000;
   engineer = 1;
   canDeactivateMines = 1;
   icon = "iconManEngineer";
   backpack = "rhsgref_hidf_alicepack";
   Items[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   RespawnItems[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal"
      };
};

class PTF_Pereno_crewman: PTF_Pereno_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Crewman";
   cost = 80000;
   weapons[] = {"rhs_weap_m3a1", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_m3a1", "Throw", "Put"};
   magazines[] =
      {
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG"
      };
   respawnMagazines[] =
      {
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG"
      };
};

// --- Cadre -----------------------------------------------------------------
//
// The long-service NCOs are the competent half of the battalion and are
// kitted to show it. High sensitivity: these men are actually watching.
// They are also the intended point of failure -- the garrison is defeated by
// fracture, and fracture starts when the man giving orders goes down.

class PTF_Pereno_teamleader: PTF_Pereno_rifleman
{
   displayName = "Corporal";
   cost = 220000;
   accuracy = 1.8;
   sensitivity = 2.6;
   icon = "iconManLeader";
   uniformClass = "PTF_U_pereno_erdl";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_tanoa\m93_erdl_co.paa"};
   headgearList[] = {"rhsgref_helmet_M1_painted", 2, "rhsgref_helmet_M1_painted_alt01", 1};
   linkedItems[] = {"rhsgref_helmet_M1_painted", "rhsgref_chestrig", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_helmet_M1_painted", "rhsgref_chestrig", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_l1a1", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_l1a1", "Throw", "Put", "Binocular"};
   // Six fit: the chest rig (100) and uniform (40) hold 140, and the first
   // aid kit (8) + six FAL magazines (99) + grenade and smoke (8.8, 11.9)
   // come to 127.7.
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67",
         "rhs_mag_m18_red"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67",
         "rhs_mag_m18_red"
      };
};

class PTF_Pereno_squadleader: PTF_Pereno_teamleader
{
   displayName = "Sergeant";
   cost = 320000;
   accuracy = 2.0;
   sensitivity = 3.0;
   headgearList[] = {"rhsgref_helmet_pasgt_erdl", 3, "rhsgref_helmet_pasgt_olive", 1};
   linkedItems[] = {"rhsgref_helmet_pasgt_erdl", "rhsgref_TacVest_ERDL", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_helmet_pasgt_erdl", "rhsgref_TacVest_ERDL", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   // Same 140 of capacity as the Corporal, carrying a second smoke on top,
   // but the split is what matters: the uniform is at 33.30 of 40 and the
   // vest at 89.76 of 100. A sixth magazine is 16.5 and fits neither, so it
   // would be dropped at spawn. Five is the ceiling here.
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67",
         "rhs_mag_m18_red",
         "rhs_mag_m18_yellow"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67",
         "rhs_mag_m18_red",
         "rhs_mag_m18_yellow"
      };
};

class PTF_Pereno_officer: PTF_Pereno_squadleader
{
   displayName = "Lieutenant";
   cost = 400000;
   sensitivity = 2.8;
   icon = "iconManOfficer";
   headgearList[] = {"rhsgref_hat_M1951", 2, "rhsgref_helmet_pasgt_erdl", 1};
   linkedItems[] = {"rhsgref_hat_M1951", "rhsgref_TacVest_ERDL", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_hat_M1951", "rhsgref_TacVest_ERDL", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_l1a1", "rhsusf_weap_m1911a1", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_l1a1", "rhsusf_weap_m1911a1", "Throw", "Put", "Binocular"};
   // Five rifle magazines now that the line carries six: 8 + 82.5 + two
   // smokes (23.8) is 114.3 of 140, and the two pistol magazines fit in
   // what is left with room to spare.
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhsusf_mag_7x45acp_MHP",
         "rhsusf_mag_7x45acp_MHP",
         "rhs_mag_m18_red",
         "rhs_mag_m18_purple"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhsusf_mag_7x45acp_MHP",
         "rhsusf_mag_7x45acp_MHP",
         "rhs_mag_m18_red",
         "rhs_mag_m18_purple"
      };
};

// --- HVT -------------------------------------------------------------------
//
// Deliberately readable at a distance so players can pick him out of a group:
// no helmet, a distinct cap, a pistol instead of a rifle, and binoculars.
// The garrison is defeated by fracture, and this is the man whose loss starts
// it -- taking him should feel like it changed something.
class PTF_Pereno_hvt: PTF_Pereno_officer
{
   displayName = "Battalion Commander (HVT)";
   cost = 900000;
   accuracy = 2.2;
   sensitivity = 3.0;
   icon = "iconManOfficer";
   headgearList[] = {"rhsgref_hat_M1951", 1};
   linkedItems[] = {"rhsgref_hat_M1951", "rhsgref_chestrig", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_hat_M1951", "rhsgref_chestrig", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhsusf_weap_m1911a1", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhsusf_weap_m1911a1", "Throw", "Put", "Binocular"};
   magazines[] =
      {
         "rhsusf_mag_7x45acp_MHP",
         "rhsusf_mag_7x45acp_MHP",
         "rhsusf_mag_7x45acp_MHP",
         "rhs_mag_m18_red"
      };
   respawnMagazines[] =
      {
         "rhsusf_mag_7x45acp_MHP",
         "rhsusf_mag_7x45acp_MHP",
         "rhsusf_mag_7x45acp_MHP",
         "rhs_mag_m18_red"
      };
};

// A crewman who flies. No flight suit, no survival vest -- the battalion's
// pilots dress like everyone else because they are everyone else.
class PTF_Pereno_pilot: PTF_Pereno_crewman
{
   displayName = "Pilot";
   cost = 150000;
};
