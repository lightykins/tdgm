#ifndef MAP_H
#define MAP_H

#include <SDL.h>
#include <SDL_image.h>

#include <string>
#include <map>
#include <vector>

class Map
{
	public:
	unsigned int width;
	unsigned int height;
	
	std::vector<Tile> tiles;
	
	unsigned int tileSize;
	
	void load(const std::string& filename, unsigned int height);
	
	void draw(SDL_Renderer& window, float dt);
}


#endif