#ifndef BOX_HPP
# define BOX_HPP

# include "defines.hpp"
# include "typedefs.hpp"
# include "../../Color/includes/Color.hpp"

class Box
{
	protected:
		Rect	_rect;
		Color	_color;

	public:
		Box(void);
		Box(Box const &);
		Box(cRect &, Color const &);
		Box(int x, int y, int w, int h, BOX_DEFAULT_COLOR);
		virtual ~Box(void);

		Box		&operator=(Box const &);

		// Setters	------------------------------------
		void	setX(int);
		void	setY(int);
		void	setW(int);
		void	setH(int);
		void	setPosition(int, int);
		void	setSize(int, int);
		void	setColor(COLOR_INIT_DEFAULT);
		void	setColor(Color const &);

		// Getters	------------------------------------
		int		getX(void) const;
		int		getY(void) const;
		int		getW(void) const;
		int		getH(void) const;
		cRect	*toRect(void) const;

};

#endif