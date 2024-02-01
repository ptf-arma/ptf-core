//Badger
class PTF_Badger : B_APC_Wheeled_01_cannon_F
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Armor";
   ace_cargo_space = 6;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   ace_hunterkiller[] = {{{0}, 3}, {{0,0}, 3}};
   maximumLoad = 750;
   side = 1;
   mass = 5000;
   author = "Paramarine Task Force";
   displayName = "Badger Woodland [PTF]";
   hiddenSelectionsTextures[] = {"\PTF_Textures\vehicles\badger\base_wd.paa", "\PTF_Textures\vehicles\badger\acc_wd.paa", "\PTF_Textures\vehicles\badger\turret_wd.paa"};
};
class PTF_Badger_D : PTF_Badger
{
   displayName = "Badger Desert [PTF]";
   hiddenSelectionsTextures[] = {"\PTF_Textures\vehicles\badger\base_d.paa", "\PTF_Textures\vehicles\badger\acc_d.paa", "\PTF_Textures\vehicles\badger\turret_d.paa"};
};