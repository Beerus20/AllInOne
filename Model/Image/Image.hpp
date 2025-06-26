#ifndef IMAGE_HPP
# define IMAGE_HPP

# include "../../Container/Container.hpp"

class Image : Container
{
	private:
		string	_path;

	public:
		Image(void);
		Image(Image const &);
		Image(cstring &);
		virtual ~Image(void);

		Image	&operator=(Image const &);
		void	setPath(cstring &);
};

#endif