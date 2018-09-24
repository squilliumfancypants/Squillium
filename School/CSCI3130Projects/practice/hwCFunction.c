/* function that prints message to screen, called by an assembly program */

#include <unistd.h>

//Pre - an array of chars
//Post - prints the array of chars to the screen
void hwCFunction( const char* message, unsigned int count );

void hwCFunction( const char* message, unsigned int count )
{
	write( 1, message, count );

	return;
}
