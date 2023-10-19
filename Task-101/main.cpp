#include <SDL2/SDL.h>
#include<iostream>
using namespace std;
int run = 0;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Color color;
void drawFilledCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius,SDL_Color color ) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    for (int x = centerX - radius; x <= centerX + radius; x++) {
        for (int y = centerY - radius; y <= centerY + radius; y++) {
            int distance = (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY);
            if (distance <= radius * radius) {
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }
    SDL_RenderPresent(renderer);
}

int initialize_window(void)
{
	SDL_Init(SDL_INIT_EVERYTHING);

 window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_BORDERLESS);
if(!window)
{
	fprintf(stderr, "Error creating SDL window\n");
	return 0;
}
renderer = SDL_CreateRenderer(window,-1,0);
if(!renderer)
{
	fprintf(stderr,"Error creating renderer\n");
	return 0;
}
return 1;
}
void process_input()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type)
	{
		case SDL_QUIT:
		run = 0;
		break;
		case SDL_KEYDOWN:
		if(event.key.keysym.sym == SDLK_ESCAPE)
		run = 0;
		break;
	}

}
void update()
{

}
void render()
{
SDL_SetRenderDrawColor(renderer, 200,200,0,255);
SDL_RenderClear(renderer);
SDL_RenderPresent(renderer);
SDL_Rect rect;
 rect.w=50;
   rect.h=50;
   rect.x=800/2;
   rect.y=600/2;
SDL_SetRenderDrawColor(renderer,255,0,0,255);
drawFilledCircle( renderer, 400, 300 ,100, color );
SDL_RenderPresent(renderer);
SDL_Delay(2000);
}
void destroy_window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char *argv[])
{

	run = initialize_window();
	//setup();
	
   
	while(run)
	{
		process_input();
		update();
		render();
	}
	destroy_window();
	return 0;
}
