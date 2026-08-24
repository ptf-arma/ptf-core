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
   // Six loose magazines, not four. Ammunition is the one thing a union that
   // unloads the freighters is never short of; four bakelites had them dry
   // before a fight was decided, which is thin even for irregulars. Six AK
   // mags (11.7 each), the grenade (6.82) and the first aid kit (8) come to
   // 85.02 against the 170 the shirt (30, not the 40 a PTF uniform holds)
   // and chest rig (140) hold, so nothing gets dropped at spawn.
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

// --- The union rank and file ----------------------------------------------

class PTF_Sind_miliciano: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Militiaman (AKM)";
};

class PTF_Sind_miliciano_akms: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Militiaman (AKMS)";
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
   displayName = "Dockworker (Shotgun)";
   cost = 40000;
   accuracy = 1.1;
   uniformClass = "PTF_U_sind_coveralls";
   linkedItems[] = {"H_Cap_blu", "V_BandollierB_blk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Cap_blu", "V_BandollierB_blk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_Izh18", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_Izh18", "Throw", "Put"};
   // Sixteen shells, not ten. A single-shot gun eats its pocketful fast, and
   // shells are what a bandolier is for. Sixteen singles (a couple of mass
   // each) plus the first aid kit are under 45 against the 120 the coveralls
   // (40) and bandolier (80) hold.
   magazines[] =
      {
         "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck",
         "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck",
         "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck",
         "rhsgref_1Rnd_00Buck",
         "rhsgref_1Rnd_Slug", "rhsgref_1Rnd_Slug", "rhsgref_1Rnd_Slug",
         "rhsgref_1Rnd_Slug", "rhsgref_1Rnd_Slug", "rhsgref_1Rnd_Slug"
      };
   respawnMagazines[] =
      {
         "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck",
         "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck",
         "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck", "rhsgref_1Rnd_00Buck",
         "rhsgref_1Rnd_00Buck",
         "rhsgref_1Rnd_Slug", "rhsgref_1Rnd_Slug", "rhsgref_1Rnd_Slug",
         "rhsgref_1Rnd_Slug", "rhsgref_1Rnd_Slug", "rhsgref_1Rnd_Slug"
      };
};

// The timberman. A Yugoslav rifle that has felled more pigs than men.
class PTF_Sind_maderero: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Logger (M70)";
   uniformClass = "U_BG_Guerilla2_1";
   linkedItems[] = {"H_Booniehat_oli", "V_BandollierB_oli", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Booniehat_oli", "V_BandollierB_oli", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_m70ab2", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_m70ab2", "Throw", "Put"};
   // Six steel magazines, not four -- same reasoning as the base class, and
   // the ceiling here is lower: six mags (13.53 each) and the first aid kit
   // come to 89.18 against the 110 the guerrilla shirt (30, a vanilla one,
   // not the 40 a PTF uniform holds) and bandolier (80) hold. A seventh fits
   // in neither container and would be dropped at spawn; he does not get one.
   magazines[] =
      {
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
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
   displayName = "Hunter (Mosin)";
   icon = "iconManRecon";
   accuracy = 2.6;
   sensitivity = 3.0;
   camouflage = 0.7;
   cost = 90000;
   uniformClass = "U_BG_Guerilla3_1";
   linkedItems[] = {"H_StrawHat_dark", "V_BandollierB_khk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_StrawHat_dark", "V_BandollierB_khk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_m38", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_m38", "Throw", "Put"};
   // Ten clips -- fifty rounds. He shoots one at a time and makes them count,
   // but forty was a short afternoon. Stripper clips are light: ten of them
   // (2.64 each) and the first aid kit come to 34.4 against the 130 the shirt
   // (50) and bandolier (80) hold, so capacity is nowhere near the reason he
   // carries ten.
   magazines[] =
      {
         "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38",
         "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38",
         "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38",
         "rhsgref_5Rnd_762x54_m38"
      };
   respawnMagazines[] =
      {
         "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38",
         "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38",
         "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38", "rhsgref_5Rnd_762x54_m38",
         "rhsgref_5Rnd_762x54_m38"
      };
};

// A grease gun that came off a freighter in 1971 and never left.
class PTF_Sind_contrabandista: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Smuggler (M3A1)";
   uniformClass = "U_I_C_Soldier_Bandit_5_F";
   linkedItems[] = {"H_Watchcap_blk", "V_TacVest_blk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Watchcap_blk", "V_TacVest_blk", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_m3a1", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_m3a1", "Throw", "Put"};
   // Six magazines, not four. A grease gun on full auto is four magazines of
   // fun and then a club; the smuggler of all people has ammunition. Six .45
   // sticks (17.47 each) and the first aid kit come to 112.82 against the 130
   // the shirt (30, a vanilla one, not the 40 a PTF uniform holds) and tac
   // vest (100) hold. A seventh stick fits in neither container and would be
   // dropped at spawn, so six is the ceiling.
   magazines[] =
      {
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG",
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
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG"
      };
};

// The machinegunner's spare belts. Same mechanism as PTF_B_guardia_pkp:
// magazines[] can only reach the uniform and the vest, so anything past the
// worn belts has to ride in a container preloaded through
// TransportMagazines. The base is
// B_Carryall_cbr, the big canvas holdall the Kestrel MANPADS packs already
// use -- exactly the bag a docker hauls line in, and at 320 capacity two
// belts (128.7) do not come near filling it.
class PTF_B_sind_pkm: B_Carryall_cbr
{
   author = "Paramarine Task Force";
   // Hidden: a loadout component, not something to place. The empty carryall
   // is already in the arsenal if a mission maker wants one.
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

// The winch man. A PKM that came ashore in the same shipment as the grease
// gun and has been kept oiled in a crane cab ever since. The union's one
// belt-fed gun, feeding on the hunter's cartridge: the cazador's Mosin
// shoots the same 7.62x54R, and nothing else in the port does.
//
// (An RPD in the AKMs' own 7.62x39 was the first choice, but no installed
// RHS mod defines rhs_weap_rpd or a 7.62x39 belt -- verified against GREF,
// AFRF and USAF 0.5.6 configs -- so the classname was a startup error
// waiting to happen. The PKM is the nearest gun that actually exists.)
//
// Two belts worn, two more in the holdall -- four hundred rounds, against
// the garrison machinegunner's seven belts and La Guardia's five. The belts
// are listed first because the engine packs in array order and a belt does
// not fit the coveralls' 40; at the belt's actual 64.35 mass, two of them
// (128.70) plus the first aid kit (8) and the RGD-5 (6.82) come to 143.52
// against the 180 the coveralls (40) and chest rig (140) hold. Per container,
// which is how the engine actually packs, that is 128.70 of 140 in the rig
// and 14.82 of 40 in the coveralls, so all of it goes on.
class PTF_Sind_ametrallador: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Machine Gunner (PKM)";
   cost = 120000;
   icon = "iconManMG";
   uniformClass = "PTF_U_sind_coveralls";
   linkedItems[] = {"H_Bandanna_khk", "V_Chestrig_oli", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Bandanna_khk", "V_Chestrig_oli", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   backpack = "PTF_B_sind_pkm";
   weapons[] = {"rhs_weap_pkm", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_pkm", "Throw", "Put"};
   magazines[] =
      {
         "rhs_100Rnd_762x54mmR",
         "rhs_100Rnd_762x54mmR",
         "rhs_mag_rgd5"
      };
   respawnMagazines[] =
      {
         "rhs_100Rnd_762x54mmR",
         "rhs_100Rnd_762x54mmR",
         "rhs_mag_rgd5"
      };
};

// Dockyard dynamite, union-audited. What he does to a culvert is nobody's
// business but the union's.
//
// Two magazines, not four. The toolkit alone is 80 mass and the mine
// detector another 20, against 140 for the coveralls (40) and tac vest (100)
// together -- and the engine packs Items[] before magazines[], so the last
// two magazines and the grenade were being dropped at spawn. He does his
// real work with what is in the demo pack anyway.
class PTF_Sind_dinamitero: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Dynamiter";
   cost = 110000;
   engineer = 1;
   canDeactivateMines = 1;
   icon = "iconManExplosive";
   uniformClass = "PTF_U_sind_coveralls";
   linkedItems[] = {"H_Bandanna_cbr", "V_TacVest_oli", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Bandanna_cbr", "V_TacVest_oli", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   backpack = "rhsgref_ins_pack_demo";
   Items[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   RespawnItems[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   weapons[] = {"rhs_weap_akms", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_akms", "Throw", "Put"};
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite"
      };
};

class PTF_Sind_sanitario: PTF_Sind_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Medic";
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
   displayName = "Liaison (Radio)";
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
   displayName = "Ringleader";
   cost = 180000;
   accuracy = 1.8;
   sensitivity = 3.2;
   icon = "iconManLeader";
   uniformClass = "U_BG_leader";
   linkedItems[] = {"H_Booniehat_khk", "V_TacChestrig_grn_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"H_Booniehat_khk", "V_TacChestrig_grn_F", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_akm", "rhs_weap_tt33", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_akm", "rhs_weap_tt33", "Throw", "Put", "Binocular"};
   // Six rifle magazines to match his men -- the man they trust should not be
   // the first one dry. With the two Tokarev magazines and the first aid kit
   // the lot is under 100 mass, comfortably inside the shirt (40) and chest
   // rig (140).
   magazines[] =
      {
         "rhs_30Rnd_762x39mm_bakelite",
         "rhs_30Rnd_762x39mm_bakelite",
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
