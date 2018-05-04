#include "Obstacle.h"
#include <iostream>

SDL_Texture * Obstacle::getDrawable() {
	return m_obstacle_drawable;
}

SDL_Rect* Obstacle::getCoords() {
	return &m_obstacle_coords;
}

int Obstacle::getX() {
	return m_obstacle_coords.x;
}

int Obstacle::getY() {
	return m_obstacle_coords.y;
}

void Obstacle::setX(int x) {
	m_obstacle_coords.x = x;
}

void Obstacle::setY(int y) {
	m_obstacle_coords.y = y;
}

void Obstacle::init(SDL_Renderer* renderer, int placement, int x, int y) 
{
	m_obstacle_BMP = SDL_LoadBMP("Img/obstacle/1.bmp");
	m_obstacle_drawable = SDL_CreateTextureFromSurface(renderer, m_obstacle_BMP);
	m_obstacle_coords.h = m_obstacle_BMP->h;
	m_obstacle_coords.w = m_obstacle_BMP->w;
	m_obstacle_coords.x = x;
	m_obstacle_coords.y = y;
	SDL_FreeSurface(m_obstacle_BMP);
}

Obstacle::Obstacle()
{
}


Obstacle::~Obstacle()
{
}
