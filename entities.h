#ifndef ENTITIES_INCLUDED
#define ENTITIES_INCLUDED

#include <SDL.h>
#include <graphics.h>
#include <input.h>

enum {player, enemy, projectile};
typedef std::pair<void*, int> entity;
struct Player{
	unsigned int hp = 100;
	unsigned int def = 10;
	int speedX = 0;
	int speedY = 0;
	SDL_Rect hitbox;
	SDL_Texture* sprite;// = getTexture(playerTex);
	unsigned int renderType = spriteRender;
    Player();
	void update();
};

struct Projectile{
	int speedX = 0;
	int speedY = 0;
	SDL_Rect hitbox;
	SDL_Texture* sprite = getTexture(projectileTex);
	unsigned int renderType = spriteRender;
	void update();
};
#endif