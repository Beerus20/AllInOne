#include "../includes/Color.hpp"
#include <SDL2/SDL_stdinc.h>

// Setters ----------------------------------------------------------
void	Color::setR(Uint8 r)
{
	this->_r = r;
}

void	Color::setG(Uint8 g)
{
	this->_g = g;
}

void	Color::setB(Uint8 b)
{
	this->_b = b;
}

void	Color::setA(Uint8 a)
{
	this->_a = a;
}

// Getters ----------------------------------------------------------

Uint8 const	&Color::getR(void) const
{
	return (this->_r);
}

Uint8 const	&Color::getG(void) const
{
	return (this->_g);
}

Uint8 const	&Color::getB(void) const
{
	return (this->_b);
}

Uint8 const	&Color::getA(void) const
{
	return (this->_a);
}
