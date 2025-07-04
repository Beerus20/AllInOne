#ifndef UTILS_HPP
# define UTILS_HPP

#include <SDL2/SDL_stdinc.h>

class Utils
{
	private:
		Utils(void);
		Utils(Utils const &);

		Utils	&operator=(Utils const &);

	public:
		virtual ~Utils(void);

		void	delay(Uint32);
};

#endif
