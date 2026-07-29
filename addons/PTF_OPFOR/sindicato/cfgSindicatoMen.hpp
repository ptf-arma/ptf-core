// ---------------------------------------------------------------------------
// El Sindicato -- the dockworkers' and timber union of Bocachico.
//
// The only organisation on the island with a structure Bastida didn't build.
// They have the port, the trucks, and the only communications network he
// doesn't monitor. They will help. They also have their own agenda, their own
// scores to settle from fourteen months of occupation, and a leadership that
// is not uniformly admirable.
//
// INDEPENDENT (side 2), deliberately: a partner force that is genuinely
// useful and genuinely inconvenient, and mission makers can flip its
// friendliness per-op with setFriend without touching config.
//
// Design notes:
//   * Not soldiers. Work clothes, bandanas and ballcaps; weapons are whatever
//     came off a boat or out of a shed -- AKMs, an old Yugoslav M70, break-
//     action shotguns, a Mosin, one grease gun. No optics anywhere. No
//     helmets anywhere. No body armour beyond a chest rig.
//   * They know the island: camouflage is the BEST in the campaign (0.7-0.9)
//     while accuracy stays worker-grade. They see you first; whether they hit
//     you is another matter.
//   * The Apex "Syndikat" bandit shirts are Independent-linked, so no
//     side-lock reissue is needed for them; only the docker coveralls (a
//     civilian item) get a PTF_U wrapper.
// ---------------------------------------------------------------------------

class PTF_Sind_base: I_G_Soldier_base_F
{
   scope = 0;
   scopeCurator = 0;
   author = "Paramarine Task Force";
   side = 2;
   faction = "PTF_IND_Sindicato";
   vehicleClass = "Men";
   editorSubcategory = "EdSubcat_Personnel";
   genericNames = "PTF_ValmeranMen";
   identityTypes[] = {"LanguageENGFRE_F", "Head_Tanoan", "Head_Tanoan", "Head_African", "Head_Euro", "G_GUERIL_default"};

   // Workers who know every trail: sharp eyes, untrained trigger.
   accuracy = 1.3;
   sensitivity = 2.4;
   camouflage = 0.8;
   cost = 60000;

   class EventHandlers;

   uniformClass = "U_I_C_Soldier_Bandit_2_F";

   Items[] = {"FirstAidKit"};
   RespawnItems[] = {"FirstAidKit"};

   linkedItems[] = {"H_Cap_oli", "V_Chestrig_oli", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Cap_oli", "V_Chestrig_oli", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};

   weapons[] = {"rhs_weap_akm", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_akm", "Throw", "Put"};
   magazines[] =
      {
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
         "rhs_mag_rgd5"
      };
};

// --- The union rank and file ----------------------------------------------

class PTF_Sind_miliciano: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Miliciano (AKM)";
};

class PTF_Sind_miliciano_akms: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Miliciano (AKMS)";
   uniformClass = "U_I_C_Soldier_Bandit_4_F";
   linkedItems[] = {"H_Bandanna_khk", "V_TacChestrig_oli_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Bandanna_khk", "V_TacChestrig_oli_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_akms", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_akms", "Throw", "Put"};
};

// The docker. Coveralls, a shotgun behind the crane cab.
class PTF_Sind_estibador: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Estibador (Escopeta)";
   cost = 40000;
   accuracy = 1.1;
   uniformClass = "PTF_U_sind_coveralls";
   linkedItems[] = {"H_Cap_blu", "V_BandollierB_blk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Cap_blu", "V_BandollierB_blk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_Izh18", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_Izh18", "Throw", "Put"};
   magazines[] =
      {
         "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck",
         "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck",
         "rhsgref_1Rnd_Slug", "rhsgref_1Rnd_Slug", "rhsgref_1Rnd_Slug", "rhsgref_1Rnd_Slug"
      };
   respawnMagazines[] =
      {
         "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck",
         "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck",
         "rhsgref_1Rnd_Slug", "rhsgref_1Rnd_Slug", "rhsgref_1Rnd_Slug", "rhsgref_1Rnd_Slug"
      };
};

// The timberman. A Yugoslav rifle that has felled more pigs than men.
class PTF_Sind_maderero: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Maderero (M70)";
   uniformClass = "U_BG_Guerilla2_1";
   linkedItems[] = {"H_Booniehat_oli", "V_BandollierB_oli", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Booniehat_oli", "V_BandollierB_oli", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_m70ab2", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_m70ab2", "Throw", "Put"};
   magazines[] =
      {
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm"
      };
};

// Grandfather's rifle. He is, infuriatingly, the best shot in the union.
class PTF_Sind_cazador: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Cazador (Mosin)";
   accuracy = 2.6;
   sensitivity = 3.0;
   camouflage = 0.7;
   cost = 90000;
   uniformClass = "U_BG_Guerilla3_1";
   linkedItems[] = {"H_StrawHat_dark", "V_BandollierB_khk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_StrawHat_dark", "V_BandollierB_khk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_m38", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_m38", "Throw", "Put"};
   magazines[] =
      {
         "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38",
         "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38",
         "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38"
      };
   respawnMagazines[] =
      {
         "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38",
         "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38",
         "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38"
      };
};

// A grease gun that came off a freighter in 1971 and never left.
class PTF_Sind_contrabandista: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Contrabandista (M3A1)";
   uniformClass = "U_I_C_Soldier_Bandit_5_F";
   linkedItems[] = {"H_Watchcap_blk", "V_TacVest_blk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Watchcap_blk", "V_TacVest_blk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
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

// Dockyard dynamite, union-audited. What he does to a culvert is nobody's
// business but the union's.
class PTF_Sind_dinamitero: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Dinamitero";
   cost = 110000;
   engineer = 1;
   canDeactivateMines = 1;
   icon = "iconManEngineer";
   uniformClass = "PTF_U_sind_coveralls";
   linkedItems[] = {"H_Bandanna_cbr", "V_TacVest_oli", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Bandanna_cbr", "V_TacVest_oli", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   backpack = "rhsgref_ins_pack_demo";
   Items[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   RespawnItems[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   weapons[] = {"rhs_weap_akms", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_akms", "Throw", "Put"};
};

class PTF_Sind_sanitario: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Sanitario";
   cost = 90000;
   attendant = 1;
   icon = "iconManMedic";
   uniformClass = "U_C_Poloshirt_burgundy";
   linkedItems[] = {"H_Cap_red", "V_TacVest_khk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Cap_red", "V_TacVest_khk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   backpack = "rhsgref_nat_backpack_medic";
   weapons[] = {"rhs_weap_makarov_pm", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_makarov_pm", "Throw", "Put"};
   magazines[] = {"rhs_mag_9x18_8_57N181S", "rhs_mag_9x18_8_57N181S", "rhs_mag_9x18_8_57N181S"};
   respawnMagazines[] = {"rhs_mag_9x18_8_57N181S", "rhs_mag_9x18_8_57N181S", "rhs_mag_9x18_8_57N181S"};
};

// --- The union's structure -------------------------------------------------
// The one thing Bastida never managed to build: people who are obeyed
// because they are trusted.

class PTF_Sind_enlace: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Enlace (Radio)";
   cost = 130000;
   sensitivity = 3.0;
   uniformClass = "U_I_C_Soldier_Bandit_3_F";
   linkedItems[] = {"H_Cap_headphones", "V_TacChestrig_cbr_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Cap_headphones", "V_TacChestrig_cbr_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   backpack = "B_AssaultPack_cbr";
   weapons[] = {"rhs_weap_tt33", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_tt33", "Throw", "Put", "Binocular"};
   magazines[] = {"rhs_mag_762x25_8", "rhs_mag_762x25_8", "rhs_mag_762x25_8"};
   respawnMagazines[] = {"rhs_mag_762x25_8", "rhs_mag_762x25_8", "rhs_mag_762x25_8"};
};

class PTF_Sind_cabecilla: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Cabecilla";
   cost = 180000;
   accuracy = 1.8;
   sensitivity = 3.2;
   icon = "iconManLeader";
   uniformClass = "U_BG_leader";
   linkedItems[] = {"H_Booniehat_khk", "V_TacChestrig_grn_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Booniehat_khk", "V_TacChestrig_grn_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_akm", "rhs_weap_tt33", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_akm", "rhs_weap_tt33", "Throw", "Put", "Binocular"};
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_mag_762x25_8",
         "rhs_mag_762x25_8"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_mag_762x25_8",
         "rhs_mag_762x25_8"
      };
};

// The union boss. He will get your wounded off the island and never let you
// forget it. Not uniformly admirable; entirely necessary.
class PTF_Sind_hvt: PTF_Sind_cabecilla
{
   displayName = "El Capataz (HVT)";
   cost = 400000;
   accuracy = 1.4;
   sensitivity = 3.4;
   uniformClass = "U_I_G_resistanceLeader_F";
   linkedItems[] = {"H_StrawHat", "V_I_G_resistanceLeader_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_StrawHat", "V_I_G_resistanceLeader_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_makarov_pm", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_makarov_pm", "Throw", "Put", "Binocular"};
   magazines[] = {"rhs_mag_9x18_8_57N181S", "rhs_mag_9x18_8_57N181S"};
   respawnMagazines[] = {"rhs_mag_9x18_8_57N181S", "rhs_mag_9x18_8_57N181S"};
};
