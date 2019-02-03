#include <iostream>
#include <windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <entities.h>
#include <graphics.h>
std::vector<SDL_Texture*> textures;
std::vector<std::string> textureFnames = {"player.png", "enemy.png", "projectile.png", "reticle.png"};
SDL_Renderer* ourRenderer = NULL;
void setColor(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void render(void* pt, int type, color* Color){
	switch(type){
		case rectangleRender:
			{
				if (Color != NULL){
					SDL_Rect* rect = (SDL_Rect*)pt;
					SDL_SetRenderDrawColor(ourRenderer, Color->r, Color->g, Color->b, Color->a);
					SDL_RenderFillRect(ourRenderer, rect);
				}
			}
			break;
		case spriteRender:
		    SDL_RenderCopy(ourRenderer, ((Texture*)pt)->first, NULL, ((Texture*)pt)->second);
			break;
	}
}
void renderAll(SDL_Renderer* renderer, const std::vector<entity*>& ents){
	if (ourRenderer == NULL){
		ourRenderer = renderer;
	}
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderClear(renderer);
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) ) { printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() ); }
	for(int i = 0; i < ents.size(); ++i){
		ents[i]->renderMe();
	}
	SDL_RenderPresent(renderer);
}
SDL_Texture* loadFromPath(SDL_Renderer* renderer, std::string path){
	SDL_Texture* a;
	SDL_Surface* load = IMG_Load(path.c_str());
	a = SDL_CreateTextureFromSurface(renderer, load);
	return a;
}
void initTextures(SDL_Renderer* renderer){
	for(int i = 0; i < ALWAYS_LAST; ++i){
		textures.push_back (loadFromPath(renderer, "resources/" + textureFnames[i]));
	}
}
SDL_Texture* getTexture(int type){
	return textures[type];
}