class CfgPatches
{
	class CAAir2_MV22
	{
		units[]=
		{
			"MV22"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"CAAir2",
			"CACharacters2"
		};
	};
};
class CfgVehicles
{
	class Plane;
	class MV22: Plane
	{
		destrType="DestructWreck";
		scope=2;
		side=1;
		faction="USMC";
		displayName="$STR_DN_MV22";
		vehicleClass="Air";
		model="\ca\air2\mv22\mv22.p3d";
		picture="\ca\air2\data\UI\picture_MV22_CA.paa";
		icon="\ca\air2\data\UI\icon_MV22_CA.paa";
		mapSize=28;
		crew="USMC_Soldier_Pilot";
		accuracy=0.5;
		soundGetIn[]=
		{
			"ca\sounds\Air\MV22\close",
			0.31622776,
			1
		};
		soundGetOut[]=
		{
			"ca\sounds\Air\MV22\open",
			0.31622776,
			1,
			40
		};
		soundDammage[]=
		{
			"ca\sounds\Air\MV22\int-alarm_loop",
			0.56234133,
			1
		};
		soundEngineOnInt[]=
		{
			"ca\sounds\Air\MV22\int_start",
			0.56234133,
			1
		};
		soundEngineOnExt[]=
		{
			"ca\sounds\Air\MV22\ext_start",
			0.56234133,
			1,
			800
		};
		soundEngineOffInt[]=
		{
			"ca\sounds\Air\MV22\int_stop",
			0.56234133,
			1
		};
		soundEngineOffExt[]=
		{
			"ca\sounds\Air\MV22\ext_stop",
			0.56234133,
			1,
			800
		};
		class Sounds
		{
			class EngineLowOut
			{
				sound[]=
				{
					"ca\sounds\Air\MV22\ext_engine_low",
					1.7782794,
					1,
					1000
				};
				frequency="1.0 min (rpm + 0.5)";
				volume="camPos*engineOn*(rpm factor[0.85, 0])";
			};
			class EngineHighOut
			{
				sound[]=
				{
					"ca\sounds\Air\MV22\ext_engine_hi",
					1.7782794,
					1,
					1200
				};
				frequency="1";
				volume="camPos*engineOn*(rpm factor[0.55, 1.0])";
			};
			class ForsageOut
			{
				sound[]=
				{
					"ca\sounds\Air\MV22\ext_forsage",
					1.7782794,
					1,
					1800
				};
				frequency="1";
				volume="camPos*engineOn*(thrust factor[0.5, 1.0])";
			};
			class WindNoiseOut
			{
				sound[]=
				{
					"ca\sounds\Air\MV22\int-wind1",
					0.017782794,
					0.60000002,
					100
				};
				frequency="(0.1+(1.2*(speed factor[1, 100])))";
				volume="camPos*(speed factor[1, 100])";
			};
			class EngineLowIn
			{
				sound[]=
				{
					"ca\sounds\Air\MV22\int_engine_low",
					1,
					1
				};
				frequency="1.0 min (rpm + 0.5)";
				volume="(1-camPos)*(engineOn*(rpm factor[0.85, 0]))";
			};
			class EngineHighIn
			{
				sound[]=
				{
					"ca\sounds\Air\MV22\int_engine_hi",
					1,
					1
				};
				frequency="1";
				volume="(1-camPos)*(engineOn*(rpm factor[0.55, 1.0]))";
			};
			class ForsageIn
			{
				sound[]=
				{
					"ca\sounds\Air\MV22\int_forsage",
					1.4125376,
					1.1
				};
				frequency="1";
				volume="(1-camPos)*(engineOn*(thrust factor[0.5, 1.0]))";
			};
			class WindNoiseIn
			{
				sound[]=
				{
					"ca\sounds\Air\MV22\int-wind1",
					0.0017782794,
					0.60000002
				};
				frequency="(0.1+(1.2*(speed factor[1, 100])))";
				volume="(1-camPos)*(speed factor[1, 100])";
			};
		};
		ejectSpeed[]={0,-2,0};
		cabinOpening=0;
		gearRetracting=1;
		driverAction="MV22_Pilot";
		cargoIsCoDriver[]={1,0};
		cargoAction[]=
		{
			"MV22_Cargo",
			"Mi17_Cargo02"
		};
		driverCompartments="Compartment1";
		cargoCompartments[]=
		{
			"Compartment2"
		};
		maxSpeed=556;
		transportSoldier=24;
		vtol=3;
		supplyRadius=8;
		armor=25;
		damageResistance=0.0017199999;
		weapons[]={};
		magazines[]={};
		selectionRotorStill="engine_static";
		selectionRotorMove="engine_blur";
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"ca\air2\mv22\data\mv22_sklo.rvmat",
				"ca\air2\mv22\data\mv22_sklo_damage.rvmat",
				"ca\air2\mv22\data\mv22_sklo_damage.rvmat",
				"ca\air2\mv22\data\mv22_sklo_in.rvmat",
				"ca\air2\mv22\data\mv22_sklo_in_damage.rvmat",
				"ca\air2\mv22\data\mv22_sklo_in_damage.rvmat",
				"ca\air2\mv22\data\mv22_01.rvmat",
				"ca\air2\mv22\data\mv22_01_damage.rvmat",
				"ca\air2\mv22\data\mv22_01_destruct.rvmat",
				"ca\air2\mv22\data\mv22_02.rvmat",
				"ca\air2\mv22\data\mv22_02_damage.rvmat",
				"ca\air2\mv22\data\mv22_02_destruct.rvmat"
			};
		};
		dammageHalf[]={};
		dammageFull[]={};
		class AnimationSources
		{
			class Door_1_1
			{
				source="user";
				animPeriod=0;
			};
			class Ramp
			{
				source="user";
				animPeriod=0;
			};
			class pack_engine_1
			{
				source="user";
				animPeriod=0;
			};
			class engine_prop_1_1_turn: pack_engine_1
			{
			};
			class engine_prop_1_2_turn: pack_engine_1
			{
			};
			class engine_prop_1_3_turn: pack_engine_1
			{
			};
			class engine_prop_2_1_turn: pack_engine_1
			{
			};
			class engine_prop_2_2_turn: pack_engine_1
			{
			};
			class engine_prop_2_3_turn: pack_engine_1
			{
			};
			class engine_prop_1_1_close: pack_engine_1
			{
			};
			class engine_prop_1_3_close: pack_engine_1
			{
			};
			class engine_prop_2_1_close: pack_engine_1
			{
			};
			class engine_prop_2_2_close: pack_engine_1
			{
			};
			class pack_engine_2: pack_engine_1
			{
			};
			class turn_wing: pack_engine_1
			{
			};
		};
		class UserActions
		{
		};
		class Reflectors
		{
			class Left
			{
				color[]={0.80000001,0.80000001,1,1};
				ambient[]={0.07,0.07,0.07,1};
				position="L svetlo";
				direction="konec L svetla";
				hitpoint="L svetlo";
				selection="L svetlo";
				size=1;
				brightness=1;
			};
			class Right
			{
				color[]={0.80000001,0.80000001,1,1};
				ambient[]={0.07,0.07,0.07,1};
				position="P svetlo";
				direction="konec P svetla";
				hitpoint="P svetlo";
				selection="P svetlo";
				size=1;
				brightness=1;
			};
		};
		class Library
		{
			libTextDesc="$STR_LIB_MV22";
		};
		class MFD
		{
			borderLeft=0.090000004;
			borderRight=0.02;
			borderTop=0.02;
			borderBottom=0.1;
			class MFD1
			{
				topLeft="HUD LH1";
				topRight="HUD PH1";
				bottomLeft="HUD LD1";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={0,1,0,0.1};
				class Pos10Vector
				{
					type="vector";
					pos0[]={0.5,0.27000001};
					pos10[]=
					{
						"0.5+0.9",
						"0.27+0.7"
					};
				};
				class Bones
				{
				};
				class Draw
				{
					alpha=0.89999998;
					color[]={0,1,0};
					clipTL[]={0,0};
					clipBR[]={1,1};
					condition="on";
					class Altitude
					{
						type="text";
						align="left";
						scale=1;
						source="altitudeASL";
						sourceScale=1;
						pos[]=
						{
							{0.28,0.041999999},
							1
						};
						right[]=
						{
							{0.31999999,0.041999999},
							1
						};
						down[]=
						{
							{0.28,0.082000002},
							1
						};
					};
					class Altitude2
					{
						type="text";
						align="left";
						scale=1;
						source="altitudeAGL";
						sourceScale=1;
						pos[]=
						{
							{0.44999999,0.041999999},
							1
						};
						right[]=
						{
							{0.49000001,0.041999999},
							1
						};
						down[]=
						{
							{0.44999999,0.082000002},
							1
						};
					};
					class RPM
					{
						type="text";
						align="left";
						scale=1;
						source="rpm";
						sourceScale=100;
						pos[]=
						{
							{0.63,0.18000001},
							1
						};
						right[]=
						{
							{0.67000002,0.18000001},
							1
						};
						down[]=
						{
							{0.63,0.22},
							1
						};
					};
					class RPM2
					{
						type="text";
						align="left";
						scale=1;
						source="rpm";
						sourceScale=100;
						pos[]=
						{
							{0.80199999,0.18000001},
							1
						};
						right[]=
						{
							{0.84200001,0.18000001},
							1
						};
						down[]=
						{
							{0.80199999,0.22},
							1
						};
					};
					class Fuel
					{
						type="text";
						align="left";
						scale=1;
						source="fuel";
						sourceScale=100;
						pos[]=
						{
							{0.63,0.42500001},
							1
						};
						right[]=
						{
							{0.67000002,0.42500001},
							1
						};
						down[]=
						{
							{0.63,0.465},
							1
						};
					};
					class Fuel2
					{
						type="text";
						align="left";
						scale=1;
						source="fuel";
						sourceScale=100;
						pos[]=
						{
							{0.80199999,0.42500001},
							1
						};
						right[]=
						{
							{0.84200001,0.42500001},
							1
						};
						down[]=
						{
							{0.80199999,0.465},
							1
						};
					};
					class Speed
					{
						type="text";
						align="left";
						scale=1;
						source="speed";
						sourceScale=2.2369399;
						pos[]=
						{
							{0.28,0.22499999},
							1
						};
						right[]=
						{
							{0.31999999,0.22499999},
							1
						};
						down[]=
						{
							{0.28,0.26499999},
							1
						};
					};
				};
			};
		};
	};
};
