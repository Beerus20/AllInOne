#ifndef LOAD_HPP
# define LOAD_HPP

# include "../Utilities/Utilities.typedef.hpp"

class Load
{
	private:
		Load(void);
		Load(Load const &);
		
		Load	&operator=(Load const &);

	public:
		virtual ~Load(void);
		Texture	*image(cstring &image_path);

};

#endif