#include "includes/Box.hpp"
#include "includes/defines.hpp"

Box::Box(void) : BOX_DEFAULT_INIT {}

Box::Box(Box const &) {}

Box::Box(BOX_DEFAULT_PARAM) : BOX_DEFAULT_VALUE(x, y, w, h, r, g, b, a) {}

Box::~Box() {}

Box	&Box::operator=(Box const &assign)
{
	if (this != &assign)
	{
	}
	return (*this);
}
