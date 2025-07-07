#include "includes/Event.hpp"
#include <SDL2/SDL_events.h>
#include "../Error/includes/Error.hpp"
#include "../Data/includes/Data.hpp"
#include "../Box/includes/Box.hpp"
#include <cstddef>
#include <iostream>
#include "../Draw/includes/Draw.hpp"

Event::Event(void) {}
Event::Event(Event const &) {}
Event::~Event(void) {}

SDL_Event	Event::_listener;
EventList	*Event::_event_list = NULL;
Box			*Event::_fbox = NULL;

Event	&Event::operator=(Event const &)
{
	return (*this);
}

bool	Event::wait(void)
{
	if (!SDL_WaitEvent(&Event::_listener))
	{
		Error::error(SDL_GetError());
		return (false);
	}
	return (Event::checkEvents());
}


bool	Event::poll(void)
{
	while (SDL_PollEvent(&Event::_listener))
	{
		if (!Event::checkEvents())
			return (false);
	}
	return (true);

}

bool	Event::waitTimeout(int timeout)
{
	if (!SDL_WaitEventTimeout(&Event::_listener, timeout))
	{
		Error::error(SDL_GetError());
		return (false);
	}
	return (Event::checkEvents());
}

bool	Event::checkEvents(void)
{
	if (Event::_listener.type == SDL_QUIT)
		return (false);
	if (Event::_listener.type == MOUSE_MOTION)
	{
		Event::_fbox = Data::map[Event::_listener.motion.y][Event::_listener.motion.x];
		Event::_event_list = Event::_fbox ? Event::_fbox->getEventList() : NULL;
	}
	if (Event::_fbox != NULL && Event::_event_list != NULL)
	{
		Draw::in(dynamic_cast<Container *>(Event::_fbox));
		for (
			EventList::iterator it(Event::_event_list->begin());
			it != Event::_event_list->end();
			it++)
		{
			if (Event::_listener.type == it->first && it->second != NULL)
			{
				std::cout << "Draw here" << std::endl;
				it->second(&Event::_listener, Event::_fbox);
			}
		}
		Draw::clear();
		Draw::out();
	}
	return (true);
}

void	Event::setEventList(EventList *event_list)
{
	Event::_event_list = event_list;
}

SDL_Event	*Event::getListener(void)
{
	return (&Event::_listener);
}
