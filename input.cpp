#include <input.h>
#include <SDL.h>

void updateInput(input* inp, SDL_Event e){
	bool flag = (e.type == SDL_KEYDOWN ? 1 : 0);
	switch(e.key.keysym.sym){
		case SDLK_w:
		    inp->w = flag;
			break;
		case SDLK_a:
		    inp->a = flag;
			break;
		case SDLK_s:
		    inp->s = flag;
			break;
		case SDLK_d:
		    inp->d = flag;
			break;
	}
}