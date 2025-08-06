#include "./includes/Utils.hpp"
#include <cstddef>
#include <fstream>
#include "../Error/includes/Error.hpp"

Utils::Utils(void) {}
Utils::Utils(const Utils &) {}
Utils::~Utils(void) {}
Utils &Utils::operator=(const Utils &) { return (*this); }

std::ifstream	Utils::open(std::string const &path, std::ios_base::openmode mode)
{
	std::ifstream	file_stream(path, mode);

	if (!file_stream.is_open())
		Error::error("file not found : " + path);
	return (file_stream);
}

Vector::string	Utils::split(const std::string &text, std::string const &separator)
{
	Vector::string	rvalue;
	std::string		tmp("");
	std::size_t		tlen(text.length());
	std::size_t		slen(separator.length());
	std::size_t		i(0);

	while (i < tlen)
	{
		if (text[i] == separator[0] && text.compare(i, slen, separator) == 0)
		{
			i += slen;
			if (!tmp.empty())
				rvalue.push_back(tmp);
			tmp.clear();
			continue ;
		}
		tmp += text[i++];
	}
	if (tmp.length() != 0)
		rvalue.push_back(tmp);
	return (rvalue);
}
