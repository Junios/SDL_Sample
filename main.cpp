//https://infoarts.tistory.com/45
//https://m.blog.naver.com/PostList.naver?blogId=pjc0247&categoryName=SDL%EA%B0%95%EC%A2%8C&categoryNo=89&logCode=0

#include <stdio.h>
#include "SDL.h"
#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")

SDL_Window* window;
SDL_Renderer* renderer;
int SDL_main(int argc, char* argv[])
{
	printf("Start\n");
	// Initialize SDL 
	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{ 
		printf("Could not initialize SDL! (%s)\n", SDL_GetError());
		return -1;
	}

	// Create window
	window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);
	if (window == NULL)
	{
		printf("Could not create window! (%s)\n", SDL_GetError());
		return -1;
	}
	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	if (renderer == NULL)
	{
		printf("Could not create renderer! (%s)\n", SDL_GetError());
		return -1;
	}


	int offSetX = 0;
	int offSetY = 0;
	SDL_Event event;
	int done = 0;
	while (!done)
	{
		printf("timer %d", SDL_GetTicks());
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			done = 1;
			break;

		case SDL_KEYDOWN:
			printf("Å° ´­·ÁÁü %s\n", SDL_GetKeyName(event.key.keysym.sym));
			printf("offSetX %d\n", offSetX);

			if (event.key.keysym.sym == 'a')
			{
				offSetX--;
			}
			if (event.key.keysym.sym == 'd')
			{
				offSetX++;
			}
			if (event.key.keysym.sym == 'w')
			{
				offSetY--;
			}
			if (event.key.keysym.sym == 's')
			{
				offSetY++;
			}
			break;
		}

		// Clear renderer (white)
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		// Draw rect (red) 
		SDL_Rect r = { 50+offSetX, 50+offSetY, 100, 100 };
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(renderer, &r);

		// Update screen 
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	printf("End\n");

	return 0;
}

