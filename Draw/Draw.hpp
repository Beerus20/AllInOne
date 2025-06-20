#ifndef DRAW_HPP
# define DRAW_HPP

class Draw
{
	private:
		

	public:
		Draw(void);
		Draw(Draw const &);
		virtual ~Draw(void);

		Draw	&operator=(Draw const &);
};

#endif