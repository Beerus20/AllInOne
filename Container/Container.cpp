#include "Container.hpp"
#include <SDL2/SDL_render.h>
#include <cstddef>
#include <iostream>

Container::Container(void) :
	Box(0, 0, TEXTURE_DEFAULT_SIZE),
	_texture(NULL),
	_format(TEXTURE_DEFAULT_FORMAT),
	_access(TEXTURE_DEFAULT_ACCESS)
{}

Container::Container(Container const &copy) :
	Box(0, 0, TEXTURE_DEFAULT_SIZE),
	_texture(NULL),
	_format(TEXTURE_DEFAULT_FORMAT),
	_access(TEXTURE_DEFAULT_ACCESS)
{
	*this = copy;
	this->init(
		Data::getRenderer(),
		_COOR(this->getCoor()),
		this->_format,
		this->_access);
}

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
	{
		SDL_DestroyTexture(this->_texture);
		this->_texture = NULL;
	}
}

Container	&Container::operator=(Container const &assign)
{
	if (this != &assign)
	{
		this->setCoor(assign.getCoor());
		this->setDimension(assign.getDimension());
		this->setTexture(assign._texture);
	}
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

bool	Container::addAt(cRect *src, cRect *dst)
{
	cTexture	*render_target(Draw::target());

	if (render_target)
		Draw::removeTarget();
	if (!Draw::texture(this->_texture, src, dst))
		return (false);
	if (render_target)
		Draw::in(const_cast<Texture *>(render_target));
	return (true);
}
