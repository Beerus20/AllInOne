#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>

class Engine {
	public:
		Engine(void);
		Engine(const Engine&);
		~Engine(void);
		Engine				&operator=(const Engine&);
		std::ostream&		print(std::ostream& os) const;
		bool				operator==(const Engine &other) const;
		bool				operator!=(const Engine &other) const;

	private:

};

std::ostream& operator << ( std::ostream& os, const Engine &engine);

#endif