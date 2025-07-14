#include "../includes/Draw.hpp"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <cstddef>
#include "../../Data/includes/Data.hpp"
#include "../../Window/includes/defines.hpp"

void	Draw::color(COLOR_DEFAULT_PARAMS)
{
	Error::check(
		SDL_SetRenderDrawColor(Draw::_renderer, r, g, b, a) != 0,
		SDL_GetError());
}

void	Draw::color(Color const &color)
{
	Draw::color(
		color.getR(),
		color.getG(),
		color.getB(),
		color.getA());
}

void	Draw::backgroundColor(COLOR_DEFAULT_PARAMS)
{
	Draw::color(r, g, b, a);
	Draw::clear();
}

void	Draw::backgroundColor(Color const &color)
{
	Draw::color(color);
	Draw::clear();
}

void	Draw::showPixel(void)
{
	SDL_Texture	*texture = SDL_CreateTexture(
		Draw::_renderer,
		PIXEL_FORMAT, 
		SDL_TEXTUREACCESS_STREAMING,
		WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT);
	SDL_PixelFormat	*format = SDL_AllocFormat(PIXEL_FORMAT);
	void	*tmp(NULL);
	Uint32	*pixels;
	int		pitch;
	SDL_LockTexture(texture, NULL, &tmp, &pitch);
	pixels = static_cast<Uint32 *>(tmp);
	for (int i(0); i < WINDOW_DEFAULT_HEIGHT; i++)
	{
		for (int j(0); j < WINDOW_DEFAULT_WIDTH; j++)
		{
			if (Data::map[i][j] != NULL)
				pixels[i * WINDOW_DEFAULT_WIDTH + j] = SDL_MapRGBA(format, 255, 0, 0, 255);
			else
				pixels[i * WINDOW_DEFAULT_WIDTH + j] = SDL_MapRGBA(format, 10, 100, 78, 255);
		}
	}
	SDL_UpdateTexture(texture, NULL, pixels, sizeof(Uint32) * WINDOW_DEFAULT_WIDTH);
	SDL_UnlockTexture(texture);
	SDL_FreeFormat(format);
	SDL_RenderCopy(Draw::_renderer, texture, NULL, NULL);
	// SDL_UnlockTexture(texture);
	SDL_DestroyTexture(texture);
}