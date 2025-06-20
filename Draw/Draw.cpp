#include "Draw.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <iostream>

Draw::Draw(void) : _renderer(NULL) {}
Draw::Draw(SDL_Renderer *renderer) : _renderer(renderer) {}
Draw::~Draw(void)
{
	this->destroy();
}

Draw::Draw(Draw const &copy)
{
	*this = copy;
}

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

void	Draw::setRenderer(SDL_Renderer *renderer)
{
	if (this->_renderer != renderer)
		this->_renderer = renderer;
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

void	Draw::destroy(void) const
{
	if (this->_renderer)
		SDL_DestroyRenderer(this->_renderer);
}

void	Draw::test(void) const
{
	Texture	*texture;

	texture = SDL_CreateTexture(this->_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 200, 200);
	SDL_Rect rect = {50, 50, 100, 100};
	SDL_SetRenderDrawColor(this->_renderer, 150, 0, 150, 255); /* On dessine en violet */

	// SDL_SetRenderTarget(this->_renderer, texture); /* On va dessiner sur la texture */
	SDL_RenderFillRect(this->_renderer, &rect);
	// SDL_SetRenderTarget(this->_renderer, NULL);
	this->apply();
	SDL_Delay(2000);
	SDL_DestroyTexture(texture);
}
