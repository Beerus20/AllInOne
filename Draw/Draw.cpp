#include "Draw.hpp"
#include <SDL2/SDL_blendmode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
#include "../Container/Container.hpp"

Draw::Draw(void) {}
Draw::Draw(Draw const &) {}
Draw::~Draw(void){}
Draw	&Draw::operator=(Draw const &) { return (*this); }

void	Draw::apply(void)
{
	Draw::removeTarget();
	SDL_RenderPresent(Data::getRenderer());
}

void	Draw::clear(void)
{
	if (SDL_RenderClear(Data::getRenderer()))
		std::cerr << "Clear renderer error" << std::endl;
}

void	Draw::color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	if (SDL_SetRenderDrawColor(Data::getRenderer(), r, g, b, a) != 0)
		std::cerr
			<< "Can't apply color : ("
			<< r << ", "
			<< g << ", "
			<< b << ", "
			<< a << ")." << std::endl;
}

cTexture	*Draw::target(void)
{
	return (SDL_GetRenderTarget(Data::getRenderer()));
}

bool	Draw::addTarget(Texture *texture)
{
	return (SDL_SetRenderTarget(Data::getRenderer(), texture) == 0);
}

bool	Draw::removeTarget(void)
{
	return (SDL_SetRenderTarget(Data::getRenderer(), NULL) == 0);
}

bool	Draw::in(Texture *texture)
{
	if (Data::isNull())
		return (false);
	Draw::removeTarget();
	return (Draw::addTarget(texture));
}

bool	Draw::in(Container *container)
{
	return (Draw::in(container->getTexture()));
}

bool	Draw::texture(Texture *__restrict__ texture, cRect *__restrict__ src, cRect *__restrict__ dst)
{
	return (SDL_RenderCopy(
		Data::getRenderer(),
		texture,
		src,
		dst) == 0);
}
