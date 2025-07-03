#include "includes/Box.hpp"

Box::Box(void) {}

Box::Box(Box const &) {}

Box::~Box() {}

Box	&Box::operator=(Box const &assign)
{
	if (this != &assign)
	{
	}
	return (*this);
}
