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

	SDL_Window* window = NULL;
	SDL_Renderer* red = NULL;
	SDL_Rect square;
	SDL_Event event;

	square.x = 100;
	square.y = 100;
	square.w = 100;
	square.h = 100;


	window = SDL_CreateWindow("Blue Square", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	red = SDL_CreateRenderer(window, -1, 0);


	


		//Key detector

		SDL_PollEvent(&event);
		while (int i = 1) {

			while (SDL_PollEvent(&event)) {
				//red background
				SDL_SetRenderDrawColor(red, 255, 0, 0, 0);
				SDL_RenderClear(red);

				//blue square
				SDL_SetRenderDrawColor(red, 0, 0, 255, 255);
				SDL_RenderFillRect(red, &square);
				SDL_RenderPresent(red);

				/* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
				switch (event.type) {
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
					case SDLK_DOWN:
						if (square.y >= SCREEN_HEIGHT- square.h) {
							break;
						}
						else {
							square.y += 5;
							break;
						}
					case (SDLK_UP&&SDLK_LEFT):
						if (square.y <0) {
							break;
						}
						else {
							square.y -= 5;
							square.x -= 5;
							break;
						}
					case SDLK_UP:
						if (square.y <0) {
							break;
						}
						else {
							square.y -= 5;
							break;
						}
					
					case SDLK_LEFT:
						if (square.x <0) {
							break;
						}
						else {
							square.x -= 5;
							break;
						}
					case SDLK_RIGHT:
						if (square.x >= SCREEN_WIDTH - square.w) {
							break;
						}
						else {
							square.x += 5;
							break;
						}
					
					
					
					}
					break;


				default:
					break;
				}
			}
		}
	
			
		
	

	SDL_DestroyWindow(window);

	return EXIT_SUCCESS;

	SDL_Quit();
}