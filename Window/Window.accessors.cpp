#include "Window.hpp"
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_video.h>

// SETTERS =================================================================
void	Window::setTitle(cstring &title)
{
	this->_title = title;
	SDL_SetWindowTitle(this->_addr, this->_title.c_str());
}

void	Window::setPosition(int x, int y)
{
	this->_box.setCoor(x, y);
	SDL_SetWindowPosition(this->_addr, x, y);
}

void	Window::setPosition(t_coor const &coor)
{
	this->_box.setCoor(coor);
	SDL_SetWindowPosition(this->_addr, _COOR(coor));
}

void	Window::setSize(int w, int h)
{
	this->_box.setDimension(w, h);
	SDL_SetWindowSize(this->_addr, w, h);
}

void	Window::setSize(t_dimension const &dimension)
{
	this->_box.setDimension(dimension);
	SDL_SetWindowSize(this->_addr, _DIM(dimension));
}


// GETTERS =================================================================
cstring	&Window::getTitle(void) const
{
	return (this->_title);
}

t_coor const	&Window::getPosition(void) const
{
	return (this->_box.getCoor());
}

t_dimension const	&Window::getSize(void) const
{
	return (this->_box.getDimension());
}

int const	&Window::getWFlags(void) const
{
	return (this->_wflags);
}

Draw	*Window::getDraw(void)
{
	return (&(this->_draw));
}
