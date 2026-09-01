//File for displaying objects
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include "structLib.h"
#include "displayManager.h"

void renderCurrentFrame(Scene* scene, SDL_Renderer* renderer){
	SDL_SetRenderDrawColor(renderer,0, 0, 0, 0);
	SDL_RenderClear(renderer);
	//int size = scene->size;
	//for(int i = 0; i < size; i++){
	//	continue;
	//}
	//Object obj = scene->objArr[0];
	SDL_FRect rect;
	rect.x = 100;
	rect.y = 100;
	rect.w = 100;
	rect.h = 100;
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderRect(renderer,&rect);
	SDL_RenderPresent(renderer);
}

void renderScene(SDL_Renderer* renderer, Scene* scene){
	//Nothing burger
}

void renderUI(SDL_Renderer* renderer){
	//Nothing burger
}
