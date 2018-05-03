#pragma once
#include <SDL.h>
class Projectile
{
public:
	Projectile();
	~Projectile();
	void move();
	void spawn(SDL_Renderer* render, int spawnX, int spawnY);
	SDL_Texture* getDrawable();
	SDL_Rect* getCoords();

private:
	int m_projectileX;
	int m_projectileY;

	SDL_Surface * projectile_BMP;
	SDL_Texture * projectile_drawable;
	SDL_Rect projectile_coords;
};

