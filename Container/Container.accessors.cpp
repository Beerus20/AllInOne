#include "Container.hpp"
#include <SDL2/SDL_stdinc.h>
#include <iostream>

// SETTERS ===========================================================
void	Container::setTexture(Texture *texture)
{
	Uint32		format(0);
	int			w(0);
	int			h(0);
	cTexture	*render_target;

	if (this->_texture && this->_texture == texture)
		return ;
	render_target = Draw::target();
	if (SDL_QueryTexture(texture, &format, NULL, &w, &h))
		std::cerr << "Error copy Texture" << std::endl;
	else
	{
		this->init(Data::getRenderer(), w, h, format);
		Draw::in(this);
		Draw::texture(texture, NULL, NULL);
		if (render_target)
			Draw::in(const_cast<Texture *>(render_target));
	}
}

void	Container::setAccess(int access_type)
{
	(void)access_type;
}

// GETTERS ===========================================================
Texture	*Container::getTexture(void) const
{
	return (this->_texture);
}

int	Container::getAccess(void) const
{
	return (this->_access);
}

Uint32	*Container::getPixels(void) const
{
	return (this->_pixels);
}
