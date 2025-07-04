#ifndef COLOR_HPP
# define COLOR_HPP

# include "defines.hpp"
#include <SDL2/SDL_stdinc.h>

class Color
{
	private:
		Uint8		_r;
		Uint8		_g;
		Uint8		_b;
		Uint8		_a;

	public:
		Color(void);
		Color(Color const &);
		Color(COLOR_INIT_DEFAULT);
		virtual ~Color(void);

		Color		&operator=(Color const &);

		// Setters ----------------------------------------------------------
		void		setR(Uint8);
		void		setG(Uint8);
		void		setB(Uint8);
		void		setA(Uint8);

		// Getters ----------------------------------------------------------
		Uint8 const	&getR(void) const;
		Uint8 const	&getG(void) const;
		Uint8 const	&getB(void) const;
		Uint8 const	&getA(void) const;
};

#endif
