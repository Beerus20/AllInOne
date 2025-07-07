#ifndef EVENT_MANAGER_HPP
# define EVENT_MANAGER_HPP

# include "../../includes/typedefs.hpp"
# include "defines.hpp"
# include <SDL2/SDL_events.h>
# include <SDL2/SDL_stdinc.h>

class EventManager
{
	protected:
		EventList			_event_list;

		void				initEventManager(void);
	public:
		EventManager(void);
		EventManager(EventManager const &);
		virtual ~EventManager(void);

		EventManager		&operator=(EventManager const &);

		bool				listen(event_type, onEvent);
		EventList 			*getEventList(void);
};

#endif
