#include "stdafx.h"
#include "Main.h"
#include "GameBrain.h"
#include <SDL.h>
#undef main

GameBrain *test = nullptr;
int main(void) {
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;


	test = new GameBrain();
	test->createWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);
	test->initImages();

	while (test->running()) {
		frameStart = SDL_GetTicks();

		test->handleEvents();
		test->update();
		test->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	test->clean();
	return 0;
}

Main::Main()
{
}


Main::~Main()
{
}
