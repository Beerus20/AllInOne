#ifndef MAIN_TYPEDEFS_HPP
# define MAIN_TYPEDEFS_HPP

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <vector>
#include <map>

class Box;

enum event_type
{
	WINDOW_EVENT = SDL_WINDOWEVENT,
	SYSWM_EVENT = SDL_SYSWMEVENT,
	KEY_DOWN = SDL_KEYDOWN,
	KEY_UP = SDL_KEYUP,
	TEXT_EDITING = SDL_TEXTEDITING,
	TEXT_INPUT = SDL_TEXTINPUT,
	MOUSE_MOTION = SDL_MOUSEMOTION,
	MOUSE_BUTTON_UP	= SDL_MOUSEBUTTONUP,
	MOUSE_BUTTON_DOWN = SDL_MOUSEBUTTONDOWN,
	MOUSE_WHEEL = SDL_MOUSEWHEEL,
};

typedef SDL_Window *					WindowAddr;
typedef SDL_Window *__restrict__		rWindowAddr;
typedef SDL_Renderer *					Renderer;
typedef SDL_Renderer *__restrict__		rRenderer;
typedef SDL_Texture *					Texture;
typedef SDL_Texture *__restrict__		rTexture;
typedef std::vector<Texture>			Textures;
typedef std::vector<Box *>				Boxs;
typedef std::vector<Box *__restrict__>	rBoxs;
typedef int (*onEvent)(SDL_Event *__restrict__, Box *__restrict__);
typedef std::map<event_type, onEvent>	EventList;

#endif
