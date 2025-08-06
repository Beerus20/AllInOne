#ifndef UTILS_COLOR_HPP
# define UTILS_COLOR_HPP

# include <iostream>

class Color
{
	public:
		virtual ~Color(void);
		static const		std::string Reset;
		static const		std::string Black;
		static const		std::string Red;
		static const		std::string Green;
		static const		std::string Yellow;
		static const		std::string Blue;
		static const		std::string Magenta;
		static const		std::string Cyan;
		static const		std::string White;

		static const		std::string BgBlack;
		static const		std::string BgRed;
		static const		std::string BgGreen;
		static const		std::string BgYellow;
		static const		std::string BgBlue;
		static const		std::string BgMagenta;
		static const		std::string BgCyan;
		static const		std::string BgWhite;

		static const		std::string Bold;
		static const		std::string Underline;
		static const		std::string Reversed;
		static const		std::string Italic;

		static const		std::string black(std::string const &content);
		static const		std::string red(std::string const &content);
		static const		std::string green(std::string const &content);
		static const		std::string yellow(std::string const &content);
		static const		std::string blue(std::string const &content);
		static const		std::string magenta(std::string const &content);
		static const		std::string cyan(std::string const &content);
		static const		std::string white(std::string const &content);

		static const		std::string bgBlack(std::string const &content);
		static const		std::string bgRed(std::string const &content);
		static const		std::string bgGreen(std::string const &content);
		static const		std::string bgYellow(std::string const &content);
		static const		std::string bgBlue(std::string const &content);
		static const		std::string bgMagenta(std::string const &content);
		static const		std::string bgCyan(std::string const &content);
		static const		std::string bgWhite(std::string const &content);

		static const		std::string bold(std::string const &content);
		static const		std::string underline(std::string const &content);
		static const		std::string reversed(std::string const &content);
		static const		std::string italic(std::string const &content);
		static std::string	text(const std::string &style, const std::string &content, const std::string &endl = "");

	private:

};

std::ostream& operator << ( std::ostream& os, const Color &color);

#endif