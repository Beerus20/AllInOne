#include "../includes/Utils.hpp"

std::ostream& operator<<( std::ostream& os, const SDL_Rect &rect)
{
	os
		<< "["
		<< Color::Green << (rect.x) << ", " << Color::Reset
		<< Color::Green << (rect.y) << ", " << Color::Reset
		<< Color::Green << (rect.w) << ", " << Color::Reset
		<< Color::Green << (rect.h) << Color::Reset
		<< "] " << std::endl;
	return (os);
}

