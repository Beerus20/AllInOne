#include "Window.hpp"

void	Window::delay(Uint32 ms)
{
	SDL_Delay(ms);
}

void	Window::destroy(void)
{
	Data::destroyPixelFormat();
	Data::destroy();
	if (this->_addr)
		SDL_DestroyWindow(this->_addr);
	SDL_Quit();
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

