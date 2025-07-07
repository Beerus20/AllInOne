#include "includes/Draw.hpp"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <cstddef>
#include "../Window/includes/Window.hpp"


Draw::Draw(void) {}
Draw::Draw(Draw const &) {}
Draw::~Draw(void) {}

Draw	&Draw::operator=(Draw const &)
{
	return (*this);
}

Renderer	Draw::_renderer = NULL;

bool	Draw::verify(cstring &error_msg)
{
	if (Draw::_renderer == NULL)
	{
		Error::warning(error_msg);
		return (false);
	}
	return (true);
}

void	Draw::in(Renderer renderer)
{
	if (renderer == NULL)
		Error::warning("NULL renderer setted");
	else
	{
		if (Draw::_renderer != renderer)
			Draw::_renderer = renderer;
	}
}

void	Draw::in(Window *window)
{
	Draw::in(window->getRenderer());
}

void	Draw::in(Container *container)
{
	if (Draw::_renderer == NULL)
		Error::warning("You are trying to draw in an empty Renderer");
	else
	{
		Error::check(
			SDL_SetRenderTarget(Draw::_renderer, container->getTexture()) != 0,
			SDL_GetError());
	}
}

void	Draw::out(void)
{
	SDL_SetRenderTarget(Draw::_renderer, NULL);
}

void	Draw::apply(void)
{
	SDL_RenderPresent(Draw::_renderer);
}

void	Draw::clear(void)
{
	Error::check(
		SDL_RenderClear(Draw::_renderer) != 0,
		SDL_GetError());
}
