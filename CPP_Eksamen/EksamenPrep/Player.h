#pragma once
#include <SDL.h>
#define PLAYERPOSY 750;

class Player
{

public:
	Player();
	~Player();

	SDL_Texture* getPlayerTexture();
	int getPlayerCoords();

	void initPlayer();
private:
	int playerPosX;

	// Spaceship(player)
	SDL_Surface * m_playerBMP;
	SDL_Texture * m_player_drawable;
	SDL_Rect m_player_coords;
};

