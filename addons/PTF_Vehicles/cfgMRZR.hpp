//MRZR4
class PTF_MRZR4 : rhsusf_mrzr4_d
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Cars";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 375;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "MRZR4 [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo", "camo1", "camo2", "camo3", "camomerged", "decal_hood_main", "decal_hood_1", "decal_hood_2", "decal_hood_3", "decal_hood_4", "sticker_mid", "sticker_rear"};
   hiddenSelectionsTextures[] = {
       "\rhsusf\addons\rhsusf_mrzr\data\blue_tan_co.paa", "\rhsusf\addons\rhsusf_mrzr\data\yel_tan_co.paa", "\rhsusf\addons\rhsusf_mrzr\data\red_tan_co.paa", "\rhsusf\addons\rhsusf_mrzr\data\grn_tan_co.paa", "\rhsusf\addons\rhsusf_mrzr\data\merged\orng_tan_co.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class CargoTurret_01 : CargoTurret
      {
         gunnerCompartments = "Compartment1";
         memoryPointsGetInGunner = "pos cargo RF";
         memoryPointsGetInGunnerDir = "pos cargo RF dir";
         gunnerAction = "passenger_inside_1";
         gunnerName = "Passenger (Front Seat)";
         isPersonTurret = 1;
         enableFFVWeaponObstruction = 1;
         proxyIndex = 2;
         class TurnOut
         {
            limitsArrayTop[] = {{28.7267, -86.447}, {26.7899, -30.4307}, {10.0909, -16.9596}, {5.3567, -1.3237}, {3.7548, 54.7238}};
            limitsArrayBottom[] = {{-8.7914, -95.7334}, {-26.2615, -38.6995}, {-24.1625, -23.4721}, {-12.2238, -3.9537}, {-10.9171, 46.5569}, {-8.2158, 49.7788}};
         };
         class TurnIn : TurnOut
         {
         };
         ejectDeadGunner = 0;
         soundAttenuationTurret = "";
         disableSoundAttenuation = 1;
         playerPosition = 2;
         gunnerGetInAction = "ChopperLight_R_In_H";
         gunnergetOutAction = "GetOutLow";
         usePreciseGetInAction = 1;
      };
      class CargoTurret_02 : CargoTurret_01
      {
         gunnerCompartments = "Compartment1";
         canHideGunner = 0;
         gunnerName = "Passenger (Left Seat)";
         gunnerAction = "rhs_mrzr_passenger";
         gunnerInAction = "rhs_mrzr_passenger";
         animationSourceHatch = "FFV_turn_L";
         gunnerLeftLegAnimName = "FFV_LB_LF";
         gunnerRightLegAnimName = "FFV_LB_RF";
         memoryPointsGetInGunner = "pos cargo LB";
         memoryPointsGetInGunnerDir = "pos cargo LB dir";
         proxyIndex = 3;
         class TurnOut
         {
            limitsArrayTop[] = {{35.4526, 63.7415}, {32.4939, 116.493}};
            limitsArrayBottom[] = {{-18.7593, 73.6969}, {-23.6628, 109.831}};
         };
         class TurnIn : TurnOut
         {
         };
         playerPosition = 3;
         gunnerGetInAction = "ChopperLight_L_In_H";
      };
      class CargoTurret_03 : CargoTurret_02
      {
         gunnerCompartments = "Compartment1";
         gunnerName = "Passenger (Right Seat)";
         gunnerAction = "rhs_mrzr_passenger";
         gunnerInAction = "rhs_mrzr_passenger";
         animationSourceHatch = "FFV_turn_R";
         gunnerLeftLegAnimName = "FFV_RB_LF";
         gunnerRightLegAnimName = "FFV_RB_RF";
         memoryPointsGetInGunner = "pos cargo RB";
         memoryPointsGetInGunnerDir = "pos cargo RB dir";
         proxyIndex = 4;
         class TurnOut
         {
            limitsArrayTop[] = {{32.7761, -88.5404}, {34.2324, -49.191}};
            limitsArrayBottom[] = {{-29.9524, -99.7416}, {-16.9604, -47.9381}};
         };
         class TurnIn : TurnOut
         {
         };
         playerPosition = 4;
         gunnerGetInAction = "ChopperLight_R_In_H";
      };
      class CargoTurret_04 : CargoTurret
      {
         gunnerCompartments = "Compartment1";
         gunnerName = "Passenger (Right Seat 2)";
         gunnerAction = "passenger_flatground_2";
         gunnerInAction = "passenger_flatground_2";
         memoryPointsGetInGunner = "pos cargo R";
         memoryPointsGetInGunnerDir = "pos cargo R dir";
         proxyIndex = 5;
         canHideGunner = 0;
         allowLauncherIn = 0;
         allowLauncherOut = 0;
         class TurnIn
         {
            limitsArrayTop[] = {{33.8208, -93.9616}, {40.8906, 66.5705}};
            limitsArrayBottom[] = {{-9.4643, -94.5753}, {-8.3683, -67.6867}, {-9.7173, 43.6372}, {-10.1082, 78.9166}};
         };
         class dynamicViewLimits
         {
            CargoTurret_05[] = {-65, 75};
         };
         playerPosition = 5;
      };
      class CargoTurret_05 : CargoTurret_04
      {
         gunnerCompartments = "Compartment1";
         gunnerName = "Passenger (Left Seat 2)";
         gunnerAction = "passenger_flatground_4";
         gunnerInAction = "passenger_flatground_4";
         proxyIndex = 6;
         class TurnIn
         {
            limitsArrayTop[] = {{37.1488, -71.9003}, {36.4967, 92.2757}};
            limitsArrayBottom[] = {{-22.1832, -70.0989}, {-13.9068, -22.8107}, {-7.1236, 75.6849}, {-7.8564, 102.583}};
         };
         class dynamicViewLimits
         {
            CargoTurret_04[] = {-75, 65};
         };
         playerPosition = 6;
      };
   };
   class textureSources
   {
      class Desert
      {
         displayName = "Desert";
         author = "J.Downs";
         textures[] = {
             "\rhsusf\addons\rhsusf_mrzr\data\blue_tan_co.paa", "\rhsusf\addons\rhsusf_mrzr\data\yel_tan_co.paa", "\rhsusf\addons\rhsusf_mrzr\data\red_tan_co.paa", "\rhsusf\addons\rhsusf_mrzr\data\grn_tan_co.paa", "\rhsusf\addons\rhsusf_mrzr\data\merged\orng_tan_co.paa"};
         decals[] = {};
         factions[] = {};
      };
   };
   class VehicleTransport
   {
      class Cargo
      {
         parachuteClass = "B_Parachute_02_F";
         parachuteHeightLimit = 15;
         canBeTransported = 1;
         dimensions[] = {"BBox_1_1_pos", "BBox_1_2_pos"};
      };
      class Carrier
      {
         cargoBayDimensions[] = {"VVT_cargo_1", "VVT_cargo_2"};
         disableHeightLimit = 1;
         maxLoadMass = 25000;
         cargoAlignment[] = {"left", "front"};
         cargoSpacing[] = {0, 0, 0};
         exits[] = {"VVT_exit"};
         unloadingInterval = 2;
         loadingDistance = 5;
         loadingAngle = 60;
         parachuteClassDefault = "B_Parachute_02_F";
         parachuteHeightLimitDefault = 5;
      };
   };

   class TransportItems : TransportItems
   {
   };
   class TransportBackpacks : TransportBackpacks
   {
   };
   class TransportMagazines : TransportMagazines
   {
   };
   class TransportWeapons : TransportWeapons
   {
   };
};
class PTF_Command_MRZR_HQ : PTF_MRZR4
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Personal";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "MRZR (Unit HQ) [PTF]";

   class TransportItems : TransportItems
   {
   };
   class TransportBackpacks : TransportBackpacks
   {
   };
   class TransportMagazines : TransportMagazines
   {
   };
   class TransportWeapons : TransportWeapons
   {
   };
};
class PTF_Command_MRZR_1ST : PTF_MRZR4
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Personal";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "MRZR (1stPlt HQ) [PTF]";

   class TransportItems : TransportItems
   {
   };
   class TransportBackpacks : TransportBackpacks
   {
   };
   class TransportMagazines : TransportMagazines
   {
   };
   class TransportWeapons : TransportWeapons
   {
   };
};
class PTF_Command_MRZR_2ND : PTF_MRZR4
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Personal";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "MRZR (2ndPlt HQ) [PTF]";

   class TransportItems : TransportItems
   {
   };
   class TransportBackpacks : TransportBackpacks
   {
   };
   class TransportMagazines : TransportMagazines
   {
   };
   class TransportWeapons : TransportWeapons
   {
   };
};
class PTF_Command_MRZR_MAG36 : PTF_MRZR4
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_PersonalAir";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "MRZR (MAG36 HQ) [PTF]";

   class TransportItems : TransportItems
   {
   };
   class TransportBackpacks : TransportBackpacks
   {
   };
   class TransportMagazines : TransportMagazines
   {
   };
   class TransportWeapons : TransportWeapons
   {
   };
};
