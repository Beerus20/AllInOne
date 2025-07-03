#include "includes/Window.hpp"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_video.h>
#include <iostream>

Window::Window(void) :
	Box()
{
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