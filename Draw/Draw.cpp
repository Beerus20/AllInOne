#include "Draw.hpp"
#include <SDL2/SDL_blendmode.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <iostream>

Draw::Draw(void) : _renderer(NULL) {}
Draw::Draw(Renderer *) : _renderer(NULL) {}
Draw::~Draw(void)
{
	this->destroy();
}

Draw::Draw(Draw const &) {}

Draw	&Draw::operator=(Draw const &assign)
{
	if (this != &assign)
		this->_renderer = assign._renderer;
	return (*this);
}

Draw::operator bool() const
{
	return (this->_renderer != NULL);
}

void	Draw::setRenderer(Renderer *renderer)
{
	if (this->_renderer != renderer)
		this->_renderer = renderer;
}

Renderer	*Draw::getRenderer(void) const
{
	return (this->_renderer);
}

void	Draw::apply(void) const
{
	SDL_RenderPresent(this->_renderer);
}

void	Draw::clear(void) const
{
	if (SDL_RenderClear(this->_renderer))
		std::cerr << "Clear renderer error" << std::endl;
}

void	Draw::color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const
{
	if (SDL_SetRenderDrawColor(this->_renderer, r, g, b, a) != 0)
		std::cerr
			<< "Can't apply color : ("
			<< r << ", "
			<< g << ", "
			<< b << ", "
			<< a << ")." << std::endl;
}

void	Draw::destroy(void)
{
	if (this->_renderer)
		SDL_DestroyRenderer(this->_renderer);
}

