class PTF_Helmet_Infantry_DIHat : ItemCore
{
   scope = 2;
   weaponPoolAvailable = 1;
   displayName = "Campaign Cover [PTF]";
   author = "Paramarine Task Force";
   picture = "\z\PTF\addons\PTF_Textures\gear\dihat\DS_UI.paa";
   model = "\z\PTF\addons\PTF_Models\gear\dihat\dihat.p3d";
   hiddenSelections[] = {""};
   hiddenSelectionsTextures[] = {""};
   class ItemInfo : HeadgearItem
   {
      mass = 2;
      allowedSlots[] = {901, 701, 605};
      uniformModel = "\z\PTF\addons\PTF_Models\gear\dihat\dihat.p3d";
      modelSides[] = {6};
      armor = "0*0";
      passThrough = 0.8;
      hiddenSelections[] = {"camo"};
   };
};