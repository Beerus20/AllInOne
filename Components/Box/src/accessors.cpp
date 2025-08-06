#include "../includes/Box.hpp"

// Setters	------------------------------------
void	Box::setX(int x)
{
	this->_rect.x = x;
}

void	Box::setY(int y)
{
	this->_rect.y = y;
}

void	Box::setW(int w)
{
	this->_rect.w = w;
}

void	Box::setH(int h)
{
	this->_rect.h = h;
}

void	Box::setPosition(int x, int y)
{
	this->_rect.x = x;
	this->_rect.y = y;
}

void	Box::setSize(int w, int h)
{
	this->_rect.w = w;
	this->_rect.h = h;
}

void	Box::setColor(COLOR_DEFAULT_PARAMS)
{
	this->_color.setR(r);
	this->_color.setG(g);
	this->_color.setB(b);
	this->_color.setA(a);
}

void	Box::setColor(Color const &color)
{
	this->_color = color;
}

// Getters	------------------------------------

int		Box::getX(void) const
{
	return (this->_rect.x);
}

int		Box::getY(void) const
{
	return (this->_rect.y);
}

int		Box::getW(void) const
{
	return (this->_rect.w);
}

int		Box::getH(void) const
{
	return (this->_rect.h);
}

cRect	*Box::toRect(void) const
{
	return (&this->_rect);
}
