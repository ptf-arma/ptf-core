//MV-22
class PTF_MV22_Ramp : DEGA_MV22_Infantry_NATO
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   ace_cargo_hasCargo = 0;
   author = "Paramarine Task Force";
   displayName = "MV-22 [MAG36]";
   hiddenSelectionsTextures[] = {"\PTF_Textures\aircraft\mv22\mv22_1_co.paa", "\PTF_Textures\aircraft\mv22\mv22_2_co.paa"};
};
class PTF_MV22_Cargo : DEGA_MV22_Vehicle_NATO
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
class PTF_MV22_Minigun : DEGA_MV22_IDWS_NATO
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 60;
   ace_cargo_hasCargo = 1;
   author = "Paramarine Task Force";
   displayName = "MV-22 Mini [MAG36]";
   hiddenSelectionsTextures[] = {"\PTF_Textures\aircraft\mv22\cargo\mv22_1_co.paa", "\PTF_Textures\aircraft\mv22\cargo\mv22_2_co.paa"};
};