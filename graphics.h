#ifndef GRAPHICS_INCLUDED
#define GRAPHICS_INCLUDED

#include <vector>
#include <SDL.h>
#include <string>

enum {rectangleRender, spriteRender};
enum {playerTex, enemyTex, projectileTex, reticleTex, ALWAYS_LAST};
typedef std::pair<SDL_Texture*, SDL_Rect*> Texture;
struct color{
	int r = 0;
	int g = 0;
	int b = 0;
	int a = 255;
};
enum colors {black, blue, green, cyan, red, purple, yellow, white, gray, bblue, bgreen, bcyan, bred, bpurple, byellow, bwhite};
void setColor(int color = white);
void render(void* pt, SDL_Renderer* renderer, color Color, int type);
void renderAll(SDL_Renderer* renderer, const std::vector<std::pair<void*, int>>&);
SDL_Texture* loadFromFile(std::string path);
void initTextures(SDL_Renderer* renderer);
SDL_Texture* getTexture(int type);
#endif