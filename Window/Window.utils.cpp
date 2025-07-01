#include "Window.hpp"
#include "../Draw/Draw.hpp"


void	Window::delay(Uint32 ms)
{
	SDL_Delay(ms);
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

void	Window::setFullScreen(Uint32 mode)
{
	if (SDL_SetWindowFullscreen(this->_addr, mode) != 0)
		this->Error("FullScreen mode error", false);
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
