#include "../includes/Window.hpp"

std::string const	&Window::getTitle(void) const
{
	return (this->_title);
}

SDL_Rect const	&Window::getRect(void) const
{
	return (this->_rect);
}

t_window_flag const	&Window::getFlags(void) const
{
	return (this->_flag);
}

void	Window::setTitle(std::string const &title)
{
	this->_title = title;
}

void	Window::setRect(SDL_Rect rect)
{
	this->_rect = rect;
}

void	Window::setFlags(t_window_flag flag)
{
	this->_flag = flag;
}
