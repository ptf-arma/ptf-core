class PTF_Uniform_Infantry_FROG_WD : rhs_uniform_FROG01_wd
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] FROG (WD) [PTF]";
   author = "Paramarine Task Force";
   class ItemInfo : ItemInfo
   {
      containerClass = "Supply60";
      mass = 20;
   };
};
class PTF_Uniform_Infantry_FROG_D : rhs_uniform_FROG01_d
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] FROG (D) [PTF]";
   author = "Paramarine Task Force";
   class ItemInfo : ItemInfo
   {
      containerClass = "Supply60";
      mass = 20;
   };
};
class PTF_Uniform_Infantry_FROG_S : rhs_uniform_FROG01_wd
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] FROG (S) [PTF]";
   author = "Paramarine Task Force";
   class ItemInfo : UniformItem
   {
      uniformModel = "-";
      uniformClass = "PTFInfantry_Inf";
      containerClass = "Supply60";
      mass = 40;
   };
};
class PTF_Uniform_Infantry_G3_Tan : rhs_uniform_g3_tan
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] G3 (Tan) [PTF]";
   author = "Paramarine Task Force";
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\gear\uniforms\gen3_tan_co.paa","rhsusf\addons\rhsusf_infantry2\data\merrells_co.paa","rhsusf\addons\rhsusf_infantry2\data\Mechanix_tan2_co.paa"};
   class ItemInfo : UniformItem
   {
      uniformClass = "PTFInfantry_Inf_3rd_Green";
      containerClass = "Supply60";
      mass = 40;
   };
};
class PTF_Uniform_Infantry_G3_Green : rhs_uniform_g3_tan
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] G3 (Green) [PTF]";
   author = "Paramarine Task Force";
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\gear\uniforms\gen3_Green_co.paa","rhsusf\addons\rhsusf_infantry2\data\merrells_co.paa","rhsusf\addons\rhsusf_infantry2\data\Mechanix_green_co.paa"};
   class ItemInfo : UniformItem
   {
      uniformClass = "PTFInfantry_Inf_3rd_Tan";
      containerClass = "Supply60";
      mass = 40;
   };
};
