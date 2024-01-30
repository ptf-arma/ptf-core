class Flag;
class AttackSpawnerMarker: Flag
{
  scope = 1; 
  name = "Attack Spawner Marker"; //Name used in the Editor and other UIs
  icon = "rhsusf\addons\rhsusf_a2port_air2\data\mapico\icomap_ah1z_ca.paa"; //Marker icon
  color[] = {0, 0, 0, 1}; //Color used for the icon and text
  side = 1; //Side ID
  size = 32; //Default icon size
};
class SupplySpawnerMarker: AttackSpawnerMarker
{
  name = "Supply Spawner Marker"; 
  icon = "rhsusf\addons\rhsusf_ch53\data\ui\ch53_icon_ca.paa"; 
};
class TransportSpawnerMarker: AttackSpawnerMarker
{
  name = "Transport Spawner Marker"; 
  icon = "rhsusf\addons\rhsusf_a2port_air2\data\mapico\icon_uh1y_ca.paa"; 
};
class PlaneSpawnerMarker: AttackSpawnerMarker
{
  name = "Plane Spawner Marker"; 
  icon = "FIR_FA18\icon.paa"; 
};
class ForkliftSpawnerMarker: AttackSpawnerMarker
{
  name = "Forklift Spawner Marker"; 
  icon = "\a3\ui_f\data\igui\cfg\simpletasks\types\Container_ca.paa"; 
};
class CargoSpawnerMarker: AttackSpawnerMarker
{
  name = "Cargo Spawner Marker"; 
  icon = "\a3\ui_f\data\igui\cfg\simpletasks\types\box_ca.paa"; 
};
class HumveeSpawnerMarker: AttackSpawnerMarker
{
  name = "Humvee Spawner Marker"; 
  icon = "rhsusf\addons\rhsusf_hmmwv\icons\ico_m1025_mk19.paa"; 
};
class MrapSpawnerMarker: AttackSpawnerMarker
{
  name = "Mrap Spawner Marker"; 
  icon = "rhsusf\addons\rhsusf_rg33l\pictures\rhs_rg33l_armed_pic_ca.paa"; 
};
class CougarSpawnerMarker: AttackSpawnerMarker
{
  name = "Cougar Spawner Marker"; 
  icon = "rhsusf\addons\rhsusf_cougar\pictures\rhs_cgrcat1a2_armed_pic_ca.paa"; 
};
class BoatSpawnerMarker: AttackSpawnerMarker
{
  name = "Boat Spawner Marker"; 
  icon = "\a3\ui_f\data\igui\cfg\simpletasks\types\Boat_ca.paa"; 
};
