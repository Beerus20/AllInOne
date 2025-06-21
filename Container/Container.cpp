#include "Container.hpp"
#include <SDL2/SDL_render.h>

Container::Container(void) :
	Box(0, 0, TEXTURE_DEFAULT_SIZE),
	_texture(NULL),
	_draw(NULL),
	_format(TEXTURE_DEFAULT_FORMAT),
	_access(TEXTURE_DEFAULT_ACCESS)
{}

Container::Container(Container const &) :
	Box(0, 0, TEXTURE_DEFAULT_SIZE),
	_texture(NULL),
	_draw(NULL),
	_format(TEXTURE_DEFAULT_FORMAT),
	_access(TEXTURE_DEFAULT_ACCESS)
{}

Container::Container(Draw *draw, Uint32 format, int access, int w, int h) :
	Box(0, 0, w, h),
	_texture(NULL),
	_draw(draw),
	_format(format),
	_access(access)
{
	this->initTexture();
}

Container::~Container(void)
{
	if (this->_texture)
		SDL_DestroyTexture(this->_texture);
}

Container	&Container::operator=(Container const &)
{
	return (*this);
}

void	Container::initTexture(void)
{
	this->_texture = SDL_CreateTexture(
		this->_draw->getRenderer(),
		this->_format,
		this->_access,
		this->getW(),
		this->getH()
	);
}

void	Container::test(void)
{
	(void)_texture;
}

