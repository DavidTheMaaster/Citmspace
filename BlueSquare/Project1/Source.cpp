#include <iostream>
#include "include\SDL.h"
#include <stdio.h>
#include <stdlib.h>

#pragma comment (lib, "lib/SDL2.lib")
#pragma comment (lib, "lib/SDL2main.lib")

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;

#define NUM_LASER 10


int main(int argc, char* args[]) {

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = NULL;
	//SDL_Renderer* rectangle = NULL;
	SDL_Surface *Ash = NULL;
	SDL_Surface *red = NULL;
	SDL_Surface *shoot_sprite = NULL;
	SDL_Surface *screenSurface = NULL;
	SDL_Rect square;
	SDL_Rect laser[NUM_LASER];
	SDL_Event event;
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
	bool shoot = false;
	int cont_laser = 0;


	square.x = 100;
	square.y = 100;
	square.w = 19;
	square.h = 32;

	for (int i = 0; i < NUM_LASER; i++) {
		laser[i].x = SCREEN_WIDTH;
		laser[i].y = SCREEN_HEIGHT;
		laser[i].w = 9;
		laser[i].h = 29;
	}


	window = SDL_CreateWindow("Gunbird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

//	rectangle = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	screenSurface = SDL_GetWindowSurface(window);







	//Key detector

	SDL_PollEvent(&event);

	while (1) {

		while (SDL_PollEvent(&event)!= 0) {
		
			if(event.type== SDL_KEYUP){
				switch (event.key.keysym.sym) {
				case SDLK_UP:up = false; break;
				case SDLK_DOWN:down = false; break;
				case SDLK_LEFT:left = false; break;
				case SDLK_RIGHT:right = false; break;
				}
			}
			else if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				case SDLK_UP:up = true; break;
				case SDLK_DOWN:down = true; break;
				case SDLK_LEFT:left = true; break;
				case SDLK_RIGHT:right = true; break;
				case SDLK_SPACE:shoot = true; break;
				case SDLK_ESCAPE:
					SDL_DestroyWindow(window);
					return EXIT_SUCCESS;
					SDL_Quit();
					break;
				}
			}
		}
		if (down == true) {
			if (square.y <= SCREEN_HEIGHT - 35) {
				square.y += 5;
			}
		}
		if (up == true) {
			if (square.y >0) {
				square.y -= 5;
			}
		}
		if (left == true) {
			if (square.x >0) {
				square.x -= 5;
			}
		}
		if (right == true) {
			if (square.x < SCREEN_WIDTH - square.w) {
				square.x += 5;
			}
		}
		if (shoot == true) {
			laser[cont_laser].x = (square.x+(square.w/2)-(laser[cont_laser].w/2));
			laser[cont_laser].y = square.y-laser[cont_laser].h;
			cont_laser++;
			if (cont_laser == NUM_LASER) {
				cont_laser = 0;
			}
			shoot = false; 
			
		}

		for (int i = 0; i < NUM_LASER; i++) {
			if ((laser[i].y + laser[i].h) > 0) {
				laser[i].y -= 15;

			}
		}
		
		
		Ash = SDL_LoadBMP("sprites/Ash.bmp");
		
		red = SDL_LoadBMP("sprites/red.bmp");
		
		SDL_BlitSurface(red, NULL, screenSurface, NULL);
		SDL_FreeSurface(red);
		
		SDL_BlitSurface(Ash, NULL, screenSurface, &square);
		SDL_FreeSurface(Ash);

		for (int i = 0; i < NUM_LASER; i++) {
			shoot_sprite = SDL_LoadBMP("sprites/Shoot.bmp");
			SDL_BlitSurface(shoot_sprite, NULL, screenSurface, &laser[i]);
			SDL_FreeSurface(shoot_sprite);
		}

		////red background
		//SDL_SetRenderDrawColor(red, 255, 0, 0, 0);
		//SDL_RenderClear(red);

		//
		////blue square
		//SDL_BlitSurface(Ash, &square, screenSurface, NULL);
		//SDL_FreeSurface(Ash);

		SDL_UpdateWindowSurface(window);


		//green square
	//for (int i = 0; i < NUM_LASER; i++) {
	//		SDL_SetRenderDrawColor(rectangle, 0, 255, 0, 255);
	//		SDL_RenderFillRect(rectangle, &laser[i]);
	//	}



		//SDL_RenderPresent(rectangle);

	
	}

	



	SDL_DestroyWindow(window);

	return EXIT_SUCCESS;

	SDL_Quit();
}

