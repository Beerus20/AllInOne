#include "./includes/Types.hpp"

Types::Types(void) {}
Types::Types(const Types &) {}
Types::~Types(void) {}
Types &Types::operator=(const Types &) { return (*this); }

const std::map<std::string, Types::t_system_flag>	Types::flags::System =
{
	{"TIMER", TIMER},
	{"AUDIO", AUDIO},
	{"VIDEO", VIDEO},
	{"JOYSTICK", JOYSTICK},
	{"GAMECONTROLLER", GAMECONTROLLER},
	{"EVENTS", EVENTS},
	{"EVERYTHING", EVERYTHING}
};

const std::map<std::string, Types::t_window_flag>	Types::flags::Window =
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
