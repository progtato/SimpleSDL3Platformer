//Header for display manager
#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H
#include "structLib.h"
#include <SDL3/SDL_render.h>
//Function declarations
void renderCurrentFrame(Scene*, SDL_Renderer*);

void renderScene(SDL_Renderer*, Scene*);

void renderUI(SDL_Renderer*);
#endif

