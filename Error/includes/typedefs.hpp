#ifndef ERROR_TYPEDEFS_HPP
# define ERROR_TYPEDEFS_HPP

# include "enums.hpp"
# include <string>
# include <utility>
# include <vector>

typedef std::string						string;
typedef string const					cstring;


typedef std::pair<error_status, string>	e_status;
typedef std::vector<e_status>			error_list;

#endif
