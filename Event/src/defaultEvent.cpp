#include "../includes/Event.hpp"
#include "../../Data/includes/Data.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_mouse.h>
#include <iostream>

bool	Event::loopEvent(EventList *e)
{
	if (e == NULL) return (true);
	for (EventList::iterator it(e->begin()); it != e->end(); it++)
	{
		if (Event::_listener.type == it->first && it->second != NULL)
			return (!it->second(&Event::_listener, Event::_fbox));
	}
	return (true);
}

int	Event::defaultMouseMotion(SDL_Event *, Box *)
{
	Event::_fbox = Data::map[Event::_listener.motion.y][Event::_listener.motion.x];	
	if (Event::_fbox && (Event::_listener.motion.state & SDL_BUTTON_LEFT))
	{
		Event::_fbox->setX(Event::_listener.motion.x - Event::_mouse.gapX);
		Event::_fbox->setY(Event::_listener.motion.y - Event::_mouse.gapY);
	}
	return (0);
}

int	Event::defaultMouseButtonUp(SDL_Event *, Box *)
{
	Event::_mouse = (Mouse) {0, 0, 0, 0};
	return (0);
}

int	Event::defaultMouseButtonDown(SDL_Event *, Box *)
{
	if (Event::_fbox)
	{
		Event::_mouse.gapX = Event::_listener.button.x - Event::_fbox->getX();
		Event::_mouse.gapY = Event::_listener.button.y - Event::_fbox->getY();
	}
	return (0);
}

int	Event::defaultKeyDown(SDL_Event *, Box *)
{
	if (Event::_listener.key.keysym.sym == SDLK_ESCAPE)
		return (1);
	return (0);
}