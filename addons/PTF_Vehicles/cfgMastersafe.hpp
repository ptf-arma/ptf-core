class PTF_weap_mastersafe : Default
{
   scope = 1;
   displayName = "MASTERSAFE";
   descriptionShort = "MASTERSAFE";
   showToPlayer = 1;
   modes[] = {"this"};
   magazines[] = {};
   minRange = 0;
   minRangeProbab = 0.001;
   midRange = 0.001;
   midRangeProbab = 0.001;
   maxRange = 0.001;
   maxRangeProbab = 0.001;
};

class VehicleMagazine;
class HighROF;
class LowROF;




class PTF_Vlmg_M240_veh : CUP_Vlmg_M240_veh
{
	magazines[]=
	{
		PTF_400rnd_TE1_Red_Tracer_762x51_M240_M
	};
};

class PTF_weap_M242 : CUP_Vacannon_M242_veh
{
	
	muzzles[]=
	{
		"this",
		"CUP_Vacannon_M242_veh_LAV25_SecondaryBin"
	};
	
	displayName="$STR_CUP_DN_M242_PrimaryBin";
	ballisticsComputer=1+16;
	canLock=2;
	discreteDistance[]={600};
	discreteDistanceInitIndex=0;
	FCSZeroingDelay=0.5;
	magazineReloadTime=15;
	magazines[]=
	{
		"CUP_150Rnd_TE1_Red_Tracer_25mm_M242_APDS",
		"CUP_150Rnd_TE1_Red_Tracer_25mm_M242_APFSDS",
		"CUP_150Rnd_TE1_Red_Tracer_25mm_M242_HE"
	};

	class HighROF: HighROF
	{
		displayName="$STR_CUP_DN_M242_PrimaryBin";
		reloadTime = 0.30000002;
		textureType = "fullAuto";
		showToPlayer = 1;
	};
	class LowROF: LowROF
	{
		displayName="$STR_CUP_DN_M242_PrimaryBin";
		reloadTime = 0.60000002;
		textureType = "dual";
		showToPlayer = 1;
	};
	// class Single : LowROF
	// {
		// displayName="$STR_CUP_DN_M242_PrimaryBin";
		// textureType = "semi";
		// reloadTime = 0.30000001;
		// autoFire = false;
		// showToPlayer = 1;
	// };
	
	modes[]={
		//"Single",
		"LowROF",
		"HighROF"
	};
	
	class CUP_Vacannon_M242_veh_LAV25_SecondaryBin: CUP_Vacannon_M242_veh
	{
		displayName="$STR_CUP_DN_M242_SecondaryBin";
		ballisticsComputer=16;
		canLock=2;
		discreteDistance[]={1000};
		discreteDistanceInitIndex=0;
		FCSZeroingDelay=0.5;
		magazineReloadTime=8;
		magazines[]=
		{
			"CUP_60Rnd_TE1_Red_Tracer_25mm_M242_APDS",
			"CUP_60Rnd_TE1_Red_Tracer_25mm_M242_APFSDS",
			"CUP_60Rnd_TE1_Red_Tracer_25mm_M242_HE"
		};


		class HighROF: HighROF
		{
			displayName="$STR_CUP_DN_M242_SecondaryBin";
			reloadTime = 0.30000002;
			textureType = "fullAuto";
			showToPlayer = 1;
		};
		class LowROF: LowROF
		{
			displayName="$STR_CUP_DN_M242_SecondaryBin";
			reloadTime = 0.60000002;
			textureType = "dual";
			showToPlayer = 1;
		};
/* 		class Single : LowROF
		{
			displayName="$STR_CUP_DN_M242_SecondaryBin";
			textureType = "semi";
			reloadTime = 0.30000001;
			autoFire = false;
			showToPlayer = 1; */
		//};
		
		modes[]={
			//"Single",
			"LowROF",
			"HighROF"
		};
		
	};

};

