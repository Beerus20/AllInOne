#include "includes/EventManager.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>
#include "../Error/includes/Error.hpp"

EventManager::EventManager(void)
{
	this->initEventManager();
}

EventManager::EventManager(EventManager const &) {}
EventManager::~EventManager(void) {}

EventManager	&EventManager::operator=(EventManager const &)
{
	return (*this);
}

void	EventManager::initEventManager(void)
{
	this->_event_list[WINDOW_EVENT] = NULL;
	this->_event_list[SYSWM_EVENT] = NULL;
	this->_event_list[KEY_DOWN] = NULL;
	this->_event_list[KEY_UP] = NULL;
	this->_event_list[TEXT_EDITING] = NULL;
	this->_event_list[TEXT_INPUT] = NULL;
	this->_event_list[MOUSE_MOTION] = NULL;
	this->_event_list[MOUSE_BUTTON_UP] = NULL;
	this->_event_list[MOUSE_BUTTON_DOWN] = NULL;
	this->_event_list[MOUSE_WHEEL] = NULL;
}

bool	EventManager::listen(event_type event, onEvent func)
{
	EventList::iterator	it(this->_event_list.find(event));

	if (it == this->_event_list.end())
	{
		Error::warning("You are trying to use one correct Event");
		return (false);
	}
	it->second = func;
	return (true);
}

EventList 	*EventManager::getEventList(void)
{
	return (&this->_event_list);
}
