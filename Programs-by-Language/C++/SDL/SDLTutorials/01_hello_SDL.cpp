//include the libraries for SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>

//Set the screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//SDL requires this type of main funtion (return type and parameters) for 
//cross-platform compatibiltiy
int main( int argc, char* args[] )
{
	//create a pointer to the window that we render to
	SDL_Window* window = NULL;
	
	//create a pointer to the surface contained by the window
	SDL_Surface* screenSurface = NULL;
	
	//initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		//print an error statement if SDL will not initialize
		printf( "SDL cannot initialize! SDL Error: %s\n", SDL_GetError() );
	}
	
	//create a new window if initialization is successful
	else
	{
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
					SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
					
		if( window == NULL )
		{
			printf( "Window could not be created. SDL Error: %s", SDL_GetError() );
		}
		
		else
		{
			//create screen surface
			screenSurface = SDL_GetWindowSurface( window );
			
			//fill the surface with white
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
			
			//update the surface
			SDL_UpdateWindowSurface( window );
			
			SDL_Delay( 2000 );
			
		}
	}
	
	//destroy the sdl window
	SDL_DestroyWindow( window );
	
	//quit sdl subsystems
	SDL_Quit();
	
	return 0;
	
}