#ifndef INPUT_INCLUDED
#define INPUT_INCLUDED

#include <SDL.h>
#include <string>

const std::string hello = "hello world";
struct input 
{
	bool one = 0;
	bool w = 0;
	bool a = 0;
	bool s = 0;
	bool d = 0;
	bool m1 = 0;
	bool m2 = 0;
	int mx = 0;
	int my = 0;
};
class InputManager{
	public:
		input* getInput();
		void updateInput(SDL_Event e);
	private:
		input inpp;
};

#endif