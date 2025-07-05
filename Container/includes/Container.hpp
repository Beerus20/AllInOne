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

	public:
		Container(void);
		Container(Container const &);
		virtual ~Container(void);

		Container			&operator=(Container const &);
		bool				initTexture(
								Renderer,
								Uint32 = TEXTURE_TYPE,
								int = PIXEL_FORMAT);
		void				destroy(void);
		Texture				getTexture(void) const;

		virtual bool		draw(rRect);

};

#endif
