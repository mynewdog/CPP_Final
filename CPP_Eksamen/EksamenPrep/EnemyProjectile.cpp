#include "stdafx.h"
#include "EnemyProjectile.h"
#include <iostream>
#include <SDL.h>

void EnemyProjectile::spawn(SDL_Renderer* render, int spawnX, int spawnY) {
	enemyprojectile_BMP = SDL_LoadBMP("Img/playergun.bmp");
	enemyprojectile_drawable = SDL_CreateTextureFromSurface(render, enemyprojectile_BMP);
	enemyprojectile_coords.h = enemyprojectile_BMP->h;
	enemyprojectile_coords.w = enemyprojectile_BMP->w;
	enemyprojectile_coords.x = spawnX;
	enemyprojectile_coords.y = spawnY;
	SDL_FreeSurface(enemyprojectile_BMP);
	move();
}

void EnemyProjectile::move() {
	if (enemyprojectile_coords.y <800) {
		enemyprojectile_coords.y += 2;
	}
}

SDL_Rect* EnemyProjectile::getCoords() {
	return &enemyprojectile_coords;
}

SDL_Texture* EnemyProjectile::getDrawable() {
	return enemyprojectile_drawable;
}

int EnemyProjectile::getX() {
	return getCoords()->x;
}

int EnemyProjectile::getY() {
	return getCoords()->y;
}

void EnemyProjectile::setX(int x) {
	enemyprojectile_coords.x = x;
}

void EnemyProjectile::setY(int y) {
	enemyprojectile_coords.y = y;
}


EnemyProjectile::EnemyProjectile(SDL_Renderer* render, int spawnX, int spawnY)
{
	enemyprojectile_BMP = SDL_LoadBMP("Img/playergun.bmp");
	enemyprojectile_drawable = SDL_CreateTextureFromSurface(render, enemyprojectile_BMP);
	enemyprojectile_coords.h = enemyprojectile_BMP->h;
	enemyprojectile_coords.w = enemyprojectile_BMP->w;
	enemyprojectile_coords.x = spawnX;
	enemyprojectile_coords.y = spawnY;
	SDL_FreeSurface(enemyprojectile_BMP);
}
EnemyProjectile::EnemyProjectile()
{
}


EnemyProjectile::~EnemyProjectile()
{
}
