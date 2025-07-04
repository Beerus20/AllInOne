#ifndef DRAW_HPP
# define DRAW_HPP

# include "../../includes/typedefs.hpp"
# include "../../Error/includes/Error.hpp"
# include "../../Color/includes/Color.hpp"
# include "../../Box/includes/Box.hpp"

class Draw
{
	private:
		static Renderer		_renderer;

		Draw(void);
		Draw(Draw const &);

		Draw				&operator=(Draw const &);
		static bool			verify(cstring & = "");

	public:
		virtual ~Draw(void);

		static void			in(Renderer);
		static void			apply(void);
		static void			clear(void);
		static void			color(COLOR_INIT_DEFAULT);
		static void			color(Color const &);

		// Form ---------------------------------------------------------
		static void			point(int, int, COLOR_DEFAULT);
		static void			rect(crRect, COLOR_DEFAULT);
		static void			fillRect(crRect, COLOR_DEFAULT);
};

#endif
