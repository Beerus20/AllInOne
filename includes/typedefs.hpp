#ifndef MAIN_TYPEDEFS_HPP
# define MAIN_TYPEDEFS_HPP

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <vector>
#include "../Box/includes/Box.hpp"

typedef SDL_Window*				WindowAddr;
typedef SDL_Renderer*			Renderer;
typedef SDL_Texture*			Texture;
typedef std::vector<Texture>	Textures;
typedef std::vector<Box *>		Boxs;

#endif
