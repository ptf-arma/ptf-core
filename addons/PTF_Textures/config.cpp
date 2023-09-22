class CfgPatches
{
   class PTF_Textures
   {
      units[] = {};
      weapons[] = {};
      requiredAddons[] = {
          "PTF_Main"};
      author[] = {
          "Paramarine Task Force"};
   };
};
class CAWorld;
class RscStandardDisplay;
class RscVignette;
class RscControlsGroupNoScrollbars;
class RscFrame;
class RscText;
class RscPicture;
class RscTitle;
class RscButtonMenu;
class RscHTML;
class RscControlsGroupNoHScrollbars;
class RscListBox;
class RscPictureKeepAspect;
class RscButton;
class RscButtonImages;
class RscShortcutButton;

class RscDisplayLoadMission: RscStandardDisplay
{
	class controlsBackground
	{
		class LoadingPicture_PTF: RscPicture
		{
			idc = 1000;
			colorText[] = {1,1,1,1};
			x = "SafeZoneX";
			y = "SafeZoneY";
			h = "SafeZoneH";
			w = "SafeZoneW";
			text = "\PTF_Textures\Backgrounds\Background1.paa";
		};
	};
};
class RscDisplayLoading
{
	class Variants
	{
		class NCA_loadingBackground1: RscDisplayLoadMission
		{
			class controlsBackground: controlsBackground
			{
				class NCA_loadingBackground: RscPicture
				{
					
					text = "\PTF_Textures\Backgrounds\Background1.paa";
				};
			};
		};
		class NCA_loadingBackground2: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background2.paa";
				};
			};
		};
			class NCA_loadingBackground3: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background3.paa";
				};
			};
		};
			class NCA_loadingBackground4: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background4.paa";
				};
			};
		};
			class NCA_loadingBackground5: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background5.paa";
				};
			};
		};
        	class NCA_loadingBackground6: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background6.paa";
				};
			};
		};
        	class NCA_loadingBackground7: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background7.paa";
				};
			};
		};
        	class NCA_loadingBackground8: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background8.paa";
				};
			};
		};
        	class NCA_loadingBackground9: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background9.paa";
				};
			};
		};
        	class NCA_loadingBackground10: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background10.paa";
				};
			};
		};
        	class NCA_loadingBackground11: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background11.paa";
				};
			};
		};
        	class NCA_loadingBackground12: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background12.paa";
				};
			};
		};
        	class NCA_loadingBackground13: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background1.paa";
				};
			};
		};
        	class NCA_loadingBackground14: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background2.paa";
				};
			};
		};
        	class NCA_loadingBackground15: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background3.paa";
				};
			};
		};
        	class NCA_loadingBackground16: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background4.paa";
				};
			};
		};
        	class NCA_loadingBackground17: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background5.paa";
				};
			};
		};
        	class NCA_loadingBackground18: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background6.paa";
				};
			};
		};
        	class NCA_loadingBackground19: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background7.paa";
				};
			};
		};
        	class NCA_loadingBackground20: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background8.paa";
				};
			};
		};
        	class NCA_loadingBackground21: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background9.paa";
				};
			};
		};
        	class NCA_loadingBackground22: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background10.paa";
				};
			};
		};
        	class NCA_loadingBackground23: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background11.paa";
				};
			};
		};
        	class NCA_loadingBackground24: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background12.paa";
				};
			};
		};
        	class NCA_loadingBackground25: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background1.paa";
				};
			};
		};
        	class NCA_loadingBackground26: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background2.paa";
				};
			};
		};
        	class NCA_loadingBackground27: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background3.paa";
				};
			};
		};
        	class NCA_loadingBackground28: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background4.paa";
				};
			};
		};
        	class NCA_loadingBackground29: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background5.paa";
				};
			};
		};
        	class NCA_loadingBackground30: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background6.paa";
				};
			};
		};
        	class NCA_loadingBackground31: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background7.paa";
				};
			};
		};
        	class NCA_loadingBackground32: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background8.paa";
				};
			};
		};
        	class NCA_loadingBackground33: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background9.paa";
				};
			};
		};
        	class NCA_loadingBackground34: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background10.paa";
				};
			};
		};
        	class NCA_loadingBackground35: NCA_loadingBackground1 {
			class controlsBackground: controlsBackground {
				class NCA_loadingBackground: NCA_loadingBackground{
					text = "\PTF_Textures\Backgrounds\Background11.paa";
				};
			};
		};
	};
};
