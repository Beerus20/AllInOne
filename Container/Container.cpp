#include "includes/Container.hpp"
#include "includes/defines.hpp"

Container::Container(void) :
	Box(CONTAINER_DEFAULT_VALUE)
{}

Container::Container(Container const &) :
	Box()
{}

Container::~Container(void) {}

Container	&Container::operator=(Container const &)
{
	return (*this);
}

bool	Container::draw(rRect rect)
{
	
	return (true);
}