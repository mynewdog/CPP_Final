#pragma once
#include <SDL.h>
#include <vector>

class Enemy
{
public:
	Enemy();
	Enemy(SDL_Renderer * renderer, int enemytype, int x, int y);
	~Enemy();

	SDL_Texture* getDrawable();
	SDL_Rect* getCoords();
	int getX();
	int getY();

	void moveX(int direction);
	void moveDown();

	void setDifficulty(int dif);
	int getDifficulty();

	void setX(int x);
	void setY(int y);

private:
	int difficulty = 1;
	SDL_Surface * m_enemy_BMP;
	SDL_Texture * m_enemy_drawable;
	SDL_Rect m_enemy_coords;
};

