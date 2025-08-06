#ifndef DATA_HPP
# define DATA_HPP

# include <SDL2/SDL.h>
# include <SDL2/SDL_rect.h>
# include <iostream>
# include <iomanip>
# include "../../FileParser/includes/FileParser.hpp"
# include "../../Utils/includes/Utils.hpp"

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

class Data
{
	public:
		struct Window
		{
			Window(std::string const &title, SDL_Rect const &rect, t_window_flag flag) : title(title), rect(rect), flag(flag) {}
			Window(std::string const &title, int x, int y, int w, int h, t_window_flag flag) : title(title), rect((SDL_Rect){x, y, w, h}), flag(flag) {}
			std::string		title;
			SDL_Rect		rect;
			t_window_flag	flag;
		};
		static Window		window;

		virtual ~Data(void);
		static void			loadWindowConfig(std::string const &path);

	private:
		Data(void);
		Data(const Data&);
		Data				&operator=(const Data&);

};
std::ostream& operator<<(std::ostream& os, const Data::Window &window);

#endif