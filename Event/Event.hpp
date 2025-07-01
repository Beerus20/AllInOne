#ifndef EVENT_HPP
# define EVENT_HPP

# include "../Utilities/Utilities.typedef.hpp"

class IEvent
{
	private:
		IEvent(IEvent const &);

		IEvent	&operator=(IEvent const &);

	public:
		IEvent(void);
		virtual ~IEvent(void);

		virtual void	onQuit(Event) = 0;
		virtual void	onKeyUp(Event) = 0;
		virtual void	onKeyDown(Event) = 0;
		virtual void	onMouseHover(Event) = 0;
		virtual void	onMouseLeftClick(Event) = 0;
		virtual void	onMouseRightClick(Event) = 0;
		virtual void	onMouseMiddleClick(Event) = 0;
		virtual void	onMouseWheel(Event) = 0;
};

#endif
