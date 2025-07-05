#ifndef IMOUSEMOVE_HPP
# define IMOUSEMOVE_HPP

class IMouseMove
{
	private:
		IMouseMove(void) {}
		IMouseMove(IMouseMove const &) {}
		IMouseMove	&operator=(IMouseMove const &) { return (*this); }

	public:
		virtual ~IMouseMove(void) {}
		
};

#endif
