//C-130J
class PTF_C130J : USAF_C130J
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_space = 40;
   ace_cargo_hasCargo = 1;
   maximumLoad = 375;
   side = 1;
   faction = "BLU_F";
   author = "Paramarine Task Force";
   displayName = "C-130J [MAG36]";
   hiddenSelections[] = {"camo1", "camo2", "Decal"};
   hiddenSelectionsTextures[] = {"USAF_C130J\data\tex\c130j_body_co.paa", "USAF_C130J\data\tex\c130j_wings_co.paa", ""};
   LESH_canBeTowed = 1;
   LESH_towFromFront = 1;
   LESH_AxisOffsetTarget[] = {0,13.5,1};
   LESH_WheelOffset[] = {0.35,0};
};
class PTF_C130J_Cargo : USAF_C130J_Cargo
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_space = 40;
   ace_cargo_hasCargo = 1;
   maximumLoad = 375;
   side = 1;
 
   faction = "BLU_F";
   author = "Paramarine Task Force";
   displayName = "C-130J Cargo [MAG36]";
   hiddenSelections[] = {"camo1", "camo2", "Decal"};
   hiddenSelectionsTextures[] = {"USAF_C130J\data\tex\c130j_body_co.paa", "USAF_C130J\data\tex\c130j_wings_co.paa", ""};
   LESH_canBeTowed = 1;
   LESH_towFromFront = 1;
   LESH_AxisOffsetTarget[] = {0,13.5,0.95};
   LESH_WheelOffset[] = {0.35,0};
};