#ifndef DATA_HPP
# define DATA_HPP

# include <SDL2/SDL.h>
# include <SDL2/SDL_rect.h>
# include <iostream>
# include <iomanip>
# include "../../FileParser/includes/FileParser.hpp"
# include "../../Utils/includes/Utils.hpp"
# include "../../Window/includes/Window.hpp"
# include "../../Config/includes/Config.hpp"


class Data
{
	public:
		virtual ~Data(void);
		static Window		window;
		
		static void			init(void);
		static void			init(std::string const &window_config_path);

	private:
		Data(void);
		Data(const Data&);
		Data				&operator=(const Data&);

};

#endif