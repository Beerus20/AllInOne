#include "../includes/Window.hpp"
#include <SDL2/SDL_video.h>

void	Window::destroy(void)
{
	if (this->_addr != NULL)
		SDL_DestroyWindow(this->_addr);
}

void	Window::maximize(void)
{
	SDL_MaximizeWindow(this->_addr);
}

void	Window::minimize(void)
{
	SDL_MinimizeWindow(this->_addr);
}

void	Window::restore(void)
{
	SDL_RestoreWindow(this->_addr);
}

void	Window::hide(void)
{
	SDL_HideWindow(this->_addr);
}

void	Window::show(void)
{
	SDL_ShowWindow(this->_addr);
}

void	Window::raise(void)
{
	SDL_RaiseWindow(this->_addr);
}
