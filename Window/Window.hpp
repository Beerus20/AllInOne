#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <cstdlib>
# include "../Utilities/Utilities.hpp"
# include "../Box/Box.hpp"
# include "../Draw/Draw.hpp"

class Window : private Box
{
	private:
		string				_title;
		int					_iflags;
		int					_wflags;
		SDL_Window			*_addr;
		Event				_event;

		void				Error(string const &, bool = true, int = EXIT_FAILURE);

	public:
		Window(void);
		Window(Window const &);
		Window(cstring &title, WINDOW_DEFAULT_CONFIG);
		virtual ~Window(void);

		Window				&operator=(Window const &);

		void				create(cstring &title, int x, int y, int w, int h, Uint32 wflags);
		void				loop(void);

		// Utils -------------------------------------------------------------------------------------
		void				delay(Uint32);
		void				destroy(void);
		void				hide(void);
		void				show(void);
		void				raise(void);
		void				reload(void) const;

		// Setters -------------------------------------------------------------------------------------
		void				setTitle(cstring &);
		void				setPosition(int x, int y);
		void				setPosition(t_coor const &);
		void				setSize(int x, int y);
		void				setSize(t_dimension const &);
		void				setBackgroundColor(int r, int g, int b, int a);
		void				setBackgroundColor(Color const &);
		void				setFullScreen(Uint32 mode = WINDOW_FULLSCREEN);

		// Getters -------------------------------------------------------------------------------------
		cstring				&getTitle(void) const;
		t_coor const		&getPosition(void) const;
		t_dimension const	&getSize(void) const;
		int const			&getWFlags(void) const;

		// Events -------------------------------------------------------------------------------------
		virtual void		onQuit(Event);
		virtual void		onKeyUp(Event);
		virtual void		onKeyDown(Event);
		virtual void		onMouseHover(Event);
		virtual void		onMouseLeftClick(Event);
		virtual void		onMouseRightClick(Event);
		virtual void		onMouseMiddleClick(Event);
		virtual void		onMouseWheel(Event);
};

#endif
