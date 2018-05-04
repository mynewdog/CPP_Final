#pragma once
#include <SDL.h>

class EnemyProjectile
{
public:
	EnemyProjectile(SDL_Renderer* render, int spawnX, int spawnY);
	EnemyProjectile();
	~EnemyProjectile();
	void move();
	void spawn(SDL_Renderer* render, int spawnX, int spawnY);
	SDL_Texture* getDrawable();
	SDL_Rect* getCoords();

	void setX(int x);
	void setY(int y);
	int getX();
	int getY();

private:
	int m_projectileX;
	int m_projectileY;

	SDL_Surface * enemyprojectile_BMP;
	SDL_Texture * enemyprojectile_drawable;
	SDL_Rect enemyprojectile_coords;
};

