#include "Load.hpp"
// #include <SDL2/SDL_image.h>

Load::Load(void) {}
Load::Load(Load const &) {}
Load::~Load(void) {}
Load	&Load::operator=(Load const &) { return (*this); }

Texture	*Load::image(cstring &image_path)
{
	(void)image_path;
	return (NULL);
	// int	flags = IMG_INIT_PNG
}
