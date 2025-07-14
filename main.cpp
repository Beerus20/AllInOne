#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <iostream>
#include <ostream>
#include "main.hpp"
#include "Color/includes/defines.hpp"
#include "Container/includes/Container.hpp"
#include "Draw/includes/Draw.hpp"
#include "includes/typedefs.hpp"
#include "Data/includes/Data.hpp"
#include "Box/includes/Box.hpp"

int	clg(SDL_Event *, Box *box)
{
	(void)box;
	// if (Data::map[e->motion.y][e->motion.x])
	// {
	// 	std::cout << Data::map[e->motion.y][e->motion.x] << std::endl;
	// }
	// std::cout
	// 	<< "Coor : (x : "
	// 	<< e->motion.x
	// 	<< ", y : "
	// 	<< e->motion.y
	// 	<< ")"
	// 	<< std::endl;

	return (0);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	std::cout << "Hello world" << std::endl;
	Window		window;
	Container	test[10];

	for (int i(0); i < 10; i++)
	{
		test[i].setX(i + 200);
		test[i].setY(i + 200);
		window.add(&test[i]);
	}
	// test.listen(MOUSE_MOTION, clg);
	window.loop();
	(void)window;
	return (0);
}
