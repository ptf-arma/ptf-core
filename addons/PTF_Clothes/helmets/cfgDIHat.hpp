class PTF_Helmet_Infantry_DIHat : ItemCore
{
   scope = 2;
   weaponPoolAvailable = 1;
   displayName = "Campaign Cover [PTF]";
   author = "Paramarine Task Force";
   picture = "\PTF_Textures\gear\dihat\DS_UI.paa";
   model = "\PTF_Models\gear\dihat\dihat.p3d";
   hiddenSelections[] = {""};
   hiddenSelectionsTextures[] = {""};
   class ItemInfo : HeadgearItem
   {
      mass = 2;
      allowedSlots[] = {901, 701, 605};
      uniformModel = "\PTF_Models\gear\dihat\dihat.p3d";
      modelSides[] = {6};
      armor = "0*0";
      passThrough = 0.8;
      hiddenSelections[] = {"camo"};
   };
};