#include "../includes/Engine.hpp"
#include <SDL2/SDL_stdinc.h>

SDL_bool	Engine::init(Types::t_system_flag system_flags)
{
	if (SDL_Init(system_flags) != 0)
		return (SDL_FALSE);

	return (SDL_TRUE);
}
