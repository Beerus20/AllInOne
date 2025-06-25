#include "Draw.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>

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

void	Draw::rects(cRect *r, Uint32 nb)
{
	SDL_RenderDrawRects(Data::getRenderer(), r, nb);
}

void	Draw::fillRect(cRect *rect, _COLOR_)
{
	Draw::color(r, g, b, a);
	SDL_RenderFillRect(Data::getRenderer(), rect);
}

void	Draw::fillRects(cRect *r, Uint32 nb)
{
	SDL_RenderFillRects(Data::getRenderer(), r, nb);
}
