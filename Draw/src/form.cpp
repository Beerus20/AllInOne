#include "../includes/Draw.hpp"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>

void	Draw::point(int x, int y, COLOR_DEFAULT_PARAMS)
{
	Draw::color(r, g, b, a);
	Error::check(
		SDL_RenderDrawPoint(Draw::_renderer, x, y) != 0,
		SDL_GetError());
}

void	Draw::rect(cRect *rect, COLOR_DEFAULT_PARAMS)
{
	Draw::color(r, g, b, a);
	Error::check(
		SDL_RenderDrawRect(Draw::_renderer, rect) != 0,
		SDL_GetError());
}

void	Draw::fillRect(crRect rect, COLOR_DEFAULT_PARAMS)
{
	Draw::color(r, g, b, a);
	Error::check(
		SDL_RenderFillRect(Draw::_renderer, rect) != 0,
		SDL_GetError());
}
