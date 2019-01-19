#ifndef GRAPHICS_INCLUDED
#define GRAPHICS_INCLUDED

#include <vector>
#include <SDL.h>
#include <string>

enum {rectangleRender, spriteRender};
enum {playerTex, enemyTex, projectileTex, ALWAYS_LAST};
struct color{
	int r = 0;
	int g = 0;
	int b = 0;
	int a = 255;
};
void render(void* pt, SDL_Renderer* renderer, color Color, int type);
void renderAll(SDL_Renderer* renderer, const std::vector<std::pair<void*, int>>&);
SDL_Texture* loadFromFile(std::string path);
void initTextures(SDL_Renderer* renderer);
SDL_Texture* getTexture(int type);
#endif