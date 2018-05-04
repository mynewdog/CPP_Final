#include "Player.h"
#include <SDL.h>

#ifndef SCREEN_SIZE
#define SCREEN_SIZE 800
#endif

Projectile* Player::getProjectile(int i) {
	return bullets[i];
}

std::vector<Projectile*> Player::getBullets(){
	return bullets;
}

void Player::addBullets(Projectile *p) {
	bullets.push_back(p);
}

void Player::removeBullet(int i) {
	bullets.erase(bullets.begin() + i);
	bullets.shrink_to_fit();
}

void Player::setX(int x) {
	player_coords.x = x;
}

void Player::spawnPlayer(SDL_Renderer* render) {
	player_BMP = SDL_LoadBMP("Img/player.bmp");
	player_drawable = SDL_CreateTextureFromSurface(render, player_BMP);
	player_coords.h = player_BMP->h;
	player_coords.w = player_BMP->w;
	player_coords.x = (SCREEN_SIZE - 54) / 2;
	player_coords.y = (SCREEN_SIZE - 100);
	SDL_FreeSurface(player_BMP);
}

void Player::updatePos(int direction) {
	if (player_coords.x >= 0 && player_coords.x <= (800 - 54)) {
		if (direction == 0) {
			player_coords.x = (player_coords.x - 12);
		}
		else if (direction == 1) {
			player_coords.x = (player_coords.x + 12);
		}
	}

	if (player_coords.x < 0) { player_coords.x = 0; }
	if (player_coords.x >(SCREEN_SIZE - 54)) {
		player_coords.x = (SCREEN_SIZE - 54);
	}
}
SDL_Rect* Player::getCoords() {
	return &player_coords;
}

int Player::getX(){
	return player_coords.x + 25;
}
int Player::getY() {
	return player_coords.y;
}

SDL_Texture* Player::getDrawable() {
	return player_drawable;
}

void Player::movePlayer() {
	if (player_coords.y >= -10) {
		player_coords.y -= 5;
	}
}


Player::Player()
{
}
Player::~Player()
{
}