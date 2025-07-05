#ifndef EVENT_MANAGER_HPP
# define EVENT_MANAGER_HPP

# include "../../includes/typedefs.hpp"
# include "defines.hpp"
#include <SDL2/SDL_stdinc.h>

class EventManager
{
	private:
		// Event			_event;
		EventList		_event_list;

	public:
		EventManager(void);
		EventManager(EventManager const &);
		virtual ~EventManager(void);

		EventManager	&operator=(EventManager const &);

		// bool			wait(void);
		// bool			poll(void);
		// bool			waitTimeout(int timeout = 20);
		// bool			checkEvents(void);

		bool			add(event_type, onEvent);

};

#endif
