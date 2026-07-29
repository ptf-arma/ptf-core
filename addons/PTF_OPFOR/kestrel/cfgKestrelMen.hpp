// ---------------------------------------------------------------------------
// Kestrel Group
//
// Design intent (campaign layer 3): ~50 foreign contractors on Marenco's
// payroll. Ex-special-forces from four or five countries, individually
// excellent, collectively uninterested in dying for a mining concession.
// They hold the airport and the research compound, and they own the island's
// air defence. Defeated by economics, not by attrition.
//
// The third silhouette. Where los Perenos are numerous and poor and La
// Guardia are well-funded and disciplined, Kestrel are FEW and EXPENSIVE:
//   * Highest accuracy and sensitivity in the campaign -- individually, these
//     are the best soldiers on the island.
//   * The smallest groups in the campaign, by design (see cfgKestrelGroups).
//     Kestrel do not mass. Four men who are each better than anything the
//     players have met, and no ninth man behind them.
//   * `cost` is set very high. Beyond AI targeting priority it is a note to
//     the mission maker: every one of these is a line item on a contract, and
//     the campaign's win condition is making that contract unprofitable.
//   * Four national camouflage patterns across the roster -- DPM, French
//     lizard, US woodland, 3-colour desert -- because nobody issued these men
//     anything. They each kept the kit they left their old army in.
//
// Note on "defeated by economics": withdrawal is campaign scripting and
// cannot live in a unit config. What config does is make Kestrel expensive to
// grind down and obviously finite, so that attrition reads as the wrong tool.
// ---------------------------------------------------------------------------

class PTF_Kestrel_base: rhsgref_nat_base
{
   // rhsgref_nat_base names an editor-preview image that does not exist in
   // RHS's editorpreviews PBO ("Cannot load texture ... rhsgref_nat_base.paa"
   // in-game). Blank it; children inherit the blank.
   editorPreview = "";
   scope = 0;
   scopeCurator = 0;
   author = "Paramarine Task Force";
   side = 0;                              // EAST
   faction = "PTF_OPFOR_Kestrel";
   vehicleClass = "Men";
   editorSubcategory = "EdSubcat_Personnel";
   // Ex-special-forces from four or five countries: NATO, African and
   // European faces, English and British-English voices.
   identityTypes[] = {"LanguageENG_F", "LanguageENGB_F", "Head_NATO", "Head_African", "Head_Euro"};
   modelSides[] = {0, 1, 2, 3};

   // Best individual soldiers in the campaign. Compare PTF_Pereno_base at
   // 1.0 / 1.2 and PTF_Guardia_base at 2.6 / 3.2.
   accuracy = 3.6;
   sensitivity = 4.2;
   camouflage = 1.0;
   cost = 800000;

   class EventHandlers;

   uniformClass = "PTF_U_kestrel_wdl";
   hiddenSelections[] = {"Camo"};
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_us_woodland_co.paa"};

   Items[] = {"FirstAidKit"};
   RespawnItems[] = {"FirstAidKit"};

   // Every role below overrides this with its own carrier. Kestrel are
   // individually equipped rather than issued as a unit, so a fireteam should
   // show four different rigs, not four copies of one.
   linkedItems[] = {"rhsusf_opscore_01", "rhsusf_plateframe_rifleman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01", "rhsusf_plateframe_rifleman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};

   weapons[] = {"rhs_weap_mk18_eotech_sup", "rhsusf_weap_glock17g4", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_mk18_eotech_sup", "rhsusf_weap_glock17g4", "Throw", "Put"};
   magazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green"
      };
   respawnMagazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green"
      };
};

// --- Operators -------------------------------------------------------------
//
// Four men, four old armies. Mechanically identical -- the variation is
// entirely visual, and it is the point: a Kestrel fireteam should not look
// like a unit, it should look like a contract.

class PTF_Kestrel_operator: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Operator (Woodland)";
};

class PTF_Kestrel_operator_dpm: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Operator (DPM)";
   uniformClass = "PTF_U_kestrel_dpm";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_dpm_co.paa"};
   linkedItems[] = {"rhsusf_bowman_cap", "rhsusf_spc_patchless", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_bowman_cap", "rhsusf_spc_patchless", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};

class PTF_Kestrel_operator_lizard: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Operator (Lizard)";
   uniformClass = "PTF_U_kestrel_lizard";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_altis_lizard_co.paa"};
   linkedItems[] = {"rhsgref_Booniehat_alpen", "rhsusf_plateframe_light", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_Booniehat_alpen", "rhsusf_plateframe_light", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};

class PTF_Kestrel_operator_desert: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Operator (3-Color Desert)";
   uniformClass = "PTF_U_kestrel_desert";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_3color_desert_co.paa"};
   linkedItems[] = {"rhsusf_patrolcap_ocp", "rhsusf_spc_rifleman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_patrolcap_ocp", "rhsusf_spc_rifleman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};

// --- Specialists -----------------------------------------------------------

class PTF_Kestrel_machinegunner: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Machinegunner";
   cost = 900000;
   linkedItems[] = {"rhsusf_opscore_01", "rhsusf_plateframe_machinegunner", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01", "rhsusf_plateframe_machinegunner", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   uniformClass = "PTF_U_kestrel_dpm";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_dpm_co.paa"};
   weapons[] = {"rhs_weap_m249_light_L_elcan", "rhsusf_weap_glock17g4", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_m249_light_L_elcan", "rhsusf_weap_glock17g4", "Throw", "Put"};
   magazines[] =
      {
         "rhsusf_100Rnd_556x45_soft_pouch",
         "rhsusf_100Rnd_556x45_soft_pouch",
         "rhsusf_100Rnd_556x45_soft_pouch",
         "rhsusf_100Rnd_556x45_soft_pouch",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67"
      };
   respawnMagazines[] =
      {
         "rhsusf_100Rnd_556x45_soft_pouch",
         "rhsusf_100Rnd_556x45_soft_pouch",
         "rhsusf_100Rnd_556x45_soft_pouch",
         "rhsusf_100Rnd_556x45_soft_pouch",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67"
      };
};

class PTF_Kestrel_marksman: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Marksman";
   cost = 950000;
   accuracy = 4.0;
   linkedItems[] = {"rhsusf_opscore_01_tan", "rhsusf_plateframe_marksman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01_tan", "rhsusf_plateframe_marksman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_mk18_SU230", "rhsusf_weap_glock17g4", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_mk18_SU230", "rhsusf_weap_glock17g4", "Throw", "Put"};
};

class PTF_Kestrel_sniper: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Sniper (XM2010)";
   cost = 1100000;
   accuracy = 4.2;
   sensitivity = 4.5;
   camouflage = 0.6;
   uniformClass = "PTF_U_kestrel_lizard";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_altis_lizard_co.paa"};
   linkedItems[] = {"rhsgref_Booniehat_alpen", "rhsusf_spc_sniper", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "rhsusf_acc_M2010S", "rhsusf_acc_harris_bipod"};
   respawnLinkedItems[] = {"rhsgref_Booniehat_alpen", "rhsusf_spc_sniper", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "rhsusf_acc_M2010S", "rhsusf_acc_harris_bipod"};
   weapons[] = {"rhs_weap_XM2010_wd_leu", "rhsusf_weap_glock17g4", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_XM2010_wd_leu", "rhsusf_weap_glock17g4", "Throw", "Put", "Binocular"};
   magazines[] =
      {
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhsusf_mag_17Rnd_9x19_JHP"
      };
   respawnMagazines[] =
      {
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhsusf_mag_17Rnd_9x19_JHP"
      };
};

// M107 with Mk211 multipurpose. This is the man who makes an airframe
// unflyable without anyone taking off, and he cuts both ways -- if the
// players can take him, they can use the same logic on Kestrel's shipments.
class PTF_Kestrel_antimateriel: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Anti-Materiel (M107)";
   cost = 1200000;
   accuracy = 4.0;
   linkedItems[] = {"rhsgref_Booniehat_alpen", "rhsusf_plateframe_marksman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "rhsusf_acc_LEUPOLDMK4"};
   respawnLinkedItems[] = {"rhsgref_Booniehat_alpen", "rhsusf_plateframe_marksman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "rhsusf_acc_LEUPOLDMK4"};
   weapons[] = {"rhs_weap_M107_w_leu", "rhsusf_weap_glock17g4", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_M107_w_leu", "rhsusf_weap_glock17g4", "Throw", "Put", "Binocular"};
   // A 10-round .50 BMG box is 41.14 mass, so not one of them will go in the
   // uniform's 40 -- the plateframe's 160 is his entire magazine capacity and
   // it holds exactly three. The five declared here before meant two were
   // dropped at spawn.
   magazines[] =
      {
         "rhsusf_mag_10Rnd_STD_50BMG_mk211",
         "rhsusf_mag_10Rnd_STD_50BMG_mk211",
         "rhsusf_mag_10Rnd_STD_50BMG_M33",
         "rhsusf_mag_17Rnd_9x19_JHP"
      };
   respawnMagazines[] =
      {
         "rhsusf_mag_10Rnd_STD_50BMG_mk211",
         "rhsusf_mag_10Rnd_STD_50BMG_mk211",
         "rhsusf_mag_10Rnd_STD_50BMG_M33",
         "rhsusf_mag_17Rnd_9x19_JHP"
      };
};

// --- Air defence -----------------------------------------------------------
//
// The reason Kestrel matter. "They own the island's air defence: MANPADS, a
// radar, and the professionalism to use both."
//
// Two flavours on purpose. The Stinger is Kestrel's own procurement -- what
// the contract bought. The Igla is the island's, inherited with the site and
// now operated by people who actually know how. Fielding both tells the
// players that Kestrel did not just arrive, they took something over.

// THE MISSILES ARE NOT IN magazines[], AND MUST NOT BE PUT BACK.
//
// A FIM-92 round is 120 mass. When the engine distributes a soldier's
// magazines[] it fills the UNIFORM and VEST only -- never the backpack --
// so a 120-mass round has to fit inside a 160-capacity carrier that is
// already holding the rifle magazines and the first aid kit. It does not,
// and the engine drops what will not fit silently: this class was spawning
// with a launcher and no rounds at all, which defeats the entire point of
// Kestrel's air defence. (Adding a backpack alone does NOT fix this. See
// PTF_Pereno_engineer, which has had one the whole time and still
// overflowed.)
//
// So the rounds go on in an init handler instead, straight into a 320
// capacity carryall. Two rounds is 240 of it. The handler also seats a round
// in the launcher itself, so he does not have to survive an AI reload cycle
// before he can engage anything. It is guarded on locality, so it runs once,
// on the machine that owns the unit.
class PTF_Kestrel_aa_stinger: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel AA Specialist (FIM-92)";
   cost = 1400000;
   icon = "iconManAT";
   linkedItems[] = {"rhsusf_opscore_01", "rhsusf_spc_iar", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01", "rhsusf_spc_iar", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   backpack = "B_Carryall_cbr";
   weapons[] = {"rhs_weap_mk18_eotech_sup", "rhs_weap_fim92", "rhsusf_weap_glock17g4", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_mk18_eotech_sup", "rhs_weap_fim92", "rhsusf_weap_glock17g4", "Throw", "Put"};
   class EventHandlers: EventHandlers
   {
      class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
      {
         init = "if (local (_this select 0)) then {private _u = _this select 0; _u addItemToBackpack 'rhs_fim92_mag'; _u addItemToBackpack 'rhs_fim92_mag'; _u addWeaponItem ['rhs_weap_fim92', 'rhs_fim92_mag'];};";
      };
   };
   magazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67"
      };
   respawnMagazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67"
      };
};

// Same treatment as the Stinger above, and for the same reason: a 9K38
// round is 100 mass and his SPC Light carrier holds 100 in total. Two rounds
// in a 320-capacity carryall, added by a locality-guarded init handler.
class PTF_Kestrel_aa_igla: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel AA Specialist (Igla)";
   cost = 1300000;
   icon = "iconManAT";
   linkedItems[] = {"rhsusf_patrolcap_ocp", "rhsusf_spc_light", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_patrolcap_ocp", "rhsusf_spc_light", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   uniformClass = "PTF_U_kestrel_desert";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_3color_desert_co.paa"};
   backpack = "B_Carryall_cbr";
   weapons[] = {"rhs_weap_mk18_eotech_sup", "rhs_weap_igla", "rhsusf_weap_glock17g4", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_mk18_eotech_sup", "rhs_weap_igla", "rhsusf_weap_glock17g4", "Throw", "Put"};
   class EventHandlers: EventHandlers
   {
      class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base
      {
         init = "if (local (_this select 0)) then {private _u = _this select 0; _u addItemToBackpack 'rhs_mag_9k38_rocket'; _u addItemToBackpack 'rhs_mag_9k38_rocket'; _u addWeaponItem ['rhs_weap_igla', 'rhs_mag_9k38_rocket'];};";
      };
   };
   magazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67"
      };
   respawnMagazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67"
      };
};

// --- Support ---------------------------------------------------------------

class PTF_Kestrel_medic: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Medic";
   cost = 900000;
   attendant = 1;
   icon = "iconManMedic";
   linkedItems[] = {"rhsusf_opscore_01", "rhsusf_plateframe_medic", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01", "rhsusf_plateframe_medic", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   Items[] = {"FirstAidKit", "Medikit"};
   RespawnItems[] = {"FirstAidKit", "Medikit"};
   // Five rifle magazines rather than the operator's seven: the Medikit is
   // 80 mass, and Items[] are packed into the uniform and carrier before
   // magazines[] are.
   magazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green"
      };
   respawnMagazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green"
      };
};

class PTF_Kestrel_breacher: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Breacher";
   cost = 950000;
   linkedItems[] = {"rhsusf_bowman_cap", "rhsusf_spc_patchless_radio", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_bowman_cap", "rhsusf_spc_patchless_radio", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   engineer = 1;
   canDeactivateMines = 1;
   icon = "iconManEngineer";
   uniformClass = "PTF_U_kestrel_dpm";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_dpm_co.paa"};
   Items[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   RespawnItems[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   // Toolkit (80), mine detector (20) and first aid kit (8) are 108 of the
   // 180 his uniform and radio carrier hold between them, and the engine
   // packs Items[] first. Four rifle magazines is what is left of seven --
   // he was losing both pistol magazines, the grenade and the smoke.
   magazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67"
      };
   respawnMagazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67"
      };
};

// The SPC Crewman carrier is cut down to fit a vehicle hatch and holds only
// 80, against 140-160 for the operators' rigs. Four magazines rather than
// seven; a crewman fights out of a vehicle, not on foot.
class PTF_Kestrel_crewman: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Crewman";
   cost = 800000;
   linkedItems[] = {"rhsusf_bowman_cap", "rhsusf_spc_crewman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_bowman_cap", "rhsusf_spc_crewman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   magazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67"
      };
   respawnMagazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67"
      };
};

class PTF_Kestrel_teamleader: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Team Leader";
   cost = 1300000;
   accuracy = 4.0;
   sensitivity = 4.5;
   icon = "iconManLeader";
   linkedItems[] = {"rhsusf_opscore_01_tan", "rhsusf_plateframe_teamleader", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01_tan", "rhsusf_plateframe_teamleader", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   uniformClass = "PTF_U_kestrel_dpm";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_dpm_co.paa"};
   weapons[] = {"rhs_weap_mk18_eotech_sup", "rhsusf_weap_glock17g4", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_mk18_eotech_sup", "rhsusf_weap_glock17g4", "Throw", "Put", "Binocular"};
};

// Kestrel's senior man on the island. Killing him does not end the contract;
// making the contract unprofitable does.
class PTF_Kestrel_commander: PTF_Kestrel_teamleader
{
   displayName = "Kestrel Site Commander";
   cost = 1600000;
   uniformClass = "PTF_U_kestrel_desert";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_3color_desert_co.paa"};
   linkedItems[] = {"rhsusf_patrolcap_ocp", "rhsusf_spc_squadleader", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_patrolcap_ocp", "rhsusf_spc_squadleader", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};

// --- HVT -------------------------------------------------------------------
//
// Not a soldier -- the man who administers the contract. Kestrel are defeated
// by economics, and he is the paperwork made flesh: the one carrying the terms
// the players are meant to find in Op 3. Civilian-ish silhouette on purpose,
// so he reads as out of place among the operators guarding him.
class PTF_Kestrel_hvt: PTF_Kestrel_commander
{
   displayName = "Kestrel Contract Manager (HVT)";
   cost = 1500000;
   accuracy = 2.4;
   sensitivity = 3.4;
   icon = "iconManLeader";
   uniformClass = "PTF_U_kestrel_olive";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_olive_co.paa"};
   linkedItems[] = {"rhsusf_bowman_cap", "rhsusf_spc_patchless", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_bowman_cap", "rhsusf_spc_patchless", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhsusf_weap_glock17g4", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhsusf_weap_glock17g4", "Throw", "Put", "Binocular"};
   magazines[] = {"rhsusf_mag_17Rnd_9x19_JHP", "rhsusf_mag_17Rnd_9x19_JHP", "rhs_mag_m18_green"};
   respawnMagazines[] = {"rhsusf_mag_17Rnd_9x19_JHP", "rhsusf_mag_17Rnd_9x19_JHP", "rhs_mag_m18_green"};
};

class PTF_Kestrel_pilot: PTF_Kestrel_crewman
{
   displayName = "Kestrel Pilot";
   cost = 1000000;
};
