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

//loads individual image as texture
SDL_Texture* loadTexture( std::string path );

//the window that contains the surface
SDL_Window* gWindow = NULL;

//the window renderer
SDL_Renderer* gRenderer = NULL;

//current displayed texture
SDL_Texture* gTexture = NULL;

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
				
			}
			
			//clear screen
			SDL_RenderClear( gRenderer );
			
			//render the texture
			SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
			
			//update the screen
			SDL_RenderPresent( gRenderer );
			
			
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
			//create renderer for the window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s", SDL_GetError() );
				success = false;
			}
			
			else
			{
				//initialize the renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				
				//initialize png loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "Failed to initialize SDL_image! SDL Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}
	return success;
}

bool LoadMedia()
{
	//set a success flag
	bool success = true;
	
	//load PNG texture
	gTexture = loadTexture( "texture.png" );
	if( gTexture == NULL )
	{
		printf( "Failed to load texture image!\n" );
		success = false;
	}
	
	return success;
}

void Close()
{
	//free loaded image
	SDL_DestroyTexture( gTexture );
	gTexture = NULL;
	
	//destroy the window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	
	//quit SDL subsystems
	IMG_Quit();
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
		printf( "Failed to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
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

SDL_Texture* loadTexture( std::string path )
{
	//the final texture
	SDL_Texture* newTexture = NULL;
	
	//load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Failed to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	
	else
	{
		//create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create a new texture from image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		
		//get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
	return newTexture;
}