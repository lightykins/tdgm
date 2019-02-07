#include <SDL.h>
#include <entities.h>
#include <managers.h>

bool rectColliding(SDL_Rect* one, SDL_Rect* two){
	int ox1 = one->x;
	int ox2 = one->x + one->w;
	int oy1 = one->y;
	int oy2 = one->y + one->h;
	
	int tx1 = two->x;
	int tx2 = two->x + two->w;
	int ty1 = two->y;
	int ty2 = two->y + two->h;	
	return (ox1 < tx2 && ox2 > tx1 && oy1 < ty2 && oy2 > ty1);
}
entity* colliding(SDL_Rect* rect, unsigned int coltype){
	std::vector<entity*>& ents = Entities->getEntities();
	for (int i = 0; i < ents.size(); ++i){
		//if (ents[i]->type == enemy){
		//	std::cout << ents[i]->collideMask;
		//	std::cout << "\n" << ((1 << player) | (1 << projectile));
        //  }
		if ((coltype & (ents[i]->collideMask))){
			//std::cout << "podhodit";
			if (rectColliding(rect, &(ents[i]->hitbox))){
				return ents[i];
			}
		}
	}
	return NULL;
}