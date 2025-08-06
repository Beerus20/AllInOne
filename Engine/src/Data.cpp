#include "../includes/Data.hpp"
#include <SDL2/SDL_stdinc.h>

Data::Window	Data::window("", 0, 0, 0, 0, DEFAULT_WFLAGS);

Data::Data(void) {}
Data::Data(const Data &) {}
Data::~Data(void) {}
Data &Data::operator=(const Data &) { return (*this); }

void	Data::loadWindowConfig(const std::string &path)
{
	Map<std::string>::string	file_content(FileParser::parse(path));

	Data::window.title = file_content.at("TITLE");
	Data::window.rect = (SDL_Rect) {
		Utils::convert<int>(
			file_content.at("X") == "center" ?
				SDL_WINDOWPOS_CENTERED :
				Utils::convert<int>(file_content.at("X"))),
		Utils::convert<int>(
			file_content.at("Y") == "center" ?
				SDL_WINDOWPOS_CENTERED :
				Utils::convert<int>(file_content.at("Y"))),
		Utils::convert<int>(file_content.at("WIDTH")),
		Utils::convert<int>(file_content.at("HEIGHT")),
	};
}

std::ostream& operator<<(std::ostream& os, const Data::Window &window)
{
	os
		<< "WINDOW title : [ " << Color::blue(window.title) << " ]" << std::endl
		<< "\trect" << " : " << window.rect << std::endl;
	return (os);
}
