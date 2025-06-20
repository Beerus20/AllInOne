#ifndef DRAW_HPP
# define DRAW_HPP

# include <SDL2/SDL_render.h>
# include <SDL2/SDL_stdinc.h>
# include "../Utilities/Utilities.typedef.hpp"

class Draw
{
	private:
		SDL_Renderer	*_renderer;

		
	public:
		Draw(void);
		Draw(Draw const &);
		Draw(SDL_Renderer *renderer);
		virtual ~Draw(void);

		Draw		&operator=(Draw const &);
		explicit	operator bool() const;

		void		test(void) const;

		void		setRenderer(SDL_Renderer *renderer);

		void		apply(void) const;
		void		clear(void) const;
		void		color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) const;

		void		point(int x, int y) const;
		void		points(cPoint *points, Uint32 nb) const;
		void		line(int x1, int y1, int x2, int y2) const;
		void		lines(cPoint *points, Uint32 nb) const;
		void		rect(cRect *r) const;
		void		rects(cRect *r, Uint32 nb) const;
		void		fillRect(cRect *r) const;
		void		fillRects(cRect *r, Uint32 nb) const;
		
		void		destroy(void) const;
	};

#endif