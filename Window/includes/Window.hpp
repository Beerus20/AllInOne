#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <SDL2/SDL_stdinc.h>
# include "../../Box/includes/Box.hpp"
# include "../../includes/typedefs.hpp"
# include "defines.hpp"
# include "../../Error/includes/Error.hpp"
#include "typedefs.hpp"

class Window : public Box
{
	private:
		string			_title;
		Uint32			_flags;
		WindowAddr		_addr;
		Renderer		_renderer;
		Textures		_textures;
		Containers		_containers;
		Event			_event;

		void			init(cstring &, WINDOW_DEFINE_INIT_DEFAULT);

	public:
		Window(void);
		Window(Window const &);
		Window(cstring &, WINDOW_DEFINE_INIT_DEFAULT);
		virtual ~Window(void);

		Window			&operator=(Window const &);

		void			loop(void);

		void			createTexture(
							int w,
							int h,
							Uint32 format = PIXEL_FORMAT,
							int access = TEXTURE_TYPE);
		void			destroy(void);
		void			destroyTextures(void);
		void			maximize(void);
		void			minimize(void);
		void			restore(void);
		void			hide(void);
		void			show(void);
		void			raise(void);
		void			add(Container *);

		// Setters ---------------------------------------------------------------------
		void			setTitle(cstring &);

		// Getters ---------------------------------------------------------------------
		cstring			&getTitle(void) const;
};

#endif
