#include <SDL.h>
#include <graphics.h>

void render(void* pt, SDL_Renderer* renderer, color Color, int type){
	switch(type){
		case rectangle:
		{
		    SDL_Rect* rect = (SDL_Rect*)pt;
			SDL_SetRenderDrawColor(renderer, Color.r, Color.g, Color.b, Color.a);
			SDL_RenderFillRect(renderer, rect);
		}
			break;
		case sprite:
		    //...
			break;
	}
}