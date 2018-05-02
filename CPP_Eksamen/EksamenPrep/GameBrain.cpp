#include "stdafx.h"
#include "GameBrain.h"
#include <iostream>

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

	// Back buttons
	m_backBMP = SDL_LoadBMP("Img/goback.bmp");
	m_back_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_backBMP);
	m_back_coords.h = m_backBMP->h;
	m_back_coords.w = m_backBMP->w;

	m_back_coords.x = 225;
	m_back_coords.y = 700;

	SDL_FreeSurface(m_backBMP);
	
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