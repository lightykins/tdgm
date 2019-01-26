#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <entities.h>
#include <graphics.h>
std::vector<SDL_Texture*> textures;
std::vector<std::string> textureFnames = {"player.png", "enemy.png", "projectile.png", "reticle.png"};
void render(void* pt, SDL_Renderer* renderer, color* Color, int type){
	switch(type){
		case rectangleRender:
		{
		    SDL_Rect* rect = (SDL_Rect*)pt;
			SDL_SetRenderDrawColor(renderer, Color->r, Color->g, Color->b, Color->a);
			SDL_RenderFillRect(renderer, rect);
		}
			break;
		case spriteRender:
		    SDL_RenderCopy(renderer, ((Texture*)pt)->first, NULL, ((Texture*)pt)->second);
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
				static Player* pt = (Player*)(ents[i].first);
				render(&(pt->hitbox), renderer, &hbox, rectangleRender);
				static Texture txt;
				txt.first = pt->sprite;
				txt.second = &(pt->hitbox);
				render(&txt, renderer, NULL, spriteRender);
				break;
			case enemy:
				static Enemy* pt2 = (Enemy*)(ents[i].first);
				render(&(pt2->hitbox), renderer, &hbox, rectangleRender);
				static Texture txt2;
				txt2.first = pt2->sprite;
				txt2.second = &(pt2->hitbox);
				render(&txt2, renderer, NULL, spriteRender);
				break; //////
			case projectile:
				break;
			case tex:
				render((Texture*)(ents[i].first), renderer, NULL, spriteRender);
		}
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