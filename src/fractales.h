#ifndef FRACTALES_H
#define FRACTALES_H

#include <SDL2/SDL.h>

typedef struct Fractales_App
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} Fractales_App;

void Fractal_AppError(const char* message);

Fractales_App* CreateWindowApp();

void RunFractalsApp(Fractales_App *fractal_app);

void CloseWindowApp(Fractales_App *fractal_app);

#endif /*FRACTALES_H */