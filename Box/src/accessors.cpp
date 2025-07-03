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

void	Box::setPosition(int x, int y)
{
	this->_x = x;
	this->_y = y;
}

void	Box::setSize(int w, int h)
{
	this->_w = w;
	this->_h = h;
}

void	Box::setColor(int r, int g, int b, int a)
{
	this->_r = r;
	this->_g = g;
	this->_b = b;
	this->_a = a;
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
