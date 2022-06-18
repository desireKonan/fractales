#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


void SDL_ExitWithError(const char* message);

int main(int argc, char** argv) {

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    //Création d'une fenêtre via SDL.
    if(SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        SDL_ExitWithError("Impossible d'initialiser une fenêtre avec la SDL !");
    }

    //Création d'une fenêtre avec rendu.
    if(SDL_CreateWindowAndRenderer(600, 400, 0, &window, &renderer) != 0) {
        SDL_ExitWithError("Impossible de créer le rendu de cette fenêtre !");
    }

    if(SDL_SetRenderDrawColor(renderer, 112, 168, 237, SDL_ALPHA_OPAQUE) != 0) {
        SDL_ExitWithError("Impossible de déssiner un point !");
    }


    SDL_Rect rectangle;
    rectangle.x = 300;
    rectangle.y = 300;
    rectangle.h = 200;
    rectangle.w = 400;


    if(SDL_RenderFillRect(renderer, &rectangle) != 0) {
        SDL_ExitWithError("Impossible de déssiner un rectangle !");
    }

    if(SDL_SetRenderDrawColor(renderer, 255, 25, 25, SDL_ALPHA_OPAQUE) != 0) {
        SDL_ExitWithError("Impossible de changer la couleur du rendu !");
    }

    if(SDL_RenderDrawLine(renderer, 50, 50, 200, 200) != 0) {
        SDL_ExitWithError("Impossible de dessiner une ligne !");
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(10000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    //SDL_Surface *image = NULL;
    //SDL_Texture *texture = NULL;
    //window = SDL_CreateWindow("Fractales", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, 0);

    /*if(window == NULL) {
        SDL_ExitWithError("Impossible de dessiner une ligne !");
        SDL_Log("ERREUR : Création fenètre échouée > %s\n", SDL_GetError());
        exit(EXIT_FAILURE); 
    }*/
    
    /*SDL_version nb;
    SDL_VERSION(&nb);

    printf("Version de SDL : --> %d.%d.%d ! \n", nb.major, nb.minor, nb.patch);*/
    return EXIT_SUCCESS;
} 


void SDL_ExitWithError(const char* message) {
    SDL_Log("ERREUR : %s, %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}