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