#include <SDL2/SDL_rect.h>
#include <iostream>
#include <ostream>
#include "main.hpp"
#include "Container/includes/Container.hpp"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	std::cout << "Hello world" << std::endl;
	Window		window;
	Container	test;
	Rect		rect = {10, 10, 200, 100};

	window.add(&test, rect, rect);
	window.loop();
	(void)window;
	return (0);
}
