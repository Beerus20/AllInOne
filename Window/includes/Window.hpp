#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <SDL2/SDL_stdinc.h>
# include <string>
# include "../../Box/includes/Box.hpp"
# include "typedefs.hpp"
# include "defines.hpp"
# include "../../Error/includes/Error.hpp"

class Window : public Box
{
	private:
		std::string		_title;
		Uint32			_flags;
		WindowAddr		_addr;

		void			init(cstring &, WINDOW_DEFINE_INIT_DEFAULT);
	public:
		Window(void);
		Window(Window const &);
		virtual ~Window(void);

		Window				&operator=(Window const &);

};

#endif
