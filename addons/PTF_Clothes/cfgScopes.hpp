//RHS
class PTF_Infantry_Weapon_Scope_M8541A : rhsusf_acc_premier_mrds
{
   scope = 2;
   scopeCurator = 2;
   scopeArsenal = 2;
   displayName = "M8541A SSDS (MRDS) [PTF]";
   baseWeapon = "M8541A SSDS (MRDS) [PTF]";
   author = "Paramarine Task Force";
   editorCategory = "EdCat_WeaponAttachments";
   editorSubcategory = "EdSubcat_TopSlot_Optics";
   vehicleClass = "WeaponAccessories";
   weaponInfoType = "RscWeaponZeroing";
   model="\rhsusf\addons\rhsusf_weapons\acc\scopes\ph_5_25x_56mm\prem_scope_pt";
   class ItemInfo : InventoryOpticsItem_Base_F
   {
      opticType = 2;
      mass = 14;
      RMBhint = "Optical Sniper Sight + Night Vision Device";
      optics = 1;
      modelOptics = "\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_prem_mildot3";
      class OpticsModes
      {
         class pso1_nvg
         {
            opticsID = 2;
            useModelOptics = 1;
            opticsPPEffects[] = {"OpticsCHAbera1", "OpticsBlur1", "TankCommanderOptics1"};
            discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800};
            discreteDistanceInitIndex = 1;
            opticsZoomMax = "0.25/3";
            opticsZoomMin = "0.25/15";
            opticsZoomInit = "0.25/3";
            discretefov[] = {"0.25/3", "0.25/6", "0.25/9", "0.25/12", "0.25/15"};
            discreteInitIndex = 0;
            modelOptics[] = {"\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_prem_mildot3", "\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_prem_mildot6", "\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_prem_mildot9", "\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_prem_mildot12", "\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_prem_mildot15"};
            memoryPointCamera = "opticView";
            visionMode[] = {"Normal", "NVG"};
            opticsFlare = 1;
            opticsDisablePeripherialVision = 1;
            distanceZoomMin = 200;
            distanceZoomMax = 1800;
            cameraDir = "";
         };
         class Mrds
         {
            opticsID=2;
            useModelOptics=0;
            opticsPPEffects[]=
            {
               ""
            };
            opticsZoomMin=0.27500001;
            opticsZoomMax=1.1;
            opticsZoomInit=0.75;
            memoryPointCamera="eye";
            visionMode[]={};
            opticsFlare=0;
            opticsDisablePeripherialVision=0;
            distanceZoomMin=200;
            distanceZoomMax=200;
            cameraDir="";
         };
      };
   };
};
