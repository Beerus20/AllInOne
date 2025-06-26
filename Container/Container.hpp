#ifndef CONTAINER_HPP
# define CONTAINER_HPP

# include <SDL2/SDL_render.h>
#include <cstddef>
# include "../Utilities/Utilities.typedef.hpp"
# include "../Box/Box.hpp"
# include "../Draw/Draw.hpp"

# define TEXTURE_DEFAULT_WIDTH			200
# define TEXTURE_DEFAULT_HEIGHT			200
# define TEXTURE_DEFAULT_SIZE			TEXTURE_DEFAULT_WIDTH, TEXTURE_DEFAULT_HEIGHT
# define TEXTURE_DEFAULT_FORMAT			SDL_PIXELFORMAT_RGBA8888
# define TEXTURE_DEFAULT_ACCESS			SDL_TEXTUREACCESS_TARGET
# define TEXTURE_DEFAULT_FORMAT_ACCESS	TEXTURE_DEFAULT_FORMAT,TEXTURE_DEFAULT_ACCESS

class Container : public Box
{
	protected:
		Texture		*_texture;
		int			_format;
		int			_access;
		
	public:
		Container(void);
		Container(Container const &);
		Container(Texture *texture);
		Container(
			int w,
			int h,
			Uint32 = TEXTURE_DEFAULT_FORMAT,
			int = TEXTURE_DEFAULT_ACCESS);
		virtual ~Container(void);
		Container	&operator=(Container const &);

		void		destroy(void);

		void		init(
			Renderer *renderer,
			int w = TEXTURE_DEFAULT_WIDTH,
			int h = TEXTURE_DEFAULT_HEIGHT,
			Uint32 format = TEXTURE_DEFAULT_FORMAT,
			int access = TEXTURE_DEFAULT_ACCESS);
		
		Texture		*getTexture(void) const;
		void		setTexture(Texture *texture);
		bool		addAt(cRect *src = NULL, cRect *dst = NULL);
};

#endif