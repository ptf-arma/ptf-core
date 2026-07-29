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
   // Marked sheet: faded VII on the door panel (built from star-free 002).
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_OPFOR\data\pereno_uaz_co.paa"};

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "\z\PTF\addons\PTF_OPFOR\data\pereno_uaz_co.paa"
            };
      };
   };
   textureList[] = {"ptf", 1};
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
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\pereno_uaz_co.paa",
         "rhsafrf\addons\rhs_a2port_car\UAZ\Data\uaz_mount_co.paa",
         "rhsafrf\addons\RHS_Decals\Data\Labels\Misc\no_ca.paa"
      };

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "\z\PTF\addons\PTF_OPFOR\data\pereno_uaz_co.paa",
            "rhsafrf\addons\rhs_a2port_car\UAZ\Data\uaz_mount_co.paa",
            "rhsafrf\addons\RHS_Decals\Data\Labels\Misc\no_ca.paa"
            };
      };
   };
   textureList[] = {"ptf", 1};
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
   // Faded BI-7 stencil on the cab door.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\pereno_ural_kabina_co.paa",
         "rhsafrf\addons\rhs_a2port_car\ural\data\ural_plachta_chdkz_co.paa",
         "rhsafrf\addons\RHS_Decals\Data\Labels\Misc\no_ca.paa"
      };

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "\z\PTF\addons\PTF_OPFOR\data\pereno_ural_kabina_co.paa",
            "rhsafrf\addons\rhs_a2port_car\ural\data\ural_plachta_chdkz_co.paa",
            "rhsafrf\addons\RHS_Decals\Data\Labels\Misc\no_ca.paa"
            };
      };
   };
   textureList[] = {"ptf", 1};
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
   // 6-entry order inherited from rhs_truck: cab, tent, kung, ap2kung,
   // repkung, decal-blank.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\pereno_gaz66_cab_co.paa",
         "\rhsafrf\addons\rhs_gaz66\data\tent_co.paa",
         "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_kung_co.paa",
         "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_ap2kung_co.paa",
         "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_repkung_co.paa",
         "rhsafrf\addons\RHS_Decals\Data\Labels\Misc\no_ca.paa"
      };

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "\z\PTF\addons\PTF_OPFOR\data\pereno_gaz66_cab_co.paa",
            "\rhsafrf\addons\rhs_gaz66\data\tent_co.paa",
            "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_kung_co.paa",
            "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_ap2kung_co.paa",
            "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_repkung_co.paa",
            "rhsafrf\addons\RHS_Decals\Data\Labels\Misc\no_ca.paa"
            };
      };
   };
   textureList[] = {"ptf", 1};
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
   // 10-entry HIDF array; index 7 is the marked body sheet.
   hiddenSelectionsTextures[] =
      {
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\m998_exterior_lg_co.paa",
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\m998_interior_lg_co.paa",
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\A2_parts_lg_co.paa",
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\wheel_wranglermt_lg_co.paa",
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\m998_mainbody_lg_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\gratting_w_co.paa",
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\tile_exmetal_lg_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\pereno_m1025_co.paa",
         "",
         ""
      };

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\m998_exterior_lg_co.paa",
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\m998_interior_lg_co.paa",
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\A2_parts_lg_co.paa",
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\wheel_wranglermt_lg_co.paa",
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\m998_mainbody_lg_co.paa",
            "rhsusf\addons\rhsusf_hmmwv\textures\gratting_w_co.paa",
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\tile_exmetal_lg_co.paa",
            "\z\PTF\addons\PTF_OPFOR\data\pereno_m1025_co.paa",
            "",
            ""
            };
      };
   };
   textureList[] = {"ptf", 1};
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
   // 11-entry m2 variant: adds the mk64 mount before the trailing empties.
   hiddenSelectionsTextures[] =
      {
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\m998_exterior_lg_co.paa",
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\m998_interior_lg_co.paa",
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\A2_parts_lg_co.paa",
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\wheel_wranglermt_lg_co.paa",
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\m998_mainbody_lg_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\gratting_w_co.paa",
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\tile_exmetal_lg_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\pereno_m1025_co.paa",
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\mk64mount_lg_co.paa",
         "",
         ""
      };

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\m998_exterior_lg_co.paa",
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\m998_interior_lg_co.paa",
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\A2_parts_lg_co.paa",
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\wheel_wranglermt_lg_co.paa",
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\m998_mainbody_lg_co.paa",
            "rhsusf\addons\rhsusf_hmmwv\textures\gratting_w_co.paa",
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\tile_exmetal_lg_co.paa",
            "\z\PTF\addons\PTF_OPFOR\data\pereno_m1025_co.paa",
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\hmmwv\mk64mount_lg_co.paa",
            "",
            ""
            };
      };
   };
   textureList[] = {"ptf", 1};
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
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\pereno_brdm2_01_co.paa",
         "\rhsgref\addons\rhsgref_a2port_armor\brdm2\data\brdm2_02_camo_co.paa",
         "\rhsgref\addons\rhsgref_a2port_armor\brdm2\data\zbik_04_co.paa"
      };

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "\z\PTF\addons\PTF_OPFOR\data\pereno_brdm2_01_co.paa",
            "\rhsgref\addons\rhsgref_a2port_armor\brdm2\data\brdm2_02_camo_co.paa",
            "\rhsgref\addons\rhsgref_a2port_armor\brdm2\data\zbik_04_co.paa"
            };
      };
   };
   textureList[] = {"ptf", 1};
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
   // Faded VII on both flanks (UV runs vertical -- placement proven against
   // the RHS medevac variant's red crosses), BI-7 stencil on the ramp door.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\pereno_m113_01_co.paa",
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\m113a3_02_tv_h_90s_co.paa",
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\m113a3_03_lg_co.paa",
         "rhsusf\addons\rhsusf_m113\data_new\m113a3_int03_wd_co.paa",
         "rhsusf\addons\rhsusf_m113\data_new\m23_pintle_wd_co.paa"
      };

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "\z\PTF\addons\PTF_OPFOR\data\pereno_m113_01_co.paa",
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\m113a3_02_tv_h_90s_co.paa",
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\m113a3_03_lg_co.paa",
            "rhsusf\addons\rhsusf_m113\data_new\m113a3_int03_wd_co.paa",
            "rhsusf\addons\rhsusf_m113\data_new\m23_pintle_wd_co.paa"
            };
      };
   };
   textureList[] = {"ptf", 1};
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
   // Faded VII on both flanks (UV runs vertical -- placement proven against
   // the RHS medevac variant's red crosses), BI-7 stencil on the ramp door.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\pereno_m113_01_co.paa",
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\m113a3_02_tv_h_90s_co.paa",
         "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\m113a3_03_lg_co.paa",
         "rhsusf\addons\rhsusf_m113\data_new\m113a3_int03_wd_co.paa",
         "rhsusf\addons\rhsusf_m113\data_new\m23_pintle_wd_co.paa"
      };

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "\z\PTF\addons\PTF_OPFOR\data\pereno_m113_01_co.paa",
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\m113a3_02_tv_h_90s_co.paa",
            "rhsgref\addons\rhsgref_vehicles_ret\data\hidf\m113a3_03_lg_co.paa",
            "rhsusf\addons\rhsusf_m113\data_new\m113a3_int03_wd_co.paa",
            "rhsusf\addons\rhsusf_m113\data_new\m23_pintle_wd_co.paa"
            };
      };
   };
   textureList[] = {"ptf", 1};
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
   // 5-entry order per the chdkz ZiL classes: cargo, cabin, interior, wheels, base.
   hiddenSelectionsTextures[] =
      {
         "\rhsgref\addons\rhsgref_vehicles_ret\data\chdkz\rhs_zil131_cargo_CHDKZ_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\pereno_zil_cabin_co.paa",
         "\rhsafrf\addons\rhs_zil131\data\rhs_zil131_interior_co.paa",
         "\rhsafrf\addons\rhs_zil131\data\rhs_zil131_wheels_co.paa",
         "\rhsafrf\addons\rhs_zil131\data\rhs_zil131_base_co.paa"
      };

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "\rhsgref\addons\rhsgref_vehicles_ret\data\chdkz\rhs_zil131_cargo_CHDKZ_co.paa",
            "\z\PTF\addons\PTF_OPFOR\data\pereno_zil_cabin_co.paa",
            "\rhsafrf\addons\rhs_zil131\data\rhs_zil131_interior_co.paa",
            "\rhsafrf\addons\rhs_zil131\data\rhs_zil131_wheels_co.paa",
            "\rhsafrf\addons\rhs_zil131\data\rhs_zil131_base_co.paa"
            };
      };
   };
   textureList[] = {"ptf", 1};
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
   // 6-entry order inherited from rhs_truck: cab, tent, kung, ap2kung,
   // repkung, decal-blank.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\pereno_gaz66_cab_co.paa",
         "\rhsafrf\addons\rhs_gaz66\data\tent_co.paa",
         "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_kung_co.paa",
         "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_ap2kung_co.paa",
         "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_repkung_co.paa",
         "rhsafrf\addons\RHS_Decals\Data\Labels\Misc\no_ca.paa"
      };

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "\z\PTF\addons\PTF_OPFOR\data\pereno_gaz66_cab_co.paa",
            "\rhsafrf\addons\rhs_gaz66\data\tent_co.paa",
            "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_kung_co.paa",
            "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_ap2kung_co.paa",
            "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_repkung_co.paa",
            "rhsafrf\addons\RHS_Decals\Data\Labels\Misc\no_ca.paa"
            };
      };
   };
   textureList[] = {"ptf", 1};
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
   // 3-entry order per the chdkz KrAZ fuel class: cab, wheels, tank.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\pereno_kraz_co.paa",
         "rhsafrf\addons\rhs_kraz255\data\kol255_co.paa",
         "rhsgref\addons\rhsgref_vehicles_ret\data\chdkz\tz8_chdkz_co.paa"
      };

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "\z\PTF\addons\PTF_OPFOR\data\pereno_kraz_co.paa",
            "rhsafrf\addons\rhs_kraz255\data\kol255_co.paa",
            "rhsgref\addons\rhsgref_vehicles_ret\data\chdkz\tz8_chdkz_co.paa"
            };
      };
   };
   textureList[] = {"ptf", 1};
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

   // Branded cab; bed stays the stock chdkz open-bed sheet (2-entry, per
   // rhsgref_ins_ural_Zu23's own array).
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\pereno_ural_kabina_co.paa",
         "rhsafrf\addons\rhs_a2port_car\ural\data\ural_open_chdkz_co.paa"
      };

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "\z\PTF\addons\PTF_OPFOR\data\pereno_ural_kabina_co.paa",
            "rhsafrf\addons\rhs_a2port_car\ural\data\ural_open_chdkz_co.paa"
            };
      };
   };
   textureList[] = {"ptf", 1};
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

   // Branded cab; rest per rhsgref_ins_gaz66_zu23's 5-entry array.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\pereno_gaz66_cab_co.paa",
         "\rhsafrf\addons\rhs_gaz66\data\tent_chdk_co.paa",
         "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_kung_co.paa",
         "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_ap2kung_co.paa",
         "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_repkung_co.paa"
      };

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "\z\PTF\addons\PTF_OPFOR\data\pereno_gaz66_cab_co.paa",
            "\rhsafrf\addons\rhs_gaz66\data\tent_chdk_co.paa",
            "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_kung_co.paa",
            "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_ap2kung_co.paa",
            "\rhsafrf\addons\rhs_gaz66\data\rhs_gaz66_repkung_co.paa"
            };
      };
   };
   textureList[] = {"ptf", 1};
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
   // Roundel painted directly over the old ChDKZ star position (RHS puts
   // national insignia at the same UV spot across factions), faded VII under
   // each boom-side rotor warning. Index 1 (detail sheet) stays stock.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\pereno_mi8_body_co.paa",
         "rhsafrf\addons\rhs_a2port_air\mi17\data\mi8_det_g_cdf_co.paa"
      };

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "\z\PTF\addons\PTF_OPFOR\data\pereno_mi8_body_co.paa",
            "rhsafrf\addons\rhs_a2port_air\mi17\data\mi8_det_g_cdf_co.paa"
            };
      };
   };
   textureList[] = {"ptf", 1};
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
   // Only the dedicated DECAL layer changes -- hull, interior and LOD sheets
   // stay stock HIDF grey, so there is no distance-pop. The decal sheet swaps
   // "HORIZON ISLANDS AIR FORCE" boom text for the Valmeran roundel + VII.
   hiddenSelectionsTextures[] =
      {
         "rhsgref\addons\rhsgref_air\uh1h\data\uh1h_hidf_grey_co.paa",
         "rhsgref\addons\rhsgref_air\uh1h\data\uh1h_hidf_grey_in_co.paa",
         "rhsgref\addons\rhsgref_air\uh1h\data\mlod_hidf_grey_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\pereno_uh1h_decals_ca.paa"
      };

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "rhsgref\addons\rhsgref_air\uh1h\data\uh1h_hidf_grey_co.paa",
            "rhsgref\addons\rhsgref_air\uh1h\data\uh1h_hidf_grey_in_co.paa",
            "rhsgref\addons\rhsgref_air\uh1h\data\mlod_hidf_grey_co.paa",
            "\z\PTF\addons\PTF_OPFOR\data\pereno_uh1h_decals_ca.paa"
            };
      };
   };
   textureList[] = {"ptf", 1};
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
   // Only the dedicated DECAL layer changes -- hull, interior and LOD sheets
   // stay stock HIDF grey, so there is no distance-pop. The decal sheet swaps
   // "HORIZON ISLANDS AIR FORCE" boom text for the Valmeran roundel + VII.
   hiddenSelectionsTextures[] =
      {
         "rhsgref\addons\rhsgref_air\uh1h\data\uh1h_hidf_grey_co.paa",
         "rhsgref\addons\rhsgref_air\uh1h\data\uh1h_hidf_grey_in_co.paa",
         "rhsgref\addons\rhsgref_air\uh1h\data\mlod_hidf_grey_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\pereno_uh1h_decals_ca.paa"
      };

   // Own the randomization path instead of fighting it: RHS/Eden appearance
   // randomization (textureSources + textureList) re-skins vehicles at spawn
   // and was wiping these overrides. With a single PTF source and a
   // single-entry textureList, any randomization that runs can only ever
   // re-apply OUR textures.
   class TextureSources
   {
      class ptf
      {
         displayName = "Los Perenos";
         author = "Paramarine Task Force";
         factions[] = {"PTF_OPFOR_Perenos"};
         textures[] =
            {
            "rhsgref\addons\rhsgref_air\uh1h\data\uh1h_hidf_grey_co.paa",
            "rhsgref\addons\rhsgref_air\uh1h\data\uh1h_hidf_grey_in_co.paa",
            "rhsgref\addons\rhsgref_air\uh1h\data\mlod_hidf_grey_co.paa",
            "\z\PTF\addons\PTF_OPFOR\data\pereno_uh1h_decals_ca.paa"
            };
      };
   };
   textureList[] = {"ptf", 1};
};
