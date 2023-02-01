class PTF_Cargo_Large_Ammo : Boxloader_Ammo_West
{
   scope = 2;
   side = 8;
   faction = "BLU_F";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Cargo";
   author = "Paramarine Task Force";
   displayName = "Large - Ammo";
   hiddenSelections[] = {
       "camo",
       "camo_signs"};
   hiddenSelectionsTextures[] = {
       "PTF_Utility\data\cargo\PTF_Cargo_Large_Ammo\Boxloader_Ammo_West_co.paa",
       "PTF_Cargo\Data\PTF_Cargo_Large_Ammo\Boxloader_Ammo_West_ca.paa"};
   class VehicleTransport
   {
      class Cargo
      {
         parachuteClass = "B_Parachute_02_F";
         parachuteHeightLimit = 15;
         canBeTransported = 1;
         dimensions[] = {"BBox_Base0", "BBox_Corner"};
      };
   };
   class TransportMagazines
   {
      mag_xx(rhsusf_100Rnd_762x51_m80a1epr, 40);
      mag_xx(rhsusf_100Rnd_556x45_mixed_soft_pouch_coyote, 30);
      mag_xx(rhsusf_200Rnd_556x45_mixed_soft_pouch_coyote, 20);
	   mag_xx(rhsusf_20Rnd_762x51_SR25_m62_Mag, 20);
      mag_xx(rhsusf_20Rnd_762x51_SR25_m993_Mag, 20);
      mag_xx(rhsusf_20Rnd_762x51_SR25_mk316_special_Mag, 20);
      mag_xx(PTF_Mag_556x45_M855A1_Stanag_Mix, 100);
      mag_xx(PTF_Mag_556x45_Mk262_Stanag_Mix, 100);
      mag_xx(CUP_17Rnd_9x19_M17_Black, 30);
      mag_xx(DemoCharge_Remote_Mag, 10);
      mag_xx(SmokeShellBlue, 20);
      mag_xx(SmokeShellGreen, 20);
      mag_xx(SmokeShellPurple, 40);
      mag_xx(SmokeShellRed, 20);
      mag_xx(SmokeShell, 60);
      mag_xx(rhs_mag_m67, 40);
      mag_xx(rhs_mag_m433_HEDP, 60);
   };
   class Transportweapons
   {
      weap_xx(rhs_weap_m72a7, 20);
      weap_xx(rhs_weap_M136_hp, 20);
   };
};
class PTF_Cargo_Large_Explosives : Boxloader_Ammo_West
{
   scope = 2;
   side = 8;
   faction = "BLU_F";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Cargo";
   author = "Paramarine Task Force";
   displayName = "Large - Explosives";
   hiddenSelections[] = {
       "camo",
       "camo_signs"};
   hiddenSelectionsTextures[] = {
       "PTF_Utility\data\cargo\PTF_Cargo_Large_Explosives\Boxloader_Ammo_West_co.paa",
       "PTF_Cargo\Data\PTF_Cargo_Large_Explosives\Boxloader_Ammo_West_ca.paa"};
   class VehicleTransport
   {
      class Cargo
      {
         parachuteClass = "B_Parachute_02_F";
         parachuteHeightLimit = 15;
         canBeTransported = 1;
         dimensions[] = {"BBox_Base0", "BBox_Corner"};
      };
   };
   class TransportMagazines
   {
      mag_xx(rhs_fgm148_magazine_AT, 10);
      mag_xx(rhs_fim92_mag, 10);
      mag_xx(DemoCharge_Remote_Mag, 20);
      mag_xx(NDS_M_6Rnd_60mm_HE, 20);
      mag_xx(MRAWS_HEAT_F, 40);
      mag_xx(rhs_mag_m67, 30);
      mag_xx(SmokeShell, 30);
   };
   class TransportWeapons
   {
	  weap_xx(rhs_weap_m72a7, 20); 
      weap_xx(rhs_weap_M136_hp, 20);
   };
};
class PTF_Cargo_Large_Medical : Boxloader_Ammo_West
{
   scope = 2;
   side = 8;
   faction = "BLU_F";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Cargo";
   author = "Paramarine Task Force";
   displayName = "Large - Medical";
   hiddenSelections[] = {
       "camo",
       "camo_signs"};
   hiddenSelectionsTextures[] = {
       "PTF_Utility\data\cargo\PTF_Cargo_Large_Medical\Boxloader_Ammo_West_co.paa",
       "PTF_Cargo\Data\PTF_Cargo_Large_Medical\Boxloader_Ammo_West_ca.paa"};
   class VehicleTransport
   {
      class Cargo
      {
         parachuteClass = "B_Parachute_02_F";
         parachuteHeightLimit = 15;
         canBeTransported = 1;
         dimensions[] = {"BBox_Base0", "BBox_Corner"};
      };
   };
   class TransportMagazines
   {
      mag_xx(SmokeShellPurple, 40);
   };
   class TransportItems
   {
      item_xx(kat_IV_16, 50);
      item_xx(kat_vacuum, 50);
      item_xx(kat_EACA, 50);
      item_xx(kat_flumazenil, 50);
      item_xx(kat_naxolone, 50);
      item_xx(kat_nitroglycerin, 50);
      item_xx(kat_norepinephine, 50);
      item_xx(kat_Painkiller, 75);
      item_xx(kat_phenylephrine, 50);
      item_xx(kat_TXA, 50);
      item_xx(ACE_fieldDressing, 150);
      item_xx(ACE_quikclot, 150);
      item_xx(ACE_elasticBandage, 150);
      item_xx(ACE_packingBandage, 150);
      item_xx(ACE_epinephrine, 50);
      item_xx(ACE_adenosine, 40);
      item_xx(ACE_morphine, 40);
      item_xx(ACE_bodyBag, 10);
      item_xx(ACE_surgicalKit, 10);
      item_xx(ACE_CableTie, 20);
      item_xx(ACE_plasmaIV, 20);
      item_xx(ACE_plasmaIV_250, 30);
      item_xx(ACE_plasmaIV_500, 30);
   };
};
class PTF_Cargo_Large_Cargo : Boxloader_Ammo_West
{
   scope = 2;
   side = 8;
   faction = "BLU_F";
   ace_cargo_space = 30;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 90000;
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Cargo";
   author = "Paramarine Task Force";
   displayName = "Large - Cargo";
   hiddenSelections[] = {
       "camo",
       "camo_signs"};
   hiddenSelectionsTextures[] = {
       "PTF_Utility\data\cargo\PTF_Cargo_Large_Ammo\Boxloader_Ammo_West_co.paa",
       "PTF_Cargo\Data\PTF_Cargo_Large_Ammo\Boxloader_Ammo_West_ca.paa"};
   class VehicleTransport
   {
      class Cargo
      {
         parachuteClass = "B_Parachute_02_F";
         parachuteHeightLimit = 15;
         canBeTransported = 1;
         dimensions[] = {"BBox_Base0", "BBox_Corner"};
      };
   };
};
//class PTF_Cargo_Large_Cargo : Boxloader_Ammo_West
//{
//   scope = 2;
//   side = 8;
//   faction = "BLU_F";
//   ace_cargo_space = 0;
//   ace_cargo_hasCargo = 0;
//   ace_cargo_size = 0;
//   ace_cargo_canLoad = 0;
//   ace_dragging_canCarry = 0;
//   maximumLoad = 180000;
//   editorCategory = "PTF_Empty";
//   editorSubcategory = "PTF_Cargo";
//   author = "Paramarine Task Force";
//   displayName = "Large - Campaign Resources";
//   hiddenSelections[] = {
//       "camo",
//       "camo_signs"};
//   hiddenSelectionsTextures[] = {
//       "PTF_Utility\data\cargo\PTF_Cargo_Large_Ammo\Boxloader_Ammo_West_co.paa",
//       "PTF_Cargo\Data\PTF_Cargo_Large_Ammo\Boxloader_Ammo_West_ca.paa"};
//   class VehicleTransport
//   {
//      class Cargo
//      {
//         dimensions[] = {"BBox_Base0", "BBox_Corner"};
//         parachuteClass = "B_Parachute_02_F";
//         canBeTransported = 0;
//         parachuteHeightLimit = 10;
//      };
//   };
//};
