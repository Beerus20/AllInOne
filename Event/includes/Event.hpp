#ifndef EVENT_HPP
# define EVENT_HPP

# include <SDL2/SDL_events.h>
# include "../../includes/typedefs.hpp"
# include "../../EventManager/includes/EventManager.hpp"

struct Mouse
{
	int		x;
	int		y;
	int		gapX;
	int		gapY;
};

class Event
{
	private:
		static SDL_Event		_listener;
		static EventManager		_event_manager;
		static Box				*_fbox;
		static Mouse			_mouse;

		Event(void);
		Event(Event const &);

		Event					&operator=(Event const &);
		static bool				checkEvents(void);
		static bool				loopEvent(EventList *);
		static int				defaultMouseMotion(SDL_Event *, Box *);
		static int				defaultMouseButtonUp(SDL_Event *, Box *);
		static int				defaultMouseButtonDown(SDL_Event *, Box *);
		static int				defaultKeyDown(SDL_Event *, Box *);

	public:
		virtual ~Event(void);

		static void				init(void);

		static bool				wait(void);
		static bool				poll(void);
		static bool				waitTimeout(int timeout = 20);

		static SDL_Event		*getListener(void);
};

#endif
