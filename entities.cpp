#include <entities.h>
#include <graphics.h>
#include <input.h>
#include <math.h>
#include <iostream>
double globalSpeed = 1;
unsigned int last2 = 0;
std::vector<entity*> entities;
long currEntityReserve = 128;
bool enemyLatch = 1;

std::vector<entity*>& getEntities(){
	static bool once = [](){
		entities.reserve(128);
		return true;
	} ();
	return entities;
}
void removeEntity(long index){
	std::vector<entity*>& ents = getEntities();
	ents.erase(ents.begin()+index);
}
Player::Player(){
	hitbox.x = 100;
	hitbox.y = 100;
	hitbox.w = 50;
	hitbox.h = 50;
	sprite = getTexture(playerTex);
	renderType = spriteRender;
	texture = new Texture;
	*texture = {sprite, &hitbox};
	reticleBox.w = 50;
	reticleBox.h = 50;
	reticleSprite = getTexture(reticleTex);
	reticleTexture = new Texture;
	*reticleTexture = {reticleSprite, &reticleBox};
}
Enemy::Enemy(){
	hitbox.x = getInput()->mx;
	hitbox.y = getInput()->my;
	hitbox.w = 50;
	hitbox.h = 50;
	sprite = getTexture(enemyTex);
	renderType = spriteRender;
	texture = new Texture;
	*texture = {sprite, &hitbox};
}
Projectile::Projectile(){
	Player* plr = (Player*)(getEntities()[0]);
	hitbox.x = plr->hitbox.x;
	hitbox.y = plr->hitbox.y;
	this->x = hitbox.x;
	this->y = hitbox.y;
	hitbox.w = 50;
	hitbox.h = 50;
	sprite = getTexture(projectileTex);
	renderType = spriteRender;
	texture = new Texture;
	*texture = {sprite, &hitbox};
}
void Player::update(){
	//unsigned int last2;
	if (!this->hp){
		std::cout << "You fucked up\n";
	}
	reticleBox.x = getInput()->mx - reticleBox.w/2;
	reticleBox.y = getInput()->my - reticleBox.h/2;
	if (getInput()->one && enemyLatch){
		enemyLatch = 0;
		getEntities().push_back(new Enemy);
	}
	if (!getInput()->one){
		enemyLatch = 1;
	}
	if (getInput()->m1 && ((SDL_GetTicks() - last2) > 200)){
		last2 = SDL_GetTicks();
		Projectile* pj = new Projectile;
		//Texture* reticle = (Texture*)(entities[1]);
		double x = reticleBox.x - reticleBox.w/2 - hitbox.x;
		double y = reticleBox.y - reticleBox.h/2 - hitbox.y;
		normalise(x, y);
		pj->speedX = x;
		pj->speedY = y;
		entities.push_back(pj);
	}
	if (getInput()->w == getInput()->s){
		speedY = 0;
	}else
	{
		speedY = (getInput()->w ? -1 : 1)*moveSpeedY*globalSpeed;
	}
	if (getInput()->d == getInput()->a){
		speedX = 0;
	}else
	{
		speedX = (getInput()->a ? -1 : 1)*moveSpeedY*globalSpeed;
	}
	bool x = speedX != 0;
	bool y = speedY != 0;
	double deltaX = speedX < 0 ? speedX * -1 : speedX;
	double deltaY = speedY < 0 ? speedY * -1 : speedY;
	normalise(deltaX, deltaY);
	if (x){
		this->x += (speedX * deltaX);
		hitbox.x = (int)(this->x);
		speedX = 0;
	}
	if (y){
		this->y += (speedY * deltaY);
		hitbox.y = (int)(this->y);
		speedY = 0;
	}
}
void Player::renderMe(){             /////
	render(texture, spriteRender);
	render(reticleTexture, spriteRender);
}
void Enemy::renderMe(){           
	render(texture, spriteRender);           
}
void Projectile::renderMe(){
	render(texture, spriteRender);          ////
}
void Enemy::update(){
/*  if (getInput()->one){			
		hitbox.x = getInput()->mx;	 
		hitbox.y = getInput()->my;	 
	}								 */
}
void Projectile::update(){
		this->x += speedX*2*globalSpeed;
		this->y += speedY*2*globalSpeed;
		if (this->x <= 100){
			delete this; //https://www.youtube.com/watch?v=N5TWbeav7hI
			dead = 1;
		}
		hitbox.x = (int)(this->x);
		hitbox.y = (int)(this->y);
}
void updateAll(std::vector<entity*>& entities){
	int size = entities.size();
	if (size > currEntityReserve)
	{
		currEntityReserve *= 2;
		entities.reserve(currEntityReserve);
		setColor(byellow);
		std::cout << "Warning: over " << currEntityReserve/2 << " entities\n";
		setColor();
	}
	for (int i = 0; i < size; ++i){
		entities[i]->update();
		if (entities[i]->dead){
			removeEntity(i);
		}
	}
}
void setGlobalSpeed(double speed){
	globalSpeed = speed;
}
