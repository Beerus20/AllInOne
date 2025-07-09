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

void	Data::test(Box *box, int x, int y)
{
	int	x1(box->getX());
	int	y1(box->getY());

	for (int j(y); j < y + box->getH(); j++)
	{
		for (int i(box->getW() + x1); i < x + box->getW(); i++)
			Data::map[j][i] = box;
	}
	for (int j(y1); y1 < y1 + box->getH(); j++)
	{
		for (int i(x1); i < x; i++)
			Data::map[j][i] = NULL;
	}
}

void	Data::updateMap(Box *box, int x, int y)
{
	if ((x < 0 && y < 0) || box == NULL)
		return ;
	int	x1(box->getX());
	int	y1(box->getY());

	if (x1 < x)
	{
		for (int i(x); i < x1 + box->getW(); i++)
		for (int j(y); j < (box->getH() + y); j++)
		{
			for (int i(x); i < (box->getW() + x); i++)
				Data::map[j][i] = box;
		}
	}
}