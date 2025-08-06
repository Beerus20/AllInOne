#ifndef BOX_HPP
#define BOX_HPP

#include <SDL2/SDL_rect.h>
#include <iostream>

class Box : public SDL_Rect
{
	public:
		Box();
		Box(const Box&);
		~Box(void);
		Box				&operator=(const Box&);
		std::ostream&	print(std::ostream& os) const;
		bool			operator==(const Box &other) const;
		bool			operator!=(const Box &other) const;

	private:

};

std::ostream& operator << ( std::ostream& os, const Box &box);

#endif