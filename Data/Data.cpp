#include "includes/Data.hpp"
#include "../Error/includes/Error.hpp"
#include <SDL2/SDL_error.h>

Data::Data(void) {}
Data::Data(Data const &) {}
Data::~Data(void)
{
	if (Error::nb == 0)
		SDL_Quit();
}

Data	&Data::operator=(Data const &)
{
	return (*this);
}


void	Data::init(int flags)
{
	if (SDL_Init(flags) != 0)
		Error::add(ERROR, SDL_GetError());
}
