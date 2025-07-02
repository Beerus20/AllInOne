#include "Window.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>
#include <iostream>
#include "../Data/Data.hpp"

Window::Window(void) :
	Box(WINDOW_POS_CENTER, WINDOW_WIDTH, WINDOW_HEIGHT),
	_title("Window"),
	_iflags(INIT_FLAGS),
	_wflags(WINDOW_FLAGS),
	_addr(NULL)
{
	std::cout << "Creation of window" << std::endl;
	this->create("Window", _WINDOW(this), this->_wflags);
}

Window::Window(cstring &title, int x, int y, int w, int h, int iflags, int wflags) :
	Box(x, y, w, h),
	_title(title),
	_iflags(iflags),
	_wflags(wflags),
	_addr(NULL)
{
	this->create(title, x, y, w, h, this->_wflags);
}

Window::Window(Window const &to_copy) :
	Box()
{
	*this = to_copy;
}

Window::~Window(void)
{
	std::cout << "Window destroyed" << std::endl;
	this->destroy();
}

Window	&Window::operator=(Window const &) { return (*this); }

inline void	Window::Error(string const &message, bool quit, int exit_status)
{
	std::cout << message << " : " << SDL_GetError() << std::endl;
	if (quit)
	{
		this->destroy();
		exit(exit_status);
	}
}

void	Window::create(cstring &title, int x, int y, int w, int h, Uint32 wflags)
{
	if (SDL_Init(this->_iflags) != 0)
		this->Error("Initialisation Error");
	this->_addr = SDL_CreateWindow(title.c_str(), x, y, w, h, wflags);
	if (this->_addr == NULL)
		this->Error("Window initialisation error");
	Data::setRenderer(SDL_CreateRenderer(this->_addr, -1, SDL_RENDERER_ACCELERATED));
	if (Data::isNull())
		this->Error("Draw initialisation error");
}

void	Window::loop(void)
{
	SDL_bool	quit(SDL_FALSE);

	while (!quit)
	{
		SDL_WaitEvent(&this->_event);
		if (this->_event.type == SDL_QUIT)
			quit = SDL_TRUE;
		std::cout << "called" << std::endl;
	}
}
