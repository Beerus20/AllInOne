#include "../includes/Draw.hpp"

void	Draw::color(COLOR_DEFAULT_PARAMS)
{
	Error::check(
		SDL_SetRenderDrawColor(Draw::_renderer, r, g, b, a) != 0,
		SDL_GetError());
}

void	Draw::color(Color const &color)
{
	Draw::color(
		color.getR(),
		color.getG(),
		color.getB(),
		color.getA());
}

void	Draw::backgroundColor(COLOR_DEFAULT_PARAMS)
{
	Draw::color(r, g, b, a);
	Draw::clear();
}

void	Draw::backgroundColor(Color const &color)
{
	Draw::color(color);
	Draw::clear();
}
