#ifndef DATA_HPP
# define DATA_HPP

# include "../Utilities/Utilities.typedef.hpp"

class Data
{
	private:
		static bool		status;
		static Renderer	*renderer;
		
		Data(void);
		Data(Data const &);
		Data	&operator=(Data const &);

	public:
		virtual ~Data(void);

		static void		setRenderer(Renderer *__restrict__ renderer);
		static Renderer	*getRenderer(void);
		static void		lock(void);
		static void		unlock(void);
		static bool		islocked(void);

		static bool		isNull(void);
		static void		destroy(void);
};

#endif