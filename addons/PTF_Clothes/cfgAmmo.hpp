

class PTF_Training_Ammo : BulletBase
{
   cartridge = "RHS_Cartridge_556x45_m855";
   hit = 0.01;
   typicalSpeed = 960; //value for 20 inch barrel (calculated from M16)
   airFriction = -0.000772;
   caliber = 0.65;
   deflecting = 21;
   visibleFire = 3;
   audibleFire = 7;
};
class PTF_Training_Ammo_Red : PTF_Training_Ammo
{
   tracerColor[] =
       {
           Red};
};
class PTF_Training_Ammo_Blue : PTF_Training_Ammo
{
   tracerColor[] =
       {
           Blue};
};
class PTF_Training_Rocket : BulletCore
{
   class CamShakeFire
   {
      power = 30;
      duration = 0.5;
      frequency = 20;
      distance = 30;
   };
   class CamShakePlayerFire
   {
      power = 0.06;
      duration = 0.1;
      frequency = 20;
   };
   class CamShakeHit
   {
      power = 100;
      duration = 1;
      frequency = 20;
   };
   audibleFire = 15.0;
   hit = 0;
};