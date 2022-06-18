#include <math.h>
#include "fractales.h"

void Fractal_AppError(const char* message) {
    SDL_Log("ERREUR : %s, %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}


Fractales_App* CreateWindowApp() {
    //Crée la structure et les ressources de notre application.
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

    return NULL;
}


void RunFractalsApp(Fractales_App *fractal_app) {
    //Toute la logique de notre application.
}


void CloseWindowApp(Fractales_App *fractal_app) {
    //Tues toutes les ressources de notre application.
}