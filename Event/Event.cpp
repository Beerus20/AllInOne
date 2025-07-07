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

SDL_Event		Event::_listener;
Box				*Event::_fbox = NULL;
EventManager	Event::_event_manager;
Mouse			Event::_mouse;

Event	&Event::operator=(Event const &)
{
	return (*this);
}

void	Event::init(void)
{
	Event::_mouse = (Mouse){0, 0, 0, 0};
	Event::_event_manager.listen(KEY_DOWN, Event::defaultKeyDown);
	Event::_event_manager.listen(MOUSE_MOTION, Event::defaultMouseMotion);
	Event::_event_manager.listen(MOUSE_BUTTON_UP, Event::defaultMouseButtonUp);
	Event::_event_manager.listen(MOUSE_BUTTON_DOWN, Event::defaultMouseButtonDown);
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
	if (
		Event::_listener.type == SDL_QUIT ||
		!Event::loopEvent(Event::_event_manager.getEventList())
	)
		return (false);
	if (Event::_fbox != NULL)
	{
		Draw::in(dynamic_cast<Container *>(Event::_fbox));
		Event::loopEvent(Event::_fbox->getEventList());
		Draw::out();
	}
	return (true);
}

SDL_Event	*Event::getListener(void)
{
	return (&Event::_listener);
}
