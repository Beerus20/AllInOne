#include "Data.hpp"

Data::Data(void) {}
Data::Data(Data const &) {}
Data::~Data(void) {}
Data	&Data::operator=(Data const &) { return (*this); }

Renderer	*Data::renderer = NULL;
bool		Data::status = false;

void	Data::setRenderer(Renderer *__restrict__ renderer)
{
	Data::renderer = renderer;
}

Renderer	*Data::getRenderer(void)
{
	return (Data::renderer);
}

void	Data::lock(void)
{
	Data::status = true;
}

void	Data::unlock(void)
{
	Data::status = false;
}

bool	Data::islocked(void)
{
	return (Data::status);
}

bool	Data::isNull(void)
{
	return (!Data::renderer);
}

void	Data::destroy(void)
{
	if (Data::renderer)
		SDL_DestroyRenderer(Data::renderer);
}