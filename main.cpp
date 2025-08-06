#include <iostream>
#include "./includes/main.hpp"
#include "FileParser/includes/FileParser.hpp"
#include "Utils/includes/Utils.hpp"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	// std::cout << Utils::split(argv[1], argv[2]);
	Data::loadWindowConfig(argv[1]);
	std::cout << Data::window << std::endl;
	return (0);
}
