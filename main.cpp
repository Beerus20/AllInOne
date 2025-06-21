#include <SDL2/SDL_rect.h>
#include <iostream>
#include <ostream>
#include "Draw/Draw.hpp"
#include "Utilities/Utilities.typedef.hpp"
#include "Window/Window.hpp"
#include "Utilities/Utilities.color.hpp"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	std::cout << "Hello world" << std::endl;
	Window		window;
	// Draw		*draw;
	// Draw		*draw2;
	// Point		point[640];
	// cRect	rect = {10, 10, 80, 40};

	// window.setColor(WHITESMOKE);
	// draw = window.getDraw();
	// draw2 = draw;
	// draw->color(255, 0, 0, 50);
	// draw->fillRect(&rect);
	// draw->apply();
	(void)window;
	return (0);
}
