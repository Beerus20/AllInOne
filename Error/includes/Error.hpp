#ifndef ERROR_HPP
# define ERROR_HPP

# include <iostream>
# include <string>
class Error
{
	public:
		~Error (void);

		static void		error(std::string const &message);
		static void		error(std::string const &label, std::string const &message);
		static void		debug(std::string const &message);
		static void		debug(std::string const &label, std::string const &message);
		static void		info(std::string const &message);
		static void		info(std::string const &label, std::string const &message);
		static void		warning(std::string const &message);
		static void		warning(std::string const &label, std::string const &message);
		static void		sdl(std::string const &label);

		static std::string const InvalidWindowConfiguration;

	private:
		Error (void);
		Error (const Error&);
		Error &operator=(const Error&);

};

#endif