#include "Window.hpp"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>
# include <SDL2/SDL.h>
#include <cstdlib>
#include <iostream>

Window::Window(void) :
	_title("Window"),
	_box(WINDOW_POS_CENTER, WINDOW_WIDTH, WINDOW_HEIGHT),
	_iflags(INIT_FLAGS),
	_wflags(WINDOW_FLAGS)
{
	std::cout << "Creation of window" << std::endl;
	if (SDL_Init(this->_iflags) != 0)
		this->Error("Error SDL_init");
	SDL_CreateWindow("Window", _b(this->_box), this->_iflags);
}

Window::Window(cstring &title, int x, int y, int w, int h, int iflags, int wflags) :
	_title(title),
	_box(x, y, w, h),
	_iflags(iflags),
	_wflags(wflags)
{
	// if ()
}

// Window::Window(Uint32 flags)
// {
// 	if (SDL_Init(flags) != 0)
// 		this->Error("Error SDL_init");
// }

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

void	Window::create(cstring &title, int x, int y, int w, int h, Uint32 wflags)
{
	SDL_CreateWindow(title.c_str(), x, y, w, h, wflags);
}

void	Window::Error(string const &message, bool quit, int exit_status)
{
	std::cout << message << " : " << SDL_GetError() << std::endl;
	if (quit) exit(exit_status);
}