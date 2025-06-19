#include "Window.hpp"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>
#include <cstdlib>
#include <iostream>

Window::Window(void) : _flags(SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_EVENTS)
{
	std::cout << "Creation of window" << std::endl;
	if (SDL_Init(this->_flags) != 0)
		this->Error("Error SDL_init");
	// SDL_CreateWindow("Window", 0, 0, 800, 500, this->_flags);
}

Window::Window(Uint32 flags)
{
	if (SDL_Init(flags) != 0)
		this->Error("Error SDL_init");
}

Window::Window(Window const &to_copy)
{
	*this = to_copy;
}

Window::~Window(void)
{
	std::cout << "Window destroyed" << std::endl;
	SDL_Quit();
}


Window	&Window::operator=(Window const &to_assign)
{
	(void)to_assign;
	return (*this);
}

void	Window::Error(string const &message, bool quit, int exit_status)
{
	std::cout << message << " : " << SDL_GetError() << std::endl;
	if (quit) exit(exit_status);
}