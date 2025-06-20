#ifndef ERROR_HPP
# define ERROR_HPP

# include "../Utilities/Utilities.typedef.hpp"

class Error
{
	private:
		Error(void);
		Error(Error const &);

		Error	&operator=(Error const &);
		
		static void	onfail(cstring &message, bool exit_on_fail);
	public:
		virtual ~Error(void);
		
		static void	check(bool condition, cstring &error_message, cstring &success_message, bool exit_on_fail = false);
		static void	check(bool condition, cstring &error_message, bool exit_on_fail = false);
		static void	sdl_check(bool condition, cstring &error_message, cstring &success_message, bool exit_on_fail = true);
		static void	sdl_check(bool condition, cstring &error_message, bool exit_on_fail = true);
};

#endif
