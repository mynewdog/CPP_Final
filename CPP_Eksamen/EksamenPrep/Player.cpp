#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include <SDL.h>

#ifndef SCREEN_SIZE
#define SCREEN_SIZE 800
#endif


std::vector<Projectile*> *getBullets() {
	std::vector<Projectile*> tempBullets;
	for (int i = 0; i < bullets.size(); i++) {
	}
	return &tempBullets;
}
void addBullets(Projectile p) {
	bullets.push_back(p);
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
			player_coords.x = (player_coords.x - 6);
		}
		else if (direction == 1) {
			player_coords.x = (player_coords.x + 6);
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