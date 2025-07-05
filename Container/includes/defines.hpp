#ifndef CONTAINER_DEFINES_HPP
# define CONTAINER_DEFINES_HPP

# define CONTAINER_DEFAULT_VALUE	0, 0, 900, 800

// SDL_TEXTUREACCESS_STATIC			La texture est rarement modifiée
// SDL_TEXTUREACCESS_STREAMING		La texture est souvent modifiée
// SDL_TEXTUREACCESS_TARGET			La texture peut être utilisée comme cible de rendu (comme un renderer)
# define TEXTURE_TYPE				SDL_TEXTUREACCESS_TARGET
# define PIXEL_FORMAT				SDL_PIXELFORMAT_RGBA8888

#endif
