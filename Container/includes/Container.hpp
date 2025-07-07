#ifndef CONTAINER_HPP
# define CONTAINER_HPP

# include "../../Box/includes/Box.hpp"
# include "../../includes/typedefs.hpp"
# include "../../Draw/includes/Draw.hpp"
# include "defines.hpp"
#include <cstddef>

class Container : public Box
{
	private:
		Texture				_texture;
		Boxs				_content;
		Rect				_src;

	public:
		Container(void);
		Container(Container const &);
		virtual ~Container(void);

		Container			&operator=(Container const &);
		bool				initTexture(
								Renderer,
								Uint32 = PIXEL_FORMAT,
								int = TEXTURE_TYPE);
		void				destroy(void);
		Texture				getTexture(void) const;
		cRect				*getSrc(void) const;

		virtual bool		draw(void);

};

#endif
