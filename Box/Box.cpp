#include "includes/Box.hpp"
#include "includes/defines.hpp"
#include "includes/typedefs.hpp"

Box::Box(void) :
	_color(RGBA_WHITESMOKE)
{
	this->_rect = (Rect){0, 0, 0, 0};
}

Box::Box(Box const &) {}

Box::Box(cRect &rect, Color const &color)
{
	this->_rect = rect;
	this->_color = color;
}

Box::Box(BOX_DEFAULT_PARAM) :
	_color(r, g, b, a)
{
	this->_rect = (Rect){x, y, w, h};
}

Box::~Box() {}

Box	&Box::operator=(Box const &assign)
{
	if (this != &assign)
	{
	}
	return (*this);
}


