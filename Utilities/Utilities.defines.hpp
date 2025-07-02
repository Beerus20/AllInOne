#ifndef UTILITIES_DEFINES_HPP
# define UTILITIES_DEFINES_HPP

// COLOR --------------------------------------------------------------------------------------------------------
# define _DEFAULT_COLOR_				int r = 245, int g = 245, int b = 245, int a =255 //<== __WHITESMOKE__
# define _COLOR_						int r, int g, int b, int a

// BOX --------------------------------------------------------------------------------------------------------
# define _BOX(box)						(box.getX()), (box.getY()), (box.getW()), (box.getH())
# define _COOR(coor)					(coor.x), (coor.y)
# define _DIM(dim)						(dim.w), (dim.h)

// WINDOWS --------------------------------------------------------------------------------------------------------
# define INIT_FLAGS						SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_EVENTS
# define WINDOW_FLAGS					SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
// # define WINDOW_FLAGS					SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_RESIZABLE
# define WINDOW_WIDTH					800
# define WINDOW_HEIGHT					500
# define WINDOW_POS_CENTER				(SDL_WINDOWPOS_CENTERED), (SDL_WINDOWPOS_CENTERED)
# define DELAY							5000
# define WINDOW_FULLSCREEN				SDL_WINDOW_FULLSCREEN
# define WINDOW_FULLSCREEN_DESKTOP		SDL_WINDOW_FULLSCREEN_DESKTOP
# define _WINDOW(window)				(window->getX()), (window->getY()), (window->getW()), (window->getH())
# define WINDOW_DEFAULT_CONFIG			int x = SDL_WINDOWPOS_CENTERED,\
										int y = SDL_WINDOWPOS_CENTERED,\
										int w = WINDOW_WIDTH,\
										int h = WINDOW_HEIGHT,\
										int iflags = INIT_FLAGS,\
										int wflags = WINDOW_FLAGS

// TEXTURE --------------------------------------------------------------------------------------------------------
# define TEXTURE_DEFAULT_WIDTH			200
# define TEXTURE_DEFAULT_HEIGHT			200
# define TEXTURE_DEFAULT_SIZE			TEXTURE_DEFAULT_WIDTH, TEXTURE_DEFAULT_HEIGHT
# define TEXTURE_DEFAULT_FORMAT			SDL_PIXELFORMAT_RGBA8888
# define TEXTURE_DEFAULT_ACCESS			SDL_TEXTUREACCESS_TARGET
# define TEXTURE_DEFAULT_FORMAT_ACCESS	TEXTURE_DEFAULT_FORMAT,TEXTURE_DEFAULT_ACCESS
# define TEXTURE_DEFAULT_CONFIG			int w = TEXTURE_DEFAULT_WIDTH,\
										int h = TEXTURE_DEFAULT_HEIGHT,\
										Uint32 format = TEXTURE_DEFAULT_FORMAT,\
										int access = TEXTURE_DEFAULT_ACCESS

#endif
