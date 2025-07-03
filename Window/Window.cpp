#include "includes/Window.hpp"
#include "includes/defines.hpp"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>
#include <cstddef>
#include <iostream>

Window::Window(void) :
	Box(WINDOW_DEFAULT_PARAMS),
	_flags(WINDOW_DEFAULT_FLAGS),
	_addr(NULL)
{
	this->init(this->_title, _WRECT(this));
}

Window::Window(Window const &to_copy)
{
	*this = to_copy;
}

Window::~Window(void)
{
	std::cout << "Window destroyed" << std::endl;
}

Window	&Window::operator=(Window const &) { return (*this); }

void	Window::init(
	std::string const &title,
	int x,
	int y,
	int w,
	int h,
	int flags)
{
	this->_addr = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
	if (this->_addr == NULL)
		Error::add(ERROR, SDL_GetError());

}