#ifndef ENGINE_HPP
# define ENGINE_HPP

# include <SDL2/SDL.h>
# include <SDL2/SDL_stdinc.h>
# include <iostream>
# include "Data.hpp"

class Engine {
	public:		
		~Engine();
		std::ostream&		print(std::ostream& os) const;

		static SDL_bool			init(t_system_flag = EVERYTHING, t_window_flag = DEFAULT_WFLAGS);
	private:
		Engine(void);
		Engine(const Engine&);
		Engine				&operator=(const Engine&);

};

std::ostream& operator << ( std::ostream& os, const Engine &engine);

#endif