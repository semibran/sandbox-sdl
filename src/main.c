#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string.h>

const int scale = 1;
const int width = 64 * scale;
const int height = 64 * scale;

int main() {
  SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window = SDL_CreateWindow("Game",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer *rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	int flags = IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	SDL_Surface* surface = IMG_Load("src/goku.png");
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
	SDL_Texture* texture = SDL_CreateTextureFromSurface(rend, surface);
	SDL_Rect dest = { 0, 0, surface->w, surface->h };

	SDL_FreeSurface(surface);
	SDL_RenderSetScale(rend, scale, scale);
	SDL_RenderClear(rend);
	SDL_RenderCopy(rend, texture, NULL, &dest);
	SDL_RenderPresent(rend);
	SDL_UpdateWindowSurface(window);

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
	window = NULL;

	SDL_Quit();
	return 0;
}
