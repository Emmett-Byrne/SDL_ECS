
#include "Entity.h"
#include "HealthComponant.h"
#include "PositionComponant.h"
#include "inputComponant.h"
#include "HealthSystem.h"
#include "AiSystem.h"
#include "ControlSystem.h"
#include "RenderSystem.h"
#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char* argv[])
{
	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Texture* texture;

	Entity player("player", "ASSETS\\Playa.png", renderer), alien("alien", "ASSETS\\Ai.png", renderer), dog("dog", "ASSETS\\Dog.png", renderer), cat("cat", "ASSETS\\Cat.png", renderer);
	HealthComponant playerhc, alienhc, doghc;
	PositionComponant playerpos, alienpos, dogpos, catpos;
	playerpos.setPosition(400, 300);
	alienpos.setPosition(50, 50);
	dogpos.setPosition(700, 50);
	catpos.setPosition(50, 500);
	inputComponant playerin;
	player.addComponant(&playerhc);
	player.addComponant(&playerpos);
	player.addComponant(&playerin);
	alien.addComponant(&alienhc);
	alien.addComponant(&alienpos);
	dog.addComponant(&doghc);
	dog.addComponant(&dogpos);
	cat.addComponant(&catpos);

	HealthSystem hs; AiSystem as; RenderSystem rs; ControlSystem cs;
	hs.addEntity(&player);
	hs.addEntity(&alien);
	hs.addEntity(&dog);
	rs.addEntity(&player);
	rs.addEntity(&alien);
	rs.addEntity(&dog);
	rs.addEntity(&cat);
	as.addEntity(&alien);
	as.addEntity(&dog);
	as.addEntity(&cat);
	cs.addEntity(&player);

	bool isRunning = true;

	int frameRate = 10;
	int frameDelay = 1000 / frameRate;
	Uint32 frameStart;
	int frameTime;

	while (isRunning)
	{
		frameStart = SDL_GetTicks();

		int frame = 0;


		SDL_Event event;
		cs.update(event);
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_UP:
					break;
				case SDLK_DOWN:
					break;
				case SDLK_LEFT:
					break;
				case SDLK_RIGHT:
					break;
				case SDLK_ESCAPE:
					isRunning = false;
				default:
					break;
				}
				break;

			case SDL_KEYUP:
				break;

			case SDL_QUIT:
				isRunning = false;
				break;

			default:
				break;
			}
		}



		system("cls");
		hs.update();
		as.update();
		player.displayData();
		alien.displayData();
		dog.displayData();
		cat.displayData();

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		rs.update(renderer);
		SDL_RenderPresent(renderer);

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return EXIT_SUCCESS;
}