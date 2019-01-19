#include <entities.h>
#include <input.h>
#include <iostream>
typedef void (*func)(void);
Player::Player(){
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
		speedY = getInput()->w ? -1 : 1;
	}
	if (getInput()->d && getInput()->a || (!getInput()->d && !getInput()->a)){
		speedX = 0;
	}else if (getInput()->d || getInput()->a)
	{
		speedX = getInput()->a ? -1 : 1;
	}
	hitbox.x += speedX;
	hitbox.y += speedY;
}
void Projectile::update(){

}
void updateAll(std::vector<entity>& entities){
	for (int i = 0; i < entities.size(); ++i){
		switch(entities[i].second){
			case player:
				((Player*)(entities[i].first))->update();
				break;
			/*case enemy:
				((Enemy*)(entities[i].first))->update();
				break;*/
			case projectile:
				((Projectile*)(entities[i].first))->update();
				break;
		}
	}
}