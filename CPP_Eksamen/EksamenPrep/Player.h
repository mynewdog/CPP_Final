#pragma once
#include <SDL.h>
#include <vector>
#include "Projectile.h"

class Player
{

public:
	Player();
	~Player();
	Projectile* getProjectile(int i);

	void movePlayer();
	void spawnPlayer(SDL_Renderer* render);
	void updatePos(int direction);
	void addBullets(Projectile *p);
	void removeBullet(int i);
	void setX(int x);
	void printBulletSize();
	
	int getX();
	int getY();

	SDL_Texture* getDrawable();
	SDL_Rect* getCoords();

	std::vector<Projectile*> getBullets();

private:
	int m_playerX;
	int m_playerY;
	std::vector<Projectile*> bullets;

	SDL_Surface * player_BMP;
	SDL_Texture * player_drawable;
	SDL_Rect player_coords;
};

