#include "Image.hpp"
#include "../../Load/Load.hpp"

Image::Image(void) :
	_path("")
{}

Image::Image(Image const &copy)
{
	*this = copy;
}

Image::Image(cstring &path)
{
	this->setPath(path);
}

Image::~Image(void)
{
	this->destroy();
}

Image	&Image::operator=(Image const &assign)
{
	if (this != &assign)
	{
		Container::operator=(assign);
	}
	return (*this);
}

void	Image::setPath(cstring &path)
{
	Texture	*static_image(NULL);

	this->_path = path;
	static_image = Load::image(path);
	this->setTexture(static_image);
}
