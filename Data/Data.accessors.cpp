#include "Data.hpp"


// SETTERS ===========================================================
void	Data::setRenderer(Renderer *__restrict__ renderer)
{
	Data::renderer = renderer;
}

void	Data::setPixelFormat(Uint32 format)
{
	Data::destroyPixelFormat();
	Data::pixel_format = SDL_AllocFormat(format);
}

// GETTERS ===========================================================
Renderer	*Data::getRenderer(void)
{
	return (Data::renderer);
}

PixelFormat	*Data::getPixelFormat(void)
{
	return (Data::pixel_format);
}
