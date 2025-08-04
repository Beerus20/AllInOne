#ifndef RENDER_HPP
#define RENDER_HPP

#include <iostream>

class Render {
	public:
		Render(void);
		Render(const Render&);
		~Render(void);
		Render				&operator=(const Render&);
		std::ostream&		print(std::ostream& os) const;
		bool				operator==(const Render &other) const;
		bool				operator!=(const Render &other) const;

	private:

};

std::ostream& operator << ( std::ostream& os, const Render &render);

#endif