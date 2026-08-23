class cfgPatches
{
	class PTF_Sound
	{
		#include "cfgPatchesUnits.hpp"
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Data_F",
			"A3_Modules_F"
		};
		author="PTF";
	};
};
class CfgFactionClasses
{
	class PTF_Sound_generic
	{
		displayName="PTF Loudspeakers (Generic)";
		priority=90;
		side=7;
	};
	class PTF_Sound_valmera
	{
		displayName="PTF Loudspeakers (Valmera)";
		priority=91;
		side=7;
	};
};
class CfgFunctions
{
	class PTF_Sound
	{
		class modules
		{
			file="\z\PTF\addons\PTF_Sound\functions";
			class moduleSpeaker{};
		};
	};
};
class CfgSounds
{
	#include "cfgSounds.hpp"
};
class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class AttributesBase
		{
			class Default;
			class Edit;
		};
		class ModuleDescription;
	};
	class PTF_Sound_Module_base: Module_F
	{
		scope=1;
		scopeCurator=1;
		curatorCanAttach=1;
		isGlobal=0;
		isTriggerActivated=0;
		isDisposable=0;
		function="PTF_Sound_fnc_moduleSpeaker";
		PTF_sound="";
		PTF_volume=5;
		PTF_distance=700;
		PTF_duration=30;
		PTF_pause=20;
		class Attributes: AttributesBase
		{
			class PTF_Sound_distance: Edit
			{
				property="PTF_Sound_distance";
				displayName="Broadcast range (m)";
				tooltip="Radius in metres the broadcast is audible out to. 0 = use this sound's default range.";
				typeName="NUMBER";
				defaultValue="0";
			};
			class ModuleDescription: ModuleDescription{};
		};
	};
	#include "cfgModules.hpp"
};
