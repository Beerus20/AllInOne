#ifndef WINDOW_DEFINES_HPP
# define WINDOW_DEFINES_HPP

// SDL_WINDOW_FULLSCREEN			Crée une fenêtre en plein écran
// SDL_WINDOW_FULLSCREEN_DESKTOP	Crée une fenêtre en plein écran à la résolution du bureau
// SDL_WINDOW_SHOWN					Crée une fenêtre visible
// SDL_WINDOW_HIDDEN				Crée une fenêtre non visible
// SDL_WINDOW_BORDERLESS			Crée une fenêtre sans bordures
// SDL_WINDOW_RESIZABLE				Crée une fenêtre redimensionnable
// SDL_WINDOW_MINIMIZED				Crée une fenêtre minimisée
// SDL_WINDOW_MAXIMIZED				Crée une fenêtre maximisée

# define WINDOW_DEFAULT_FLAGS		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
# define WINDOW_DEFAULT_WIDTH		900
# define WINDOW_DEFAULT_HEIGHT		800
# define WINDOW_DEFAULT_POS			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED // SDL_WINDOWPOS_UNDEFINED
# define WINDOW_DEFAULT_SIZE		WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT
# define WINDOW_DEFAULT_PARAMS		WINDOW_DEFAULT_POS, WINDOW_DEFAULT_SIZE

# define WINDOW_INIT_DEFAULT		int x, int y, int w, int h, int flags
# define WINDOW_DEFINE_INIT_DEFAULT	int = SDL_WINDOWPOS_CENTERED,\
									int = SDL_WINDOWPOS_CENTERED,\
									int = WINDOW_DEFAULT_WIDTH,\
									int = WINDOW_DEFAULT_HEIGHT,\
									int = WINDOW_DEFAULT_FLAGS

# define _WRECT(rect)				rect->getX(), rect->getY(), rect->getW(), rect->getH()

// SDL_RENDERER_SOFTWARE			Le renderer est logiciel, le rendu sera effectué par le CPU et les données seront stockées en mémoire vive.
// SDL_RENDERER_ACCELERATED			Le renderer utilise l’accélération matérielle. Les données sont en mémoire vidéo, plus rapide que la mémoire vive.
// SDL_RENDERER_PRESENTVSYNC		La mise à jour de la fenêtre de rendu est synchronisé avec la fréquence de rafraîchissement de l’écran.
# define WINDOW_RENDERER_TYPE		SDL_RENDERER_ACCELERATED

#endif
