#include "Utilities.hpp"
#include <SDL2/SDL_pixels.h>
#include "../Data/Data.hpp"

Utilities::Utilities(void) {}
Utilities::Utilities(Utilities const &) {}
Utilities::~Utilities(void) {}
Utilities	&Utilities::operator=(Utilities const &)
{
	return (*this);
}

Uint32	Utilities::RGBToInt(Uint8 r, Uint8 g, Uint8 b)
{
	return (SDL_MapRGB(Data::getPixelFormat(), r, g, b));
}

Uint32	Utilities::RGBAToInt(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	return (SDL_MapRGBA(Data::getPixelFormat(), r, g, b, a));
}


void	Utilities::intToRGB(
	Uint32 pixel,
	Uint8 *__restrict__ r,
	Uint8 *__restrict__ g,
	Uint8 *__restrict__ b)
{
	SDL_GetRGB(pixel, Data::getPixelFormat(), r, g, b);
}

void	Utilities::intToRGBA(
	Uint32 pixel,
	Uint8 *__restrict__ r,
	Uint8 *__restrict__ g,
	Uint8 *__restrict__ b,
	Uint8 *__restrict__ a)
{
	SDL_GetRGBA(pixel, Data::getPixelFormat(), r, g, b, a);
}
