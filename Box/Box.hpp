#ifndef BOX_HPP
# define BOX_HPP

# include "../Utilities/Utilities.hpp"
# include "../Utilities/Utilities.typedef.hpp"
# include "../Color/Color.hpp"
# include "../Event/Event.hpp"

class Box : public IEvent
{
	private:
		t_coor				_coor;
		t_dimension			_dimension;
		Rect				_rect;
		Color				_color;

	public:
		Box(void);
		Box(Box const &);
		Box(t_coor, t_dimension, _DEFAULT_COLOR_);
		Box(t_coor, t_dimension, Color const &color);
		Box(int x, int y, int w, int h, _DEFAULT_COLOR_);
		Box(int x, int y, int w, int h, Color const &color);
		virtual ~Box(void);

		Box					&operator=(Box const &);

		virtual void		draw(void);
		virtual void		reload(void);

		// Setters ----------------------------------------------------------
		void				setX(int);
		void				setY(int);
		void				setW(int);
		void				setH(int);
		void				setCoor(int x, int y);
		void				setCoor(t_coor);
		void				setDimension(int w, int h);
		void				setDimension(t_dimension);
		void				setColor(int, int, int, int = 255);
		void				setColor(Color &);

		// Getters ----------------------------------------------------------
		int const			&getX(void) const;
		int const			&getY(void) const;
		int const			&getW(void) const;
		int const			&getH(void) const;
		t_coor const		&getCoor(void) const;
		t_dimension const	&getDimension(void) const;
		cRect				*toRect(void);
		Color const			&getColor(void) const;

		// Event ----------------------------------------------------------
		virtual void		onQuit(Event) = 0;
		virtual void		onKeyUp(Event) = 0;
		virtual void		onKeyDown(Event) = 0;
		virtual void		onMouseHover(Event) = 0;
		virtual void		onMouseLeftClick(Event) = 0;
		virtual void		onMouseRightClick(Event) = 0;
		virtual void		onMouseMiddleClick(Event) = 0;
		virtual void		onMouseWheel(Event) = 0;
};

#endif