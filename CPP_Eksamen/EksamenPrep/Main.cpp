#include "stdafx.h"
#include "Main.h"
#include "GameBrain.h"
#include <SDL.h>
#undef main

GameBrain *game = nullptr;
int main(void) {
	const int FPS = 30;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;


	game = new GameBrain();
	game->create_window("Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);
	game->init();

	while (game->running()) {
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->clean();
	return 0;
}

Main::Main()
{
}


Main::~Main()
{
}
