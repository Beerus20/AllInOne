#ifndef BOX_HPP
# define BOX_HPP

# include "../Utilities/Utilities.hpp"
# include "../Utilities/Utilities.typedef.hpp"

class Box
{
	private:
		t_coor		_coor;
		t_dimension	_dimension;
		Rect		_rect;
	
	public:
		Box(void);
		Box(Box const &);
		Box(t_coor, t_dimension);
		Box(int x, int y, int w, int h);
		virtual ~Box(void);

		Box	&operator=(Box const &);

		void				setX(int);
		void				setY(int);
		void				setW(int);
		void				setH(int);
		void				setCoor(int x, int y);
		void				setCoor(t_coor);
		void				setDimension(int w, int h);
		void				setDimension(t_dimension);
		int const			&getX(void) const;
		int const			&getY(void) const;
		int const			&getW(void) const;
		int const			&getH(void) const;
		t_coor const		&getCoor(void) const;
		t_dimension const	&getDimension(void) const;
		cRect				*toRect(void);
};

# define _BOX(box) (box.getX()), (box.getY()), (box.getW()), (box.getH())
# define _COOR(coor) (coor.x), (coor.y)
# define _DIM(dim) (dim.w), (dim.h)

#endif