// ---------------------------------------------------------------------------
// Los Perenos motor pool.
//
// "Technicals, two or three armoured vehicles that may or may not run."
// Nothing here is retextured yet -- these are RHS hulls rebadged onto the
// faction so they appear under los Perenos in Eden and Zeus and spawn with
// Pereno crews instead of Chernarussian or HIDF ones. Custom liveries are a
// later texture pass; see README.md.
//
// The mix is deliberately incoherent -- Soviet soft-skins next to ex-US
// tracks -- because the battalion bought from whoever would sell.
// ---------------------------------------------------------------------------

// RHS's default insurgent UAZ texture (uaz_main_001) carries the red star of
// the old ChDKZ faction -- wrong on Valmera. RHS also ships uaz_main_002,
// identical camo without the star, so the garrison points there. Zero new
// texture cost.
class PTF_Pereno_uaz_open: rhsgref_ins_g_uaz_open
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "UAZ (Abierto)";
   crew = "PTF_Pereno_crewman";
   typicalCargo[] = {"PTF_Pereno_crewman", "PTF_Pereno_rifleman"};
   hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_a2port_car\uaz\data\uaz_main_002_co.paa"};
};

class PTF_Pereno_uaz_dshkm: rhsgref_ins_g_uaz_dshkm_chdkz
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "UAZ (DShKM)";
   crew = "PTF_Pereno_crewman";
   typicalCargo[] = {"PTF_Pereno_crewman", "PTF_Pereno_crewman"};
   hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_a2port_car\uaz\data\uaz_main_002_co.paa"};
};

class PTF_Pereno_ural: rhsgref_ins_g_ural
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Ural (Transporte)";
   crew = "PTF_Pereno_crewman";
   typicalCargo[] = {"PTF_Pereno_crewman"};
};

class PTF_Pereno_ural_open: rhsgref_ins_g_ural_open
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Ural (Abierto)";
   crew = "PTF_Pereno_crewman";
   typicalCargo[] = {"PTF_Pereno_crewman"};
};

class PTF_Pereno_gaz66: rhsgref_ins_g_gaz66
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "GAZ-66";
   crew = "PTF_Pereno_crewman";
   typicalCargo[] = {"PTF_Pereno_crewman"};
};

class PTF_Pereno_m1025: rhsgref_hidf_m1025
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "M1025";
   crew = "PTF_Pereno_crewman";
   typicalCargo[] = {"PTF_Pereno_crewman", "PTF_Pereno_rifleman"};
};

class PTF_Pereno_m1025_m2: rhsgref_hidf_m1025_m2
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "M1025 (M2)";
   crew = "PTF_Pereno_crewman";
   typicalCargo[] = {"PTF_Pereno_crewman", "PTF_Pereno_crewman"};
};

// --- The armour ------------------------------------------------------------

class PTF_Pereno_brdm2: rhsgref_BRDM2_ins_g
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_APCs";
   displayName = "BRDM-2";
   crew = "PTF_Pereno_crewman";
   typicalCargo[] = {"PTF_Pereno_crewman", "PTF_Pereno_crewman"};
};

class PTF_Pereno_m113_unarmed: rhsgref_hidf_m113a3_unarmed
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_APCs";
   displayName = "M113A3 (Desarmado)";
   crew = "PTF_Pereno_crewman";
   typicalCargo[] = {"PTF_Pereno_crewman", "PTF_Pereno_crewman"};
};

class PTF_Pereno_m113_m2: rhsgref_hidf_m113a3_m2
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_APCs";
   displayName = "M113A3 (M2)";
   crew = "PTF_Pereno_crewman";
   typicalCargo[] = {"PTF_Pereno_crewman", "PTF_Pereno_crewman"};
};

// --- Emplacements ----------------------------------------------------------
//
// What a garrison actually fights from: a checkpoint gun, a recoilless rifle
// covering the one road in, and the "few mortars" the brief allows them.

class PTF_Pereno_dshkm: rhsgref_ins_g_DSHKM
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Turrets";
   displayName = "DShKM";
   crew = "PTF_Pereno_rifleman";
};

class PTF_Pereno_spg9: rhsgref_ins_g_SPG9
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Turrets";
   displayName = "SPG-9";
   crew = "PTF_Pereno_rifleman";
};

class PTF_Pereno_2b14: rhsgref_ins_g_2b14
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Artillery";
   displayName = "Mortero 2B14 (82mm)";
   crew = "PTF_Pereno_rifleman";
};

// --- Logistics -------------------------------------------------------------
// A garrison lives on its trucks. Three different Soviet-era makes because
// the depot bought whatever was cheap that year.

class PTF_Pereno_zil131: rhsgref_ins_zil131
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "ZiL-131 (Transporte)";
   crew = "PTF_Pereno_crewman";
   typicalCargo[] = {"PTF_Pereno_crewman"};
};

class PTF_Pereno_gaz66_ammo: rhsgref_ins_gaz66_ammo
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "GAZ-66 (Municiones)";
   crew = "PTF_Pereno_crewman";
   typicalCargo[] = {"PTF_Pereno_crewman"};
};

class PTF_Pereno_kraz_fuel: rhsgref_ins_kraz255b1_fuel
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "KrAZ-255 (Combustible)";
   crew = "PTF_Pereno_crewman";
   typicalCargo[] = {"PTF_Pereno_crewman"};
};

// --- Air defence -----------------------------------------------------------
// Guns only, deliberately: the garrison has no missiles. Kestrel owns the
// island's missile air defence, and that distinction is campaign structure.

class PTF_Pereno_zu23: rhsgref_ins_ZU23
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_AAs";
   displayName = "ZU-23-2";
   crew = "PTF_Pereno_rifleman";
};

class PTF_Pereno_ural_zu23: rhsgref_ins_ural_Zu23
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Ural (ZU-23)";
   crew = "PTF_Pereno_crewman";
   typicalCargo[] = {"PTF_Pereno_crewman", "PTF_Pereno_crewman"};
};

class PTF_Pereno_gaz66_zu23: rhsgref_ins_gaz66_zu23
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "GAZ-66 (ZU-23)";
   crew = "PTF_Pereno_crewman";
   typicalCargo[] = {"PTF_Pereno_crewman", "PTF_Pereno_crewman"};
};

// --- Boats -----------------------------------------------------------------
// RHS boats only exist on the BLUFOR HIDF faction, so these are HIDF hulls
// with side/faction/crew overridden.

class PTF_Pereno_boat: rhsgref_hidf_assault_boat
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Boats";
   displayName = "Lancha de Asalto";
   crew = "PTF_Pereno_crewman";
   typicalCargo[] = {"PTF_Pereno_crewman", "PTF_Pereno_rifleman"};
};

// The Poseidon II. Every fishing village on Valmera has a dozen; so does the
// battalion.
class PTF_Pereno_canoe: rhsgref_hidf_canoe
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Boats";
   displayName = "Canoa";
   crew = "PTF_Pereno_rifleman";
};

// --- Helicopters -----------------------------------------------------------
// One Soviet workhorse and two ex-US-aid Hueys: the air wing of a battalion
// that has never been given two aircraft from the same decade.

class PTF_Pereno_mi8: rhsgref_ins_Mi8amt
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Helicopters";
   displayName = "Mi-8AMT (Transporte)";
   crew = "PTF_Pereno_pilot";
   typicalCargo[] = {"PTF_Pereno_pilot"};
};

class PTF_Pereno_uh1h: rhs_uh1h_hidf_unarmed
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Helicopters";
   displayName = "UH-1H (Desarmado)";
   crew = "PTF_Pereno_pilot";
   typicalCargo[] = {"PTF_Pereno_pilot"};
};

class PTF_Pereno_uh1h_gunship: rhs_uh1h_hidf_gunship
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Perenos";
   editorSubcategory = "EdSubcat_Helicopters";
   displayName = "UH-1H (Artillado)";
   crew = "PTF_Pereno_pilot";
   typicalCargo[] = {"PTF_Pereno_pilot", "PTF_Pereno_crewman", "PTF_Pereno_crewman"};
};
