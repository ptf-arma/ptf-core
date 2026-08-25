class cfgPatches
{
	class PTF_Sound
	{
		#include "cfgPatchesUnits.hpp"
		weapons[]={};
		requiredVersion=1.16;
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
			class serverLoop{};
			class speakerDialog{};
			class speakerAction{};
			class addCutAction{};
			class browseDialog{};
			class placeSpeaker{};
			class initZeus
			{
				postInit=1;
			};
		};
	};
};
class CfgSounds
{
	#include "cfgSounds.hpp"
};
// Zeus right-click menu for placed loudspeaker modules. The root class is
// ZEN's; without ZEN loaded this is an inert config branch.
class zen_context_menu_actions
{
	class PTF_Sound_Speaker
	{
		displayName="Loudspeaker";
		icon="\a3\ui_f\data\igui\cfg\simpleTasks\types\talk_ca.paa";
		class PTF_Sound_Preview
		{
			displayName="Preview (only you)";
			icon="\a3\ui_f\data\igui\cfg\simpleTasks\types\use_ca.paa";
			condition="_hoveredEntity isKindOf 'PTF_Sound_Module_base'";
			statement="[_hoveredEntity, 'preview'] call PTF_Sound_fnc_speakerAction";
			priority=50;
		};
		class PTF_Sound_PlayNow
		{
			displayName="Broadcast now";
			icon="\a3\ui_f\data\igui\cfg\simpleTasks\types\interact_ca.paa";
			condition="_hoveredEntity isKindOf 'PTF_Sound_Module_base' && {!(_hoveredEntity getVariable ['PTF_Sound_paused', false])}";
			statement="[_hoveredEntity, 'playnow'] call PTF_Sound_fnc_speakerAction";
			priority=40;
		};
		class PTF_Sound_Pause
		{
			displayName="Mute";
			icon="\a3\ui_f\data\igui\cfg\simpleTasks\types\wait_ca.paa";
			condition="_hoveredEntity isKindOf 'PTF_Sound_Module_base' && {!(_hoveredEntity getVariable ['PTF_Sound_paused', false])}";
			statement="[_hoveredEntity, 'pause'] call PTF_Sound_fnc_speakerAction";
			priority=30;
		};
		class PTF_Sound_Resume
		{
			displayName="Resume broadcast";
			icon="\a3\ui_f\data\igui\cfg\simpleTasks\types\run_ca.paa";
			condition="_hoveredEntity isKindOf 'PTF_Sound_Module_base' && {_hoveredEntity getVariable ['PTF_Sound_paused', false]}";
			statement="[_hoveredEntity, 'resume'] call PTF_Sound_fnc_speakerAction";
			priority=30;
		};
		class PTF_Sound_Adjust
		{
			displayName="Adjust range / pause";
			icon="\a3\ui_f\data\igui\cfg\simpleTasks\types\repair_ca.paa";
			condition="_hoveredEntity isKindOf 'PTF_Sound_Module_base'";
			statement="[_hoveredEntity, 'adjust'] call PTF_Sound_fnc_speakerAction";
			priority=20;
		};
	};
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
			class Checkbox;
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
		PTF_soundClass="";
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
			class PTF_Sound_pause: Edit
			{
				property="PTF_Sound_pause";
				displayName="Pause between repeats (s)";
				tooltip="Seconds of silence between plays. -1 = use this sound's default pause.";
				typeName="NUMBER";
				defaultValue="-1";
			};
			class PTF_Sound_paused: Checkbox
			{
				property="PTF_Sound_paused";
				displayName="Start muted";
				tooltip="Hold the broadcast until resumed (Zeus right-click menu, or set PTF_Sound_paused to false).";
				typeName="BOOL";
				defaultValue="false";
			};
			class ModuleDescription: ModuleDescription{};
		};
	};
	#include "cfgModules.hpp"
};
