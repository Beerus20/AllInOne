#include "Data.hpp"
#include <SDL2/SDL_pixels.h>
#include <cstddef>
#include "../Container/Container.hpp"

Data::Data(void) {}
Data::Data(Data const &) {}
Data::~Data(void)
{
	Data::destroyPixelFormat();
}

Data	&Data::operator=(Data const &) { return (*this); }

Renderer	*Data::renderer = NULL;
bool		Data::status = false;
PixelFormat	*Data::pixel_format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
Container	*Data::container_target = NULL;

void	Data::lock(void)
{
	Data::status = true;
}

void	Data::unlock(void)
{
	Data::status = false;
}

bool	Data::islocked(void)
{
	return (Data::status);
}

bool	Data::isNull(void)
{
	return (!Data::renderer);
}

void	Data::destroy(void)
{
	if (Data::renderer)
		SDL_DestroyRenderer(Data::renderer);
}

void	Data::destroyPixelFormat(void)
{
	if (Data::pixel_format)
		SDL_FreeFormat(Data::pixel_format);
}


