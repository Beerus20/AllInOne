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
	cRect	rect = {10, 10, 80, 40};

	window.setBackgroundColor(WHITESMOKE);
	Draw::color(RED);
	Draw::fillRect(&rect);
	Draw::apply();
	(void)window;
	return (0);
}
