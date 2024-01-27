class PTF_Standard_Arsenal : Box_NATO_Equip_F
{
   scope = 2;
   side = 8;
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canload = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_candrag = 0;
   faction = "BLU_F";
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Arsenal";
   author = "Paramarine Task Force";
   displayname = "Standard Arsenal [PTF]";
   hiddenselections[] = {
       "camo",
       "camo_signs"};
   hiddenselectionstextures[] = {
       "PTF_textures\objects\arsenal\equipment_box_blufor_co.paa",
       "PTF_textures\objects\arsenal\equipment_box_blufor_ca.paa"};
   class EventHandlers
   {
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
      init = "[(_this select 0)] remoteExec ['PTF_fnc_arsenal_init', 0, true]";
      };
   };
   class Transportitems : Transportitems{};
   class Transportbackpacks : Transportbackpacks{};
   class Transportmagazines : Transportmagazines{};
   class Transportweapons : Transportweapons{};
};
class PTF_Standard_Arsenal_No_Ammo : PTF_Standard_Arsenal
{
   displayname = "Standard Arsenal (No ammo) [PTF]";
   class EventHandlers
   {
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
       init = "[(_this select 0)] remoteExec ['PTF_fnc_arsenalnoammo_init', 0, true]";
      };
   };
};
class PTF_Training_box: PTF_Standard_Arsenal
{
    displayname="Training Box [PTF]";
	class Transportitems: TransportItems
	{
		class _xx_training_attachment_adapter_yellow
		{
			name="training_attachment_adapter_yellow";
			count=250;
		};
		class _xx_training_attachment_suppressor_blue
		{
			name="training_attachment_suppressor_blue";
			count=250;
		};
	};
	class Transportmagazines: TransportMagazines
	{
			class _xx_training_stanag_30rnd_rubber_blue
			{
			magazine="training_stanag_30rnd_rubber_blue";
			count=1000;
			};
			class _xx_training_stanag_30rnd_blank_yellow
			{
			magazine="training_stanag_30rnd_blank_yellow";
			count=1000;
			};
		};
	};