// ---------------------------------------------------------------------------
// Batallon de Infanteria No. 7 "Pera" -- los Perenos
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
//   * Ammunition loads are deliberately thin. They fight hard for about four
//     minutes; they do not have the magazines for a long engagement.
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
   magazines[] =
      {
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
         "rhs_mag_m67"
      };
};

// --- Rank and file ---------------------------------------------------------

// The bottom of the barrel: a teenager on a checkpoint with three magazines
// and a cap. Lowest sensitivity in the faction.
class PTF_Pereno_sentry: PTF_Pereno_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Centinela";
   sensitivity = 0.8;
   cost = 25000;
   linkedItems[] = {"rhsgref_hat_M1951", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_hat_M1951", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
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
   displayName = "Recluta";
   sensitivity = 1.0;
   cost = 35000;
   magazines[] =
      {
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
         "rhs_mag_20Rnd_762x51_m80_fnfal"
      };
};

// Helmet is randomised per spawn: bare and painted M1 shells in a mix, so a
// squad looks like it was issued out of a depot rather than a catalogue.
class PTF_Pereno_rifleman: PTF_Pereno_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Fusilero";
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
   displayName = "Fusilero (AKM)";
   weapons[] = {"rhs_weap_akm", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_akm", "Throw", "Put"};
   magazines[] =
      {
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
         "rhs_mag_m67"
      };
};

// --- Specialists -----------------------------------------------------------

class PTF_Pereno_grenadier: PTF_Pereno_rifleman
{
   displayName = "Granadero (M79)";
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
   displayName = "Ametrallador (FN MAG)";
   cost = 130000;
   backpack = "rhsgref_hidf_alicepack_mg";
   weapons[] = {"rhs_weap_fnmag", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_fnmag", "Throw", "Put"};
   magazines[] = {"rhsusf_100Rnd_762x51", "rhsusf_100Rnd_762x51", "rhsusf_100Rnd_762x51", "rhs_mag_m67"};
   respawnMagazines[] = {"rhsusf_100Rnd_762x51", "rhsusf_100Rnd_762x51", "rhsusf_100Rnd_762x51", "rhs_mag_m67"};
};

class PTF_Pereno_machinegunner_assist: PTF_Pereno_rifleman
{
   displayName = "Ayudante de Ametrallador";
   cost = 100000;
   backpack = "rhsgref_hidf_alicepack_mg";
};

class PTF_Pereno_at: PTF_Pereno_rifleman
{
   displayName = "Fusilero AT (RPG-7)";
   cost = 120000;
   backpack = "rhsgref_hidf_alicepack";
   weapons[] = {"rhs_weap_l1a1_wood", "rhs_weap_rpg7", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_l1a1_wood", "rhs_weap_rpg7", "Throw", "Put"};
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_rpg7_PG7V_mag",
         "rhs_rpg7_PG7V_mag",
         "rhs_rpg7_OG7V_mag"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_rpg7_PG7V_mag",
         "rhs_rpg7_PG7V_mag",
         "rhs_rpg7_OG7V_mag"
      };
};

// L1A1 with the old SUIT sight -- the closest thing the garrison has to a
// precision weapon, and a daylight-only one.
class PTF_Pereno_marksman: PTF_Pereno_rifleman
{
   displayName = "Tirador";
   cost = 140000;
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
   displayName = "Enfermero";
   cost = 160000;
   attendant = 1;
   icon = "iconManMedic";
   backpack = "rhsgref_hidf_alicepack_medic";
};

class PTF_Pereno_engineer: PTF_Pereno_rifleman
{
   displayName = "Zapador";
   cost = 150000;
   engineer = 1;
   canDeactivateMines = 1;
   icon = "iconManEngineer";
   backpack = "rhsgref_hidf_alicepack";
   Items[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   RespawnItems[] = {"FirstAidKit", "ToolKit", "MineDetector"};
};

class PTF_Pereno_crewman: PTF_Pereno_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Tripulante";
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
   displayName = "Cabo";
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
   displayName = "Sargento";
   cost = 320000;
   accuracy = 2.0;
   sensitivity = 3.0;
   headgearList[] = {"rhsgref_helmet_pasgt_erdl", 3, "rhsgref_helmet_pasgt_olive", 1};
   linkedItems[] = {"rhsgref_helmet_pasgt_erdl", "rhsgref_TacVest_ERDL", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_helmet_pasgt_erdl", "rhsgref_TacVest_ERDL", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
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
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67",
         "rhs_mag_m18_red",
         "rhs_mag_m18_yellow"
      };
};

class PTF_Pereno_officer: PTF_Pereno_squadleader
{
   displayName = "Teniente";
   cost = 400000;
   sensitivity = 2.8;
   headgearList[] = {"rhsgref_hat_M1951", 2, "rhsgref_helmet_pasgt_erdl", 1};
   linkedItems[] = {"rhsgref_hat_M1951", "rhsgref_TacVest_ERDL", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_hat_M1951", "rhsgref_TacVest_ERDL", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_l1a1", "rhsusf_weap_m1911a1", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_l1a1", "rhsusf_weap_m1911a1", "Throw", "Put", "Binocular"};
   magazines[] =
      {
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
   displayName = "Comandante de Batallon (HVT)";
   cost = 900000;
   accuracy = 2.2;
   sensitivity = 3.0;
   icon = "iconManLeader";
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
   displayName = "Piloto";
   cost = 150000;
};
