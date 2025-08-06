#include "../includes/Engine.hpp"
#include <SDL2/SDL_stdinc.h>

SDL_bool	Engine::init(t_system_flag system_flags, t_window_flag window_flags)
{
	(void)window_flags;
	if (SDL_Init(system_flags) != 0)
		return (SDL_FALSE);

	return (SDL_TRUE);
}
