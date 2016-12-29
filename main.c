/**
* main.c - initiera motorn
 */

#include <SDL2/SDL.h>
#include <stdio.h>

const int WIN_X = 800;
const int WIN_Y = 600;

int main(int argc, char *argv[]) {
    	//skapa variabler för fönster och innehåll
	SDL_Window* win = NULL;
	SDL_Surface* surf = NULL;

	// initiera grafik- och tidsystem
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
     	printf("SDL misslyckades! SDL_Error: %s\n", SDL_GetError());
        return 1;
	}
	else {
		//skapa fönster
		win = SDL_CreateWindow ("EVA",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                WIN_X,
                                WIN_Y,
                                0);
	}
	if (!win) {
		printf("Fönster misslyckades! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}
	else {
		//hämta innehåll för fönster
		surf = SDL_GetWindowSurface(win);
		//rita innehåll
		SDL_FillRect(surf, NULL, SDL_MapRGB(surf->format, 0xFF, 0xFF, 0xFF));
		//uppdatera innehåll
		SDL_UpdateWindowSurface(win);
		//vänta antal millisekunder
		SDL_Delay(5000);
	}
	//rensa resurser
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
