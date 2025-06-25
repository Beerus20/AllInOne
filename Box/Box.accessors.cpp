#include "Box.hpp"


void	Box::setX(int x)
{
	this->_coor.x = x;
}

void	Box::setY(int y)
{
	this->_coor.y = y;
}

void	Box::setW(int w)
{
	this->_dimension.w = w;
}

void	Box::setH(int h)
{
	this->_dimension.h = h;
}

void	Box::setCoor(int x, int y)
{
	this->_coor.x = x;
	this->_coor.y = y;
}

void	Box::setCoor(t_coor coor)
{
	this->_coor = coor;
}

void	Box::setDimension(int w, int h)
{
	this->_dimension.w = w;
	this->_dimension.h = h;
}

void	Box::setDimension(t_dimension dimension)
{
	this->_dimension = dimension;
}

int const	&Box::getX(void) const
{
	return (this->_coor.x);
}

int const	&Box::getY(void) const
{
	return (this->_coor.y);
}

int const	&Box::getW(void) const
{
	return (this->_dimension.w);
}

int const	&Box::getH(void) const
{
	return (this->_dimension.h);
}

t_coor const	&Box::getCoor(void) const
{
	return (this->_coor);
}

t_dimension const	&Box::getDimension(void) const
{
	return (this->_dimension);
}

cRect	*Box::toRect(void)
{
	this->_rect = (Rect){_COOR(this->_coor), _DIM(this->_dimension)};
	return (&this->_rect);
}
