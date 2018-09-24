#include <SDL2/SDL.h>
#include <stdio.h>

bool Init();
//starts up SDL and creates a new WindowShapeMode

bool LoadMedia();
//loads media

void Close();
//frees media and shuts down SDLK_BREAK

//the window we render to
SDL_Window* gWindow = NULL;

//the surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//the image we will load and show on the screen
SDL_Surface* gImage = NULL;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
	//start up SDL and create the main window
	if( !Init() )
	{
		printf( "Failed to initialize!\n" );
	}
	
	else
	{
		//load media
		if( !LoadMedia() )
		{
			printf( "Failed to load media!\n");
		}
		
		else
		{
			//Apply the image
			SDL_BlitSurface( gImage, NULL, gScreenSurface, NULL);
			
			//update the window surface
			SDL_UpdateWindowSurface( gWindow );
	
	//wait two seconds
	SDL_Delay( 2000 );
		}
	}
	
	//free resources and close SDL
	Close();
	
	return 0;
}


bool Init()
{
	//initialization flag
	bool success = true;
	
	//check for SDL initialization
	if( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf( "SDL did not initialize. SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	
	else
	{
		//create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
									SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if( gWindow == NULL)
		{
			printf( "Window could not be created! SDL Error: %s", SDL_GetError() );
			success = false;
		}
		
		else
		{
			//get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}
	return success;
}

bool LoadMedia()
{
	//loading success flag
	bool success = true;
	
	//load splash image
	gImage = SDL_LoadBMP( "bw-ragweed.bmp" );
	if( gImage == NULL)
	{
		printf( "Unable to load image %s. SDL Error: %s\n", "bw-ragweed.bmp", SDL_GetError() );
		success = false;
	}
	
	return success;
}

void Close()
{
	//Deallocate the surface
	SDL_FreeSurface( gImage );
	gImage = NULL;
	
	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	
	//Quit the SDL subsystems
	SDL_Quit();
}

