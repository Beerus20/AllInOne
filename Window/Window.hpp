#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <SDL2/SDL_render.h>
# include <SDL2/SDL_stdinc.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_video.h>
# include <cstdlib>
# include "Window.utils.hpp"
# include "../Utilities/Utilities.hpp"
# include "../Utilities/Utilities.typedef.hpp"
# include "../Box/Box.hpp"
# include "../Draw/Draw.hpp"

class Window
{
	private:
		string			_title;
		Box				_box;
		int				_iflags;
		int				_wflags;
		SDL_Window		*_addr;
		Draw			_draw;

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

		void				create(cstring &title, int x, int y, int w, int h, Uint32 wflags);

		void				delay(Uint32);
		void				destroy(void);
		void				hide(void);
		void				show(void);
		void				raise(void);
		void				setFullScreen(Uint32 mode = WINDOW_FULLSCREEN);
		void				setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		void				reload(void) const;

		void				setTitle(cstring &);
		void				setPosition(int x, int y);
		void				setPosition(t_coor const &);
		void				setSize(int x, int y);
		void				setSize(t_dimension const &);
		cstring				&getTitle(void) const;
		t_coor const		&getPosition(void) const;
		t_dimension const	&getSize(void) const;
		int const			&getWFlags(void) const;
		Draw 				*getDraw(void);
};

#endif
