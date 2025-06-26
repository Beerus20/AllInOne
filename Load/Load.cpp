#include "Load.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <iostream>
#include "../Data/Data.hpp"

Load::Load(void) {}
Load::Load(Load const &) {}
Load::~Load(void) {}
Load	&Load::operator=(Load const &) { return (*this); }

Surface	*Load::_surface = NULL;

Texture	*Load::image(cstring &image_path)
{
	Texture	*texture(NULL);

	Load::_surface = SDL_LoadBMP(image_path.c_str());
	if (!Load::_surface)
	{
		std::cerr << "Loading image error" << std::endl;
		return (NULL);
	}
	texture = SDL_CreateTextureFromSurface(Data::getRenderer(), Load::_surface);
	if (!texture)
	{
		std::cerr << "Image creation error" << std::endl;
		return (NULL);
	}
	SDL_FreeSurface(Load::_surface);
	Load::_surface = NULL;
	return (texture);
}
