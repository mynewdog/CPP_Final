#pragma once
#include <SDL.h>
#include <vector>

class Obstacle
{
public:
	Obstacle();
	Obstacle(SDL_Renderer * renderer, int placement, int x, int y);
	~Obstacle();

	SDL_Texture* getDrawable();
	SDL_Rect* getCoords();

	int getX();
	int getY();
	void setX(int x);
	void setY(int y);

private:
	SDL_Surface * m_obstacle_BMP;
	SDL_Texture * m_obstacle_drawable;
	SDL_Rect m_obstacle_coords;
};

