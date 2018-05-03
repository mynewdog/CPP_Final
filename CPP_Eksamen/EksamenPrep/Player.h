#pragma once
#include <SDL.h>

class Player
{

public:
	Player();
	~Player();

	void updatePos(SDL_Rect coords, int direction);
private:
};

