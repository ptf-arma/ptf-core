class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		AAV_Driver="AAV_Driver";
		AAV_Gunner="AAV_Gunner";
		AAV_Commander="AAV_Commander";
		AAV_Driver_OUT="AAV_Driver_OUT";
		AAV_Gunner_OUT="AAV_Gunner_OUT";
		AAV_Commander_OUT="AAV_Commander_OUT";
		AAV_Cargo01="AAV_Cargo01";
		AAV_Cargo02="AAV_Cargo02";
		AAV_Cargo03="AAV_Cargo03";
		AAV_Cargo04="AAV_Cargo04";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class Stryker_Dead;
		class KIA_AAV_Driver: DefaultDie
		{
			actions="DeadActions";
			file="\ca\tracked2\AAV\DATA\anim\KIA_AAV_Driver.rtm";
			speed=0.5;
			looped=0;
			terminal=1;
			soundEnabled=0;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
		class AAV_Driver: Crew
		{
			file="\ca\tracked2\AAV\DATA\anim\AAV_Driver.rtm";
			interpolateTo[]=
			{
				"KIA_AAV_Driver",
				1
			};
		};
		class KIA_AAV_Gunner: DefaultDie
		{
			actions="DeadActions";
			file="\ca\tracked2\AAV\DATA\anim\KIA_AAV_Gunner.rtm";
			speed=0.5;
			looped=0;
			terminal=1;
			soundEnabled=0;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
		class AAV_Gunner: Crew
		{
			file="\ca\tracked2\AAV\DATA\anim\AAV_Gunner.rtm";
			interpolateTo[]=
			{
				"KIA_AAV_Gunner",
				1
			};
		};
		class KIA_AAV_Commander: DefaultDie
		{
			actions="DeadActions";
			file="\ca\tracked2\AAV\DATA\anim\KIA_AAV_Commander.rtm";
			speed=0.5;
			looped=0;
			terminal=1;
			soundEnabled=0;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
		class AAV_Commander: Crew
		{
			file="\ca\tracked2\AAV\DATA\anim\AAV_Commander.rtm";
			interpolateTo[]=
			{
				"KIA_AAV_Commander",
				1
			};
		};
		class KIA_AAV_Driver_OUT: DefaultDie
		{
			actions="DeadActions";
			file="\ca\tracked2\AAV\DATA\anim\KIA_AAV_Driver_OUT.rtm";
			speed=0.5;
			looped=0;
			terminal=1;
			soundEnabled=0;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
		class AAV_Driver_OUT: Crew
		{
			file="\ca\tracked2\AAV\DATA\anim\AAV_Driver_OUT.rtm";
			interpolateTo[]=
			{
				"KIA_AAV_Driver_OUT",
				1
			};
		};
		class KIA_AAV_Gunner_OUT: DefaultDie
		{
			actions="DeadActions";
			file="\ca\tracked2\AAV\DATA\anim\KIA_AAV_Gunner_OUT.rtm";
			speed=0.5;
			looped=0;
			terminal=1;
			soundEnabled=0;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
		class AAV_Gunner_OUT: Crew
		{
			file="\ca\tracked2\AAV\DATA\anim\AAV_Gunner_OUT.rtm";
			interpolateTo[]=
			{
				"KIA_AAV_Gunner_OUT",
				1
			};
		};
		class KIA_AAV_Commander_OUT: DefaultDie
		{
			actions="DeadActions";
			file="\ca\tracked2\AAV\DATA\anim\KIA_AAV_Commander_OUT.rtm";
			speed=0.5;
			looped=0;
			terminal=1;
			soundEnabled=0;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
		class AAV_Commander_OUT: Crew
		{
			file="\ca\tracked2\AAV\DATA\anim\AAV_Commander_OUT.rtm";
			interpolateTo[]=
			{
				"KIA_AAV_Commander_OUT",
				1
			};
		};
		class AAV_Cargo01: Crew
		{
			file="\ca\tracked2\AAV\DATA\anim\OutCargoLB.rtm";
			interpolateTo[]=
			{
				"Stryker_Dead",
				1
			};
		};
		class AAV_Cargo02: Crew
		{
			file="\ca\tracked2\AAV\DATA\anim\OutCargoLF.rtm";
			interpolateTo[]=
			{
				"Stryker_Dead",
				1
			};
		};
		class AAV_Cargo03: Crew
		{
			file="\ca\tracked2\AAV\DATA\anim\OutCargoRB.rtm";
			interpolateTo[]=
			{
				"Stryker_Dead",
				1
			};
		};
		class AAV_Cargo04: Crew
		{
			file="\ca\tracked2\AAV\DATA\anim\OutCargoRF.rtm";
			interpolateTo[]=
			{
				"Stryker_Dead",
				1
			};
		};
	};
};
class CfgMovesWomen: CfgMovesBasic
{
	class ManActions
	{
		AAV_Driver="";
		AAV_Gunner="";
		AAV_Commander="";
		AAV_Driver_OUT="";
		AAV_Gunner_OUT="";
		AAV_Commander_OUT="";
		AAV_Cargo01="crew";
		AAV_Cargo02="crew";
		AAV_Cargo03="crew";
		AAV_Cargo04="crew";
	};
};
class DefaultEventhandlers;
class CfgPatches
{
	class CATracked2_AAV
	{
		units[]=
		{
			"AAV",
			"AAV_cutscene"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"CATracked2",
			"CACharacters2"
		};
	};
};
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class FDustEffects_none
{
};
class CfgVehicles
{
	class Land;
	class LandVehicle: Land
	{
	};
	class Tank: LandVehicle
	{
		class Turrets;
	};
	class Tracked_APC: Tank
	{
		class NewTurret;
		class AnimationSources;
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class AAV: Tracked_APC
	{
		scope=2;
		side=1;
		faction="USMC";
		displayName="$STR_DN_AAVP7A1";
		vehicleClass="Armored";
		model="\ca\tracked2\AAV\AAV";
		icon="\ca\tracked2\AAV\data\icomap_AAV_CA.paa";
		picture="\ca\tracked2\AAV\data\AAV_CA.paa";
		mapSize=9;
		accuracy=0.69999999;
		threat[]={1,1,0.30000001};
		armor=210;
		damageResistance=0.01168;
		cost=4000000;
		maxSpeed=72;
		canFloat=1;
		supplyRadius=5;
		wheelCircumference=2.0009999;
		hiddenSelections[]=
		{
			"Camo1",
			"Camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\ca\tracked2\aav\data\aav_ext_co.paa",
			"\ca\tracked2\aav\data\aav_ext2_co.paa"
		};
		crew="USMC_Soldier_Crew";
		cargoAction[]=
		{
			"Stryker_Cargo01"
		};
		typicalCargo[]=
		{
			"USMC_Soldier_Crew",
			"USMC_Soldier_Crew",
			"USMC_Soldier_Crew"
		};
		transportSoldier=19;
		getInAction="GetInHigh";
		getOutAction="GetOutHigh";
		driverAction="AAV_Driver_OUT";
		driverInAction="AAV_Driver";
		driverForceOptics=0;
		commanderUsesPilotView=1;
		driverOpticsModel="\ca\Tracked\optika_tank_driver_west";
		class Exhausts
		{
			class Exhaust1
			{
				position="vyfuk start";
				direction="vyfuk konec";
				effect="ExhaustsEffectBig";
			};
		};
		fireDustEffect="FDustEffects_none";
		insideSoundCoef=0.89999998;
		soundCrash[]=
		{
			"\ca\Tracked\Data\Sound\crash1",
			10,
			1
		};
		soundGear[]=
		{
			"",
			5.6234134e-005,
			1
		};
		soundGetIn[]=
		{
			"ca\SOUNDS\Vehicles\Tracked\Other\int\int-tracked-getin-01",
			0.56234133,
			1
		};
		soundGetOut[]=
		{
			"ca\SOUNDS\Vehicles\Tracked\Other\ext\ext-tracked-getout-01",
			0.56234133,
			1,
			60
		};
		soundEngineOnInt[]=
		{
			"ca\sounds\Vehicles\Tracked\Other\int\int-tracked-start-01",
			0.79432821,
			1
		};
		soundEngineOnExt[]=
		{
			"ca\SOUNDS\Vehicles\Tracked\Other\ext\ext-tracked-start-01",
			0.79432821,
			1,
			400
		};
		soundEngineOffInt[]=
		{
			"ca\sounds\vehicles\Tracked\Other\int\int-tracked-stop-02.wss",
			0.79432821,
			1
		};
		soundEngineOffExt[]=
		{
			"ca\sounds\vehicles\Tracked\Other\ext\ext-tracked-stop-02.wss",
			0.79432821,
			0.80000001,
			400
		};
		buildCrash0[]=
		{
			"Ca\sounds\Vehicles\Crash\tank_building_01",
			0.70794576,
			1,
			150
		};
		buildCrash1[]=
		{
			"Ca\sounds\Vehicles\Crash\tank_building_02",
			0.70794576,
			1,
			150
		};
		buildCrash2[]=
		{
			"Ca\sounds\Vehicles\Crash\tank_building_03",
			0.70794576,
			1,
			150
		};
		buildCrash3[]=
		{
			"Ca\sounds\Vehicles\Crash\tank_building_04",
			0.70794576,
			1,
			150
		};
		soundBuildingCrash[]=
		{
			"buildCrash0",
			0.25,
			"buildCrash1",
			0.25,
			"buildCrash2",
			0.25,
			"buildCrash3",
			0.25
		};
		WoodCrash0[]=
		{
			"Ca\sounds\Vehicles\Crash\tank_wood_01",
			0.70794576,
			1,
			150
		};
		WoodCrash1[]=
		{
			"Ca\sounds\Vehicles\Crash\tank_wood_02",
			0.70794576,
			1,
			150
		};
		WoodCrash2[]=
		{
			"Ca\sounds\Vehicles\Crash\tank_wood_03",
			0.70794576,
			1,
			150
		};
		WoodCrash3[]=
		{
			"Ca\sounds\Vehicles\Crash\tank_wood_04",
			0.70794576,
			1,
			150
		};
		soundWoodCrash[]=
		{
			"woodCrash0",
			0.25,
			"woodCrash1",
			0.25,
			"woodCrash2",
			0.25,
			"woodCrash3",
			0.25
		};
		ArmorCrash0[]=
		{
			"Ca\sounds\Vehicles\Crash\tank_vehicle_01",
			0.70794576,
			1,
			150
		};
		ArmorCrash1[]=
		{
			"Ca\sounds\Vehicles\Crash\tank_vehicle_02",
			0.70794576,
			1,
			150
		};
		ArmorCrash2[]=
		{
			"Ca\sounds\Vehicles\Crash\tank_vehicle_03",
			0.70794576,
			1,
			150
		};
		ArmorCrash3[]=
		{
			"Ca\sounds\Vehicles\Crash\tank_vehicle_04",
			0.70794576,
			1,
			150
		};
		soundArmorCrash[]=
		{
			"ArmorCrash0",
			0.25,
			"ArmorCrash1",
			0.25,
			"ArmorCrash2",
			0.25,
			"ArmorCrash3",
			0.25
		};
		class SoundEvents
		{
			class AccelerationIn
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\int\int-tracked-acce-02",
					1.2589254,
					1
				};
				limit="0.15";
				expression="engineOn*(1-camPos)*2*gmeterZ*((speed factor[1.5, 5]) min (speed factor[5, 1.5]))";
			};
			class AccelerationOut
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\ext\ext-tracked-acce-02",
					1.2589254,
					1,
					700
				};
				limit="0.15";
				expression="engineOn*camPos*2*gmeterZ*((speed factor[1.5, 5]) min (speed factor[5, 1.5]))";
			};
		};
		class Sounds
		{
			class Engine
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\ext\ext-tracked-engine-03",
					1.4125376,
					1,
					1000
				};
				frequency="(randomizer*0.05+0.8)*rpm";
				volume="engineOn*camPos*(rpm factor[0.6, 0.9])";
			};
			class IdleOut
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\ext\ext-tracked-idle-02",
					0.56234133,
					1,
					350
				};
				frequency="1";
				volume="engineOn*camPos*(rpm factor[0.7, 0.2])";
			};
			class NoiseOut
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\ext\noise2",
					1,
					1,
					150
				};
				frequency="1";
				volume="camPos*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class ThreadsOutH0
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_hard_01",
					1,
					1,
					400
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*((rpm factor[0.3, 0.6]) min (rpm factor[0.6, 0.3]))";
			};
			class ThreadsOutH1
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_hard_02",
					1.2589254,
					1,
					400
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*((rpm factor[0.5, 0.8]) min (rpm factor[0.8, 0.5]))";
			};
			class ThreadsOutH2
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_hard_03",
					1.4125376,
					1,
					400
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*((rpm factor[0.65, 0.9]) min (rpm factor[0.9, 0.65]))";
			};
			class ThreadsOutH3
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_hard_04",
					1.5848932,
					1,
					400
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*((rpm factor[0.8, 1.2]) min (rpm factor[1.2, 0.8]))";
			};
			class ThreadsOutH4
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_hard_05",
					1.7782794,
					1,
					400
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*((rpm factor[1, 2.0]) min (rpm factor[2.0, 1]))";
			};
			class ThreadsOutS0
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_soft_01",
					1,
					1,
					300
				};
				frequency="1";
				volume="engineOn*camPos*grass*((rpm factor[0.3, 0.6]) min (rpm factor[0.6, 0.3]))";
			};
			class ThreadsOutS1
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_soft_02",
					1.1220185,
					1,
					300
				};
				frequency="1";
				volume="engineOn*camPos*grass*((rpm factor[0.5, 0.8]) min (rpm factor[0.8, 0.5]))";
			};
			class ThreadsOutS2
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_soft_03",
					1.2589254,
					1,
					300
				};
				frequency="1";
				volume="engineOn*camPos*grass*((rpm factor[0.65, 0.9]) min (rpm factor[0.9, 0.65]))";
			};
			class ThreadsOutS3
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_soft_04",
					1.4125376,
					1,
					300
				};
				frequency="1";
				volume="engineOn*camPos*grass*((rpm factor[0.8, 1.2]) min (rpm factor[1.2, 0.8]))";
			};
			class ThreadsOutS4
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_soft_05",
					1.7782794,
					1,
					300
				};
				frequency="1";
				volume="engineOn*camPos*grass*((rpm factor[1, 2.0]) min (rpm factor[2.0, 1]))";
			};
			class Movement
			{
				sound[]=
				{
					"",
					1,
					1
				};
				frequency="0";
				volume="0";
			};
			class EngineIn
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\int\int-tracked-engine-03",
					1,
					1
				};
				frequency="(randomizer*0.05+0.8)*rpm";
				volume="engineOn*(1-camPos)*(rpm factor[0.4, 1])";
			};
			class IdleIn
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\int\int-tracked-idle-02",
					0.63095737,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(rpm factor[0.6, 0.15])";
			};
			class NoiseIn
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\int\noise2",
					0.19952624,
					1
				};
				frequency="1";
				volume="(1-camPos)*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class ThreadsInH0
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_hard_01",
					1,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*((rpm factor[0.3, 0.6]) min (rpm factor[0.6, 0.3]))";
			};
			class ThreadsInH1
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_hard_02",
					1.1220185,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*((rpm factor[0.5, 0.8]) min (rpm factor[0.8, 0.5]))";
			};
			class ThreadsInH2
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_hard_03",
					1.2589254,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*((rpm factor[0.65, 0.9]) min (rpm factor[0.9, 0.65]))";
			};
			class ThreadsInH3
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_hard_04",
					1.4125376,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*((rpm factor[0.8, 1.2]) min (rpm factor[1.2, 0.8]))";
			};
			class ThreadsInH4
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_hard_05",
					1.5848932,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*((rpm factor[1, 2.0]) min (rpm factor[2.0, 1]))";
			};
			class ThreadsInS0
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_soft_01",
					1,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*((rpm factor[0.3, 0.6]) min (rpm factor[0.6, 0.3]))";
			};
			class ThreadsInS1
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_soft_02",
					1.1220185,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*((rpm factor[0.5, 0.8]) min (rpm factor[0.8, 0.5]))";
			};
			class ThreadsInS2
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_soft_03",
					1.2589254,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*((rpm factor[0.65, 0.9]) min (rpm factor[0.9, 0.65]))";
			};
			class ThreadsInS3
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_soft_04",
					1.4125376,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*((rpm factor[0.8, 1.2]) min (rpm factor[1.2, 0.8]))";
			};
			class ThreadsInS4
			{
				sound[]=
				{
					"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_soft_05",
					1.5848932,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*((rpm factor[1, 2.0]) min (rpm factor[2.0, 1]))";
			};
		};
		viewDriverShadow=1;
		viewGunnerShadow=1;
		viewCargoShadow=1;
		viewCargoShadowDiff=0.050000001;
		viewDriverShadowDiff=0.050000001;
		viewGunnerShadowDiff=0.050000001;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				castGunnerShadow=1;
				viewGunnerShadow=1;
				weapons[]=
				{
					"MK19",
					"M2"
				};
				magazines[]=
				{
					"48Rnd_40mm_MK19",
					"48Rnd_40mm_MK19",
					"48Rnd_40mm_MK19",
					"48Rnd_40mm_MK19",
					"100Rnd_127x99_M2",
					"100Rnd_127x99_M2",
					"100Rnd_127x99_M2",
					"100Rnd_127x99_M2"
				};
				gunnerForceOptics=1;
				gunnerAction="AAV_Gunner_OUT";
				gunnerInAction="AAV_Gunner";
				selectionFireAnim="zasleh_1";
				memoryPointGun="machinegun";
				gunnerOpticsModel="\ca\Tracked\optika_stryker_gunner";
				gunnerOpticsEffect[]=
				{
					"TankGunnerOptics1"
				};
				gunnerOutOpticsEffect[]={};
				gunnerOutOpticsModel="";
				class Turrets
				{
				};
				class GunFire: WeaponCloudsMGun
				{
					interval=0.0099999998;
				};
				class ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.2;
					minFov=0.057999998;
					maxFov=0.2;
				};
				outGunnerMayFire=1;
				startEngine=0;
				stabilizedInAxes=0;
			};
			class CommanderOptics: NewTurret
			{
				proxyType="CPCommander";
				proxyIndex=1;
				gunnerName="$STR_POSITION_COMMANDER";
				primaryGunner=0;
				primaryObserver=1;
				gunnerForceOptics=0;
				body="ObsTurret";
				gun="ObsGun";
				animationSourceBody="obsTurret";
				animationSourceGun="obsGun";
				gunnerAction="AAV_Commander_OUT";
				gunnerInAction="AAV_Commander";
				soundServo[]=
				{
					"",
					0.0031622776,
					1
				};
				gunBeg="";
				gunEnd="";
				commanding=2;
				gunnerOpticsModel="\ca\weapons\2Dscope_com2";
				gunnerOpticsColor[]={1,1,1,1};
				gunnerOutOpticsModel="";
				gunnerOutOpticsShowCursor=0;
				memoryPointGunnerOutOptics="commander_weapon_view";
				memoryPointGunnerOptics="commanderview";
				memoryPointsGetInGunner="pos commander";
				memoryPointsGetInGunnerDir="pos commander dir";
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				animationSourceHatch="hatchCommander";
				minElev=-10;
				maxElev=35;
				initElev=0;
				minTurn=-360;
				maxTurn=360;
				initTurn=0;
				weapons[]=
				{
					"SmokeLauncher"
				};
				magazines[]=
				{
					"SmokeLauncherMag",
					"SmokeLauncherMag"
				};
				outGunnerMayFire=1;
				class ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.46599999;
					minFov=0.46599999;
					maxFov=0.46599999;
				};
				startEngine=0;
				stabilizedInAxes=0;
			};
		};
		class AnimationSources: AnimationSources
		{
			class plate_front
			{
				source="user";
				animPeriod=3;
				initPhase=0;
			};
			class turbine_cover_left: plate_front
			{
			};
			class turbine_cover_right: plate_front
			{
			};
		};
		class EventHandlers: DefaultEventhandlers
		{
			init="_scr = _this execVM ""\ca\Data\ParticleEffects\SCRIPTS\init.sqf"";_this execVM ""\ca\tracked2\AAV\scripts\init.sqf""";
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"ca\tracked2\aav\data\aav_ext.rvmat",
				"ca\tracked2\aav\data\aav_ext_damage.rvmat",
				"ca\tracked2\aav\data\aav_ext_destruct.rvmat",
				"ca\tracked2\aav\data\aav_ext2.rvmat",
				"ca\tracked2\aav\data\aav_ext2_damage.rvmat",
				"ca\tracked2\aav\data\aav_ext2_destruct.rvmat",
				"ca\tracked2\aav\data\aav_tracks.rvmat",
				"ca\tracked2\aav\data\aav_tracks_damage.rvmat",
				"ca\tracked2\aav\data\aav_tracks_destruct.rvmat"
			};
		};
		class Library
		{
			libTextDesc="$STR_LIB_AAVP7A1";
		};
		smokeLauncherGrenadeCount=4;
		smokeLauncherVelocity=14;
		smokeLauncherOnTurret=1;
		smokeLauncherAngle=90;
	};
	class AAV_cutscene: AAV
	{
		scope=1;
		transportSoldier=4;
		model="\ca\tracked2\AAV\AAV02";
		cargoAction[]=
		{
			"AAV_Cargo01",
			"AAV_Cargo03",
			"AAV_Cargo02",
			"AAV_Cargo04"
		};
		crewVulnerable=1;
		ejectDeadCargo=1;
		class AnimationSources: AnimationSources
		{
			class hide_bikes
			{
				source="user";
				animPeriod=0.001;
				initPhase=1;
			};
		};
	};
};
