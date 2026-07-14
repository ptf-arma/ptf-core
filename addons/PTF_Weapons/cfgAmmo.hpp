class cfgAmmo {
	
	// PTF_ACE_Hellfire_AGM114K is defined once in PTF_Aircraft (where its
	// model lives). It was previously also defined here with a broken
	// \PTF_Weapons\... model path, making the effective model load-order
	// dependent. cfgMagazine.hpp references it by string, which resolves
	// at runtime, so no declaration is needed here.

	class ptf_B_12Gauge_Slug_NoCartridge : B_12Gauge_Slug_NoCartridge {
		hit = 0;
		class EventHandlers {
			init	= "_this call PTF_Fnc_BeanBag";
		};
	};

	class G_40mm_Smoke: SmokeShell {
		simulation = "shotSmoke";
		deflectionSlowDown = 0.3;
	};

	class ibr_stone_grenade: GrenadeHand
	{
		timeToLive = 900;
		grenadeFireSound[] = {};
		grenadeBurningSound[] = {};
		model = "a3\data_f\cl_rock1.p3d";
		simulation = "shotShell";
		SoundSetExplosion[] = {""};
		soundHit[] = {"",0,1};
		hit = 5;
		cost = 1;
		CraterEffects = "";
		explosionEffects = "";
		indirectHit = 0;
		indirectHitRange = 0;
		deflecting = 5;
		airFriction = -0.001;
		whistleDist = 16;
		typicalSpeed = 26;
		explosionTime = 0;
		fuseDistance = 0.5;
		directionalExplosion = 0;
		deflectionSlowDown = 0.8;
		simulationStep = 0.05;
		supersonicCrackNear[] = {};
		supersonicCrackFar[] = {};
		soundHit1[] = {"ibr_lartanians\snd\spear.wss"};
		soundHit2[] = {"ibr_lartanians\snd\spear.wss"};
		soundHit3[] = {"ibr_lartanians\snd\spear.wss"};
		soundHit4[] = {"ibr_lartanians\snd\spear.wss"};
		multiSoundHit[] = {};
		class CamShakeExplode
		{
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
		class CamShakeHit
		{
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
		class CamShakeFire
		{
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
		class CamShakePlayerFire
		{
			power = 0;
			duration = 0;
			frequency = 0;
			distance = 0;
		};
	};
};

