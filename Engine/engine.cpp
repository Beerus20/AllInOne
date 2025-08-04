#include "./includes/Engine.hpp"

Engine::Engine(void)
{
}

Engine::Engine(const Engine &other)
{
	(void)other;
}

Engine::~Engine(void)
{
}

Engine &Engine::operator=(const Engine &other)
{
	(void)other;
	return (*this);
}

std::ostream& Engine::print(std::ostream& os) const
{
	os << "print Engine";
	return os;
}

bool Engine::operator==(const Engine &other) const
{
	(void)other;
	return (false);
}

bool Engine::operator!=(const Engine &other) const
{
	(void)other;
	return (false);
}

std::ostream& operator << ( std::ostream& os, const Engine &engine)
{
	return engine.print(os);
}
