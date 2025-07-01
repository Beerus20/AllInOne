#ifndef UTILITIES_TYPEDEF_HPP
# define UTILITIES_TYPEDEF_HPP

# include <SDL2/SDL_events.h>
# include <SDL2/SDL_rect.h>
# include <SDL2/SDL_render.h>
# include <SDL2/SDL_surface.h>
# include <string>
# include "Utilities.defines.hpp"

typedef std::string					string;
typedef string const 				cstring;
typedef string *__restrict__		rstring;
typedef cstring *__restrict__		crstring;

typedef SDL_Point					Point;
typedef Point const					cPoint;
typedef Point *__restrict__			rPoint;
typedef cPoint *__restrict__		crPoint;

typedef SDL_Rect					Rect;
typedef Rect const					cRect;
typedef Rect *__restrict__			rRect;
typedef cRect *__restrict__			crRect;

typedef SDL_Texture					Texture;
typedef Texture const				cTexture;
typedef Texture *__restrict__		rTexture;
typedef cTexture *__restrict__		crTecTexture;

typedef SDL_Renderer				Renderer;
typedef Renderer const				cRenderer;
typedef Renderer *__restrict__		rRenderer;
typedef cRenderer *__restrict__		crRenderer;

typedef SDL_Surface					Surface;
typedef Surface const				cSurface;
typedef Surface *__restrict__		rSurface;
typedef cSurface *__restrict__		crSurface;

typedef SDL_PixelFormat				PixelFormat;
typedef PixelFormat const			cPixelFormat;
typedef PixelFormat *__restrict__	rPixelFormat;
typedef cPixelFormat *__restrict__	crPixelFormat;

typedef SDL_Event					Event;
typedef Event const					cEvent;
typedef Event *__restrict__			rEvent;
typedef cEvent *__restrict__		crEvent;


#endif
