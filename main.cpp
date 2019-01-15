#include <iostream>
#include <windows.h>
#include <input.h>
#include "SDL.h"
int SCREEN_HEIGHT = 480;
int SCREEN_WIDTH = 640;
SDL_Window* window = NULL;
enum color {blue = 1, green, cyan, red, purple, dyellow, white, gray, bblue, bcyan, bred, pink, yellow, bwhite};
void setColor(int color = white){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int main(int argc, char* argv[]){
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
	    setColor(red);
	    std::cout << SDL_GetError() << "\n";
	    setColor();
	    return 0;
	}else{
		window = SDL_CreateWindow( "cheto tam", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	}
	setColor(green);
	std::cout << hello + "\n\n\n";
	setColor();
    input inp;
	setColor((white << 4) + cyan);
	SDL_Event e;
	bool quit = 0;
	while (!quit){
		while(SDL_PollEvent(&e) != 0){
			if (e.type == SDL_QUIT){
				quit = 1;
				break;
			}else if ((e.type == SDL_KEYDOWN) || (e.type == SDL_KEYUP)){
				updateInput(&inp, e);
			}
		}
		std::cout << "w " << inp.w << " "
		          << "a " << inp.a << " "
				  << "s " << inp.s << " "
				  << "d " << inp.d << " "
				  << '\r' << std::flush;
	}
	SDL_Quit();
	return 0;
}