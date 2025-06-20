#include "Draw.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>

void	Draw::point(int x, int y) const
{
	SDL_RenderDrawPoint(this->_renderer, x, y);
}

void	Draw::points(cPoint *points, Uint32 nb) const
{
	SDL_RenderDrawPoints(this->_renderer, points, nb);
}

void	Draw::line(int x1, int y1, int x2, int y2) const
{
	SDL_RenderDrawLine(this->_renderer, x1, y1, x2, y2);
}

void	Draw::lines(cPoint *points, Uint32 nb) const
{
	SDL_RenderDrawLines(this->_renderer, points, nb);
}

void	Draw::rect(cRect *r) const
{
	SDL_RenderDrawRect(this->_renderer, r);
}

void	Draw::rects(cRect *r, Uint32 nb) const
{
	SDL_RenderDrawRects(this->_renderer, r, nb);
}

void	Draw::fillRect(cRect *r) const
{
	SDL_RenderFillRect(this->_renderer, r);
}

void	Draw::fillRects(cRect *r, Uint32 nb) const
{
	SDL_RenderFillRects(this->_renderer, r, nb);
}
