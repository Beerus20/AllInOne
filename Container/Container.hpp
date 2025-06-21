#ifndef CONTAINER_HPP
# define CONTAINER_HPP

# include <SDL2/SDL_render.h>
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
	private:
		Texture		*_texture;
		Draw		*_draw;
		int			_format;
		int			_access;

		Container(Container const &);
		Container	&operator=(Container const &);

	public:
		Container(void);
		Container(
			Draw *draw,
			Uint32 = TEXTURE_DEFAULT_FORMAT,
			int = TEXTURE_DEFAULT_ACCESS,
			int = TEXTURE_DEFAULT_WIDTH,
			int = TEXTURE_DEFAULT_HEIGHT);
		virtual ~Container(void);

		void		test(void);

		void	initTexture(void);
};

#endif