class PTF_Training_Ammo : BulletCore
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
   audibleFire = 5.0;
   hit = 0;
   indirectHit = 0;
   maxSpeed = 241;
   model = "\ca\weapons\bullet";
   sideAirFriction = 0.5;
   class HitEffects
   {
      vehicle = "ImpactMetal";
      object = "ImpactConcrete";
   };
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