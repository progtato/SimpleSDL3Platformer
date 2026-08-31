//Main file of the game
//Imports
#define SDL_MAIN_USE_CALLBACKS 1 //Used so you enter program with SDL_AppInit rather than main()
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "structLib.h"
#include "jsonManager.h"
#include "saveManager.h"
#include "displayManager.h"
#include "physics.h"

//Globals
#define CURRENT_LEVEL = 0;
#define GAME_OVER = 0;
static SDL_Window* window;
static SDL_Renderer* renderer;


//Function Definitions
//SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]){
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]){

	if (!SDL_SetAppMetadata("Test 1", "0.1", "wwwSMT")){
		return SDL_APP_FAILURE;
	}
	

	if (!SDL_CreateWindowAndRenderer("examples/renderer/clear", 640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        	SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        	return SDL_APP_FAILURE;
    	}
    	SDL_SetRenderLogicalPresentation(renderer, 640, 480, SDL_LOGICAL_PRESENTATION_LETTERBOX);

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }
    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    const double now = ((double)SDL_GetTicks()) / 1000.0;  /* convert from milliseconds to seconds. */
    /* choose the color for the frame we will draw. The sine wave trick makes it fade between colors smoothly. */
    const float red = (float) (0.5 + 0.5 * SDL_sin(now));
    const float green = (float) (0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 2 / 3));
    const float blue = (float) (0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 4 / 3));
    SDL_SetRenderDrawColorFloat(renderer, red, green, blue, SDL_ALPHA_OPAQUE_FLOAT);  /* new color, full alpha. */

    /* clear the window to the draw color. */
    SDL_RenderClear(renderer);

    /* put the newly-cleared rendering on the screen. */
    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    /* SDL will clean up the window/renderer for us. */
}
