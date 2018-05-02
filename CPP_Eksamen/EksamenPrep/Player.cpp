#include "stdafx.h"
#include "Player.h"
#include <iostream>

SDL_Texture* Player::getPlayerTexture() {
	return m_player_drawable;
}
int Player::getPlayerCoords(){
	return m_player_coords.x;
}

void Player::initPlayer() {
	// Spaceship(Player)
	m_playerBMP = SDL_LoadBMP("Img/player.bmp");

	m_player_coords.h = m_playerBMP->h;
	m_player_coords.w = m_playerBMP->w;
	m_player_coords.x = 190;
	m_player_coords.y =	PLAYERPOSY;
}




Player::Player()
{
}
Player::~Player()
{
}
