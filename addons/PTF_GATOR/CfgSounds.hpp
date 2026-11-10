// Sounds for say3D, played on each client by PTF_GATOR_fnc_soundLoop. Cut from Pixabay
// recordings and the owner's incoming alarm by tools/gator/import_sounds.py (see
// credits_and_license.txt).
// sound[] = {file, volume, pitch, audible distance in metres}
class CfgSounds
{
	// Loud, so it is still faintly heard, and placed, at its 2 km reach.
	class PTF_GATOR_alarm
	{
		name = "G/ATOR incoming alarm";
		sound[] = {"\z\PTF\addons\PTF_GATOR\sounds\alarm.ogg", 8.5, 1, 2000};
		titles[] = {};
	};
	// An anti-radiation missile homing on it (PTF_GATOR_fnc_armReport): Arma's own missile
	// lock warning, beeping at the trailer.
	class PTF_GATOR_armAlarm
	{
		name = "G/ATOR missile warning";
		sound[] = {"\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_1", 3, 1, 300};
		titles[] = {};
	};
	// A traced round coming down near a player (PTF_GATOR_fnc_splashWarn): Arma's own
	// "incoming" call, on their radio.
	class PTF_GATOR_incoming
	{
		name = "G/ATOR incoming call";
		sound[] = {"\A3\Dubbing_F_Warlords\announcer\BLUFOR\incoming.ogg", 1.5, 1};
		titles[] = {};
	};
	class PTF_GATOR_gen_start
	{
		name = "G/ATOR generator start";
		sound[] = {"\z\PTF\addons\PTF_GATOR\sounds\gen_start.ogg", 2, 1, 250};
		titles[] = {};
	};
	class PTF_GATOR_gen_loop
	{
		name = "G/ATOR generator running";
		sound[] = {"\z\PTF\addons\PTF_GATOR\sounds\gen_loop.ogg", 2, 1, 200};
		titles[] = {};
	};
	class PTF_GATOR_gen_stop
	{
		name = "G/ATOR generator stop";
		sound[] = {"\z\PTF\addons\PTF_GATOR\sounds\gen_stop.ogg", 2, 1, 200};
		titles[] = {};
	};
	class PTF_GATOR_radar_hum
	{
		name = "G/ATOR antenna running";
		sound[] = {"\z\PTF\addons\PTF_GATOR\sounds\radar_hum.ogg", 1.5, 1, 120};
		titles[] = {};
	};
	class PTF_GATOR_motor_start
	{
		name = "G/ATOR array motor start";
		sound[] = {"\z\PTF\addons\PTF_GATOR\sounds\motor_start.ogg", 4, 1, 100};
		titles[] = {};
	};
	class PTF_GATOR_motor_loop
	{
		name = "G/ATOR array motor";
		sound[] = {"\z\PTF\addons\PTF_GATOR\sounds\motor_loop.ogg", 4, 1, 100};
		titles[] = {};
	};
	// The same motor, smaller and higher, while a leg goes up or down.
	class PTF_GATOR_leg_motor
	{
		name = "G/ATOR leg motor";
		sound[] = {"\z\PTF\addons\PTF_GATOR\sounds\motor_loop.ogg", 2.5, 1.35, 50};
		titles[] = {};
	};
	class PTF_GATOR_leg_down
	{
		name = "G/ATOR leg down";
		sound[] = {"\z\PTF\addons\PTF_GATOR\sounds\leg_down.ogg", 2, 1, 60};
		titles[] = {};
	};
};
