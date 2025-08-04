#include "../includes/Event.hpp"

Event::Event(void)
{
}

Event::Event(const Event &other)
{
	(void)other;
}

Event::~Event(void)
{
}

Event &Event::operator=(const Event &other)
{
	(void)other;
	return (*this);
}

std::ostream& Event::print(std::ostream& os) const
{
	os << "print Event";
	return os;
}

bool Event::operator==(const Event &other) const
{
	(void)other;
	return (false);
}

bool Event::operator!=(const Event &other) const
{
	(void)other;
	return (false);
}

std::ostream& operator << ( std::ostream& os, const Event &event)
{
	return event.print(os);
}
