#include <iostream>
#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>

#pragma comment (lib, "lib/SDL2.lib")
#pragma comment (lib, "lib/SDL2main.lib")

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;



int main(int argc, char* args[]) {

	SDL_Init(SDL_INIT_EVERYTHING);


	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
	bool space = false;
	SDL_Window* window = NULL;
	SDL_Renderer* red = NULL;
	SDL_Rect square;
	SDL_Rect shot[2];
	SDL_Event event;

	int current_laser = 0;

	square.x = 100;
	square.y = 100;
	square.w = 50;
	square.h = 50;

	for (int i = 0; i > 2; i++) {
		shot[i].x = 0;
		shot[i].y = 0;
		shot[i].w = 10;
		shot[i].h = 20;
	}
	


	window = SDL_CreateWindow("Blue Square", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_RENDERER_PRESENTVSYNC);

	red = SDL_CreateRenderer(window, -1, 0);


	SDL_PollEvent(&event);

	while (1) {
		
		//Key detector
		while (1) {
			while (SDL_PollEvent(&event) != 0) {
				if (event.type == SDL_KEYUP)
				{
					switch (event.key.keysym.sym) {
					case SDLK_UP: up = false; break;
					case SDLK_DOWN: down = false; break;
					case SDLK_LEFT: left = false; break;
					case SDLK_RIGHT: right = false; break;
					}

				}

				else if (event.type == SDL_KEYDOWN)
				{
					switch (event.key.keysym.sym) {
					case SDLK_UP: up = true; break;
					case SDLK_DOWN: down = true; break;
					case SDLK_LEFT: left = true; break;
					case SDLK_RIGHT: right = true; break;
					case SDLK_SPACE: space = true;
						if ((shot[current_laser].y + shot[current_laser].h) > 0) {
							shot[current_laser].y -= 1;
						}

						break;

					}
				}

			}

			// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -//

						//Movement

			if (up == true) {
				if (square.y > 0) {
					square.y -= 1;
				}
			}
			if (down == true) {
				if (square.y < SCREEN_HEIGHT - square.h) {
					square.y += 1;
				}
			}
			if (right == true) {
				if (square.x < SCREEN_WIDTH - square.w) {
					square.x += 1;
				}
			}
			if (left == true) {
				if (square.x > 0) {
					square.x -= 1;
				}
			}
			if (space == true) {
				shot[current_laser].x = (square.x + (square.w / 2));
				shot[current_laser].y = (square.y);
				space = false;
				current_laser++;
				if (current_laser == 2) {
					current_laser = 0;
				}
			}

			

			//red background
			SDL_SetRenderDrawColor(red, 255, 0, 0, 0);
			SDL_RenderClear(red);

			//green laser
			for (int i = 0; i < 2; i++) {
				SDL_SetRenderDrawColor(red, 0, 255, 0, 255);
				SDL_RenderFillRect(red, &shot[i]);
			}

			//blue square
			SDL_SetRenderDrawColor(red, 0, 0, 255, 255);
			SDL_RenderFillRect(red, &square);
			SDL_RenderPresent(red);
			
		}


	}

	SDL_DestroyWindow(window);

	return EXIT_SUCCESS;

	SDL_Quit();
}