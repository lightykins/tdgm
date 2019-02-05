#ifndef TILE_H
#define TILE_H

#include <SDL.h>
#include <SDL_image.h>

class Tile
{

	public:

	TileType tileType;

	Tile(){}
			
	Tile(const unsigned int tileSize, 	Texture txt)

	 void draw(SDL_Renderer& window, float dt);




}

#endif