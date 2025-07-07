#include "includes/Data.hpp"
#include "../Container/includes/Container.hpp"
#include <SDL2/SDL_stdinc.h>
#include "../Window/includes/Window.hpp"
#include <cstddef>
#include <iostream>
#include "../Event/includes/Event.hpp"

bool	Data::isInited = false;
Map		Data::map;


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
	SDL_DisplayMode		dm;

	if (SDL_Init(flags) != 0)
		Error::add(ERROR, SDL_GetError());
	SDL_GetDesktopDisplayMode(0, &dm);
	for (int y(0); y < dm.h; y++)
	{
		std::vector<Box *>	row(dm.w, NULL);
		Data::map.push_back(row);
	}
	if (Error::nb == 0)
		Data::isInited = true;
	Event::init();
}

void	Data::addContent(Box *__restrict__ container)
{
	int	w(container->getX() + container->getW());
	int	h(container->getY() + container->getH());
	int	x(container->getX());
	int	y;

	while (x < w)
	{
		y = container->getY();
		while (y < h)
			Data::map[y++][x] = container;
		x++;
	}
}
