#include "Box.hpp"
#include <thread>

Box::Box(void) :
	_coor(0,0),
	_dimension(0, 0)
{}

Box::Box(Box const &copy) :
	IEvent(),
	_coor(copy._coor),
	_dimension(copy._dimension)
{}

Box::Box(t_coor coor, t_dimension dimension, _COLOR_) :
	_coor(coor),
	_dimension(dimension),
	_color(r, g, b, a)
{}

Box::Box(t_coor coor, t_dimension dimension, Color const &color) :
	_coor(coor),
	_dimension(dimension),
	_color(color)
{}

Box::Box(int x, int y, int w, int h, _COLOR_) :
	_coor(x, y),
	_dimension(w, h),
	_color(r, g, b, a)
{}

Box::Box(int x, int y, int w, int h, Color const &color) :
	_coor(x, y),
	_dimension(w, h),
	_color(color)
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


