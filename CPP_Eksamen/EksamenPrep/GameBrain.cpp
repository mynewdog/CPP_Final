#include "stdafx.h"
#include "GameBrain.h"
#include <iostream>
#include <SDL.h>
#include "Projectile.h"
#include "Player.h"
#include <string>
#include "Obstacle.h"
#include "ScoreHandler.h"

#ifndef SCREEN_SIZE
#define SCREEN_SIZE 800
#endif
// Dir 0 = LEFT | 1 = RIGHT
int direction = 1;
int ticks = 0;
int oldTime = 0;

Player *p1 = new Player();
ScoreHandler *score = new ScoreHandler();

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
	
	// Vector 1
	if (enemy1.front().getX() <= 0) {
		for (int i = 0; i < enemy1.size(); i++) {
			enemy1[i].moveDown();
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
		for (int i = 0; i < enemy2.size(); i++) {
			enemy2[i].moveDown();
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
		for (int i = 0; i < enemy3.size(); i++) {
			enemy3[i].moveDown();
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
		for (int i = 0; i < enemy4.size(); i++) {
			enemy4[i].moveDown();
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
		for (int i = 0; i < enemy5.size(); i++) {
			enemy5[i].moveDown();
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

void GameBrain::initObstacles() {
	// Left
	Obstacle obs1(m_gameRenderer, 0, 0, 100, 600);
	Obstacle obs2(m_gameRenderer, 0, 1, 122, 600);
	Obstacle obs3(m_gameRenderer, 0, 1, 144, 600);
	Obstacle obs4(m_gameRenderer, 0, 2, 166, 600);
	Obstacle obs5(m_gameRenderer, 0, 1, 100, 622);
	Obstacle obs6(m_gameRenderer, 0, 1, 122, 622);
	Obstacle obs7(m_gameRenderer, 0, 1, 144, 622);
	Obstacle obs8(m_gameRenderer, 0, 1, 166, 622);
	Obstacle obs9(m_gameRenderer, 0, 1, 100, 644);
	Obstacle obs10(m_gameRenderer, 0, 1, 122, 644);
	Obstacle obs11(m_gameRenderer, 0, 1, 144, 644);
	Obstacle obs12(m_gameRenderer, 0, 1, 166, 644);
	Obstacle obs13(m_gameRenderer, 0, 4, 100, 666);
	Obstacle obs14(m_gameRenderer, 0, 3, 166, 666);
	leftObst.push_back(obs1);
	leftObst.push_back(obs2);
	leftObst.push_back(obs3);
	leftObst.push_back(obs4);
	leftObst.push_back(obs5);
	leftObst.push_back(obs6);
	leftObst.push_back(obs7);
	leftObst.push_back(obs8);
	leftObst.push_back(obs9);
	leftObst.push_back(obs10);
	leftObst.push_back(obs11);
	leftObst.push_back(obs12);
	leftObst.push_back(obs13);
	leftObst.push_back(obs14);

	// Middle
	Obstacle obs15(m_gameRenderer, 0, 0, 356, 600);
	Obstacle obs16(m_gameRenderer, 0, 1, 378, 600);
	Obstacle obs17(m_gameRenderer, 0, 1, 400, 600);
	Obstacle obs18(m_gameRenderer, 0, 2, 422, 600);
	Obstacle obs19(m_gameRenderer, 0, 1, 356, 622);
	Obstacle obs20(m_gameRenderer, 0, 1, 378, 622);
	Obstacle obs21(m_gameRenderer, 0, 1, 400, 622);
	Obstacle obs22(m_gameRenderer, 0, 1, 422, 622);
	Obstacle obs23(m_gameRenderer, 0, 1, 356, 644);
	Obstacle obs24(m_gameRenderer, 0, 1, 378, 644);
	Obstacle obs25(m_gameRenderer, 0, 1, 400, 644);
	Obstacle obs26(m_gameRenderer, 0, 1, 422, 644);
	Obstacle obs27(m_gameRenderer, 0, 4, 356, 666);
	Obstacle obs28(m_gameRenderer, 0, 3, 422, 666);
	middleObst.push_back(obs15);
	middleObst.push_back(obs16);
	middleObst.push_back(obs17);
	middleObst.push_back(obs18);
	middleObst.push_back(obs19);
	middleObst.push_back(obs20);
	middleObst.push_back(obs21);
	middleObst.push_back(obs22);
	middleObst.push_back(obs23);
	middleObst.push_back(obs24);
	middleObst.push_back(obs25);
	middleObst.push_back(obs26);
	middleObst.push_back(obs27);
	middleObst.push_back(obs28);

	// Right
	Obstacle obs29(m_gameRenderer, 0, 0, 612, 600);
	Obstacle obs30(m_gameRenderer, 0, 1, 634, 600);
	Obstacle obs31(m_gameRenderer, 0, 1, 656, 600);
	Obstacle obs32(m_gameRenderer, 0, 2, 678, 600);
	Obstacle obs33(m_gameRenderer, 0, 1, 612, 622);
	Obstacle obs34(m_gameRenderer, 0, 1, 634, 622);
	Obstacle obs35(m_gameRenderer, 0, 1, 656, 622);
	Obstacle obs36(m_gameRenderer, 0, 1, 678, 622);
	Obstacle obs37(m_gameRenderer, 0, 1, 612, 644);
	Obstacle obs38(m_gameRenderer, 0, 1, 634, 644);
	Obstacle obs39(m_gameRenderer, 0, 1, 656, 644);
	Obstacle obs40(m_gameRenderer, 0, 1, 678, 644);
	Obstacle obs41(m_gameRenderer, 0, 4, 612, 666);
	Obstacle obs42(m_gameRenderer, 0, 3, 678, 666);
	rightObst.push_back(obs29);
	rightObst.push_back(obs30);
	rightObst.push_back(obs31);
	rightObst.push_back(obs32);
	rightObst.push_back(obs33);
	rightObst.push_back(obs34);
	rightObst.push_back(obs35);
	rightObst.push_back(obs36);
	rightObst.push_back(obs37);
	rightObst.push_back(obs38);
	rightObst.push_back(obs39);
	rightObst.push_back(obs40);
	rightObst.push_back(obs41);
	rightObst.push_back(obs42);
}

void GameBrain::init() {
	p1->spawnPlayer(m_gameRenderer);
	m_currentScore = 0;

	// Obstacles
	initObstacles();

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
	m_backBMP = SDL_LoadBMP("Img/howto.bmp");

	m_back_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_backBMP);
	m_back_coords.h = m_backBMP->h;
	m_back_coords.w = m_backBMP->w;
	m_back_coords.x = 0;
	m_back_coords.y = 0;
	SDL_FreeSurface(m_backBMP);

	// Score - 10k spot
	m_score1 = SDL_LoadBMP("Img/score/0.bmp");
	m_score1_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_score1);
	m_score1_coords.h = 25;
	m_score1_coords.w = 26;
	m_score1_coords.x = 24;
	m_score1_coords.y = 62;
	SDL_FreeSurface(m_score1);

	// Score - 1k spot
	m_score2 = SDL_LoadBMP("Img/score/0.bmp");
	m_score2_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_score2);
	m_score2_coords.h = 25;
	m_score2_coords.w = 26;
	m_score2_coords.x = 50;
	m_score2_coords.y = 62;
	SDL_FreeSurface(m_score2);

	// Score - 100 spot
	m_score3 = SDL_LoadBMP("Img/score/0.bmp");
	m_score3_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_score3);
	m_score3_coords.h = 25;
	m_score3_coords.w = 26;
	m_score3_coords.x = 76;
	m_score3_coords.y = 62;
	SDL_FreeSurface(m_score3);

	// Score - 10 spot
	m_score4 = SDL_LoadBMP("Img/score/0.bmp");
	m_score4_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_score4);
	m_score4_coords.h = 25;
	m_score4_coords.w = 26;
	m_score4_coords.x = 102;
	m_score4_coords.y = 62;
	SDL_FreeSurface(m_score4);

	// Score - 1 spot
	m_score5 = SDL_LoadBMP("Img/score/0.bmp");
	m_score5_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_score5);
	m_score5_coords.h = 25;
	m_score5_coords.w = 26;
	m_score5_coords.x = 128;
	m_score5_coords.y = 62;
	SDL_FreeSurface(m_score5);

	//////////////////////////
	/////////////////////////

	// HighScore - 10k spot
	m_highscore1 = SDL_LoadBMP("Img/score/0.bmp");
	m_highscore1_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_highscore1);
	m_highscore1_coords.h = 25;
	m_highscore1_coords.w = 26;
	m_highscore1_coords.x = 307;
	m_highscore1_coords.y = 62;
	SDL_FreeSurface(m_highscore1);

	// HighScore - 1k spot
	m_highscore2 = SDL_LoadBMP("Img/score/0.bmp");
	m_highscore2_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_highscore2);
	m_highscore2_coords.h = 25;
	m_highscore2_coords.w = 26;
	m_highscore2_coords.x = 333;
	m_highscore2_coords.y = 62;
	SDL_FreeSurface(m_highscore2);

	// HighScore - 100 spot
	m_highscore3 = SDL_LoadBMP("Img/score/0.bmp");
	m_highscore3_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_highscore3);
	m_highscore3_coords.h = 25;
	m_highscore3_coords.w = 26;
	m_highscore3_coords.x = 359;
	m_highscore3_coords.y = 62;
	SDL_FreeSurface(m_highscore3);

	// HighScore - 10 spot
	m_highscore4 = SDL_LoadBMP("Img/score/0.bmp");
	m_highscore4_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_highscore4);
	m_highscore4_coords.h = 25;
	m_highscore4_coords.w = 26;
	m_highscore4_coords.x = 385;
	m_highscore4_coords.y = 62;
	SDL_FreeSurface(m_highscore4);

	// HighScore - 1 spot
	m_highscore5 = SDL_LoadBMP("Img/score/0.bmp");
	m_highscore5_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_highscore5);
	m_highscore5_coords.h = 25;
	m_highscore5_coords.w = 26;
	m_highscore5_coords.x = 411;
	m_highscore5_coords.y = 62;
	SDL_FreeSurface(m_highscore5);

	// Game over screen
	m_gameOverBMP = SDL_LoadBMP("Img/gameoverBG.bmp");

	m_gameOver_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_gameOverBMP);
	m_gameOver_coords.h = m_gameOverBMP->h;
	m_gameOver_coords.w = m_gameOverBMP->w;
	m_gameOver_coords.x = 0;
	m_gameOver_coords.y = 0;
	SDL_FreeSurface(m_gameOverBMP);

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

void GameBrain::checkWin() {
	if (m_killCounter == 5) {
		std::cout << "You won" << std::endl;
		restart();
	}
}

void GameBrain::restart() {
	if (m_currentScore > score->readFile()) {
		std::string temp = std::to_string(m_currentScore);
		const char * converted = temp.c_str();
		score->writeFile(converted);
	}
	// Remove all bullets from screen
	for (int i = 0; i < p1->getBullets().size(); i++) {
		p1->getBullets()[i]->setY(-1500);
	}

	// Set player back to position
	p1->setX((SCREEN_SIZE - 54) / 2);

	// Update score
	updateHighScore();
	m_currentScore = 0;
	updateScore();

	// Reset enemies, killcounter and update screen
	redrawObstacles();
	redrawEnemies();
	m_killCounter = 0;
	m_screen = 3;
}

void GameBrain::updateScore() {
	int tempScore[5];
	int tempScoreCalc = m_currentScore;
	int calc = 0;

	// 10000
	calc = tempScoreCalc / 10000;
	tempScoreCalc -= (calc * 10000);
	tempScore[0] = calc;

	// 1000
	calc = tempScoreCalc / 1000;
	tempScoreCalc -= (calc * 1000);
	tempScore[1] = calc;

	// 100
	calc = tempScoreCalc / 100;
	tempScoreCalc -= (calc * 100);
	tempScore[2] = calc;

	// 10
	calc = tempScoreCalc / 10;
	tempScoreCalc -= (calc * 10);
	tempScore[3] = calc;


	std::string pathName = "Img/score/";
	std::string pathNum = "4";
	std::string pathFile = ".bmp";
	std::string finalString = pathName + pathNum + pathFile;
	
	// Check 10 spot
	if (tempScore[3] < 10) {
		if (tempScore[3] == 0) { pathNum = "0"; }
		else if (tempScore[3] == 1) { pathNum = "1"; }
		else if (tempScore[3] == 2) { pathNum = "2"; }
		else if (tempScore[3] == 3) { pathNum = "3"; }
		else if (tempScore[3] == 4) { pathNum = "4"; }
		else if (tempScore[3] == 5) { pathNum = "5"; }
		else if (tempScore[3] == 6) { pathNum = "6"; }
		else if (tempScore[3] == 7) { pathNum = "7"; }
		else if (tempScore[3] == 8) { pathNum = "8"; }
		else if (tempScore[3] == 9) { pathNum = "9"; }

		std::string finalString = pathName + pathNum + pathFile;
		m_score4 = SDL_LoadBMP(finalString.c_str());
		m_score4_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_score4);
		SDL_FreeSurface(m_score4);
	}

	// Check 100 spot
	if (tempScore[2] < 10) {
		if (tempScore[2] == 0) { pathNum = "0"; }
		else if (tempScore[2] == 1) { pathNum = "1"; }
		else if (tempScore[2] == 2) { pathNum = "2"; }
		else if (tempScore[2] == 3) { pathNum = "3"; }
		else if (tempScore[2] == 4) { pathNum = "4"; }
		else if (tempScore[2] == 5) { pathNum = "5"; }
		else if (tempScore[2] == 6) { pathNum = "6"; }
		else if (tempScore[2] == 7) { pathNum = "7"; }
		else if (tempScore[2] == 8) { pathNum = "8"; }
		else if (tempScore[2] == 9) { pathNum = "9"; }

		std::string finalString = pathName + pathNum + pathFile;
		m_score3 = SDL_LoadBMP(finalString.c_str());
		m_score3_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_score3);
		SDL_FreeSurface(m_score3);
	}

	// Check 1000 spot
	if (tempScore[1] < 10) {
		if (tempScore[1] == 0) { pathNum = "0"; }
		else if (tempScore[1] == 1) { pathNum = "1"; }
		else if (tempScore[1] == 2) { pathNum = "2"; }
		else if (tempScore[1] == 3) { pathNum = "3"; }
		else if (tempScore[1] == 4) { pathNum = "4"; }
		else if (tempScore[1] == 5) { pathNum = "5"; }
		else if (tempScore[1] == 6) { pathNum = "6"; }
		else if (tempScore[1] == 7) { pathNum = "7"; }
		else if (tempScore[1] == 8) { pathNum = "8"; }
		else if (tempScore[1] == 9) { pathNum = "9"; }

		std::string finalString = pathName + pathNum + pathFile;
		m_score2 = SDL_LoadBMP(finalString.c_str());
		m_score2_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_score2);
		SDL_FreeSurface(m_score2);
	}

	// Check 10k spot
	if (tempScore[0] < 10) {
		if (tempScore[0] == 0) { pathNum = "0"; }
		else if (tempScore[0] == 1) { pathNum = "1"; }
		else if (tempScore[0] == 2) { pathNum = "2"; }
		else if (tempScore[0] == 3) { pathNum = "3"; }
		else if (tempScore[0] == 4) { pathNum = "4"; }
		else if (tempScore[0] == 5) { pathNum = "5"; }
		else if (tempScore[0] == 6) { pathNum = "6"; }
		else if (tempScore[0] == 7) { pathNum = "7"; }
		else if (tempScore[0] == 8) { pathNum = "8"; }
		else if (tempScore[0] == 9) { pathNum = "9"; }

		std::string finalString = pathName + pathNum + pathFile;
		m_score1 = SDL_LoadBMP(finalString.c_str());
		m_score1_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_score1);
		SDL_FreeSurface(m_score1);
	}
}
void GameBrain::updateHighScore() {
	int tempScore[5];
	int tempScoreCalc = score->readFile();
	int calc = 0;

	// 10000
	calc = tempScoreCalc / 10000;
	tempScoreCalc -= (calc * 10000);
	tempScore[0] = calc;

	// 1000
	calc = tempScoreCalc / 1000;
	tempScoreCalc -= (calc * 1000);
	tempScore[1] = calc;

	// 100
	calc = tempScoreCalc / 100;
	tempScoreCalc -= (calc * 100);
	tempScore[2] = calc;

	// 10
	calc = tempScoreCalc / 10;
	tempScoreCalc -= (calc * 10);
	tempScore[3] = calc;


	std::string pathName = "Img/score/";
	std::string pathNum = "4";
	std::string pathFile = ".bmp";
	std::string finalString = pathName + pathNum + pathFile;

	// Check 10 spot
	if (tempScore[3] < 10) {
		if (tempScore[3] == 0) { pathNum = "0"; }
		else if (tempScore[3] == 1) { pathNum = "1"; }
		else if (tempScore[3] == 2) { pathNum = "2"; }
		else if (tempScore[3] == 3) { pathNum = "3"; }
		else if (tempScore[3] == 4) { pathNum = "4"; }
		else if (tempScore[3] == 5) { pathNum = "5"; }
		else if (tempScore[3] == 6) { pathNum = "6"; }
		else if (tempScore[3] == 7) { pathNum = "7"; }
		else if (tempScore[3] == 8) { pathNum = "8"; }
		else if (tempScore[3] == 9) { pathNum = "9"; }

		std::string finalString = pathName + pathNum + pathFile;
		m_highscore4 = SDL_LoadBMP(finalString.c_str());
		m_highscore4_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_highscore4);
		SDL_FreeSurface(m_highscore4);
	}

	// Check 100 spot
	if (tempScore[2] < 10) {
		if (tempScore[2] == 0) { pathNum = "0"; }
		else if (tempScore[2] == 1) { pathNum = "1"; }
		else if (tempScore[2] == 2) { pathNum = "2"; }
		else if (tempScore[2] == 3) { pathNum = "3"; }
		else if (tempScore[2] == 4) { pathNum = "4"; }
		else if (tempScore[2] == 5) { pathNum = "5"; }
		else if (tempScore[2] == 6) { pathNum = "6"; }
		else if (tempScore[2] == 7) { pathNum = "7"; }
		else if (tempScore[2] == 8) { pathNum = "8"; }
		else if (tempScore[2] == 9) { pathNum = "9"; }

		std::string finalString = pathName + pathNum + pathFile;
		m_highscore3 = SDL_LoadBMP(finalString.c_str());
		m_highscore3_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_highscore3);
		SDL_FreeSurface(m_highscore3);
	}

	// Check 1000 spot
	if (tempScore[1] < 10) {
		if (tempScore[1] == 0) { pathNum = "0"; }
		else if (tempScore[1] == 1) { pathNum = "1"; }
		else if (tempScore[1] == 2) { pathNum = "2"; }
		else if (tempScore[1] == 3) { pathNum = "3"; }
		else if (tempScore[1] == 4) { pathNum = "4"; }
		else if (tempScore[1] == 5) { pathNum = "5"; }
		else if (tempScore[1] == 6) { pathNum = "6"; }
		else if (tempScore[1] == 7) { pathNum = "7"; }
		else if (tempScore[1] == 8) { pathNum = "8"; }
		else if (tempScore[1] == 9) { pathNum = "9"; }

		std::string finalString = pathName + pathNum + pathFile;
		m_highscore2 = SDL_LoadBMP(finalString.c_str());
		m_highscore2_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_highscore2);
		SDL_FreeSurface(m_highscore2);
	}

	// Check 10k spot
	if (tempScore[0] < 10) {
		if (tempScore[0] == 0) { pathNum = "0"; }
		else if (tempScore[0] == 1) { pathNum = "1"; }
		else if (tempScore[0] == 2) { pathNum = "2"; }
		else if (tempScore[0] == 3) { pathNum = "3"; }
		else if (tempScore[0] == 4) { pathNum = "4"; }
		else if (tempScore[0] == 5) { pathNum = "5"; }
		else if (tempScore[0] == 6) { pathNum = "6"; }
		else if (tempScore[0] == 7) { pathNum = "7"; }
		else if (tempScore[0] == 8) { pathNum = "8"; }
		else if (tempScore[0] == 9) { pathNum = "9"; }

		std::string finalString = pathName + pathNum + pathFile;
		m_highscore1 = SDL_LoadBMP(finalString.c_str());
		m_highscore1_drawable = SDL_CreateTextureFromSurface(m_gameRenderer, m_highscore1);
		SDL_FreeSurface(m_highscore1);
	}
}

void GameBrain::redrawEnemies() {
	enemy1[0].setX(45);
	enemy1[0].setY(400);
	
	enemy2[0].setX(45);
	enemy2[0].setY(340);
	
	enemy3[0].setX(45);
	enemy3[0].setY(280);
	
	enemy4[0].setX(45);
	enemy4[0].setY(220);
	
	enemy5[0].setX(45);
	enemy5[0].setY(160);
	int i = 1;
	while ((i > 0) && (i < 11)) {
		enemy1[i].setX(enemy1[i-1].getX() + 60);
		enemy1[i].setY(400);

		enemy2[i].setX(enemy2[i - 1].getX() + 60);
		enemy2[i].setY(340);

		enemy3[i].setX(enemy3[i - 1].getX() + 60);
		enemy3[i].setY(280);

		enemy4[i].setX(enemy4[i - 1].getX() + 60);
		enemy4[i].setY(220);

		enemy5[i].setX(enemy5[i - 1].getX() + 60);
		enemy5[i].setY(160);
		i++;
	}
}

void GameBrain::redrawObstacles() {
	leftObst[0].setY(400);
	middleObst[0].setY(340);
	rightObst[0].setY(280);

	for (int j = 0; j < 4; j++) {
		leftObst[j].setY(600);
		middleObst[j].setY(600);
		rightObst[j].setY(600);
	}

	for (int k = 4; k < 8; k++) {
		leftObst[k].setY(622);
		middleObst[k].setY(622);
		rightObst[k].setY(622);
	}

	for (int l = 8; l < 12; l++) {
		leftObst[l].setY(644);
		middleObst[l].setY(644);
		rightObst[l].setY(644);
	}

	for (int m = 12; m < 14; m++) {
		leftObst[m].setY(666);
		middleObst[m].setY(666);
		rightObst[m].setY(666);
	}
}

void GameBrain::checkCollision() {
	for (int i = 0; i < p1->getBullets().size(); i++) {
		if (p1->getBullets()[i]->getX() < 0) {
			p1->removeBullet(i);
		}
	}

	// Check if hit obstacle 1
	for (int i = 0; i < p1->getBullets().size(); i++) {
		if (p1->getBullets()[i]->getY() > 500) {

			// Check if hit obstacle
			for (int j = 0; j < leftObst.size(); j++) {
				if (p1->getBullets()[i]->getX()+1 >= leftObst[j].getX() &&
					p1->getBullets()[i]->getX()+1 <= (leftObst[j].getX() + 21) &&
					p1->getBullets()[i]->getY() >= leftObst[j].getY() &&
					p1->getBullets()[i]->getY() <= (leftObst[j].getY() + 21)) {
						p1->getBullets()[i]->setY(-1500);
						leftObst[j].setY(-850);
				}
			}
		}
	}

	// Check if hit obstacle 2
	for (int i = 0; i < p1->getBullets().size(); i++) {
		if (p1->getBullets()[i]->getY() > 500) {

			// Check if hit obstacle
			for (int j = 0; j < middleObst.size(); j++) {
				if (p1->getBullets()[i]->getX() + 1 >= middleObst[j].getX() &&
					p1->getBullets()[i]->getX() + 1 <= (middleObst[j].getX() + 21) &&
					p1->getBullets()[i]->getY() >= middleObst[j].getY() &&
					p1->getBullets()[i]->getY() <= (middleObst[j].getY() + 21)) {
					p1->getBullets()[i]->setY(-1500);
					middleObst[j].setY(-850);
				}
			}
		}
	}

	// Check if hit obstacle 3
	for (int i = 0; i < p1->getBullets().size(); i++) {
		if (p1->getBullets()[i]->getY() > 500) {

			// Check if hit obstacle
			for (int j = 0; j < rightObst.size(); j++) {
				if (p1->getBullets()[i]->getX() + 1 >= rightObst[j].getX() &&
					p1->getBullets()[i]->getX() + 1 <= (rightObst[j].getX() + 21) &&
					p1->getBullets()[i]->getY() >= rightObst[j].getY() &&
					p1->getBullets()[i]->getY() <= (rightObst[j].getY() + 21)) {
					p1->getBullets()[i]->setY(-1500);
					rightObst[j].setY(-850);
				}
			}
		}
	}

	// Check if alien touches player
	for (int i = 0; i < 11; i++) {
		if ((enemy1[i].getY() + 47) >= p1->getY() ||
			(enemy2[i].getY() + 47) >= p1->getY() ||
			(enemy3[i].getY() + 47) >= p1->getY() ||
			(enemy4[i].getY() + 47) >= p1->getY() ||
			(enemy5[i].getY() + 47) >= p1->getY()) {
				restart();	
				
				updateScore();
		}
	}

	if (p1->getBullets().size() > 0) {
		// Vector 1
		for (int i = 0; i < p1->getBullets().size(); i++) {
			if (!(p1->getBullets()[i]->getY() < 0)) {
				for (int j = 0; j < enemy1.size(); j++) {
					if (p1->getBullets()[i]->getY() >= enemy1[j].getY() &&
						p1->getBullets()[i]->getY() <= (enemy1[j].getY() + 47) &&
						p1->getBullets()[i]->getX() >= enemy1[j].getX() &&
						p1->getBullets()[i]->getX() <= (enemy1[j].getX() + 47))
					{
						p1->getBullets()[i]->setY(-1200);
						enemy1[j].setY(-1000);
						m_killCounter++;
						m_currentScore += 10;
						updateScore();
						std::cout << m_currentScore << std::endl;
						checkWin();
						
					}
				}
			}
		}

		// Vector 2
		for (int i = 0; i < p1->getBullets().size(); i++) {
			if (!(p1->getBullets()[i]->getY() < 0)) {
				for (int j = 0; j < enemy2.size(); j++) {
					if (p1->getBullets()[i]->getY() >= enemy2[j].getY() &&
						p1->getBullets()[i]->getY() <= (enemy2[j].getY() + 47) &&
						p1->getBullets()[i]->getX() >= enemy2[j].getX() &&
						p1->getBullets()[i]->getX() <= (enemy2[j].getX() + 47))
					{
						p1->getBullets()[i]->setY(-1200);
						enemy2[j].setY(-1000);
						m_killCounter++;
						m_currentScore += 20;
						updateScore();
						std::cout << m_currentScore << std::endl;
						checkWin();
						
					}
				}
			}
		}

		// Vector 3
		for (int i = 0; i < p1->getBullets().size(); i++) {
			if (!(p1->getBullets()[i]->getY() < 0)) {
				for (int j = 0; j < enemy3.size(); j++) {
					if (p1->getBullets()[i]->getY() >= enemy3[j].getY() &&
						p1->getBullets()[i]->getY() <= (enemy3[j].getY() + 47) &&
						p1->getBullets()[i]->getX() >= enemy3[j].getX() &&
						p1->getBullets()[i]->getX() <= (enemy3[j].getX() + 47))
					{
						p1->getBullets()[i]->setY(-1200);
						enemy3[j].setY(-1000);
						m_killCounter++;
						m_currentScore += 30;
						updateScore();
						std::cout << m_currentScore << std::endl;
						checkWin();
						
					}
				}
			}
		}

		// Vector 4
		for (int i = 0; i < p1->getBullets().size(); i++) {
			if (!(p1->getBullets()[i]->getY() < 0)) {
				for (int j = 0; j < enemy4.size(); j++) {
					if (p1->getBullets()[i]->getY() >= enemy4[j].getY() &&
						p1->getBullets()[i]->getY() <= (enemy4[j].getY() + 47) &&
						p1->getBullets()[i]->getX() >= enemy4[j].getX() &&
						p1->getBullets()[i]->getX() <= (enemy4[j].getX() + 47))
					{
						p1->getBullets()[i]->setY(-1200);
						enemy4[j].setY(-1000);
						m_killCounter++;
						m_currentScore += 40;
						updateScore();
						std::cout << m_currentScore << std::endl;
						checkWin();
						
					}
				}
			}
		}

		// Vector 5
		for (int i = 0; i < p1->getBullets().size(); i++) {
			if (!(p1->getBullets()[i]->getY() < 0)) {
				for (int j = 0; j < enemy5.size(); j++) {
					if (p1->getBullets()[i]->getY() >= enemy5[j].getY() &&
						p1->getBullets()[i]->getY() <= (enemy5[j].getY() + 47) &&
						p1->getBullets()[i]->getX() >= enemy5[j].getX() &&
						p1->getBullets()[i]->getX() <= (enemy5[j].getX() + 47))
					{
						p1->getBullets()[i]->setY(-1200);
						enemy5[j].setY(-1000);
						m_killCounter++;
						m_currentScore += 50;
						updateScore();
						std::cout << m_currentScore << std::endl;
						checkWin();
						

					}
				}
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
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);
	
	if (event.type == SDL_KEYDOWN) {
	
		// Check space and left
		if (keystate[SDL_SCANCODE_SPACE] && keystate[SDL_SCANCODE_LEFT]) {
			p1->updatePos(0);
			int currentTime = SDL_GetTicks();
			if (currentTime > oldTime + 300) {
				oldTime = currentTime;
				Projectile *p = new Projectile();
				std::cout << "Projectile created" << std::endl;
				p->spawn(m_gameRenderer, p1->getX(), p1->getY());
				p1->addBullets(p);
			}
		}

		// Check space and right
		else if (keystate[SDL_SCANCODE_SPACE] && keystate[SDL_SCANCODE_RIGHT]) {
			p1->updatePos(1);
			int currentTime = SDL_GetTicks();
			// Only shoot every 0.5s
			if (currentTime > oldTime + 300) {
				oldTime = currentTime;
				std::cout << "Projectile created" << std::endl;
				Projectile *p = new Projectile();
				p->spawn(m_gameRenderer, p1->getX(), p1->getY());
				p1->addBullets(p);
			}
		}

		// Check only left and right
		else if (keystate[SDL_SCANCODE_LEFT] && !keystate[SDL_SCANCODE_SPACE]) {
			p1->updatePos(0);
		}
		else if (keystate[SDL_SCANCODE_RIGHT] && !keystate[SDL_SCANCODE_SPACE]) {
			p1->updatePos(1);
		}

		//Check only space
		else if (keystate[SDL_SCANCODE_SPACE] && !keystate[SDL_SCANCODE_LEFT] && !keystate[SDL_SCANCODE_RIGHT] && m_screen == 2) {
			int currentTime = SDL_GetTicks();
			// Only shoot every 0.5s
			if (currentTime > oldTime + 300) {
				oldTime = currentTime;
				Projectile *p = new Projectile();
				std::cout << "Projectile created" << std::endl;
				p->spawn(m_gameRenderer, p1->getX(), p1->getY());
				p1->addBullets(p);
			}
		}
		if (event.key.keysym.sym == SDLK_ESCAPE && m_screen == 2) {
			m_screen = 0;
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
				restart();
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

		// Restart game if enter button pressed)
		if (event.key.keysym.sym == SDLK_RETURN && m_screen == 3) {
			m_screen = 2;
		}

		// Go to main menu from game over screen
		if (event.key.keysym.sym == SDLK_ESCAPE && m_screen == 3) {
			m_screen = 0;
		}
	}

}
void GameBrain::drawGameScreen() {
	SDL_RenderCopy(m_gameRenderer, m_gameBG_drawable, nullptr, &m_gameBG_coords);
}


void GameBrain::render() {
	// Clear last frame
	SDL_RenderClear(m_gameRenderer);
	SDL_FillRect(NULL, NULL, 0x000000);

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

		// Render all enemies
		for (int i = 0; i < 11; i++) {
			SDL_RenderCopy(m_gameRenderer, enemy1[i].getDrawable(), nullptr, enemy1[i].getCoords());
			SDL_RenderCopy(m_gameRenderer, enemy2[i].getDrawable(), nullptr, enemy2[i].getCoords());
			SDL_RenderCopy(m_gameRenderer, enemy3[i].getDrawable(), nullptr, enemy3[i].getCoords());
			SDL_RenderCopy(m_gameRenderer, enemy4[i].getDrawable(), nullptr, enemy4[i].getCoords());
			SDL_RenderCopy(m_gameRenderer, enemy5[i].getDrawable(), nullptr, enemy5[i].getCoords());
		}

		// Obstacles
		// Left
		for (int i = 0; i < leftObst.size(); i++) {
			SDL_RenderCopy(m_gameRenderer, leftObst[i].getDrawable(), nullptr, leftObst[i].getCoords());
		}
		// Middle
		for (int i = 0; i < middleObst.size(); i++) {
			SDL_RenderCopy(m_gameRenderer, middleObst[i].getDrawable(), nullptr, middleObst[i].getCoords());
		}
		// Right
		for (int i = 0; i < rightObst.size(); i++) {
			SDL_RenderCopy(m_gameRenderer, rightObst[i].getDrawable(), nullptr, rightObst[i].getCoords());
		}
		
		// Render score
		SDL_RenderCopy(m_gameRenderer, m_score1_drawable, nullptr, &m_score1_coords);
		SDL_RenderCopy(m_gameRenderer, m_score2_drawable, nullptr, &m_score2_coords);
		SDL_RenderCopy(m_gameRenderer, m_score3_drawable, nullptr, &m_score3_coords);
		SDL_RenderCopy(m_gameRenderer, m_score4_drawable, nullptr, &m_score4_coords);
		SDL_RenderCopy(m_gameRenderer, m_score5_drawable, nullptr, &m_score5_coords);

		// Render highscore
		SDL_RenderCopy(m_gameRenderer, m_highscore1_drawable, nullptr, &m_highscore1_coords);
		SDL_RenderCopy(m_gameRenderer, m_highscore2_drawable, nullptr, &m_highscore2_coords);
		SDL_RenderCopy(m_gameRenderer, m_highscore3_drawable, nullptr, &m_highscore3_coords);
		SDL_RenderCopy(m_gameRenderer, m_highscore4_drawable, nullptr, &m_highscore4_coords);
		SDL_RenderCopy(m_gameRenderer, m_highscore5_drawable, nullptr, &m_highscore5_coords);

		if (ticks < 60) {
			ticks++;
		}
		else {
			ticks = 0;
		}

		// Try projectiles
		if (p1->getBullets().size() > 0) {
			for (int i = 0; i < p1->getBullets().size(); i++) {
				SDL_RenderCopy(m_gameRenderer, p1->getBullets()[i]->getDrawable(), nullptr, p1->getBullets()[i]->getCoords());
				p1->getBullets()[i]->move();
			}
		}
		
		
		
	}

	// Game over screen
	else if (m_screen == 3) {
		SDL_RenderCopy(m_gameRenderer, m_gameOver_drawable, nullptr, &m_gameOver_coords);
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