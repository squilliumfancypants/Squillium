#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>

//define screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//define constants for the different key presses
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL,
};

//the window we render to
SDL_Window* gWindow = NULL;

//create images for all the different key presses
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

SDL_Surface* gScreenSurface = NULL;

//current displayed image
SDL_Surface* gCurrentSurface = NULL;

//loads the individual image
SDL_Surface* loadSurface( std::string path );

//initializes SDL and creates a new WindowShapeMode
bool Initialize();

//load media into 
bool LoadMedia();

//frees media and shuts down SDLK_Break
void Close();

int main( int argc, char* args[] )
{
	//start up SDL and create the main window
	if( !Initialize() )
	{
		printf( "Could not initialize!\n");
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
			//main loop flag
			bool quit = false;
			
			//event handler
			SDL_Event e;
			
			//set current surface to default
			gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
			
			//while application is running 
			while( !quit )
			{
				//handle events on the queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//user requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					
					//user presses a key
					else if( e.type == SDL_KEYDOWN )
					{
						//select surfaces based on key press
						switch( e.key.keysym.sym )
						{
							case SDLK_UP :
							gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
							break;
							
							case SDLK_DOWN :
							gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
							break;
							
							case SDLK_LEFT :
							gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
							break;
							
							case SDLK_RIGHT :
							gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
							break;
							
							default :
							gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
							break;
						}
					}
				}
			
				//blit (apply) the image to the surface
				SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL);
				
				//update the window surface
				SDL_UpdateWindowSurface( gWindow );
			}
		}
	}
	
	//free resources and close SDL
	Close();
	
	return 0;
}

SDL_Surface* loadSurface( std::string path )
{
	//load the image at the specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
	
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s", path.c_str(), SDL_GetError() );
	}
	
	return loadedSurface;
}

bool Initialize()
{
	//set an initialization flag
	bool success = true;
	
	//check for SDL initialization
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "Could not initialize SDL! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	
	else
	{
		//create the window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		
		if( gWindow == NULL)
		{
			printf( "Could not create window! SDL Error: %s\n", SDL_GetError() );
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
	//success flag
	bool success = true;
	
	//load default surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "FLAG_B24.BMP" );
	
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL )
	{
		printf( "Failed to load default image!\n");
		success = false;
	}
	
	//load up surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface( "RAY.BMP" );
	
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL )
	{
		printf( "Failed to load up image!\n");
		success = false;
	}
	
	//load down surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface( "VENUS.BMP" );
	
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL )
	{
		printf( "Failed to load down image!\n");
		success = false;
	}
	
	//load default surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( "MARBLES.BMP" );
	
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL )
	{
		printf( "Failed to load left image!\n");
		success = false;
	}
	
	//load default surface
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "LAND3.BMP" );
	
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
	{
		printf( "Failed to load right image!\n");
		success = false;
	}
		
	return success;
}

void Close()
{
	//deallocate the surfaces
	for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++)
	{
		SDL_FreeSurface( gKeyPressSurfaces[ i ] );
		gKeyPressSurfaces[ i ] = NULL;
	}
	
	//destroy the window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	
	//quit the SDL subsystems
	SDL_Quit();
}



