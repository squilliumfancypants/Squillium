#include <SDL2/SDL.h>
#include <stdio.h>

//screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//key press surface constants
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

//starts up SDL and creates a new WindowShapeMode
bool Init();

//loads media
bool LoadMedia();

//frees media and shuts down SDLK_BREAK
void Close();

//loads the individual image
SDL_Surface* loadSurface( std::string path ); 

//the window we render to
SDL_Window* gWindow = NULL;

//the surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//the images that correspond to a key press
SDL_Surface* gKeyPressSurface[ KEY_PRESS_SURFACE_TOTAL ];

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
			//Main loop flag
			bool quit = false;
			
			//Event handler
			SDL_Event e;
			
			//while application is running 
			while( !quit )
			{
				//handle events on queue
				while( SDL_PollEvent( &e ) != 0)
				{
					//user requests quit
					if( e.type == SDL_Quit() )
					{
						quit = true;
					}
				}
			}
			
			//Apply the image
			SDL_BlitSurface( gImage, NULL, gScreenSurface, NULL);
			
			//update the window surface
			SDL_UpdateWindowSurface( gWindow );
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
	gImage = SDL_LoadBMP( "Images/bw-ragweed.bmp" );
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

