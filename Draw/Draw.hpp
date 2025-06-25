#ifndef DRAW_HPP
# define DRAW_HPP

# include <SDL2/SDL_render.h>
# include <SDL2/SDL_stdinc.h>
# include "../Utilities/Utilities.typedef.hpp"
# include "../Data/Data.hpp"

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

		static void			point(int x, int y);
		static void			points(cPoint *points, Uint32 nb);
		static void			line(int x1, int y1, int x2, int y2);
		static void			lines(cPoint *points, Uint32 nb);
		static void			rect(cRect *r);
		static void			rects(cRect *r, Uint32 nb);
		static void			fillRect(cRect *r);
		static void			fillRects(cRect *r, Uint32 nb);
		
	};

#endif