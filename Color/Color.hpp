#ifndef COLOR_HPP
# define COLOR_HPP

# include "../Utilities/Utilities.hpp"
# include <ostream>

# define _GET_COLOR_(color) color.getR(), color.getG(), color.getB(), color.getA()

class Color
{
	private:
		Uint8	_r;
		Uint8	_g;
		Uint8	_b;
		Uint8	_a;
		Uint32	_value;

	public:
		Color(void);
		Color(Color const &);
		Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
		virtual ~Color(void);

		Color	&operator=(Color const &);

		void	setR(Uint8);
		void	setG(Uint8);
		void	setB(Uint8);
		void	setA(Uint8);
		void	setValue(Uint32);
		void	set(int, int, int, int = 255);

		Uint8	getR(void) const;
		Uint8	getG(void) const;
		Uint8	getB(void) const;
		Uint8	getA(void) const;
		Uint32	getValue(void) const;
};

std::ostream	&operator<<(std::ostream &o, Color const &color);

#endif
