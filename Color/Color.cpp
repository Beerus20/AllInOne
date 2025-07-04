#include "includes/Color.hpp"

Color::Color(void) {}
Color::Color(Color const &) {}
Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) :
	_r(r), _g(g), _b(b), _a(a)
{}


Color::~Color(void) {}

Color	&Color::operator=(Color const &assign)
{
	if (this != &assign)
	{
		this->_r = assign._r;
		this->_g = assign._g;
		this->_b = assign._b;
		this->_a = assign._a;
	}
	return (*this);
}
