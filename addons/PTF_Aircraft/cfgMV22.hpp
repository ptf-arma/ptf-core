//MV-22
class PTF_MV22_Ramp : CUP_B_MV22_USMC_RAMPGUN
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   ace_cargo_hasCargo = 0;
   author = "Paramarine Task Force";
   displayName = "MV-22 (RampGun)[MAG36]";
   hiddenSelectionsTextures[] = {"\PTF_Textures\aircraft\mv22\mv22_1_co.paa", "\PTF_Textures\aircraft\mv22\mv22_2_co.paa"};
};
class PTF_MV22_Cargo : CUP_B_MV22_VIV_USMC
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 60;
   ace_cargo_hasCargo = 1;
   author = "Paramarine Task Force";
   displayName = "MV-22 Cargo [MAG36]";
   hiddenSelectionsTextures[] = {"\PTF_Textures\aircraft\mv22\cargo\mv22_1_co.paa", "\PTF_Textures\aircraft\mv22\cargo\mv22_2_co.paa"};
};