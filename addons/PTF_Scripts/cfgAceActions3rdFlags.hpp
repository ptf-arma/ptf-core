class PTF_3rd_Flags : PTF_Flag_Raise
{
    displayName = "3rd Platoon Flags";
    icon = "\z\PTF\addons\PTF_Textures\Icons\flagup_ico.paa";
    class 3_flag_Raise : PTF_Flag_Raise
    {
        displayName = "Raise 3rd Platoon Flag";
        statement = "0 = [_target, ""3flag.paa""] call PTF_fnc_FlagRaise";
    };
    class 31_flag_Raise : PTF_Flag_Raise
    {
        displayName = "Raise 3-1 Flag";
        statement = "0 = [_target, ""31flag.paa""] call PTF_fnc_FlagRaise";
    };
    class 32_flag_Raise : PTF_Flag_Raise
    {
        displayName = "Raise 3-2 Flag";
        statement = "0 = [_target, ""32flag.paa""] call PTF_fnc_FlagRaise";
    };
    class 33_flag_Raise : PTF_Flag_Raise
    {
        displayName = "Raise 3-3 Flag";
        statement = "0 = [_target, ""33flag.paa""] call PTF_fnc_FlagRaise";
    };
    class 34_flag_Raise : PTF_Flag_Raise
    {
        displayName = "Raise 3-4 Flag";
        statement = "0 = [_target, ""34flag.paa""] call PTF_fnc_FlagRaise";
    };
};
