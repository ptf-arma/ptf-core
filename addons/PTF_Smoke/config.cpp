class cfgPatches
{
	class PTF_Smoke
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Data_F",
			"A3_Weapons_F"
		};
		author="PTF";
	};
};
class cfgCloudlets
{
	class Default;
	class SmokeShellWhite: Default
	{
		angleVar = 0.1;
		animationName = "";
		animationSpeed[] = {1.5, 0.5};
		animationSpeedCoef = 0.00001;
		beforeDestroyScript = "";
		circleRadius = 0;
		circleVelocity[] = {0, 0, 0};
		color[] = {{0.6, 0.6, 0.6, 0.85}, {0.7, 0.7, 0.7, 0.65}, {0.8, 0.8, 0.8, 0.45}, {0.9, 0.9, 0.9, 0.25}, {1, 1, 1, 0}};
		colorCoef[] = {"colorR", "colorG", "colorB", "colorA"};
		colorVar[] = {0, 0, 0, 0};
		destroyOnWaterSurface = 1;
		destroyOnWaterSurfaceOffset = -0.6;
		interval = 0.125;
		lifeTime = 20;
		lifeTimeVar = 5;
		moveVelocity[] = {0.5, 0.4, 0.4};
		MoveVelocityVar[] = {0.25, 0.25, 0.25};
		onTimerScript = "";
		particleFSFrameCount = 1;
		particleFSIndex = 0;
		particleFSLoop = 1;
		particleFSNtieth = 1;
		particleShape = "\A3\data_f\ParticleEffects\Universal\smoke.p3d";
		particleType = "Billboard";
		position[] = {0, 0, 0};
		positionVar[] = {0, 0, 0};
		randomDirectionIntensity = 0.04;
		randomDirectionIntensityVar = 0;
		randomDirectionPeriod = 1;
		randomDirectionPeriodVar = 0;
		rotationVelocity = 6;
		rotationVelocityVar = 5;
		rubbing = 0.05;
		size[] = {0.1, 2, 4, 6};
		sizeCoef = 1;
		sizeVar = 1;
		timerPeriod = 1;
		volume = 1;
		weight = 1.2777;
	};
};
