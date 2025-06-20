#include <iostream>
#include <ostream>
#include "Window/Window.hpp"

void	test(int x, int y, int w, int h, string mess)
{
	std::cout
		<< mess << " : "
		<< x << " " 
		<< y << " " 
		<< w << " " 
		<< h << " "
		<< std::endl; 
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	std::cout << "Hello world" << std::endl;
	Window		window;
	
	(void)window;
	return (0);
}