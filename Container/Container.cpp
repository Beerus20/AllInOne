#include "includes/Container.hpp"
#include "includes/defines.hpp"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <cstddef>
#include "../Draw/includes/Draw.hpp"

Container::Container(void) :
	Box(CONTAINER_DEFAULT_VALUE)
{
	this->_src = *this->toRect();
}

Container::Container(Container const &) :
	Box()
{}

Container::~Container(void)
{
	this->destroy();
}

Container	&Container::operator=(Container const &)
{
	return (*this);
}

bool	Container::initTexture(Renderer renderer, Uint32 format, int access)
{
	this->_texture = SDL_CreateTexture(renderer, format, access, this->getW(), this->getH());
	if (this->_texture == NULL)
	{
		Error::warning(SDL_GetError());
		return (false);
	}
	return (true);
}

void	Container::destroy(void)
{
	if (this->_texture != NULL)
		SDL_DestroyTexture(this->_texture);
}

bool	Container::draw(void)
{
	Draw::rect(this->toRect());
	return (true);
}
