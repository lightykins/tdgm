#ifndef ENTITIES_INCLUDED
#define ENTITIES_INCLUDED

#include <SDL.h>
#include <graphics.h>
#include <input.h>
#include <iostream>
enum {player, enemy, projectile};
typedef std::pair<void*, int> entity;

struct Player{
	void update(); 
	unsigned int hp = 100;
	unsigned int def = 10;
	int speedX = 0;
	int speedY = 0;
	SDL_Rect hitbox;
	SDL_Texture* sprite;// = getTexture(playerTex);
	unsigned int renderType = spriteRender;
    Player();
};

struct Projectile{
	void update(); 
	int speedX = 0;
	int speedY = 0;
	SDL_Rect hitbox;
	SDL_Texture* sprite = getTexture(projectileTex);
	unsigned int renderType = spriteRender;
};

void updateAll(std::vector<entity>& entities);
#endif