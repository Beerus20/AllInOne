#ifndef ENGINE_HPP
# define ENGINE_HPP

# include <SDL2/SDL.h>
# include <SDL2/SDL_stdinc.h>
# include <iostream>
# include "../../Data/includes/Data.hpp"
# include "../../Utils/includes/Utils.hpp"

class Engine {
	public:		
		~Engine();
		std::ostream&		print(std::ostream& os) const;

		static SDL_bool			init(Types::t_system_flag = Types::EVERYTHING);
	private:
		Engine(void);
		Engine(const Engine&);
		Engine				&operator=(const Engine&);

};

std::ostream& operator << ( std::ostream& os, const Engine &engine);

#endif