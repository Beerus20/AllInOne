#include "includes/Container.hpp"

Container::Container(void) :
	Box()
{}

Container::Container(Container const &) :
	Box()
{}

Container::~Container(void) {}

Container	&Container::operator=(Container const &)
{
	return (*this);
}

