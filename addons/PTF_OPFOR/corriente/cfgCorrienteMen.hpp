// ---------------------------------------------------------------------------
// La Corriente -- the cartel coalition of the Operation Undertow campaign
// (mainland Colombia, UMB Colombia map). Follows the Road to War deck.
//
// The brief, from the deck:
//   * "Large and spread across the region. Controls most river crossings."
//   * "AKs and Galils, technicals, fast river boats and cheap FPV drones."
//   * "Pays civilians to act as lookouts. Assume you are being watched."
//   * "NOT DECLARED HOSTILE. Engage only on a hostile act or hostile intent."
//
// That last line is the design constraint that matters: INDEPENDENT (side 2),
// like El Sindicato, so a mission maker sets the cartel's hostility per-op
// with setFriend instead of fighting the config. The PTF is not at war with
// La Corriente; the config must not make it so.
//
// Design notes:
//   * Not an army, but not a union either: these men have fought a civil war
//     for months. Better shots than El Sindicato, sharper than the Pereno
//     conscripts, nowhere near La Guardia. camouflage 0.9 -- river locals.
//   * The signature unit is the halcon, the paid lookout: nearly harmless,
//     nearly invisible, and the best sensor the cartel owns. Killing him is
//     how the players tell the region whose side they are on.
//   * The deck says "AKs and Galils". No installed RHS mod ships a Galil
//     (checked GREF/AFRF/USAF), so the captured-army-rifle tier is an AK-74M
//     instead -- deliberately in 5.45, a different ammunition family from the
//     cartel's 7.62x39 AKMs, so a picked-up magazine teaches the same lesson
//     it does for the Pereno FAL/AKM split.
//   * "Cheap FPV drones" has no attack-drone equivalent in the content base;
//     the drone operator flies a vanilla AR-2 Darter as commercial-grade
//     eyes in the sky, which is the half of the threat that changes how
//     players move.
// ---------------------------------------------------------------------------

class PTF_Corr_base: I_G_Soldier_base_F
{
   scope = 0;
   scopeCurator = 0;
   author = "Paramarine Task Force";
   side = 2;
   faction = "PTF_IND_Corriente";
   vehicleClass = "Men";
   editorSubcategory = "EdSubcat_Personnel";
   genericNames = "PTF_ValmeranMen";
   identityTypes[] = {"LanguageGRE_F", "Head_Tanoan", "Head_African", "Head_Euro", "Head_Euro", "G_GUERIL_default"};

   // Months of civil war: better than the union, far short of the Guardia.
   accuracy = 1.6;
   sensitivity = 2.2;
   camouflage = 0.9;
   cost = 80000;

   class EventHandlers;

   uniformClass = "U_I_C_Soldier_Bandit_1_F";

   Items[] = {"FirstAidKit"};
   RespawnItems[] = {"FirstAidKit"};

   linkedItems[] = {"H_ShemagOpen_tan", "V_Chestrig_khk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_ShemagOpen_tan", "V_Chestrig_khk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};

   weapons[] = {"rhs_weap_akm", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_akm", "Throw", "Put"};
   // Six bakelites and a grenade, same arithmetic as the Sindicato base
   // class: 6 x 11.5 + 6.82 + 8 = 83.82 against the 170 the bandit shirt
   // (30) and chest rig (140) hold. The cartel is not short of ammunition.
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_mag_rgd5"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_mag_rgd5"
      };
};

// --- The lookout network -----------------------------------------------------

// The halcon: a man with a phone, a ballcap and a reason to be standing there.
// The deck's "assume you are being watched", as a placeable unit.
//
// The stats are the point. sensitivity 3.6 -- watching is his whole job --
// against accuracy 0.6 and a pocket pistol he has fired twice. camouflage 0.6
// because nothing about him reads as a combatant. He is not a fight; he is
// the reason the fight arrives ten minutes later.
class PTF_Corr_halcon: PTF_Corr_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Lookout (Halcon)";
   accuracy = 0.6;
   sensitivity = 3.6;
   camouflage = 0.6;
   cost = 20000;
   class EventHandlers: EventHandlers
   {
      init = "if (local (_this select 0)) then {[(_this select 0), [], nil] call BIS_fnc_unitHeadgear;}";
   };
   // All ballcaps, different ballcaps: two lookouts on the same corner must
   // not be wearing the same hat.
   headgearList[] =
      {
         "H_Cap_blk", 2,
         "H_Cap_oli", 1,
         "H_Cap_red", 1,
         "H_Cap_blu", 1
      };
   uniformClass = "U_C_Poloshirt_blue";
   linkedItems[] = {"H_Cap_blk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Cap_blk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_makarov_pm", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_makarov_pm", "Throw", "Put", "Binocular"};
   magazines[] = {"rhs_mag_9x18_8_57N181S", "rhs_mag_9x18_8_57N181S"};
   respawnMagazines[] = {"rhs_mag_9x18_8_57N181S", "rhs_mag_9x18_8_57N181S"};
};

// --- The gunmen --------------------------------------------------------------
// Headgear is randomised per spawn on the rank and file, the same
// headgearList + BIS_fnc_unitHeadgear mechanism as the Pereno riflemen: a
// coalition hires whoever shows up, and ten men under ten identical shemags
// read as an army, which is the one thing the cartel must not read as.
// Specialists and leaders keep fixed headgear -- kit reads rank at a glance,
// per the house style.

class PTF_Corr_miliciano: PTF_Corr_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Gunman (AKM)";
   class EventHandlers: EventHandlers
   {
      init = "if (local (_this select 0)) then {[(_this select 0), [], nil] call BIS_fnc_unitHeadgear;}";
   };
   headgearList[] =
      {
         "H_ShemagOpen_tan", 2,
         "H_Shemag_olive", 1,
         "H_Cap_blk", 2,
         "H_Bandanna_gry", 2,
         "H_Booniehat_tan", 1
      };
};

class PTF_Corr_miliciano_akms: PTF_Corr_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Gunman (AKMS)";
   class EventHandlers: EventHandlers
   {
      init = "if (local (_this select 0)) then {[(_this select 0), [], nil] call BIS_fnc_unitHeadgear;}";
   };
   headgearList[] =
      {
         "H_Bandanna_gry", 2,
         "H_Cap_blk", 2,
         "H_ShemagOpen_tan", 1,
         "H_Cap_oli", 1
      };
   uniformClass = "U_I_C_Soldier_Bandit_3_F";
   linkedItems[] = {"H_Bandanna_gry", "V_TacVest_brn", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Bandanna_gry", "V_TacVest_brn", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_akms", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_akms", "Throw", "Put"};
   // The tac vest holds 100 against the rig's 140: five bakelites, not six.
   // Per container the shirt takes the aid kit and one magazine (19.50 of 30)
   // and the vest the other four and the grenade (52.82 of 100).
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_mag_rgd5"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_mag_rgd5"
      };
};

// The captured-army-rifle tier -- the deck's "Galils", see the header note.
// 5.45 on purpose: his magazines fit nothing else in the faction.
class PTF_Corr_fusilero: PTF_Corr_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Rifleman (AK-74M)";
   class EventHandlers: EventHandlers
   {
      init = "if (local (_this select 0)) then {[(_this select 0), [], nil] call BIS_fnc_unitHeadgear;}";
   };
   headgearList[] =
      {
         "H_Booniehat_tan", 2,
         "H_ShemagOpen_tan", 1,
         "H_Bandanna_gry", 1,
         "H_Shemag_olive", 1
      };
   uniformClass = "U_BG_Guerilla2_2";
   linkedItems[] = {"H_Booniehat_tan", "V_Chestrig_khk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Booniehat_tan", "V_Chestrig_khk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_ak74m", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_ak74m", "Throw", "Put"};
   magazines[] =
      {
         "rhs_30Rnd_545x39_7N10_AK",
         "rhs_30Rnd_545x39_7N10_AK",
         "rhs_30Rnd_545x39_7N10_AK",
         "rhs_30Rnd_545x39_7N10_AK",
         "rhs_30Rnd_545x39_7N10_AK",
         "rhs_30Rnd_545x39_7N10_AK",
         "rhs_mag_rgd5"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_545x39_7N10_AK",
         "rhs_30Rnd_545x39_7N10_AK",
         "rhs_30Rnd_545x39_7N10_AK",
         "rhs_30Rnd_545x39_7N10_AK",
         "rhs_30Rnd_545x39_7N10_AK",
         "rhs_30Rnd_545x39_7N10_AK",
         "rhs_mag_rgd5"
      };
};

// --- Support weapons ---------------------------------------------------------

// The blooper again -- the same surplus channel that armed the Perenos runs
// south too. Sidearm because a single-shot launcher is not a rifle.
class PTF_Corr_granadero: PTF_Corr_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Grenadier (M79)";
   icon = "iconManExplosive";
   uniformClass = "U_BG_Guerilla2_3";
   linkedItems[] = {"H_Shemag_olive", "V_TacVest_brn", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Shemag_olive", "V_TacVest_brn", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_m79", "rhs_weap_tt33", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_m79", "rhs_weap_tt33", "Throw", "Put"};
   magazines[] =
      {
         "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE",
         "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE",
         "rhs_mag_M433_HEDP", "rhs_mag_M433_HEDP",
         "rhs_mag_762x25_8", "rhs_mag_762x25_8"
      };
   respawnMagazines[] =
      {
         "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE",
         "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE",
         "rhs_mag_M433_HEDP", "rhs_mag_M433_HEDP",
         "rhs_mag_762x25_8", "rhs_mag_762x25_8"
      };
};

// The machinegunner's spare belts, same TransportMagazines mechanism as
// every other preloaded pack in the addon -- magazines[] cannot reach a
// backpack. Carryall base: 320 capacity, two belts (128.7) rattle in it.
class PTF_B_corr_pkm: B_Carryall_cbr
{
   author = "Paramarine Task Force";
   // Hidden: a loadout component, not something to place.
   scope = 1;
   scopeCurator = 0;
   displayName = "Canvas Holdall (PKM)";
   class TransportMagazines
   {
      class _xx_rhs_100Rnd_762x54mmR
      {
         magazine = "rhs_100Rnd_762x54mmR";
         count = 2;
      };
   };
};

// Two belts worn, two in the holdall -- the Sindicato winch man's arithmetic
// exactly: belts first because 64.35 fits no shirt, 128.70 of 140 in the rig,
// aid kit + grenade + smoke in the shirt (24.82 of 30).
class PTF_Corr_ametrallador: PTF_Corr_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Machine Gunner (PKM)";
   cost = 130000;
   icon = "iconManMG";
   uniformClass = "U_BG_Guerilla2_2";
   linkedItems[] = {"H_Bandanna_gry", "V_Chestrig_khk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Bandanna_gry", "V_Chestrig_khk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   backpack = "PTF_B_corr_pkm";
   weapons[] = {"rhs_weap_pkm", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_pkm", "Throw", "Put"};
   magazines[] =
      {
         "rhs_100Rnd_762x54mmR",
         "rhs_100Rnd_762x54mmR",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white"
      };
   respawnMagazines[] =
      {
         "rhs_100Rnd_762x54mmR",
         "rhs_100Rnd_762x54mmR",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white"
      };
};

// The AT gunner's reloads. Two more PG-7Vs (31.5 each) in a carryall.
class PTF_B_corr_rpg: B_Carryall_cbr
{
   author = "Paramarine Task Force";
   // Hidden: a loadout component, not something to place.
   scope = 1;
   scopeCurator = 0;
   displayName = "Canvas Holdall (RPG)";
   class TransportMagazines
   {
      class _xx_rhs_rpg7_PG7V_mag
      {
         magazine = "rhs_rpg7_PG7V_mag";
         count = 2;
      };
   };
};

// What the cartel points at an NAC truck. Rockets first in the array: a
// PG-7V (31.5) fits no 30-capacity shirt, so both go to the rig (63 of 140);
// the shirt takes the aid kit and one bakelite (19.5 of 30), the rig the
// other one (74.5 of 140). Nothing is dropped at spawn.
class PTF_Corr_rpg: PTF_Corr_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "AT Gunner (RPG-7)";
   cost = 120000;
   icon = "iconManAT";
   uniformClass = "U_BG_Guerilla2_3";
   linkedItems[] = {"H_ShemagOpen_tan", "V_Chestrig_khk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_ShemagOpen_tan", "V_Chestrig_khk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   backpack = "PTF_B_corr_rpg";
   weapons[] = {"rhs_weap_akms", "rhs_weap_rpg7", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_akms", "rhs_weap_rpg7", "Throw", "Put"};
   magazines[] =
      {
         "rhs_rpg7_PG7V_mag",
         "rhs_rpg7_PG7V_mag",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite"
      };
   respawnMagazines[] =
      {
         "rhs_rpg7_PG7V_mag",
         "rhs_rpg7_PG7V_mag",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite"
      };
};

// A Dragunov that came across a border, scope still on it. The riverbank
// overwatch the deck's checkpoints imply.
class PTF_Corr_tirador: PTF_Corr_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Marksman (SVDS)";
   icon = "iconManRecon";
   accuracy = 2.6;
   sensitivity = 2.8;
   camouflage = 0.8;
   cost = 150000;
   uniformClass = "U_BG_Guerilla3_2";
   linkedItems[] = {"H_Booniehat_tan", "V_BandollierB_cbr", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Booniehat_tan", "V_BandollierB_cbr", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_svds_pso1", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_svds_pso1", "Throw", "Put"};
   magazines[] =
      {
         "rhs_10Rnd_762x54mmR_7N1", "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1", "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1", "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1", "rhs_10Rnd_762x54mmR_7N1",
         "rhs_mag_rdg2_white"
      };
   respawnMagazines[] =
      {
         "rhs_10Rnd_762x54mmR_7N1", "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1", "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1", "rhs_10Rnd_762x54mmR_7N1",
         "rhs_10Rnd_762x54mmR_7N1", "rhs_10Rnd_762x54mmR_7N1",
         "rhs_mag_rdg2_white"
      };
};

// --- The bought tier ---------------------------------------------------------

// The sicario: what Kestrel's "training, drones, air transport and cash"
// looks like when it walks. A new AK-103 with polymer magazines -- the same
// rifle La Guardia carries, because the same money bought it -- but on IRON
// SIGHTS, deliberately. Kestrel sells rifles and a month of drills; it does
// not sell EOTechs to a cartel. The tier gap between a sicario (2.4 / 3.2,
// six magazines, no optic, no armour) and a Guardia veteran (glass, plates,
// eight magazines, night vision) is the campaign's proof that money spent on
// men beats money spent on gear only up to a point.
class PTF_Corr_sicario: PTF_Corr_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Sicario (AK-103)";
   accuracy = 2.4;
   sensitivity = 3.2;
   cost = 300000;
   uniformClass = "U_BG_Guerilla2_1";
   linkedItems[] = {"H_Shemag_olive", "V_TacChestrig_cbr_F", "G_Balaclava_blk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Shemag_olive", "V_TacChestrig_cbr_F", "G_Balaclava_blk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_ak103", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_ak103", "Throw", "Put"};
   // Six polymer magazines, a frag and a smoke: 6 x 11.5 + 6.82 + 10 + 8 =
   // 93.82 against the 170 the guerrilla shirt (30) and chest rig (140)
   // hold. Not eight magazines -- eight is La Guardia's number, and the
   // sicario is not La Guardia.
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
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
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_30Rnd_762x39mm_polymer",
         "rhs_mag_rgd5",
         "rhs_mag_rdg2_white"
      };
};

// --- Specialists -------------------------------------------------------------

// The deck's "cheap FPV drones", as close as the content base gets: a
// commercial-grade quadcopter and a man who is better at flying it than at
// everything else he does. The terminal is Independent-side (I_UavTerminal),
// which only connects to Independent drones -- the faction's Darter is one.
class PTF_Corr_dronero: PTF_Corr_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Drone Operator (AR-2)";
   cost = 160000;
   sensitivity = 3.0;
   uavHacker = 1;
   uniformClass = "U_I_C_Soldier_Bandit_3_F";
   linkedItems[] = {"H_Cap_blk", "V_TacVest_brn", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "I_UavTerminal"};
   respawnLinkedItems[] = {"H_Cap_blk", "V_TacVest_brn", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "I_UavTerminal"};
   backpack = "I_UAV_01_backpack_F";
   weapons[] = {"rhs_weap_akms", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_akms", "Throw", "Put"};
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite"
      };
};

// The boat crew. The rivers are the cartel's roads; he is the driver.
class PTF_Corr_lanchero: PTF_Corr_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Boatman";
   cost = 70000;
   camouflage = 1.0;
   class EventHandlers: EventHandlers
   {
      init = "if (local (_this select 0)) then {[(_this select 0), [], nil] call BIS_fnc_unitHeadgear;}";
   };
   headgearList[] =
      {
         "H_Bandanna_gry", 2,
         "H_Cap_blk", 1,
         "H_Booniehat_tan", 1
      };
   uniformClass = "U_C_Poloshirt_salmon";
   linkedItems[] = {"H_Bandanna_gry", "V_BandollierB_cbr", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Bandanna_gry", "V_BandollierB_cbr", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_akms", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_akms", "Throw", "Put"};
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite"
      };
};

class PTF_Corr_sanitario: PTF_Corr_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Medic";
   cost = 100000;
   attendant = 1;
   icon = "iconManMedic";
   uniformClass = "U_BG_Guerilla1_1";
   linkedItems[] = {"H_Cap_blk", "V_TacVest_brn", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Cap_blk", "V_TacVest_brn", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   backpack = "rhsgref_nat_backpack_medic";
   weapons[] = {"rhs_weap_makarov_pm", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_makarov_pm", "Throw", "Put"};
   magazines[] = {"rhs_mag_9x18_8_57N181S", "rhs_mag_9x18_8_57N181S", "rhs_mag_9x18_8_57N181S"};
   respawnMagazines[] = {"rhs_mag_9x18_8_57N181S", "rhs_mag_9x18_8_57N181S", "rhs_mag_9x18_8_57N181S"};
};

// --- The structure -----------------------------------------------------------

// The jefe: obeyed because he pays, feared because he decides who does not
// get paid. Smoke and no frag, like the Sindicato ringleader -- his job in a
// fight is telling boats and trucks where to be.
class PTF_Corr_jefe: PTF_Corr_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Squad Boss (Jefe)";
   cost = 220000;
   accuracy = 2.0;
   sensitivity = 3.0;
   icon = "iconManLeader";
   uniformClass = "U_BG_leader";
   linkedItems[] = {"H_Booniehat_tan", "V_TacChestrig_cbr_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Booniehat_tan", "V_TacChestrig_cbr_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_akm", "rhs_weap_tt33", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_akm", "rhs_weap_tt33", "Throw", "Put", "Binocular"};
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_mag_762x25_8",
         "rhs_mag_762x25_8",
         "rhs_mag_rdg2_white"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_mag_762x25_8",
         "rhs_mag_762x25_8",
         "rhs_mag_rdg2_white"
      };
};

// "Machete". Field commander; name unknown -- the deck's one named box on
// the cartel's org chart, and the campaign's way into the rest of it. The
// balaclava is the identity: nobody has a face to put on the name, and the
// players should not get one for free either.
class PTF_Corr_machete: PTF_Corr_jefe
{
   displayName = "Machete - Field Commander (HVT)";
   cost = 600000;
   accuracy = 2.4;
   sensitivity = 3.4;
   camouflage = 0.8;
   uniformClass = "U_BG_Guerilla2_3";
   linkedItems[] = {"H_ShemagOpen_tan", "V_TacChestrig_cbr_F", "G_Balaclava_blk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_ShemagOpen_tan", "V_TacChestrig_cbr_F", "G_Balaclava_blk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_akms", "rhs_weap_tt33", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_akms", "rhs_weap_tt33", "Throw", "Put", "Binocular"};
};

// The river boss -- the deck's second unknown box: "Who controls the boats
// and river checkpoints?" This is who. A businessman, not a fighter: a
// pocket pistol, binoculars, and the best sensitivity in the faction short
// of Machete, because he has spent twenty years reading the river for
// customs launches. He dies easily; the intelligence he represents does not
// arrive twice.
class PTF_Corr_patron: PTF_Corr_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "River Boss (HVT)";
   icon = "iconManLeader";
   accuracy = 1.2;
   sensitivity = 3.4;
   camouflage = 0.9;
   cost = 500000;
   uniformClass = "U_I_G_resistanceLeader_F";
   linkedItems[] = {"H_Cap_blk", "V_I_G_resistanceLeader_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Cap_blk", "V_I_G_resistanceLeader_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_tt33", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_tt33", "Throw", "Put", "Binocular"};
   magazines[] = {"rhs_mag_762x25_8", "rhs_mag_762x25_8"};
   respawnMagazines[] = {"rhs_mag_762x25_8", "rhs_mag_762x25_8"};
};
