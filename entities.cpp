#include <entities.h>
#include <iostream>

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
	hitbox.x += speedX;
	hitbox.y += speedY;
}