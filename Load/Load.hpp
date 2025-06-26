#ifndef LOAD_HPP
# define LOAD_HPP

# include "../Utilities/Utilities.typedef.hpp"


class Load
{
	private:
		static Surface	*_surface;

		Load(void);
		Load(Load const &);
		
		Load	&operator=(Load const &);

	public:
		virtual ~Load(void);
		static Texture	*image(cstring &image_path);

};

#endif