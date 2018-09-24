/* Calls an x86_64 GAS syntax assembly function to write a message to stdout */

#include <string.h>

//function prototype for the assembly function
void hwASFunction( const char* message, unsigned int count );

int main( int argc, char * argv[] )
{
	char *message = "Hello world \n\0";

	hwASFunction( message, strlen( message ));

	return 0;
}
