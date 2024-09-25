class PTF_Helmet_Service_Cap : H_HelmetB
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "Service Cap [PTF]";
   author = "Paramarine Task Force";
   picture = "";
   hiddenSelections[] = {"camo"};
   hiddenSelectionsTextures[] =
       {
           "\z\PTF\addons\PTF_Textures\gear\servicecap\service_cap.paa"};
   model = "\z\PTF\addons\PTF_Models\gear\servicecap\Cap.p3d";
   class ItemInfo : ItemInfo
   {
      mass = 5;
      armor = 0;
      uniformModel = "\z\PTF\addons\PTF_Models\gear\servicecap\Cap.p3d";
      modelSides[] = {0};
      class HitpointsProtectionInfo
      {
      };
   };
};