#include "Color.hpp"

// SETTERS ==================================================
void	Color::setR(Uint8 r)
{
	this->_r = r;
	this->_value = Utilities::RGBAToInt(this->_r, this->_g, this->_b, this->_a);
}

void	Color::setG(Uint8 g)
{
	this->_g = g;
	this->_value = Utilities::RGBAToInt(this->_r, this->_g, this->_b, this->_a);
}

void	Color::setB(Uint8 b)
{
	this->_b = b;
	this->_value = Utilities::RGBAToInt(this->_r, this->_g, this->_b, this->_a);
}

void	Color::setA(Uint8 a)
{
	this->_a = a;
	this->_value = Utilities::RGBAToInt(this->_r, this->_g, this->_b, this->_a);
}

void	Color::setValue(Uint32 value)
{
	this->_value = value;
	Utilities::intToRGBA(
		this->_value,
		&this->_r,
		&this->_g,
		&this->_b,
		&this->_a);
}

void	Color::set(int r, int g, int b, int a)
{
	this->_r = r;
	this->_g = g;
	this->_b = b;
	this->_a = a;
	this->_value = Utilities::RGBAToInt(this->_r, this->_g, this->_b, this->_a);
}

// GETTERS ==================================================
Uint8	Color::getR(void) const
{
	return (this->_r);
}

Uint8	Color::getG(void) const
{
	return (this->_g);
}

Uint8	Color::getB(void) const
{
	return (this->_b);
}

Uint8	Color::getA(void) const
{
	return (this->_a);
}

Uint32	Color::getValue(void) const
{
	return (this->_value);
}
