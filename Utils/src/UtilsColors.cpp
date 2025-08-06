#include "../includes/UtilsColors.hpp"

const std::string Color::Reset = "\033[0m";
const std::string Color::Black = "\033[30m";
const std::string Color::Red = "\033[31m";
const std::string Color::Green = "\033[32m";
const std::string Color::Yellow = "\033[33m";
const std::string Color::Blue = "\033[34m";
const std::string Color::Magenta = "\033[35m";
const std::string Color::Cyan = "\033[36m";
const std::string Color::White = "\033[37m";

const std::string Color::BgBlack = "\033[40m";
const std::string Color::BgRed = "\033[41m";
const std::string Color::BgGreen = "\033[42m";
const std::string Color::BgYellow = "\033[43m";
const std::string Color::BgBlue = "\033[44m";
const std::string Color::BgMagenta = "\033[45m";
const std::string Color::BgCyan = "\033[46m";
const std::string Color::BgWhite = "\033[47m";

const std::string Color::Bold = "\033[1m";
const std::string Color::Underline = "\033[4m";
const std::string Color::Reversed = "\033[7m";
const std::string Color::Italic = "\033[3m";

std::string Color::text(const std::string &style, const std::string &content, const std::string &endl)
{
	return style + content + Color::Reset + endl;
}

const std::string Color::black(std::string const &content)
{
	return (Color::Black + content + Color::Reset);
}
const std::string Color::red(std::string const &content)
{
	return (Color::Red + content + Color::Reset);
}
const std::string Color::green(std::string const &content)
{
	return (Color::Green + content + Color::Reset);
}
const std::string Color::yellow(std::string const &content)
{
	return (Color::Yellow + content + Color::Reset);
}
const std::string Color::blue(std::string const &content)
{
	return (Color::Blue + content + Color::Reset);
}
const std::string Color::magenta(std::string const &content)
{
	return (Color::Magenta + content + Color::Reset);
}
const std::string Color::cyan(std::string const &content)
{
	return (Color::Cyan + content + Color::Reset);
}
const std::string Color::white(std::string const &content)
{
	return (Color::White + content + Color::Reset);
}

const std::string Color::bgBlack(std::string const &content)
{
	return (Color::BgBlack + content + Color::Reset);
}
const std::string Color::bgRed(std::string const &content)
{
	return (Color::BgRed + content + Color::Reset);
}
const std::string Color::bgGreen(std::string const &content)
{
	return (Color::BgGreen + content + Color::Reset);
}
const std::string Color::bgYellow(std::string const &content)
{
	return (Color::BgYellow + content + Color::Reset);
}
const std::string Color::bgBlue(std::string const &content)
{
	return (Color::BgBlue + content + Color::Reset);
}
const std::string Color::bgMagenta(std::string const &content)
{
	return (Color::BgMagenta + content + Color::Reset);
}
const std::string Color::bgCyan(std::string const &content)
{
	return (Color::BgCyan + content + Color::Reset);
}
const std::string Color::bgWhite(std::string const &content)
{
	return (Color::BgWhite + content + Color::Reset);
}

const std::string Color::bold(std::string const &content)
{
	return (Color::Bold + content + Color::Reset);
}
const std::string Color::underline(std::string const &content)
{
	return (Color::Underline + content + Color::Reset);
}
const std::string Color::reversed(std::string const &content)
{
	return (Color::Reversed + content + Color::Reset);
}
const std::string Color::italic(std::string const &content)
{
	return (Color::Italic + content + Color::Reset);
}
