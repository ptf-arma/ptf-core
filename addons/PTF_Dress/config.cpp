class CfgPatches
{
   class PTF_Dress
   {
      name = "PTF Dress Uniforms";
      author = "Paramarine Task Force";
      units[] = {};
      weapons[] = {};
      requiredVersion = 2.18; // findDisplay by name, displayUpdate, hash maps
      requiredAddons[] =
      {
         "PTF_Main",
         "A3_Characters_F",
         // Every uniform here retextures the Art of War parade uniform and cap.
         "A3_Characters_F_AoW",
         "A3_Characters_F_AoW_Headgear"
      };
   };
};

class CfgFunctions
{
   class PTF_Dress
   {
      tag = "PTF_Dress";
      class Rack
      {
         file = "\z\PTF\addons\PTF_Dress\fnc";
         class rackInit { postInit = 1; };
         class rackTexture {};
         class rackDraw {};
      };
   };
};

#include "cfgRibbons.hpp"

class CfgVehicles
{
   class B_Uniform_ParadeUniform_01_US_decorated_F;
   class PTF_Dress_USMC_A_Base : B_Uniform_ParadeUniform_01_US_decorated_F
   {
      scope = 0;
      author = "Paramarine Task Force";
      // camo2 stays empty in each rank's textures: it is the vanilla cord and
      // braid, which a Service "A" coat does not have.
      model = "\a3\Characters_F_AoW\Uniforms\ParadeUniform_Decorated_01_F";
   };
   #include "cfgRankVehicles.hpp"
};

class CfgWeapons
{
   class UniformItem;
   class Uniform_Base;
   class PTF_Uniform_Dress_USMC_A_Base : Uniform_Base
   {
      scope = 0;
      author = "Paramarine Task Force";
      picture = "\a3\Characters_F_AoW\Uniforms\data\ui\icon_U_B_ParadeUniform_01_US_decorated_F_ca.paa";
      model = "\a3\Characters_F_AoW\Uniforms\Suitpacks\suitpack_FormalSuit_01_F.p3d";
      hiddenSelections[] = {"camo"};
      hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Dress\data\ptf_dress_usmc_suitpack_co.paa"};
      class ItemInfo : UniformItem
      {
         uniformModel = "-";
         containerClass = "Supply20";
         mass = 30;
      };
   };
   #include "cfgRankUniforms.hpp"

   class H_ParadeDressCap_01_base_F;
   class H_ParadeDressCap_01_US_F : H_ParadeDressCap_01_base_F
   {
      class ItemInfo;
   };
   class PTF_Headgear_Dress_USMC_Cover : H_ParadeDressCap_01_US_F
   {
      scope = 2;
      author = "Paramarine Task Force";
      picture = "\z\PTF\addons\PTF_Dress\ui\ptf_dress_icon_cover_ca.paa";
      displayName = "[Dress] Service Frame Cap - Enlisted [PTF]";
      hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Dress\data\ptf_dress_usmc_cover_co.paa"};
      hiddenSelectionsMaterials[] = {"\z\PTF\addons\PTF_Dress\data\ptf_dress_usmc_cover.rvmat"};
      class ItemInfo : ItemInfo
      {
         hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Dress\data\ptf_dress_usmc_cover_co.paa"};
         hiddenSelectionsMaterials[] = {"\z\PTF\addons\PTF_Dress\data\ptf_dress_usmc_cover.rvmat"};
      };
   };
   class PTF_Headgear_Dress_USMC_Cover_Officer : H_ParadeDressCap_01_US_F
   {
      scope = 2;
      author = "Paramarine Task Force";
      picture = "\z\PTF\addons\PTF_Dress\ui\ptf_dress_icon_cover_officer_ca.paa";
      displayName = "[Dress] Service Frame Cap - Company Grade [PTF]";
      hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Dress\data\ptf_dress_usmc_cover_officer_co.paa"};
      hiddenSelectionsMaterials[] = {"\z\PTF\addons\PTF_Dress\data\ptf_dress_usmc_cover_officer.rvmat"};
      class ItemInfo : ItemInfo
      {
         hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Dress\data\ptf_dress_usmc_cover_officer_co.paa"};
         hiddenSelectionsMaterials[] = {"\z\PTF\addons\PTF_Dress\data\ptf_dress_usmc_cover_officer.rvmat"};
      };
   };
   class PTF_Headgear_Dress_USMC_Cover_Field : H_ParadeDressCap_01_US_F
   {
      scope = 2;
      author = "Paramarine Task Force";
      picture = "\z\PTF\addons\PTF_Dress\ui\ptf_dress_icon_cover_field_ca.paa";
      displayName = "[Dress] Service Frame Cap - Field Grade [PTF]";
      hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Dress\data\ptf_dress_usmc_cover_field_co.paa"};
      hiddenSelectionsMaterials[] = {"\z\PTF\addons\PTF_Dress\data\ptf_dress_usmc_cover_officer.rvmat"};
      class ItemInfo : ItemInfo
      {
         hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Dress\data\ptf_dress_usmc_cover_field_co.paa"};
         hiddenSelectionsMaterials[] = {"\z\PTF\addons\PTF_Dress\data\ptf_dress_usmc_cover_officer.rvmat"};
      };
   };
};
