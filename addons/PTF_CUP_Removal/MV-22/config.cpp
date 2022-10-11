class DefaultEventhandlers;
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		F35B_Pilot="F35B_Pilot";
		SU25_Pilot="SU25_Pilot";
		MV22_Pilot="MV22_Pilot";
		MV22_Cargo="MV22_Cargo";
		C130_Pilot="C130_Pilot";
		C130_Cargo="C130_Cargo";
		KA52_Pilot="KA52_Pilot";
		KA52_Gunner="KA52_Gunner";
		UH1Y_Pilot="UH1Y_Pilot";
		UH1Y_Gunner="UH1Y_Gunner";
		UH1Y_Gunner02="UH1Y_Gunner02";
		UH1Y_Cargo01="UH1Y_Cargo01";
		UH1Y_Cargo02="UH1Y_Cargo02";
		UH1Y_Cargo03="UH1Y_Cargo03";
		HIND_Pilot="HIND_Pilot";
		HIND_Gunner="HIND_Gunner";
		HIND_Cargo="HIND_Cargo";
		UH1Y_CUT_H01="UH1Y_CUT_H01";
		UH1Y_CUT_H02="UH1Y_CUT_H02";
		UH1Y_CUT_H03="UH1Y_CUT_H03";
		UH1Y_CUT_H04="UH1Y_CUT_H04";
		UH1Y_CUT_H05="UH1Y_CUT_H05";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class KIA_F35B_Pilot: DefaultDie
		{
			actions="DeadActions";
			file="\ca\air2\F35B\DATA\anim\KIA_F35B_Pilot.rtm";
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
		class F35B_Pilot: Crew
		{
			file="\ca\air2\F35B\DATA\anim\F35B_Pilot.rtm";
			interpolateTo[]=
			{
				"KIA_F35B_Pilot",
				1
			};
		};
		class KIA_SU25_Pilot: DefaultDie
		{
			actions="DeadActions";
			file="\ca\air2\SU25\DATA\anim\SU25PilotKIA.rtm";
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
		class SU25_Pilot: Crew
		{
			file="\ca\air2\SU25\DATA\anim\SU25Pilot.rtm";
			interpolateTo[]=
			{
				"KIA_SU25_Pilot",
				1
			};
		};
		class KIA_MV22_Pilot: DefaultDie
		{
			actions="DeadActions";
			file="\ca\air2\MV22\DATA\anim\KIA_MV22_Pilot.rtm";
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
		class MV22_Pilot: Crew
		{
			file="\ca\air2\MV22\DATA\anim\MV22_Pilot.rtm";
			interpolateTo[]=
			{
				"KIA_MV22_Pilot",
				1
			};
		};
		class KIA_MV22_Cargo: KIA_MV22_Pilot
		{
		};
		class MV22_Cargo: Crew
		{
			file="\ca\air2\MV22\DATA\anim\MV22_Pilot.rtm";
			interpolateTo[]=
			{
				"KIA_MV22_Cargo",
				1
			};
		};
		class KIA_C130_Pilot: DefaultDie
		{
			actions="DeadActions";
			file="\ca\air2\C130J\DATA\anim\C130pilotKIA.rtm";
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
		class C130_Pilot: Crew
		{
			file="\ca\air2\C130J\DATA\anim\C130Pilot.rtm";
			interpolateTo[]=
			{
				"KIA_C130_Pilot",
				1
			};
		};
		class KIA_C130_Cargo: KIA_C130_Pilot
		{
		};
		class C130_Cargo: Crew
		{
			file="\ca\air2\C130J\DATA\anim\C130Pilot.rtm";
			interpolateTo[]=
			{
				"KIA_C130_Cargo",
				1
			};
		};
		class KIA_KA52_Pilot: DefaultDie
		{
			actions="DeadActions";
			file="\ca\air2\KA52\DATA\anim\kia_ka52_pilot.rtm";
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
		class KA52_Pilot: Crew
		{
			file="\ca\air2\KA52\DATA\anim\ka52_pilot.rtm";
			interpolateTo[]=
			{
				"KIA_KA52_Pilot",
				1
			};
		};
		class KIA_KA52_Gunner: KIA_KA52_Pilot
		{
		};
		class KA52_Gunner: KA52_Pilot
		{
			interpolateTo[]=
			{
				"KIA_KA52_Gunner",
				1
			};
		};
		class KIA_UH1Y_Pilot: DefaultDie
		{
			actions="DeadActions";
			file="\CA\air2\UH1Y\data\Anim\KIA_UH1Y_Pilot.rtm";
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
		class UH1Y_Pilot: Crew
		{
			file="\CA\air2\UH1Y\data\Anim\UH1Y_Pilot.rtm";
			interpolateTo[]=
			{
				"KIA_UH1Y_Pilot",
				1
			};
		};
		class KIA_UH1Y_Gunner: DefaultDie
		{
			actions="DeadActions";
			file="\CA\air2\UH1Y\data\Anim\KIA_UH1Y_Gunner01.rtm";
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
		class UH1Y_Gunner: Crew
		{
			file="\CA\air2\UH1Y\data\Anim\UH1Y_Gunner.rtm";
			interpolateTo[]=
			{
				"KIA_UH1Y_Gunner",
				1
			};
		};
		class KIA_UH1Y_Gunner02: DefaultDie
		{
			actions="DeadActions";
			file="\CA\air2\UH1Y\data\Anim\KIA_UH1Y_Pilot.rtm";
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
		class UH1Y_Gunner02: Crew
		{
			file="\CA\air2\UH1Y\data\Anim\UH1Y_Pilot.rtm";
			interpolateTo[]=
			{
				"KIA_UH1Y_Gunner02",
				1
			};
		};
		class KIA_UH1Y_Cargo01: DefaultDie
		{
			actions="DeadActions";
			file="\ca\air2\UH1Y\data\Anim\KIA_cargo_01.rtm";
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
		class UH1Y_Cargo01: Crew
		{
			file="\ca\air2\UH1Y\data\Anim\cargo_01.rtm";
			interpolateTo[]=
			{
				"KIA_UH1Y_Cargo01",
				0.1
			};
			connectTo[]=
			{
				"UH1Y_Cargo01",
				0.30000001,
				"UH1Y_Cargo01_V1",
				0.1,
				"UH1Y_Cargo01_V2",
				0.1,
				"UH1Y_Cargo01_V3",
				0.1
			};
			equivalentTo="UH1Y_Cargo01";
			variantsAI[]=
			{
				"UH1Y_Cargo01",
				0.40000001,
				"UH1Y_Cargo01_V1",
				0.2,
				"UH1Y_Cargo01_V2",
				0.2,
				"UH1Y_Cargo01_V3",
				0.2
			};
			variantAfter[]={5,10,20};
			speed=0.30000001;
		};
		class UH1Y_Cargo01_V1: UH1Y_Cargo01
		{
			file="\ca\air2\UH1Y\data\Anim\cargo_01nadech.rtm";
			interpolateTo[]=
			{
				"KIA_UH1Y_Cargo01",
				1
			};
			connectTo[]=
			{
				"UH1Y_Cargo01",
				0.1
			};
			speed=0.39500001;
			looped=0;
			variantAfter[]={5,5,5};
		};
		class UH1Y_Cargo01_V2: UH1Y_Cargo01_V1
		{
			file="\ca\air2\UH1Y\data\Anim\cargo_01poposed.rtm";
			speed=0.588;
		};
		class UH1Y_Cargo01_V3: UH1Y_Cargo01_V1
		{
			file="\ca\air2\UH1Y\data\Anim\cargo_01presunruky.rtm";
			speed=0.491;
		};
		class KIA_UH1Y_Cargo02: KIA_UH1Y_Cargo01
		{
			file="\ca\air2\UH1Y\data\Anim\KIA_cargo_02.rtm";
		};
		class UH1Y_Cargo02: Crew
		{
			file="\ca\air2\UH1Y\data\Anim\cargo_02.rtm";
			interpolateTo[]=
			{
				"KIA_UH1Y_Cargo02",
				0.1
			};
			connectTo[]=
			{
				"UH1Y_Cargo02",
				0.30000001,
				"UH1Y_Cargo02_V1",
				0.1,
				"UH1Y_Cargo02_V2",
				0.1,
				"UH1Y_Cargo02_V3",
				0.1
			};
			equivalentTo="UH1Y_Cargo02";
			variantsAI[]=
			{
				"UH1Y_Cargo02",
				0.40000001,
				"UH1Y_Cargo02_V1",
				0.2,
				"UH1Y_Cargo02_V2",
				0.2,
				"UH1Y_Cargo02_V3",
				0.2
			};
			variantAfter[]={5,10,20};
			speed=0.30000001;
		};
		class UH1Y_Cargo02_V1: UH1Y_Cargo02
		{
			file="\ca\air2\UH1Y\data\Anim\cargo_02poposed.rtm";
			interpolateTo[]=
			{
				"KIA_UH1Y_Cargo02",
				1
			};
			connectTo[]=
			{
				"UH1Y_Cargo02",
				0.1
			};
			speed=0.65200001;
			looped=0;
			variantAfter[]={5,5,5};
		};
		class UH1Y_Cargo02_V2: UH1Y_Cargo02_V1
		{
			file="\ca\air2\UH1Y\data\Anim\cargo_02predklon.rtm";
			speed=0.3125;
		};
		class UH1Y_Cargo02_V3: UH1Y_Cargo02_V1
		{
			file="\ca\air2\UH1Y\data\Anim\cargo_02presunruky.rtm";
			speed=0.37;
		};
		class KIA_UH1Y_Cargo03: KIA_UH1Y_Cargo01
		{
			file="\ca\air2\UH1Y\data\Anim\KIA_cargo_03.rtm";
		};
		class UH1Y_Cargo03: Crew
		{
			file="\ca\air2\UH1Y\data\Anim\cargo_03.rtm";
			interpolateTo[]=
			{
				"KIA_UH1Y_Cargo03",
				0.1
			};
			connectTo[]=
			{
				"UH1Y_Cargo03",
				0.30000001,
				"UH1Y_Cargo03_V1",
				0.1,
				"UH1Y_Cargo03_V2",
				0.1,
				"UH1Y_Cargo03_V3",
				0.1
			};
			equivalentTo="UH1Y_Cargo03";
			variantsAI[]=
			{
				"UH1Y_Cargo03",
				0.40000001,
				"UH1Y_Cargo03_V1",
				0.1,
				"UH1Y_Cargo03_V2",
				0.25,
				"UH1Y_Cargo03_V3",
				0.25
			};
			variantAfter[]={5,10,20};
			speed=0.30000001;
		};
		class UH1Y_Cargo03_V1: UH1Y_Cargo03
		{
			file="\ca\air2\UH1Y\data\Anim\cargo_03predklon.rtm";
			interpolateTo[]=
			{
				"KIA_UH1Y_Cargo03",
				1
			};
			connectTo[]=
			{
				"UH1Y_Cargo03",
				0.1
			};
			speed=0.37;
			looped=0;
			variantAfter[]={5,5,5};
		};
		class UH1Y_Cargo03_V2: UH1Y_Cargo03_V1
		{
			file="\ca\air2\UH1Y\data\Anim\cargo_03presunruky.rtm";
			speed=0.37;
			variantAfter[]={5,5,5};
		};
		class UH1Y_Cargo03_V3: UH1Y_Cargo03_V1
		{
			file="\ca\air2\UH1Y\data\Anim\cargo_03protazenizad.rtm";
			speed=0.491;
			variantAfter[]={5,5,5};
		};
		class KIA_HIND_Pilot: DefaultDie
		{
			actions="DeadActions";
			speed=0.5;
			looped=0;
			terminal=1;
			file="\ca\air2\Mi35\Data\Anim\KIA_Mi35_Pilot.rtm";
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
		class HIND_Pilot: Crew
		{
			file="\ca\air2\Mi35\Data\Anim\Mi35_Pilot.rtm";
			interpolateTo[]=
			{
				"KIA_HIND_Pilot",
				1
			};
		};
		class KIA_HIND_Gunner: DefaultDie
		{
			actions="DeadActions";
			speed=0.5;
			looped=0;
			terminal=1;
			file="\ca\air2\Mi35\Data\Anim\KIA_Mi35_Gunner.rtm";
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
		class HIND_Gunner: Crew
		{
			file="\ca\air2\Mi35\Data\Anim\Mi35_Gunner.rtm";
			interpolateTo[]=
			{
				"KIA_HIND_Gunner",
				1
			};
		};
		class KIA_HIND_Cargo: DefaultDie
		{
			actions="DeadActions";
			file="\ca\wheeled\Data\Anim\KIA_Skodovka_Cargo01.rtm";
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
		class HIND_Cargo: Crew
		{
			file="\ca\wheeled\Data\Anim\UAZ_Cargo03.rtm";
			interpolateTo[]=
			{
				"KIA_HIND_Cargo",
				0.1
			};
		};
		class UH1Y_CUT_H01_Loop: Crew
		{
			file="\ca\air2\UH1Y\data\Anim\c1_heliflight_h1_loop.rtm";
			interpolateTo[]=
			{
				"KIA_UH1Y_Cargo01",
				1
			};
			speed=0.070257999;
			head="headNo";
		};
		class UH1Y_CUT_H01: Crew
		{
			file="\ca\air2\UH1Y\data\Anim\c1_heliflight_h1.rtm";
			looped=0;
			speed=0.0082989996;
			connectTo[]=
			{
				"UH1Y_CUT_H01_Loop",
				0.1
			};
			variantsAI[]=
			{
				"UH1Y_CUT_H01_Loop",
				1
			};
			variantAfter[]={5,10,20};
			head="headNo";
		};
		class UH1Y_CUT_H02_Loop: Crew
		{
			file="\ca\air2\UH1Y\data\Anim\c1_heliflight_h2_loop.rtm";
			interpolateTo[]=
			{
				"KIA_UH1Y_Cargo01",
				1
			};
			speed=0.103093;
			head="headNo";
		};
		class UH1Y_CUT_H02: Crew
		{
			file="\ca\air2\UH1Y\data\Anim\c1_heliflight_h2.rtm";
			looped=0;
			speed=0.0088050002;
			connectTo[]=
			{
				"UH1Y_CUT_H02_Loop",
				0.1
			};
			variantsAI[]=
			{
				"UH1Y_CUT_H02_Loop",
				1
			};
			variantAfter[]={5,10,20};
			head="headNo";
		};
		class UH1Y_CUT_H03_Loop: Crew
		{
			file="\ca\air2\UH1Y\data\Anim\c1_heliflight_h3_loop.rtm";
			interpolateTo[]=
			{
				"KIA_UH1Y_Cargo01",
				1
			};
			speed=0.119522;
			head="headNo";
		};
		class UH1Y_CUT_H03: Crew
		{
			file="\ca\air2\UH1Y\data\Anim\c1_heliflight_h3.rtm";
			looped=0;
			speed=0.0089389998;
			connectTo[]=
			{
				"UH1Y_CUT_H03_Loop",
				0.1
			};
			variantsAI[]=
			{
				"UH1Y_CUT_H03_Loop",
				1
			};
			variantAfter[]={5,10,20};
			head="headNo";
		};
		class UH1Y_CUT_H04_Loop: Crew
		{
			file="\ca\air2\UH1Y\data\Anim\c1_heliflight_h4_loop.rtm";
			interpolateTo[]=
			{
				"KIA_UH1Y_Cargo01",
				1
			};
			speed=0.062762;
			head="headNo";
		};
		class UH1Y_CUT_H04: Crew
		{
			file="\ca\air2\UH1Y\data\Anim\c1_heliflight_h4.rtm";
			looped=0;
			speed=0.0086059999;
			connectTo[]=
			{
				"UH1Y_CUT_H04_Loop",
				0.1
			};
			variantsAI[]=
			{
				"UH1Y_CUT_H04_Loop",
				1
			};
			variantAfter[]={5,10,20};
			head="headNo";
		};
		class UH1Y_CUT_H05_Loop: Crew
		{
			file="\ca\air2\UH1Y\data\Anim\c1_heliflight_h5_loop.rtm";
			interpolateTo[]=
			{
				"KIA_UH1Y_Cargo01",
				1
			};
			speed=0.114943;
			head="headNo";
		};
		class UH1Y_CUT_H05: Crew
		{
			file="\ca\air2\UH1Y\data\Anim\c1_heliflight_h5.rtm";
			looped=0;
			speed=0.0086930003;
			connectTo[]=
			{
				"UH1Y_CUT_H05_Loop",
				0.1
			};
			variantsAI[]=
			{
				"UH1Y_CUT_H05_Loop",
				1
			};
			variantAfter[]={5,10,20};
			head="headNo";
		};
	};
};
class CfgMovesWomen: CfgMovesBasic
{
	class ManActions
	{
		F35B_Pilot="";
		SU25_Pilot="";
		MV22_Pilot="";
		MV22_Cargo="Crew";
		C130_Pilot="";
		C130_Cargo="Crew";
		KA52_Pilot="";
		KA52_Gunner="";
		UH1Y_Pilot="";
		UH1Y_Gunner="";
		UH1Y_Gunner02="";
		UH1Y_Cargo01="Crew";
		UH1Y_Cargo02="Crew";
		UH1Y_Cargo03="Crew";
		HIND_Pilot="";
		HIND_Gunner="";
		HIND_Cargo="Crew";
		UH1Y_CUT_H01="";
		UH1Y_CUT_H02="";
		UH1Y_CUT_H03="";
		UH1Y_CUT_H04="";
		UH1Y_CUT_H05="";
	};
};
class CfgPatches
{
	class CAAir2
	{
		units[]=
		{
			"Mi24_P",
			"Mi24_V",
			"Mi24_D"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"CAAir",
			"CAWeapons",
			"CACharacters2",
			"CA_Anims_Char"
		};
	};
};
class CfgVehicles
{
	class AllVehicles;
	class Car;
	class Air: AllVehicles
	{
		class NewTurret;
		irScanRangeMin=500;
		class ViewPilot;
	};
	class Helicopter: Air
	{
		class HitPoints
		{
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
		};
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class HitPoints;
			};
		};
		class ViewPilot: ViewPilot
		{
		};
		class AnimationSources;
	};
	class Plane: Air
	{
		class ViewPilot: ViewPilot
		{
		};
		class EventHandlers;
	};
	class ParachuteBase: Helicopter
	{
		class ViewPilot: ViewPilot
		{
		};
		class Turrets
		{
		};
		class EventHandlers;
	};
	class Mi24_Base: Helicopter
	{
		destrType="DestructWreck";
		scope=0;
		picture="\ca\air2\data\UI\Picture_mi24_CA.paa";
		icon="\ca\air2\data\UI\Icon_mi24_CA.paa";
		mapSize=20;
		accuracy=0.5;
		memoryPointGun="machinegun_2";
		weapons[]={};
		magazines[]={};
		model="\ca\air2\Mi35\mi24_v.p3d";
		displayName="$STR_DN_MI24";
		vehicleClass="Air";
		memoryPointLMissile="Missile_1";
		memoryPointRMissile="Missile_2";
		memoryPointLRocket="Rocket_1";
		memoryPointRRocket="Rocket_2";
		transportMaxBackpacks=10;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				body="mainTurret";
				gun="mainGun";
				minElev=-60;
				maxElev=20;
				initElev=0;
				minTurn=-60;
				maxTurn=60;
				initTurn=0;
				soundServo[]=
				{
					"",
					0.0099999998,
					1
				};
				memoryPointGun="machinegun";
				gunBeg="muzzle_1";
				gunEnd="chamber_1";
				weapons[]=
				{
					"YakB",
					"AT6Launcher",
					"S8Launcher"
				};
				magazines[]=
				{
					"1470Rnd_127x108_YakB",
					"4Rnd_AT6_Mi24V",
					"80Rnd_80mm"
				};
				gunnerName="$STR_POSITION_GUNNER";
				gunnerOpticsModel="\ca\weapons\2Dscope_HINDgun";
				gunnerOpticsEffect[]=
				{
					"TankGunnerOptics1"
				};
				gunnerAction="HIND_Gunner";
				gunnerInAction="HIND_Gunner";
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				primaryGunner=1;
				class ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.155;
					minFov=0.046999998;
					maxFov=0.155;
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class Gatling_1
			{
				source="revolving";
				weapon="YakB";
			};
			class Doors
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
		};
		class HitPoints: HitPoints
		{
			class HitGlass1: HitGlass1
			{
				armor=5;
			};
			class HitGlass2: HitGlass2
			{
				armor=0.5;
			};
			class HitGlass3: HitGlass3
			{
				armor=5;
			};
			class HitGlass4: HitGlass4
			{
				armor=0.5;
			};
		};
		armor=33;
		damageResistance=0.00138;
		irScanRangeMin=0;
		irScanRangeMax=1000;
		nightVision=1;
		driverAction="HIND_Pilot";
		driverInAction="HIND_Pilot";
		cargoAction[]=
		{
			"HIND_Cargo"
		};
		getInAction="GetInHigh";
		getOutAction="GetOutHigh";
		transportSoldier=8;
		crew="RU_Soldier_Pilot";
		typicalCargo[]=
		{
			"RU_Soldier_Pilot",
			"RU_Soldier_Pilot",
			"RU_Soldier_AT",
			"RU_Soldier_AT"
		};
		transportAmmo=0;
		transportMaxMagazines=150;
		transportMaxWeapons=30;
		supplyRadius=2.5;
		initCargoAngleY=10;
		minCargoAngleY=-60;
		maxCargoAngleY=120;
		gunnerUsesPilotView=0;
		cargoIsCoDriver[]={0,0};
		driverCanSee=31;
		gunnerCanSee=31;
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"ca\air2\mi35\data\mi35_sklo.rvmat",
				"ca\air2\mi35\data\mi35_sklo_damage.rvmat",
				"ca\air2\mi35\data\mi35_sklo_damage.rvmat",
				"ca\air2\mi35\data\mi35_sklo_interier.rvmat",
				"ca\air2\mi35\data\mi35_sklo_interier_damage.rvmat",
				"ca\air2\mi35\data\mi35_sklo_interier_damage.rvmat",
				"ca\air2\mi35\data\mi35_001.rvmat",
				"ca\air2\mi35\data\mi35_001_damage.rvmat",
				"ca\air2\mi35\data\mi35_001_destruct.rvmat",
				"ca\air2\mi35\data\mi35_002.rvmat",
				"ca\air2\mi35\data\mi35_002_damage.rvmat",
				"ca\air2\mi35\data\mi35_002_destruct.rvmat",
				"ca\air2\mi35\data\mi35_003.rvmat",
				"ca\air2\mi35\data\mi35_003_damage.rvmat",
				"ca\air2\mi35\data\mi35_003_destruct.rvmat"
			};
		};
		hiddenSelections[]=
		{
			"Camo1",
			"Camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\ca\air2\mi35\data\mi24v_001_co.paa",
			"\ca\air2\mi35\data\mi24v_002_co.paa"
		};
		dammageHalf[]={};
		dammageFull[]={};
		viewDriverShadow=1;
		viewGunnerShadow=1;
		viewCargoShadow=1;
		gearRetracting=1;
		gearUpTime=1;
		gearDownTime=1;
		maxSpeed=310;
		mainRotorSpeed=1.2;
		backRotorSpeed=6.0999999;
		memoryPointsGetInCargo[]=
		{
			"pos cargo"
		};
		memoryPointsGetInCargoDir[]=
		{
			"pos cargo dir"
		};
		soundGetIn[]=
		{
			"ca\sounds\Air\Mi17\ext\ext-Mi17-getin-01",
			1,
			1
		};
		soundGetOut[]=
		{
			"ca\sounds\Air\Mi17\ext\ext-Mi17-getout-01",
			1,
			1,
			40
		};
		soundEnviron[]=
		{
			"",
			0.031622775,
			1
		};
		soundDammage[]=
		{
			"ca\sounds\Air\Mi17\int\alarm_loop1",
			0.0005623413,
			1
		};
		soundEngineOnInt[]=
		{
			"ca\sounds\Air\Mi17\int\int-Mi17-start-1a",
			0.56234133,
			1
		};
		soundEngineOnExt[]=
		{
			"ca\sounds\Air\Mi17\ext\ext-Mi17-start-01a",
			0.79432821,
			1,
			700
		};
		soundEngineOffInt[]=
		{
			"ca\sounds\Air\Mi17\int\int-Mi17-stop-1a",
			0.56234133,
			1
		};
		soundEngineOffExt[]=
		{
			"ca\sounds\Air\Mi17\ext\ext-Mi17-stop-01a",
			0.79432821,
			1,
			700
		};
		class Sounds
		{
			class Engine
			{
				sound[]=
				{
					"ca\sounds\air\Mi17\ext\ext-sovietheli-engine-6",
					5.6234131,
					1,
					900
				};
				frequency="rotorSpeed";
				volume="camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[]=
				{
					"ca\sounds\air\Mi17\ext\ext-Mi17-rotor-low-2",
					1.7782794,
					1,
					1400
				};
				frequency="rotorSpeed";
				volume="camPos*(0 max (rotorSpeed-0.1))";
				cone[]={1.6,3.1400001,2,0.94999999};
			};
			class RotorHighOut
			{
				sound[]=
				{
					"ca\sounds\air\Mi17\ext\ext-Mi17-rotor-high-2",
					3.1622777,
					1,
					1650
				};
				frequency="rotorSpeed";
				volume="camPos*10*(0 max (rotorThrust-0.9))";
				cone[]={1.6,3.1400001,2,0.94999999};
			};
			class EngineIn
			{
				sound[]=
				{
					"ca\sounds\air\Mi17\int\int-sovietheli-engine-3",
					1,
					1
				};
				frequency="rotorSpeed";
				volume="(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[]=
				{
					"ca\sounds\air\Mi17\int\int-Mi17-rotor-low-2",
					1.7782794,
					1
				};
				frequency="rotorSpeed";
				volume="(1-camPos)*(0 max (rotorSpeed-0.1))";
			};
			class RotorHighIn
			{
				sound[]=
				{
					"ca\sounds\air\Mi17\int\int-Mi17-rotor-high-2",
					1.7782794,
					1
				};
				frequency="rotorSpeed";
				volume="(1-camPos)*3*(rotorThrust-0.9)";
			};
		};
		class Reflectors
		{
			class Left
			{
				color[]={0.80000001,0.80000001,1,1};
				ambient[]={0.07,0.07,0.07,1};
				position="L svetlo";
				direction="L svetlo konec";
				hitpoint="L svetlo";
				selection="L svetlo";
				size=1;
				brightness=1;
			};
		};
		minFireTime=30;
		threat[]={0.80000001,1,0.60000002};
		class UserActions
		{
			class OpenRdoor
			{
				displayName="$STR_AM_OPENRDOOR";
				position="right cargo door";
				radius=1.6;
				onlyForplayer=0;
				condition="this animationPhase ""dvere_p_vrch"" < 0.5 && (getpos this select 2) < 3 && (speed this < 3) AND Alive(this)";
				statement="[this] exec ""ca\air2\Mi35\data\scripts\rdoorop.sqs""";
			};
			class CloseRdoor
			{
				displayName="$STR_AM_CLOSERDOOR";
				position="right cargo door";
				radius=1.6;
				onlyForplayer=0;
				condition="this animationPhase ""dvere_p_vrch"" > 0.5 AND Alive(this)";
				statement="[this] exec ""ca\air2\Mi35\data\scripts\rdoorcl.sqs""";
			};
			class OpenLdoor
			{
				displayName="$STR_AM_OPENLDOOR";
				position="left cargo door";
				radius=1.6;
				onlyForplayer=0;
				condition="this animationPhase ""dvere_l_vrch"" < 0.5 && (getpos this select 2) < 3 && (speed this < 3) AND Alive(this)";
				statement="[this] exec ""ca\air2\Mi35\data\scripts\ldoorop.sqs""";
			};
			class CloseLdoor
			{
				displayName="$STR_AM_CLOSELDOOR";
				position="left cargo door";
				radius=1.6;
				onlyForplayer=0;
				condition="this animationPhase ""dvere_l_vrch"" > 0.5 AND Alive(this)";
				statement="[this] exec ""ca\air2\Mi35\data\scripts\ldoorcl.sqs""";
			};
		};
	};
	class Mi24_Base_RU: Mi24_Base
	{
		accuracy=1.5;
		side=0;
		faction="RU";
	};
	class Mi24_Base_CDF: Mi24_Base
	{
		accuracy=1.5;
		side=1;
		faction="CDF";
	};
	class Mi24_V: Mi24_Base_RU
	{
		scope=2;
		accuracy=1000;
		displayName="$STR_DN_MI24V";
		class Library
		{
			libTextDesc="$STR_LIB_MI24_V";
		};
	};
	class Mi24_P: Mi24_Base_RU
	{
		scope=2;
		accuracy=1000;
		model="\ca\air2\Mi35\mi24_p.p3d";
		displayName="$STR_DN_MI24P";
		vehicleClass="Air";
		class Library
		{
			libTextDesc="$STR_LIB_MI24_P";
		};
		weapons[]={};
		magazines[]={};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				body="";
				gun="";
				weapons[]=
				{
					"GSh302",
					"AT9Launcher",
					"HeliBombLauncher",
					"80mmLauncher"
				};
				magazines[]=
				{
					"750Rnd_30mm_GSh301",
					"4Rnd_AT9_Mi24P",
					"2Rnd_FAB_250",
					"40Rnd_80mm"
				};
			};
		};
		hiddenSelectionsTextures[]=
		{
			"\ca\air2\mi35\data\mi24p_001_co.paa",
			"\ca\air2\mi35\data\mi24p_002_co.paa"
		};
		class Viewoptics
		{
			initAngleX=0;
			minAngleX=0;
			maxAngleX=0;
			initAngleY=0;
			minAngleY=0;
			maxAngleY=0;
			initFov=1;
			minFov=0.2;
			maxFov=1.2;
		};
		class AnimationSources: AnimationSources
		{
			class Gatling_1
			{
			};
			class Doors;
		};
	};
	class Mi24_D: Mi24_Base_CDF
	{
		scope=2;
		accuracy=1000;
		model="\ca\air2\Mi35\mi35.p3d";
		displayName="$STR_DN_MI24D";
		vehicleClass="Air";
		crew="CDF_Soldier_Pilot";
		typicalCargo[]=
		{
			"LDF_Soldier_Pilot",
			"LDF_Soldier_Pilot",
			"LDF_Soldier_AR",
			"LDF_Soldier_RPG",
			"LDF_Soldier"
		};
		hiddenSelectionsTextures[]=
		{
			"\ca\air2\mi35\data\mi35_001_co.paa",
			"\ca\air2\mi35\data\mi35_002_co.paa"
		};
		weapons[]={};
		magazines[]={};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[]=
				{
					"YakB",
					"AT2Launcher",
					"57mmLauncher_128"
				};
				magazines[]=
				{
					"1470Rnd_127x108_YakB",
					"4Rnd_AT2_Mi24D",
					"128Rnd_57mm"
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class Gatling_1;
			class Doors;
		};
		class Library
		{
			libTextDesc="$STR_LIB_MI24_D";
		};
	};
	class HelicopterWreck;
	class PlaneWreck;
	class SU25Wreck: PlaneWreck
	{
		scope=1;
		class Armory
		{
			disabled=1;
		};
		model="\ca\air2\Su25\Su25Wreck.p3d";
		class Eventhandlers
		{
		};
	};
	class Mi24Wreck: HelicopterWreck
	{
		model="\ca\air2\Mi35\Mi24Wreck.p3d";
		scope=1;
		class Armory
		{
			disabled=1;
		};
		class Eventhandlers
		{
		};
	};
	class F35bWreck: PlaneWreck
	{
		model="\ca\air2\F35B\F35bWreck.p3d";
		scope=1;
		class Armory
		{
			disabled=1;
		};
		class Eventhandlers
		{
		};
	};
	class MQ9PredatorWreck: PlaneWreck
	{
		model="\ca\air2\MQ9PredatorB\MQ9PredatorWreck.p3d";
		scope=1;
		class Armory
		{
			disabled=1;
		};
		class Eventhandlers
		{
		};
	};
	class MV22Wreck: PlaneWreck
	{
		model="\ca\air2\MV22\MV22Wreck.p3d";
		scope=1;
		class Armory
		{
			disabled=1;
		};
		class Eventhandlers
		{
		};
	};
	class C130JWreck: PlaneWreck
	{
		model="\ca\air2\C130J\C130JWreck.p3d";
		scope=1;
		class Armory
		{
			disabled=1;
		};
		class Eventhandlers
		{
		};
	};
	class Ka52Wreck: HelicopterWreck
	{
		model="\ca\air2\Ka52\Ka52Wreck.p3d";
		scope=1;
		class Armory
		{
			disabled=1;
		};
		class Eventhandlers
		{
		};
	};
	class UH1YWreck: HelicopterWreck
	{
		model="\ca\air2\UH1Y\UH1YWreck.p3d";
		scope=1;
		class Armory
		{
			disabled=1;
		};
		class Eventhandlers
		{
		};
	};
};
