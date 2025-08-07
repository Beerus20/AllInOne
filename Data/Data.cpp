#include "./includes/Data.hpp"
#include <SDL2/SDL_stdinc.h>

Window	Data::window;

Data::Data(void) {}
Data::Data(const Data &) {}
Data::~Data(void) {}
Data &Data::operator=(const Data &) { return (*this); }

void	Data::init(void)
{
	Config::load();
	Data::window.init(Config::Window);
}


void	Data::init(std::string const &window_config_path)
{
	Data::window.init(Config::load(window_config_path));
}