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
	SDL_Surface* screenSurface = NULL;
	SDL_Surface *rectangle = NULL;
	SDL_Surface *red = NULL;
	SDL_Rect square;
	

	square.x = 0;
	square.y = 0;
	square.w = 100;
	square.h = 100;

	window = SDL_CreateWindow("Homeworks", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	screenSurface = SDL_GetWindowSurface(window);
	rectangle = SDL_LoadBMP("colors/blue.bmp");
	red = SDL_LoadBMP("colors/red.bmp");

	SDL_BlitSurface(red, NULL, screenSurface, NULL);
	SDL_FreeSurface(red);

	SDL_BlitSurface(rectangle, &square, screenSurface, NULL);
	SDL_FreeSurface(rectangle);


	SDL_UpdateWindowSurface(window);

	for(;;){ }


	SDL_DestroyWindow(window);

	return EXIT_SUCCESS;

	SDL_Quit();

}