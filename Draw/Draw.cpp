#include "Draw.hpp"

Draw::Draw(void) {}
Draw::Draw(Draw const &copy) { (void)copy; }
Draw::~Draw(void) {}

Draw	&Draw::operator=(Draw const &assign)
{
	if (this != &assign)
		(void)assign;
	return (*this);
}

