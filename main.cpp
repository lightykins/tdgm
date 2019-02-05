#include <iostream>			//commit test
#include <vector>
#include <windows.h>
#include <string>
#include "SDL.h"
#include <input.h>
#include <entities.h>
#include <graphics.h>
#include <physics.h>

int SCREEN_HEIGHT = 480;
int SCREEN_WIDTH = 640;

SDL_Window* window = NULL;
SDL_Renderer* renderer;
InputManager inputmg;
EntityManager entitymg;
GraphicsManager graphicsmg;
AllManager allmg;

bool updateEvts(){
	static SDL_Event e;
	while(SDL_PollEvent(&e) != 0){
		if (e.type == SDL_QUIT){
			return 1;
		}else if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP || e.type == SDL_MOUSEMOTION 
			      || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP){
			inputmg.updateInput(e);
		}
	}	
	return 0;
}
bool init(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
	    setColor(red);
	    std::cout << SDL_GetError() << "\n";
	    setColor();
	    return 0;
	}else{
		window = SDL_CreateWindow( "cheto tam", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	}
	return 1;
}
int main(int argc, char* argv[]){
	if (!init()) return 0;
	setColor(green);
	std::cout << "\n\n\n" + hello + "\n\n\n";
	setColor((white << 4) + cyan);
	bool quit = 0;
	std::vector<entity*>& entities = getEntities();
	initTextures(renderer);
	entitymg.inputData = inputmg.getInput();
	entitymg.graphicsmg = graphicsmg;
	entitymg.getEntites().push_back(new Player);
		while (!quit){
			unsigned int before = SDL_GetTicks();
		
			quit = updateEvts(); //and input
			entitymg.updateEntities();
			entitymg.renderEntities();
		
			unsigned int diff = SDL_GetTicks() - before;
			if (diff < 1000/120) {SDL_Delay(1000/120 - diff); setGlobalSpeed(1);}
			else {setGlobalSpeed((double)diff / (((double)1000)/120));}
		}
	SDL_Quit();
	return 0;
}