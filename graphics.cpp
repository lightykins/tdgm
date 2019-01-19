#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <entities.h>
#include <graphics.h>
std::vector<SDL_Texture*> textures(10);
std::vector<std::string> textureFnames = {"player.png", "enemy.png", "projectile.png"};
void render(void* pt, SDL_Renderer* renderer, color Color, int type){
	switch(type){
		case rectangleRender:
		{
		    SDL_Rect* rect = (SDL_Rect*)pt;
			SDL_SetRenderDrawColor(renderer, Color.r, Color.g, Color.b, Color.a);
			SDL_RenderFillRect(renderer, rect);
		}
			break;
		case spriteRender:
		    //...
			break;
	}
}
void renderAll(SDL_Renderer* renderer, const std::vector<entity> &ents){
	color hbox;
	hbox.r = 255;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	static SDL_Rect* rect;
	for(int i = 0; i < ents.size(); ++i){
		switch(ents[i].second){
			case player:
				rect = &(((Player*)(ents[i].first))->hitbox);
				break;
			case projectile:
				break;
		}
		render(rect, renderer, hbox, rectangleRender);
	}
	SDL_RenderPresent(renderer);
}
SDL_Texture* loadFromPath(SDL_Renderer* renderer, std::string path){
	SDL_Texture* a;
	static SDL_Surface* load = IMG_Load(path.c_str());
	a = SDL_CreateTextureFromSurface(renderer, load);
	return a;
}
void initTextures(SDL_Renderer* renderer){
	for(int i = 0; i < ALWAYS_LAST; ++i){
		textures[i] = loadFromPath(renderer, "resources/" + textureFnames[i]);
	}
}
SDL_Texture* getTexture(int type){
	return textures[type];
}