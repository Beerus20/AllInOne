#include "./includes/Config.hpp"

Map<std::string>::string	Config::Window;
Map<std::string>::string	Config::Engine;

Config::Config(void) {}
Config::Config(const Config &) {}
Config::~Config(void) {}
Config &Config::operator=(const Config &) { return (*this); }

void	Config::load(void)
{
	Config::Window = Config::load(WINDOW_DEFAULT_CONFIG_FILE_PATH);
	Config::Engine = Config::load(ENGINE_DEFAULT_CONFIG_FILE_PATH);
}

Map<std::string>::string	Config::load(std::string const &file_path)
{
	return (FileParser::parse(file_path));
}
