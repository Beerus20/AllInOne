#include "Error.hpp"
#include "../Utilities/Utilities.color.hpp"
#include <SDL2/SDL_error.h>
#include <iostream>

Error::Error(void) {}
Error::Error(Error const &) { }
Error::~Error(void) {}
Error	&Error::operator=(Error const &)
{
	return (*this);
}

void	Error::onfail(cstring &message, bool exit_on_fail)
{
		std::cerr << T_RED + message + T_END << std::endl;
		if (exit_on_fail) exit(1);
}

void	Error::check(bool condition, cstring &error_message, cstring &success_message, bool exit_on_fail)
{
	if (!condition)
		Error::onfail(error_message, exit_on_fail);
	else
		std::cout << T_GREEN + success_message + T_END << std::endl;
}

void	Error::check(bool condition, cstring &error_message, bool exit_on_fail)
{
	if (!condition)
		Error::onfail(error_message, exit_on_fail);
}

void	Error::sdl_check(bool condition, cstring &error_message, cstring &success_message, bool exit_on_fail)
{
	Error::check(
		condition,
		error_message + " : " + SDL_GetError(),
		success_message,
		exit_on_fail);
}

void	Error::sdl_check(bool condition, cstring &error_message, bool exit_on_fail)
{
	Error::check(
		condition,
		error_message + " : " + SDL_GetError(),
		exit_on_fail);
}
