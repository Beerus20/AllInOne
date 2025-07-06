#include <SDL2/SDL_rect.h>
#include <iostream>
#include <ostream>
#include "main.hpp"
#include "Container/includes/Container.hpp"
#include "includes/typedefs.hpp"

int	clg(rEvent e)
{
	std::cout
		<< "Coor : (x : "
		<< e->motion.x
		<< ", y : "
		<< e->motion.y
		<< ")"
		<< std::endl;
	return (0);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	std::cout << "Hello world" << std::endl;
	Window		window;
	Container	test;

	window.add(&test);
	window.EventManager::add(MOUSE_MOTION, clg);
	window.loop();
	(void)window;
	return (0);
}
