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
