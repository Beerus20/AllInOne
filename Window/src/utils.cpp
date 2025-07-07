#include "../includes/Window.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <utility>
#include "../../Data/includes/Data.hpp"
#include <iostream>

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

void	Window::add(Container *container)
{
	if (container != NULL)
	{
		if (!container->getTexture())
			container->initTexture(this->getRenderer());
		this->_content.push_back(container);
		Data::addContent(container);
	}
	else
	 	Error::warning("You are trying to set a NULL container");
}
