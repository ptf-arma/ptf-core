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
