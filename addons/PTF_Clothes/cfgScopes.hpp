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

class PTF_Infantry_Weapon_Scope_Accu: Scot_Trij_Accu
{
   scope=2;
   displayName="GSM Trijicon AccuPower";
   author="Scotty_Z";
   picture="\a3\Weapons_F\acc\Data\UI\icon_optic_DMS_ca.paa";
   model="\Scottys_LPVO\Trij_Accu\Trij_Accu.p3d";
   descriptionShort="Trijicon AccuPower 1-8x Magnification";
   weaponInfoType="RscWeaponZeroing";
   ACE_ScopeAdjust_Vertical[]={-14.5,14.5};
   ACE_ScopeAdjust_Horizontal[]={-14.5,14.5};
   ACE_ScopeAdjust_VerticalIncrement=0.1;
   ACE_ScopeAdjust_HorizontalIncrement=0.1;
   class ItemInfo: InventoryOpticsItem_Base_F
   {
      mass=14;
      RMBhint="1-8x28 Low Power Variable Optic";
      opticType=2;
      optics=1;
      modelOptics="\A3\Weapons_f_beta\acc\reticle_MRCO_F";
      memoryPointCamera="eye";
      class OpticsModes
      {
         class Snip
         {
            opticsID=1;
            useModelOptics=1;
            opticsPPEffects[]=
            {
               "OpticsCHAbera5",
               "OpticsBlur5"
            };
            opticsFlare=1;
            opticsDisablePeripherialVision=1;
            opticsZoomMin="0.249/8";
            opticsZoomMax="0.249/1";
            opticsZoomInit="0.249/1";
            discretefov[]=
            {
               "0.249/1",
               "0.249/2",
               "0.249/3",
               "0.249/4",
               "0.249/5",
               "0.249/6",
               "0.249/7",
               "0.249/8"
            };
            discreteInitIndex=0;
            memoryPointCamera="opticView";
            modelOptics[]=
            {
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_1.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_2.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_3.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_4.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_5.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_6.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_7.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_8.p3d"
            };
            discretedistance[]={100};
            discreteDistanceInitIndex=0;
            visionMode[] = {"Normal"};
            distanceZoomMin=100;
            distanceZoomMax=100;
            cameraDir="";
         };
         class RMR
         {
            opticsID=2;
            useModelOptics=0;
            opticsPPEffects[]=
            {
               ""
            };
            opticsFlare=0;
            opticsDisablePeripherialVision=0;
            opticsZoomMin=0.25;
            opticsZoomMax=1.25;
            opticsZoomInit=0.75;
            memoryPointCamera="eye2";
            visionMode[]={};
            distanceZoomMin=100;
            distanceZoomMax=100;
            cameraDir="";
         };
      };
   };
};

class PTF_Infantry_Weapon_Scope_Accu_RMR: Scot_Trij_Accu_RMR
{
   scope=2;
   displayName="GSM Trijicon AccuPower (RMR)";
   author="Scotty_Z";
   picture="\a3\Weapons_F\acc\Data\UI\icon_optic_DMS_ca.paa";
   model="\Scottys_LPVO\Trij_Accu\Trij_Accu_RMR.p3d";
   descriptionShort="Trijicon AccuPower 1-8x Magnification";
   weaponInfoType="RscWeaponZeroing";
   ACE_ScopeAdjust_Vertical[]={-14.5,14.5};
   ACE_ScopeAdjust_Horizontal[]={-14.5,14.5};
   ACE_ScopeAdjust_VerticalIncrement=0.1;
   ACE_ScopeAdjust_HorizontalIncrement=0.1;
   class ItemInfo: InventoryOpticsItem_Base_F
   {
      mass=14;
      RMBhint="1-8x28 Low Power Variable Optic";
      opticType=2;
      optics=1;
      modelOptics="\A3\Weapons_f_beta\acc\reticle_MRCO_F";
      memoryPointCamera="eye";
      class OpticsModes
      {
         class Snip
         {
            opticsID=1;
            useModelOptics=1;
            opticsPPEffects[]=
            {
               "OpticsCHAbera5",
               "OpticsBlur5"
            };
            opticsFlare=1;
            opticsDisablePeripherialVision=1;
            opticsZoomMin="0.249/8";
            opticsZoomMax="0.249/1";
            opticsZoomInit="0.249/1";
            discretefov[]=
            {
               "0.249/1",
               "0.249/2",
               "0.249/3",
               "0.249/4",
               "0.249/5",
               "0.249/6",
               "0.249/7",
               "0.249/8"
            };
            discreteInitIndex=0;
            memoryPointCamera="opticView";
            modelOptics[]=
            {
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_1.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_2.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_3.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_4.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_5.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_6.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_7.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_8.p3d"
            };
            discretedistance[]={100};
            discreteDistanceInitIndex=0;
            visionMode[] = {"Normal"};
            distanceZoomMin=100;
            distanceZoomMax=100;
            cameraDir="";
         };
         class RMR
         {
            opticsID=2;
            useModelOptics=0;
            opticsPPEffects[]=
            {
               ""
            };
            opticsFlare=0;
            opticsDisablePeripherialVision=0;
            opticsZoomMin=0.25;
            opticsZoomMax=1.25;
            opticsZoomInit=0.75;
            memoryPointCamera="eye2";
            visionMode[]={};
            distanceZoomMin=100;
            distanceZoomMax=100;
            cameraDir="";
         };
      };
   };
};

class PTF_Infantry_Weapon_Scope_Accu_RMRCant: Scot_Trij_Accu_RMR_Top_Canted
{
   scope=2;
   displayName="GSM Trijicon AccuPower (RMR Top Canted)";
   author="Scotty_Z";
   picture="\a3\Weapons_F\acc\Data\UI\icon_optic_DMS_ca.paa";
   model="\Scottys_LPVO\Trij_Accu\Trij_Accu_RMR_TOP45.p3d";
   descriptionShort="Trijicon AccuPower 1-8x Magnification";
   weaponInfoType="RscWeaponZeroing";
   ACE_ScopeAdjust_Vertical[]={-14.5,14.5};
   ACE_ScopeAdjust_Horizontal[]={-14.5,14.5};
   ACE_ScopeAdjust_VerticalIncrement=0.1;
   ACE_ScopeAdjust_HorizontalIncrement=0.1;
   class ItemInfo: InventoryOpticsItem_Base_F
   {
      mass=14;
      RMBhint="1-8x28 Low Power Variable Optic";
      opticType=2;
      optics=1;
      modelOptics="\A3\Weapons_f_beta\acc\reticle_MRCO_F";
      memoryPointCamera="eye";
      class OpticsModes
      {
         class Snip
         {
            opticsID=1;
            useModelOptics=1;
            opticsPPEffects[]=
            {
               "OpticsCHAbera5",
               "OpticsBlur5"
            };
            opticsFlare=1;
            opticsDisablePeripherialVision=1;
            opticsZoomMin="0.249/8";
            opticsZoomMax="0.249/1";
            opticsZoomInit="0.249/1";
            discretefov[]=
            {
               "0.249/1",
               "0.249/2",
               "0.249/3",
               "0.249/4",
               "0.249/5",
               "0.249/6",
               "0.249/7",
               "0.249/8"
            };
            discreteInitIndex=0;
            memoryPointCamera="opticView";
            modelOptics[]=
            {
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_1.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_2.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_3.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_4.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_5.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_6.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_7.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_8.p3d"
            };
            discretedistance[]={100};
            discreteDistanceInitIndex=0;
            visionMode[]={"Normal"};
            distanceZoomMin=100;
            distanceZoomMax=100;
            cameraDir="";
         };
         class RMR
         {
            opticsID=2;
            useModelOptics=0;
            opticsPPEffects[]=
            {
               ""
            };
            opticsFlare=0;
            opticsDisablePeripherialVision=0;
            opticsZoomMin=0.25;
            opticsZoomMax=1.25;
            opticsZoomInit=0.75;
            memoryPointCamera="eye2";
            visionMode[]={};
            distanceZoomMin=100;
            distanceZoomMax=100;
            cameraDir="";
         };
      };
   };
};

class PTF_Infantry_Weapon_Scope_Accu_T1: Scot_Trij_Accu_T1
{
   scope=2;
   displayName="GSM Trijicon AccuPower (T1)";
   author="Scotty_Z";
   picture="\a3\Weapons_F\acc\Data\UI\icon_optic_DMS_ca.paa";
   model="\Scottys_LPVO\Trij_Accu\Trij_Accu_T1.p3d";
   descriptionShort="Trijicon AccuPower 1-8x Magnification";
   weaponInfoType="RscWeaponZeroing";
   ACE_ScopeAdjust_Vertical[]={-14.5,14.5};
   ACE_ScopeAdjust_Horizontal[]={-14.5,14.5};
   ACE_ScopeAdjust_VerticalIncrement=0.1;
   ACE_ScopeAdjust_HorizontalIncrement=0.1;
   class ItemInfo: InventoryOpticsItem_Base_F
   {
      mass=14;
      RMBhint="1-8x28 Low Power Variable Optic";
      opticType=2;
      optics=1;
      modelOptics="\A3\Weapons_f_beta\acc\reticle_MRCO_F";
      memoryPointCamera="eye";
      class OpticsModes
      {
         class Snip
         {
            opticsID=1;
            useModelOptics=1;
            opticsPPEffects[]=
            {
               "OpticsCHAbera5",
               "OpticsBlur5"
            };
            opticsFlare=1;
            opticsDisablePeripherialVision=1;
            opticsZoomMin="0.249/8";
            opticsZoomMax="0.249/1";
            opticsZoomInit="0.249/1";
            discretefov[]=
            {
               "0.249/1",
               "0.249/2",
               "0.249/3",
               "0.249/4",
               "0.249/5",
               "0.249/6",
               "0.249/7",
               "0.249/8"
            };
            discreteInitIndex=0;
            memoryPointCamera="opticView";
            modelOptics[]=
            {
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_1.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_2.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_3.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_4.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_5.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_6.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_7.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_8.p3d"
            };
            discretedistance[]={100};
            discreteDistanceInitIndex=0;
            visionMode[]={"Normal"};
            distanceZoomMin=100;
            distanceZoomMax=100;
            cameraDir="";
         };
         class RMR
         {
            opticsID=2;
            useModelOptics=0;
            opticsPPEffects[]=
            {
               ""
            };
            opticsFlare=0;
            opticsDisablePeripherialVision=0;
            opticsZoomMin=0.25;
            opticsZoomMax=1.25;
            opticsZoomInit=0.75;
            memoryPointCamera="eye2";
            visionMode[]={};
            distanceZoomMin=100;
            distanceZoomMax=100;
            cameraDir="";
         };
      };
   };
};

class PTF_Infantry_Weapon_Scope_Accu_T2: Scot_Trij_Accu_T2
{
   scope=2;
   displayName="GSM Trijicon AccuPower (T2)";
   author="Scotty_Z";
   picture="\a3\Weapons_F\acc\Data\UI\icon_optic_DMS_ca.paa";
   model="\Scottys_LPVO\Trij_Accu\Trij_Accu_T2.p3d";
   descriptionShort="Trijicon AccuPower 1-8x Magnification";
   weaponInfoType="RscWeaponZeroing";
   ACE_ScopeAdjust_Vertical[]={-14.5,14.5};
   ACE_ScopeAdjust_Horizontal[]={-14.5,14.5};
   ACE_ScopeAdjust_VerticalIncrement=0.1;
   ACE_ScopeAdjust_HorizontalIncrement=0.1;
   class ItemInfo: InventoryOpticsItem_Base_F
   {
      mass=14;
      RMBhint="1-8x28 Low Power Variable Optic";
      opticType=2;
      optics=1;
      modelOptics="\A3\Weapons_f_beta\acc\reticle_MRCO_F";
      memoryPointCamera="eye";
      class OpticsModes
      {
         class Snip
         {
            opticsID=1;
            useModelOptics=1;
            opticsPPEffects[]=
            {
               "OpticsCHAbera5",
               "OpticsBlur5"
            };
            opticsFlare=1;
            opticsDisablePeripherialVision=1;
            opticsZoomMin="0.249/8";
            opticsZoomMax="0.249/1";
            opticsZoomInit="0.249/1";
            discretefov[]=
            {
               "0.249/1",
               "0.249/2",
               "0.249/3",
               "0.249/4",
               "0.249/5",
               "0.249/6",
               "0.249/7",
               "0.249/8"
            };
            discreteInitIndex=0;
            memoryPointCamera="opticView";
            modelOptics[]=
            {
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_1.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_2.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_3.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_4.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_5.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_6.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_7.p3d",
               "Scottys_LPVO\data\reticles\Trij_Accu_1-8_8.p3d"
            };
            discretedistance[]={100};
            discreteDistanceInitIndex=0;
            visionMode[]={"Normal"};
            distanceZoomMin=100;
            distanceZoomMax=100;
            cameraDir="";
         };
         class RMR
         {
            opticsID=2;
            useModelOptics=0;
            opticsPPEffects[]=
            {
               ""
            };
            opticsFlare=0;
            opticsDisablePeripherialVision=0;
            opticsZoomMin=0.25;
            opticsZoomMax=1.25;
            opticsZoomInit=0.75;
            memoryPointCamera="eye2";
            visionMode[]={};
            distanceZoomMin=100;
            distanceZoomMax=100;
            cameraDir="";
         };
      };
   };
};