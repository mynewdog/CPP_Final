#include "stdafx.h"
#include "Projectile.h"
#include "GameBrain.h"
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
	while (projectile_coords.y > 0) {
		projectile_coords.y -= 5;
	}
	std::cout << m_projectileY << std::endl;
}

Projectile::Projectile()
{
}


Projectile::~Projectile()
{
}
