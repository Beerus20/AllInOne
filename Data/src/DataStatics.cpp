#include "../includes/Data.hpp"

const std::map<std::string, t_system_flag>	Data::SystemFlags =
{
	{"TIMER", TIMER},
	{"AUDIO", AUDIO},
	{"VIDEO", VIDEO},
	{"JOYSTICK", JOYSTICK},
	{"GAMECONTROLLER", GAMECONTROLLER},
	{"EVENTS", EVENTS},
	{"EVERYTHING", EVERYTHING}
};

const std::map<std::string, t_window_flag>	Data::WindowFlags =
{
	{"FULLSCREEN", FULLSCREEN},
	{"FULLSCREEN_DESKTOP", FULLSCREEN_DESKTOP},
	{"SHOWN", SHOWN},
	{"HIDDEN", HIDDEN},
	{"BORDERLESS", BORDERLESS},
	{"RESIZABLE", RESIZABLE},
	{"MINIMIZED", MINIMIZED},
	{"MAXIMIZED", MAXIMIZED},
	{"DEFAULT", DEFAULT_WFLAGS}
};
