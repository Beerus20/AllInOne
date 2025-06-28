#include <SDL2/SDL_rect.h>
#include <iostream>
#include <ostream>
#include "Draw/Draw.hpp"
#include "Utilities/Utilities.typedef.hpp"
#include "Window/Window.hpp"
#include "Utilities/Utilities.color.hpp"
#include "Container/Container.hpp"
#include "Model/Image/Image.hpp"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	std::cout << "Hello world" << std::endl;
	Window		window;
	Container	nav;
	Rect		rect = {10, 10, 400, 100};
	Rect		test = {10, 10, 20, 10};

	window.setBackgroundColor(WHITESMOKE);
	nav.init(Data::getRenderer());
	Draw::in(&nav);
	Draw::color(BURLYWOOD);
	Draw::clear();
	Draw::fillRect(&test, VIOLET);
	if (!nav.addAt(NULL, &rect))
		std::cout << "Error adding container" << std::endl;
	Draw::apply();
	return (0);
}
