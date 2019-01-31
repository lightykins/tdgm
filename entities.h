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
	double x = 100;
	double y = 100;
	unsigned int hp = 100;
	unsigned int def = 10;
	double moveSpeedX = 2;
	double moveSpeedY = 2;
	double speedX = 0;
	double speedY = 0;
	SDL_Rect hitbox;
	SDL_Texture* sprite = getTexture(playerTex);
	unsigned int renderType = spriteRender;
	long index = 0;
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
	long index;
	Enemy();
};

struct Projectile{
	void update(); 
	double x;
	double y;
	double speedX = 0;
	double speedY = 0;
	SDL_Rect hitbox;
	SDL_Texture* sprite = getTexture(projectileTex);
	unsigned int renderType = spriteRender;
	long index;
	Projectile();
};
std::vector<entity>& getEntities();
void removeEntity(long index);
void updateAll(std::vector<entity>& entities);
void setGlobalSpeed(double speed);
#endif