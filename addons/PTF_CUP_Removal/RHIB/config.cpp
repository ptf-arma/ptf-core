class DefaultEventhandlers;
class CfgPatches
{
	class CAWater
	{
		units[]=
		{
			"Zodiac",
			"RHIB",
			"RHIB2Turret",
			"PBX"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"CAData",
			"CACharacters",
			"CAWeapons",
			"CA_Anims_Char"
		};
	};
};
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		PBX_Driver="PBX_Driver";
		PBX_Cargo01="PBX_Cargo01";
		PBX_Cargo02="PBX_Cargo02";
		PBX_Cargo03="PBX_Cargo03";
		RHIB_Driver="RHIB_Driver";
		RHIB_Gunner="RHIB_Gunner";
		RHIB_Cargo="RHIB_Cargo";
		Zodiac_Driver="Zodiac_Driver";
		Zodiac_Cargo01="Zodiac_Cargo01";
		Zodiac_Cargo02="Zodiac_Cargo02";
		Zodiac_Cargo03="Zodiac_Cargo03";
		Zodiac_Cargo04="Zodiac_Cargo04";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class PBX_Driver: Crew
		{
			file="\ca\water\Data\Anim\PBX_Driver.rtm";
			interpolateTo[]=
			{
				"Zodiac_Dead",
				1
			};
		};
		class PBX_Cargo01: Crew
		{
			file="\ca\water\Data\Anim\PBX_Cargo01.rtm";
			interpolateTo[]=
			{
				"Zodiac_Dead",
				1
			};
		};
		class PBX_Cargo02: Crew
		{
			file="\ca\water\Data\Anim\PBX_Cargo02.rtm";
			interpolateTo[]=
			{
				"Zodiac_Dead",
				1
			};
		};
		class PBX_Cargo03: Crew
		{
			file="\ca\water\Data\Anim\PBX_Cargo03.rtm";
			interpolateTo[]=
			{
				"Zodiac_Dead",
				1
			};
		};
		class KIA_RHIB_Driver: DefaultDie
		{
			file="\ca\water\Data\Anim\KIA_RHIB_Driver.rtm";
			actions="DeadActions";
			speed=0.5;
			looped=0;
			terminal=1;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
		class RHIB_Driver: Crew
		{
			file="\ca\water\Data\Anim\RHIB_Driver.rtm";
			interpolateTo[]=
			{
				"KIA_RHIB_Driver",
				1
			};
		};
		class RHIB_Gunner: Crew
		{
			file="\ca\water\Data\Anim\RHIB_Gunner.rtm";
			interpolateTo[]=
			{
				"Zodiac_Dead",
				1
			};
		};
		class KIA_RHIB_Cargo: DefaultDie
		{
			file="\ca\water\Data\Anim\KIA_RHIB_Cargo.rtm";
			actions="DeadActions";
			speed=0.5;
			looped=0;
			terminal=1;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
		class Zodiac_Dead: KIA_RHIB_Cargo
		{
		};
		class RHIB_Cargo: Crew
		{
			file="\ca\water\Data\Anim\RHIB_Cargo.rtm";
			interpolateTo[]=
			{
				"KIA_RHIB_Cargo",
				1
			};
		};
		class Zodiac_Driver: Crew
		{
			file="\ca\water\Data\Anim\Zodiac_Driver.rtm";
			interpolateTo[]=
			{
				"Zodiac_Dead",
				1
			};
		};
		class Zodiac_Cargo01: Crew
		{
			file="\ca\water\Data\Anim\Zodiac_Cargo01.rtm";
			interpolateTo[]=
			{
				"Zodiac_Dead",
				1
			};
		};
		class Zodiac_Cargo02: Crew
		{
			file="\ca\water\Data\Anim\Zodiac_Cargo02.rtm";
			interpolateTo[]=
			{
				"Zodiac_Dead",
				1
			};
		};
		class Zodiac_Cargo03: Crew
		{
			file="\ca\water\Data\Anim\Zodiac_Cargo03.rtm";
			interpolateTo[]=
			{
				"Zodiac_Dead",
				1
			};
		};
		class Zodiac_Cargo04: Crew
		{
			file="\ca\water\Data\Anim\Zodiac_Cargo04.rtm";
			interpolateTo[]=
			{
				"Zodiac_Dead",
				1
			};
		};
	};
};
class CfgMovesWomen: CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		PBX_Driver="";
		PBX_Cargo01="";
		PBX_Cargo02="";
		PBX_Cargo03="";
		RHIB_Driver="";
		RHIB_Gunner="";
		RHIB_Cargo="";
		Zodiac_Driver="";
		Zodiac_Cargo01="";
		Zodiac_Cargo02="";
		Zodiac_Cargo03="";
		Zodiac_Cargo04="";
	};
};
class CfgVehicles
{
	class All;
	class AllVehicles: All
	{
		class ViewPilot;
	};
	class Ship: AllVehicles
	{
		unitInfoType="UnitInfoCar";
		class HitPoints
		{
			class HitEngine
			{
				armor=1.2;
				material=60;
				name="motor";
				visual="motor";
				passThrough=1;
			};
		};
		class NewTurret;
		class Turrets;
		enableGPS=0;
		getInAction="GetInLow";
		getOutAction="GetOutLow";
		cargoGetInAction[]=
		{
			"GetInLow"
		};
		cargoGetOutAction[]=
		{
			"GetOutLow"
		};
		class MarkerLights
		{
			class RedStill
			{
				name="cerveny pozicni";
				color[]={1,0.1,0.1,1};
				ambient[]={0.1,0.0099999998,0.0099999998,1};
				brightness=0.0099999998;
				blinking=0;
			};
			class GreenStill
			{
				name="zeleny pozicni";
				color[]={0.1,1,0.1,1};
				ambient[]={0.0099999998,0.1,0.0099999998,1};
				brightness=0.0099999998;
				blinking=0;
			};
			class WhiteStill
			{
				name="bily pozicni";
				color[]={1,1,1,1};
				ambient[]={0.1,0.1,0.1,1};
				brightness=0.0099999998;
				blinking=0;
			};
		};
		class ViewPilot: ViewPilot
		{
			initFov=0.69999999;
			minFov=0.25;
			maxFov=1.4;
			initAngleX=0;
			minAngleX=-65;
			maxAngleX=85;
			initAngleY=0;
			minAngleY=-150;
			maxAngleY=150;
		};
		precision=10;
		class Eventhandlers: DefaultEventhandlers
		{
		};
		class DestructionEffects
		{
		};
	};
	class Boat: Ship
	{
		precision=6;
		brakeDistance=20;
	};
	class RHIB: Boat
	{
		scope=2;
		displayName="$STR_DN_RHIB";
		vehicleClass="Ship";
		accuracy=0.5;
		crew="USMC_Soldier";
		faction="USMC";
		side=1;
		model="\ca\water\rhib";
		picture="\ca\water\data\ico\rhib_CA.paa";
		Icon="\Ca\water\Data\map_ico\icomap_RHIB_CA.paa";
		mapSize=8;
		unitInfoType="UnitInfoShip";
		soundEnviron[]=
		{
			"",
			0.056234132,
			0.89999998
		};
		class SoundEvents
		{
		};
		insideSoundCoef=1;
		soundEngineOnInt[]=
		{
			"ca\sounds\vehicles\water\rhib\ext-boat-start-01",
			0.1,
			1
		};
		soundEngineOnExt[]=
		{
			"ca\sounds\vehicles\water\rhib\ext-boat-start-01",
			1,
			1,
			150
		};
		soundEngineOffInt[]=
		{
			"ca\sounds\vehicles\water\rhib\ext-boat-stop-01",
			0.1,
			1
		};
		soundEngineOffExt[]=
		{
			"ca\sounds\vehicles\water\rhib\ext-boat-stop-01",
			1,
			1,
			150
		};
		class Sounds
		{
			class Engine
			{
				sound[]=
				{
					"ca\sounds\vehicles\water\rhib\ext-boat-engine-low-01",
					1,
					0.89999998,
					300
				};
				frequency="(randomizer*0.05+0.95)*rpm";
				volume="engineOn*(rpm factor[0.5, 0.1])";
			};
			class EngineHighOut
			{
				sound[]=
				{
					"ca\sounds\vehicles\water\rhib\ext-boat-engine-high-01",
					1,
					0.80000001,
					300
				};
				frequency="(randomizer*0.05+0.95)*rpm";
				volume="engineOn*(rpm factor[0.4, 1.3])";
			};
			class IdleOut
			{
				sound[]=
				{
					"ca\sounds\vehicles\water\rhib\ext-boat-engine-idle-03",
					0.56234133,
					1,
					150
				};
				frequency="1";
				volume="engineOn*(rpm factor[0.3, 0])";
			};
			class WaternoiseOutW0
			{
				sound[]=
				{
					"ca\sounds\vehicles\water\water_sfx\ext-water-noise-nospeed",
					0.39810717,
					1,
					100
				};
				frequency="1";
				volume="(speed factor[7, 0])";
			};
			class WaternoiseOutW1
			{
				sound[]=
				{
					"ca\sounds\vehicles\water\water_sfx\ext-boat-lospd-noise-02",
					0.39810717,
					1,
					100
				};
				frequency="1";
				volume="((speed factor[2, 12]) min (speed factor[12, 2]))";
			};
			class WaternoiseOutW2
			{
				sound[]=
				{
					"ca\sounds\vehicles\water\water_sfx\ext-boat-hispd-noise-02",
					0.39810717,
					1,
					100
				};
				frequency="1";
				volume="(speed factor[9, 18.7])";
			};
		};
		driverAction="RHIB_Driver";
		cargoAction[]=
		{
			"RHIB_Cargo"
		};
		getInAction="GetInMedium";
		getOutAction="GetOutMedium";
		cargoGetInAction[]=
		{
			"GetInMedium"
		};
		cargoGetOutAction[]=
		{
			"GetOutMedium"
		};
		castDriverShadow=1;
		castCargoShadow=1;
		gunnerHasFlares=0;
		maxSpeed=60;
		enableGPS=1;
		transportSoldier=10;
		typicalCargo[]=
		{
			"USMC_Soldier",
			"USMC_Soldier_AT"
		};
		supplyRadius=3;
		class Exhausts
		{
			class Exhaust1
			{
				position="vyfuk start";
				direction="vyfuk konec";
				effect="";
			};
		};
		class TransportMagazines
		{
			class _xx_30Rnd_556x45_Stanag
			{
				magazine="30Rnd_556x45_Stanag";
				count="30*1";
			};
			class _xx_200Rnd_556x45_M249
			{
				magazine="200Rnd_556x45_M249";
				count="5*1";
			};
			class _xx_HandGrenade_west
			{
				magazine="HandGrenade_west";
				count="10*1";
			};
			class _xx_5Rnd_762x51_M24
			{
				magazine="5Rnd_762x51_M24";
				count="10*1";
			};
			class _xx_15rnd_9x19_M9
			{
				magazine="15rnd_9x19_M9";
				count="15*1";
			};
			class _xx_M136
			{
				magazine="M136";
				count="3*1";
			};
			class _xx_1Rnd_HE_M203
			{
				magazine="1Rnd_HE_M203";
				count="3*1";
			};
		};
		cost=10000;
		armor=30;
		class AnimationSources
		{
			class ReloadAnim
			{
				source="reload";
				weapon="M2";
			};
			class ReloadMagazine
			{
				source="reloadmagazine";
				weapon="M2";
			};
			class Revolving
			{
				source="revolving";
				weapon="M2";
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: NewTurret
			{
				class HitPoints
				{
					class HitTurret
					{
						armor=0.80000001;
						material=60;
						name="vez";
						visual="vez";
						passThrough=1;
					};
					class HitGun
					{
						armor=0.60000002;
						material=60;
						name="zbran";
						visual="zbran";
						passThrough=1;
					};
				};
				stabilizedInAxes=0;
				body="MainTurret";
				gun="MainGun";
				animationSourceBody="mainTurret";
				animationSourceGun="mainGun";
				gunnerAction="RHIB_Gunner";
				gunnerGetInAction="GetInMedium";
				gunnerGetOutAction="GetOutMedium";
				ejectDeadGunner=1;
				outGunnerMayFire=1;
				inGunnerMayFire=0;
				minElev=-25;
				maxElev=60;
				initElev=5;
				minTurn=-135;
				maxTurn=135;
				initTurn=0;
				soundServo[]=
				{
					"\ca\sounds\vehicles\servos\turret-1",
					0.0056234132,
					1
				};
				gunBeg="usti hlavne";
				gunEnd="konec hlavne";
				weapons[]=
				{
					"M2"
				};
				magazines[]=
				{
					"100Rnd_127x99_M2",
					"100Rnd_127x99_M2",
					"100Rnd_127x99_M2"
				};
				gunnerName="$STR_POSITION_FRONTGUNNER";
				gunnerOpticsModel="\ca\weapons\optika_empty";
				gunnerForceOptics=0;
				startEngine=0;
				commanding=2;
				primaryGunner=0;
				primaryObserver=1;
				class ViewOptics
				{
					initAngleX=0;
					minAngleX=-30;
					maxAngleX=30;
					initAngleY=0;
					minAngleY=-100;
					maxAngleY=100;
					initFov=0.69999999;
					minFov=0.25;
					maxFov=1.1;
				};
				class ViewGunner
				{
					initAngleX=5;
					minAngleX=-65;
					maxAngleX=85;
					initAngleY=0;
					minAngleY=-150;
					maxAngleY=150;
					initFov=0.69999999;
					minFov=0.25;
					maxFov=1.1;
				};
			};
		};
		class Library
		{
			libTextDesc="$STR_LIB_RHIB";
		};
		extCameraPosition[]={0,4,-14};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"ca\water\data\rhib.rvmat",
				"ca\water\data\rhib.rvmat",
				"ca\water\data\rhib_destruct.rvmat",
				"ca\water\data\rhib_dash.rvmat",
				"ca\water\data\rhib_dash.rvmat",
				"ca\water\data\rhib_dash_destruct.rvmat"
			};
		};
	};
	class RHIB2Turret: RHIB
	{
		displayName="$STR_DN_RHIB2";
		vehicleClass="Ship";
		model="\ca\water\rhib_gunboat";
		picture="\ca\water\data\ico\rhib_CA.paa";
		Icon="\Ca\water\Data\map_ico\icomap_gunboat_CA.paa";
		mapSize=8;
		transportSoldier=7;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
			};
			class BackTurret: MainTurret
			{
				body="Turret_2";
				gun="Gun_2";
				animationSourceBody="Turret_2";
				animationSourceGun="Gun_2";
				animationSourceHatch="";
				selectionFireAnim="zasleh_1";
				stabilizedInAxes=0;
				proxyIndex=2;
				gunnerName="$STR_POSITION_REARGUNNER";
				commanding=-2;
				gunnerOpticsModel="\ca\weapons\optika_empty";
				minElev=-50;
				maxElev=25;
				initElev=-5;
				minTurn=120;
				maxTurn=240;
				initTurn=180;
				weapons[]=
				{
					"MK19"
				};
				magazines[]=
				{
					"48Rnd_40mm_MK19",
					"48Rnd_40mm_MK19",
					"48Rnd_40mm_MK19",
					"48Rnd_40mm_MK19"
				};
				gunBeg="usti hlavne_1";
				gunEnd="konec hlavne_1";
				primaryGunner=1;
				primaryObserver=0;
				memoryPointGun="kulas_1";
				memoryPointGunnerOptics="gunnerview_1";
			};
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"ca\water\data\rhib.rvmat",
				"ca\water\data\rhib.rvmat",
				"ca\water\data\rhib_destruct.rvmat",
				"ca\water\data\rhib_dash.rvmat",
				"ca\water\data\rhib_dash.rvmat",
				"ca\water\data\rhib_dash_destruct.rvmat"
			};
		};
	};
	class RubberBoat: Boat
	{
		scope=0;
		vehicleClass="Ship";
		accuracy=0.5;
		mapSize=6;
		soundEnviron[]=
		{
			"",
			0.056234132,
			0.94999999
		};
		class SoundEvents
		{
		};
		insideSoundCoef=1;
		soundEngineOnInt[]=
		{
			"\ca\sounds\Vehicles\Water\CRRC_PBX\ext-boat-engine-start-01",
			0.1,
			1
		};
		soundEngineOnExt[]=
		{
			"\ca\sounds\Vehicles\Water\CRRC_PBX\ext-boat-engine-start-01",
			1,
			1,
			100
		};
		soundEngineOffInt[]=
		{
			"ca\sounds\vehicles\Water\CRRC_PBX\ext-boat-engine-stop-01",
			0.1,
			1
		};
		soundEngineOffExt[]=
		{
			"ca\sounds\vehicles\Water\CRRC_PBX\ext-boat-engine-stop-01",
			1,
			1,
			100
		};
		class Sounds
		{
			class Engine
			{
				sound[]=
				{
					"\ca\sounds\Vehicles\Water\CRRC_PBX\ext-boat-engine-low-01",
					1,
					1,
					300
				};
				frequency="(randomizer*0.05+0.95)*rpm";
				volume="engineOn*(thrust factor[0.7, 0.1])";
			};
			class EngineHighOut
			{
				sound[]=
				{
					"\ca\sounds\Vehicles\Water\CRRC_PBX\ext-boat-engine-high-01",
					1,
					0.80000001,
					400
				};
				frequency="(randomizer*0.05+0.95)*rpm";
				volume="engineOn*(thrust factor[0.5, 1.3])";
			};
			class IdleOut
			{
				sound[]=
				{
					"\ca\SOUNDS\Vehicles\Water\CRRC_PBX\ext-boat-engine-idle-01",
					0.56234133,
					1,
					150
				};
				frequency="1";
				volume="engineOn*(rpm factor[0.2, 0])";
			};
			class WaternoiseOutW0
			{
				sound[]=
				{
					"ca\sounds\vehicles\water\water_sfx\ext-water-noise-nospeed",
					0.39810717,
					1,
					100
				};
				frequency="1";
				volume="(speed factor[7, 0])";
			};
			class WaternoiseOutW1
			{
				sound[]=
				{
					"ca\sounds\vehicles\water\water_sfx\ext-boat-lospd-noise-02",
					0.39810717,
					1,
					100
				};
				frequency="1";
				volume="((speed factor[2, 12]) min (speed factor[12, 2]))";
			};
			class WaternoiseOutW2
			{
				sound[]=
				{
					"ca\sounds\vehicles\water\water_sfx\ext-boat-hispd-noise-02",
					0.39810717,
					1,
					100
				};
				frequency="1";
				volume="(speed factor[9, 18.7])";
			};
		};
		castDriverShadow=1;
		castCargoShadow=1;
		ejectDeadCargo=1;
		ejectDeadDriver=1;
		class Turrets
		{
		};
		maxSpeed=60;
		transportSoldier=4;
		class Exhausts
		{
			class Exhaust1
			{
				position="vyfuk start";
				direction="vyfuk konec";
				effect="";
			};
		};
		supplyRadius=2;
		class DestructionEffects
		{
		};
		cost=10000;
		armor=20;
	};
	class Zodiac: RubberBoat
	{
		scope=2;
		side=1;
		faction="USMC";
		displayName="$STR_DN_ZODIAC";
		class Library
		{
			libTextDesc="$STR_LIB_ZODIAC";
		};
		crew="USMC_Soldier";
		typicalCargo[]=
		{
			"USMC_Soldier",
			"USMC_Soldier_AT"
		};
		model="\ca\water\zodiac";
		picture="\ca\water\data\ico\zodiac_CA.paa";
		Icon="\Ca\water\Data\map_ico\icomap_rubber_CA.paa";
		driverAction="Zodiac_Driver";
		cargoAction[]=
		{
			"Zodiac_Cargo01",
			"Zodiac_Cargo02",
			"Zodiac_Cargo03",
			"Zodiac_Cargo04"
		};
		class TransportMagazines
		{
			class _xx_30Rnd_556x45_Stanag
			{
				magazine="30Rnd_556x45_Stanag";
				count="30*1";
			};
			class _xx_200Rnd_556x45_M249
			{
				magazine="200Rnd_556x45_M249";
				count="5*1";
			};
			class _xx_HandGrenade_west
			{
				magazine="HandGrenade_west";
				count="10*1";
			};
			class _xx_5Rnd_762x51_M24
			{
				magazine="5Rnd_762x51_M24";
				count="10*1";
			};
			class _xx_15rnd_9x19_M9
			{
				magazine="15rnd_9x19_M9";
				count="15*1";
			};
			class _xx_M136
			{
				magazine="M136";
				count="3*1";
			};
			class _xx_1Rnd_HE_M203
			{
				magazine="1Rnd_HE_M203";
				count="3*1";
			};
		};
		extCameraPosition[]={0,1.5,-4};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"ca\water\data\zodiac_engine.rvmat",
				"ca\water\data\zodiac_engine.rvmat",
				"ca\water\data\zodiac_engine_destruct.rvmat",
				"ca\water\data\zodiac_guma.rvmat",
				"ca\water\data\zodiac_guma.rvmat",
				"ca\water\data\zodiac_guma_destruct.rvmat",
				"ca\water\data\zodiac_gumb.rvmat",
				"ca\water\data\zodiac_gumb.rvmat",
				"ca\water\data\zodiac_gumb_destruct.rvmat",
				"ca\water\data\zodiac_trup.rvmat",
				"ca\water\data\zodiac_trup.rvmat",
				"ca\water\data\zodiac_trup_destruct.rvmat"
			};
		};
	};
	class PBX: RubberBoat
	{
		scope=2;
		displayName="$STR_DN_BOAT";
		faction="RU";
		model="\ca\water\PBX";
		picture="\ca\water\data\ico\pbx_CA.paa";
		Icon="\Ca\water\Data\map_ico\icomap_rubber_CA.paa";
		mapSize=6;
		transportSoldier=3;
		typicalCargo[]=
		{
			"RU_Soldier",
			"RU_Soldier_AR"
		};
		driverAction="PBX_Driver";
		cargoAction[]=
		{
			"PBX_Cargo01",
			"PBX_Cargo02",
			"PBX_Cargo03"
		};
		side=0;
		maxSpeed=65;
		crew="RU_Soldier";
		class TransportMagazines
		{
			class _xx_30Rnd_545x39_AK
			{
				magazine="30Rnd_545x39_AK";
				count="30*1";
			};
			class _xx_100Rnd_762x54_PK
			{
				magazine="100Rnd_762x54_PK";
				count="5*1";
			};
			class _xx_8Rnd_9x18_Makarov
			{
				magazine="8Rnd_9x18_Makarov";
				count="20*1";
			};
			class _xx_HandGrenade_east
			{
				magazine="HandGrenade_east";
				count="10*1";
			};
			class _xx_10Rnd_762x54_SVD
			{
				magazine="10Rnd_762x54_SVD";
				count="10*1";
			};
			class _xx_PG7VR
			{
				magazine="PG7VR";
				count="3*1";
			};
			class _xx_1Rnd_HE_GP25
			{
				magazine="1Rnd_HE_GP25";
				count="3*1";
			};
		};
		class Library
		{
			libTextDesc="$STR_LIB_BOAT";
		};
		extCameraPosition[]={0,4,-14};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"ca\water\data\pbx_engine.rvmat",
				"ca\water\data\pbx_engine.rvmat",
				"ca\water\data\pbx_engine_destruct.rvmat",
				"ca\water\data\pbx_01.rvmat",
				"ca\water\data\pbx_01.rvmat",
				"ca\water\data\pbx_01_destruct.rvmat",
				"ca\water\data\pbx_02.rvmat",
				"ca\water\data\pbx_02.rvmat",
				"ca\water\data\pbx_02_destruct.rvmat"
			};
		};
	};
};
