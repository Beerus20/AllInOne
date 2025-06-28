#ifndef DRAW_HPP
# define DRAW_HPP

# include <SDL2/SDL_render.h>
# include <SDL2/SDL_stdinc.h>
#include <cstddef>
# include "../Utilities/Utilities.typedef.hpp"
# include "../Data/Data.hpp"

# define _DEFAULT_COLOR_	int r = 245, int g = 245, int b = 245, int a =255 //<== __WHITESMOKE__
# define _COLOR_			int r, int g, int b, int a

class Container;

class Draw
{
	private:
		Draw(void);
		Draw(Draw const &);

		Draw			&operator=(Draw const &);

	public:
		virtual ~Draw(void);

		static bool			in(Texture *texture);
		static bool			in(Container *container);
		static cTexture		*target(void);
		static bool			addTarget(Texture *texture);
		static bool			removeTarget(void);
		static void			apply(void);
		static void			clear(void);
		static void			color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

		static void			point(int x, int y, _DEFAULT_COLOR_);
		static void			points(cPoint *points, Uint32 nb);
		static void			line(int x1, int y1, int x2, int y2, _DEFAULT_COLOR_);
		static void			lines(cPoint *points, Uint32 nb);
		static void			rect(cRect *rect, _DEFAULT_COLOR_);
		static void			rects(cRect *rect, Uint32 nb);
		static void			fillRect(cRect *rect, _DEFAULT_COLOR_);
		static void			fillRects(cRect *rect, Uint32 nb);
		static void			pixels(Uint32 (*func)(int w, int h), cRect * = NULL);

		static bool			texture(
			Texture *__restrict__ texture,
			cRect *__restrict__ src = NULL,
			cRect *__restrict__ dst = NULL);
};

#endif