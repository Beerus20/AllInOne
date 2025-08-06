#include "./includes/Engine.hpp"
#include <SDL2/SDL.h>

Engine::Engine(void) {}
Engine::Engine(const Engine &) {}
Engine::~Engine(void)
{
	SDL_Quit();
}
Engine &Engine::operator=(const Engine &) { return (*this); }

std::ostream& Engine::print(std::ostream& os) const
{
	os << "print Engine";
	return os;
}

std::ostream& operator << ( std::ostream& os, const Engine &engine)
{
	return engine.print(os);
}


