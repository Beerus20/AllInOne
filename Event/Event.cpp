#include "Event.hpp"

IEvent::IEvent(void) {}
IEvent::IEvent(IEvent const &) {}
IEvent::~IEvent(void) {}

IEvent	&IEvent::operator=(IEvent const &)
{
	return (*this);
}
