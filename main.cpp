#include <SDL2/SDL_rect.h>
#include <iostream>
#include <ostream>
#include "Draw/Draw.hpp"
#include "Utilities/Utilities.typedef.hpp"
#include "Window/Window.hpp"
#include "Utilities/Utilities.color.hpp"
#include "Container/Container.hpp"

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	std::cout << "Hello world" << std::endl;
	Window		window;
	SDL_Texture *texture = NULL;
	Container	nav;
	SDL_Renderer *renderer = NULL;

	window.setBackgroundColor(WHITESMOKE);
	nav.init(Data::getRenderer());
	// if (!Draw::in(&nav))
	// 	std::cout << "Target changement error" << std::endl;
	// Draw::color(RED);
	// Draw::fillRect(&rect);
	// if (!nav.addAt(NULL, &rect))
	// 	std::cout << "Error adding container" << std::endl;
	// (void)window;
	
	SDL_Rect rect = {10, 10, 10, 10}, dst = {0, 0, 0, 0};
    SDL_Color rouge = {255, 0, 0, 255}, bleu = {0, 0, 255, 255};
	(void)dst;
	renderer = Data::getRenderer();
	texture = nav.getTexture();
	Draw::in(&nav);
	// SDL_SetRenderTarget(renderer, texture);
    /* La texture est la cible de rendu, maintenant, on dessine sur la texture. */
    SDL_SetRenderDrawColor(renderer, bleu.r, bleu.g, bleu.b, bleu.a);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, rouge.r, rouge.g, rouge.b, rouge.a);
    SDL_RenderFillRect(renderer, &rect); /* On dessine un rectangle rouge sur la texture. */
	
    SDL_SetRenderTarget(renderer, NULL); /* Le renderer est la cible de rendu. */
	
    /* On récupère les dimensions de la texture, on la copie sur le renderer
	et on met à jour l’écran. */
    // SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);

	nav.addAt();
    // SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
	Draw::apply();
	return (0);
}
