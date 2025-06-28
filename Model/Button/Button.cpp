#include "Button.hpp"

Button::Button(void) :
	_label("")
{}

Button::Button(Button const &copy) :
	Container()
{
	*this = copy;
}

Button::Button(cstring const &label) :
	_label(label)
{}
Button::~Button() {}

Button	&Button::operator=(Button const &assign)
{
	if (this != &assign)
	{
		Container::operator=(assign);
		this->_label = assign._label;
	}
	return (*this);
}

cstring	&Button::getLabel(void) const
{
	return (this->_label);
}

void	Button::setLabel(cstring const &label)
{
	this->_label = label;
}
