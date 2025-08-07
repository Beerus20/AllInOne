#ifndef DATA_HPP
# define DATA_HPP

# include <SDL2/SDL.h>
# include <SDL2/SDL_rect.h>
# include <iostream>
# include <iomanip>
# include "../../FileParser/includes/FileParser.hpp"
# include "../../Utils/includes/Utils.hpp"
# include "Window.hpp"

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

class Data
{
	public:
		virtual ~Data(void);

		static Window		window;
		
		static void			loadWindowConfig(std::string const &path);

	private:
		Data(void);
		Data(const Data&);
		Data				&operator=(const Data&);

};

#endif