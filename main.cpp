#include <iostream>
#include <windows.h>
#include <input.h>
#include <graphics.h>
#include "SDL.h"
int SCREEN_HEIGHT = 480;
int SCREEN_WIDTH = 640;

input inpp;
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
			updateInput(&inpp, e);
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
	SDL_Rect rect;
	rect.x = 50; rect.y = 50; rect.w = 50; rect.h = 50;
	color Color; Color.b = 255;
	while (!quit){
		quit = updateEvts();
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		render(&rect, renderer, Color, rectangle);
		SDL_RenderPresent(renderer);
		std::cout << "w " << inpp.w << " "
		          << "a " << inpp.a << " "
				  << "s " << inpp.s << " "
				  << "d " << inpp.d << " "
				  << '\r' << std::flush;
	}
	SDL_Quit();
	return 0;
}