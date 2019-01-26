#ifndef ENTITIES_INCLUDED
#define ENTITIES_INCLUDED

#include <SDL.h>
#include <graphics.h>
#include <input.h>
#include <iostream>
enum {player, enemy, projectile, tex};
const int playerIndex = 0;
const int reticleIndex = 1;
typedef std::pair<void*, int> entity;

struct Player{
	void update(); 
	unsigned int hp = 100;
	unsigned int def = 10;
	double moveSpeedX = 2;
	double moveSpeedY = 2;
	double speedX = 0;
	double speedY = 0;
	SDL_Rect hitbox;
	SDL_Texture* sprite = getTexture(playerTex);
	unsigned int renderType = spriteRender;
    Player();
};

struct Enemy{
	void update();
	unsigned int hp = 100;
	unsigned int def = 0;
	double moveSpeedX = 2;
	double moveSpeedY = 2;
	double speedX = 0;
	double speedY = 0;
	SDL_Rect hitbox;
	SDL_Texture* sprite = getTexture(enemyTex);
	unsigned int renderType = spriteRender;
	Enemy();
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
void setGlobalSpeed(unsigned int speed);
#endif