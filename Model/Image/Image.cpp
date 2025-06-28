#include "Image.hpp"
#include "../../Load/Load.hpp"

Image::Image(void) :
	_path("")
{}

Image::Image(Image const &copy) :
	Container()
{
	*this = copy;
}

Image::Image(cstring &path)
{
	this->setPath(path);
}

Image::~Image(void) {}

Image	&Image::operator=(Image const &assign)
{
	if (this != &assign)
	{
		Container::operator=(assign);
		this->_path = assign._path;
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
