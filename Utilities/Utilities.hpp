#ifndef UTILITIES_HPP
# define UTILITIES_HPP

#include <SDL2/SDL_stdinc.h>
#include <sys/types.h>
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
		~Utilities(void);

		Uint32	RGBToInt(Uint8, Uint8, Uint8);
		Uint32	RGBAToInt(Uint8, Uint8, Uint8, Uint8);
		void	intToRGB(
			Uint32,
			Uint8 *__restrict__,
			Uint8 *__restrict__,
			Uint8 *__restrict__);
		void	intToRGBA(
			Uint32,
			Uint8 *__restrict__,
			Uint8 *__restrict__,
			Uint8 *__restrict__,
			Uint8 *__restrict__);

};

#endif
