#ifndef DATA_HPP
# define DATA_HPP

# include "defines.hpp"
# include "../../Error/includes/Error.hpp"

class Data
{
	private:
		Data(void);
		Data(Data const &);

		Data	&operator=(Data const &);

	public:
		virtual ~Data(void);

		static void	init(int = LAUNCHER_DEFAULT_VALUE);
};

#endif