#pragma once
#include <SDL.h>
#include "Projectile.h"
#include <vector>
#include "Enemy.h"

#define PLAYERPOSY 750

class GameBrain {

public: 
	GameBrain();
	~GameBrain();
	
	void createWindow(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	void updateEnemyVectors(std::vector<SDL_Rect> arr);
	void render();
	void handleEvents();
	void clean();
	void update();
	void init();
	void drawGameScreen();

	int checkCollision();

	void updateCursor();
	bool running();

private:
	int m_menuChoice = 0;
	int m_screen = 0;

	SDL_Window * m_gameWindow;
	SDL_Renderer * m_gameRenderer;

	// Menu Drawable
	
	SDL_Surface * m_mainMenuBMP;
	SDL_Texture * m_menu_drawable;
	SDL_Rect m_menu_coords;

	// Cursor Drawable
	SDL_Surface * m_cursorBMP;
	SDL_Texture * m_cursor_drawable;
	SDL_Rect m_cursor_coords;

	// Back Button
	SDL_Surface * m_backBMP;
	SDL_Texture * m_back_drawable;
	SDL_Rect m_back_coords;

	//Game Background
	SDL_Surface * m_gameBG_BMP;
	SDL_Texture * m_gameBG_drawable;
	SDL_Rect m_gameBG_coords;

	// Game logo
	SDL_Surface * m_logoBMP;
	SDL_Texture * m_logo_drawable;
	SDL_Rect m_logo_coords;

	// Spaceship(player)
	SDL_Surface * m_playerBMP;
	SDL_Texture * m_player_drawable;
	SDL_Rect m_player_coords;

	std::vector<Enemy> enemy1;
	std::vector<Enemy> enemy2;
	std::vector<Enemy> enemy3;
	std::vector<Enemy> enemy4;
	std::vector<Enemy> enemy5;

	/*
	// Enemy type 1
	SDL_Surface * m_enemy1_BMP;
	SDL_Texture * m_enemy1_drawable;
	SDL_Rect m_enemy1_coords;
	std::vector<SDL_Rect> m_arr_enemy1_coords;

	// Enemy type 2
	SDL_Surface * m_enemy2_BMP;
	SDL_Texture * m_enemy2_drawable;
	SDL_Rect m_enemy2_coords;
	std::vector<SDL_Rect> m_arr_enemy2_coords;

	// Enemy type 3
	SDL_Surface * m_enemy3_BMP;
	SDL_Texture * m_enemy3_drawable;
	SDL_Rect m_enemy3_coords;
	std::vector<SDL_Rect> m_arr_enemy3_coords;

	// Enemy type 4
	SDL_Surface * m_enemy4_BMP;
	SDL_Texture * m_enemy4_drawable;
	SDL_Rect m_enemy4_coords;
	std::vector<SDL_Rect> m_arr_enemy4_coords;

	// Enemy type 5
	SDL_Surface * m_enemy5_BMP;
	SDL_Texture * m_enemy5_drawable;
	SDL_Rect m_enemy5_coords;
	std::vector<SDL_Rect> m_arr_enemy5_coords;
	*/
	bool isRunning;
};