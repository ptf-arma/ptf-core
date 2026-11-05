class CfgPatches
{
   class PTF_DICoverUSMC
   {
      name = "PTF Campaign Cover";
      author = "Paramarine Task Force";
      units[] = {};
      weapons[] = {"PTF_DI_COVER"};
      requiredVersion = 0.1;
      requiredAddons[] = {"PTF_Main", "A3_Characters_F"};
   };
};

class CfgWeapons
{
   class ItemCore;
   class HeadgearItem;
   class PTF_DI_COVER : ItemCore
   {
      scope = 2;
      weaponPoolAvailable = 1;
      displayName = "[Dress] Campaign Cover [PTF]";
      author = "Paramarine Task Force";
      picture = "\z\PTF\addons\PTF_DICoverUSMC\UI\DS_UI.paa";
      model = "\z\PTF\addons\PTF_DICoverUSMC\DICover.p3d";
      class ItemInfo : HeadgearItem
      {
         mass = 2;
         allowedSlots[] = {901, 701, 605};
         uniformModel = "\z\PTF\addons\PTF_DICoverUSMC\DICover.p3d";
         modelSides[] = {6};
         armor = 0;
         passThrough = 0.8;
      };
   };
};
