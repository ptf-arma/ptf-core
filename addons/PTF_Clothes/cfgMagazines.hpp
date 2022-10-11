//Mixed Maxs 5.56
class PTF_Mag_556x45_Mk262_PMAG_Mix : rhs_mag_30Rnd_556x45_Mk262_PMAG
{
   author = "Paramarine Task Force";
   displayName = "30rnd Mk262 Mod 1 (TE4)";
   tracersEvery = 5;
   displayNameShort = "Mk262 (TE4)";
};
class PTF_Mag_556x45_Mk262_PMAG_Tan_Mix : rhs_mag_30Rnd_556x45_Mk262_PMAG_Tan
{
   author = "Paramarine Task Force";
   displayName = "30rnd Mk262 Mod 1 (TE4)";
   tracersEvery = 5;
   displayNameShort = "Mk262 (TE4)";
};
class PTF_Mag_556x45_M855A1_PMAG_Mix : rhs_mag_30Rnd_556x45_M855A1_PMAG
{
   author = "Paramarine Task Force";
   displayName = "30rnd M855A1 (TE4)";
   tracersEvery = 5;
   displayNameShort = "M855A1 EPR (TE4)";
};
class PTF_Mag_556x45_M855A1_PMAG_Tan_Mix : rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan
{
   author = "Paramarine Task Force";
   displayName = "30rnd M855A1 (TE4)";
   tracersEvery = 5;
   displayNameShort = "M855A1 EPR (TE4)";
};
class PTF_Mag_556x45_Mk318_PMAG_Mix : rhs_mag_30Rnd_556x45_Mk318_PMAG
{
   author = "Paramarine Task Force";
   displayName = "30rnd Mk318 Mod 0 (TE4)";
   tracersEvery = 5;
   displayNameShort = "Mk318 (TE4)";
};
class PTF_Mag_556x45_Mk318_PMAG_Tan_Mix : rhs_mag_30Rnd_556x45_Mk318_PMAG_Tan
{
   author = "Paramarine Task Force";
   displayName = "30rnd Mk318 Mod 0 (TE4)";
   tracersEvery = 5;
   displayNameShort = "Mk318 (TE4)";
};
class PTF_Mag_556x45_Mk318_SCAR_Mix : rhs_mag_30Rnd_556x45_Mk318_SCAR
{
   author = "Paramarine Task Force";
   displayName = "30rnd Mk318 Mod 0 (TE4)";
   tracersEvery = 5;
   displayNameShort = "Mk318 (TE4)";
};
class PTF_Mag_556x45_Mk262_Stanag_Mix : rhs_mag_30Rnd_556x45_Mk262_Stanag
{
   author = "Paramarine Task Force";
   displayName = "30rnd Mk262 Mod 1 (TE4)";
   tracersEvery = 5;
   displayNameShort = "Mk262 (TE4)";
};
class PTF_Mag_556x45_Mk318_Stanag_Mix : rhs_mag_30Rnd_556x45_Mk318_Stanag
{
   author = "Paramarine Task Force";
   displayName = "30rnd Mk318 Mod 0 (TE4)";
   tracersEvery = 5;
   displayNameShort = "Mk318 (TE4)";
};
class PTF_Mag_556x45_M855A1_Stanag_Mix : rhs_mag_30Rnd_556x45_M855A1_Stanag
{
   author = "Paramarine Task Force";
   displayName = "30rnd M855A1 (TE4)";
   tracersEvery = 5;
   displayNameShort = "M855A1 EPR (TE4)";
};
//Mixed Mags 7.62
class PTF_Mag_762x51_MK316_Special_Mix : rhs_mag_20Rnd_SCAR_762x51_mk316_special
{
   author = "Paramarine Task Force";
   displayName = "20rnd Mk316 Mod 0 (TE3)";
   displayNameShort = "Mk316 (TE3)";
   tracersEvery = 4;
};
class PTF_Mag_762x51_M80A1_EPR_Mix : rhs_mag_20Rnd_SCAR_762x51_m80a1_epr
{
   author = "Paramarine Task Force";
   displayName = "20rnd M80A1 EPR (TE3)";
   displayNameShort = "M80A1 EPR (TE3)";
   tracersEvery = 4;
};
//Training Mag 5.56
class PTF_Training_Mag : 30Rnd_556x45_Stanag
{
   displayName = "30rnd M855A1 Training Mag";
   author = "Paramarine Task Force";
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
class PTF_Training_Mag_Red : PTF_Training_Mag
{
   displayName = "30rnd M855A1 Training Mag - Red";
   author = "Paramarine Task Force";
   ammo = "PTF_Training_Ammo_Red";
};
class PTF_Training_Mag_Blue : PTF_Training_Mag
{
   displayName = "30rnd M855A1 Training Mag - Blue";
   author = "Paramarine Task Force";
   ammo = "PTF_Training_Ammo_Blue";
};