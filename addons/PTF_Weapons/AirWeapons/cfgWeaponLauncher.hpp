class PTF_RKT_Launcher : FIR_RKT_Launcher
{
    ballisticsComputer = 8;
    holdsterAnimValue = 1;
    magazines[] = {"FIR_Hydra_P_7rnd_M","FIR_Hydra_P_21rnd_M","FIR_Hydra_Smoke_P_7rnd_M","FIR_Hydra_Smoke_Red_P_7rnd_M",
    "FIR_Hydra_Smoke_Orange_P_7rnd_M","FIR_Hydra_Smoke_Purple_P_7rnd_M","FIR_Hydra_Smoke_P_21rnd_M","FIR_Hydra_Smoke_Red_P_21rnd_M",
    "FIR_Hydra_Smoke_Orange_P_21rnd_M","FIR_Hydra_Smoke_Purple_P_21rnd_M","FIR_Hydra_P_19rnd_M","FIR_Hydra_WDU4_P_7rnd_M","FIR_Hydra_WDU4_P_19rnd_M",
    "FIR_Hydra_WP_P_7rnd_M","FIR_Hydra_LAU130_P_19rnd_M","FIR_CRV7_P_19rnd_M","FIR_Hydra_M259_P_7rnd_M","FIR_Hydra_WP_P_21rnd_M",
    "FIR_Hydra_M229_P_7rnd_M","FIR_Hydra_M229_P_19rnd_M","FIR_Hydra_M247_P_7rnd_M","FIR_Hydra_M247_P_19rnd_M","FIR_Hydra_M257_P_7rnd_M","FIR_Hydra_M261_P_7rnd_M","FIR_Hydra_M261_P_19rnd_M",
    "FIR_Hydra_M282_P_7rnd_M","FIR_Hydra_M282_P_19rnd_M","FIR_Hydra_WDU4_P_38rnd_M","FIR_Hydra_WDU4_P_14rnd_M","FIR_Hydra_M282_P_38rnd_M","FIR_Hydra_M282_P_14rnd_M","FIR_Hydra_M261_P_38rnd_M","FIR_Hydra_M261_P_14rnd_M","FIR_Hydra_M247_P_38rnd_M","FIR_Hydra_M247_P_14rnd_M",
    "FIR_Hydra_M229_P_38rnd_M","FIR_Hydra_M229_P_14rnd_M","FIR_Hydra_P_38rnd_M","FIR_Hydra_P_14rnd_M","FIR_Hydra_M278_P_7rnd_M", "PTF_Hydra_WP_21rnd"};
    displayName = "Rocket Launcher";
    modes[] = { "Far_AI", "Single","Burst" };
    cursor = "EmptyCursor";
    cursorAim = "rocket";
    class Far_AI : FIR_RKT_Base
    {
        minRange = 50;
        minRangeProbab = 0.041;
        midRange = 600;
        midRangeProbab = 0.21;
        maxRange = 2500;
        maxRangeProbab = 0.11;
        displayName = "HYDRA-SINGLE";

        sounds[] = { "StandardSound" };

        class StandardSound
        {
            begin1[] = { "A3\Sounds_F\weapons\Rockets\new_rocket_7", 1.7782794, 1.2, 1600 };
            soundBegin[] = { "begin1", 1 };
            weaponSoundEffect = "DefaultRifle";
        };
        soundFly[] = { "\A3\Sounds_F\weapons\Rockets\rocket_fly_2", 1.0, 1.2, 700 };
        weaponSoundEffect = "DefaultRifle";

        burst = 1;
        reloadTime = 0.08;
        autoFire = 0;
        showToPlayer = 0;
    };
    class Single : FIR_RKT_Base
    {
        minRange = 1;
        minRangeProbab = 0.001;
        midRange = 2;
        midRangeProbab = 0.001;
        maxRange = 3;
        maxRangeProbab = 0.001;
        displayName = "SINGLE";
        burst = 1;
        reloadTime = 0.1;
        soundContinuous = 0;
        autoFire = 0;

        sounds[] = { "StandardSound" };

        class StandardSound
        {
            begin1[] = { "A3\Sounds_F\weapons\Rockets\new_rocket_7", 1.7782794, 1.2, 1600 };
            soundBegin[] = { "begin1", 1 };
            weaponSoundEffect = "DefaultRifle";
        };
        soundFly[] = { "\A3\Sounds_F\weapons\Rockets\rocket_fly_2", 1.0, 1.2, 700 };
        weaponSoundEffect = "DefaultRifle";		
    };		
    class Burst : FIR_RKT_Base
    {
        minRange = 1;
        minRangeProbab = 0.001;
        midRange = 2;
        midRangeProbab = 0.001;
        maxRange = 3;
        maxRangeProbab = 0.001;
        displayName = "FULLAUTO";
        burst = 1;
        reloadTime = 0.1;
        soundContinuous = 0;
        autoFire = 1;
        textureType = "fullAuto";
        sounds[] = { "StandardSound" };

        class StandardSound
        {
            begin1[] = { "A3\Sounds_F\weapons\Rockets\new_rocket_7", 1.7782794, 1.2, 1600 };
            soundBegin[] = { "begin1", 1 };
            weaponSoundEffect = "DefaultRifle";
        };
        soundFly[] = { "\A3\Sounds_F\weapons\Rockets\rocket_fly_2", 1.0, 1.2, 700 };
        weaponSoundEffect = "DefaultRifle";		
        
        dispersion = 0.006000;
    };
        FIR_AWS_SMS_A10C_CODE = "FIR_AirWeaponSystem_US\ui\sms\a10\wep_hydra.paa";				
};