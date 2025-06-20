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
	Draw		draw;
	// Point		point[640];

	window.setColor(WHITESMOKE);
	draw = window.getDraw();
	draw.test();
	// size_t i = 0;
	// for(i = 0; i < 640; i++)
	// {
	// 	point[i].x = i;
	// 	point[i].y = 200;
	// }
	// draw.color(RED);
	// draw.points(point, 640);
	// draw.color(BLUE);
	// draw.line(0, 0, 800, 500);
	draw.apply();
	(void)window;
	return (0);
}
