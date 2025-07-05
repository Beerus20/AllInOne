#include "includes/Error.hpp"
#include "includes/enums.hpp"
#include "includes/typedefs.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <utility>

Error::Error(void) {}
Error::Error(Error const &) {}
Error::~Error(void) {}

unsigned int	Error::nb = 0;
error_list		Error::_list;

Error	&Error::operator=(Error const &)
{
	return (*this);
}

void	Error::warning(std::string const &message)
{
	std::cout
		<< "WARNING" << std::endl
		<< "TYPES : " << message << std::endl;
}

void	Error::debug(std::string const &message)
{
	std::cout
		<< "DEBUG" << std::endl
		<< "TYPES : " << message << std::endl;
}

void	Error::info(std::string const &message)
{
	std::cout
		<< "INFO" << std::endl
		<< "TYPES : " << message << std::endl;
}

void	Error::error(std::string const &message)
{
	std::cout
		<< "ERROR" << std::endl
		<< "TYPES : " << message << std::endl;
}

void	Error::add(error_status status, cstring &message)
{
	Error::_list.push_back(std::make_pair(status, message));
	Error::nb = Error::_list.size();
}

void	Error::check(bool condition, cstring &error_msg, cstring &succes_msg)
{
	if (condition)
	{
		if (!succes_msg.empty()) std::cout << succes_msg << std::endl;
	}
	else
	{
		if (!error_msg.empty()) std::cout << error_msg << std::endl;
	}

}