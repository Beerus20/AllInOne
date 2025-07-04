#ifndef ERROR_HPP
# define ERROR_HPP

#include "enums.hpp"
# include "typedefs.hpp"
# include <string>
# include <utility>
# include <vector>

class Error
{
	private:
		static error_list		_list;

		Error(void);
		Error(Error const &);

		Error					&operator=(Error const &);

	public:
		static unsigned int		nb;
		virtual ~Error(void);

		static void				warning(cstring &);
		static void				debug(cstring &);
		static void				info(cstring &);
		static void				error(cstring &);
		static void				add(error_status, cstring & = "");
		static void				check(bool condition, cstring &error_msg = "", cstring &succes_msg = "");
};

#endif
