#include "../includes/Window.hpp"
Window::Window(void) : _title("Window"), _rect((SDL_Rect){0, 0, 0, 0}), _flag(DEFAULT_WFLAGS) {}
Window::Window(const Window &other) { *this = other; }
Window::~Window(void) {}
Window &Window::operator=(const Window &other)
{
	if (this != &other)
	{
		this->_title = other._title;
		this->_rect = other._rect;
		this->_flag = other._flag;
	}
	return (*this);
}
std::ostream& Window::print(std::ostream& os) const
{
	os
		<< "WINDOW title : [ " << Color::blue(this->_title) << " ]" << std::endl
		<< "\trect" << " : " << this->_rect << std::endl;
	return os;
}

bool Window::operator==(const Window &other) const
{
	return (this->_title == other._title && this->_flag == other._flag);
}

bool Window::operator!=(const Window &other) const
{
	return (!(*this == other));
}

std::ostream& operator << ( std::ostream& os, const Window &window)
{
	return window.print(os);
}

void	Window::init(Map<std::string>::string config)
{
	this->_title = config.at("TITLE");
	this->_rect = (SDL_Rect) {
			Utils::convert<int>(
				config.at("X") == "center" ?
					SDL_WINDOWPOS_CENTERED :
					Utils::convert<int>(config.at("X"))),
			Utils::convert<int>(
				config.at("Y") == "center" ?
					SDL_WINDOWPOS_CENTERED :
					Utils::convert<int>(config.at("Y"))),
			Utils::convert<int>(config.at("WIDTH")),
			Utils::convert<int>(config.at("HEIGHT")),
		};
	this->initFlag(config.at("FLAGS"));
}

void	Window::init(std::string const &title, SDL_Rect const &rect, t_window_flag flag)
{
	this->_title = title;
	this->_rect = rect;
	this->_flag = flag;
}

void	Window::init(std::string const &title, int x, int y, int w, int h, t_window_flag flag)
{
	this->_title = title;
	this->_rect = (SDL_Rect){x, y, w, h};
	this->_flag = flag;
}

void	Window::initFlag(std::string const &str_flag)
{
	Vector::string	flags(Utils::split(str_flag, "|"));
	int				flag(0);

	for (Vector::string::const_iterator it(flags.begin()); it != flags.end(); it++)
	{
		if (*it == "FULLSCREEN")
			flag |= FULLSCREEN;
		else if (*it == "FULLSCREEN_DESKTOP")
			flag |= FULLSCREEN_DESKTOP;
		else if (*it == "SHOWN")
			flag |= SHOWN;
		else if (*it == "HIDDEN")
			flag |= HIDDEN;
		else if (*it == "BORDERLESS")
			flag |= BORDERLESS;
		else if (*it == "RESIZABLE")
			flag |= RESIZABLE;
		else if (*it == "MINIMIZED")
			flag |= MINIMIZED;
		else if (*it == "MAXIMIZED")
			flag |= MAXIMIZED;
		else
			Error::error(Error::Window::InvalidConfiguration);
	}
	this->_flag = (t_window_flag)flag;
}

