enum {rectangle, sprite};
struct color{
	int r = 0;
	int g = 0;
	int b = 0;
	int a = 255;
};
void render(void* pt, SDL_Renderer* renderer, color Color, int type);