#include <input.h>


void updateInput(input* inp, SDL_Event e){
	if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP){
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
	}else
	{
	    if (e.type == SDL_MOUSEMOTION){
            SDL_GetMouseState(&(inp->mx), &(inp->my));
        }else
		{
			bool flag = (e.type == SDL_MOUSEBUTTONDOWN ? 1 : 0);
			switch(e.button.button){
				case SDL_BUTTON_LEFT:
				    inp->m1 = flag;
				case SDL_BUTTON_RIGHT:
				    inp->m2 = flag;
			}
		}
    }
}