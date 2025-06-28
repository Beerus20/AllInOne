#include "Data.hpp"


// SETTERS ===========================================================
void	Data::setRenderer(Renderer *__restrict__ renderer)
{
	if (Data::renderer)
		Data::destroy();
	Data::renderer = renderer;
}

void	Data::setPixelFormat(Uint32 format)
{
	Data::destroyPixelFormat();
	Data::pixel_format = SDL_AllocFormat(format);
}

void	Data::setContainerTarget(Container *container)
{
	Data::container_target = container;
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

Container	*Data::getContainerTarget(void)
{
	return (Data::container_target);
}
