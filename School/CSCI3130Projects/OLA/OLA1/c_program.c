/* Assignment: OLA1
 * Class: CSCI3130 - 001
 * Filename: c_program.c
 * Author: William Hampton
 * Date: 9/04/18
*/

#include <string.h>

//pre - array of characters, and the number of characters in the array
void asm_function( const char *haiku );

int main( int argc, char * argv[] )
{
	const char *haiku = "One two three four five\nFive six seven, eight nine ten\nTen eleven twelve\nAuthor: William Hampton\n";

	asm_function( haiku );
	
	return 0;
}
