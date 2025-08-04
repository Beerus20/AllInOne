#include "../includes/Render.hpp"

Render::Render(void)
{
}

Render::Render(const Render &other)
{
	(void)other;
}

Render::~Render(void)
{
}

Render &Render::operator=(const Render &other)
{
	(void)other;
	return (*this);
}

std::ostream& Render::print(std::ostream& os) const
{
	os << "print Render";
	return os;
}

bool Render::operator==(const Render &other) const
{
	(void)other;
	return (false);
}

bool Render::operator!=(const Render &other) const
{
	(void)other;
	return (false);
}

std::ostream& operator << ( std::ostream& os, const Render &render)
{
	return render.print(os);
}
