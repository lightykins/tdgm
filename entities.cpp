#include <entities.h>
#include <input.h>
#include <math.h>
#include <iostream>
typedef void (*func)(void);
unsigned int globalSpeed = 1;
Player::Player(){
	hitbox.x = 100;
	hitbox.y = 100;
	hitbox.w = 50;
	hitbox.h = 50;
}
Enemy::Enemy(){
	hitbox.x = 100;
	hitbox.y = 100;
	hitbox.w = 50;
	hitbox.h = 50;
}
void Player::update(){
	if (!this->hp){
		std::cout << "You fucked up\n";
	}
	if ((getInput()->w && getInput()->s) || (!getInput()->w && !getInput()->s)){
		speedY = 0;
	}else if (getInput()->w || getInput()->s)
	{
		speedY = (getInput()->w ? -1 : 1)*moveSpeedY*globalSpeed;
	}
	if (getInput()->d && getInput()->a || (!getInput()->d && !getInput()->a)){
		speedX = 0;
	}else if (getInput()->d || getInput()->a)
	{
		speedX = (getInput()->a ? -1 : 1)*moveSpeedY*globalSpeed;
	}
	//normalise(&speedX, &speedY);
	hitbox.x += speedX;
	hitbox.y += speedY;
	speedX = 0;
	speedY = 0;
}

void Enemy::update(){
	if (getInput()->one){
		hitbox.x = getInput()->mx;
		hitbox.y = getInput()->my;
	}
}
void Projectile::update(){

}
void updateAll(std::vector<entity>& entities){
	for (int i = 0; i < entities.size(); ++i){
		switch(entities[i].second){
			case player:
				((Player*)(entities[i].first))->update();
				break;
			case enemy:
				((Enemy*)(entities[i].first))->update();
				break;
			case projectile:
				((Projectile*)(entities[i].first))->update();
				break;
		}
	}
	if (getInput()->one){
		entities.push_back({new Enemy, enemy});   //если зажать двигаецо
    }
}
void setGlobalSpeed(unsigned int speed){
	globalSpeed = speed;
}