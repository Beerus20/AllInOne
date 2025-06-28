#ifndef DATA_HPP
# define DATA_HPP

# include "../Utilities/Utilities.typedef.hpp"

class Container;

class Data
{
	private:
		static bool			status;
		static Renderer		*renderer;
		static PixelFormat	*pixel_format;
		static Container	*container_target;

		Data(void);
		Data(Data const &);
		Data	&operator=(Data const &);

	public:
		virtual ~Data(void);

		static void		lock(void);
		static void		unlock(void);
		static bool		islocked(void);

		static void		setRenderer(Renderer *__restrict__ renderer);
		static void		setPixelFormat(Uint32);
		static void		setContainerTarget(Container *);

		static Renderer		*getRenderer(void);
		static PixelFormat	*getPixelFormat(void);
		static Container	*getContainerTarget(void);

		static bool		isNull(void);
		static void		destroy(void);
		static void		destroyPixelFormat(void);
};

#endif