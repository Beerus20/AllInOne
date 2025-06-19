#ifndef BOX_HPP
# define BOX_HPP

# include "../Utilities/Utilities.hpp"

class Box
{
	private:
		t_coor		_coor;
		t_dimension	_dimension;
	
	private:
		Box(void);
		Box(Box const &);
		Box(t_coor, t_dimension);
		Box(int x, int y, int w, int h);
		virtual ~Box(void);

		Box	&operator=(Box const &);

};

#endif