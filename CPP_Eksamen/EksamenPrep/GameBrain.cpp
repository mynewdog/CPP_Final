#include "stdafx.h"
#include "GameBrain.h"
#include <iostream>
#include <SDL.h>
#include "Player.h"

#ifndef SCREEN_SIZE
#define SCREEN_SIZE 800
#endif

void GameBrain::createWindow(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		m_gameWindow = SDL_CreateWindow(title, xPos, yPos, width, height, fullscreen);
		if (m_gameWindow) {
			std::cout << "Window Created " << std::endl;
		}

		m_gameRenderer = SDL_CreateRenderer(m_gameWindow, -1, 0);
		if (m_gameRenderer) {
			SDL_SetRenderDrawColor(m_gameRenderer, 0, 0, 0, 255);
			std::cout << "Renderer Created" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}
}
void GameBrain::updateEnemyVectors() {
	// Dir 0 = LEFT | 1 = RIGHT
	int direction = 1;
	if (m_arr_enemy1_coords.front().x >= 0 && m_arr_enemy1_coords.back().x <= (SCREEN_SIZE - 48)) {
		for (int i = 0; i < m_arr_enemy1_coords.size(); i++) {
			
			// Check if hit left wall
			if (direction == 0) {
				if (m_arr_enemy1_coords.front().x < 5) {
					m_arr_enemy1_coords[i].x -= m_arr_enemy1_coords.front().x;
				}
				else {
					m_arr_enemy1_coords[i].x -= 5;
				}
				
			}

			// Check if hit right wall
			else if (direction == 1) {
				if ((SCREEN_SIZE - m_arr_enemy1_coords.back().x - 48) < 5) {
					m_arr_enemy1_coords[i].x += (SCREEN_SIZE - 48 - m_arr_enemy1_coords.back().x);
					std::cout << m_arr_enemy1_coords.back().x << "px" << std::endl;
				}
				else {
					m_arr_enemy1_coords[i].x += 5;
				}
				
			}
			
		}
	}

	// If hit right wall
	if (m_arr_enemy1_coords.back().x >= (SCREEN_SIZE - 48)) {
		direction = 0;
		std::cout << direction << std::endl;
	}
	// If hit left wall
	if (m_arr_enemy1_coords.front().x <= 0) {
		direction = 1;
		std::cout << direction << std::endl;
	}
	
}

void GameBrain::initImages() {
	// Main Menu Background
	m_mainMenuBMP = SDL_LoadBMP("Img/mainmenu.bmp");
	m_menu_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_mainMenuBMP);
	m_menu_coords.h = m_mainMenuBMP->h;
	m_menu_coords.w = m_mainMenuBMP->w;
	m_menu_coords.x = 225;
	m_menu_coords.y = 300;
	SDL_FreeSurface(m_mainMenuBMP);

	// Cursor
	m_cursorBMP = SDL_LoadBMP("Img/selectarrow.bmp");
	m_cursor_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_cursorBMP);
	m_cursor_coords.h = m_cursorBMP->h;
	m_cursor_coords.w = m_cursorBMP->w;
	m_cursor_coords.x = 190;
	m_cursor_coords.y = 305;
	SDL_FreeSurface(m_cursorBMP);

	// Back button
	m_backBMP = SDL_LoadBMP("Img/goback.bmp");
	
	m_back_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_backBMP);
	m_back_coords.h = m_backBMP->h;
	m_back_coords.w = m_backBMP->w;
	m_back_coords.x = 225;
	m_back_coords.y = 700;
	SDL_FreeSurface(m_backBMP);

	// Game background
	m_gameBG_BMP = SDL_LoadBMP("Img/gameBG.bmp");
	m_gameBG_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_gameBG_BMP);
	m_gameBG_coords.h = m_gameBG_BMP->h;
	m_gameBG_coords.w = m_gameBG_BMP->w;
	m_gameBG_coords.x = 0;
	m_gameBG_coords.y = 0;
	SDL_FreeSurface(m_gameBG_BMP);

	// Spaceship(Player)
	m_playerBMP = SDL_LoadBMP("Img/player.bmp");
	m_player_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_playerBMP);
	m_player_coords.h = m_playerBMP->h;
	m_player_coords.w = m_playerBMP->w;
	m_player_coords.x = (SCREEN_SIZE - 54) / 2;
	m_player_coords.y = (SCREEN_SIZE - 100);
	SDL_FreeSurface(m_playerBMP);

	// Enemy type 1
	m_enemy1_BMP = SDL_LoadBMP("Img/enemy_1.bmp");
	m_enemy1_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_enemy1_BMP);
	m_enemy1_coords.h = m_enemy1_BMP->h;
	m_enemy1_coords.w = m_enemy1_BMP->w;
	m_enemy1_coords.x = 45;
	m_enemy1_coords.y = (SCREEN_SIZE - 400);

	for (int i = 0; i < 11; i++) {
		m_arr_enemy1_coords.push_back(m_enemy1_coords);
		if (i > 0) {
			m_arr_enemy1_coords[i].x = (m_arr_enemy1_coords[i - 1].x + 60);
		}
	}

	SDL_FreeSurface(m_enemy1_BMP);
}
	

void GameBrain::updateCursor() {
	if (m_menuChoice == 0) {
		m_cursor_coords.x = 190;
		m_cursor_coords.y = 305;
	}
	else if (m_menuChoice == 1) {
		m_cursor_coords.x = 240;
		m_cursor_coords.y = 387;
	}
	else if (m_menuChoice == 2) {
		m_cursor_coords.x = 288;
		m_cursor_coords.y = 472;
	}
}

void GameBrain::update() {

}
void GameBrain::updatePos(int direction) {
	if (m_player_coords.x >= 0 && m_player_coords.x <= (800 - 54)) {
		if (direction == 0) {
			m_player_coords.x = (m_player_coords.x - 6);
		}
		else if (direction == 1) {
			m_player_coords.x = (m_player_coords.x + 6);
		}
	}

	if (m_player_coords.x < 0) { m_player_coords.x = 0; }
	if (m_player_coords.x > (SCREEN_SIZE - 54)) {
		m_player_coords.x = (SCREEN_SIZE - 54);
	}
}
void GameBrain::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;

	}

	// Check main menu cursor select
	if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_LEFT && m_screen == 2) {
				updatePos(0);
			}
			else if (event.key.keysym.sym == SDLK_RIGHT && m_screen == 2) {
				updatePos(1);
			}

			// Pressed down arrow
			if (event.key.keysym.sym == SDLK_DOWN) {
				m_menuChoice++;
				if (m_menuChoice == 3) { m_menuChoice = 0;  }
				updateCursor();
				std::cout << "Pressed down " << m_menuChoice << std::endl;
			}

			// Pressed up arrow
			if (event.key.keysym.sym == SDLK_UP) {
				m_menuChoice--;
				if (m_menuChoice == -1) { m_menuChoice = 2;  }
				updateCursor();
				std::cout << "Pressed up " << m_menuChoice << std::endl;
			}

			// Pressed enter
			if (event.key.keysym.sym == SDLK_RETURN) {
				std::cout << "Enter: " << m_menuChoice << std::endl;
				// Change to game screen
				if (m_menuChoice == 0 && m_screen == 0) {
					m_screen = 2;
				}


				// Change to how to screen
				if (m_menuChoice == 1 && m_screen == 0) {
					m_screen = 1;
				}
				else if (m_screen == 1) {
					m_screen = 0;
				}

				// Exit 
				else if (m_menuChoice == 2) {
					isRunning = false;
					exit(EXIT_SUCCESS);
				}	
		}
	}

}
void GameBrain::drawGameScreen() {
	SDL_RenderCopy(m_gameRenderer, m_gameBG_drawable, nullptr, &m_gameBG_coords);
}


void GameBrain::render() {
	// Clear last frame
	SDL_RenderClear(m_gameRenderer);

	// Update if on main menu
	if (m_screen == 0) {
		SDL_RenderCopy(m_gameRenderer, m_menu_drawable, nullptr, &m_menu_coords);
		SDL_RenderCopy(m_gameRenderer, m_cursor_drawable, nullptr, &m_cursor_coords);
	}

	// Update if on how to screen
	else if (m_screen == 1) {
		SDL_RenderCopy(m_gameRenderer, m_back_drawable, nullptr, &m_back_coords);
	}
	
	// Update if playing game
	else if (m_screen == 2) {
		drawGameScreen();
		SDL_RenderCopy(m_gameRenderer, m_player_drawable, nullptr, &m_player_coords);
		for (int i = 0; i < 11; i++) {
			SDL_RenderCopy(m_gameRenderer, m_enemy1_drawable, nullptr, &m_arr_enemy1_coords[i]);
		}

		updateEnemyVectors();
	}

	// Update this frame
	SDL_RenderPresent(m_gameRenderer);
}

bool GameBrain::running() {
	return isRunning;
}

void GameBrain::clean() {
	SDL_DestroyWindow(m_gameWindow);
	SDL_DestroyRenderer(m_gameRenderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

GameBrain::GameBrain() {

}

GameBrain::~GameBrain() {

}