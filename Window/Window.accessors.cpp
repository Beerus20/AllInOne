#include "Window.hpp"

// SETTERS =================================================================
void	Window::setTitle(cstring &title)
{
	this->_title = title;
	SDL_SetWindowTitle(this->_addr, this->_title.c_str());
}

void	Window::setPosition(int x, int y)
{
	this->setCoor(x, y);
	SDL_SetWindowPosition(this->_addr, x, y);
}

void	Window::setPosition(t_coor const &coor)
{
	this->setCoor(coor);
	SDL_SetWindowPosition(this->_addr, _COOR(coor));
}

void	Window::setSize(int w, int h)
{
	this->setDimension(w, h);
	SDL_SetWindowSize(this->_addr, w, h);
}

void	Window::setSize(t_dimension const &dimension)
{
	this->setDimension(dimension);
	SDL_SetWindowSize(this->_addr, _DIM(dimension));
}

void	Window::setBackgroundColor(int r, int g, int b, int a)
{
	Draw::removeTarget();
	Draw::color(r, g, b, a);
	Draw::clear();
}

void	Window::setBackgroundColor(Color const &color)
{
	Draw::removeTarget();
	Draw::color(color);
	Draw::clear();
}

void	Window::setFullScreen(Uint32 mode)
{
	if (SDL_SetWindowFullscreen(this->_addr, mode) != 0)
		this->Error("FullScreen mode error", false);
}

// GETTERS =================================================================
cstring	&Window::getTitle(void) const
{
	return (this->_title);
}

t_coor const	&Window::getPosition(void) const
{
	return (this->getCoor());
}

t_dimension const	&Window::getSize(void) const
{
	return (this->getDimension());
}

int const	&Window::getWFlags(void) const
{
	return (this->_wflags);
}
