#include "Container.hpp"
#include <SDL2/SDL_render.h>
#include <iostream>

Container::Container(void) :
	Box(0, 0, TEXTURE_DEFAULT_SIZE),
	_texture(NULL),
	_format(TEXTURE_DEFAULT_FORMAT),
	_access(TEXTURE_DEFAULT_ACCESS)
{}

Container::Container(Container const &) :
	Box(0, 0, TEXTURE_DEFAULT_SIZE),
	_texture(NULL),
	_format(TEXTURE_DEFAULT_FORMAT),
	_access(TEXTURE_DEFAULT_ACCESS)
{}

Container::Container(int w, int h, Uint32 format, int access) :
	Box(0, 0, w, h),
	_texture(NULL),
	_format(format),
	_access(access)
{
	this->init(
		Data::getRenderer(),
		w,
		h,
		this->_format,
		this->_access);
}

Container::~Container(void)
{
	this->destroy();
}

void	Container::destroy(void)
{
	if (this->_texture)
		SDL_DestroyTexture(this->_texture);
}

Container	&Container::operator=(Container const &)
{
	return (*this);
}

void	Container::init(Renderer *renderer, int w, int h, Uint32 format, int access)
{
	this->destroy();		
	this->_texture = SDL_CreateTexture(renderer, format, access, w, h);
	if (this->_texture == NULL)
		std::cerr << "Failed initialisation of container" << std::endl;
}

Texture	*Container::getTexture(void) const
{
	return (this->_texture);
}

bool	Container::addAt(cRect *src, cRect *dst)
{

	// if (this->_texture != Draw::target())
	// 	Draw::removeTarget();
	// if (!Draw::addTarget(this->_texture))
	// 	return (false);
	return (SDL_RenderCopy(
		Data::getRenderer(),
		this->_texture,
		src,
		dst) == 0);
}
