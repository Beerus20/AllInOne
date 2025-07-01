#include "Color.hpp"

Color::Color(void) :
	_r(245),
	_g(245),
	_b(245),
	_a(255)
{
	this->_value = Utilities::RGBAToInt(this->_r, this->_g, this->_b, this->_a);
}

Color::Color(Color const &copy)
{
	*this = copy;
}

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) :
	_r(r),
	_g(g),
	_b(b),
	_a(a)
{
	this->_value = Utilities::RGBAToInt(this->_r, this->_g, this->_b, this->_a);
}

Color::~Color(void) {}

Color	&Color::operator=(Color const &assign)
{
	if (this != &assign)
	{
		this->_r = assign._r;
		this->_g = assign._g;
		this->_b = assign._b;
		this->_a = assign._a;
		this->_value = assign._value;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Color const &color)
{
	o << "Color : " << std::endl
		<< "r : " << color.getR() << std::endl
		<< "g : " << color.getG() << std::endl
		<< "b : " << color.getB() << std::endl
		<< "a : " << color.getA() << std::endl;
	return (o);
}

