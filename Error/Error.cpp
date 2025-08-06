#include "./includes/Error.hpp"
#include <SDL2/SDL_error.h>

Error::Error(void) {}
Error::Error(const Error &) {}
Error::~Error(void) {}
Error &Error::operator=(const Error &) { return (*this); }

void	Error::error(std::string const &message)
{
	(void)message;
	std::cout << "to define" << std::endl;
}

void	Error::error(std::string const &label, std::string const &message)
{
	(void)label;
	(void)message;
	std::cout << "to define" << std::endl;
}

void	Error::debug(std::string const &message)
{
	(void)message;
	std::cout << "to define" << std::endl;
}

void	Error::debug(std::string const &label, std::string const &message)
{
	(void)label;
	(void)message;
	std::cout << "to define" << std::endl;
}

void	Error::info(std::string const &message)
{
	(void)message;
	std::cout << "to define" << std::endl;
}

void	Error::info(std::string const &label, std::string const &message)
{
	(void)label;
	(void)message;
	std::cout << "to define" << std::endl;
}

void	Error::warning(std::string const &message)
{
	(void)message;
	std::cout << "to define" << std::endl;
}

void	Error::warning(std::string const &label, std::string const &message)
{
	(void)label;
	(void)message;
	std::cout << "to define" << std::endl;
}

void	Error::sdl(std::string const &label)
{
	std::cout << label << " : " << SDL_GetError() << std::endl;
}