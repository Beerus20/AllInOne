#include "includes/Utils.hpp"
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>

Utils::Utils(void) {}
Utils::Utils(Utils const &) {}
Utils::~Utils(void) {}

Utils	&Utils::operator=(Utils const &)
{
	return (*this);
}

void	Utils::delay(Uint32 ms)
{
	SDL_Delay(ms);
}
