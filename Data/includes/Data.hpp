#ifndef DATA_HPP
# define DATA_HPP

# include "defines.hpp"
# include "../../Error/includes/Error.hpp"
# include "typedefs.hpp"
# include "../../Container/includes/Container.hpp"

class Window;

class Data
{
	private:
		Data(void);
		Data(Data const &);

		Data			&operator=(Data const &);

	public:
		static bool		isInited;
		static Map		map;

		virtual ~Data(void);

		static void		init(int = LAUNCHER_DEFAULT_VALUE);
		static void		addContent(Box *__restrict__);

		static void		test(Box *, int x, int y);
		static void		updateMap(Box *, int x, int y);
};

#endif