#include "./includes/FileParser.hpp"
#include <cstddef>
#include <fstream>
#include <string>
#include "../Error/includes/Error.hpp"

FileParser::FileParser(std::string const &path)
{
	(void)path;
}

FileParser::FileParser(const FileParser &) {}
FileParser::~FileParser(void) {}
FileParser &FileParser::operator=(const FileParser &) { return (*this); }
std::ostream& FileParser::print(std::ostream& os) const
{
	os << "print FileParser";
	return os;
}

bool FileParser::operator==(const FileParser &) const
{
	return (false);
}

bool FileParser::operator!=(const FileParser &) const
{
	return (false);
}

std::ostream& operator << ( std::ostream& os, const FileParser &fileparser)
{
	return fileparser.print(os);
}

Map<std::string>::string	FileParser::parse(std::string const &path)
{
	std::ifstream				file(Utils::open(path));
	std::string					line;
	Vector::string				tmp;
	Map<std::string>::string	rvalue;
	std::size_t					line_index(0);

	while (std::getline(file, line) && ++line_index)
	{
		if (!line.empty())
		{
			tmp = Utils::split(line, " : ");
			if (tmp.size() != 2)
				Error::error(Error::InvalidConfiguration + " at line : " + Utils::toString(line_index));
			rvalue[tmp[0]] = tmp[1];
		}
	}
	return (rvalue);
}

