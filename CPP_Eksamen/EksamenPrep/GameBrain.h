#pragma once
#include <SDL.h>
#include "Projectile.h"
#include <vector>
#include "Enemy.h"
#include "Obstacle.h"
#include "EnemyProjectile.h"

#define PLAYERPOSY 750

class GameBrain {

public: 
	GameBrain();
	~GameBrain();
	
	void createWindow(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	void updateEnemyVectors();
	void enemyAI();
	void render();
	void handleEvents();
	void clean();
	void update();
	void init();
	void initObstacles();
	void drawGameScreen();
	void checkWin();
	void redrawEnemies();
	void checkCollision();
	void restart(int difficulty);
	void updateScore();
	void updateHighScore();
	void updateCursor();
	void redrawObstacles();

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

	// Howto screen
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

	std::vector<EnemyProjectile> enemyProjectiles;

	//Game over screen
	SDL_Surface * m_gameOverBMP;
	SDL_Texture * m_gameOver_drawable;
	SDL_Rect m_gameOver_coords;

	//Score on play screen
	SDL_Surface * m_score1;
	SDL_Texture * m_score1_drawable;
	SDL_Rect m_score1_coords;

	SDL_Surface * m_score2;
	SDL_Texture * m_score2_drawable;
	SDL_Rect m_score2_coords;

	SDL_Surface * m_score3;
	SDL_Texture * m_score3_drawable;
	SDL_Rect m_score3_coords;

	SDL_Surface * m_score4;
	SDL_Texture * m_score4_drawable;
	SDL_Rect m_score4_coords;

	SDL_Surface * m_score5;
	SDL_Texture * m_score5_drawable;
	SDL_Rect m_score5_coords;

	//////////////////////////
	//////////////////////////
	//////////////////////////

	//Highscore
	SDL_Surface * m_highscore1;
	SDL_Texture * m_highscore1_drawable;
	SDL_Rect m_highscore1_coords;

	SDL_Surface * m_highscore2;
	SDL_Texture * m_highscore2_drawable;
	SDL_Rect m_highscore2_coords;

	SDL_Surface * m_highscore3;
	SDL_Texture * m_highscore3_drawable;
	SDL_Rect m_highscore3_coords;

	SDL_Surface * m_highscore4;
	SDL_Texture * m_highscore4_drawable;
	SDL_Rect m_highscore4_coords;

	SDL_Surface * m_highscore5;
	SDL_Texture * m_highscore5_drawable;
	SDL_Rect m_highscore5_coords;

	std::vector<Obstacle> leftObst;
	std::vector<Obstacle> middleObst;
	std::vector<Obstacle> rightObst;

	int m_killCounter;
	int m_currentScore;
	int m_highScore;

	bool isRunning;
};