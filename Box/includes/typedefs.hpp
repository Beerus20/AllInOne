#ifndef BOX_TYPEDEFS_HPP
# define BOX_TYPEDEFS_HPP

#include <SDL2/SDL_rect.h>

typedef SDL_Rect				Rect;
typedef Rect const 				cRect;
typedef Rect *__restrict__		rRect;
typedef const rRect				crRect;

#endif
