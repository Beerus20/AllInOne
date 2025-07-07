#include "../includes/Container.hpp"

// Getters --------------------------------------------------------
Texture	Container::getTexture(void) const
{
	return (this->_texture);
}

cRect	*Container::getSrc(void) const
{
	return (this->_src.w == 0 || this->_src.h == 0 ? NULL : &this->_src);
}
