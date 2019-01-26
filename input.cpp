#include <input.h>										//мб сделать по сканкодам как в тееворлд но надо до конца разобраться

input inpp;
void updateInput(SDL_Event e){
	if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP){
	    bool flag = (e.type == SDL_KEYDOWN ? 1 : 0);
	    switch(e.key.keysym.sym){
	    	case SDLK_w:
		        inpp.w = flag;
		    	break;
		    case SDLK_a:
		        inpp.a = flag;
		    	break;
		    case SDLK_s:
		        inpp.s = flag;
			    break;
		    case SDLK_d:
		        inpp.d = flag;
			    break;
			case SDLK_1:
				inpp.one = flag;
				break;
		}
	}else
	{
	    if (e.type == SDL_MOUSEMOTION){
            SDL_GetMouseState(&(inpp.mx), &(inpp.my));
        }else
		{
			bool flag = (e.type == SDL_MOUSEBUTTONDOWN ? 1 : 0);
			switch(e.button.button){
				case SDL_BUTTON_LEFT:
				    inpp.m1 = flag;
					break;
				case SDL_BUTTON_RIGHT:
				    inpp.m2 = flag;
					break;
			}
		}
    }
}
input* getInput(){
	return &inpp;
}