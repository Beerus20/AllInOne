#ifndef EVENT_HPP
# define EVENT_HPP

# include <SDL2/SDL_events.h>
# include "../../includes/typedefs.hpp"

class Event
{
	private:
		static SDL_Event		_listener;
		static EventList		*_event_list;
		static Box				*_fbox;

		Event(void);
		Event(Event const &);

		Event					&operator=(Event const &);
		static bool				checkEvents(void);

	public:
		virtual ~Event(void);

		static bool				wait(void);
		static bool				poll(void);
		static bool				waitTimeout(int timeout = 20);

		static void				setEventList(EventList *event_list);
};

#endif
