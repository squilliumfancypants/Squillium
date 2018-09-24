#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <stdio.h>

//screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//map key press constants
enum KeyPresses
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

//initialzes SDL and creates a new window
bool Initialize();

//load media of the surface onto the window
bool LoadMedia();

//close SDL and free up window and surface
void Close();

//loads the image onto the surface
SDL_Surface* loadSurface( std::string path );

//the window that contains the surface
SDL_Window* gWindow = NULL;

//the surface that holds the image
SDL_Surface* gScreenSurface = NULL;

SDL_Surface* gCurrentSurface = NULL;

//an array of pointers to surfaces loaded with images
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

int main( int argc, char* args[] )
{
	//initialize SDL and create a window
	if( !Initialize() )
	{
		printf( "Failed to initialze!");
	}
	
	else
	{
		//load the media
		if( !LoadMedia() )
		{
			printf( "Failed to load media!");
		}
		
		//quit flag
		bool quit = false;
		
		SDL_Event e;
		
		//set the current surface to default
		gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
		
		while( !quit )
		{
			//take events off of poll while there are events to be processed
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
					switch ( e.key.keysym.sym )
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
			
			//apply the image stretched
			SDL_Rect stretchRect;
			stretchRect.x = 0;
			stretchRect.y = 0;
			stretchRect.w = SCREEN_WIDTH;
			stretchRect.h = SCREEN_HEIGHT;
			
			//blit the scaled image to the screen
			SDL_BlitScaled( gCurrentSurface, NULL, gScreenSurface, &stretchRect);
			
			//update the window
			SDL_UpdateWindowSurface( gWindow );
		}
	}
	
	//free up the window and surface and close sdl
	Close();
	
	return 0;
}

bool Initialize()
{
	//set initialization flag
	bool success = true;
	
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "Failed to initialize SDL! SDL Error: %s", SDL_GetError() );
		success = false;
	}
	
	else
	{
		//create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if( gWindow == NULL )
		{
			printf( "Failed to create window! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		
		else
		{
			//initialize png loading
			int imgFlags = IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) )
			{
				printf( "Failed to initialize SDL_image! SDL Error: %s\n", IMG_GetError() );
				success = false;
			}
			
			else
			{
				//get window surface
				gScreenSurface = SDL_GetWindowSurface( gWindow );
			}
		}
	}
	return success;
}

bool LoadMedia()
{
	//set a success flag
	bool success = true;
	
	//load the BMP images into the array of pointers
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "loaded.png");
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL)
	{
		printf( "Failed to load image %s! SDL Error: %s", "loaded.png", SDL_GetError() );
		success = false;
	}
	
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface( "loaded.png" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL )
	{
		printf( "Failed to load image %s! SDL Error: %s\n", "loaded.png", SDL_GetError() );
		success = false;
	}
	
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface( "loaded.png" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL )
	{
		printf( "Failed to load image %s! SDL Error: %s\n", "loaded.png", SDL_GetError() );
		success = false;
	}
	
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( "left.bmp" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL )
	{
		printf( "Failed to load image %s! SDL Error: %s\n", "left.bmp", SDL_GetError() );
		success = false;
	}
	
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "loaded.png" );
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
	{
		printf( "Failed to load image %s! SDL Error: %s\n", "loaded.png", SDL_GetError() );
		success = false;
	}
	
	return success;
}

void Close()
{
	//free up the surfaces in the array of pointers
	for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++)
	{
		SDL_FreeSurface( gKeyPressSurfaces[ i ] );
		gKeyPressSurfaces[ i ] = NULL;
	}
	
	//destroy the window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	
	//quit SDL subsystems
	SDL_Quit();
}

SDL_Surface* loadSurface( std::string path )
{
	//final optimized image
	SDL_Surface* optimizedSurface = NULL;
	
	//load the bmp image onto the surface
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Failed to load image %s! SDL_image Error: %s", path.c_str(), IMG_GetError() );
	}
	
	else
	{
		//convert surface
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, NULL );
		if(optimizedSurface == NULL )
		{
			printf( "Failed to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		
		//get rid of the old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
	
	return optimizedSurface;
}