#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NBRE_ITERATION_MAX 15000

void SDL_ExitWithError(const char* message);

int main(int argc, char** argv) {

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    float c_x1 = 0.0;
    float c_y1 = 0.0; 
    float c_x2 = 0.0;
    float c_y2 = 0.0;
    float image_x = 0.0;
    float image_y = 0.0;
    int zoom = 100;
    int iter = 0;

    printf("[-----| Fractales |-----]\n");
    printf("|----- Donnez une constante (z = a + bi) : \n");
    printf("|----- Donnez un x1 (re) : \n");
    scanf("%f", &c_x1);
    printf("|----- Donnez un y1 (im) : \n");
    scanf("%f", &c_y1);
    printf("|----- Donnez un x2 (re) : \n");
    scanf("%f", &c_x2);
    printf("|----- Donnez un y2 (im) : \n");
    scanf("%f", &c_y2);
    printf("|----- Donnez un nombre d'itération : \n");
    scanf("%d", &iter);

    //Définir les coordonnées de l'images à dessiner à dessiner.
    image_x = (c_x1 - c_x2) * zoom;
    image_y = (c_y1 - c_y2) * zoom;

    //Si le nombre d'itération max est inférieur au nombre d'itération.
    if(iter > NBRE_ITERATION_MAX) {
        printf("Le nombre d'itération est très grand ! \n");
        exit(EXIT_FAILURE);
    }

    //Création d'une fenêtre via SDL.
    if(SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        SDL_ExitWithError("Impossible d'initialiser une fenêtre avec la SDL !");
    }

    window =  SDL_CreateWindow("Fractales Application", 50, 50, 800, 500, SDL_WINDOW_SHOWN);

    //Création d'une fenêtre avec rendu.
    if(window == NULL) {
        SDL_ExitWithError("Impossible de créer la fenêtre !");
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_SOFTWARE);

    //Création d'une fenêtre avec rendu.
    if(renderer == NULL) {
        SDL_ExitWithError("Impossible de créer le rendu de cette fenêtre !");
    }


    SDL_bool programme_lance = SDL_TRUE;

    while (programme_lance)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch(event.type) {
                case SDL_QUIT:
                    programme_lance = SDL_FALSE;
                    break;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_q) {
                        printf("Vous avez clique sur la touche %s", SDLK_q);
                        programme_lance = SDL_FALSE;
                    }
                    break;
                default:
                    break;
            }
        }
        

        //Code de la fractale.
        for (int x = 0; x < image_x; x++)
        {
            for (int y = 0; y < image_y; y++)
            {
                float c_r = x / zoom + c_x1;
                float c_i = y / zoom + c_y1;
                float z_r = 0.0;
                float z_i = 0.0;
                int i = 0;

                do
                {
                    float tmp = z_r;
                    z_r = z_r * z_r + z_i * z_i + c_r;
                    z_i = 2 * z_i * tmp + c_i;
                    i++;
                } while (z_r * z_r + z_i * z_i < 4 && i < iter);
                
                if(i == iter) {
                    //On redessine le point sur l'image.
                    SDL_RenderDrawPoint(renderer, x, y);
                    SDL_RenderPresent(renderer);
                }
            }          
        }
        
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
} 


void SDL_ExitWithError(const char* message) {
    SDL_Log("ERREUR : %s, %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}