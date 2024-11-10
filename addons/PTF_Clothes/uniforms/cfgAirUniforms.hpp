class PTF_Uniform_Air_CSU13BP_WD : CSU13BP_Base_NG
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Air] CSU-13B/P (WD) [PTF]";
   author = "Paramarine Task Force";
   ACE_GForceCoef = 0.8;	
   class ItemInfo : ItemInfo
   {
      containerClass = "Supply60";
      mass = 20;
   };
};
class PTF_Uniform_Air_CSU13BP_D : CSU13BPTan_Base_NG
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Air] CSU-13B/P (D) [PTF]";
   author = "Paramarine Task Force";
   ACE_GForceCoef = 0.8;	
   class ItemInfo : ItemInfo
   {
      containerClass = "Supply60";
      mass = 20;
   };
};
class PTF_Uniform_Air_CWU27P_WD : CWU27P_Base
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Air] CWU-27/P (WD) [PTF]";
   author = "Paramarine Task Force";
   class ItemInfo : ItemInfo
   {
      containerClass = "Supply60";
      mass = 20;
   };
};
class PTF_Uniform_Air_CWU27P_D : CWU27PTan_Base
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Air] CWU-27/P (D) [PTF]";
   author = "Paramarine Task Force";
   class ItemInfo : ItemInfo
   {
      containerClass = "Supply60";
      mass = 20;
   };
};
class PTF_Uniform_Air_CSU15BP_WD : CSU15BP_Base_Rolled_FG
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Air] CSU-15B/P (WD) [PTF]";
   ACE_GForceCoef = 0.8;
   author = "Paramarine Task Force";
   class ItemInfo : ItemInfo
   {
      containerClass = "Supply60";
      mass = 20;
   };
};
class PTF_Uniform_Air_CSU15BP_D : CSU15BPTan_Base_Rolled_FG
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Air] CSU-15B/P (D) [PTF]";
   author = "Paramarine Task Force";
   ACE_GForceCoef = 0.8;
   class ItemInfo : ItemInfo
   {
      containerClass = "Supply60";
      mass = 20;
   };
};
class PTF_Uniform_Air_SNA_USN : CWU27P_Base
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Air] SNA Coverall [PTF]";
   author = "Paramarine Task Force";
   class ItemInfo : UniformItem
   {
      uniformModel = "-";
      uniformClass = "PTFInfantry_Air";
      containerClass = "Supply60";
      mass = 20;
   };
};