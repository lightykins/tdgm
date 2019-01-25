#include <iostream>			//commit test
#include <vector>
#include <windows.h>
#include <string>
#include "SDL.h"
#include <input.h>
#include <graphics.h>
#include <entities.h>

int SCREEN_HEIGHT = 480;
int SCREEN_WIDTH = 640;

SDL_Window* window = NULL;
SDL_Renderer* renderer;
enum colors {blue = 1, green, cyan, red, purple, dyellow, white, gray, bblue, bcyan, bred, pink, yellow, bwhite};
void setColor(int color = white){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
bool updateEvts(){
	static SDL_Event e;
	while(SDL_PollEvent(&e) != 0){
		if (e.type == SDL_QUIT){
			return 1;
		}else if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP || e.type == SDL_MOUSEMOTION 
			      || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP){
			updateInput(e);
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
	std::vector<entity> entities;
	initTextures(renderer);
	SDL_Rect reticlebox; reticlebox.w = 30; reticlebox.h = 30;
	Texture reticle; reticle.first = getTexture(reticleTex); reticle.second = &reticlebox;
	entities.push_back({new Player, player});
	entities.push_back({&reticle, tex});
	while (!quit){
		quit = updateEvts();
		updateAll(entities);
		reticle.second->x = getInput()->mx - reticlebox.w/2; reticle.second->y = getInput()->my - reticlebox.h/2;
		unsigned int before = SDL_GetTicks();
		renderAll(renderer, entities);
		unsigned int diff = SDL_GetTicks() - before;
		if (diff < 1000/120) {SDL_Delay(1000/120 - diff);}
		else {setGlobalSpeed(diff / (1000/120));}
		std::cout	<< "w " << getInput()->w << " "
					<< "a " << getInput()->a << " "
					<< "s " << getInput()->s << " "
					<< "d " << getInput()->d << " "
					<< '\r' << std::flush;
	}
	SDL_Quit();
	return 0;
}