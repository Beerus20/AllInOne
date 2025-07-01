#ifndef CONTAINER_HPP
# define CONTAINER_HPP

# include "../Utilities/Utilities.hpp"
# include "../Box/Box.hpp"
# include "../Draw/Draw.hpp"

class Container : public Box
{
	protected:
		Texture			*_texture;
		Uint32			*_pixels;
		int				_format;
		int				_access;

	public:
		Container(void);
		Container(Container const &);
		Container(Texture *texture);
		Container(int w, int h, Uint32 = TEXTURE_DEFAULT_FORMAT, int = TEXTURE_DEFAULT_ACCESS);
		virtual ~Container(void);

		Container		&operator=(Container const &);

		void			init(Renderer *renderer, TEXTURE_DEFAULT_CONFIG);
		void			destroy(void);

		// Utils ------------------------------------------------------------------------------------
		bool			addAt(crRect src = NULL, crRect dst = NULL);
		bool			addTo(Container *__restrict__ container, crRect src = NULL, crRect dst = NULL);

		// Setters ------------------------------------------------------------------------------------
		void			setTexture(Texture *texture);
		void			setAccess(int access_type);

		// Getters ------------------------------------------------------------------------------------
		Texture			*getTexture(void) const;
		int				getAccess(void) const;
		Uint32			*getPixels(void) const;

		// Events ------------------------------------------------------------------------------------
		virtual void	onQuit(Event);
		virtual void	onKeyUp(Event);
		virtual void	onKeyDown(Event);
		virtual void	onMouseHover(Event);
		virtual void	onMouseLeftClick(Event);
		virtual void	onMouseRightClick(Event);
		virtual void	onMouseMiddleClick(Event);
		virtual void	onMouseWheel(Event);
};

#endif