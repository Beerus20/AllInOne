#include "../includes/Box.hpp"

// Setters	------------------------------------
void	Box::setX(int x)
{
	this->_x = x;
}

void	Box::setY(int y)
{
	this->_y = y;
}

void	Box::setW(int w)
{
	this->_w = w;
}

void	Box::setH(int h)
{
	this->_h = h;
}

// Getters	------------------------------------

int		Box::getX(void) const
{
	return (this->_x);
}

int		Box::getY(void) const
{
	return (this->_y);
}

int		Box::getW(void) const
{
	return (this->_w);
}

int		Box::getH(void) const
{
	return (this->_h);
}
