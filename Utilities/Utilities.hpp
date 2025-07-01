#ifndef UTILITIES_HPP
# define UTILITIES_HPP

# include <SDL2/SDL_stdinc.h>
# include <sys/types.h>
# include <SDL2/SDL_error.h>
# include <SDL2/SDL_pixels.h>
# include <SDL2/SDL_render.h>
# include <SDL2/SDL_stdinc.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_video.h>
# include <SDL2/SDL.h>
# include "Utilities.typedef.hpp"
# include "Utilities.defines.hpp"


# define CREATE_STRUCT_2D(name, a, b) \
	typedef struct s_##name { \
		int	a, b; \
		s_##name(int a, int b) : a(a), b(b) {} \
		s_##name(const s_##name &copy) : a(copy.a), b(copy.b) {} \
		s_##name	&operator=(const s_##name &assign) \
		{ \
			if (this != &assign) \
			{ \
				this->a = assign.a; \
				this->b = assign.b; \
			} \
			return (*this); \
		} \
	} t_##name

CREATE_STRUCT_2D(coor, x, y);
CREATE_STRUCT_2D(dimension, w, h);

class Utilities
{
	private:
		Utilities(void);
		Utilities(Utilities const &);

		Utilities	&operator=(Utilities const &);

	public:
		virtual ~Utilities(void);

		static Uint32	RGBToInt(Uint8, Uint8, Uint8);
		static Uint32	RGBAToInt(Uint8, Uint8, Uint8, Uint8);
		static void	intToRGB(
			Uint32,
			Uint8 *__restrict__,
			Uint8 *__restrict__,
			Uint8 *__restrict__);
		static void	intToRGBA(
			Uint32,
			Uint8 *__restrict__,
			Uint8 *__restrict__,
			Uint8 *__restrict__,
			Uint8 *__restrict__);

};

#endif
