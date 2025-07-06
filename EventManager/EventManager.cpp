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

EventManager::EventManager(rEvent event) :
	_event(event)
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

void	EventManager::setEvent(rEvent event)
{
	this->_event = event;
}

bool	EventManager::wait(void)
{
	if (!SDL_WaitEvent(this->_event))
	{
		Error::error(SDL_GetError());
		return (false);
	}
	return (this->checkEvents());
}


bool	EventManager::poll(void)
{
	while (SDL_PollEvent(this->_event))
	{
		if (!this->checkEvents())
			return (false);
	}
	return (true);
}

bool	EventManager::waitTimeout(int timeout)
{
	if (!SDL_WaitEventTimeout(this->_event, timeout))
	{
		Error::error(SDL_GetError());
		return (false);
	}
	return (this->checkEvents());
}

bool	EventManager::checkEvents(void)
{
	if (this->_event->type == SDL_QUIT)
		return (false);
	for (
		EventList::iterator it(this->_event_list.begin());
		it != this->_event_list.end();
		it++)
	{
		if (this->_event->type == it->first && it->second != NULL)
			it->second(this->_event);  
	}
	return (true);
}

bool	EventManager::add(event_type event, onEvent func)
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
