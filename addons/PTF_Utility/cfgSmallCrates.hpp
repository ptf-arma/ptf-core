class PTF_Cargo_Small : Boxloader_SmallPallet_Ammo
{
   scope = 2;
   side = 8;
   armor = 500;
   epeImpulseDamageCoef = 100;
   faction = "BLU_F";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 5;
   ace_cargo_canload = 1;
   ace_dragging_canCarry = 0;
   ace_dragging_candrag = 1;
   AL_canBeMoved = 1;
   AL_weight = 10;
   AL_ForkAttachpoint[] = {0,0.15,0};
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Cargo";
   author = "Paramarine Task Force";
   displayname = "Small - Empty";
   hiddenselections[] = {
       "camo",
       "camo_signs"};
   hiddenselectionstextures[] = {
       "PTF_Utility\data\cargo\PTF_Cargo_Small_ammo\Boxloader_SmallPallet_ammo_co.paa",
       "PTF_Cargo\Data\PTF_Cargo_Small_ammo\Boxloader_SmallPallet_ammo_ca.paa"};
   class vehicleTransport
   {
      class Cargo
      {
         parachuteClass = "B_Parachute_02_F";
         parachuteHeightLimit = 15;
         canBeTransported = 1;
         dimensions[] = {
             "BBox_Base", "BBox_Corner"};
      };
   };
   class Transportmagazines{};
   class Transportweapons{};
   class Transportitems{};
};

class PTF_Cargo_Small_Ammo : PTF_Cargo_Small
{
   displayname = "Small - Ammo";
   class Transportmagazines
   {
      mag_xx(rhsusf_100Rnd_762x51_m80a1epr, 20);
      mag_xx(rhsusf_200Rnd_556x45_mixed_soft_pouch_coyote, 20);
      mag_xx(rhsusf_20Rnd_762x51_SR25_m62_Mag, 5);
      mag_xx(rhsusf_20Rnd_762x51_SR25_m993_Mag, 5);
      mag_xx(rhsusf_20Rnd_762x51_SR25_mk316_special_Mag, 5);
      mag_xx(PTF_Mag_556x45_M855A1_Stanag_Mix, 100);
      mag_xx(SmokeShellBlue, 10);
      mag_xx(SmokeShellGreen, 10);
      mag_xx(SmokeShellPurple, 20);
      mag_xx(SmokeShellRed, 10);
      mag_xx(SmokeShell, 30);
      mag_xx(rhs_mag_m67, 20);
      mag_xx(rhs_mag_m433_HEDP, 10);
      mag_xx(rhs_mag_M441_HE, 10);
      mag_xx(rhs_mag_M397_HET, 10);
      mag_xx(rhsusf_mag_6Rnd_M441_HE, 10);
      mag_xx(rhsusf_mag_6Rnd_M433_HEDP, 10);
      mag_xx(ACE_CTS9, 40);
      mag_xx(rhsusf_mag_7x45acp_MHP, 20);
      mag_xx(PTF_Mag_762x51_M80A1_EPR_Mix, 20);
   };
   class Transportweapons
   {
      weap_xx(rhs_weap_m72a7, 10);
      weap_xx(rhs_weap_M136_hp, 10);
   };
   class Transportitems
   {
      item_xx(ACE_CableTie, 20);
      item_xx(ACE_IR_Strobe_Item, 25);
   };
};
class PTF_Cargo_Small_Launcher : PTF_Cargo_Small
{
   displayname = "Small - Launcher";
   class Transportmagazines
   {
      mag_xx(rhs_fgm148_magazine_AT, 5);
      mag_xx(MRAWS_HEAT_F, 5);
      mag_xx(MRAWS_HE_F, 10);
      mag_xx(MRAWS_HEAT55_F, 10);
      mag_xx(rhs_fim92_mag, 10);
   };
   class Transportweapons
   {
	   weap_xx(rhs_weap_m72a7, 10);
      weap_xx(rhs_weap_M136_hp, 5);
      weap_xx(rhs_weap_M136, 5);
      weap_xx(rhs_weap_M136_hedp, 5);
   };
};
class PTF_Cargo_Small_Explosives : PTF_Cargo_Small
{
   displayname = "Small - Explosives";
   class Transportmagazines
   {
      mag_xx(tsp_breach_block_mag, 25);
      mag_xx(tsp_breach_popper_mag, 25);
      mag_xx(DemoCharge_Remote_Mag, 10);
      mag_xx(tsp_breach_package_mag, 10);
      mag_xx(rhs_mag_m67, 15);
      mag_xx(SmokeShell, 15);
      mag_xx(ClaymoreDirectionalMine_Remote_Mag, 5);
      mag_xx(SatchelCharge_Remote_Mag, 5);
   };
   class Transportitems
   {
	   item_xx(ACE_Clacker, 5);
   };
};
class PTF_Cargo_Small_Medical : PTF_Cargo_Small
{
   displayname = "Small - Medical";
   class Transportitems
   {
      item_xx(ACE_salineIV_250, 30);
      item_xx(ACE_salineIV_500, 30);
      item_xx(ACE_salineIV, 30)
      item_xx(ACE_tourniquet, 25);
      item_xx(ACE_fieldDressing, 100);
      item_xx(ACE_quikclot, 100);
      item_xx(ACE_elasticBandage, 75);
      item_xx(ACE_packingBandage, 75);
      item_xx(ACE_epinephrine, 25);
      item_xx(ACE_adenosine, 20);
      item_xx(ACE_morphine, 20);
      item_xx(ACE_bodyBag, 5);
      item_xx(ACE_splint, 25);
      item_xx(ACE_plasmaIV,15);
      item_xx(ACE_plasmaIV_500, 15);
      item_xx(kat_IV_16, 30);
      item_xx(kat_Carbonate, 30);
      item_xx(kat_Painkiller, 30);
      item_xx(kat_EACA, 30);
      item_xx(kat_IO_FAST, 30);
      item_xx(kat_naloxone, 30);
      item_xx(kat_norepinephrine, 30);
      item_xx(kat_phenylephrine, 30);
      item_xx(kat_Carbonate, 30);
      item_xx(kat_TXA, 30);
   };
};
class PTF_Cargo_Small_Humanitarian : PTF_Cargo_Small
{
   displayname = "Small - Humanitarian";
   class Transportitems
   {
      item_xx(ACE_Banana, 30);
      item_xx(ACE_Can_Franta, 30);
      item_xx(ACE_Can_RedGull, 30);
      item_xx(ACE_Can_Spirit, 30);
      item_xx(ACE_Canteen, 30);
      item_xx(ACE_Humanitarian_Ration, 100);
      item_xx(ACE_WaterBottle, 100);
   };
};
class PTF_Cargo_Mortar : PTF_Cargo_Small
{
   displayname = "Small - Mortar";
   class TransportMagazines
   {
      mag_xx(NDS_M_6Rnd_60mm_HE   , 4);
      mag_xx(avm224_M_6Rnd_60mm_SMOKE_csw, 4);
      mag_xx(NDS_M_6Rnd_60mm_HE_0, 2);
      mag_xx(avm224_M_6Rnd_60mm_ILLUM_IR_csw, 24);
      mag_xx(avm224_M_6Rnd_60mm_ILLUM_csw, 4);
   };
};
class PTF_Cargo_Vic : PTF_Cargo_Small
{
   ace_cargo_space = 40;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 5;
   ace_cargo_canload = 1;
   ace_dragging_canCarry = 0;
   ace_dragging_candrag = 1;
   displayname = "Small - Vic Box";
   class EventHandlers
   {
      init = "[(_this select 0)] remoteExec ['PTF_fnc_SmallVicBox_init', 0, true]";
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
      };
   };
};
class PTF_Cargo_Tracks : PTF_Cargo_Small
{
   ace_cargo_space = 40;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 5;
   ace_cargo_canload = 1;
   ace_dragging_canCarry = 0;
   ace_dragging_candrag = 1;
   displayname = "Track Box";
   class EventHandlers
   {
      init = "[(_this select 0)] remoteExec ['PTF_fnc_Tracks_init', 0, true]";
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
      };
   };
};
class PTF_Cargo_Ammo : NATO_Box_Base
{
   scope = 2;
   side = 8;
   armor = 500;
   epeImpulseDamageCoef = 100;
   faction = "BLU_F";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 2;
   ace_cargo_canload = 1;
   ace_dragging_canCarry = 1;
   ace_dragging_candrag = 1;
   AL_canBeMoved = 1;
   AL_weight = 10;
   AL_ForkAttachpoint[] = {0,0,0.25};
   maximumLoad = 375;
   model = "\A3\weapons_F\ammoBoxes\ammoBox_F";
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Cargo";
   author = "Paramarine Task Force";
   displayname = "Ammo Box";

   hiddenselections[] = {
       "Camo_Signs ",
       "Camo"};
   hiddenselectionstextures[] = {
       "A3\weapons_F\ammoboxes\data\ammoBox_signs_CA.paa",
       "A3\weapons_F\ammoboxes\data\ammoBox_CO.paa"};

   class VehicleTransport
   {
      class Cargo
      {
         parachuteClass = "B_Parachute_02_F";
         parachuteHeightLimit = 15;
         canBeTransported = 1;
         dimensions[] = {
             "BBox_Base", "BBox_Corner"};
      };
   };

   class TransportMagazines{};
   class TransportWeapons{};
   class TransportItems {};
   class TransportBackpacks{};
};
class PTF_Cargo_Small_Repair : PTF_Cargo_Small
{
   displayname = "Small - Repair";
   class VehicleTransport
      {
         class Cargo
         {
            parachuteClass = "B_Parachute_02_F";
            parachuteHeightLimit = 40;
            canBeTransported = 1;
            dimensions[] = {"BBox_Base0","BBox_Corner_1m"};
         };
         class Carrier{};
      };
   model = "\boxloader\mdl\boxloader_crate1.p3d";
   supplyRadius = 10;
   transportRepair = 200000000;
};
class PTF_Cargo_Small_Rearm : PTF_Cargo_Small
{
   displayname = "Small - Rearm";
   supplyRadius = 10;
   transportAmmo = 200000000;
};
class PTF_Cargo_Tiny_Ammo : Land_Ammobox_rounds_F
{
   scope = 2;
   side = 8;
   armor = 500;
   epeImpulseDamageCoef = 100;
   faction = "BLU_F";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 2;
   ace_cargo_canload = 1;
   ace_dragging_canCarry = 1;
   ace_dragging_candrag = 1;
   maximumLoad = 133;
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Cargo";
   author = "Paramarine Task Force";
   displayname = "Tiny Ammo Box";

   class TransportMagazines
   {
   };
   class TransportWeapons
   {
   };
   class TransportItems
   {
   };
   class TransportBackpacks
   {
   };
};
