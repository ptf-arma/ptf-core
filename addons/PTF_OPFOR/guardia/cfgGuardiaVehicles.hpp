// ---------------------------------------------------------------------------
// La Guardia motor pool.
//
// "Technicals and a handful of genuinely dangerous armoured vehicles."
//
// The distinction from the garrison is qualitative, not cosmetic. Where los
// Perenos field a DShKM jeep and an M113 that may or may not run, La Guardia
// field an AGS-30 grenade launcher on a jeep and a BMP-2 -- a 30mm autocannon
// with an ATGM on the rail. The BMP-2 is the vehicle that should make players
// stop treating a Guardia contact as a firefight they can simply win.
//
// As with los Perenos these are rebadged RHS hulls, not retextures. Liveries
// are a later texture pass.
// ---------------------------------------------------------------------------

// The UAZ and the Ural are the only hulls La Guardia share with los Perenos,
// and stock they are the identical green -- at 300m a Guardia technical and a
// garrison technical were the same vehicle. RHS's own "ins" and "ins_g"
// variants do NOT help here: they differ only by faction and crew, not by a
// single texture.
//
// So these carry a darker, desaturated repaint of RHS's own texture -- the
// original composited through a tone matrix, so every panel line and
// weathering pass survives. Reads as a regime security force rather than an
// army, which is what La Guardia are. los Perenos keep stock RHS green.
// See LIVERIES.md.

class PTF_Guardia_uaz_ags: rhsgref_ins_g_uaz_ags
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Guardia";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "UAZ (AGS-30)";
   crew = "PTF_Guardia_crewman";
   typicalCargo[] = {"PTF_Guardia_crewman", "PTF_Guardia_crewman"};
   // Single-entry override, exactly as RHS does it -- camo1 is the body; the
   // n*/i* selections are driven by RHS's decal system, not by textures here.
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_OPFOR\data\guardia_uaz_co.paa"};
};

class PTF_Guardia_uaz_spg9: rhsgref_ins_g_uaz_spg9
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Guardia";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "UAZ (SPG-9)";
   crew = "PTF_Guardia_crewman";
   typicalCargo[] = {"PTF_Guardia_crewman", "PTF_Guardia_crewman"};
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_OPFOR\data\guardia_uaz_co.paa"};
};

class PTF_Guardia_ural: rhsgref_ins_g_ural
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Guardia";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Ural (Transporte)";
   crew = "PTF_Guardia_crewman";
   typicalCargo[] = {"PTF_Guardia_crewman"};
   // camo1 = cab, camo2 = tarp, third entry is RHS's blank decal label.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\guardia_ural_kabina_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_ural_plachta_co.paa",
         "rhsafrf\addons\RHS_Decals\Data\Labels\Misc\no_ca.paa"
      };
};

// Guardia dark repaint, and a marking fix in one: the stock insurgent BTR-70
// wears ChDKZ red stripes (the old faction, same disease as the UAZ star), so
// this repaint is built from RHS's CLEAN base textures instead. Texture order
// mirrors rhsgref_ins_btr70's own 5-entry override: camo1, camo2, blank,
// stowage x2. The i*/n* decal slots beyond index 4 are runtime-painted.
class PTF_Guardia_btr70: rhsgref_ins_g_btr70
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Guardia";
   editorSubcategory = "EdSubcat_APCs";
   displayName = "BTR-70";
   crew = "PTF_Guardia_crewman";
   typicalCargo[] = {"PTF_Guardia_crewman", "PTF_Guardia_crewman"};
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\guardia_btr70_1_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_btr70_2_co.paa",
         "",
         "rhsafrf\addons\rhs_btr70\habar\data\sa_gear_02_co.paa",
         "rhsafrf\addons\rhs_btr70\habar\data\sa_gear_02_co.paa"
      };
};

class PTF_Guardia_bmp2: rhsgref_ins_g_bmp2
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Guardia";
   editorSubcategory = "EdSubcat_APCs";
   displayName = "BMP-2";
   crew = "PTF_Guardia_crewman";
   typicalCargo[] = {"PTF_Guardia_crewman", "PTF_Guardia_crewman", "PTF_Guardia_crewman"};

   // Hull stencil only -- the camouflage is NOT repainted. A "LA GUARDIA"
   // marking with the faction's crimson bar is composited onto both flanks of
   // RHS's own hull texture, so the vehicle keeps its exact paint.
   //
   // Only index 2 changes; the other five entries point straight back at RHS,
   // so this costs one 1.6 MB texture rather than the whole six-texture set.
   // The BMP-2 is Guardia-exclusive, so this is branding rather than
   // disambiguation -- worth it because this is the vehicle whose arrival is
   // supposed to change how a fight feels.
   //
   // Note RHS also exposes rhs_decalParameters on this hull (cBMP3NumberPlaces
   // / cBMPLeftBack), so per-vehicle tactical numbers can be set from Eden
   // without touching textures at all.
   hiddenSelectionsTextures[] =
      {
         "rhsafrf\addons\rhs_bmp\textures\bmp_1_chdkz_co.paa",
         "rhsafrf\addons\rhs_bmp\textures\bmp_2_chdkz_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_bmp2_hull_co.paa",
         "rhsafrf\addons\rhs_bmp\textures\bmp_4_chdkz_co.paa",
         "rhsafrf\addons\rhs_bmp\textures\bmp_5_chdkz_co.paa",
         "rhsafrf\addons\rhs_bmp\textures\bmp_6_chdkz_co.paa"
      };
};

// --- Emplacements ----------------------------------------------------------
// Presa Alta and Tagua Air Base are the only two places La Guardia garrison,
// and both are fixed sites. These are what those sites are held with.

class PTF_Guardia_ags30: rhsgref_ins_g_AGS30_TriPod
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Guardia";
   editorSubcategory = "EdSubcat_Turrets";
   displayName = "AGS-30";
   crew = "PTF_Guardia_rifleman";
};

class PTF_Guardia_nsv: rhsgref_ins_g_NSV_TriPod
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Guardia";
   editorSubcategory = "EdSubcat_Turrets";
   displayName = "NSV";
   crew = "PTF_Guardia_rifleman";
};

// --- Logistics -------------------------------------------------------------
// KamAZ-5350s, bought new. The garrison drives thirty-year-old ZiLs; the
// difference is the point.

class PTF_Guardia_kamaz: rhs_kamaz5350_msv
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Guardia";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "KamAZ-5350 (Transporte)";
   crew = "PTF_Guardia_crewman";
   typicalCargo[] = {"PTF_Guardia_crewman"};
   // Same 5-entry order as rhs_kamaz5350: cabin, cargo, base, bed, cover.
   // Selections beyond index 4 are RHS's runtime decal slots.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\guardia_kamaz_cabin_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_kamaz_cargo_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_kamaz_base_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_kamaz_bed_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_kamaz_cover_co.paa"
      };
};

class PTF_Guardia_kamaz_ammo: rhs_kamaz5350_ammo_msv
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Guardia";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "KamAZ-5350 (Municiones)";
   crew = "PTF_Guardia_crewman";
   typicalCargo[] = {"PTF_Guardia_crewman"};
   // Same 5-entry order as rhs_kamaz5350: cabin, cargo, base, bed, cover.
   // Selections beyond index 4 are RHS's runtime decal slots.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\guardia_kamaz_cabin_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_kamaz_cargo_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_kamaz_base_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_kamaz_bed_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_kamaz_cover_co.paa"
      };
};

class PTF_Guardia_kamaz_open: rhs_kamaz5350_open_msv
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Guardia";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "KamAZ-5350 (Abierto)";
   crew = "PTF_Guardia_crewman";
   typicalCargo[] = {"PTF_Guardia_crewman"};
   // Same 5-entry order as rhs_kamaz5350: cabin, cargo, base, bed, cover.
   // Selections beyond index 4 are RHS's runtime decal slots.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\guardia_kamaz_cabin_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_kamaz_cargo_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_kamaz_base_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_kamaz_bed_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_kamaz_cover_co.paa"
      };
};

// --- Air defence -----------------------------------------------------------

class PTF_Guardia_ural_zu23: RHS_Ural_Zu23_MSV_01
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Guardia";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Ural (ZU-23)";
   crew = "PTF_Guardia_crewman";
   typicalCargo[] = {"PTF_Guardia_crewman", "PTF_Guardia_crewman"};
};

// The campaign's only self-propelled AA. Radar-laid, mobile, and murderous
// against anything low and slow -- its appearance should mean something.
class PTF_Guardia_zsu234: rhsgref_ins_zsu234
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Guardia";
   editorSubcategory = "EdSubcat_APCs";
   displayName = "ZSU-23-4 (Shilka)";
   crew = "PTF_Guardia_crewman";
   typicalCargo[] = {"PTF_Guardia_crewman", "PTF_Guardia_crewman"};
   // 4-entry order mirrors rhsgref_ins_zsu234: three hull sheets + blank decal.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\guardia_zsu_1_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_zsu_2_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_zsu_3_co.paa",
         "rhsafrf\addons\rhs_decals\Data\Labels\Misc\no_ca.paa"
      };
};

// --- Boats -----------------------------------------------------------------
// Presa Alta is a dam. Somebody has to patrol the reservoir.

class PTF_Guardia_rhib: rhsgref_hidf_rhib
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Guardia";
   editorSubcategory = "EdSubcat_Boats";
   displayName = "RHIB";
   crew = "PTF_Guardia_crewman";
   typicalCargo[] = {"PTF_Guardia_crewman", "PTF_Guardia_rifleman"};
};

// --- Helicopters -----------------------------------------------------------

class PTF_Guardia_mi17: rhsgref_cdf_reg_Mi17Sh
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Guardia";
   editorSubcategory = "EdSubcat_Helicopters";
   displayName = "Mi-17Sh (Transporte)";
   crew = "PTF_Guardia_pilot";
   typicalCargo[] = {"PTF_Guardia_pilot"};
   // 2-entry order mirrors rhsgref_cdf_reg_Mi17Sh: body camo + detail sheet.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\guardia_mi17_body_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_mi17_det_co.paa"
      };
};

// The escalation ceiling. Field it once, late, and make it the mission.
class PTF_Guardia_mi35: rhsgref_cdf_Mi35
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Guardia";
   editorSubcategory = "EdSubcat_Helicopters";
   displayName = "Mi-35";
   crew = "PTF_Guardia_pilot";
   typicalCargo[] = {"PTF_Guardia_pilot"};
   // 3-entry order mirrors rhsgref_cdf_Mi35: two hull sheets + detail sheet.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\guardia_mi35_1_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_mi35_2_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\guardia_mi35_det_co.paa"
      };
};
