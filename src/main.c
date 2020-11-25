#include <SDL2/SDL.h>

const int width = 256;
const int height = 256;

int main() {
	SDL_Window *window = SDL_CreateWindow("life",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		width, height, SDL_WINDOW_SHOWN);
	SDL_Event event;

	while (1) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				break;
			}
		}
		SDL_Delay(16);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
