#pragma once
#include <SDL.h>
#define PLAYERPOSY 750
#include <vector>
class GameBrain {

public: 
	GameBrain();
	~GameBrain();
	
	void createWindow(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	void updateEnemyVectors();
	void updatePos(int direction);
	void render();
	void handleEvents();
	void clean();
	void update();
	void initImages();
	void drawGameScreen();

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

	// Spaceship(player)
	SDL_Surface * m_playerBMP;
	SDL_Texture * m_player_drawable;
	SDL_Rect m_player_coords;

	// Enemy type 1
	SDL_Surface * m_enemy1_BMP;
	SDL_Texture * m_enemy1_drawable;
	SDL_Rect m_enemy1_coords;
	std::vector<SDL_Rect> m_arr_enemy1_coords;

	bool isRunning;
};