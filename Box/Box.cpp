#include "Box.hpp"

Box::Box(void) :
	_coor(0,0),
	_dimension(0, 0)
{}

Box::Box(Box const &copy) :
	_coor(copy._coor),
	_dimension(copy._dimension)
{}

Box::Box(t_coor coor, t_dimension dimension) :
	_coor(coor),
	_dimension(dimension)
{}

Box::Box(int x, int y, int w, int h) :
	_coor(x, y),
	_dimension(w, h)
{}

Box::~Box() {}

Box	&Box::operator=(Box const &assign)
{
	if (this != &assign)
	{
		this->_coor = assign._coor;
		this->_dimension = assign._dimension;
	}
	return (*this);
}
