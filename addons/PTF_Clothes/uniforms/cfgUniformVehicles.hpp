class ContainerSupply;
class Supply25 : ContainerSupply
{
   maximumLoad = 25;
};
class B_Pilot_F;
class PTFInfantry_Air : B_Pilot_F
{
   faction = "Moe_Faction";
   author = "Paramarine Task Force";
   scope = 1;
   scopeCurator = 0;
   identityTypes[] = {"LanguageENG_F", "Head_NATO"};
   displayName = "Moe Pilot (Gloves)";
   model = "\MoeCoveralls\LongSleeves\NomexLongSleeves.p3d";
   uniformClass = "CWU27P_Base_NG";
   picture = "";
   backpack = "";
   vest = "";
   weapons[] = {"Throw", "Put"};
   respawnWeapons[] = {"Throw", "Put"};
   Items[] = {"FirstAidKit"};
   respawnItems[] = {"FirstAidKit"};
   magazines[] = {};
   respawnMagazines[] = {};
   linkedItems[] = {"ItemMap", "ItemCompass", "ItemRadio", "ItemWatch"};
   respawnLinkedItems[] = {"ItemMap", "ItemCompass", "ItemRadio", "ItemWatch"};
   hiddenselections[] = {"NomexTex"};
   hiddenselectionstextures[] = {"\z\PTF\addons\PTF_Textures\gear\uniforms\CWU27P_blue.paa"};
};
// Custom squadron/command CWU-27/P coveralls (worn models for the
// PTF_Uniform_Air_CWU27P_* items in cfgAirUniforms.hpp). Same Moe model and
// NomexTex selection as PTFInfantry_Air, with a per-uniform texture; the
// _Rolled variants swap in Moe's rolled-sleeves model.
class PTFInfantry_Air_CWU27P_Gunfighters : PTFInfantry_Air
{
   displayName = "[Air] CWU-27/P (Gunfighters) [PTF]";
   uniformClass = "PTF_Uniform_Air_CWU27P_Gunfighters";
   hiddenselections[] = {"NomexTex"};
   hiddenselectionstextures[] = {"\z\PTF\addons\PTF_Textures\gear\uniforms\CWU27P_Gunfighters_Green_co.paa"};
};
class PTFInfantry_Air_CWU27P_Gunfighters_Rolled : PTFInfantry_Air
{
   model = "\MoeCoveralls\RolledSleeves\NomexRolledSleeves.p3d";
   displayName = "[Air] CWU-27/P (Gunfighters, Rolled) [PTF]";
   uniformClass = "PTF_Uniform_Air_CWU27P_Gunfighters_Rolled";
   hiddenselections[] = {"NomexTex"};
   hiddenselectionstextures[] = {"\z\PTF\addons\PTF_Textures\gear\uniforms\CWU27P_Gunfighters_Green_co.paa"};
};
class PTFInfantry_Air_CWU27P_MAG_CO : PTFInfantry_Air
{
   displayName = "[Air] CWU-27/P (MAG CO) [PTF]";
   uniformClass = "PTF_Uniform_Air_CWU27P_MAG_CO";
   hiddenselections[] = {"NomexTex"};
   hiddenselectionstextures[] = {"\z\PTF\addons\PTF_Textures\gear\uniforms\CWU27P_MAG_CO_Green_co.paa"};
};
class PTFInfantry_Air_CWU27P_MAG_CO_Rolled : PTFInfantry_Air
{
   model = "\MoeCoveralls\RolledSleeves\NomexRolledSleeves.p3d";
   displayName = "[Air] CWU-27/P (MAG CO, Rolled) [PTF]";
   uniformClass = "PTF_Uniform_Air_CWU27P_MAG_CO_Rolled";
   hiddenselections[] = {"NomexTex"};
   hiddenselectionstextures[] = {"\z\PTF\addons\PTF_Textures\gear\uniforms\CWU27P_MAG_CO_Green_co.paa"};
};
class PTFInfantry_Air_CWU27P_MAG_XO : PTFInfantry_Air
{
   displayName = "[Air] CWU-27/P (MAG XO) [PTF]";
   uniformClass = "PTF_Uniform_Air_CWU27P_MAG_XO";
   hiddenselections[] = {"NomexTex"};
   hiddenselectionstextures[] = {"\z\PTF\addons\PTF_Textures\gear\uniforms\CWU27P_MAG_XO_Green_co.paa"};
};
class PTFInfantry_Air_CWU27P_MAG_XO_Rolled : PTFInfantry_Air
{
   model = "\MoeCoveralls\RolledSleeves\NomexRolledSleeves.p3d";
   displayName = "[Air] CWU-27/P (MAG XO, Rolled) [PTF]";
   uniformClass = "PTF_Uniform_Air_CWU27P_MAG_XO_Rolled";
   hiddenselections[] = {"NomexTex"};
   hiddenselectionstextures[] = {"\z\PTF\addons\PTF_Textures\gear\uniforms\CWU27P_MAG_XO_Green_co.paa"};
};
class PTFInfantry_Inf : B_Pilot_F
{
   faction = "Moe_Faction";
   author = "Paramarine Task Force";
   scope = 1;
   scopeCurator = 0;
   identityTypes[] = {"LanguageENG_F", "Head_NATO"};
   displayName = "Moe Pilot (Gloves)";
   model = "\rhsusf\addons\rhsusf_infantry\rhsusf_marine_v2.p3d";
   uniformClass = "CWU27P_Base_NG";
   picture = "";
   backpack = "";
   vest = "";
   weapons[] = {"Throw", "Put"};
   respawnWeapons[] = {"Throw", "Put"};
   Items[] = {"FirstAidKit"};
   respawnItems[] = {"FirstAidKit"};
   magazines[] = {};
   respawnMagazines[] = {};
   linkedItems[] = {"ItemMap", "ItemCompass", "ItemRadio", "ItemWatch"};
   respawnLinkedItems[] = {"ItemMap", "ItemCompass", "ItemRadio", "ItemWatch"};
   hiddenSelections[] = {"camo", "insignia"};
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\gear\uniforms\ptf_frog_snow.paa"};
};
class PTFInfantry_Inf_3rd_Green : B_Pilot_F
{
   faction = "Moe_Faction";
   author = "Paramarine Task Force";
   scope = 1;
   scopeCurator = 0;
   identityTypes[] = {"LanguageENG_F", "Head_NATO"};
   displayName = "Moe Pilot (Gloves)";
   model = "\rhsusf\addons\rhsusf_infantry2\CryeGen3.p3d";
   uniformClass = "CWU27P_Base_NG";
   picture = "";
   backpack = "";
   vest = "";
   weapons[] = {"Throw", "Put"};
   respawnWeapons[] = {"Throw", "Put"};
   Items[] = {"FirstAidKit"};
   respawnItems[] = {"FirstAidKit"};
   magazines[] = {};
   respawnMagazines[] = {};
   linkedItems[] = {"ItemMap", "ItemCompass", "ItemRadio", "ItemWatch"};
   respawnLinkedItems[] = {"ItemMap", "ItemCompass", "ItemRadio", "ItemWatch"};
   hiddenSelections[] = {"Camo","Camo2","Gloves","insignia"};
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\gear\uniforms\gen3_green_co.paa","rhsusf\addons\rhsusf_infantry2\data\merrells_co.paa", "rhsusf\addons\rhsusf_infantry2\data\mechanix_g_co.paa"};
};
class PTFInfantry_Inf_3rd_Tan : B_Pilot_F
{
   faction = "Moe_Faction";
   author = "Paramarine Task Force";
   scope = 1;
   scopeCurator = 0;
   identityTypes[] = {"LanguageENG_F", "Head_NATO"};
   displayName = "Moe Pilot (Gloves)";
   model = "\rhsusf\addons\rhsusf_infantry2\CryeGen3.p3d";
   uniformClass = "CWU27P_Base_NG";
   picture = "";
   backpack = "";
   vest = "";
   weapons[] = {"Throw", "Put"};
   respawnWeapons[] = {"Throw", "Put"};
   Items[] = {"FirstAidKit"};
   respawnItems[] = {"FirstAidKit"};
   magazines[] = {};
   respawnMagazines[] = {};
   linkedItems[] = {"ItemMap", "ItemCompass", "ItemRadio", "ItemWatch"};
   respawnLinkedItems[] = {"ItemMap", "ItemCompass", "ItemRadio", "ItemWatch"};
   hiddenSelections[] = {"Camo","Camo2","Gloves","insignia"};
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\gear\uniforms\gen3_tan_co.paa", "rhsusf\addons\rhsusf_infantry2\data\merrells_co.paa", "rhsusf\addons\rhsusf_infantry2\data\mechanix_g_co.paa"};
};
