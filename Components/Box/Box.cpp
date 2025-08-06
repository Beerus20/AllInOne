#include "./includes/Box.hpp"

Box::Box(void) {}

Box::Box(const Box &other)
{
	(void)other;
}

Box::~Box(void)
{
}

Box &Box::operator=(const Box &other)
{
	(void)other;
	return (*this);
}

std::ostream& Box::print(std::ostream& os) const
{
	os << "print Box";
	return os;
}

bool Box::operator==(const Box &other) const
{
	(void)other;
	return (false);
}

bool Box::operator!=(const Box &other) const
{
	(void)other;
	return (false);
}

std::ostream& operator << ( std::ostream& os, const Box &box)
{
	return box.print(os);
}
