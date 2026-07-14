class PTF_Large_Box : Boxloader_Ammo_West
{
   scope = 2;
   side = 8;
   armor = 500;
   epeImpulseDamageCoef = 100;
   faction = "BLU_F";
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   AL_canBeMoved = 1;
   AL_weight = 30;
   AL_ForkAttachpoint[] = {0,0.9,0};
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Cargo";
   author = "Paramarine Task Force";
   displayName = "Large - Empty";
   hiddenSelections[] = {
       "camo",
       "camo_signs"};
   hiddenSelectionsTextures[] = {};
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
   class TransportMagazines{};
   class Transportweapons{};
   class TransportItems{};
};

class PTF_Cargo_Large_Ammo : PTF_Large_Box
{
   displayName = "Large - Ammo";
   class TransportMagazines
   {
      mag_xx(rhsusf_100Rnd_762x51_m80a1epr,40);
      mag_xx(rhsusf_200Rnd_556x45_mixed_soft_pouch_coyote,40);
      mag_xx(rhsusf_20Rnd_762x51_SR25_mk316_special_Mag,40);
      mag_xx(PTF_Mag_556x45_Mk262_Stanag_Mix,200);
      mag_xx(SmokeShellBlue,20);
      mag_xx(SmokeShellGreen,20);
      mag_xx(SmokeShellPurple,20);
      mag_xx(SmokeShellRed,20);
      mag_xx(SmokeShell,40);
      mag_xx(rhs_mag_m67,40);
      mag_xx(rhs_mag_m433_HEDP,20);
      mag_xx(rhs_mag_M441_HE,20);
      mag_xx(rhs_mag_M397_HET,20);
      mag_xx(rhsusf_mag_6Rnd_M441_HE,20);
      mag_xx(rhsusf_mag_6Rnd_M433_HEDP,20);
      mag_xx(ACE_CTS9,80);
      mag_xx(rhsusf_mag_7x45acp_MHP,40);
      mag_xx(PTF_Mag_762x51_M80A1_EPR_Mix,40);
   };
   class Transportweapons
   {
      weap_xx(rhs_weap_m72a7,20);
      weap_xx(rhs_weap_M136_hp,20);
   };
   class TransportItems
   {
      item_xx(ACE_IR_Strobe_Item,50);
      item_xx(ACE_CableTie,40);
      item_xx(ACE_UAVBattery,10);
   };
   class TransportBackpacks
   {
      backpack_xx(PTF_SSO_Backpack,2);
   };
};

class PTF_Cargo_Large_Launcher: PTF_Large_Box
{
   displayName = "Large - Launcher";
   class TransportMagazines
   {
      mag_xx(rhs_fgm148_magazine_AT,10);
      mag_xx(MRAWS_HEAT_F,10);
      mag_xx(MRAWS_HE_F,20);
      mag_xx(MRAWS_HEAT55_F,20);
      mag_xx(rhs_fim92_mag,20);

   };
   class TransportWeapons
   {
	  weap_xx(rhs_weap_m72a7,20);
     weap_xx(rhs_weap_M136_hp,10);
     weap_xx(rhs_weap_M136,10);
     weap_xx(rhs_weap_M136_hedp,10);
   };
};

class PTF_Cargo_Large_Explosives: PTF_Large_Box
{
   displayName = "Large - Explosives";
   class TransportMagazines
   {
      mag_xx(tsp_breach_popper_mag,50);
      mag_xx(DemoCharge_Remote_Mag,20);
      mag_xx(tsp_breach_package_mag,20);
      mag_xx(rhs_mag_m67,30);
      mag_xx(SmokeShell,30);
      mag_xx(ClaymoreDirectionalMine_Remote_Mag,10);
      mag_xx(SatchelCharge_Remote_Mag,10);
      mag_xx(tsp_breach_block_mag,25);
   };

   class TransportItems
   {
	  item_xx(ACE_Clacker,10);
   };
};

class PTF_Cargo_Large_Medical : PTF_Large_Box
{
   displayName = "Large - Medical";
   class TransportItems
   {
      item_xx(ACE_salineIV_250,30);
      item_xx(ACE_salineIV_500,30);
      item_xx(ACE_salineIV,30);
      item_xx(ACE_tourniquet,50);
      item_xx(ACE_fieldDressing,200);
      item_xx(ACE_quikclot,200);
      item_xx(ACE_elasticBandage,150);
      item_xx(ACE_packingBandage,150);
      item_xx(ACE_epinephrine,50);
      item_xx(ACE_adenosine,40);
      item_xx(ACE_morphine,40);
      item_xx(ACE_bodyBag,10);
      item_xx(ACE_splint,50);
      item_xx(ACE_plasmaIV,30);
      item_xx(ACE_plasmaIV_500,15);
      item_xx(kat_IV_16,30);
      item_xx(kat_Carbonate,30);
      item_xx(kat_Painkiller,30);
      item_xx(kat_EACA,30);
      item_xx(kat_IO_FAST,30);
      item_xx(kat_naloxone,30);
      item_xx(kat_norepinephrine,30);
      item_xx(kat_phenylephrine,30);
      item_xx(kat_TXA,30);
   };
};

class PTF_Cargo_Large_VicBox : PTF_Large_Box
{
   ace_cargo_space = 40;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 5;
   ace_cargo_canload = 1;
   ace_dragging_canCarry = 0;
   ace_dragging_candrag = 0;
   displayName = "Large - VicBox";
  class EventHandlers
   {
      init = "[(_this select 0)] remoteExec ['PTF_fnc_BigVicBox_init', 0, true]";
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
      };
   };
   class TransportItems
   {
      item_xx(ToolKit,6);
   };
};

class PTF_Cargo_Large_Refuel : PTF_Large_Box
{
   ace_dragging_dragPosition[] = {0,2,0};
   AL_ForkAttachpoint[] = {0,0.55,0};
   class VehicleTransport
      {
         class Cargo
         {
            parachuteClass = "B_Parachute_02_F";
            parachuteHeightLimit = 40;
            canBeTransported = 1;
            dimensions[] = {"VTV_Cargo_Base","VTV_Cargo_Corner"};
         };
         class Carrier{};
      };
   displayname = "Large - Refuel";
   ace_cargo_size = 5;
   ace_cargo_canLoad = 1;
   model = "\boxloader_cargo\mdl\boxloader_sixcon_dar.p3d";
   supplyRadius = 10;
   transportRefuel = 200000000;
   ace_refuel_fuelCargo = 100000; // Maximum fuel cargo amount (in liters)
   ace_refuel_hooks[] = {{0,0,0},{0,0,0}}; // Nozzle hooks
};
