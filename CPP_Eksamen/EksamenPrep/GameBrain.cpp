#include "stdafx.h"
#include "GameBrain.h"
#include <iostream>
#include <SDL.h>
#include "Projectile.h"
#include "Player.h"

#ifndef SCREEN_SIZE
#define SCREEN_SIZE 800
#endif
// Dir 0 = LEFT | 1 = RIGHT
int direction = 1;
Player *p1 = new Player();

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
/*
void GameBrain::updateEnemyVectors(std::vector<SDL_Rect> arr) {
	// Check right
	if (arr.back().x >= (SCREEN_SIZE - 48)) {
		if (arr[0].y <= 660) {
			for (int i = 0; i < arr.size(); i++) {
				arr[i].y += 48;
			}
		}
		
		direction = 0;
	}
	else if (arr.front().x <= 0) {
		if (arr[0].y <= 660) {
			for (int i = 0; i < arr.size(); i++) {
				arr[i].y += 48;
			}
		}
		direction = 1;

	}

	if (direction == 1) {
		for (int i = 0; i < arr.size(); i++) {
			arr[i].x += 1;
		}
	}
	else if (direction == 0) {
		for (int i = 0; i < arr.size(); i++) {
			arr[i].x -= 1;
		}
	}
	
}
*/
void GameBrain::updateEnemyVectors() {
	
	// Vector 1
	if (enemy1.front().getX() <= 0) {
		if (enemy1[0].getY() <= 600) {
			for (int i = 0; i < enemy1.size(); i++) {
				enemy1[i].moveDown();
			}
		}
		direction = 1;
	}
	else if (enemy1.back().getX() >= (SCREEN_SIZE - 48)) {
			for (int i = 0; i < enemy1.size(); i++) {
				enemy1[i].moveDown();
			}
		direction = 0;
	}

	if (direction == 0) {
		for (int i = 0; i < enemy1.size(); i++) {
			enemy1[i].moveX(0);
		}
	}

	if (direction == 1) {
		for (int i = 0; i < enemy1.size(); i++) {
			enemy1[i].moveX(1);
		}
	}
	// Vector 2
	if (enemy2.front().getX() <= 0) {
		if (enemy2[0].getY() <= 600) {
			for (int i = 0; i < enemy2.size(); i++) {
				enemy2[i].moveDown();
			}
		}
		direction = 1;
	}
	else if (enemy2.back().getX() >= (SCREEN_SIZE - 48)) {
		for (int i = 0; i < enemy2.size(); i++) {
			enemy2[i].moveDown();
		}
		direction = 0;
	}

	if (direction == 0) {
		for (int i = 0; i < enemy2.size(); i++) {
			enemy2[i].moveX(0);
		}
	}

	if (direction == 1) {
		for (int i = 0; i < enemy2.size(); i++) {
			enemy2[i].moveX(1);
		}
	}

	// Vector 3
	if (enemy3.front().getX() <= 0) {
		if (enemy3[0].getY() <= 600) {
			for (int i = 0; i < enemy3.size(); i++) {
				enemy3[i].moveDown();
			}
		}
		direction = 1;
	}
	else if (enemy3.back().getX() >= (SCREEN_SIZE - 48)) {
		for (int i = 0; i < enemy3.size(); i++) {
			enemy3[i].moveDown();
		}
		direction = 0;
	}

	if (direction == 0) {
		for (int i = 0; i < enemy3.size(); i++) {
			enemy3[i].moveX(0);
		}
	}

	if (direction == 1) {
		for (int i = 0; i < enemy3.size(); i++) {
			enemy3[i].moveX(1);
		}
	}

	// Vector 4
	if (enemy4.front().getX() <= 0) {
		if (enemy4[0].getY() <= 600) {
			for (int i = 0; i < enemy4.size(); i++) {
				enemy4[i].moveDown();
			}
		}
		direction = 1;
	}
	else if (enemy4.back().getX() >= (SCREEN_SIZE - 48)) {
		for (int i = 0; i < enemy4.size(); i++) {
			enemy4[i].moveDown();
		}
		direction = 0;
	}

	if (direction == 0) {
		for (int i = 0; i < enemy4.size(); i++) {
			enemy4[i].moveX(0);
		}
	}

	if (direction == 1) {
		for (int i = 0; i < enemy4.size(); i++) {
			enemy4[i].moveX(1);
		}
	}

	// Vector 5
	if (enemy5.front().getX() <= 0) {
		if (enemy5[0].getY() <= 600) {
			for (int i = 0; i < enemy5.size(); i++) {
				enemy5[i].moveDown();
			}
		}
		direction = 1;
	}
	else if (enemy5.back().getX() >= (SCREEN_SIZE - 48)) {
		for (int i = 0; i < enemy5.size(); i++) {
			enemy5[i].moveDown();
		}
		direction = 0;
	}

	if (direction == 0) {
		for (int i = 0; i < enemy5.size(); i++) {
			enemy5[i].moveX(0);
		}
	}

	if (direction == 1) {
		for (int i = 0; i < enemy5.size(); i++) {
			enemy5[i].moveX(1);
		}
	}
}

void GameBrain::init() {
	p1->spawnPlayer(m_gameRenderer);

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

	// Logo
	m_logoBMP = SDL_LoadBMP("Img/logo.bmp");
	m_logo_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_logoBMP);
	m_logo_coords.h = m_logoBMP->h;
	m_logo_coords.w = m_logoBMP->w;
	m_logo_coords.x = (800-480)/2;
	m_logo_coords.y = 50;
	SDL_FreeSurface(m_logoBMP);

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
	Enemy e1(m_gameRenderer, 1, 45, 400);
	Enemy e2(m_gameRenderer, 2, 45, 340);
	Enemy e3(m_gameRenderer, 3, 45, 280);
	Enemy e4(m_gameRenderer, 4, 45, 220);
	Enemy e5(m_gameRenderer, 5, 45, 160);

	enemy1.push_back(e1);
	enemy2.push_back(e2);
	enemy3.push_back(e3);
	enemy4.push_back(e4);
	enemy5.push_back(e5);

	for (int i = 1; i < 11; i++) {
		Enemy enemy_1(m_gameRenderer, 1, enemy1[i-1].getX()+60, 400);
		enemy1.push_back(enemy_1);
	}
	for (int i = 1; i < 11; i++) {
		Enemy enemy_2(m_gameRenderer, 2, enemy2[i - 1].getX() + 60, 340);
		enemy2.push_back(enemy_2);
	}
	for (int i = 1; i < 11; i++) {
		Enemy enemy_3(m_gameRenderer, 3, enemy3[i - 1].getX() + 60, 280);
		enemy3.push_back(enemy_3);
	}
	for (int i = 1; i < 11; i++) {
		Enemy enemy_4(m_gameRenderer, 4, enemy4[i - 1].getX() + 60, 220);
		enemy4.push_back(enemy_4);
	}
	for (int i = 1; i < 11; i++) {
		Enemy enemy_5(m_gameRenderer, 5, enemy5[i - 1].getX() + 60, 160);
		enemy5.push_back(enemy_5);
	}
}

void GameBrain::checkCollision() {
	for (int i = 0; i < p1->getBullets().size(); i++) {
		for (int j = 0; j < enemy1.size(); j++) {
			if (p1->getBullets()[i]->getY() >= enemy1[j].getY() &&
				p1->getBullets()[i]->getY() <= (enemy1[j].getY() + 47) && 
				p1->getBullets()[i]->getX() >= enemy1[j].getX() &&
				p1->getBullets()[i]->getX() <= (enemy1[j].getX() + 47))
				{
						//p1->getBullets()[i]
						std::cout << "HIT BLYAT" << std::endl;
				}
		}
	}
	
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
			if (event.key.keysym.sym == SDLK_SPACE && m_screen == 2) {
				Projectile *p = new Projectile();
				p->spawn(m_gameRenderer, p1->getX(), p1->getY());
				p1->addBullets(p);
				
			}
			if (event.key.keysym.sym == SDLK_ESCAPE && m_screen == 2) {
				m_screen = 0;
			}
			if (event.key.keysym.sym == SDLK_LEFT && m_screen == 2) {
				p1->updatePos(0);
			}
			else if (event.key.keysym.sym == SDLK_RIGHT && m_screen == 2) {
				p1->updatePos(1);
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
		SDL_RenderCopy(m_gameRenderer, m_logo_drawable, nullptr, &m_logo_coords);
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
		SDL_RenderCopy(m_gameRenderer, p1->getDrawable(), nullptr, p1->getCoords());
		updateEnemyVectors();
		checkCollision();

		for (int i = 0; i < 11; i++) {
			SDL_RenderCopy(m_gameRenderer, enemy1[i].getDrawable(), nullptr, enemy1[i].getCoords());
			SDL_RenderCopy(m_gameRenderer, enemy2[i].getDrawable(), nullptr, enemy2[i].getCoords());
			SDL_RenderCopy(m_gameRenderer, enemy3[i].getDrawable(), nullptr, enemy3[i].getCoords());
			SDL_RenderCopy(m_gameRenderer, enemy4[i].getDrawable(), nullptr, enemy4[i].getCoords());
			SDL_RenderCopy(m_gameRenderer, enemy5[i].getDrawable(), nullptr, enemy5[i].getCoords());
			/*
			SDL_RenderCopy(m_gameRenderer, m_enemy1_drawable, nullptr, &m_arr_enemy1_coords[i]);
			SDL_RenderCopy(m_gameRenderer, m_enemy2_drawable, nullptr, &m_arr_enemy2_coords[i]);
			SDL_RenderCopy(m_gameRenderer, m_enemy3_drawable, nullptr, &m_arr_enemy3_coords[i]);
			SDL_RenderCopy(m_gameRenderer, m_enemy4_drawable, nullptr, &m_arr_enemy4_coords[i]);
			SDL_RenderCopy(m_gameRenderer, m_enemy5_drawable, nullptr, &m_arr_enemy5_coords[i]);
			*/
		}

		// Try projectiles
		if (p1->getBullets().size() > 0) {
			for (int i = 0; i < p1->getBullets().size(); i++) {
				SDL_RenderCopy(m_gameRenderer, p1->getBullets()[i]->getDrawable(), nullptr, p1->getBullets()[i]->getCoords());
				p1->getBullets()[i]->move();
			}
		}
		
		
		
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