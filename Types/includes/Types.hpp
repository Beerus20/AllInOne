#ifndef MY_TYPES_HPP
# define MY_TYPES_HPP

# include <SDL2/SDL.h>
# include <SDL2/SDL_video.h>
# include <map>
# include <string>

class Types
{
	public:
		typedef enum e_system_flag
		{
			TIMER = SDL_INIT_TIMER,
			AUDIO = SDL_INIT_AUDIO,
			VIDEO = SDL_INIT_VIDEO,
			JOYSTICK = SDL_INIT_JOYSTICK,
			GAMECONTROLLER = SDL_INIT_GAMECONTROLLER,
			EVENTS = SDL_INIT_EVENTS,
			EVERYTHING = SDL_INIT_EVERYTHING
		}	t_system_flag;

		typedef enum e_window_flag
		{
			FULLSCREEN = SDL_WINDOW_FULLSCREEN,
			FULLSCREEN_DESKTOP = SDL_WINDOW_FULLSCREEN_DESKTOP,
			SHOWN = SDL_WINDOW_SHOWN,
			HIDDEN = SDL_WINDOW_HIDDEN,
			BORDERLESS = SDL_WINDOW_BORDERLESS,
			RESIZABLE = SDL_WINDOW_RESIZABLE,
			MINIMIZED = SDL_WINDOW_MINIMIZED,
			MAXIMIZED = SDL_WINDOW_MAXIMIZED,
			DEFAULT_WFLAGS = RESIZABLE | SHOWN
		}	t_window_flag;	

		struct flags
		{
			static const std::map<std::string, t_system_flag>	System;
			static const std::map<std::string, t_window_flag>	Window;
		};
		virtual ~Types(void);
		
	private:
		Types(void);
		Types(const Types&);
		Types				&operator=(const Types&);

};

#endif
