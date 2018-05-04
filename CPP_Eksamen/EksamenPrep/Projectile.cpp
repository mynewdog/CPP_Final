#include "stdafx.h"
#include "Projectile.h"
#include <iostream>
#include <SDL.h>

void Projectile::spawn(SDL_Renderer* render, int spawnX, int spawnY) {
	projectile_BMP = SDL_LoadBMP("Img/playergun.bmp");
	projectile_drawable = SDL_CreateTextureFromSurface(render, projectile_BMP);
	projectile_coords.h = projectile_BMP->h;
	projectile_coords.w = projectile_BMP->w;
	projectile_coords.x = spawnX;
	projectile_coords.y = spawnY;
	SDL_FreeSurface(projectile_BMP);
	move();
}

SDL_Rect* Projectile::getCoords() {
	return &projectile_coords;
}

SDL_Texture* Projectile::getDrawable() {
	return projectile_drawable;
}

void Projectile::move() {
	if (projectile_coords.y >= -10) {
		projectile_coords.y -= 10;
	}
}

int Projectile::getX() {
	return getCoords()->x;
}

int Projectile::getY() {
	return getCoords()->y;
}

void Projectile::setX(int x) {
	projectile_coords.x = x;
}

void Projectile::setY(int y) {
	projectile_coords.y = y;
}

Projectile::Projectile()
{
}


Projectile::~Projectile()
{
}
