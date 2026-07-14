////// Menu


class RscControlsgroupNoHScrollbars;
class RscStandardDisplay;
class Rscpicture;
class RscControlsGroupNoScrollbars;
class RscPictureKeepAspect;
class RscVideo;
class RscButton;
class RscText;
class RscStructuredText; 
class RscButtonMenuMain;
class ace_arsenal_display;
class GroupSingleplayer : RscControlsGroupNoScrollbars {
		class Controls {
			class Campaigns : RscButtonMenuMain {};
		};
};

class GroupTutorials : GroupSingleplayer {
	class Controls : Controls {
		class ace_arsenal_display : ace_arsenal_display {};
	};
};

class GroupMultiplayer : GroupSingleplayer {
	class Controls : Controls {};
};

////////
