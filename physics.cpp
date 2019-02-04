#include <SDL.h>
#include <entities.h>

bool rectColliding(SDL_Rect* one, SDL_Rect* two){
	return (one->x > two->x+two->w) && (one->x + one->w < two->x) &&
		   (one->y < two->y+two->h) && (one->y + one->h > two->y); 
}
entity* colliding(SDL_Rect* rect, unsigned int coltype){
	std::vector<entity*>& ents = getEntities();
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