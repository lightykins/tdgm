#ifndef ENTITIES_INCLUDED
#define ENTITIES_INCLUDED

#include <SDL.h>
#include <input.h>
#include <vector>
#include <iostream>
enum {player, enemy, projectile, tex};
const int playerIndex = 0;
const int reticleIndex = 1;
typedef std::pair<SDL_Texture*, SDL_Rect*> Texture;
//typedef std::pair<void*, int> entity;
class entity {
	public:
		virtual void update() {};
		virtual void renderMe() {};
		unsigned int collideType;
		unsigned int type;
		bool dead = 0;
};
class Player : public entity{
	public:
		virtual void update(); 
		virtual void renderMe();
		unsigned int collideType = 1 << player;
		unsigned int type = player;
		
		double x = 100;
		double y = 100;
		unsigned int hp = 100;
		unsigned int def = 10;
		double moveSpeedX = 2;
		double moveSpeedY = 2;
		double speedX = 0;
		double speedY = 0;
		SDL_Rect hitbox;
		SDL_Texture* sprite;
		Texture* texture;
		SDL_Rect reticleBox;
		SDL_Texture* reticleSprite;
		Texture* reticleTexture;
		unsigned int renderType;
		Player();
};

class Enemy : public entity{
	public:
		virtual void update();
		virtual void renderMe();
		unsigned int collideType = 1 << enemy;
		unsigned int type = enemy;
		
		unsigned int hp = 100;
		unsigned int def = 0;
		double moveSpeedX = 2;
		double moveSpeedY = 2;
		double speedX = 0;
		double speedY = 0;
		SDL_Rect hitbox;
		SDL_Texture* sprite;
		Texture* texture;
		unsigned int renderType;
		Enemy();
};

class Projectile : public entity{
	public:
		virtual void update(); 
		virtual void renderMe();
		unsigned int collideType = 1 << projectile;
		unsigned int type = projectile;
		//bool dead = 0;
		
		double x;
		double y;
		double speedX = 0;
		double speedY = 0;
		SDL_Rect hitbox;
		SDL_Texture* sprite;
		Texture* texture;
		unsigned int renderType;
		long index;
		Projectile();
};
std::vector<entity*>& getEntities();
void removeEntity(long index);
void updateAll(std::vector<entity*>& entities);
void setGlobalSpeed(double speed);
#endif