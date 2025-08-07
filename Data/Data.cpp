#include "./includes/Data.hpp"
#include "includes/Window.hpp"
#include <SDL2/SDL_stdinc.h>

Window	Data::window;

Data::Data(void) {}
Data::Data(const Data &) {}
Data::~Data(void) {}
Data &Data::operator=(const Data &) { return (*this); }

void	Data::loadWindowConfig(const std::string &path)
{
	Data::window.init(FileParser::parse(path));
}
