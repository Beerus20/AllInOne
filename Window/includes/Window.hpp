#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <SDL2/SDL_stdinc.h>
# include "../../Box/includes/Box.hpp"
# include "../../includes/typedefs.hpp"
# include "defines.hpp"
# include "../../Error/includes/Error.hpp"
# include "typedefs.hpp"
# include "../../EventManager/includes/EventManager.hpp"

class Window : public Box
{
	private:
		string			_title;
		Uint32			_flags;
		WindowAddr		_addr;
		Renderer		_renderer;
		Containers		_content;

		void			init(cstring &, WINDOW_DEFINE_INIT_DEFAULT);

	public:
		Window(void);
		Window(Window const &);
		Window(cstring &, WINDOW_DEFINE_INIT_DEFAULT);
		virtual ~Window(void);

		Window			&operator=(Window const &);

		void			loop(void);

		void			destroy(void);
		void			maximize(void);
		void			minimize(void);
		void			restore(void);
		void			hide(void);
		void			show(void);
		void			raise(void);
		void			add(Container *);

		virtual bool	draw(void);
		// Setters ---------------------------------------------------------------------
		void			setTitle(cstring &);

		// Getters ---------------------------------------------------------------------
		cstring			&getTitle(void) const;
		Renderer		getRenderer(void) const;
};

#endif
