#include "../includes/Window.hpp"
#include <SDL2/SDL_video.h>

// Setters ---------------------------------------------------------------------
void	Window::setTitle(cstring &title)
{
	this->_title = title;
	SDL_SetWindowTitle(this->_addr, this->_title.c_str());
}

// Getters ---------------------------------------------------------------------
cstring	&Window::getTitle(void) const
{
	return (this->_title);
}
