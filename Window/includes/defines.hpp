#ifndef WINDOW_DEFINES_HPP
# define WINDOW_DEFINES_HPP

// SDL_WINDOW_FULLSCREEN				Crée une fenêtre en plein écran
// SDL_WINDOW_FULLSCREEN_DESKTOP		Crée une fenêtre en plein écran à la résolution du bureau
// SDL_WINDOW_SHOWN					Crée une fenêtre visible
// SDL_WINDOW_HIDDEN					Crée une fenêtre non visible
// SDL_WINDOW_BORDERLESS				Crée une fenêtre sans bordures
// SDL_WINDOW_RESIZABLE				Crée une fenêtre redimensionnable
// SDL_WINDOW_MINIMIZED				Crée une fenêtre minimisée
// SDL_WINDOW_MAXIMIZED				Crée une fenêtre maximisée

# define WINDOW_DEFAULT_FLAGS		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
# define WINDOW_DEFAULT_POS			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED
# define WINDOW_DEFAULT_SIZE		900, 800

#endif
