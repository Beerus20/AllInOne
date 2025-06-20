#include "Window.hpp"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>
#include <cstdlib>
#include <iostream>
#include "../Utilities/Utilities.color.hpp"

Window::Window(void) :
	_title("Window"),
	_box(WINDOW_POS_CENTER, WINDOW_WIDTH, WINDOW_HEIGHT),
	_iflags(INIT_FLAGS),
	_wflags(WINDOW_FLAGS),
	_addr(NULL),
	_renderer(NULL)
{
	std::cout << "Creation of window" << std::endl;
	this->create("Window", _BOX(this->_box), this->_wflags);
}

Window::Window(cstring &title, int x, int y, int w, int h, int iflags, int wflags) :
	_title(title),
	_box(x, y, w, h),
	_iflags(iflags),
	_wflags(wflags),
	_addr(NULL),
	_renderer(NULL)
{
	this->create(title, x, y, w, h, this->_wflags);
}

Window::Window(Window const &to_copy)
{
	*this = to_copy;
}

Window::~Window(void)
{
	this->delay(DELAY);
	std::cout << "Window destroyed" << std::endl;
	this->destroy();
}


Window	&Window::operator=(Window const &to_assign)
{
	(void)to_assign;
	return (*this);
}

inline void	Window::Error(string const &message, bool quit, int exit_status)
{
	std::cout << message << " : " << SDL_GetError() << std::endl;
	if (quit)
	{
		this->destroy();
		exit(exit_status);
	}
}

void	Window::create(cstring &title, int x, int y, int w, int h, Uint32 wflags)
{
	if (SDL_Init(this->_iflags) != 0)
		this->Error("Initialisation Error");
	this->_addr = SDL_CreateWindow(title.c_str(), x, y, w, h, wflags);
	if (this->_addr == NULL)
		this->Error("Window initialisation error");
	this->_renderer = SDL_CreateRenderer(this->_addr, -1, SDL_RENDERER_ACCELERATED);
	if (this->_renderer == NULL)
		this->Error("Renderer initialisation error");

	if (SDL_SetRenderDrawColor(this->_renderer, DARKVIOLET) != 0)
		this->Error("Draw color error", false);
	if (SDL_RenderClear(this->_renderer))
		this->Error("Clear renderer error", false);

	this->delay(500);
	SDL_RenderPresent(this->_renderer);
}

void	Window::delay(Uint32 ms)
{
	SDL_Delay(ms);
}

void	Window::destroy(void)
{
	if (this->_renderer)
		SDL_DestroyRenderer(this->_renderer);
	if (this->_addr)
		SDL_DestroyWindow(this->_addr);
	SDL_Quit();
}

void	Window::hide(void)
{
	SDL_HideWindow(this->_addr);
}

void	Window::show(void)
{
	SDL_ShowWindow(this->_addr);
}

void	Window::raise(void)
{
	SDL_RaiseWindow(this->_addr);
}

void	Window::setFullScreen(Uint32 mode)
{
	if (SDL_SetWindowFullscreen(this->_addr, mode) != 0)
		this->Error("FullScreen mode error", false);
}
