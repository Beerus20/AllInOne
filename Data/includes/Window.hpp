#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <SDL2/SDL_rect.h>
# include <SDL2/SDL_video.h>
# include <iostream>
# include "../../Utils/includes/Utils.hpp"
# include "../../Error/includes/Error.hpp"

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

class Window
{
	public:
		Window(void);
		Window(const Window&);
		virtual ~Window(void);

		Window				&operator=(const Window&);
		std::ostream&		print(std::ostream& os) const;
		bool				operator==(const Window &) const;
		bool				operator!=(const Window &) const;

		void				init(Map<std::string>::string config);
		void				init(std::string const &title, SDL_Rect const &rect, t_window_flag flag);
		void				init(std::string const &title, int x, int y, int w, int h, t_window_flag flag);
		void				initFlag(std::string const &str_flag);

		std::string const	&getTitle(void) const;
		SDL_Rect const		&getRect(void) const;
		t_window_flag const	&getFlags(void) const;
		void				setTitle(std::string const &title);
		void				setRect(SDL_Rect rect);
		void				setFlags(t_window_flag flag);

	private:
		std::string			_title;
		SDL_Rect			_rect;
		t_window_flag		_flag;

};

std::ostream& operator<<( std::ostream& os, const Window &window);

#endif