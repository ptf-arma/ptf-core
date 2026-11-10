// The radar trailer is an engineless car, so it rolls on PhysX wheels when towed. PhysX
// cars need two axles: the real wheels are the rear pair and the tongue stand's caster
// stands in for the front pair (memory points only, no mesh). See tools/gator/build_model.py.
//
// Setting up, by ACE interaction: lower each of the four legs (at the leg), start the
// generator, raise the array, start the antenna turning. Packing up runs it backwards.
// Raising, lowering and turning need the generator running; the array only goes up on all
// four legs, and the legs only come up once it is down.
//
// ptf_gator_deploy (0 down, 1 raised) drives the array, and the hydraulic struts follow it
// (the diagonal ones unpin about halfway down). ptf_gator_spin turns the turntable with the
// box, array and struts. ptf_gator_leg_* drive the legs. Sounds are played on each client
// by PTF_GATOR_fnc_soundLoop from that state: see functions/fn_soundLoop.sqf.

class SensorTemplateActiveRadar;
class SensorTemplateDataLink;

class CfgVehicles
{
	class Car;
	class B_Radar_System_01_F;

	// The G/ATOR's working radar: the vanilla AN/MPQ-105 retuned to 10 km against aircraft,
	// all the way round, on the data link. Never placed by hand; PTF_GATOR_fnc_radarLoop
	// creates it hidden, crews it with its UAV AI and attaches it to a turning G/ATOR.
	class PTF_GATOR_Sensor: B_Radar_System_01_F
	{
		scope = 1;
		scopeCurator = 0;
		displayName = "G/ATOR radar";
		author = "Paramarine Task Force";
		class Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange = 0;
							maxRange = 10000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget
						{
							minRange = 0;
							maxRange = 0;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						typeRecognitionDistance = 8000;
						angleRangeHorizontal = 360;
						angleRangeVertical = 100;
						aimDown = -45;
						maxTrackableSpeed = 1500;
						groundNoiseDistanceCoef = -1;
						maxGroundNoiseDistance = -1;
						minSpeedThreshold = 0;
						maxSpeedThreshold = 0;
					};
					class DataLinkSensorComponent: SensorTemplateDataLink {};
				};
			};
		};
		reportOwnPosition = 1;
		receiveRemoteTargets = 1;
		reportRemoteTargets = 1;
	};
	// Heavily jammed by CROWS (PTF_GATOR_fnc_operatorTick): its air radar reaches 4 km.
	class PTF_GATOR_SensorJammed: PTF_GATOR_Sensor
	{
		class Components: Components
		{
			class SensorsManagerComponent: SensorsManagerComponent
			{
				class Components: Components
				{
					class ActiveRadarSensorComponent: ActiveRadarSensorComponent
					{
						class AirTarget: AirTarget
						{
							maxRange = 4000;
						};
					};
				};
			};
		};
	};

	class Car_F: Car
	{
		class ACE_Actions;
		class AnimationSources;
	};

	class PTF_GATOR: Car_F
	{
		scope = 2;
		scopeCurator = 2;
		author = "Paramarine Task Force";
		displayName = "AN/TPS-80 G/ATOR";
		editorCategory = "PTF";
		editorSubcategory = "PTF_UtilityAir";
		side = 1;
		faction = "BLU_F";
		vehicleClass = "Support";
		model = "\z\ptf_gator\addons\data\gator.p3d";
		picture = "\A3\ui_f\data\map\vehicleicons\iconCar_ca.paa";
		icon = "iconCar";
		mapSize = 7;
		// camo1-3 are the trailer, generator and array; "lights" is the lamp lenses.
		hiddenSelections[] = {"camo1", "camo2", "camo3", "lights"};
		hiddenSelectionsTextures[] =
		{
			"\z\ptf_gator\addons\data\data\support_co.paa",
			"\z\ptf_gator\addons\data\data\generator_co.paa",
			"\z\ptf_gator\addons\data\data\radar_co.paa",
			"\z\ptf_gator\addons\data\data\support_co.paa"
		};

		// Nobody rides it. Its radar is a hidden PTF_GATOR_Sensor (below) that the server
		// attaches to the turntable while the antenna turns on power (PTF_GATOR_fnc_radarLoop):
		// vehicle sensors only run with crew, and that needs crew seats, which this model has none of.
		hasDriver = 0;
		crew = "";
		typicalCargo[] = {};
		transportSoldier = 0;
		class Turrets {};
		// No headlights (the inherited car ones would add their own hit points).
		class Reflectors {};
		reportOwnPosition = 1;
		receiveRemoteTargets = 1;
		reportRemoteTargets = 1;

		// Damage, repaired with ACE: the trailer, the generator and its tank, the antenna, and
		// the wheels (which ACE can also take off and put back on). The hit points are in the
		// model's hit points LOD (tools/gator/build_model.py, HIT_POINTS).
		class HitPoints
		{
			// HitBody rather than HitHull: ACE's wheel finder skips HitBody when it looks for the
			// hit point nearest each PhysX wheel, so the tongue stand's stand-in wheels pair
			// with the real wheels instead of making the trailer body a "wheel".
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "hit_hull";
				visual = "";
				passThrough = 1;
				minimalHit = 0.05;
				explosionShielding = 1;
				radius = 0.6;
			};
			class HitEngine
			{
				armor = 0.6;
				material = -1;
				name = "hit_engine";
				visual = "";
				passThrough = 0.3;
				minimalHit = 0.1;
				explosionShielding = 0.5;
				radius = 0.45;
			};
			class HitFuel
			{
				armor = 0.5;
				material = -1;
				name = "hit_fuel";
				visual = "";
				passThrough = 0.3;
				minimalHit = 0.1;
				explosionShielding = 0.5;
				radius = 0.35;
			};
			class HitRadar
			{
				armor = 0.8;
				material = -1;
				name = "hit_radar";
				visual = "";
				passThrough = 0.2;
				minimalHit = 0.1;
				explosionShielding = 1;
				radius = 0.6;
			};
			class HitLF2Wheel
			{
				armor = -120;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "";
				// Hidden by the engine once the wheel is destroyed or taken off with ACE.
				armorComponent = "wheel_1_2_hide";
				passThrough = 0;
				minimalHit = -0.00833333;
				explosionShielding = 4;
				radius = 0.33;
			};
			class HitRF2Wheel: HitLF2Wheel
			{
				name = "wheel_2_2_steering";
				armorComponent = "wheel_2_2_hide";
			};
		};
		armor = 150;
		cost = 1000000;
		// The generator's tank: one 20 L jerrycan, about 25 minutes of running
		// (ptf_gator_fuelMinutes; PTF_GATOR_fnc_fuelLoop burns it). ACE refuels it at the
		// generator's left side.
		fuelCapacity = 20;
		ace_refuel_fuelCapacity = 20;
		ace_refuel_hooks[] = {{-1.3, 1.0, 1.25}};
		ptf_gator_fuelMinutes = 25;

		// Sling loading (vanilla and SLR): the frame's four lifting eyes.
		slingLoadCargoMemoryPoints[] = {"SlingLoadCargo1", "SlingLoadCargo2", "SlingLoadCargo3", "SlingLoadCargo4"};
		// No storage of any kind: no ACE cargo, no inventory.
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_canLoad = 0;
		class ace_cargo {};
		ace_dragging_canDrag = 0;
		ace_dragging_canCarry = 0;
		transportMaxBackpacks = 0;
		transportMaxMagazines = 0;
		transportMaxWeapons = 0;
		maximumLoad = 0;

		// PhysX: a trailer on a 2.75 m-circumference tyre. The engine is a token one.
		simulation = "carx";
		wheelCircumference = 2.749;
		maxSpeed = 90;
		enginePower = 10;
		peakTorque = 50;
		maxOmega = 100;
		idleRpm = 400;
		redRpm = 1000;
		thrustDelay = 0.5;
		brakeIdleSpeed = 1.78;
		differentialType = "rear_open";
		frontRearSplit = 0.5;
		antiRollbarForceCoef = 0;
		class complexGearbox
		{
			GearboxRatios[] = {"R1", -4, "N", 0, "D1", 4};
			TransmissionRatios[] = {"High", 5};
			gearBoxMode = "auto";
			moveOffGear = 1;
			driveString = "D";
			neutralString = "N";
			reverseString = "R";
		};
		class Wheels
		{
			// The real wheels: 0.44 m radius, about 2.5 t each.
			class LR
			{
				side = "left";
				suspTravelDirection[] = {0, -1, 0};
				boneName = "wheel_1_2_damper";
				steering = 0;
				center = "wheel_1_2_axis";
				boundary = "wheel_1_2_bound";
				width = 0.3;
				mass = 60;
				MOI = 6;
				dampingRate = 1;
				dampingRateDamaged = 5;
				dampingRateInAir = 1;
				dampingRateDestroyed = 5000;
				maxBrakeTorque = 3000;
				maxHandBrakeTorque = 6000;
				suspForceAppPointOffset = "wheel_1_2_axis";
				tireForceAppPointOffset = "wheel_1_2_axis";
				maxCompression = 0.06;
				maxDroop = 0.08;
				sprungMass = 2500;
				springStrength = 220000;
				springDamperRate = 19000;
				longitudinalStiffnessPerUnitGravity = 10000;
				latStiffX = 2.5;
				latStiffY = 18;
				frictionVsSlipGraph[] = {{0, 2}, {0.5, 1.5}, {1, 1.3}};
			};
			class RR: LR
			{
				side = "right";
				boneName = "wheel_2_2_damper";
				center = "wheel_2_2_axis";
				boundary = "wheel_2_2_bound";
				suspForceAppPointOffset = "wheel_2_2_axis";
				tireForceAppPointOffset = "wheel_2_2_axis";
			};
			// The tongue stand's caster, split into a narrow pair.
			class LF: LR
			{
				// ACE pairs a PhysX wheel with the hit point whose selection starts with the first
				// nine letters of its boneName: "wheel_1_2" sends it to the real left wheel, so
				// ACE doesn't make some other hit point a wheel. No bone has this name.
				boneName = "wheel_1_2_stand";
				center = "wheel_1_1_axis";
				boundary = "wheel_1_1_bound";
				suspForceAppPointOffset = "wheel_1_1_axis";
				tireForceAppPointOffset = "wheel_1_1_axis";
				width = 0.08;
				mass = 10;
				MOI = 0.05;
				maxBrakeTorque = 200;
				maxHandBrakeTorque = 400;
				sprungMass = 250;
				springStrength = 22000;
				springDamperRate = 1900;
				maxCompression = 0.03;
				maxDroop = 0.03;
			};
			class RF: LF
			{
				side = "right";
				boneName = "wheel_2_2_stand";
				center = "wheel_2_1_axis";
				boundary = "wheel_2_1_bound";
				suspForceAppPointOffset = "wheel_2_1_axis";
				tireForceAppPointOffset = "wheel_2_1_axis";
			};
		};

		// How long the generator takes to start and to stop (its sound clips), in seconds.
		// It only powers the radar once started.
		ptf_gator_powerStartTime = 5;
		ptf_gator_powerStopTime = 3;
		// How far off enemy AI may hear the generator, in metres (PTF_GATOR_fnc_hearGenerator).
		ptf_gator_hearingRange = 250;
		// Counter-battery and air tracks reach the network over the SATCOM antenna it carries,
		// set down on its cable (PTF_GATOR_fnc_satcom): the first of these that's loaded (the
		// TFW RF-3080, else a vanilla satellite antenna), and the cable's length in metres.
		ptf_gator_cableLength = 40;
		ptf_gator_satcomClasses[] =
		{
			"tfw_rf3080Object", "Land_SatelliteAntenna_01_F",
			"SatelliteAntenna_01_Olive_F", "SatelliteAntenna_01_Black_F", "SatelliteAntenna_01_Sand_F",
			"SatelliteAntenna_01_Small_Olive_F", "SatelliteAntenna_01_Small_Black_F", "SatelliteAntenna_01_Small_Sand_F"
		};
		// Its operator computer, on its own cable (PTF_GATOR_fnc_computer): the first of these
		// rugged laptops that's loaded, and the cable's length in metres.
		ptf_gator_computerCable = 20;
		ptf_gator_computerClasses[] = {"Land_Laptop_03_olive_F", "Land_Laptop_03_black_F", "Land_Laptop_device_F", "Land_Laptop_unfolded_F"};

		// Destroyed, it is charred (the _destruct materials) and its markings burn off
		// (model.cfg); the inherited destruction effects burn at destructionEffect1 and 2.
		class Damage
		{
			tex[] = {};
			mat[] =
			{
				"z\ptf_gator\addons\data\data\support.rvmat", "z\ptf_gator\addons\data\data\support.rvmat", "z\ptf_gator\addons\data\data\support_destruct.rvmat",
				"z\ptf_gator\addons\data\data\generator.rvmat", "z\ptf_gator\addons\data\data\generator.rvmat", "z\ptf_gator\addons\data\data\generator_destruct.rvmat",
				"z\ptf_gator\addons\data\data\radar.rvmat", "z\ptf_gator\addons\data\data\radar.rvmat", "z\ptf_gator\addons\data\data\radar_destruct.rvmat",
				"z\ptf_gator\addons\data\data\lights.rvmat", "z\ptf_gator\addons\data\data\lights.rvmat", "z\ptf_gator\addons\data\data\support_destruct.rvmat"
			};
		};

		class AnimationSources: AnimationSources
		{
			// The array, 0 down to 1 raised; the struts follow it.
			class ptf_gator_deploy
			{
				source = "user";
				animPeriod = 32;
				initPhase = 0;
			};
			// The turntable, one turn per unit of phase; animPeriod is seconds per turn.
			class ptf_gator_spin
			{
				source = "user";
				animPeriod = 6;
				initPhase = 0;
			};
			// The wheels' roll while towed, one turn per unit (PTF_GATOR_fnc_towLoop).
			class ptf_gator_wheels
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			// A wheel's damage: it disappears when shot off or taken off with ACE.
			class ptf_gator_HitLF2Wheel
			{
				source = "Hit";
				hitpoint = "HitLF2Wheel";
				raw = 1;
			};
			class ptf_gator_HitRF2Wheel: ptf_gator_HitLF2Wheel
			{
				hitpoint = "HitRF2Wheel";
			};
			// The tongue stand's caster, 0 down to 1 wound up (while hitched).
			class ptf_gator_stand
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
			// The leveling legs, each on its own: 0 up, 1 a foot on flat ground under a trailer on
			// its wheels, on to 2 reaching down a slope (PTF_GATOR_fnc_setLeg, _level).
			class ptf_gator_leg_fl
			{
				source = "user";
				animPeriod = 4;
				initPhase = 0;
			};
			class ptf_gator_leg_fr
			{
				source = "user";
				animPeriod = 4;
				initPhase = 0;
			};
			class ptf_gator_leg_rl
			{
				source = "user";
				animPeriod = 4;
				initPhase = 0;
			};
			class ptf_gator_leg_rr
			{
				source = "user";
				animPeriod = 4;
				initPhase = 0;
			};
		};

		class ACE_Actions: ACE_Actions
		{
			class PTF_GATOR_Radar
			{
				displayName = "G/ATOR";
				selection = "interact";
				distance = 4;
				condition = "true";
				icon = "";
				class PTF_GATOR_Deploy
				{
					displayName = "Raise array";
					condition = "[_target, true] call PTF_GATOR_fnc_canSetDeployed";
					statement = "[_target, 'raise'] call PTF_GATOR_fnc_task";
				};
				class PTF_GATOR_Stow
				{
					displayName = "Lower array for travel";
					condition = "[_target, false] call PTF_GATOR_fnc_canSetDeployed";
					statement = "[_target, 'lower'] call PTF_GATOR_fnc_task";
				};
				class PTF_GATOR_SpinStart
				{
					displayName = "Start antenna rotation";
					condition = "[_target, true] call PTF_GATOR_fnc_canSetSpinning";
					statement = "[_target, true] call PTF_GATOR_fnc_setSpinning";
				};
				class PTF_GATOR_SpinStop
				{
					displayName = "Stop antenna rotation";
					condition = "[_target, false] call PTF_GATOR_fnc_canSetSpinning";
					statement = "[_target, false] call PTF_GATOR_fnc_setSpinning";
				};
				// The hardware is worked here; the radar itself (emissions, sector, tracks) from
				// the operator computer's console (PTF_GATOR_fnc_console).
				// The SATCOM antenna: out on its cable into the player's hands (an ACE drag), to set
				// down more than 3 m away; and back in.
				class PTF_GATOR_SatcomOut
				{
					displayName = "Take out SATCOM antenna";
					condition = "alive _target && {isNull (_target getVariable ['PTF_GATOR_antenna', objNull])} && {isNull (_target getVariable ['PTF_GATOR_tower', objNull])} && {abs speed _target < 1} && {isNull (_player getVariable ['ace_dragging_draggedObject', objNull])} && {isNull (_player getVariable ['ace_dragging_carriedObject', objNull])}";
					statement = "[_target, 'out', _player] call PTF_GATOR_fnc_satcom";
				};
				class PTF_GATOR_SatcomStow
				{
					displayName = "Stow SATCOM antenna";
					condition = "private _a = _target getVariable ['PTF_GATOR_antenna', objNull]; !isNull _a && {isNull attachedTo _a}";
					statement = "[_target, 'stow'] call PTF_GATOR_fnc_task";
				};
				// The operator computer: out on its cable into the player's hands (an ACE carry), for
				// manual control at its console; and back in.
				class PTF_GATOR_ComputerOut
				{
					displayName = "Take out operator computer";
					condition = "alive _target && {isNull (_target getVariable ['PTF_GATOR_computer', objNull])} && {isNull (_target getVariable ['PTF_GATOR_tower', objNull])} && {abs speed _target < 1} && {isNull (_player getVariable ['ace_dragging_draggedObject', objNull])} && {isNull (_player getVariable ['ace_dragging_carriedObject', objNull])}";
					statement = "[_target, 'out', _player] call PTF_GATOR_fnc_computer";
				};
				class PTF_GATOR_ComputerStow
				{
					displayName = "Stow operator computer";
					condition = "private _c = _target getVariable ['PTF_GATOR_computer', objNull]; !isNull _c && {isNull attachedTo _c}";
					statement = "[_target, 'stow'] call PTF_GATOR_fnc_computer";
				};
				// The incoming alarm: sounds while traced enemy rounds are in the air.
				class PTF_GATOR_AlarmOn
				{
					displayName = "Turn incoming alarm on";
					condition = "alive _target && {!(_target getVariable ['PTF_GATOR_alarm', false])}";
					statement = "_target setVariable ['PTF_GATOR_alarm', true, true]";
				};
				class PTF_GATOR_AlarmOff
				{
					displayName = "Turn incoming alarm off";
					condition = "_target getVariable ['PTF_GATOR_alarm', false]";
					statement = "_target setVariable ['PTF_GATOR_alarm', false, true]; _target setVariable ['PTF_GATOR_alarmUntil', -1, true]";
				};
			};
			class PTF_GATOR_Tow
			{
				displayName = "Towing";
				selection = "hitch";
				distance = 3;
				condition = "true";
				icon = "";
				class PTF_GATOR_Hitch
				{
					displayName = "Hitch to vehicle";
					condition = "!isNull ([_target] call PTF_GATOR_fnc_towFindVehicle)";
					statement = "[_target, [_target] call PTF_GATOR_fnc_towFindVehicle] call PTF_GATOR_fnc_towHitch";
				};
				// Says why it won't hitch with a wheel off, where it otherwise would.
				class PTF_GATOR_HitchBlocked
				{
					displayName = "Hitch to vehicle";
					condition = "isNull ([_target] call PTF_GATOR_fnc_towFindVehicle) && {!isNull ([_target, true] call PTF_GATOR_fnc_towFindVehicle)}";
					statement = "['A wheel is off. Put it back on before towing.', 1.5] call ace_common_fnc_displayTextStructured";
				};
				class PTF_GATOR_Unhitch
				{
					displayName = "Unhitch";
					condition = "private _tower = _target getVariable ['PTF_GATOR_tower', objNull]; !isNull _tower && {abs speed _tower < 2}";
					statement = "[_target, objNull] call PTF_GATOR_fnc_towHitch";
				};
			};
			class PTF_GATOR_Generator
			{
				displayName = "Generator";
				selection = "generator";
				distance = 3;
				condition = "true";
				icon = "";
				class PTF_GATOR_PowerOn
				{
					displayName = "Start generator";
					condition = "[_target, true] call PTF_GATOR_fnc_canSetPower";
					statement = "[_target, 'power'] call PTF_GATOR_fnc_task";
				};
				class PTF_GATOR_PowerOff
				{
					displayName = "Stop generator";
					condition = "[_target, false] call PTF_GATOR_fnc_canSetPower";
					statement = "[_target, false] call PTF_GATOR_fnc_setPower";
				};
				class PTF_GATOR_FuelCheck
				{
					displayName = "Check fuel";
					condition = "alive _target";
					statement = "[_target] call PTF_GATOR_fnc_fuelReport";
				};
			};
			class PTF_GATOR_Leg_FL
			{
				displayName = "Front left leg";
				selection = "leg_fl";
				distance = 2.5;
				condition = "true";
				icon = "";
				class PTF_GATOR_LegDown
				{
					displayName = "Lower leg";
					condition = "[_target, ""fl"", true] call PTF_GATOR_fnc_canSetLeg";
					statement = "[_target, ""legDown"", ""fl""] call PTF_GATOR_fnc_task";
				};
				class PTF_GATOR_LegUp
				{
					displayName = "Raise leg";
					condition = "[_target, ""fl"", false] call PTF_GATOR_fnc_canSetLeg";
					statement = "[_target, ""legUp"", ""fl""] call PTF_GATOR_fnc_task";
				};
			};
			class PTF_GATOR_Leg_FR
			{
				displayName = "Front right leg";
				selection = "leg_fr";
				distance = 2.5;
				condition = "true";
				icon = "";
				class PTF_GATOR_LegDown
				{
					displayName = "Lower leg";
					condition = "[_target, ""fr"", true] call PTF_GATOR_fnc_canSetLeg";
					statement = "[_target, ""legDown"", ""fr""] call PTF_GATOR_fnc_task";
				};
				class PTF_GATOR_LegUp
				{
					displayName = "Raise leg";
					condition = "[_target, ""fr"", false] call PTF_GATOR_fnc_canSetLeg";
					statement = "[_target, ""legUp"", ""fr""] call PTF_GATOR_fnc_task";
				};
			};
			class PTF_GATOR_Leg_RL
			{
				displayName = "Rear left leg";
				selection = "leg_rl";
				distance = 2.5;
				condition = "true";
				icon = "";
				class PTF_GATOR_LegDown
				{
					displayName = "Lower leg";
					condition = "[_target, ""rl"", true] call PTF_GATOR_fnc_canSetLeg";
					statement = "[_target, ""legDown"", ""rl""] call PTF_GATOR_fnc_task";
				};
				class PTF_GATOR_LegUp
				{
					displayName = "Raise leg";
					condition = "[_target, ""rl"", false] call PTF_GATOR_fnc_canSetLeg";
					statement = "[_target, ""legUp"", ""rl""] call PTF_GATOR_fnc_task";
				};
			};
			class PTF_GATOR_Leg_RR
			{
				displayName = "Rear right leg";
				selection = "leg_rr";
				distance = 2.5;
				condition = "true";
				icon = "";
				class PTF_GATOR_LegDown
				{
					displayName = "Lower leg";
					condition = "[_target, ""rr"", true] call PTF_GATOR_fnc_canSetLeg";
					statement = "[_target, ""legDown"", ""rr""] call PTF_GATOR_fnc_task";
				};
				class PTF_GATOR_LegUp
				{
					displayName = "Raise leg";
					condition = "[_target, ""rr"", false] call PTF_GATOR_fnc_canSetLeg";
					statement = "[_target, ""legUp"", ""rr""] call PTF_GATOR_fnc_task";
				};
			};
		};
	};
};
