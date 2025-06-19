#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <SDL2/SDL_stdinc.h>
# include <SDL2/SDL.h>
# include <cstdlib>
# include <string>
# include "../Utilities/Utilities.hpp"

typedef std::string		string;

class Window
{
	private:
		// int		_x;
		// int		_y;
		// int		_w;
		// int		_h;
		int		_flags;
		void	Error(string const &, bool = true, int = EXIT_FAILURE);

	public:
		Window(void);
		Window(Window const &);
		Window(Uint32);
		virtual ~Window(void);

		Window	&operator=(Window const &);
};

#endif
