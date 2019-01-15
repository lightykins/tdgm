#include <SDL.h>
#include <string>

const std::string hello = "hello world";
struct input 
{
	bool w = 0;
	bool a = 0;
	bool s = 0;
	bool d = 0;
	bool m1 = 0;
	bool m2 = 0;
	bool mx = 0;
	bool my = 0;
};
void updateInput(input* inp, SDL_Event e);