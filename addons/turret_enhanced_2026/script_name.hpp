/*
	(Turret Enhanced 2026 Version)
	Display name of the mod, used by the Addon Options categories, the Controls section and messages.
	Also change mod.cpp (name, tooltipOwned) and .hemtt/project.toml (name) when renaming.
*/

#define GLT_MOD_NAME "Turret Enhanced (2026 Version)"

/*
	PBO prefix = the root of every file path inside the addon (functions, images, XEH scripts).
	Paths in config.cpp are built from GLT_PREFIX, so renaming the prefix means changing:
		- GLT_PREFIX below
		- addons/main/$PBOPREFIX$
		- the 4 image paths in mod.cpp (mod.cpp is not preprocessed)
	SQF code does not contain the prefix: functions are reached through CfgFunctions.
*/
#define GLT_PREFIX Turret_Enhanced_2026

#define GLT_QUOTE(x) #x
#define GLT_PATH(f) \GLT_PREFIX\f
#define GLT_QPATH(f) GLT_QUOTE(GLT_PATH(f))
#define GLT_COMPILE(f) call compile preprocessFileLineNumbers 'GLT_PATH(f)'
