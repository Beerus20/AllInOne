#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <SDL2/SDL_stdinc.h>
# include <SDL2/SDL.h>
# include <cstdlib>
# include "../Utilities/Utilities.hpp"
# include "../Utilities/Utilities.typedef.hpp"
# include "../Box/Box.hpp"

# define INIT_FLAGS			SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_EVENTS
# define WINDOW_FLAGS		SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_RESIZABLE
# define WINDOW_WIDTH		800
# define WINDOW_HEIGHT		500
# define WINDOW_POS_CENTER	(SDL_WINDOWPOS_CENTERED), (SDL_WINDOWPOS_CENTERED)

class Window
{
	private:
		string	_title;
		Box		_box;
		int		_iflags;
		int		_wflags;

		void	Error(string const &, bool = true, int = EXIT_FAILURE);

	public:
		Window(void);
		Window(Window const &);
		Window(
			cstring &title,
			int x = SDL_WINDOWPOS_CENTERED,
			int y = SDL_WINDOWPOS_CENTERED,
			int w = WINDOW_WIDTH,
			int h = WINDOW_HEIGHT,
			int iflags = INIT_FLAGS,
			int wflags = WINDOW_FLAGS);
		virtual ~Window(void);

		Window	&operator=(Window const &);

		void	create(cstring &title, int x, int y, int w, int h, Uint32 wflags);
};

#endif
