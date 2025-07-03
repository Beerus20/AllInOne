#ifndef BOX_HPP
# define BOX_HPP

class Box
{
	protected:
		int		_x;
		int		_y;
		int		_w;
		int		_h;
		int		_r;
		int		_g;
		int		_b;
		int		_a;

	public:
		Box(void);
		Box(Box const &);
		Box(
			int x,
			int y,
			int w,
			int h,
			int r,
			int g,
			int b,
			int a);
		virtual ~Box(void);

		Box		&operator=(Box const &);

		// Setters	------------------------------------
		void	setX(int);
		void	setY(int);
		void	setW(int);
		void	setH(int);

		// Getters	------------------------------------
		int		getX(void) const;
		int		getY(void) const;
		int		getW(void) const;
		int		getH(void) const;

};

#endif