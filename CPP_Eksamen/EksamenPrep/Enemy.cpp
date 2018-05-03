#include "Enemy.h"
#include <string.h>

SDL_Texture * Enemy::getDrawable() {
	return m_enemy_drawable;
}

SDL_Rect* Enemy::getCoords() {
	return &m_enemy_coords;
}

int Enemy::getX() {
	return m_enemy_coords.x;
}

int Enemy::getY() {
	return m_enemy_coords.y;
}

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
}
// Renderer, 1-5 enemytype, pos X, pos Y
Enemy::Enemy(SDL_Renderer * renderer, int enemytype, int x, int y) {
	const char * path;
	if (enemytype == 1) {
		path = "Img/enemy_1.bmp";
	}
	else if (enemytype == 2) {
		path = "Img/enemy_2.bmp";
	}
	else if (enemytype == 3) {
		path = "Img/enemy_3.bmp";
	}
	else if (enemytype == 4) {
		path = "Img/enemy_4.bmp";
	}
	else {
		path = "Img/enemy_5.bmp";
	}

	m_enemy_BMP = SDL_LoadBMP(path);
	m_enemy_drawable = SDL_CreateTextureFromSurface(renderer, m_enemy_BMP);
	m_enemy_coords.h = m_enemy_BMP->h;
	m_enemy_coords.w = m_enemy_BMP->w;
	m_enemy_coords.x = x;
	m_enemy_coords.y = y;
	SDL_FreeSurface(m_enemy_BMP);
}