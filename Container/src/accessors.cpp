#include "../includes/Container.hpp"

// Getters --------------------------------------------------------
Texture	Container::getTexture(void) const
{
	return (this->_texture);
}

cRect	*Container::getSrc(void) const
{
	return (&this->_src);
}
