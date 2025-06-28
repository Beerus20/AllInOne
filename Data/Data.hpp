#ifndef DATA_HPP
# define DATA_HPP

# include "../Utilities/Utilities.typedef.hpp"

class Data
{
	private:
		static bool			status;
		static Renderer		*renderer;
		static PixelFormat	*pixel_format;

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

		static Renderer		*getRenderer(void);
		static PixelFormat	*getPixelFormat(void);

		static bool		isNull(void);
		static void		destroy(void);
		static void		destroyPixelFormat(void);
};

#endif