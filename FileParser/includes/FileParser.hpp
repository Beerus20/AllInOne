#ifndef FILEPARSER_HPP
# define FILEPARSER_HPP

# include <iostream>
#include <string>
# include "../../Utils/includes/Utils.hpp"

class FileParser
{
	public:
		FileParser(std::string const &path);
		FileParser(const FileParser&);
		virtual ~FileParser(void);
		FileParser						&operator=(const FileParser&);
		std::ostream&					print(std::ostream& os) const;
		bool							operator==(const FileParser &) const;
		bool							operator!=(const FileParser &) const;

		static Map<std::string>::string	parse(std::string const &path);

	private:

};

std::ostream& operator << ( std::ostream& os, const FileParser &fileparser);

#endif