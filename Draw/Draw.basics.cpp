#include "Draw.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <cstddef>
#include "../Container/Container.hpp"

void	Draw::point(int x, int y, _COLOR_)
{
	Draw::color(r, g, b, a);
	SDL_RenderDrawPoint(Data::getRenderer(), x, y);
}

void	Draw::points(cPoint *points, Uint32 nb)
{
	SDL_RenderDrawPoints(Data::getRenderer(), points, nb);
}

void	Draw::line(int x1, int y1, int x2, int y2, _COLOR_)
{
	Draw::color(r, g, b, a);
	SDL_RenderDrawLine(Data::getRenderer(), x1, y1, x2, y2);
}

void	Draw::lines(cPoint *points, Uint32 nb)
{
	SDL_RenderDrawLines(Data::getRenderer(), points, nb);
}

void	Draw::rect(cRect *rect, _COLOR_)
{
	Draw::color(r, g, b, a);
	SDL_RenderDrawRect(Data::getRenderer(), rect);
}

void	Draw::rect(cRect *rect, Color const &color)
{
	Draw::color(color);
	SDL_RenderDrawRect(Data::getRenderer(), rect);
}

void	Draw::rects(cRect *r, Uint32 nb)
{
	SDL_RenderDrawRects(Data::getRenderer(), r, nb);
}

void	Draw::fillRect(cRect *rect, _COLOR_)
{
	Draw::color(r, g, b, a);
	SDL_RenderFillRect(Data::getRenderer(), rect);
}

void	Draw::fillRect(cRect *rect, Color const &color)
{
	Draw::color(color);
	SDL_RenderFillRect(Data::getRenderer(), rect);
}

void	Draw::fillRects(cRect *r, Uint32 nb)
{
	SDL_RenderFillRects(Data::getRenderer(), r, nb);
}

void	Draw::box(Box *box, bool fill)
{
	if (fill)
		Draw::fillRect(box->toRect(), box->getColor());
	else
		Draw::rect(box->toRect(), box->getColor());
}

void	Draw::pixels(Uint32 (*func)(int, int), cRect *rect)
{
	Container	*container(Data::getContainerTarget());
	Uint32		*pixels(NULL);
	int			width(0);
	int			height(0);

	if (container == NULL || (*func) == NULL)
		return ;
	width = container->getW();
	height = container->getH();
	pixels = container->getPixels();
	for (int i(0); i < height; i++)
	{
		for (int j(0); j < width; j++)
			pixels[i * width + j] = (*func)(i, j);
	}
	SDL_UpdateTexture(container->getTexture(), rect, pixels, width * sizeof(Uint32));
}
