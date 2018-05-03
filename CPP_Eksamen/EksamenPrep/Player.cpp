#include "stdafx.h"
#include "Player.h"
#include <SDL.h>

#ifndef SCREEN_SIZE
#define SCREEN_SIZE 800

// Direction 0 = LEFT | 1 = RIGHT
void Player::updatePos(SDL_Rect coords, int direction) {
	if (coords.x > 0 && coords.x < (800 - 64)) {
		// Update
		if (direction == 0) {
			coords.x = (coords.x - 10);
		}
		else if (direction == 1) {
			coords.x = (coords.x + 10);
		}
	}

	if (coords.x < 0) { coords.x = 0; }
	if (coords.x > (SCREEN_SIZE - 64)) { coords.x = (SCREEN_SIZE - 64); }
}

Player::Player()
{
}
Player::~Player()
{
}
