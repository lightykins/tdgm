#include <iostream>
#include <windows.h>
#include <input.h>
#include "SDL.h"
enum color {blue = 1, green, cyan, red, purple, dyellow, white, gray, bblue, bcyan, bred, pink, yellow, bwhite};
void setColor(int color = white){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int main(int argc, char* argv[]){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
	    std::cout << SDL_GetError() << "\n";
	}
	setColor(green);
	std::cout << hello + "\n";
	setColor();
	std::cin.get(); 
	SDL_Quit();
	return 0;
}
