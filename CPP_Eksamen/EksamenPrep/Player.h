#pragma once
#include <SDL.h>
#include <vector>
#include "Projectile.h"

class Player
{

public:
	Player();
	~Player();
	void movePlayer();
	void spawnPlayer(SDL_Renderer* render);
	void updatePos(int direction);
	std::vector<Projectile*> getBullets();
	void addBullets(Projectile *p);
	SDL_Texture* getDrawable();
	SDL_Rect* getCoords();

	int getX();
	int getY();

private:
	int m_playerX;
	int m_playerY;
	std::vector<Projectile*> bullets;

	SDL_Surface * player_BMP;
	SDL_Texture * player_drawable;
	SDL_Rect player_coords;
};

