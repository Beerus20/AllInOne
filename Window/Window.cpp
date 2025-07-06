#include "includes/Window.hpp"
#include "includes/defines.hpp"
#include "includes/typedefs.hpp"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <cstddef>
#include <iostream>

Window::Window(void) :
	Box(WINDOW_DEFAULT_PARAMS),
	EventManager(&_event),
	_title("window"),
	_flags(WINDOW_DEFAULT_FLAGS),
	_addr(NULL),
	_renderer(NULL)
{
	this->init(this->_title, _WRECT(this));
}

Window::Window(Window const &to_copy) :
	Box(),
	EventManager(&_event)
{
	*this = to_copy;
}

Window::Window(cstring &title, WINDOW_INIT_DEFAULT) :
	Box(x, y, w, h),
	_title(title),
	_flags(flags),
	_addr(NULL),
	_renderer(NULL)
{
	this->init(this->_title, _WRECT(this), this->_flags);
}

Window::~Window(void)
{
	this->destroy();
	std::cout << "Window destroyed" << std::endl;
}

Window	&Window::operator=(Window const &) { return (*this); }

void	Window::init(cstring &title, WINDOW_INIT_DEFAULT)
{
	this->_addr = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
	if (this->_addr == NULL)
		Error::add(ERROR, SDL_GetError());
	this->_renderer = SDL_CreateRenderer(this->_addr, -1, WINDOW_RENDERER_TYPE);
	if (this->_renderer == NULL)
		Error::add(ERROR, SDL_GetError());
}

bool	Window::draw(void)
{
	Draw::in(this);
	for (Containers::iterator it(this->_content.begin()); it != this->_content.end(); it++)
	{
		Draw::in(*it);
		(*it)->draw();
		Draw::out();
		SDL_RenderCopy(
			this->_renderer,
			(*it)->getTexture(),
			(*it)->getSrc(),
			(*it)->toRect()
		);
	}
	Draw::apply();
	return (true);
}

void	Window::loop(void)
{
	while (this->wait())
		this->draw();
}
