class PTF_Training_Ballistic_Mag : 30Rnd_556x45_Stanag
{
   AUTHOR_MACRO
   INVENTORY_PICTURE(rhs_mag_30Rnd_556x45_M855A1_Stanag)
   displayName = "556x45 Training Mag";
   displayNameShort = "M855A1 Training";
   ammo = "PTF_Training_Ammo";
   initSpeed = 960; //3150 ft/s from M16. 2970 ft/s from M4
   mass = 9.35;
   tracersEvery = 1;
   lastRoundsTracer = 0;
   model = rhsusf\addons\rhsusf_weapons\magazines\rhs_stanag_mag;
   modelSpecial = rhsusf\addons\rhsusf_weapons\mag_proxies\rhs_mag_556x45_stanag_usgi_n_30rnd;
   modelSpecialIsProxy = 1;
   hiddenSelections[] = {"camo", "camo01", "camo02"};
   hiddenSelectionsTextures[] =
       {
           "rhsusf\addons\rhsusf_weapons\mag_proxies\data\rhs_30rn_usgi_alum_co.paa",
           "rhsusf\addons\rhsusf_weapons\mag_proxies\data\rhs_556_m885a1_co.paa",
           "rhsusf\addons\rhsusf_weapons\mag_proxies\data\rhs_30rn_magpul_black_co.paa"};
};